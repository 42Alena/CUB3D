## DDA: Digital Differential Analysis
- fast algorithm 
- typically used on square grids to find which squares a line hits

### Player = vector with direction
the position of the player is always a vector (an x and a y coordinate),
the direction is now determinated by two values: the x and y coordinate of the direction.
 A direction vector can be seen as follows: if you draw a line in the direction the player looks, through the position of the player, then every point of the line is the sum of the position of the player, and a multiple of the direction vector. 
 The length of a direction vector doesn't really matter, only its direction. Multiplying x and y by the same value changes the length but keeps the same direction.

 ### Camera Plane Vector
 This method with vectors also requires an extra vector, which is the camera plane vector.

### How to calculate a ray

FOV: Field Of View
The ray starts at the position of the player (posX, posY).
