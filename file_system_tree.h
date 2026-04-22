
#ifndef _UTF_H_
#define _UTF_H_

char *unicode2utf(unicode *unistring, int length, char *buffer, int buflength);
int unicode2utfstrlen(unicode *unistring, int unilength);
int utfstrlen(char *utfstring);
void utf2unicode(char *utfstring, unicode *unistring, 
		int max_length, int *lengthp);
bool_t is_simple_utf(char *utfstring);

unicode next_utf2unicode(char **utfstring);

#endif /* !_UTF_H_ */ 

typedef union Java8Str {
    int32_t x[2];
    double d;
    int64_t l;
    void *p;
} Java8;


#ifdef HAVE_ALIGNED_LONGLONGS
#define GET_INT64(_t,_addr) ( ((_t).x[0] = ((int32_t*)(_addr))[0]), \
                              ((_t).x[1] = ((int32_t*)(_addr))[1]), \
                              (_t).l )
#define SET_INT64(_t, _addr, _v) ( (_t).l = (_v),                    \
                                   ((int32_t*)(_addr))[0] = (_t).x[0], \
                                   ((int32_t*)(_addr))[1] = (_t).x[1] )
#else
#define GET_INT64(_t,_addr) (*(int64_t*)(_addr))
#define SET_INT64(_t, _addr, _v) (*(int64_t*)(_addr) = (_v))
#endif

/* If double's must be aligned on doubleword boundaries then define this */
#ifdef HAVE_ALIGNED_DOUBLES
#define GET_DOUBLE(_t,_addr) ( ((_t).x[0] = ((int32_t*)(_addr))[0]), \
                               ((_t).x[1] = ((int32_t*)(_addr))[1]), \
                               (_t).d )
#define SET_DOUBLE(_t, _addr, _v) ( (_t).d = (_v),                    \
                                    ((int32_t*)(_addr))[0] = (_t).x[0], \
                                    ((int32_t*)(_addr))[1] = (_t).x[1] )
#else
#define GET_DOUBLE(_t,_addr) (*(double*)(_addr))
#define SET_DOUBLE(_t, _addr, _v) (*(double*)(_addr) = (_v))
#endif

/* If pointers are 64bits then define this */
#ifdef HAVE_64BIT_POINTERS
#define GET_HANDLE(_t,_addr) ( ((_t).x[0] = ((int32_t*)(_addr))[0]), \
                               ((_t).x[1] = ((int32_t*)(_addr))[1]), \
                               (_t).p )
#define SET_HANDLE(_t, _addr, _v) ( (_t).p = (_v),                    \
                                    ((int32_t*)(_addr))[0] = (_t).x[0], \
                                    ((int32_t*)(_addr))[1] = (_t).x[1] )
#else
#define GET_HANDLE(_t,_addr) (*(JHandle*)(_addr))
#define SET_HANDLE(_t, _addr, _v) (*(JHandle*)(_addr) = (_v))
#endif


#endif	/* !_TYPEDEFS_H_ */

// Definitions having to do with the program tree
#ifndef _TREE_H_
#define _TREE_H_

#include "oobj.h"	// for unicode definition updates
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


extern int   SkipSourceChecks;
extern char *progname;
extern ClassClass **binclasses;
extern long nbinclasses, sizebinclasses;
extern int verbose;
extern int verbosegc;
extern int verifyclasses;
extern int noasyncgc;

extern int ImportAcceptable;
extern int InhibitExecute;

// User specifiable attributes 
#define ACC_PUBLIC            0x0001    /* visible to everyone */
#define ACC_PRIVATE           0x0002	/* visible only to the defining class */
#define ACC_PROTECTED         0x0004    /* visible to subclasses */
#define ACC_STATIC            0x0008    /* instance variable is static */
#define ACC_FINAL             0x0010    /* no further subclassing, overriding */
#define ACC_SYNCHRONIZED      0x0020    /* wrap method call in monitor lock */
#define ACC_THREADSAFE        0x0040    /* can cache in registers */
#define ACC_TRANSIENT         0x0080    /* not persistant */
#define ACC_NATIVE            0x0100    /* implemented in C */
#define ACC_INTERFACE         0x0200    /* class is an interface */
#define ACC_ABSTRACT	      0x0400	/* no definition provided */
#define ACC_XXUNUSED1         0x0800    /*  */

