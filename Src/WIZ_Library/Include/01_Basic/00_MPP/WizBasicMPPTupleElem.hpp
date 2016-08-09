#ifndef __WIZ_BASIC_MPP_TUPLE_ELEM_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_MPP_TUPLE_ELEM_HPP__SHANHAOBO_19800429__

/// 这个是获取tuple元素的
/// WIZ_MPP_TUPLE_ELEM(3, 1, (X, Y, Z)) => Y
#define WIZ_MPP_TUPLE_ELEM(size, index, tuple)      WIZ_MPP_BRIDGE_TUPLE_ELEM((size, index, tuple))
#define WIZ_MPP_BRIDGE_TUPLE_ELEM(par)              WIZ_MPP_BRIDGE_TUPLE_ELEM_I##par
#define WIZ_MPP_BRIDGE_TUPLE_ELEM_I(s, i, t)        WIZ_MPP_BRIDGE_TUPLE_ELEM_II(WIZ_MPP_PREDEF_TUPLE_ELEM_##s##_##i t)
#define WIZ_MPP_BRIDGE_TUPLE_ELEM_II(res)           res


/// 预定义
#define WIZ_MPP_PREDEF_TUPLE_ELEM_1_0(a) a

#define WIZ_MPP_PREDEF_TUPLE_ELEM_2_0(a, b) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_2_1(a, b) b

#define WIZ_MPP_PREDEF_TUPLE_ELEM_3_0(a, b, c) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_3_1(a, b, c) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_3_2(a, b, c) c

#define WIZ_MPP_PREDEF_TUPLE_ELEM_4_0(a, b, c, d) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_4_1(a, b, c, d) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_4_2(a, b, c, d) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_4_3(a, b, c, d) d

#define WIZ_MPP_PREDEF_TUPLE_ELEM_5_0(a, b, c, d, e) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_5_1(a, b, c, d, e) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_5_2(a, b, c, d, e) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_5_3(a, b, c, d, e) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_5_4(a, b, c, d, e) e

#define WIZ_MPP_PREDEF_TUPLE_ELEM_6_0(a, b, c, d, e, f) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_6_1(a, b, c, d, e, f) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_6_2(a, b, c, d, e, f) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_6_3(a, b, c, d, e, f) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_6_4(a, b, c, d, e, f) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_6_5(a, b, c, d, e, f) f

#define WIZ_MPP_PREDEF_TUPLE_ELEM_7_0(a, b, c, d, e, f, g) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_7_1(a, b, c, d, e, f, g) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_7_2(a, b, c, d, e, f, g) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_7_3(a, b, c, d, e, f, g) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_7_4(a, b, c, d, e, f, g) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_7_5(a, b, c, d, e, f, g) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_7_6(a, b, c, d, e, f, g) g

#define WIZ_MPP_PREDEF_TUPLE_ELEM_8_0(a, b, c, d, e, f, g, h) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_8_1(a, b, c, d, e, f, g, h) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_8_2(a, b, c, d, e, f, g, h) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_8_3(a, b, c, d, e, f, g, h) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_8_4(a, b, c, d, e, f, g, h) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_8_5(a, b, c, d, e, f, g, h) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_8_6(a, b, c, d, e, f, g, h) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_8_7(a, b, c, d, e, f, g, h) h

#define WIZ_MPP_PREDEF_TUPLE_ELEM_9_0(a, b, c, d, e, f, g, h, i) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_9_1(a, b, c, d, e, f, g, h, i) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_9_2(a, b, c, d, e, f, g, h, i) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_9_3(a, b, c, d, e, f, g, h, i) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_9_4(a, b, c, d, e, f, g, h, i) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_9_5(a, b, c, d, e, f, g, h, i) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_9_6(a, b, c, d, e, f, g, h, i) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_9_7(a, b, c, d, e, f, g, h, i) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_9_8(a, b, c, d, e, f, g, h, i) i

#define WIZ_MPP_PREDEF_TUPLE_ELEM_10_0(a, b, c, d, e, f, g, h, i, j) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_10_1(a, b, c, d, e, f, g, h, i, j) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_10_2(a, b, c, d, e, f, g, h, i, j) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_10_3(a, b, c, d, e, f, g, h, i, j) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_10_4(a, b, c, d, e, f, g, h, i, j) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_10_5(a, b, c, d, e, f, g, h, i, j) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_10_6(a, b, c, d, e, f, g, h, i, j) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_10_7(a, b, c, d, e, f, g, h, i, j) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_10_8(a, b, c, d, e, f, g, h, i, j) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_10_9(a, b, c, d, e, f, g, h, i, j) j

