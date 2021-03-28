<h3 align="center">Ray Tracing in One Weekend</h3>

<div align="center">

[![norminette](https://github.com/librity/weekendrt/actions/workflows/norminette.yml/badge.svg)](https://github.com/librity/weekendrt/actions/workflows/norminette.yml)
![License](https://img.shields.io/github/license/librity/weekendrt?color=yellow)
![Code size in bytes](https://img.shields.io/github/languages/code-size/librity/weekendrt?color=blue)
![Lines of code](https://img.shields.io/tokei/lines/github/librity/weekendrt?color=blueviolet)
![Top language](https://img.shields.io/github/languages/top/librity/weekendrt?color=ff69b4)
![Last commit](https://img.shields.io/github/last-commit/librity/weekendrt?color=orange)

</div>

<p align="center"> A simple ray tracer made in a weekend.
  <br>
</p>

---

## 📝 Table of Contents

- [About](#about)
- [Installation](#getting_started)
- [Usage](#usage)
- [Math](#math)
- [Tests](#tests)
- [Github Actions](#github_actions)
- [Repos](#repos)
- [References](#references)
- [Docs](#docs)
- [Resources](#resources)
- [Markdown References](#markdown)

## 🧐 About <a name = "about"></a>

A plain C implementation of the Weekend Raytracer challenge.
I just followed the instructions layed out on the online book:

- https://github.com/RayTracing/raytracing.github.io
- https://raytracing.github.io/books/RayTracingInOneWeekend.html

## 🏁 Getting Started <a name = "getting_started"></a>

### ⚙️ Prerequisites

All you need is a shell and a C compiler like `gcc` or `clang`.

### 🖥️ Installing

Just clone the repo and run `make`:

```bashweekendrt
$ git clone https://github.com/librity/weekendrt.git
$ cd weekendrt
$ make example
```

A beautiful image should pop out of your terminal like magic.

## 🎈 Usage <a name="usage"></a>

<p align="center">
  <img src="gallery/candy.bmp" />
</p>

### 🖼️ Rendering `.bmp`

`ft_libbmp` implementation based on:

- https://engineering.purdue.edu/ece264/17au/hw/HW15
- https://github.com/marc-q/libbmp

```c
typedef struct {             // Total: 54 bytes
  uint16_t  type;             // Magic identifier: 0x4d42
  uint32_t  size;             // File size in bytes
  uint16_t  reserved1;        // Not used
  uint16_t  reserved2;        // Not used
  uint32_t  offset;           // Offset to image data in bytes from beginning of file (54 bytes)
  uint32_t  dib_header_size;  // DIB Header size in bytes (40 bytes)
  int32_t   width_px;         // Width of the image
  int32_t   height_px;        // Height of image
  uint16_t  num_planes;       // Number of color planes
  uint16_t  bits_per_pixel;   // Bits per pixel
  uint32_t  compression;      // Compression type
  uint32_t  image_size_bytes; // Image size in bytes
  int32_t   x_resolution_ppm; // Pixels per meter
  int32_t   y_resolution_ppm; // Pixels per meter
  uint32_t  num_colors;       // Number of colors
  uint32_t  important_colors; // Important colors
} BMPHeader;
```

<p align="center">
  <img src=".github/bitmap_hexdump.png" />
</p>

## 🧑‍🏫 Math <a name = "math"></a>

### ☀️ Rays

The linear interpolation of a line with a free variable `t` generates a ray:

<p align="center">
  <img src="https://latex.codecogs.com/png.image?\dpi{300}&space;\inline&space;\inline&space;\mathbf{P}(t)&space;=&space;\mathbf{A}&space;&plus;&space;t&space;\mathbf{b}&space;\quad&space;(I)" title="\inline \inline \mathbf{P}(t) = \mathbf{A} + t \mathbf{b} \quad (I)" />
</p>

`t` can be understood as the `translation` of the ray.

<p align="center">
  <img src=".github/ray_lerp.jpg" />
</p>

### 🔮 Spheres

An arbitrary point `P` is on the surface of a sphere centered in `C` with radius `r`
if and only if it satisfies the equation:

<p align="center">
  <img src="https://latex.codecogs.com/png.image?\dpi{300}&space;\inline&space;(\mathbf{P}&space;-&space;\mathbf{C})&space;\cdot&space;(\mathbf{P}&space;-&space;\mathbf{C})&space;=&space;(x&space;-&space;C_x)^2&space;&plus;&space;(y&space;-&space;C_y)^2&space;&plus;&space;(z&space;-&space;C_z)^2&space;=&space;r^2&space;\quad&space;(II)" title="\inline (\mathbf{P} - \mathbf{C}) \cdot (\mathbf{P} - \mathbf{C}) = (x - C_x)^2 + (y - C_y)^2 + (z - C_z)^2 = r^2 \quad (II)" />
</p>

An arbitrary ray `P(t)` of origin `A` and direction `b`
intersects a sphere centered in `C` if and only if
it has at least one root in:

<p align="center">
  <img src="https://latex.codecogs.com/png.image?\dpi{300}&space;\inline&space;t^2&space;\mathbf{b}&space;\cdot&space;\mathbf{b}&space;&space;&space;&space;&plus;&space;2t&space;\mathbf{b}&space;\cdot&space;(\mathbf{A}-\mathbf{C})&space;&plus;&space;(\mathbf{A}-\mathbf{C})&space;\cdot&space;(\mathbf{A}-\mathbf{C})&space;-&space;r^2&space;=&space;0&space;\quad&space;(III)&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;" title="\inline t^2 \mathbf{b} \cdot \mathbf{b} + 2t \mathbf{b} \cdot (\mathbf{A}-\mathbf{C}) + (\mathbf{A}-\mathbf{C}) \cdot (\mathbf{A}-\mathbf{C}) - r^2 = 0 \quad (III) " />
</p>

The above being a combination of equations `(I)` and `(II)`.

<p align="center">
  <img src=".github/ray_sphere_intersection.jpg" />
</p>

## ✅ Tests <a name = "tests"></a>

## 🐙 Github Actions <a name = "github_actions"></a>

[Norminette Github Action](https://github.com/AdrianWR/libft/blob/master/.github/workflows/norminette.yaml)
by [@AdrianWR](https://github.com/AdrianWR)

## ☁️ Repos <a name="repos"></a>

- https://github.com/marc-q/libbmp
- https://github.com/MetalheadKen/RayTracingInOneWeekend
- https://github.com/carld/ray-tracer
- https://github.com/AngusLang/rayt

## 🏫 References <a name="references"></a>

- https://en.wikipedia.org/wiki/Dot_product
- https://stats.stackexchange.com/questions/137907/division-of-vectors
- http://www.r-tutor.com/r-introduction/vector/vector-arithmetics
- https://physics.stackexchange.com/questions/111652/can-we-divide-two-vectors
- https://mathworld.wolfram.com/VectorDivision.html
- https://en.wikipedia.org/wiki/List_of_Unicode_characters

## 📚 Docs <a name="docs"></a>

- https://en.wikipedia.org/wiki/Extended_ASCII
- https://en.cppreference.com/w/cpp/io/manip/flush
- https://www.cplusplus.com/reference/cstdio/printf/

## 📝 Resources <a name="resources"></a>

- https://overiq.com/c-programming-101/fwrite-function-in-c/
- https://www.c-programming-simple-steps.com/typedef-in-c.html
- https://www.geeksforgeeks.org/use-fflushstdin-c/
- https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm
- https://www.tutorialspoint.com/c_standard_library/c_function_perror.htm
- https://stackoverflow.com/questions/4264127/correct-format-specifier-for-double-in-printf
- https://stackoverflow.com/questions/13252697/writing-bits-to-a-file-in-c
- https://stackoverflow.com/questions/39002052/how-i-can-print-to-stderr-in-c
- https://stackoverflow.com/questions/5248919/undefined-reference-to-sqrt-or-other-mathematical-functions
- https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences

## ⬇️ Markdown References <a name="markdown"></a>

- https://emojipedia.org/sun/
- https://jaantollander.com/post/scientific-writing-with-markdown/
- https://paperhive.org/help/markdown
- http://www.sciweavers.org/free-online-latex-equation-editor
- http://latex.codecogs.com/
- http://csrgxtu.github.io/2015/03/20/Writing-Mathematic-Fomulars-in-Markdown/
- https://en.wikibooks.org/wiki/LaTeX/Mathematics#Controlling_horizontal_spacing
