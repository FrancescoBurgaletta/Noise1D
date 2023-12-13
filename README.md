# A simple 1D procedural noise function

This is a simple implementation of a one dimensional procedural noise function, mostly useful in graphics to generate seamless textures and all sorts of effects. Here i wanted to comprehend the basic concepts that are fundamental to anyone undertaking the task of creating procedural textures.
Many kinds of (noise functions)[https://physbam.stanford.edu/cs448x/old/Procedural_Noise(2f)Categories.html] exist: value noise interpolates values sampled on integer grid points in a pseudorandom fashion with a cubic polynomial, gradient noise does the same thing but with the first derivative (Perlin noise and Simplex noise are two examples of gradient noise), value-gradient noise samples both the value and the first derivative.
This noise function not only samples both the value and the first derivative, but also the second derivative, which is crucial for the seamlessness of optical effects on the texture surface.
This is how it works:

1. Value, first and second derivatives are sampled for both the floor and the ceiling computed on the input value. This is done by using a hash function as prng mapped to [-1,1]. This yields a total of 6 values, which are guaranteed to be different from one another thanks to the hashing and are unique for each grid point.
2. A 5th degree polynomial is then constructed from the previously obtained 6 values, which make this polynomial unique. The polynomial is constructed on 0 and 1 as grid points to simplify the computation of the parameters.
3. The fractional part of the input value is computed and fed to the polynomial to give the final result.

## WARNING
The implemented noise function provides values tht are slightly above 1 and below -1, so an accurate analysis on the analytical properties of the function must take place to provide upper and lower bounds such that the function will be tightly bounded within [-1,1].
