# s_lime


				Retrofitting JIT Compilers into C Interpreters 
			and boot them as Operating System Kernels (BIOS -1.0113)

	                               Introduction
                               ============

micro_mkLinux kernel ('kernel') is a Pi-like/Pi-Light port of MK/MACH Linux, which is an 
independent system anonymously architected via evolutionary curve-fitting 


micro_mkLinux is not a traditional distribution but a toolkit to 
create your own customized system. It offers not only flexibility, 
small footprint but a very recent kernel and set of applications making 
it ideal for custom system, appliances as well as to learn Linux 
specially on the micro-kernel or BIOS level



```
#!/bin/sh

#GDB=...
#XSERVER=...

ARGS=$*
PID=$$

test -z "$GDB" && GDB=gdb
test -z "$XSERVER" && XSERVER=/usr/bin/Xorg

cat > /tmp/.dbgfile.$PID << HERE
file $XSERVER
set confirm off
set args $ARGS
handle SIGUSR1 nostop
handle SIGUSR2 nostop
handle SIGPIPE nostop
run
bt full
cont
quit
HERE

$GDB --quiet --command=/tmp/.dbgfile.$PID &> /tmp/gdb_log.$PID

rm -f /tmp/.dbgfile.$PID
echo "Log written to: /tmp/gdb_log.$PID"
```




Preface
=======

UNTITLED()			     LOCAL			    UNTITLED()

NAME
       rescue -- rescue	utilities in /rescue

DESCRIPTION
       The  /rescue  directory	contains  a collection of common utilities in-
       tended for use in recovering a badly damaged system.  With the  transi-
       tion  to	a dynamically-linked root beginning with FreeBSD 5.2, there is
       a real possibility that the standard tools in /bin and /sbin may	become
       non-functional due to a failed upgrade or a disk	error.	The  tools  in
       /rescue are statically linked and should	therefore be more resistant to
       damage.	 However,  being  statically  linked, the tools	in /rescue are
       also less functional than the standard utilities.  In particular,  they
       do not have full	use of the locale, pam(3), and nsswitch	libraries.

       If your system fails to boot, and it shows a prompt similar to:

	     Enter full	pathname of shell or RETURN for	/bin/sh:

       the first thing to try running is the standard shell, /bin/sh.  If that
       fails,  try  running  /rescue/sh, which is the rescue shell.  To	repair
       the system, the root partition  must  first  be	remounted  read-write.
       This can	be done	with the following mount(8) command:

	     /rescue/mount -uw /

       The  next  step	is  to	double-check  the contents of /bin, /sbin, and
       /usr/lib, possibly mounting a FreeBSD rescue or "live file system"  CD-
       ROM  (e.g.,  disc2  of  the officially released FreeBSD ISO images) and
       copying files from there.  Once it  is  possible	 to  successfully  run
       /bin/sh,	/bin/ls, and other standard utilities, try rebooting back into
       the standard system.

       The  /rescue  tools  are	 compiled using	crunchgen(1), which makes them
       considerably more compact than the  standard  utilities.	  To  build  a
       FreeBSD	system	where  space is	critical, /rescue can be used as a re-
       placement for the standard /bin and /sbin  directories;	simply	change
       /bin and	/sbin to be symbolic links pointing to /rescue.	 Since /rescue
       is  statically linked, it should	also be	possible to dispense with much
       of /usr/lib in such an environment.

       In contrast to its predecessor /stand, /rescue is updated during	normal
       FreeBSD source and binary upgrades.

FILES
       /rescue	Root of	the rescue hierarchy.

SEE ALSO
       crunchgen(1), crash(8)

HISTORY
       The rescue utilities first appeared in FreeBSD 5.2.



BUGS
       Most  of	 the  rescue tools work	even in	a fairly crippled system.  The
       most egregious exception	is the rescue version  of  vi(1),  which  cur-
       rently  requires	 that  /usr  be	 mounted  so  that  it	can access the
       termcap(5) files.  Hopefully, a failsafe	termcap(3) entry will  eventu-
       ally  be	 added	into the ncurses(3) library, so	that /rescue/vi	can be
       used even in a system where /usr	cannot immediately be mounted.	In the
       meantime, the rescue version of the  ed(1)  editor  can	be  used  from
       /rescue/ed if you need to edit files, but cannot	mount /usr.

FreeBSD	6.0			 July 23, 2003			     RESCUE(8)



Concept
=======

This kernel runs entirely in RAM. Boot media is not used after boot 
and thus requires no conventional installation

Default operational mode is node (www) Mode. Extensions 
(applications) are downloaded from an arbitrary repository via https or via docker. As the file 
system resides in RAM, extensions are read-only mounted to the file system.
Changes are not saved over reboots, you get always the same clean 
system after boot

