#include <time.h>
#include "bool.h"


// Object-Orientation Header Format Layer J-4 Tags (aka JAVA) for unicode definition updates

#ifndef _OOBJ_H_
#define _OOBJ_H_

#ifndef JAVA_CLASSFILE_MAGIC

#include <stddef.h>

#include "typedefs.h"
#include "debug.h"
#include "bool.h"
#include "oobj_md.h"
#include "signature.h"

#define JAVA_CLASSFILE_MAGIC	          0xCafeBabe

#define JAVASRCEXT "java"
#define JAVASRCEXTLEN 4
#define JAVAOBJEXT "class"
#define JAVAOBJEXTLEN 5

#define JAVA_VERSION     45
#define JAVA_MINOR_VERSION 3
#define ARRAYHEADER     long alloclen

#define HandleTo(T) typedef struct H##T { Class##T *obj; struct methodtable *methods;} H##T


typedef long OBJECT;
typedef OBJECT Classjava_lang_Object;
typedef OBJECT ClassObject;
HandleTo(java_lang_Object);
typedef Hjava_lang_Object JHandle;
typedef Hjava_lang_Object HObject;

typedef unsigned short unicode;

extern unicode	*str2unicode(char *, unicode *, long);
extern char	*int642CString(int64_t number, char *buf, int buflen);

#define ALIGN(n) (((n)+3)&~3)
#define UCALIGN(n) ((unsigned char *)ALIGN((int)(n)))

struct fieldblock {
    struct ClassClass *clazz;
    char *signature;
    char *name;
    unsigned long ID;
    unsigned short access;
    union {
	unsigned long offset;	/* info of data */	
	OBJECT static_value;
	void *static_address;
    } u;
};

#define fieldname(fb)    ((fb)->name)
#define fieldsig(fb)     ((fb)->signature)
#define fieldIsArray(fb) (fieldsig(fb)[0] == SIGNATURE_ARRAY)
#define fieldIsClass(fb) (fieldsig(fb)[0] == SIGNATURE_CLASS)
#define	fieldclass(fb)   ((fb)->clazz)

struct execenv;

struct methodblock {
    struct fieldblock fb;
    unsigned char       *code;	/* the code */
    struct CatchFrame   *exception_table;
    struct lineno       *line_number_table;
    struct localvar     *localvar_table;

    unsigned long        code_length;
    unsigned long        exception_table_length;
    unsigned long        line_number_table_length;
    unsigned long        localvar_table_length;

    bool_t  (*invoker)
      (JHandle *o, struct methodblock *mb, int args_size, struct execenv *ee);
    unsigned short args_size;	/* total size of all arguments */
    unsigned short maxstack;	/* maximum stack usage */
    unsigned short nlocals;	/* maximum number of locals */
    void *CompiledCode;		/* it's type is machine dependent */
    long CompiledCodeFlags;	/* machine dependent bits */
};

struct ClassClass;
struct HIOstream;

struct methodtable {
    struct ClassClass *classdescriptor;
    struct methodblock *methods[1];
};

typedef struct {
    char body[1];
} ArrayOfByte;
typedef ArrayOfByte ClassArrayOfByte;
HandleTo(ArrayOfByte);

typedef struct {
    unicode body[1];
} ArrayOfChar;
typedef ArrayOfChar ClassArrayOfChar;
HandleTo(ArrayOfChar);

typedef struct {
    signed short body[1];
} ArrayOfShort;
typedef ArrayOfShort ClassArrayOfShort;
HandleTo(ArrayOfShort);

typedef struct {
    long        body[1];
} ArrayOfInt;
typedef ArrayOfInt ClassArrayOfInt;
HandleTo(ArrayOfInt);

typedef struct {
    int64_t        body[1];
} ArrayOfLong;
typedef ArrayOfLong ClassArrayOfLong;
HandleTo(ArrayOfLong);

typedef struct {
    float       body[1];
} ArrayOfFloat;
typedef ArrayOfFloat ClassArrayOfFloat;
HandleTo(ArrayOfFloat);

typedef struct {
    double       body[1];
} ArrayOfDouble;
typedef ArrayOfDouble ClassArrayOfDouble;
HandleTo(ArrayOfDouble);

typedef struct {
    JHandle *(body[1]);
} ArrayOfArray;
typedef ArrayOfArray ClassArrayOfArray;
HandleTo(ArrayOfArray);

typedef struct {
    HObject *(body[1]);
} ArrayOfObject;
typedef ArrayOfObject ClassArrayOfObject;
HandleTo(ArrayOfObject);

typedef struct Hjava_lang_String HString;

typedef struct {
    HString  *(body[1]);
} ArrayOfString;
typedef ArrayOfString ClassArrayOfString;
HandleTo(ArrayOfString);


