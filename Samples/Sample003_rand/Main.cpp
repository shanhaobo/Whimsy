#include "../SampleBase.hpp"

#include <iostream>
#include <fstream>


int _tmain(int argc, _TCHAR* argv[])
{
    ::std::ofstream lTxt;

    lTxt.open(_T("D:\\Documents\\MATLAB\\Rand.txt"));

    ::Wiz::R64::Type lRadius, lTheta;
    ::Wiz::R64::Type x, y;

    /// 为啥要0~2500然后开方, 而不直接使用 0~50
    /// 是因为让大半径的点更多些,毕竟 10个点分布在半径为10的圆周上 比 10个点分布在半径为50的圆周上要密
    ::Wiz::Random::Type<::Wiz::R64::Type> tRandom(0, 2500);

    for (::Wiz::I::Type i = 0; i < 1000; ++i)
    {
        lRadius = sqrt(tRandom.Generate());
        lTheta = rand();
        x = lRadius * sin(lTheta);
        y = lRadius * cos(lTheta);

        lTxt << x << '\t' << y << '\n';
    }


    lTxt.close();

    return 0;
}

