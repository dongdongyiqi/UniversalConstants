<h1>🌌 UniversalConstants Library (v1.0.0)</h1>

<p><strong>UniversalConstants</strong> 是一个基于 C++17 打造的<strong>常用常数库</strong>。</p>

<p>本项目创新性地采用了 <strong>“括号控位语法”<code>NAME(digits)</code></strong>，完美实现了接口的终极统一。无论是面对纯数学理论的无限精度计算，还是面对人类物理实验测量的极限截断，本库都能动态调配底层算力，优雅丝滑地支撑你的每一场高精度科研和工程运算。</p>

<blockquote>
<p>💡 <strong>双模式支持</strong>：本项目提供两种使用方式。如果你只需要普通精度的常用常数（<strong>不想安装任何依赖</strong>），请直接使用 <strong>[轻量免安装版]</strong>；如果你需要动态计算数百万位的极限精度，请使用 <strong>[GMP 硬核版]</strong>。</p>
</blockquote>

<hr>

<h2>🛠️ 快速上手（两套方案任选）</h2>

<h3>方案 A：轻量免安装版（强烈推荐普通用户使用）</h3>

<p>如果你不想折腾环境，只需将仓库中的 <code>BasicConstants.h</code> 复制到你的项目目录即可，<strong>零依赖，开箱即用</strong>。</p>

<pre><code>#include &lt;iostream&gt;
#include "BasicConstants.h" // 直接包含即可，无需安装任何第三方库

int main() {
    // 直接获取 double 级别的高精度常数
    double pi = BasicConstants::PI;
    double light_speed = BasicConstants::C;
    
    std::cout &lt;&lt; "PI: " &lt;&lt; pi &lt;&lt; std::endl;
    std::cout &lt;&lt; "光速: " &lt;&lt; light_speed &lt;&lt; " m/s" &lt;&lt; std::endl;
    return 0;
}
</code></pre>

<h3>方案 B：GMP 硬核动态精度版（适合科研与极限计算）</h3>

<p>本模式依赖 GMP（GNU Multiple Precision Arithmetic Library）进行无限精度浮点运算。</p>

<h4>1. 依赖要求</h4>
<p>请确保你的系统已安装 GMP：</p>
<ul>
<li><strong>macOS</strong>: <code>brew install gmp</code></li>
<li><strong>Ubuntu/Debian</strong>: <code>sudo apt install libgmp-dev</code></li>
<li><strong>Windows</strong>: 建议使用 <code>vcpkg install gmp</code> 或通过 MSYS2 安装。</li>
</ul>

<h4>2. 代码范例</h4>
<p>引入 <code>UniversalConstants.h</code>，享受极致现代的 C++ 调用体验：</p>

<pre><code>#include &lt;iostream&gt;
#include "UniversalConstants.h"

using namespace UniversalConstants::Math;
using namespace UniversalConstants::Physics;

int main() {
    // 括号写几就是几位！现场调用顶级引擎计算 360 万位圆周率
    mpf_class huge_pi = PI(3600000); 
    
    // 动态现场生成 1000 位高精度自然常数 E
    mpf_class high_res_e = E(1000); 
    
    // 跨领域常数混合无损高精度数学运算
    mpf_class quantum_gravity = (H_BAR(50) * G(50)) / (C(50) * C(50) * C(50));
    std::cout &lt;&lt; "运算结果: " &lt;&lt; quantum_gravity &lt;&lt; std::endl;

    return 0;
}
</code></pre>

<h4>3. 在你的 CMake 项目中集成（硬核版）</h4>
<p>假设你将本仓库克隆到了 <code>external/UniversalConstants</code> 目录下。在你的项目 <code>CMakeLists.txt</code> 中：</p>

