# Dynamic Arrays #

[TOC]

## Intro ##

A dynamic array, growable array, resizable array, dynamic table, mutable array, or array list is a random access, variable-size list data structure that allows elements to be added or removed. It is supplied with standard libraries in many modern mainstream programming languages. Dynamic arrays overcome a limit of static arrays, which have a fixed capacity that needs to be specified at allocation.

A dynamic array is not the same thing as a dynamically allocated array or variable-length array, either of which is an array whose size is fixed when the array is allocated, although a dynamic array may use such a fixed-size array as a back end.

## How it works ##

A dynamic array works very similar to the conventional static array, except that the dynamic array is capable of resizing itself when it runs out of space.
The choice of how resizing works is the key factory to determine the efficiency of the dynamic array.

Usage example:

```
DynamicArray<int> arr([5, 10, 20, 30], 4);
arr.insert(55);
arr.insert(44);
```

In this example, client code knows nothing about how the array resizes itself.

However, if the array resizes itself by 1 after each single insertion, so that every time we add an elements to an array of size `n`, a new array of size `n+1` is created to accomodate the new element then `n` number of elements is copied to the new array and the new element is added to the new array.

Here's the class implementation:

```js
class DynamicArray:
    properties:
        // no. of elements it can hold
        integer: capacity;
        // no. of elements that are actually occupy the array
        integer: size;
        // array pointer
        pointer: arr;
    
    init():
        let capacity = 1;
        let size = 0;
        // allocate heap memory
        mem_address d1 = allocate (capacity*4) bytes;
        let <arr> point to <d1>;
    
    push_back(integer elem):
        // empty array
        if size == 0:
            arr[0] = elem;
        // non-empty and not full
        if size < capacity - 1:
            arr[capacity - 2] = elem;
        // array is full
        else:
            resize();
            arr[capacity - 1] = elem;
    
    resize():
        mem_address d2 = ((capacity + 1) *4) bytes;
        copy (d1) to (d2);
        delete (d1);
        let (arr) point to (d2);

    insert(integer pos, integer elem):
        ...
        ...
```

Notice that the efficiency is extremly bad, because we have to create a new array and copy n elements to the new array each single time we insert an element to the array.

The best way to resize is to create a new array that is twice as big when resizing the array to avoid resizing the array at each single step.

## Class Interface ##

psudo-code impelentation:

```js
class DynamicArray:
    properties:
        integer capacity;
        integer size;
        // pointer to some type `T`
        pointer(T) array;
        resize();
    
    constructors:
        // construct empty array
        DynamicArray();
        // construct with a single element
        DynamicArray(T value);
        // construct with an array pointer
        DynamicArray(pointer(T) values, integer no_of_values);

    destructors:
        ~DynamicArray();

    methods:
        push_back(T value) -> void;
        set(integer index, T value) -> void;
        add(integer index, T value) -> void;
        get(integer index) -> T;
        pop() -> T;
        delete(integer index) -> T;
        size() -> integer;
        capactiy() -> integer;
        is_empty() -> boolean;
        read() -> void;
```

>At a later stage, we will create a custom iterator for our >data structures.

### constructors ###

We will define a constant `MINUMUM_CAPACITY` that determines the initial size of the array upon creation.

```js
DynamicArray::DynamicArray():
    capacity := MINUMUM_CAPACITY;
    size := 0;
    array := allocate_memeory(capacity);
    if not check_allocation_successful(): 
        throw fatal_error;

DynamicArray::DynamicArray( T value ):
    capacity := MINUMUM_CAPACITY;
    array := allocate_memeory(capacity);
    if not check_allocation_successful(): 
        throw fatal_error;
    array[0] = value;
    size := 1;

DynamicArray::DynamicArray(
    pointer(T) values, 
    integer no_of_values
    ):
    capacity := no_of_values * k;
    array := allocate_memeory(capacity);
    if not check_allocation_successful(): 
        throw fatal_error;
    size := no_of_values;
    for (integer i = 0; i < size; i++):
        array[i] := values[i];
```

### destructors ###

```js
DynamicArray::~DynamicArray()
{
    free_memory(array);
}
```

### resize operation ###

resizing the array when it is full is the most crucial operation in this data structure!

we will define some constant `k` which determines the growth factor of the array, in our case, we will let the capacity double when our array is full, therefore k will be 2;

```js
DynamicArray::resize():
    // define new capacity
    integer new_capacity = capacity * k;
    // allocate memory for a new array
    pointer(T) new_array = allocate_memeory(new_capacity * k);
    if not check_allocation_successful(): 
        throw error;
    array := new_array
    capacity := new_capacity
```

### push operation ###

We check first if array is full, if it is, then we resize the array, then we proceed with the insertion.

```js
DynamicArray::push(T value):
    if size >= capacity:
        resize();
    array[size] = value;
    size++;
```

### set operation ###

Note that if user requested to insert a value at an index that is greater than the current size, we will fill the array with zeros until we reach the desired index, keep in mind the array will keep resizing itself.

```js
DynamicArray::set(integer index, T value):
    while index >= size:
        this.push(0);
    array[index] := value;
```

### add operation ###

```js
DynamicArray::add(integer index, T value):
    if index >= size;
        throw fatal_error;
    if size + 1 >= capacity:
        resize();
    for(integer i := index; i < size; i++):
        array[i+1] := array[i];
    array[index] = value;
    size ++ ;
```

### get operation ###

```js
DynamicArray::get(integer index):
    return array[index];
```

### pop operation ###

```js
DynamicArray::pop():
    define: T holder = array[size - 1];
    size--;
    return holder;
```

### delete operation ###

```js
DynamicArray::delete(integer index):
    define: T holder = array[index];
    for(integer i = index; i < size; i++):
        array[i] = array[i+1];
    return holder;
```

### Utility operations ###

```js
DynamicArray::size():
    return this->size;
```

```js
DynamicArray::capactiy():
    return this->capacity;
```

```js
DynamicArray::is_empty():
    return this->size == 0;
```

```js
DynamicArray::read():
    foreach value in array:
        print(value);
```
