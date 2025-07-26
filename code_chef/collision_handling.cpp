// collisoin handling -> 

// 1. Chaining -> if collision ouccers at a index make that index
// point to a linked list etc and store the ones coliding over there 
// when you want to retrieve the element just search the linked list for
// the required elements.

// 2. Open address
// a. Linear Probing -> when collision ouccers just do a linear search 
// in the places ahed to check which is empty and store the element there 
// if after that you insert other element and it clashes then repeate the same
// also to find elements first use the traditional method otherwise linear probing

// b. quadratic probing -> unlike linear that moved '1' step at a time this move via a 
// quadratic equation like i^2 so like say if collision ouccered on index i then it would
// move i + 1^2 still not then i + 2^2 ... i + 3^2 and so on ... till found this avoid clustring 