<pre><code>cmake_minimum_required(VERSION 3.15)
project(MyApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# 将本库作为子目录加入
add_subdirectory(external/UniversalConstants)

add_executable(MyApp main.cpp)

# 链接本库（PUBLIC 传递性会自动帮你链接 GMP，无需手动再写）
target_link_libraries(MyApp PRIVATE UniversalConstants)
</code></pre>

<p><em>⚠️ 注意：如果你没有安装 GMP，CMake 配置阶段会直接报错。请按照上方的“依赖要求”安装好 GMP 后重试。</em></p>

<hr>

<h2>📂 完整函数字典与使用指南 (GMP 硬核版)</h2>

<p>本库通过命名空间将常数分为两大阵营，所有函数均接受一个 <code>long long</code> 类型的参数（表示所需的小数点后位数）。</p>

<h3>1. 🌀 理论数学常数空间 (<code>UniversalConstants::Math</code>)</h3>
<p>此类常数属于纯数学理论，支持括号内输入<strong>无限大精度</strong>（由于算法高度优化，你的家用电脑几秒内即可秒杀数百万位）。</p>

<table>
<thead>
<tr>
<th>函数调用语法</th>
<th>常数名称（中文说明）</th>
<th>数学公式 / 底层算法引擎</th>
</tr>
</thead>
<tbody>
<tr><td><code>PI(digits)</code></td><td><strong>圆周率 π</strong></td><td>内置顶级 Chudnovsky 二进制分割递归引擎</td></tr>
<tr><td><code>TAU(digits)</code></td><td><strong>圆周率倍数 τ</strong></td><td>自动对齐 2×π 精度</td></tr>
<tr><td><code>E(digits)</code></td><td><strong>自然对数的底 e</strong></td><td>内置泰勒级数（Taylor Series）逼近算法</td></tr>
<tr><td><code>PHI(digits)</code></td><td><strong>黄金分割比 φ</strong></td><td>现场进行大数级无损开方: (1 + √5) / 2</td></tr>
<tr><td><code>SILVER(digits)</code></td><td><strong>白银分割比</strong></td><td>现场无损大数开方: 1 + √2</td></tr>
<tr><td><code>SQRT2(digits)</code></td><td><strong>根号 2</strong></td><td>触发 GMP 原生内部最高精度开方引擎: √2</td></tr>
<tr><td><code>SQRT3(digits)</code></td><td><strong>根号 3</strong></td><td>触发 GMP 原生内部最高精度开方引擎: √3</td></tr>
<tr><td><code>SQRT5(digits)</code></td><td><strong>根号 5</strong></td><td>触发 GMP 原生内部最高精度开方引擎: √5</td></tr>
<tr><td><code>PLASTIC(digits)</code></td><td><strong>塑料常数</strong></td><td>预存极高精度解（超出位宽自动补零对齐）</td></tr>
<tr><td><code>LN2(digits)</code></td><td><strong>2 的自然对数</strong></td><td>采用经典的级数展开高精度逼近求解</td></tr>
<tr><td><code>LN10(digits)</code></td><td><strong>10 的自然对数</strong></td><td>采用经典的级数展开高精度逼近求解</td></tr>
<tr><td><code>GAMMA(digits)</code></td><td><strong>欧拉-马歇罗尼常数</strong></td><td>收录高等数学调和级数差值极限的高精预存值</td></tr>
<tr><td><code>GELFOND(digits)</code></td><td><strong>格尔丰德常数</strong></td><td>数论知名常数 e^π 的极高精预存值</td></tr>
<tr><td><code>CATALAN(digits)</code></td><td><strong>卡塔兰常数</strong></td><td>组合数学核心常数的最高精预存封装</td></tr>
<tr><td><code>APERY(digits)</code></td><td><strong>阿佩里常数</strong></td><td>黎曼 ζ(3) 函数的精确高精预存值</td></tr>
<tr><td><code>GAUSS(digits)</code></td><td><strong>高斯常数</strong></td><td>算术几何平均数核心的高精预存封装</td></tr>
<tr><td><code>KHINCHIN(digits)</code></td><td><strong>辛钦常数</strong></td><td>连分数理论终极常数的高精预存封装</td></tr>
<tr><td><code>GLAISHER(digits)</code></td><td><strong>格莱舍-金克林常数</strong></td><td>含有阶乘和级数的高等数学常数高精封装</td></tr>
<tr><td><code>DOTTIE(digits)</code></td><td><strong>多蒂数</strong></td><td>经典代数方程 cos(x)=x 的唯一实根高精预存</td></tr>
<tr><td><code>FEIGENBAUM_DELTA(digits)</code></td><td><strong>费根鲍姆分叉常数</strong></td><td>混沌学/非线性物理第一核心常数高精封装</td></tr>
<tr><td><code>FEIGENBAUM_ALPHA(digits)</code></td><td><strong>费根鲍姆缩放常数</strong></td><td>混沌学倍周期分叉的核心指标高精封装</td></tr>
<tr><td><code>TWIN_PRIME(digits)</code></td><td><strong>孪生素数常数</strong></td><td>解析数论/孪生素数猜想的核心常数高精封装</td></tr>
<tr><td><code>LANDAU_RAMANUJAN(digits)</code></td><td><strong>兰道-拉马努金常数</strong></td><td>数论中关于整数平方和分布的极高精封装</td></tr>
</tbody>
</table>

<h3>2. 🔬 物理与通用工程常数空间 (<code>UniversalConstants::Physics</code>)</h3>
<p>此类常数受限于目前人类科学实验探测的物理极限。当用户指定的 <code>digits</code> 超出实验精度上限时，本库会自动提供目前人类科技已知的最精确固定值，超出的位数自动补零对齐。</p>

<table>
<thead>
<tr>
<th>函数调用语法</th>
<th>常数名称（中文说明）</th>
<th>国际标准 CODATA 物理量纲值</th>
</tr>
</thead>
<tbody>
<tr><td><code>C(digits)</code></td><td><strong>真空光速 c</strong></td><td>299792458 m/s（绝对定义值，无限精度）</td></tr>
<tr><td><code>G(digits)</code></td><td><strong>万有引力常数 G</strong></td><td>6.67430 × 10^-11 m^3/(kg·s^2)</td></tr>
<tr><td><code>STANDARD_G(digits)</code></td><td><strong>地表标准重力加速度</strong></td><td>9.80665 m/s^2（工业标准值）</td></tr>
<tr><td><code>HUBBLE(digits)</code></td><td><strong>哈勃常数</strong></td><td>67.4 km/s/Mpc（现代天文学膨胀率极限测值）</td></tr>
<tr><td><code>COSMOLOGICAL_CONSTANT(digits)</code></td><td><strong>宇宙学常数</strong></td><td>2.846 × 10^-122（量子真空能量上限测值）</td></tr>
<tr><td><code>H(digits)</code></td><td><strong>普朗克常数 h</strong></td><td>6.62607015 × 10^-34 J·s（现代国际单位制定义值）</td></tr>
<tr><td><code>H_BAR(digits)</code></td><td><strong>约化普朗克常数 ħ</strong></td><td>1.054571817 × 10^-34 J·s</td></tr>
<tr><td><code>E_CHARGE(digits)</code></td><td><strong>元电荷量 e</strong></td><td>1.602176634 × 10^-19 C（单电子电量定义值）</td></tr>
<tr><td><code>VACUUM_PERMITTIVITY(digits)</code></td><td><strong>真空介电常数 ε₀</strong></td><td>8.8541878128 × 10^-12 F/m（电磁学基石）</td></tr>
<tr><td><code>VACUUM_PERMEABILITY(digits)</code></td><td><strong>真空磁导率 μ₀</strong></td><td>1.25663706212 × 10^-6 N/A^2（电磁学基石）</td></tr>
<tr><td><code>FINE_STRUCTURE(digits)</code></td><td><strong>精细结构常数 α</strong></td><td>7.2973525643 × 10^-3（量子电动力学核心无量纲常数）</td></tr>
<tr><td><code>COULOMB_K(digits)</code></td><td><strong>库仑常数 k_e</strong></td><td>8.987742438 × 10^9 N·m^2/C^2</td></tr>
<tr><td><code>BOHR_MAGNETON(digits)</code></td><td><strong>玻尔磁子</strong></td><td>9.274010078 × 10^-24 J/T</td></tr>
<tr><td><code>ELECTRON_MASS(digits)</code></td><td><strong>电子静止质量 m_e</strong></td><td>9.1093837015 × 10^-31 kg</td></tr>
<tr><td><code>PROTON_MASS(digits)</code></td><td><strong>质子静止质量 m_p</strong></td><td>1.67262192369 × 10^-27 kg</td></tr>
<tr><td><code>NEUTRON_MASS(digits)</code></td><td><strong>中子静止质量 m_n</strong></td><td>1.67492749804 × 10^-27 kg</td></tr>
<tr><td><code>BOHR_RADIUS(digits)</code></td><td><strong>玻尔半径 a_0</strong></td><td>5.29177210903 × 10^-11 m</td></tr>
<tr><td><code>ELECTRON_RADIUS(digits)</code></td><td><strong>经典电子半径</strong></td><td>2.8179403262 × 10^-15 m</td></tr>
<tr><td><code>RYDBERG_CONSTANT(digits)</code></td><td><strong>里德伯常数 R_∞</strong></td><td>10973731.56816 m^-1</td></tr>
<tr><td><code>NA(digits)</code></td><td><strong>阿伏伽德罗常数 N_A</strong></td><td>6.02214076 × 10^23 mol^-1</td></tr>
<tr><td><code>KB(digits)</code></td><td><strong>玻尔兹曼常数 k_B</strong></td><td>1.380649 × 10^-23 J/K</td></tr>
<tr><td><code>R_GAS(digits)</code></td><td><strong>摩尔气体常数 R</strong></td><td>8.314462618 J/(mol·K)</td></tr>
<tr><td><code>FARADAY(digits)</code></td><td><strong>法拉第常数 F</strong></td><td>96485.33212 C/mol（电化学核心指标）</td></tr>
<tr><td><code>STEFAN_BOLTZMANN(digits)</code></td><td><strong>斯特藩-玻尔兹曼常数</strong></td><td>5.670374419 × 10^-8 W/(m^2·K^4)</td></tr>
<tr><td><code>WIEN(digits)</code></td><td><strong>维恩位移常数</strong></td><td>2.897771955 × 10^-3 m·K</td></tr>
<tr><td><code>AU(digits)</code></td><td><strong>天文单位 au</strong></td><td>149597870700 m（日地平均距离定义值）</td></tr>
<tr><td><code>LIGHT_YEAR(digits)</code></td><td><strong>光年</strong></td><td>9460730472580800 m</td></tr>
<tr><td><code>PARSEC(digits)</code></td><td><strong>秒差距 pc</strong></td><td>3.085677581 × 10^16 m</td></tr>
<tr><td><code>SOLAR_MASS(digits)</code></td><td><strong>太阳质量</strong></td><td>1.98847 × 10^30 kg</td></tr>
<tr><td><code>EARTH_MASS(digits)</code></td><td><strong>地球质量</strong></td><td>5.9722 × 10^24 kg</td></tr>
</tbody>
</table>

<hr>

<h2>💡 关于本项目定位</h2>

<p>本项目的硬核版是为<strong>真正需要高精度数值计算</strong>的场景（如计算物理、密码学、高精度数学研究）打造的。它非常适合需要动态控制小数位数的硬核科研和工程运算。如果你只是需要一个普通的 <code>double</code> 级别精度（3.1415926），推荐直接使用源码中的 <code>BasicConstants.h</code>，无需引入 GMP。</p>

<p>💡 <em>Developed with passion for extreme numeric computation. Managed securely by CMake Static Architecture.</em></p>
