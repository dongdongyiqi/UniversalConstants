#pragma once
#include <gmpxx.h>

namespace UniversalConstants {
    namespace Math {
        mpf_class PI(long long digits);
        mpf_class TAU(long long digits);
        mpf_class E(long long digits);
        mpf_class PHI(long long digits);
        mpf_class SILVER(long long digits);
        mpf_class SQRT2(long long digits);
        mpf_class SQRT3(long long digits);
        mpf_class SQRT5(long long digits);
        mpf_class PLASTIC(long long digits);
        mpf_class LN2(long long digits);
        mpf_class LN10(long long digits);
        mpf_class GAMMA(long long digits);
        mpf_class GELFOND(long long digits);
        mpf_class CATALAN(long long digits);
        mpf_class APERY(long long digits);
        mpf_class GAUSS(long long digits);
        mpf_class KHINCHIN(long long digits);
        mpf_class GLAISHER(long long digits);
        mpf_class DOTTIE(long long digits);
        mpf_class FEIGENBAUM_DELTA(long long digits);
        mpf_class FEIGENBAUM_ALPHA(long long digits);
        mpf_class TWIN_PRIME(long long digits);
        mpf_class LANDAU_RAMANUJAN(long long digits);
    }

    namespace Physics {
        mpf_class C(long long digits);
        mpf_class G(long long digits);
        mpf_class STANDARD_G(long long digits);
        mpf_class HUBBLE(long long digits);
        mpf_class COSMOLOGICAL_CONSTANT(long long digits);
        mpf_class H(long long digits);
        mpf_class H_BAR(long long digits);
        mpf_class E_CHARGE(long long digits);
        mpf_class VACUUM_PERMITTIVITY(long long digits);
        mpf_class VACUUM_PERMEABILITY(long long digits);
        mpf_class FINE_STRUCTURE(long long digits);
        mpf_class COULOMB_K(long long digits);
        mpf_class BOHR_MAGNETON(long long digits);
        mpf_class ELECTRON_MASS(long long digits);
        mpf_class PROTON_MASS(long long digits);
        mpf_class NEUTRON_MASS(long long digits);
        mpf_class BOHR_RADIUS(long long digits);
        mpf_class ELECTRON_RADIUS(long long digits);
        mpf_class RYDBERG_CONSTANT(long long digits);
        mpf_class NA(long long digits);
        mpf_class KB(long long digits);
        mpf_class R_GAS(long long digits);
        mpf_class FARADAY(long long digits);
        mpf_class STEFAN_BOLTZMANN(long long digits);
        mpf_class WIEN(long long digits);
        mpf_class AU(long long digits);
        mpf_class LIGHT_YEAR(long long digits);
        mpf_class PARSEC(long long digits);
        mpf_class SOLAR_MASS(long long digits);
        mpf_class EARTH_MASS(long long digits);
    }
}