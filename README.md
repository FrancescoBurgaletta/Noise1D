# A simple 1D procedural noise function

This is a simple implementation of one dimensional procedural noise, mostly useful in graphics to generate seamless textures and all sorts of effects. Here i wanted to study the basic concepts that are fundamental to anyone undertaking the task of creating procedural textures.

Many kinds of [noise functions](https://physbam.stanford.edu/cs448x/old/Procedural_Noise(2f)Categories.html) exist: value noise interpolates values sampled in a pseudorandom fashion on integer grid points with a cubic polynomial, gradient noise does the same thing but with the first derivative (Perlin noise and Simplex noise are two examples of gradient noise), value-gradient noise samples both the value and the first derivative.

This noise function not only samples both the value and the first derivative, but also the second derivative, which is crucial for the seamlessness of optical effects on the texture surface. This is how it works:

1. Value, first and second derivatives are sampled using a hash function for both the floor and the ceiling computed on the input value, and then mapped to [-1,1]. This yields a total of 6 values, which are guaranteed to be different from one another thanks to the hashing and are unique for each grid point.
2. A 5th degree polynomial is then constructed from the previously obtained 6 values, making this polynomial unique. The polynomial is constructed using 0 and 1 as base points to simplify the parameters computation.
3. The fractional part of the input value is computed and fed to the polynomial to give the final result.

Here is how the noise looks in different ranges:

![plot1](https://github.com/FrancescoBurgaletta/Noise1D/assets/143550199/e11ae587-dc2c-478c-9fca-e82c5df800b0)
![plot2](https://github.com/FrancescoBurgaletta/Noise1D/assets/143550199/91fe2f5a-8d85-4ea0-86f2-70e9437c4e77)
![plot3](https://github.com/FrancescoBurgaletta/Noise1D/assets/143550199/c26b1b8b-2cd8-4154-9553-4a0b4a412afd)
![plot4](https://github.com/FrancescoBurgaletta/Noise1D/assets/143550199/a77960cf-c428-443d-82ab-4ab6b99e3e6b)

And here is how a fractal noise obtained from the sum of 4 octaves looks like:

![plot5](https://github.com/FrancescoBurgaletta/Noise1D/assets/143550199/5e406b57-fc4d-48a3-b4db-befa4c4f89df)


<!--![plot](https://github.com/FrancescoBurgaletta/Noise1D/assets/143550199/c45c1678-6b75-4a00-9cd7-aa7fa5b3c798)-->
<!--![plot](https://github.com/FrancescoBurgaletta/Noise1D/assets/143550199/a11301f4-de90-432f-97e4-f805eaf56040)-->

## WARNING
The implemented noise function, like many other implementations, provides values that are slightly above 1 and below -1, so, in general, an accurate analysis on the analytical properties of the function must take place to provide upper and lower bounds such that the function will be scaled within [-1,1].

For now, the value 1.34375 seems to be the correct scaling factor, but further investigation might be needed.
