#define SAFE_DEREF(ar, ptr) \
    (bounds_check((ar), (ptr), sizeof(*(ptr))), *(ptr))

#define SAFE_ASSIGN(ar, ptr, value) \
    do { \
        bounds_check((ar), (ptr), sizeof(*(ptr))); \
        *(ptr) = (value); \
    } while (0)


#include <stdint.h>
#include <assert.h>



typedef struct {
    char *visible_bytes;
    uint64_t length;
} array_ref;


typedef struct {
    void *ptr;
    array_ref *ar;
} safe_ptr;



static inline void bounds_check(array_ref *ar, void *ptr, size_t size) {
    assert(ar != NULL);

    uint64_t i = (char*)ptr - ar->visible_bytes;
    assert(i < ar->length);
    assert((ar->length - i) >= size);
}
	


int x = *p1;
 // ...
  *p2 = x;

bounds_check(p1ar, p1, sizeof(*p1));
x = *p1;

...

bounds_check(p2ar, p2, sizeof(*p2));
*p2 = x;




  assert(p1ar != NULL);
  uint64_t i = (char*)p1 - p1ar->visible_bytes;
  assert(i < p1ar->length);
  assert((p1ar->length - i) >= sizeof(*p1));
  x = *p1;
  ...
  assert(p2ar != NULL);
  uint64_t i = (char*)p2 - p2ar->visible_bytes;
  assert(i < p2ar->length);
  assert((p2ar->length - i) >= sizeof(*p2));
  *p2 = x;






x = SAFE_DEREF(p1ar, p1);
SAFE_ASSIGN(p2ar, p2, x);
