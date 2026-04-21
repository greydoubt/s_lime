#ifndef JS_STRING_H
#define JS_STRING_H

#include <stddef.h>  // For size_t

// Define a structure to represent a JavaScript string
typedef struct {
    const char* value;  // Pointer to the raw string value
    size_t length;      // Length of the string (in characters)
} JSString;

// Define a structure for a tuple that holds a string and its metadata (for example, type or index)
typedef struct {
    JSString js_string;  // The wrapped JavaScript string
    int type;            // Type identifier for the string (e.g., if it represents a string, number, etc.)
    int index;           // Index of the string, if part of an array or list
} JSTuple;

// Function stubs for wrapping JavaScript strings into C values (tuples)

// Wrap a raw JavaScript string into a JSString
JSString wrap_js_string(const char* raw_string, size_t length);

// Wrap a JSString into a JSTuple with an additional type and index
JSTuple wrap_js_string_into_tuple(const char* raw_string, size_t length, int type, int index);

// Utility function to free a JSString (if dynamically allocated memory is used)
void free_js_string(JSString* js_str);

// Utility function to free a JSTuple (free any dynamically allocated memory)
void free_js_tuple(JSTuple* js_tuple);

// Function to print the contents of a JSString for debugging or testing
void print_js_string(const JSString* js_str);

// Function to print the contents of a JSTuple for debugging or testing
void print_js_tuple(const JSTuple* js_tuple);

#endif // JS_STRING_H
