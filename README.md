### OPERATIONS:

###### Push A:

+shift all elements in array A down by 1.

+set the first element in array A to equal the first element of array B.

+shift all elements in array B up by 1.

###### Push B:

+shift all elements in array B down by 1.

+set the first element in array B to equal the first element of array A.

+shift all elements in array A up by 1.

###### Swap A:

+Set a temporary element to the first element in array A;

+Set the first element in array A to the second element in array A;

+Set the second element in array A to the temporary element;

###### Swap B:

+Set a temporary element to the first element in array B;

+Set the first element in array B to the second element in array B;

+Set the second element in array B to the temporary element;

###### Swap AB:

+call Swap A();

+call Swap B();

###### Rotate A:

+Set a temporary element to the last element in array A;

+Shift all elements in array A down by 1.

+Set the first element of array A to be equal to the temporary element.

###### Rotate B:

+Set a temporary element to the last element in array B;

+Shift all elements in array B down by 1.

+Set the first element of array B to be equal to the temporary element.

###### Rotate AB:

+call Rotate A();

+call Rotate B();

###### Reverse Rotate A:

+Set a temporary element to the first element in array A;

+Shift all elements in array A up by 1.

+Set the last element of array A to be equal to the temporary element.

###### Reverse Rotate B:

+Set a temporary element to the first element in array B;

+Shift all elements in array B up by 1.

+Set the last element of array B to be equal to the temporary element.

###### Reverse Rotate AB:

+call Reverse Rotate A();

+call Reverse Rotate B();


### PROCESS

#### Presorting

Command line parameters are taken in and parsed into an array of integers:

Input => [5, 11, 20, 1, 43, 88, 22, 33]

We find a sorted version of this array:

[5, 11, 20, 1, 43, 88, 22, 33] => [1, 5, 11, 20, 22, 33, 43, 88]

We replace the integer values in the original array with their index in the sorted array:

[5, 11, 20, 1, 43, 88, 22, 33] => [1, 2, 3, 0, 6, 7, 4, 5]

Now the goal is to try and shift each integer value closer to the index it represents.

Whatever sequence of pushswap operations shifts [1, 2, 3, 0, 6, 7, 4, 5] into [0, 1, 2, 3, 4, 5, 6, 7]

will also shift the original integers in the same manner, ordering them from lowest to highest.

#### Operation Strings

Sequences of pushswap operations are represented as operation strings, ASCII-encoded, printable,
null-terminated character arrays. Because we only have 11 total potential operations to execute,
we only need one byte or character for each operation. For readability, I've associated each
operation with digits 0-9 and the characters A and B.



'0' = Null. Do Nothing.;

'1' = Push A;

'2' = Push B;

'3' = Swap A;

'4' = Swap B;

'5' = Swap AB;

'6' = Rotate A;

'7' = Rotate B;

'8' = Reverse Rotate A;

'9' = Reverse Rotate B;

'A' = Rotate AB;

'B' = Reverse Rotate AB;



#### Selection Strings

char *selstr is used to refer to a selection string, which is intended to specify elements of an array
to be selected for some operation. A selstr is an ASCII encoded, null-terminated string of '0' and '1'
characters. The first character represents whether or not element 0 of an array is selected. The second
character represents whether or not element 1 of an array is selected, so on and so forth. '0' is used
to represent "false" or unselected elements in a human readable format, while '1' characters mark array
elements that ARE selected.

