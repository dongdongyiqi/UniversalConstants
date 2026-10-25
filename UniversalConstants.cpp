#include "UniversalConstants.h"
#include <gmp.h>
#include <gmpxx.h>
#include <string>
#include <cmath>

namespace UniversalConstants {

    // 内部通用精度控制函数
    void _set_prec(long long digits) {
        unsigned long long prec_bits = digits * 3.321928094887362 + 32;
        mpf_set_default_prec(prec_bits);
    }

    // 内部圆周率 Chudnovsky 二进制分割引擎
    struct _BSNode { mpz_class P; mpz_class Q; mpz_class T; };
    _BSNode _bs_chudnovsky(long long a, long long b) {
        _BSNode res;
        if (b - a == 1) {
            if (a == 0) { res.P = 1; res.Q = 1; res.T = 13591409; }
            else {
                mpz_class a_mpz(std::to_string(a));
                mpz_class t1 = a_mpz * 6 - 5; mpz_class t2 = a_mpz * 2 - 1; mpz_class t3 = a_mpz * 6 - 1;
                res.P = -t1 * t2 * t3;
                res.Q = a_mpz * a_mpz * a_mpz * mpz_class("10939058860032000");
                res.T = res.P * (mpz_class("13591409") + a_mpz * 545140134);
            }
        } else {
            long long mid = a + (b - a) / 2;
            _BSNode left = _bs_chudnovsky(a, mid); _BSNode right = _bs_chudnovsky(mid, b);
            res.P = left.P * right.P; res.Q = left.Q * right.Q; res.T = left.T * right.Q + left.P * right.T;
        }
        return res;
    }

    namespace Math {
        mpf_class PI(long long digits) {
            _set_prec(digits);
            long long N = digits / 14.18164594 + 1;
            _BSNode r = _bs_chudnovsky(0, N);
            mpf_class base_10005("10005");
            mpf_class sqrt_val;
            mpf_sqrt(sqrt_val.get_mpf_t(), base_10005.get_mpf_t());
            return (mpf_class("426880") * sqrt_val * mpf_class(r.Q)) / mpf_class(r.T);
        }

        mpf_class TAU(long long digits) { _set_prec(digits); return PI(digits) * mpf_class("2"); }

        // 修正点1：将除数 i 包装为 mpf_class(std::to_string(i))，消除类型歧义
        mpf_class E(long long digits) {
            _set_prec(digits);
            mpf_class sum = 2, term = 1;
            long long i = 2;
            while (term > mpf_class("1e-" + std::to_string(digits))) {
                term /= mpf_class(std::to_string(i));
                sum += term;
                i++;
            }
            return sum;
        }

        mpf_class PHI(long long digits) {
            _set_prec(digits);
            mpf_class base_5("5");
            mpf_class sqrt_val;
            mpf_sqrt(sqrt_val.get_mpf_t(), base_5.get_mpf_t());
            return (mpf_class("1") + sqrt_val) / mpf_class("2");
        }

        mpf_class SILVER(long long digits) {
            _set_prec(digits);
            mpf_class base_2("2");
            mpf_class sqrt_val;
            mpf_sqrt(sqrt_val.get_mpf_t(), base_2.get_mpf_t());
            return mpf_class("1") + sqrt_val;
        }

        mpf_class SQRT2(long long digits) {
            _set_prec(digits);
            mpf_class base_2("2");
            mpf_class sqrt_val;
            mpf_sqrt(sqrt_val.get_mpf_t(), base_2.get_mpf_t());
            return sqrt_val;
        }

        mpf_class SQRT3(long long digits) {
            _set_prec(digits);
            mpf_class base_3("3");
            mpf_class sqrt_val;
            mpf_sqrt(sqrt_val.get_mpf_t(), base_3.get_mpf_t());
            return sqrt_val;
        }

        mpf_class SQRT5(long long digits) {
            _set_prec(digits);
            mpf_class base_5("5");
            mpf_class sqrt_val;
            mpf_sqrt(sqrt_val.get_mpf_t(), base_5.get_mpf_t());
            return sqrt_val;
        }

        mpf_class PLASTIC(long long digits) { _set_prec(digits); return mpf_class("1.324717957244746025960908854"); }

        // 修正点2：将除数 k 包装为 mpf_class(std::to_string(k))，消除接口模糊
        mpf_class LN2(long long digits) {
            _set_prec(digits + 10);
            mpf_class res;
            mpf_class base_2("2");
            mpf_class x = (base_2 - 1) / (base_2 + 1);
            mpf_class x_pow = x;
            mpf_class sum = x;
            mpf_class term;
            long long k = 3;
            while (true) {
                x_pow = x_pow * x * x;
                term = x_pow / mpf_class(std::to_string(k));
                if (term < mpf_class("1e-" + std::to_string(digits + 2))) break;
                sum += term;
                k += 2;
            }
            res = sum * 2;
            return res;
        }

        // 修正点3：同上，将除数 k 完美安全地进行大数化对齐
        mpf_class LN10(long long digits) {
            _set_prec(digits + 10);
            mpf_class res;
            mpf_class base_10("10");
            mpf_class x = (base_10 - 1) / (base_10 + 1);
            mpf_class x_pow = x;
            mpf_class sum = x;
            mpf_class term;
            long long k = 3;
            while (true) {
                x_pow = x_pow * x * x;
                term = x_pow / mpf_class(std::to_string(k));
                if (term < mpf_class("1e-" + std::to_string(digits + 2))) break;
                sum += term;
                k += 2;
            }
            res = sum * 2;
            return res;
        }

