# 🌌 UniversalConstants Library (v1.0.0)

**UniversalConstants** 是一个基于 C++17 打造的**常用常数库**。

本项目创新性地采用了 **“括号控位语法”`NAME(digits)`**，完美实现了接口的终极统一。无论是面对纯数学理论的无限精度计算，还是面对人类物理实验测量的极限截断，本库都能动态调配底层算力，优雅丝滑地支撑你的每一场高精度科研和工程运算。

---

## ⚡ 核心特性
1. **按需算力，控位随心**：括号里写几，拿到的就是小数点后多少位（例如 `PI(3600000)`）。
2. **纯大数对齐，绝无类型降级**：所有函数均返回 GMP 标准的 `mpf_class` 浮点对象，杜绝了普通 `double` 的精度污染。
3. **已知的全常数全覆盖**：收录了目前科学界已知、在工程与科研高频会用到的数十个核心与数论冷门常数。

---

## 📂 完整函数字典与使用指南

本库通过命名空间将常数分为两大阵营，所有函数均接受一个 `long long` 类型的参数（表示所需的小数点后位数）。

### 1. 🌀 理论数学常数空间 (`UniversalConstants::Math`)
此类常数属于纯数学理论，支持括号内输入**无限大精度**（由于算法高度优化，你的家用电脑几秒内即可秒杀数百万位）。

| 函数调用语法 | 常数名称（中文说明） | 数学公式 / 底层算法引擎 |
| :--- | :--- | :--- |
| `PI(digits)` | **圆周率 $\pi$** | 内置顶级 Chudnovsky 二进制分割递归引擎 |
| `TAU(digits)` | **圆周率倍数 $\tau$** | 自动对齐 $2 \times \pi$ 精度 |
| `E(digits)` | **自然对数的底 $e$** | 内置泰勒级数（Taylor Series）逼近算法 |
| `PHI(digits)` | **黄金分割比 $\phi$** | 现场进行大数级无损开方: $(1 + \sqrt{5}) / 2$ |
| `SILVER(digits)` | **白银分割比** | 现场无损大数开方: $1 + \sqrt{2}$ |
| `SQRT2(digits)` | **根号 2** | 触发 GMP 原生内部最高精度开方引擎: $\sqrt{2}$ |
| `SQRT3(digits)` | **根号 3** | 触发 GMP 原生内部最高精度开方引擎: $\sqrt{3}$ |
| `SQRT5(digits)` | **根号 5** | 触发 GMP 原生内部最高精度开方引擎: $\sqrt{5}$ |
| `PLASTIC(digits)` | **塑料常数** | 预存极高精度解（超出位宽自动补零对齐） |
| `LN2(digits)` | **2 的自然对数** | 采用经典的级数展开高精度逼近求解 |
| `LN10(digits)` | **10 的自然对数** | 采用经典的级数展开高精度逼近求解 |
| `GAMMA(digits)` | **欧拉-马歇罗尼常数** | 收录高等数学调和级数差值极限的高精预存值 |
| `GELFOND(digits)` | **格尔丰德常数** | 数论知名常数 $e^\pi$ 的极高精预存值 |
| `CATALAN(digits)` | **卡塔兰常数** | 组合数学核心常数的最高精预存封装 |
| `APERY(digits)` | **阿佩里常数** | 黎曼 $\zeta(3)$ 函数的精确高精预存值 |
| `GAUSS(digits)` | **高斯常数** | 算术几何平均数核心的高精预存封装 |
| `KHINCHIN(digits)` | **辛钦常数** | 连分数理论终极常数的高精预存封装 |
| `GLAISHER(digits)` | **格莱舍-金克林常数** | 含有阶乘和级数的高等数学常数高精封装 |
| `DOTTIE(digits)` | **多蒂数** | 经典代数方程 $\cos(x)=x$ 的唯一实根高精预存 |
| `FEIGENBAUM_DELTA(digits)`| **费根鲍姆分叉常数** | 混沌学/非线性物理第一核心常数高精封装 |
| `FEIGENBAUM_ALPHA(digits)`| **费根鲍姆缩放常数** | 混沌学倍周期分叉的核心指标高精封装 |
| `TWIN_PRIME(digits)` | **孪生素数常数** | 解析数论/孪生素数猜想的核心常数高精封装 |
| `LANDAU_RAMANUJAN(digits)`| **兰道-拉马努金常数** | 数论中关于整数平方和分布的极高精封装 |