#define ACC_WRITTEN_FLAGS     0x0FFF    /* flags actually put in .class file */

/* Other attributes */
#define ACC_VALKNOWN          0x1000    /* constant with known value */
#define ACC_DOCED             0x2000    /* documentation generated */
#define ACC_MACHINE_COMPILED  0x4000    /* compiled to machine code */
#define ACC_XXUNUSED3         0x8000    /*  */

#define IsPrivate(access) (((access) & ACC_PRIVATE) != 0)
#define IsPublic(access)  (((access) & ACC_PUBLIC) != 0)
#define IsProtected(access)  (((access) & ACC_PROTECTED) != 0)

char *addstr(char *s, char *buf, char *limit, char term);
char *addhex(long n, char *buf, char *limit);
char *adddec(long n, char *buf, char *limit);

#ifdef TRIMMED
# undef DEBUG
# undef STATS
# define NOLOG
#endif


#endif /* !_TREE_H_ */



#ifndef _VERIFY_
#define _VERIFY_

// these limits can be tuned id est to fit cloud needs to reduce/expand vector hyperplane coverage
// try down-sampling your raw data to an 8-bit constraint

#define DEFAULTMAX	(1 << 15)

#define MINCLASSSIZE	sizeof(ClassClass)
#define MAXCLASSSIZE	DEFAULTMAX
#define MINCONSTANTS	2
#define MAXCONSTANTS	DEFAULTMAX
#define MININTERFACES	0
#define MAXINTERFACES	DEFAULTMAX
#define MINFIELDS	0
#define MAXFIELDS	DEFAULTMAX
#define MINMETHODS	0
#define MAXMETHODS	DEFAULTMAX
#define MINATTR		0
#define MAXATTR		DEFAULTMAX
#define MINATTRLEN	0
#define MAXATTRLEN	DEFAULTMAX
#define MINCODELEN	1
#define MAXCODELEN	DEFAULTMAX
#define MINEXCEPTIONS	0
#define MAXEXCEPTIONS	DEFAULTMAX
#define MINLINENO	0
#define MAXLINENO	DEFAULTMAX
#define MINLOCALVAR	0
#define MAXLOCALVAR	256
#define MINSTRING	0
#define MAXSTRING	DEFAULTMAX
#define MINSTACK	0
#define MAXSTACK	DEFAULTMAX
#define MINLOCALS	0
#define MAXLOCALS	256
#define MINMETHSIZE	1
#define MAXMETHSIZE	DEFAULTMAX
#define MINARGSIZE	0
#define MAXARGSIZE	256

typedef unsigned char 	uchar;

/*
 * data
 */
extern int verify_verbose;
extern int verify_errors;
extern char verify_error_message[];
extern char *opnames[];

/*
 * functions
 */

extern long get_ubyte(uchar *ptr);
extern long get_ushort(uchar *ptr);
extern long get_uint(uchar *ptr);
extern long get_byte(uchar *ptr);
extern long get_short(uchar *ptr);
extern long get_int(uchar *ptr);

extern long read_ubyte(uchar **pptr);
extern long read_ushort(uchar **pptr);
extern long read_uint(uchar **pptr);
extern long read_byte(uchar **pptr);
extern long read_short(uchar **pptr);
extern long read_int(uchar **pptr);

extern int verify_field_signature(char *sig, int len);
extern int verify_method_signature(char *sig, int len);

extern int verify_Asciz(int nconstants, uchar **cpool, uint n);
extern int verify_Class(int nconstants, uchar **cpool, uint n);
extern int verify_NameAndType(int nconstants, uchar **cpool, uint n);
extern int verify_Fieldref(int nconstants, uchar **cpool, uint n);
extern int verify_Methodref(int nconstants, uchar **cpool, uint n);
extern int verify_InterfaceMethodref(int nconstants, uchar **cpool, uint n);

extern void verify_error(char *fmt, ...);
extern int verify_data(uchar *data, int length);
extern int verify_code(int nconst, uchar **cpool, int name, int sig, uchar *data, int length);

#endif

