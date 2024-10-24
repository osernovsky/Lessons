
# Lesson on String Functions in C

## Introduction
In C programming, strings are arrays of characters that are terminated by a null character (`\0`). This lesson covers some common string manipulation functions provided by the `string.h` library.

## String Comparison

### `strcmp()`
The `strcmp()` function compares two strings lexicographically (character by character). It returns:
- `0` if both strings are equal,
- A negative value if the first string is less than the second,
- A positive value if the first string is greater than the second.

```c
#include <stdio.h>
#include <string.h>

int main() {
    const char *str1 = "apple";
    const char *str2 = "banana";
    int result = strcmp(str1, str2);

    if (result == 0) {
        printf("Strings are equal\n");
    } else if (result < 0) {
        printf("str1 is less than str2\n");
    } else {
        printf("str1 is greater than str2\n");
    }

    return 0;
}
```

### `strncmp()`
The `strncmp()` function compares only the first `n` characters of two strings. This is useful if you want to compare only part of a string.

```c
#include <stdio.h>
#include <string.h>

int main() {
    const char *str1 = "apple";
    const char *str2 = "application";
    int result = strncmp(str1, str2, 5);

    if (result == 0) {
        printf("First 5 characters are equal\n");
    } else {
        printf("First 5 characters are not equal\n");
    }

    return 0;
}
```

## String Concatenation

### `strcat()`
The `strcat()` function concatenates (appends) the second string to the first string. The first string must be large enough to hold the result.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    const char *str2 = " World";
    strcat(str1, str2);

    printf("%s\n", str1);  // Output: Hello World

    return 0;
}
```

### `strncat()`
The `strncat()` function appends only the first `n` characters of the second string to the first string.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    const char *str2 = " World";
    strncat(str1, str2, 3);

    printf("%s\n", str1);  // Output: Hello Wor

    return 0;
}
```

## String Length

### `strlen()`
The `strlen()` function returns the length of the string (excluding the null character).

```c
#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, World!";
    printf("Length: %lu\n", strlen(str));

    return 0;
}
```

## String Search

### `strstr()`
The `strstr()` function searches for the first occurrence of a substring in a string. It returns a pointer to the start of the substring, or `NULL` if the substring is not found.

```c
#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, World!";
    const char *substr = "World";
    char *result = strstr(str, substr);

    if (result) {
        printf("Substring found: %s\n", result);
    } else {
        printf("Substring not found\n");
    }

    return 0;
}
```

## String Copy

### `strcpy()`
The `strcpy()` function copies the source string into the destination string. The destination must be large enough to hold the source string.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char dest[20];
    const char *src = "Hello, World!";
    strcpy(dest, src);

    printf("%s\n", dest);

    return 0;
}
```

### `strncpy()`
The `strncpy()` function copies only the first `n` characters of the source string to the destination.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char dest[20];
    const char *src = "Hello, World!";
    strncpy(dest, src, 5);

    printf("%s\n", dest);  // Output: Hello

    return 0;
}
```

## Additional Function: `strcspn()`

### `strcspn()`
The `strcspn()` function scans a string for the first occurrence of any character from a set of characters. It returns the number of characters in the initial segment of the string that do not match any character in the set.

```c
#include <stdio.h>
#include <string.h>

int main() {
    const char str[] = "Hello, world!";
    const char set[] = ",!";
    size_t pos = strcspn(str, set);
    
    printf("Первый символ из набора ',!' находится на позиции %zu\n", pos);
    
    return 0;
}
```

This example demonstrates how to find the first occurrence of any character from the set `",!"` in the string `"Hello, world!"`. The function returns the position where any of the characters in the set first appears.

## Conclusion
These are some of the most commonly used string manipulation functions in C. Understanding how to work with strings and manipulate them is essential for any C programmer, as strings are a fundamental part of most programs.
