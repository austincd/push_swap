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
