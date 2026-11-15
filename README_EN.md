<div align="center">
  <strong>English</strong> | <a href="./README_CN.md">简体中文</a>
</div>

<h1>🌌 UniversalConstants Library (v1.0.0)</h1>

<p><strong>UniversalConstants</strong> is a modern <strong>universal constants library</strong> built with C++17.</p>

<p>This library introduces an innovative <strong>"Parentheses Precision Syntax" <code>NAME(digits)</code></strong>, achieving ultimate interface unification. Whether you are performing arbitrary-precision calculations in pure mathematics or working within the experimental measurement limits of modern physics, UniversalConstants dynamically allocates underlying computing power to support your high-precision scientific and engineering workflows seamlessly.</p>

<blockquote>
<p>💡 <strong>Dual-Mode Support</strong>: This project offers two usage modes. If you only need standard double-precision constants (<strong>zero dependencies</strong>), use the <strong>[Lightweight Header-Only Mode]</strong>. If you need to dynamically compute millions of decimal places, use the <strong>[GMP Hardcore Mode]</strong>.</p>
</blockquote>

<hr>

<h2>🛠️ Quick Start (Choose Your Mode)</h2>

<h3>Mode A: Lightweight Zero-Dependency Mode (Recommended for General Use)</h3>

<p>If you don't want to configure external libraries, simply copy <code>BasicConstants.h</code> from this repository into your project directory. <strong>Zero dependencies, ready out of the box.</strong></p>

<pre><code>#include &lt;iostream&gt;
#include "BasicConstants.h" // Include directly, no third-party libraries required

int main() {
    // Retrieve standard double-precision constants directly
    double pi = BasicConstants::PI;
    double light_speed = BasicConstants::C;
    
    std::cout &lt;&lt; "PI: " &lt;&lt; pi &lt;&lt; std::endl;
    std::cout &lt;&lt; "Speed of Light: " &lt;&lt; light_speed &lt;&lt; " m/s" &lt;&lt; std::endl;
    return 0;
}
</code></pre>

<h3>Mode B: GMP Hardcore Dynamic-Precision Mode (For Scientific & Extreme Computing)</h3>

<p>This mode relies on GMP (GNU Multiple Precision Arithmetic Library) for arbitrary-precision floating-point arithmetic.</p>

<h4>1. Prerequisites</h4>
<p>Ensure GMP is installed on your system:</p>
<ul>
<li><strong>macOS</strong>: <code>brew install gmp</code></li>
<li><strong>Ubuntu/Debian</strong>: <code>sudo apt install libgmp-dev</code></li>
<li><strong>Windows</strong>: Recommended via <code>vcpkg install gmp</code> or MSYS2.</li>
</ul>

<h4>2. Code Example</h4>
<p>Include <code>UniversalConstants.h</code> for a clean, modern C++ experience:</p>

<pre><code>#include &lt;iostream&gt;
#include "UniversalConstants.h"

using namespace UniversalConstants::Math;
using namespace UniversalConstants::Physics;

int main() {
    // Specify exact decimal digits inside parentheses! Computes 3.6 million digits of Pi on the fly
    mpf_class huge_pi = PI(3600000); 
    
    // Dynamically generate Euler's number (e) to 1,000 decimal places
    mpf_class high_res_e = E(1000); 
    
    // Lossless cross-domain high-precision arithmetic
    mpf_class quantum_gravity = (H_BAR(50) * G(50)) / (C(50) * C(50) * C(50));
    std::cout &lt;&lt; "Result: " &lt;&lt; quantum_gravity &lt;&lt; std::endl;

    return 0;
}
</code></pre>

<h4>3. CMake Integration (Hardcore Mode)</h4>
<p>Assuming you have cloned this repository into <code>external/UniversalConstants</code>, add the following to your project's <code>CMakeLists.txt</code>:</p>