/* Note: any handles in this structure must also have explicit
   code in the ScanClasses() routine of the garbage collector
   to mark the handle. */
typedef struct ClassClass {
    /* Things following here are saved in the .class file */
    unsigned short	     major_version;
    unsigned short	     minor_version;
    char                    *name;
    char                    *super_name;
    char                    *source_name;
    struct Hjava_lang_Class  *superclass;
    struct Hjava_lang_Class  *HandleToSelf;
    HObject		    *loader;
    struct methodblock	    *finalizer;

    union cp_item_type      *constantpool;
    struct methodblock      *methods;
    struct fieldblock       *fields;
    short                   *implements;

    struct methodtable      *methodtable;
    struct fieldblock      **slottable;

    HArrayOfChar	    *classname_array;

    unsigned long            thishash;
    unsigned long            totalhash;

    unsigned short           constantpool_count;  /* number of items in pool */
    unsigned short           methods_count;       /* number of methods */
    unsigned short           fields_count;        /* number of fields */
    unsigned short           implements_count;    /* number of protocols */

    unsigned short           methodtable_size;    /* the size of method table */
    unsigned short           slottbl_size;        /* size of slottable */
    unsigned short           instance_size;       /* (bytes) of an instance */

    unsigned short access;           /* how this class can be accesses */
    unsigned short flags;	     /* see the CCF_* macros */
} ClassClass;

typedef ClassClass Classjava_lang_Class;
HandleTo(java_lang_Class);
typedef Hjava_lang_Class HClass;

extern bool_t	createInternalClass(unsigned char *bytes, unsigned char *limit,
				    ClassClass *);
extern void	FreeClass(ClassClass *cb);

#define classname(cb)   ((cb)->name)
#define classsupername(cb) ((cb)->super_name)
#define classsrcname(cb) ((cb)->source_name)
#define cbSuperclass(cb)   ((cb)->superclass)
#define cbHandle(cb)       ((cb)->HandleToSelf)
#define	cbLoader(cb)	((cb)->loader)

#define cbConstantPool(cb) ((cb)->constantpool)
#define	cbMethods(cb)      ((cb)->methods)
#define	cbFields(cb)       ((cb)->fields)
#define cbImplements(cb)   ((cb)->implements)
#define cbMethodTable(cb)  ((cb)->methodtable)
#define cbSlotTable(cb)    ((cb)->slottable)

#define cbThisHash(cb)     ((cb)->thishash)
#define cbTotalHash(cb)    ((cb)->totalhash)
#define cbSlotTableSize(cb) ((cb)->slottbl_size)
#define cbInstanceSize(cb) ((cb)->instance_size)
#define cbMethodTableSize(cb) ((cb)->methodtable_size)
#define cbClassnameArray(cb)  ((cb)->classname_array)
#define cbAccess(cb)       ((cb)->access)
#define cbIsInterface(cb)  ((cbAccess(cb) & ACC_INTERFACE) != 0)

extern char *classname2string(char *str, char *dst, int size);

#define twoword_static_address(fb) ((fb)->u.static_address)
#define normal_static_address(fb)  (&(fb)->u.static_value)

/* ClassClass flags */
#define CCF_IsResolved	  0x02	/* been resolved yet? */
#define CCF_IsError	  0x04	/* Resolution caused an error */
#define CCF_IsSoftRef	  0x08	/* whether this is class Ref or subclass */
#define CCF_IsInitialized 0x10	/* whether this is class has been inited */
#define CCF_IsLoaded      0x20	/* Is this really the class object or a stub.*/
#define CCF_IsVerified    0x40	/* Is this really the class object or a stub.*/

#define CCIs(cb,flag) (((cb)->flags & CCF_Is##flag) != 0)
#define CCSet(cb,flag) ((cb)->flags |= CCF_Is##flag)
#define CCClear(cb,flag) ((cb)->flags &= ~CCF_Is##flag)

/* map from pc to line number */
struct lineno {
    unsigned long pc, 
    line_number;
};

extern struct lineno *lntbl;
extern long lntsize, lntused;

/* Symbol table entry for local variables and parameters.
   pc0/length defines the range that the variable is valid, slot
   is the position in the local variable array in ExecEnv.
   nameoff and sigoff are offsets into the string table for the
   variable name and type signature.  A variable is defined with
   DefineVariable, and at that time, the node for that name is
   stored in the localvar entry.  When code generate is completed
   for a particular scope, a second pass it made to replace the
   src node entry with the correct length. */

struct localvar {
    long pc0;			/* starting pc for this variable */
    long length;		/* -1 initially, end pc - pc when we're done */
    short nameoff;		/* offset into string table */
    short sigoff;		/* offset into string table */
    long slot;			/* local variable slot */
};

