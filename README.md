# Ray Tracing in One Weekend

A simple ray tracer made in a weekend.

## Online Book

- https://github.com/RayTracing/raytracing.github.io
- https://raytracing.github.io/books/RayTracingInOneWeekend.html

## .bmp

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

## Repos

- https://github.com/MetalheadKen/RayTracingInOneWeekend
- https://github.com/carld/ray-tracer
- https://github.com/AngusLang/rayt

## References

- https://en.wikipedia.org/wiki/Dot_product
- https://stats.stackexchange.com/questions/137907/division-of-vectors
- http://www.r-tutor.com/r-introduction/vector/vector-arithmetics
- https://physics.stackexchange.com/questions/111652/can-we-divide-two-vectors
- https://mathworld.wolfram.com/VectorDivision.html

## Docs

- https://en.wikipedia.org/wiki/Extended_ASCII
- https://en.cppreference.com/w/cpp/io/manip/flush
- https://www.cplusplus.com/reference/cstdio/printf/

## Resources

- https://stackoverflow.com/questions/4264127/correct-format-specifier-for-double-in-printf
- https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm
- https://overiq.com/c-programming-101/fwrite-function-in-c/
- https://stackoverflow.com/questions/13252697/writing-bits-to-a-file-in-c
- https://www.tutorialspoint.com/c_standard_library/c_function_perror.htm
- https://stackoverflow.com/questions/39002052/how-i-can-print-to-stderr-in-c
- https://www.geeksforgeeks.org/use-fflushstdin-c/
