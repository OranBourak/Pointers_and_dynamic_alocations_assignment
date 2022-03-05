# Pointers_assignment
Introduction to computer Science - Ex.4 - Pointers , Dynamic allocations, Strings. written in C 


1. String_Pointers -

  str_statistics - void type - recieves char array and 3 pointers to int type initiated to 0. calcutes how many letters (Capital/Lower case), numbers there are in a certain string input. [Assumptions that strings are in maximum length of 50 chars.]

-------------

2. 1 Dim dynamic allocation - 

  divide - returns int pointer type - function recieves 2 int arrays a and b and their size. 
  allocates a 3rd int array with the size of array b, for every cell it calcutes the number of elements 
  in a that devide by every element in b.
  returns the allocated array to main function which releases the allocated array after printed.
  
-------------

3. 2 Dim dynamic allocation -
  
  shrink - returns long pointer to pointer type - function recieves a 2 dim array of unsigned int if
  size is uneven returns null, else allocates a 2 dim array with size/2 as size, and every element is
  built as a number that contains a[2i][2j] as the most significant number, a[2i][2j+1] next,
  a[2i+1][2j], and a[2i+1][2j+1]. e.g - {{12,13},{14,15}} --> {12131415}
  
  returns to main function which prints the array and releases memory.
  
  -------------
  4. Array of strings - 
  
    init_arr - returns a pointer to char pointers. initiates a pointer to char pointers
    if failed returns null else returns the pointer.
    
    add - recieves a pointer to char pointers and its size and a 2nd string, if the string is not 
    in the array, creates a new array that contains all elements from old array and the string and
    updates size. else if it's in the array or the allocation failed returns null.
    
    twice - recieves a pointer to char pointers, size and an index, if the index is in range the
    the function doubles the word in that index. e.g - arr = {"one","two"} index = 1 --> arr =
    {"one,"twotwo"}
    else it doesn't change the array.
    
    find - recieves a pointer to char pointers, size and another string. if the string is in the
    array returns the index, else returns -1.
    
    print - recieves a pointer to char pointers and size. and prints.
    
    main function - Menu of the following. 
    first asks how many words would you like to initiate the starting array of strings.
    and then manipulates the array.
    releases memory at the end of the program.