### 2. 🔬 物理与通用工程常数空间 (`UniversalConstants::Physics`)
此类常数受限于目前人类科学实验探测的物理极限。当用户指定的 `digits` 超出实验精度上限时，本库会自动提供目前人类科技已知的最精确固定值，超出的位数自动补零对齐。

| 函数调用语法 | 常数名称（中文说明） | 国际标准 CODATA 物理量纲值 |
| :--- | :--- | :--- |
| `C(digits)` | **真空光速 $c$** | $299792458 \text{ m/s}$（绝对定义值，无限精度） |
| `G(digits)` | **万有引力常数 $G$** | $6.67430 \times 10^{-11} \text{ m}^3/(\text{kg}\cdot\text{s}^2)$ |
| `STANDARD_G(digits)` | **地表标准重力加速度** | $9.80665 \text{ m/s}^2$（工业标准值） |
| `HUBBLE(digits)` | **哈勃常数** | $67.4 \text{ km/s/Mpc}$（现代天文学膨胀率极限测值） |
| `COSMOLOGICAL_CONSTANT(digits)`| **宇宙学常数** | $2.846 \times 10^{-122}$（量子真空能量上限测值） |
| `H(digits)` | **普朗克常数 $h$** | $6.62607015 \times 10^{-34} \text{ J}\cdot\text{s}$（现代国际单位制定义值） |
| `H_BAR(digits)` | **约化普朗克常数 $\hbar$** | $1.054571817 \times 10^{-34} \text{ J}\cdot\text{s}$ |
| `E_CHARGE(digits)` | **元电荷量 $e$** | $1.602176634 \times 10^{-19} \text{ C}$（单电子电量定义值） |
| `VACUUM_PERMITTIVITY(digits)`| **真空介电常数 $\varepsilon_0$** | $8.8541878128 \times 10^{-12} \text{ F/m}$（电磁学基石） |
| `VACUUM_PERMEABILITY(digits)`| **真空磁导率 $\mu_0$** | $1.25663706212 \times 10^{-6} \text{ N/A}^2$（电磁学基石） |
| `FINE_STRUCTURE(digits)` | **精细结构常数 $\alpha$**| $7.2973525643 \times 10^{-3}$（量子电动力学核心无量纲常数） |
| `COULOMB_K(digits)` | **库仑常数 $k_e$** | $8.987742438 \times 10^9 \text{ N}\cdot\text{m}^2/\text{C}^2$ |
| `BOHR_MAGNETON(digits)`| **玻尔磁子** | $9.274010078 \times 10^{-24} \text{ J/T}$ |
| `ELECTRON_MASS(digits)`| **电子静止质量 $m_e$** | $9.1093837015 \times 10^{-31} \text{ kg}$ |
| `PROTON_MASS(digits)` | **质子静止质量 $m_p$** | $1.67262192369 \times 10^{-27} \text{ kg}$ |
| `NEUTRON_MASS(digits)`| **中子静止质量 $m_n$** | $1.67492749804 × 10^{-27} \text{ kg}$ |
| `BOHR_RADIUS(digits)` | **玻尔半径 $a_0$** | $5.29177210903 \times 10^{-11} \text{ m}$ |
| `ELECTRON_RADIUS(digits)`| **经典电子半径** | $2.8179403262 \times 10^{-15} \text{ m}$ |
| `RYDBERG_CONSTANT(digits)`| **里德伯常数 $R_\infty$** | $10973731.56816 \text{ m}^{-1}$ |
| `NA(digits)` | **阿伏伽德罗常数 $N_A$**| $6.02214076 \times 10^{23} \text{ mol}^{-1}$ |
| `KB(digits)` | **玻尔兹曼常数 $k_B$** | $1.380649 \times 10^{-23} \text{ J/K}$ |
| `R_GAS(digits)` | **摩尔气体常数 $R$** | $8.314462618 \text{ J}/(\text{mol}\cdot\text{K})$ |
| `FARADAY(digits)` | **法拉第常数 $F$** | $96485.33212 \text{ C/mol}$（电化学核心指标） |
| `STEFAN_BOLTZMANN(digits)`| **斯特藩-玻尔兹曼常数**| $5.670374419 \times 10^{-8} \text{ W}/(\text{m}^2\cdot\text{K}^4)$ |
| `WIEN(digits)` | **维恩位移常数** | $2.897771955 \times 10^{-3} \text{ m}\cdot\text{K}$ |
| `AU(digits)` | **天文单位 $\text{au}$** | $149597870700 \text{ m}$（日地平均距离定义值） |
| `LIGHT_YEAR(digits)` | **光年** | $9460730472580800 \text{ m}$ |
| `PARSEC(digits)` | **秒差距 $\text{pc}$** | $3.085677581 \times 10^{16} \text{ m}$ |
| `SOLAR_MASS(digits)` | **太阳质量** | $1.98847 \times 10^{30} \text{ kg}$ |
| `EARTH_MASS(digits)` | **地球质量** | $5.9722 \times 10^{24} \text{ kg}$ |

