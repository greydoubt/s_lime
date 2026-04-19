#include <stdint.h>
#include <assert.h>



#define SAFE_DEREF(ar, ptr) \
    (bounds_check((ar), (ptr), sizeof(*(ptr))), *(ptr))

#define SAFE_ASSIGN(ar, ptr, value) \
    do { \
        bounds_check((ar), (ptr), sizeof(*(ptr))); \
        *(ptr) = (value); \
    } while (0)



/* If you change these typecodes, you'll have to fix the arrayinfo table
   in gc.c and the {in,}direct_{load,store}_ops tables in
   compiler/tree2code.c */

#ifndef _TYPECODES_H_
#define _TYPECODES_H_

#define T_NORMAL_OBJECT	0
#define T_XXUNUSEDXX1   1	/* Used to be T_ARRAY */
#define T_CLASS		2
#define T_BOOLEAN	4
#define T_CHAR		5

#define T_FLOATING	4	/* add log2 size to get correct code:
					float has code 6,
					double has code 7 */
#define T_INTEGER	010
#define T_UINTEGER	014

#define	T_MAXNUMERIC	020

#define	T_XXUNUSEDXX2	020
#define	T_VOID		021
#define	T_FUNC		022
#define	T_UNKNOWN	023
#define	T_ERROR		024

/* for type construction */
#define T_TMASK	034
#define T_LMASK 003
#define T_LSIZE 2
#define T_MKTYPE( t, l )  ( ( (t)&T_TMASK ) | ( (l)&T_LMASK) )

/* for type deconstruction */
	/*
	 * Because we promise always to let ints and compile-only types be 
	 * distinguished by the "t" and "s" bits above, we can simplify
	 * some of our predicates by masking out the "c" bit when testing
	 * for integers. Thus the T_TS_MASK...
	 */
#define T_TS_MASK 034
#define T_ISINTEGER(t)  ( ((t)&030) == T_INTEGER  )
#define T_ISFLOATING(t) ( ((t)&036) == T_FLOAT )
#define T_ISNUMERIC(t)  ( (t) >= T_CHAR && (t) < T_MAXNUMERIC )
#define T_SIZEFIELD(t)	((t)&T_LMASK)
#define T_ELEMENT_SIZE(t) (1<<T_SIZEFIELD(t))	/* only for some!! */

#define T_IS_BIG_TYPE(t) ((t == T_DOUBLE) || (t == T_LONG))
#define T_TYPE_WORDS(t) (T_IS_BIG_TYPE(t) ? 2 : 1)

/* nick-names for the usual scalar types */
#define T_FLOAT  T_MKTYPE(T_FLOATING,2)
#define T_DOUBLE T_MKTYPE(T_FLOATING,3)
#define T_BYTE	 T_MKTYPE(T_INTEGER,0)
#define T_SHORT	 T_MKTYPE(T_INTEGER,1)
#define T_INT	 T_MKTYPE(T_INTEGER,2)
#define T_LONG	 T_MKTYPE(T_INTEGER,3)

#ifdef NO_LONGER_USED
/* We no longer support these types */
#define T_UBYTE	 T_MKTYPE(T_UINTEGER,0)
#define T_USHORT T_MKTYPE(T_UINTEGER,1)
#define T_UINT	 T_MKTYPE(T_UINTEGER,2)
#define T_ULONG	 T_MKTYPE(T_UINTEGER,3)

#endif

/* only a slight exaggeration */
#define N_TYPECODES	(1<<6)
#define	N_TYPEMASK	(N_TYPECODES-1)

#endif /* !_TYPECODES_H_ */




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