#define WIZ_MPP_PREDEF_TUPLE_ELEM_11_0(a, b, c, d, e, f, g, h, i, j, k) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_11_1(a, b, c, d, e, f, g, h, i, j, k) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_11_2(a, b, c, d, e, f, g, h, i, j, k) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_11_3(a, b, c, d, e, f, g, h, i, j, k) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_11_4(a, b, c, d, e, f, g, h, i, j, k) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_11_5(a, b, c, d, e, f, g, h, i, j, k) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_11_6(a, b, c, d, e, f, g, h, i, j, k) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_11_7(a, b, c, d, e, f, g, h, i, j, k) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_11_8(a, b, c, d, e, f, g, h, i, j, k) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_11_9(a, b, c, d, e, f, g, h, i, j, k) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_11_10(a, b, c, d, e, f, g, h, i, j, k) k

#define WIZ_MPP_PREDEF_TUPLE_ELEM_12_0(a, b, c, d, e, f, g, h, i, j, k, l) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_12_1(a, b, c, d, e, f, g, h, i, j, k, l) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_12_2(a, b, c, d, e, f, g, h, i, j, k, l) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_12_3(a, b, c, d, e, f, g, h, i, j, k, l) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_12_4(a, b, c, d, e, f, g, h, i, j, k, l) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_12_5(a, b, c, d, e, f, g, h, i, j, k, l) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_12_6(a, b, c, d, e, f, g, h, i, j, k, l) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_12_7(a, b, c, d, e, f, g, h, i, j, k, l) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_12_8(a, b, c, d, e, f, g, h, i, j, k, l) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_12_9(a, b, c, d, e, f, g, h, i, j, k, l) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_12_10(a, b, c, d, e, f, g, h, i, j, k, l) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_12_11(a, b, c, d, e, f, g, h, i, j, k, l) l

#define WIZ_MPP_PREDEF_TUPLE_ELEM_13_0(a, b, c, d, e, f, g, h, i, j, k, l, m) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_13_1(a, b, c, d, e, f, g, h, i, j, k, l, m) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_13_2(a, b, c, d, e, f, g, h, i, j, k, l, m) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_13_3(a, b, c, d, e, f, g, h, i, j, k, l, m) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_13_4(a, b, c, d, e, f, g, h, i, j, k, l, m) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_13_5(a, b, c, d, e, f, g, h, i, j, k, l, m) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_13_6(a, b, c, d, e, f, g, h, i, j, k, l, m) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_13_7(a, b, c, d, e, f, g, h, i, j, k, l, m) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_13_8(a, b, c, d, e, f, g, h, i, j, k, l, m) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_13_9(a, b, c, d, e, f, g, h, i, j, k, l, m) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_13_10(a, b, c, d, e, f, g, h, i, j, k, l, m) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_13_11(a, b, c, d, e, f, g, h, i, j, k, l, m) l
#define WIZ_MPP_PREDEF_TUPLE_ELEM_13_12(a, b, c, d, e, f, g, h, i, j, k, l, m) m

#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n) l
#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n) m
#define WIZ_MPP_PREDEF_TUPLE_ELEM_14_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n) n

#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) l
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) m
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) n
#define WIZ_MPP_PREDEF_TUPLE_ELEM_15_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) o

#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) l
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) m
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) n
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) o
#define WIZ_MPP_PREDEF_TUPLE_ELEM_16_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) p

#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) l
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) m
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) n
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) o
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) p
#define WIZ_MPP_PREDEF_TUPLE_ELEM_17_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) q

#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) l
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) m
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) n
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) o
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) p
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) q
#define WIZ_MPP_PREDEF_TUPLE_ELEM_18_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) r

#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) l
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) m
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) n
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) o
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) p
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) q
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) r
#define WIZ_MPP_PREDEF_TUPLE_ELEM_19_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) s

#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) l
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) m
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) n
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) o
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) p
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) q
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) r
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) s
#define WIZ_MPP_PREDEF_TUPLE_ELEM_20_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) t

#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) l
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) m
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) n
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) o
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) p
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) q
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) r
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) s
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) t
#define WIZ_MPP_PREDEF_TUPLE_ELEM_21_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) u

#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) l
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) m
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) n
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) o
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) p
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) q
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) r
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) s
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) t
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) u
#define WIZ_MPP_PREDEF_TUPLE_ELEM_22_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) v

#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) l
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) m
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) n
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) o
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) p
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) q
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) r
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) s
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) t
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) u
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) v
#define WIZ_MPP_PREDEF_TUPLE_ELEM_23_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) w

#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) l
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) m
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) n
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) o
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) p
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) q
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) r
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) s
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) t
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) u
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) v
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) w
#define WIZ_MPP_PREDEF_TUPLE_ELEM_24_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) x

#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) a
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) b
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) c
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) d
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) e
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) f
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) g
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) h
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) i
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) j
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) k
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) l
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) m
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) n
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) o
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) p
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) q
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) r
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) s
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) t
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) u
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) v
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) w
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) x
#define WIZ_MPP_PREDEF_TUPLE_ELEM_25_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) y

#endif /*__WIZ_BASIC_MPP_TUPLE_ELEM_HPP__SHANHAOBO_19800429__*/
