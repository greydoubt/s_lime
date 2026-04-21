#include "2jzstrings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Wrap a raw JavaScript string into a JSString
JSString wrap_js_string(const char* raw_string, size_t length) {
    JSString js_str;
    js_str.value = raw_string;
    js_str.length = length;
    return js_str;
}

// Wrap a JSString into a JSTuple with type and index
JSTuple wrap_js_string_into_tuple(const char* raw_string, size_t length, int type, int index) {
    JSTuple tuple;
    tuple.js_string = wrap_js_string(raw_string, length);
    tuple.type = type;
    tuple.index = index;
    return tuple;
}

// Free a JSString (if any dynamic memory management is involved)
void free_js_string(JSString* js_str) {
    // In this case, we assume the string was not dynamically allocated by the C side
    // But if it were, you would free the memory here.
    js_str->value = NULL;
    js_str->length = 0;
}

// Free a JSTuple (free any dynamically allocated memory)
void free_js_tuple(JSTuple* js_tuple) {
    free_js_string(&js_tuple->js_string);
    js_tuple->type = 0;
    js_tuple->index = -1;
}

// Print a JSString for debugging
void print_js_string(const JSString* js_str) {
    printf("JSString: \"%s\", Length: %zu\n", js_str->value, js_str->length);
}

// Print a JSTuple for debugging
void print_js_tuple(const JSTuple* js_tuple) {
    printf("JSTuple: Type: %d, Index: %d, String: \"%s\", Length: %zu\n",
           js_tuple->type, js_tuple->index, js_tuple->js_string.value, js_tuple->js_string.length);
}
