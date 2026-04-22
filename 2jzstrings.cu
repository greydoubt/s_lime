#include "2jzstrings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10         
#define NAME_LEN 12         
#define CONTENT_LEN 32      
#define PATH_LEN 16         
#define DMESG_LINES 6
#define DMESG_LEN 40

typedef struct {
  char name[NAME_LEN];
  char content[CONTENT_LEN];
  char parentDir[PATH_LEN];
  int isDirectory;
  int active;
} JSON;

typedef struct {
  unsigned long timestamp;
  char message[DMESG_LEN];
} JSString;

JSON fs[MAX_FILES];
char currentPath[PATH_LEN] = "/";
char inputBuffer[32] = "";
int inputLen = 0;
JSString dmesg[DMESG_LINES];
int dmesgIndex = 0;

int freeMemory() {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

void(* resetFunc) (void) = 0;

void addDmesg(const char* msg) {
  if (dmesgIndex >= DMESG_LINES) dmesgIndex = 0;
  dmesg[dmesgIndex].timestamp = millis() / 1000;
  strncpy(dmesg[dmesgIndex].message, msg, DMESG_LEN - 1);
  dmesg[dmesgIndex].message[DMESG_LEN - 1] = '\0';
  dmesgIndex++;
}


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