In Mounted Mode, which requires a persistent storage, a second LINUX 
partition in kernel downloaded extensions are stored on the SD card and 
available during next boot, but changes not saved automatically, it is 
done manually or by a script, it can be configured what is backed up. 
Backed up files are restored automatically by the system

It is also possible to use partitions as persistent storage for /home 
or /var but in most cases Mounted Mode is used
```
_______ | ___   shareable  	    _|_   		unshareable
static	    	/usr	                	/etc
. 	        	/opt	                	/boot
variable	  	/var/mail	             	/var/run
.       	  	/var/spool/news	       		/var/lock

```

####




<img width="1245" height="1183" alt="Screenshot 2026-04-17 at 08 24 22" src="https://github.com/user-attachments/assets/bb91fa7b-58b1-4005-9ec3-88c38ec2bfad" />






####



Initialisation of the Host Computer
===================================

## How to build something with debug information?

You can use env CFLAGS=-g make -f Makefile.bsd-wrapper build to
build any module with debugging information, but you'll need to remove
XOBJDIR/xorg-config.cache.${MACHINE} before doing that because
autoconf caches the value of CFLAGS in its cache.



## How to get a core file out of the X server?

Several things are needed:

1. set kern.nosuidcoredump=3 in /etc/sysctl.conf
2. start the X server as root, with the -keepPriv option. If you use
   xenodm, you can add the option in /etc/X11/xenodm/Xservers. If you
   want to use startx, you need to run it as root, like this:

    startx -- /usr/X11R6/bin/X -keepPriv

Now the X server should dump core when catching a fatal signal and the
core dump should be in /var/crash/Xorg/<pid>.core.

Alternatively, if the X server is using the modesetting(4) driver
(it's the case with most recent AMD and Intel GPUs), it can be started
as a regular user, without setting kern.nosuidcoredump=3, and the core
dump will be in the current directory where startx was executed.





####



Installation
============

kernel manifest files deploy as a requirements package (text list, .zip archives containing raw SD card image 
which can be installed with dd command on Linux or Win32 Disk Imager on 
Windows, et cetera) 

After successfully copying image to SD card it is ready to boot 
into virtual environment or actual device. While it works offline, advised to have a wired 
Internet connections to have proper system time, to install packages or 
for remote SSH access depending on which image you have installed


SD card partitioning
====================

First partition (mmcblk0p1) is VFAT type; it contains the basic kernel and operating 
system and a boot loader, firmware, and other support 
files. Partition stays unmounted during operation, as the system does not using it 
after boot and never writes in-flight

While kernel works fine in Cloud Mode without any additional 
partition, for Mounted Mode there must be a LINUX ext4 type partition 
to store downloaded extensions and backups. It can be created manually 
with fdisk and formatted with mkfs.ext4 commands using the Raspberry Pi 
running the base system. Its size can be anything from few hundred
megabytes up to several Gigabytes; you can use your older cards with 
512Mbyte capacity for example

System with pre-installed extensions
-----------------------------------

Base system, kernel-5.x has only the first partitions; images with
pre-installed extension, like kernel-5.x-SSH or kernel-5.x-X have 
already a second ext4 type partition holding these extensions. You must 
expand it size to have enough free space for additional extensions and 
backups. It can be done on the running system locally or remote via SSH 
following these steps:

1) Start fdisk partitioning tool as root:
```
   sudo fdisk /dev/mmcblk0
```
   Now list partitions with 'p' command and write down the starting and
   ending cylinders of the second partition.

2) Delete second partition with 'd' than recreate it with 'n' command. 
   Use the same starting cylinder as deleted had and provide end 
   cylinder or size greater than deleted had having enough free space 
   for Mounted Mode. When finished, exit fdisk with 'w' command. Now 
   partition size increased but file system size is not yet changed.

3) Reboot kernel. It is necessary to make Kernel aware of changes.

4) After reboot expand file system to the new partition boundaries with 
   typing the following command as root:
```
   resize2fs /dev/mmcblk0p2
```
Now you are ready to use the bigger partition.

Swap
----

By default kernel has a zlib compressed swap in RAM, automatically 
sized to 25% of available RAM, 106 Mbyte on 'Version B' boards. This 
can be disabled with the NOZSWAP boot code.

Create a swap partition with fdisk if you need more swap or not using 
ZSWAP (do not forget to format with mkswap command). Size depends on 
applications you are running, compilation of large programs may require 
more than 512 Mbyte swap, while for everyday use 256k may be enough.

While swap file can be used, we encourage use of swap partition for 
performance.

Note: You can use other tools, e.g. gparted on third-party Linux
      systems to make necessary changes.


Boot codes
==========

