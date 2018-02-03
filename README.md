# push_swap
Push_swap: 42 Project from Algorithms path, intended to find the shortest sequence of operations to sort a set of integers.

Operations Available:

Push A:
{
  Shift all Elements in array A down by 1;
  Copy B[0] to A[0];
  Shift all Elements in array B up by 1;
}
Push B:
{
  Shift all Elements in array B down by 1;
  Copy A[0] to B[0];
  Shift all Elements in array A up by 1;
}
Swap A():
{
  Temp = A[0];
  A[0] = A[1];
  A[1] = Temp;
}
Swap B():
{
  Temp = B[0];
  B[0] = B[1];
  B[1] = Temp;
}
Swap AB():
{
  Swap A();
  Swap B();
}
Rotate A(A):
{
  if (A)
  {
    num_elements = A.length;
    Temp = A[num_elements - 1];
    A.shift(DOWN, 1);
  }
}

Rotate B(element *B):
{
  int     num_elements;
  element temp;
  
  if (B)
  {
    num_elements = ft_array_length(B, sizeof(element));
    temp = B[num_elements - 1];
    ft_ShiftElements(A, DOWN);//operations only require shifting by 1. Only need the list and direction(set via macro).
    B[0] = temp;
  }
}

Rotate AB(element *A, element *B):
{
  //Rotate A();
  //Rotate B();
  Rotate(A);
  Rotate(B);
}

Reverse Rotate(element *array)
{
  int     num_elements;
  element temp;
  
  if (array && array.length > 0)
  {
    temp = array[0];
    ft_ShiftElements(array, UP);
    array[num_Elements - 1] = temp;
  }
}


Reverse Rotate(element *array)
{

}

First Actions
