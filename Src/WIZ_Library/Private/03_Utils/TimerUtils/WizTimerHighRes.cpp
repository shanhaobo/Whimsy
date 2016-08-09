#include "../../../include/01_Basic/04_TU/WizBasicTU.hpp"
#include "../../../include/01_Basic/02_MU/WizBasicMUAssert.hpp"
#include "../../../include/03_Utils/TimerUtils/WizTimerHighRes.hpp"

#include <algorithm>

#if (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_WINDOWS)
#   include <windows.h>
#elif (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_LINUX)
#   include <sys/time.h>
#endif /// (WIZ_CFG_PLATFORM)

namespace Wiz
{
    namespace Timer
    {
        namespace HighRes
        {
            namespace Impl
            {
                template<class DerivedT>
                class Type : public Timer::HighRes::Type
                {
                public:
                    typedef DerivedT tDerived;

                public:
                    tDerived* GetDerivedPtr()
                    {
                        return static_cast<tDerived*>(this);
                    }
                public:
                    virtual R64::Type Now_Second()             /// Ãë
                    {
                        return GetDerivedPtr()->Now<1>();
                    }

                    virtual R64::Type Now_MilliSecond()        /// ºÁÃë
                    {
                        return GetDerivedPtr()->Now<1000>();
                    }

                    virtual R64::Type Now_MicroSecond()        /// Î¢Ãë
                    {
                        return GetDerivedPtr()->Now<1000000>();
                    }
                }; /// class Type
            } /// end of namespace Impl

#if (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_WINDOWS)
            namespace Windows
            {
                class Type : public Timer::HighRes::Impl::Type<Type>
                {
                public:
                    Type() : m_TimerMask(0)
                    {
                        Reset();
                    }

                    virtual ~Type()
                    {

                    }

                protected:
                    DWORD_PTR GetTimerMask()
                    {
                        // Get the current process core mask
                        DWORD_PTR procMask;
                        DWORD_PTR sysMask;
                        ::GetProcessAffinityMask(::GetCurrentProcess(), &procMask, &sysMask);

                        // If procMask is 0, consider there is only one core available
                        // (using 0 as procMask will cause an infinite loop below)
                        if (procMask == 0)
                        {
                            procMask = 1;
                        }

                        DWORD_PTR TimerMask = 1;
                        while ((TimerMask & procMask) == 0)
                        {
                            TimerMask <<= 1;
                        }

                        return TimerMask;
                    }

                public:
                    virtual Void::Type Reset()
                    {
                        if (m_TimerMask == 0)
                        {
                            m_TimerMask = GetTimerMask();
                        } /// end if

                        HANDLE CurrThread = ::GetCurrentThread();

                        // Set affinity to the first core
                        DWORD_PTR OldMask = ::SetThreadAffinityMask(CurrThread, m_TimerMask);

                        // Get the constant frequency
                        ::QueryPerformanceFrequency(&m_Frequency);

                        // Query the timer
                        ::QueryPerformanceCounter(&m_StartTime);

                        mStartTick = ::GetTickCount();

                        // Reset affinity
                        ::SetThreadAffinityMask(CurrThread, OldMask);

                        mLastTime = 0;

                        m_FrequencyR64 = R64::Type(m_Frequency.QuadPart);
                    }

                    template<int iMultiTime>
                    R64::Type Now()
                    {
                        LARGE_INTEGER CurTime;

                        HANDLE CurrThread = ::GetCurrentThread();

                        // Set affinity to the first core
                        DWORD_PTR oldMask = ::SetThreadAffinityMask(CurrThread, m_TimerMask);

                        // Query the timer
                        ::QueryPerformanceCounter(&CurTime);

                        // Reset affinity
                        ::SetThreadAffinityMask(CurrThread, oldMask);

                        LONGLONG NewTime = CurTime.QuadPart - m_StartTime.QuadPart;

                        // scale by iMultiTime
                        unsigned long newTicks = (unsigned long)(iMultiTime * NewTime / m_Frequency.QuadPart);
                        R64::Type NowTime = static_cast<R64::Type>(iMultiTime * NewTime) / m_FrequencyR64;

                        // detect and compensate for performance counter leaps
                        // (surprisingly common, see Microsoft KB: Q274323)
                        unsigned long check = ::GetTickCount() - mStartTick;
                        signed long msecOff = (signed long)(newTicks - check);
                        if (msecOff < -100 || msecOff > 100)
                        {
                            // We must keep the timer running forward :)
                            LONGLONG adjust = (::std::min)(msecOff * m_Frequency.QuadPart / iMultiTime, NewTime - mLastTime);
                            m_StartTime.QuadPart += adjust;
                            NewTime -= adjust;

                            // Re-calculate milliseconds
                            NowTime = static_cast<R64::Type>((iMultiTime * NewTime) / m_FrequencyR64);
                        }

                        // Record last time for adjust
                        mLastTime = NewTime;

                        return NowTime;
                    }

                protected:
                    LARGE_INTEGER   m_StartTime;
                    LARGE_INTEGER   m_Frequency;
                    R64::Type       m_FrequencyR64;

                    DWORD           mStartTick;
                    LONGLONG        mLastTime;

                    DWORD_PTR       m_TimerMask;
                };
            } /// end of namespace Windows
#endif /// (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_WINDOWS)

#if (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_LINUX)
            namespace Linux
            {
                class Type : public Timer::HighRes::Impl::Type<Type>
                {
                public:
                    Type()
                    {
                        Reset();
                    }

                    virtual ~Type()
                    {

                    }

                public:
                    virtual Void::Type Reset()
                    {
                        gettimeofday(&start, NULL);
                    }

                    template<int iMultiTime>
                    R64::Type Now()
                    {
                        struct timeval now;
                        gettimeofday(&now, NULL);

                        return R64::Type(now.tv_sec - start.tv_sec) * iMultiTime + R64::Type(now.tv_usec - start.tv_usec) * iMultiTime / 1000000;
                    }

                private:
                    struct timeval start;
                };
            } /// end of namespace Linux
#endif /// (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_LINUX)

            Ptr Create()
            {
#if (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_WINDOWS)
                return new Windows::Type;
#elif (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_LINUX)
                return new Linux::Type;
#else

#   error WIZ_CFG_PLATFORM Is Illegal
                return WIZ_NULLPTR;
#endif 
            }

            Void::Type Destroy(Ptr& inPtr)
            {
                inPtr = WIZ_NULLPTR;
            }

            ////////////////////////////////////////////////////////

            struct tInnerSingletonManagedInstance
            {
                Ptr ManagedPtr;

                tInnerSingletonManagedInstance() : ManagedPtr(WIZ_NULLPTR)
                {
                }

                ~tInnerSingletonManagedInstance()
                {
                    Destroy(ManagedPtr);
                }
            };
            tInnerSingletonManagedInstance innerSingletonInstance;

            Ptr instancePtr()
            {
                if (::Wiz::NotValidPtr(innerSingletonInstance.ManagedPtr))
                {
                    innerSingletonInstance.ManagedPtr = Create();
                    if (::Wiz::NotValidPtr(innerSingletonInstance.ManagedPtr))
                    {
                        WIZ_ASSERT(::Wiz::Bool::False);
                        return WIZ_NULLPTR;
                    }
                }
                return innerSingletonInstance.ManagedPtr;
            }
        } /// end of namespace HighRes
    } /// end of namespace Timer
} /// end of namespace rkk


