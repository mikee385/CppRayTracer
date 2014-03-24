# Simple Ray Tracer - C++ #

The intention of this project is to have a meaningful program that I can recreate in other programming languages while I am learning them.

This program produces ray-traced images with various lighting effects, including diffuse and specular lighting, reflection, and refraction.  Spheres and planes are currently supported, along with spherical light sources.  Output images are produced in the PPM file format, due to its simplicity.  

I have no intention of making this an actively evolving project.  It exists solely for my own amusement and to help me learn.  I intend to eventually reproduce this program in programming languages that are new to me, e.g. Go, Rust.  This program contains some meaningful programming abstractions that will help me to test out various features of other programming languages, including:

- Data structures
- Generics 
- Recursion
- File I/O
- Concurrency

This will serve as the reference implementation for validation of any other implementations I produce.

The design of this program is entirely my own, but the concepts and ideas were heavily influenced by the following:

- Raytracing Topics & Techniques by Jacco Bikker ([http://www.flipcode.com/archives/Raytracing_Topics_Techniques-Part_1_Introduction.shtml](http://www.flipcode.com/archives/Raytracing_Topics_Techniques-Part_1_Introduction.shtml "http://www.flipcode.com/archives/Raytracing_Topics_Techniques-Part_1_Introduction.shtml"))
- 3D Basic Lessons ([http://www.scratchapixel.com/lessons/3d-basic-lessons/](http://www.scratchapixel.com/lessons/3d-basic-lessons/ "http://www.scratchapixel.com/lessons/3d-basic-lessons/"))
