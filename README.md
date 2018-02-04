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

"001011" + ["one", "two", "three", "four", "five", "six"] = ["three", "five", "six"];

#### How to Order a list of elements?

Order a list of elements by making sublists that are ordered:

+List A begins as an unordered list;
+Sift elements out from the unordered list A into one or more sorted lists in list B using rotation and push operation strings;
+Continue until the remaining elements in list A form a rotationally sorted list;
+Merge the sorted list A and the sorted segments of list B into a rotationally sorted list A containing all elements, once again using rotation and push operation strings;
+Rotate until list is sorted, with 0 at index 0, 1 at index 1, so on and so forth, until all elements are in list A and in ascending order.

#### Technique : Sifting

What can we do in a certain number of operations?

We want to remove a selection of elements from array A and put them into array B in one or more rotationally sorted subarrays.

We can only move elements between list A and list B when they are the first element in the source list. We try to find the fewest number
of operations necessary to bring the element we want to sift out to the surface, along with the part of the target list we want to insert
said element into.

find the number of rotations and reverse rotations to bring some element in list A to index 0 of list A, and some element in list B to index 0 of list B.
if we rotate in one direction for list A and another for list B, we can't take advantage of the AB operations to save steps, so the total number of operations
is the sum of the rotation operations needed for list A and list B.

if we rotate in the same direction for list A and list B, we can use the AB option until the list with fewer rotations is in place, and then follow
with single list rotations. In this instance, the total number of operations is the greater of the required number of operations for each list.

This way, we can be sure that whenever we want to move lists A and B to a particular position, we'll surely choose the shortest operation string to rotate
them to that position.

#### void ft_apply_moves(element *A, element *B, char *opstr)

The ft_apply_moves function takes an array A and an array B, along with an operation string, and then
executes the operation specified by each character in the operation string, in sequence.

####