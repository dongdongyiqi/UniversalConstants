#pragma once

namespace BasicConstants {
    // 基础数学常数
    constexpr double PI = 3.14159265358979323846;
    constexpr double TAU = 6.28318530717958647692;
    constexpr double E = 2.71828182845904523536;
    constexpr double PHI = 1.61803398874989484820;

    // 物理与工程常数 (double 精度)
    constexpr double C = 299792458.0;            // 真空光速 (m/s)
    constexpr double G = 6.67430e-11;            // 万有引力常数
    constexpr double STANDARD_G = 9.80665;       // 地表标准重力加速度 (m/s^2)
    constexpr double H = 6.62607015e-34;         // 普朗克常数 (J·s)
    constexpr double H_BAR = 1.054571817e-34;    // 约化普朗克常数 (J·s)
    constexpr double E_CHARGE = 1.602176634e-19; // 元电荷量 (C)
    constexpr double NA = 6.02214076e23;         // 阿伏伽德罗常数 (mol^-1)
    constexpr double KB = 1.380649e-23;          // 玻尔兹曼常数 (J/K)

    // 天文常数
    constexpr double AU = 149597870700.0;        // 天文单位 (m)
    constexpr double LIGHT_YEAR = 9460730472580800.0; // 光年 (m)
}