<pre><code>cmake_minimum_required(VERSION 3.15)
project(MyApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Add UniversalConstants as a subdirectory
add_subdirectory(external/UniversalConstants)

add_executable(MyApp main.cpp)

# Link the library (PUBLIC transitivity automatically links GMP for you)
target_link_libraries(MyApp PRIVATE UniversalConstants)
</code></pre>

<p><em>⚠️ Note: If GMP is not installed on your system, CMake will report an error during configuration. Please install GMP following the prerequisites above and try again.</em></p>

<hr>

<h2>📂 Complete Function Reference (GMP Hardcore Mode)</h2>

<p>Constants are organized into two namespaces. Every function accepts a <code>long long</code> argument specifying the desired number of decimal places.</p>

<h3>1. 🌀 Theoretical Mathematical Constants (<code>UniversalConstants::Math</code>)</h3>
<p>These constants belong to pure mathematics and support <strong>arbitrary precision</strong> (thanks to heavily optimized algorithms, modern consumer CPUs can compute millions of digits in seconds).</p>

<table>
<thead>
<tr>
<th>Function Syntax</th>
<th>Constant Name</th>
<th>Mathematical Formula / Underlying Engine</th>
</tr>
</thead>
<tbody>
<tr><td><code>PI(digits)</code></td><td><strong>Pi (π)</strong></td><td>Built-in Chudnovsky binary splitting recursive engine</td></tr>
<tr><td><code>TAU(digits)</code></td><td><strong>Tau (τ)</strong></td><td>Automatically aligned to 2×π precision</td></tr>
<tr><td><code>E(digits)</code></td><td><strong>Euler's Number (e)</strong></td><td>Built-in Taylor Series approximation algorithm</td></tr>
<tr><td><code>PHI(digits)</code></td><td><strong>Golden Ratio (φ)</strong></td><td>On-the-fly lossless big-number square root: (1 + √5) / 2</td></tr>
<tr><td><code>SILVER(digits)</code></td><td><strong>Silver Ratio</strong></td><td>On-the-fly lossless big-number square root: 1 + √2</td></tr>
<tr><td><code>SQRT2(digits)</code></td><td><strong>Square Root of 2</strong></td><td>Triggers GMP's native arbitrary-precision root engine: √2</td></tr>
<tr><td><code>SQRT3(digits)</code></td><td><strong>Square Root of 3</strong></td><td>Triggers GMP's native arbitrary-precision root engine: √3</td></tr>
<tr><td><code>SQRT5(digits)</code></td><td><strong>Square Root of 5</strong></td><td>Triggers GMP's native arbitrary-precision root engine: √5</td></tr>
<tr><td><code>PLASTIC(digits)</code></td><td><strong>Plastic Number</strong></td><td>Precomputed ultra-high-precision value (zero-padded beyond width)</td></tr>
<tr><td><code>LN2(digits)</code></td><td><strong>Natural Logarithm of 2</strong></td><td>High-precision series expansion approximation</td></tr>
<tr><td><code>LN10(digits)</code></td><td><strong>Natural Logarithm of 10</strong></td><td>High-precision series expansion approximation</td></tr>
<tr><td><code>GAMMA(digits)</code></td><td><strong>Euler–Mascheroni Constant</strong></td><td>Precomputed high-precision harmonic series limit</td></tr>
<tr><td><code>GELFOND(digits)</code></td><td><strong>Gelfond's Constant</strong></td><td>Precomputed high-precision value of e^π</td></tr>
<tr><td><code>CATALAN(digits)</code></td><td><strong>Catalan's Constant</strong></td><td>Precomputed high-precision combinatorics constant</td></tr>
<tr><td><code>APERY(digits)</code></td><td><strong>Apéry's Constant</strong></td><td>Precomputed high-precision value of Riemann ζ(3)</td></tr>
<tr><td><code>GAUSS(digits)</code></td><td><strong>Gauss's Constant</strong></td><td>Precomputed arithmetic–geometric mean constant</td></tr>
<tr><td><code>KHINCHIN(digits)</code></td><td><strong>Khinchin's Constant</strong></td><td>Precomputed continued fraction theory constant</td></tr>
<tr><td><code>GLAISHER(digits)</code></td><td><strong>Glaisher–Kinkelin Constant</strong></td><td>Precomputed hyperfactorial series constant</td></tr>
<tr><td><code>DOTTIE(digits)</code></td><td><strong>Dottie Number</strong></td><td>Unique real root of cos(x) = x</td></tr>
<tr><td><code>FEIGENBAUM_DELTA(digits)</code></td><td><strong>Feigenbaum Constant δ</strong></td><td>Bifurcation velocity constant in chaos theory</td></tr>
<tr><td><code>FEIGENBAUM_ALPHA(digits)</code></td><td><strong>Feigenbaum Constant α</strong></td><td>Period-doubling reduction parameter in chaos theory</td></tr>
<tr><td><code>TWIN_PRIME(digits)</code></td><td><strong>Twin Prime Constant</strong></td><td>Analytic number theory constant for twin primes</td></tr>
<tr><td><code>LANDAU_RAMANUJAN(digits)</code></td><td><strong>Landau–Ramanujan Constant</strong></td><td>Number theory constant for sums of two squares</td></tr>
</tbody>
</table>

<h3>2. 🔬 Physical & Engineering Constants (<code>UniversalConstants::Physics</code>)</h3>
<p>These constants are bounded by the limits of human experimental measurement. When the requested <code>digits</code> exceed current experimental precision, the library returns the most accurate CODATA value known to science and automatically zero-pads any remaining digits.</p>

<table>
<thead>
<tr>
<th>Function Syntax</th>
<th>Constant Name</th>
<th>CODATA Standard Value & Units</th>
</tr>
</thead>
<tbody>
<tr><td><code>C(digits)</code></td><td><strong>Speed of Light in Vacuum (c)</strong></td><td>299,792,458 m/s (Exact SI definition, infinite precision)</td></tr>
<tr><td><code>G(digits)</code></td><td><strong>Newtonian Constant of Gravitation (G)</strong></td><td>6.67430 × 10^-11 m^3/(kg·s^2)</td></tr>
<tr><td><code>STANDARD_G(digits)</code></td><td><strong>Standard Acceleration of Gravity</strong></td><td>9.80665 m/s^2 (Standard industrial value)</td></tr>
<tr><td><code>HUBBLE(digits)</code></td><td><strong>Hubble Constant</strong></td><td>67.4 km/s/Mpc (Modern cosmological measurement)</td></tr>
<tr><td><code>COSMOLOGICAL_CONSTANT(digits)</code></td><td><strong>Cosmological Constant</strong></td><td>2.846 × 10^-122 (Quantum vacuum energy limit)</td></tr>
<tr><td><code>H(digits)</code></td><td><strong>Planck Constant (h)</strong></td><td>6.62607015 × 10^-34 J·s (Exact SI definition)</td></tr>
<tr><td><code>H_BAR(digits)</code></td><td><strong>Reduced Planck Constant (ħ)</strong></td><td>1.054571817 × 10^-34 J·s</td></tr>
<tr><td><code>E_CHARGE(digits)</code></td><td><strong>Elementary Charge (e)</strong></td><td>1.602176634 × 10^-19 C (Exact SI definition)</td></tr>
<tr><td><code>VACUUM_PERMITTIVITY(digits)</code></td><td><strong>Vacuum Electric Permittivity (ε₀)</strong></td><td>8.8541878128 × 10^-12 F/m</td></tr>
<h3>2. 🔬 Physical & Engineering Constants (<code>UniversalConstants::Physics</code>)</h3>
<p>These constants are bounded by the limits of human experimental measurement. When the requested <code>digits</code> exceed current experimental precision, the library returns the most accurate CODATA value known to science and automatically zero-pads any remaining digits.</p>

<table>
<thead>
<tr>
<th>Function Syntax</th>
<th>Constant Name</th>
<th>CODATA Standard Value & Units</th>
</tr>
</thead>
<tbody>
<tr><td><code>C(digits)</code></td><td><strong>Speed of Light in Vacuum (c)</strong></td><td>299,792,458 m/s (Exact SI definition, infinite precision)</td></tr>
<tr><td><code>G(digits)</code></td><td><strong>Newtonian Constant of Gravitation (G)</strong></td><td>6.67430 × 10^-11 m^3/(kg·s^2)</td></tr>
<tr><td><code>STANDARD_G(digits)</code></td><td><strong>Standard Acceleration of Gravity</strong></td><td>9.80665 m/s^2 (Standard industrial value)</td></tr>
<tr><td><code>HUBBLE(digits)</code></td><td><strong>Hubble Constant</strong></td><td>67.4 km/s/Mpc (Modern cosmological measurement)</td></tr>
<tr><td><code>COSMOLOGICAL_CONSTANT(digits)</code></td><td><strong>Cosmological Constant</strong></td><td>2.846 × 10^-122 (Quantum vacuum energy limit)</td></tr>
<tr><td><code>H(digits)</code></td><td><strong>Planck Constant (h)</strong></td><td>6.62607015 × 10^-34 J·s (Exact SI definition)</td></tr>
<tr><td><code>H_BAR(digits)</code></td><td><strong>Reduced Planck Constant (ħ)</strong></td><td>1.054571817 × 10^-34 J·s</td></tr>
<tr><td><code>E_CHARGE(digits)</code></td><td><strong>Elementary Charge (e)</strong></td><td>1.602176634 × 10^-19 C (Exact SI definition)</td></tr>
<tr><td><code>VACUUM_PERMITTIVITY(digits)</code></td><td><strong>Vacuum Electric Permittivity (ε₀)</strong></td><td>8.8541878128 × 10^-12 F/m</td></tr>
<tr><td><code>VACUUM_PERMEABILITY(digits)</code></td><td><strong>Vacuum Magnetic Permeability (μ₀)</strong></td><td>1.25663706212 × 10^-6 N/A^2</td></tr>
<tr><td><code>FINE_STRUCTURE(digits)</code></td><td><strong>Fine-Structure Constant (α)</strong></td><td>7.2973525643 × 10^-3 (Dimensionless QED constant)</td></tr>
<tr><td><code>COULOMB_K(digits)</code></td><td><strong>Coulomb Constant (k_e)</strong></td><td>8.987742438 × 10^9 N·m^2/C^2</td></tr>
<tr><td><code>BOHR_MAGNETON(digits)</code></td><td><strong>Bohr Magneton</strong></td><td>9.274010078 × 10^-24 J/T</td></tr>
<tr><td><code>ELECTRON_MASS(digits)</code></td><td><strong>Electron Rest Mass (m_e)</strong></td><td>9.1093837015 × 10^-31 kg</td></tr>
<tr><td><code>PROTON_MASS(digits)</code></td><td><strong>Proton Rest Mass (m_p)</strong></td><td>1.67262192369 × 10^-27 kg</td></tr>
<tr><td><code>NEUTRON_MASS(digits)</code></td><td><strong>Neutron Rest Mass (m_n)</strong></td><td>1.67492749804 × 10^-27 kg</td></tr>
<tr><td><code>BOHR_RADIUS(digits)</code></td><td><strong>Bohr Radius (a_0)</strong></td><td>5.29177210903 × 10^-11 m</td></tr>
<tr><td><code>ELECTRON_RADIUS(digits)</code></td><td><strong>Classical Electron Radius</strong></td><td>2.8179403262 × 10^-15 m</td></tr>
<tr><td><code>RYDBERG_CONSTANT(digits)</code></td><td><strong>Rydberg Constant (R_∞)</strong></td><td>10973731.56816 m^-1</td></tr>
<tr><td><code>NA(digits)</code></td><td><strong>Avogadro Constant (N_A)</strong></td><td>6.02214076 × 10^23 mol^-1 (Exact SI definition)</td></tr>
<tr><td><code>KB(digits)</code></td><td><strong>Boltzmann Constant (k_B)</strong></td><td>1.380649 × 10^-23 J/K (Exact SI definition)</td></tr>
</tbody>
</table>

<hr>

<h2>🤝 Contributing & License</h2>
<p>Issues and Pull Requests are welcome! If you find this library helpful, please consider giving it a ⭐ <strong>Star</strong>.</p>