/* Try/catch is implemented as follows.  On a per class basis,
   there is a catch frame handler (below) for each catch frame
   that appears in the source.  It contains the pc range of the
   corresponding try body, a pc to jump to in the event that that
   handler is chosen, and a catchType which must match the object
   being thrown if that catch handler is to be taken.

   The list of catch frames are sorted by pc.  If one range is
   inside another, then outer most range (the one that encompasses
   the other) appears last in the list.  Therefore, it is possible
   to search forward, and the first one that matches is the
   innermost one.

   Methods with catch handlers will layout the code without the
   catch frames.  After all the code is generated, the catch
   clauses are generated and table entries are created.

   When the class is complete, the table entries are dumped along
   with the rest of the class. */

struct CatchFrame {
    long    start_pc, end_pc;	/* pc range of corresponding try block */
    long    handler_pc;	        /* pc of catch handler */
    void*   compiled_CatchFrame; /* space to be used by machine code */
    short   catchType;	        /* type of catch parameter */
};

#define MC_SUPER        (1<<5)
#define MC_NARGSMASK    (MC_SUPER-1)
#define MC_INT          (0<<6)
#define MC_FLOAT        (1<<6)
#define MC_VOID         (2<<6)
#define MC_OTHER        (3<<6)
#define MC_TYPEMASK     (3<<6)

enum {
    CONSTANT_Utf8 = 1,
    CONSTANT_Unicode,		/* unused */
    CONSTANT_Integer,
    CONSTANT_Float,
    CONSTANT_Long,      
    CONSTANT_Double,
    CONSTANT_Class,
    CONSTANT_String,
    CONSTANT_Fieldref,
    CONSTANT_Methodref,
    CONSTANT_InterfaceMethodref,
    CONSTANT_NameAndType
};

union cp_item_type {
    int i;
    void *p;
    float f;
    char *cp;
};
typedef union cp_item_type cp_item_type;

#define CONSTANT_POOL_ENTRY_RESOLVED 0x80
#define CONSTANT_POOL_ENTRY_TYPEMASK 0x7F
#define CONSTANT_POOL_TYPE_TABLE_GET(cp,i) (((unsigned char *)(cp))[i])
#define CONSTANT_POOL_TYPE_TABLE_PUT(cp,i,v) (CONSTANT_POOL_TYPE_TABLE_GET(cp,i) = (v))
#define CONSTANT_POOL_TYPE_TABLE_SET_RESOLVED(cp,i) \
	(CONSTANT_POOL_TYPE_TABLE_GET(cp,i) |= CONSTANT_POOL_ENTRY_RESOLVED)
#define CONSTANT_POOL_TYPE_TABLE_IS_RESOLVED(cp,i) \
	((CONSTANT_POOL_TYPE_TABLE_GET(cp,i) & CONSTANT_POOL_ENTRY_RESOLVED) != 0)
#define CONSTANT_POOL_TYPE_TABLE_GET_TYPE(cp,i) \
        CONSTANT_POOL_TYPE_TABLE_GET(cp,i) & CONSTANT_POOL_ENTRY_TYPEMASK

#define CONSTANT_POOL_TYPE_TABLE_INDEX 0
#define CONSTANT_POOL_UNUSED_INDEX 1

/* The following are used by the constant pool of "array" classes. */

#define CONSTANT_POOL_ARRAY_DEPTH_INDEX 1
#define CONSTANT_POOL_ARRAY_TYPE_INDEX 2
#define CONSTANT_POOL_ARRAY_CLASS_INDEX 3
#define CONSTANT_POOL_ARRAY_CLASSNAME_INDEX 4
#define CONSTANT_POOL_ARRAY_LENGTH 5

#endif

#endif /* !_OOBJ_H_ */




// Prototypes for "zip" file reader support
#ifndef _ZIP_H_
#define _ZIP_H_

// Central directory element

typedef struct {
    char *fn;		/* file name */
    int len;		/* file size */
    int mod;		/* file modification time */
    long off;		/* local file header offset */
} direl_t;

/*
 * Zip file
 */
typedef struct {
    char *fn;		/* zip file name */
    int fd;		/* zip file descriptor */
    direl_t *dir;	/* zip file directory */
    int nel;		/* number of directory entries */
    long cenoff;	/* Offset of central directory (CEN) */
    long endoff;	/* Offset of end-of-central-directory record */
} zip_t;

struct stat;

zip_t *zip_open(const char *fn);
void zip_close(zip_t *zip);
bool_t zip_stat(zip_t *zip, const char *fn, struct stat *sbuf);
bool_t zip_get(zip_t *zip, const char *fn, void *buf, int len);

#endif /* !_ZIP_H_ */ 

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