        mpf_class GAMMA(long long digits) { _set_prec(digits); return mpf_class("0.5772156649015328606065120900824024310421"); }
        mpf_class GELFOND(long long digits) { _set_prec(digits); return mpf_class("23.140692632779269005729086367"); }
        mpf_class CATALAN(long long digits) { _set_prec(digits); return mpf_class("0.915965594177219015054603514932"); }
        mpf_class APERY(long long digits) { _set_prec(digits); return mpf_class("1.202056903159594285399738161511"); }
        mpf_class GAUSS(long long digits) { _set_prec(digits); return mpf_class("0.834626841674073186281429732799"); }
        mpf_class KHINCHIN(long long digits) { _set_prec(digits); return mpf_class("2.68545200106530644530971483548"); }
        mpf_class GLAISHER(long long digits) { _set_prec(digits); return mpf_class("1.28242712910062263687534256886"); }
        mpf_class DOTTIE(long long digits) { _set_prec(digits); return mpf_class("0.73908513321516064165531208767"); }
        mpf_class FEIGENBAUM_DELTA(long long digits) { _set_prec(digits); return mpf_class("4.66920160910299067185320382"); }
        mpf_class FEIGENBAUM_ALPHA(long long digits) { _set_prec(digits); return mpf_class("2.50290787509589282228390287"); }
        mpf_class TWIN_PRIME(long long digits) { _set_prec(digits); return mpf_class("0.66016181584686957392781211"); }
        mpf_class LANDAU_RAMANUJAN(long long digits) { _set_prec(digits); return mpf_class("0.76422365358922066299069873"); }
    }

    namespace Physics {
        mpf_class C(long long digits) { _set_prec(digits); return mpf_class("299792458"); }
        mpf_class G(long long digits) { _set_prec(digits); return mpf_class("6.67430e-11"); }
        mpf_class STANDARD_G(long long digits) { _set_prec(digits); return mpf_class("9.80665"); }
        mpf_class HUBBLE(long long digits) { _set_prec(digits); return mpf_class("67.4"); }
        mpf_class COSMOLOGICAL_CONSTANT(long long digits) { _set_prec(digits); return mpf_class("2.846e-122"); }
        mpf_class H(long long digits) { _set_prec(digits); return mpf_class("6.62607015e-34"); }
        mpf_class H_BAR(long long digits) { _set_prec(digits); return mpf_class("1.054571817e-34"); }
        mpf_class E_CHARGE(long long digits) { _set_prec(digits); return mpf_class("1.602176634e-19"); }
        mpf_class VACUUM_PERMITTIVITY(long long digits) { _set_prec(digits); return mpf_class("8.8541878128e-12"); }
        mpf_class VACUUM_PERMEABILITY(long long digits) { _set_prec(digits); return mpf_class("1.25663706212e-6"); }
        mpf_class FINE_STRUCTURE(long long digits) { _set_prec(digits); return mpf_class("7.2973525643e-3"); }
        mpf_class COULOMB_K(long long digits) { _set_prec(digits); return mpf_class("8.987742438e9"); }
        mpf_class BOHR_MAGNETON(long long digits) { _set_prec(digits); return mpf_class("9.274010078e-24"); }
        mpf_class ELECTRON_MASS(long long digits) { _set_prec(digits); return mpf_class("9.1093837015e-31"); }
        mpf_class PROTON_MASS(long long digits) { _set_prec(digits); return mpf_class("1.67262192369e-27"); }
        mpf_class NEUTRON_MASS(long long digits) { _set_prec(digits); return mpf_class("1.67492749804e-27"); }
        mpf_class BOHR_RADIUS(long long digits) { _set_prec(digits); return mpf_class("5.29177210903e-11"); }
        mpf_class ELECTRON_RADIUS(long long digits) { _set_prec(digits); return mpf_class("2.8179403262e-15"); }
        mpf_class RYDBERG_CONSTANT(long long digits) { _set_prec(digits); return mpf_class("10973731.56816"); }
        mpf_class NA(long long digits) { _set_prec(digits); return mpf_class("6.02214076e23"); }
        mpf_class KB(long long digits) { _set_prec(digits); return mpf_class("1.380649e-23"); }
        mpf_class R_GAS(long long digits) { _set_prec(digits); return mpf_class("8.314462618"); }
        mpf_class FARADAY(long long digits) { _set_prec(digits); return mpf_class("96485.33212"); }
        mpf_class STEFAN_BOLTZMANN(long long digits) { _set_prec(digits); return mpf_class("5.670374419e-8"); }
        mpf_class WIEN(long long digits) { _set_prec(digits); return mpf_class("2.897771955e-3"); }
        mpf_class AU(long long digits) { _set_prec(digits); return mpf_class("149597870700"); }
        mpf_class LIGHT_YEAR(long long digits) { _set_prec(digits); return mpf_class("9460730472580800"); }
        mpf_class PARSEC(long long digits) { _set_prec(digits); return mpf_class("3.085677581e16"); }
        mpf_class SOLAR_MASS(long long digits) { _set_prec(digits); return mpf_class("1.98847e30"); }
        mpf_class EARTH_MASS(long long digits) { _set_prec(digits); return mpf_class("5.9722e24"); }
    }
}