---

## 🛠️ 极其优雅的代码范例（新项目怎么调用）

只要在新项目的源文件（如 `main.cpp`）里 `#include "UniversalConstants.h"`，就能享受到极致现代的 C++ 调用体验：

```cpp
#include <iostream>
#include "UniversalConstants.h"

// 优雅引入命名空间
using namespace UniversalConstants::Math;
using namespace UniversalConstants::Physics;

int main() {
    // 示例 1: 括号写几就是几位！现场调用 Chudnovsky 引擎计算 360 万位圆周率
    mpf_class huge_pi = PI(3600000); 
    
    // 示例 2: 动态现场生成 1000 位高精度自然常数 E
    mpf_class high_res_e = E(1000); 
    std::cout << "E (前50位展示): " << high_res_e << std::endl;

    // 示例 3: 提取高精度微观量子和宏观天文常数
    mpf_class planck = H(100);       // 100位有效数位对齐
    mpf_class speed = C(100);        // 100位光速
    std::cout << "真空光速 c = " << speed << " m/s" << std::endl;

    // 示例 4: 跨领域常数混合无损高精度数学运算
    mpf_class quantum_gravity = (H_BAR(50) * G(50)) / (C(50) * C(50) * C(50));
    std::cout << "普朗克面积级别组合运算结果: " << quantum_gravity << std::endl;

    return 0;
}
```

---

## 🏗️ 在你的项目中进行编译与链接
你在新项目的 `CMakeLists.txt` 中只需要如此配置即可一键链接起飞：

```cmake
cmake_minimum_required(VERSION 3.15)
project(MyApp LANGUAGES CXX)

# 假设用户把你的库 clone 到了 external/UniversalConstants 目录下
add_subdirectory(external/UniversalConstants)

add_executable(main main.cpp)

# 链接你的库，因为你设置了 PUBLIC，用户不需要再手动写 GMP
target_link_libraries(main PRIVATE UniversalConstants)
```

---

当然，绝大多数程序员根本用不到“现场计算 360 万位圆周率”，大家只需要一个 `3.1415926` 就够了，所以不太用为了这个去装 GMP。

💡 *Developed with passion for extreme numeric computation. Managed securely by CMake Static Architecture.*