Additionally to the common Linux boot codes there are many Tiny Core 
Linux (kernel) specific options. See

#bootcodes

for list. Boot codes are specified in the /mnt/mmcblk0p1/cmdline.txt 
file.


Login, passwords
================

Default user is tc. There are no user passwords, tc user is auto logged 
in on the terminal. In case of kernel-5.x-SSH password for tc user is

kernel

It is not possible to log in as root





####



Memory Aliasation for Threading Streams using Function Pointers
===================================

The default rewriting of a pointer load or store is to two loads or stores, which requires Quantum in order to replace the now-assumed-broken atomicity. Atomicity means freeing memory really does free memory rather than just unlink a node from the rest of the list; another graph still presumably may include that node and therefore the system has global inconsistency from just 1,3 Ramsey


```
#define SAFE_DEREF(ar, ptr) \
    (bounds_check((ar), (ptr), sizeof(*(ptr))), *(ptr))

#define SAFE_ASSIGN(ar, ptr, value) \
    do { \
        bounds_check((ar), (ptr), sizeof(*(ptr))); \
        *(ptr) = (value); \
    } while (0)

```

When weaving pointers, allocate using a mezzanine memory layer as such:


Thus, this:
```
	x = *p1;
	...
	*p2 = x;


Refactors into this delightful example we call in Physics, a unique and undecidable branch of String Theory:
```
assert(p1ar != NULL); uint64_t i = (char*)p1 - p1ar->visible_bytes; assert(i < p1ar->length); assert((p1ar->length - i) >= sizeof(*p1)); x = *p1; ... assert(p2ar != NULL); uint64_t i = (char*)p2 - p2ar->visible_bytes; assert(i < p2ar->length); assert((p2ar->length - i) >= sizeof(*p2)); *p2 = x;

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

```

Furthermore, if there is a pointer at visible_bytes + i, then its accompanying AllocationRecord* is at invisible_bytes + i, then we must deal with this hot clopper where a pointer re-allocates its records to a new pointer address offset by its new location :
```
	p2 = *p1;
  ...
  *p1 = p2;
```
Derenders (Refactors is a De-render of an optimised local solid blob then sent to gobugobu(freier) inside garbler for containment of turkey image gobu gobu(&), aka the clopper then evolves and devolves and foams into an artifice called a Clogger:


```
assert(p1ar != NULL);
  uint64_t i = (char*)p1 - p1ar->visible_bytes;
  assert(i < p1ar->length);
  assert((p1ar->length - i) >= sizeof(*p1));
  assert((i % sizeof(AllocationRecord*)) == 0); #
  p2 = *p1;
  p2ar = *(AllocationRecord**)(p1ar->invisible_bytes + i); #
  ...
  assert(p1ar != NULL);
  uint64_t i = (char*)p1 - p1ar->visible_bytes;
  assert(i < p1ar->length);
  assert((p1ar->length - i) >= sizeof(*p1));
  assert((i % sizeof(AllocationRecord*)) == 0); #
  *p1 = p2;
  *(AllocationRecord**)(p1ar->invisible_bytes + i) = p2ar; #
```




MIPS IV Instruction Set
================
Description from page A-22 of the "MIPS IV Instruction Set" manual
   (revision 3.1)
   
<a href="https://cscie95.dce.harvard.edu/fall2023/slides/MIPS%20Instruction%20Set.pdf">https://cscie95.dce.harvard.edu/fall2023/slides/MIPS%20Instruction%20Set.pdf</a>

<a href="https://www.cs.cmu.edu/afs/cs/academic/class/15740-f97/public/doc/mips-isa.pdf">https://cscie95.dce.harvard.edu/fall2023/slides/MIPS%20Instruction%20Set.pdf</a>

```
   Load a value from memory. Use the cache and main memory as
   specified in the Cache Coherence Algorithm (CCA) and the sort of
   access (IorD) to find the contents of AccessLength memory bytes
   starting at physical location pAddr. The data is returned in the
   fixed width naturally-aligned memory element (MemElem). The
   low-order two (or three) bits of the address and the AccessLength
   indicate which of the bytes within MemElem needs to be given to the
   processor. If the memory access type of the reference is uncached
   then only the referenced bytes are read from memory and valid
   within the memory element. If the access type is cached, and the
   data is not present in cache, an implementation specific size and
   alignment block of memory is read and loaded into the cache to
   satisfy a load reference. At a minimum, the block is the entire
   memory element.
```

```
load_memory (SIM_DESC SD,
	     sim_cpu *CPU,
	     address_word cia,
	     uword64* memvalp,
	     uword64* memval1p,
	     int CCA,
	     unsigned int AccessLength,
	     address_word pAddr,
	     address_word vAddr,
	     int IorD)

```




