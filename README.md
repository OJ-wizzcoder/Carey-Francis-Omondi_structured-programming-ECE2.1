<h2>Pointer Concepts and Programming Tasks</h2>
<h2>1. Difference Between a Normal Variable and a Pointer</h2>

<h3>Normal Variable</h3>

What it stores: The actual data value.

Memory access: Accessed directly using the variable name.

Reading value: By using the variable name.

Modifying value: Assigning a new value directly.

Example:

int x = 10;
x = 20;   // value is directly modified

<h3>Pointer Variable</h3>

What it stores: The memory address of another variable.

Memory access: Indirect, through the address it stores.

Reading value: Using dereferencing (*).

Modifying value: By dereferencing and assigning a new value.

Example:

int x = 10;
int *p = &x;   // p stores address of x
*p = 20;       // modifies value of x through the pointer

<h2>2. Variable vs Pointer Declaration and Definition</h2>

<h3>Variable Declaration & Definition</h3>
int num = 10;


Declares and defines an integer variable.

num stores the value 10.

<h3>Pointer Declaration & Definition</h3>
int *ptr;
ptr = &num;


*ptr declares ptr as a pointer to an integer.

&num gives the address of num.

ptr stores the address of num.

<h3>Operators</h3>

& → Address-of operator (gets memory address)

* → Dereference operator (accesses value at address)

<h2>3. Dereferencing a Pointer</h2>

Dereferencing means accessing or modifying the value stored at the memory address held by a pointer.

Example:

int a = 5;
int *p = &a;

printf("%d\n", *p);  // prints 5
*p = 15;             // modifies a
printf("%d\n", a);   // prints 15

<h2>4. When Pointers Are Preferred Over Normal Variables</h2>

<h3>Use Cases</h3>

Function parameter modification (call by reference)

Dynamic memory allocation

Efficient array and string handling

Practical Examples

Swapping values using a function

Passing large arrays to functions without copying

<h2>5. Limitations and Risks of Using Pointers</h2>

Can cause segmentation faults if misused

Uninitialized pointers may point to random memory

Memory leaks if dynamically allocated memory is not freed

Harder to debug compared to normal variables

<h2>6. Call by Value vs Call by Reference</h2>

<h3>Call by Value</h3>

A copy of the variable is passed

Original value remains unchanged

void increment(int x) {
    x++;
}

<h3>Call by Reference</h3>

Address of variable is passed

Original value can be modified

void increment(int *x) {
    (*x)++;
}

<h2>7. When to Use Each</h2>

<h3>Call by Value Preferred When:</h3>

Original data must not change

Small variables (int, char)

<h3>Call by Reference Preferred When:</h3>

Data needs to be modified

Large data structures (arrays, structs)

Performance is important

