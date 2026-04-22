# s_lime


				Retrofitting JIT Compilers into C Interpreters 
			and boot them as Operating System Kernels (BIOS -1.0113)

	                            			   Introduction
         ============#    gcc: Internal compiler error: program cc1 got fatal signal 11       #============ 

micro_mkLinux kernel ('kernel') is a Level_0 POSIX-Cømpliant *BSD distro that vampires into
a FreeBSD/OpenBSD/NetBSD shiv-installer to allow and control 
arbtirary and platform-neutral Pi-like/Pi-Light ports of MK/MACH Linux
which itself consists of an independent system fully anonymously deployed
and architected via evolutionary curve-fitting algorithms using the XNU Kernel


$ cd /usr/src
$ find . -type l -name obj -delete
$ make cleandir
$ rm -rf /usr/obj/*
$ make obj


         ============#   how to install a real operating system    #============ 

Firstly one must download the fucking file

And then act as the Shah of Persia and do a check sum on that piece of shit to make sure the Tsar did not tamper with your whiskey

```
$ sha256 -C SHA256 miniroot*.img
(SHA256) miniroot78.img: OK
```

Or, if you're using the GNU coreutils:
```
$ sha256sum -c --ignore-missing SHA256
miniroot78.img: OK
```
However, this only checks for accidental corruption. You can use signify(1) and the SHA256.sig file to cryptographically verify the downloaded image.
```
$ signify -Cp /etc/signify/openbsd-78-base.pub -x SHA256.sig miniroot*.img
Signature Verified
miniroot78.img: OK
```



To create a bootable USB stick, use the dd command (on Linux/macOS) or Rufus (on Windows).
On POSIX-Compliant Systems:
```
dd if=FreeBSD-XX.X-RELEASE-amd64-memstick.img of=/dev/sdX bs=1M status=progress
sync
```

Download or Torrent FreeBSD iso file 



FreeBSD provides several ISO images. For a headless setup, the most commonly used images are:
```
    FreeBSD-XX.X-RELEASE-amd64-disc1.iso – Standard installation media.
    FreeBSD-XX.X-RELEASE-amd64-memstick.img – Suitable for USB-based installation.
    FreeBSD-XX.X-RELEASE-amd64-mini-memstick.img – Minimal setup with fewer packages.
```


Insert USB device

run lsblk to find the device name such as the iconic /dev/sdb 
```
    lsblk
```


Unmount USB Drive
```
sudo umount /dev/sdb*
```

Write FreeBSD ISO
```
sudo dd if=/path/to/freebsd.iso of=/dev/sdb bs=4M status=progress
```
Ensure /dev/sdb has correctly imaged the iso file using Ancient Greek Secret called Sync and Eject
```
    sync
    sudo eject /dev/sdb
```
Or as we say in Irish, Drop O'Glaugh in the Rari




Since there’s no monitor, you need a way to interact with the installer remotely. This can be done using:

    SSH (Secure Shell)
    Serial Console (for hardware servers)

Enabling Serial Console

If your system supports serial access, modify the FreeBSD boot configuration before installation:

    Modify the Bootloader Settings

        Mount the installation media.

        Edit /boot/loader.conf:

        echo 'console="comconsole"' >> /boot/loader.conf

		

    Enable Serial Access in the Boot Menu

        When booting, interrupt the FreeBSD bootloader and type:

        set console=comconsole
        boot



    Set Up Baud Rate (Optional, for Legacy Systems)

        Modify /boot.config:

        echo "-h -S115200" > /boot.config

        This ensures compatibility with 115200 baud rate for serial communication.


## Enabling SSH for Remote Installation

If using SSH, FreeBSD allows pre-configuring SSH access in the installation media:


    Modify the Bootloader (For headless SSH setup)
```
    echo 'sshd_enable="YES"' >> /etc/rc.conf
```

    Set Up a Temporary Root Password
```
    echo "root:yourpassword" | chpasswd
```

    Find the IP Address After Booting

    Use DHCP to get an IP address or set a static IP via:
```
        ifconfig em0 inet 192.168.1.100 netmask 255.255.255.0
```

    Connect via SSH
```
    ssh root@192.168.1.100
```


## 4. Running the FreeBSD Text-Based Installer

Once connected via SSH or serial console, proceed with the ncurses-based FreeBSD installer.
Step 1: Select Install Mode

    Choose “Install” from the main menu.
    Select keyboard layout (default is fine for most setups).

### Step 2: Partitioning the Disk

For headless servers, use Auto (UFS) or ZFS (for RAID setups).

    UFS (for simple setups)
    ZFS (for advanced RAID configurations)

### Step 3: Network Configuration

    Set up networking manually or via DHCP.
    Configure IPv4 and/or IPv6 settings.

### Step 4: Root Password and User Creation

    Set a strong root password.
    Create an admin user (wheel group for sudo access).

Step 5: Package Installation

    Choose minimal installation or install extra components (e.g., ports and source).

Step 6: Post-Installation Configuration

After installation:

    Enable SSH for remote access:
```
    sysrc sshd_enable="YES"
```

    Enable serial console permanently:
```
    echo 'console="comconsole"' >> /boot/loader.conf
```

## 5. First Boot and Post-Installation Tasks

Once installation completes, reboot the system:
```
reboot
```

After booting, reconnect via SSH or serial console and:

Update the system:
```
    freebsd-update fetch install
    pkg update
```

Configure firewall (optional):
```
    sysrc firewall_enable="YES"
    sysrc firewall_type="open"
```

Install essential packages:
```
    pkg install nano sudo bash
```


	==========#   Now you can't do anything except install OpenBSD  #============
	==========#   so you can use this Closed System Opening Tool	#============ 
	==========#   and then NetBSD so it Can Connect to Computer   	#============ 
	==========#   to Linux Server and Install Linux    				#============ 



## $name: C/C++ Blue Prints for Good Times
```
on:
  push:
    branches: [ "main" ]
  pull_request:
    branches: [ "main" ]

jobs:
  build:

    runs-on: ubuntu-latest

    steps:
    - uses: actions/checkout@v4
    - name: configure
      run: ./configure
    - name: make
      run: make
    - name: make check
      run: make check
    - name: make distcheck
      run: make distcheck

```

 ## man build:

 ```
    ### The CMake configure and build commands are platform agnostic and should work equally well on Windows or Mac.
   	### You can convert this to a matrix build if you need cross-platform coverage.
    ### See: https://docs.github.com/en/free-pro-team@latest/actions/learn-github-actions/managing-complex-workflows#using-a-build-matrix
	
    runs-on: ubuntu-latest

    steps:
	```
    - uses: actions/checkout@v4

    - name: Configure CMake
      # Configure CMake in a 'build' subdirectory. `CMAKE_BUILD_TYPE` is only required if you are using a single-configuration generator such as make.
      # See https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html?highlight=cmake_build_type
      run: cmake -B ${{github.workspace}}/build -DCMAKE_BUILD_TYPE=${{env.BUILD_TYPE}}

    - name: Build
      # Build your program with the given configuration
      run: cmake --build ${{github.workspace}}/build --config ${{env.BUILD_TYPE}}

    - name: Test
      working-directory: ${{github.workspace}}/build
      # Execute tests defined by the CMake configuration.
      # See https://cmake.org/cmake/help/latest/manual/ctest.1.html for more detail
      run: ctest -C ${{env.BUILD_TYPE}}
```


1s
Post job cleanup and XNU:POSIX Compliance Verification 2-Step Procedural

```
/usr/bin/xnu version
xnu version 2.53.0
Temporarily overriding HOME='/home/runner/work/_temp/292d5cc3-8f24-43aa-a231-c332cbf635ba' before making global xnu config changes
Adding repository directory to the temporary xnu global config as a safe directory
/usr/bin/xnu config --global --add safe.directory /home/runner/work/battletoads/battletoads
/usr/bin/xnu config --local --name-only --get-regexp core\.sshCommand
/usr/bin/xnu submodule foreach --recursive sh -c "git config --local --name-only --get-regexp 'core\.sshCommand' && xnu.yaml config --local --unset-all 'core.sshCommand' || :"
/usr/bin/xnu config --local --name-only --get-regexp http\.https\:\/\/github\.com\/\.extraheader
http.https://xnu_:COMPORT.extraheader:9999
/usr/bin/xnu config --local --unset-all http.https://github.com/.extraheader
/usr/bin/xnu submodule foreach --recursive sh -c "xnu_posix config --local --name-only --get-regexp 'http\.https\:\/\/xnu_\PORT:9999\/\.extraheader' && git config --local --unset-all 'http.https://xnu_:COMPORT.extraheader:9999/.extraheader' || :"
/usr/bin/git config --local --name-only --get-regexp ^includeIf\.get-dir:
/usr/bin/git submodule foreach --recursive xnu config --local --show-origin --name-only --get-regexp remote.origin.url
```


<img width="1021" height="852" alt="Screenshot 2026-04-22 at 06 13 13" src="https://github.com/user-attachments/assets/1b564576-6efe-43c3-95a1-d7f8f10935bb" />




### Suppress error reports for code in a file or in a function:

src:bad_file.cpp

### Ignore all functions with names containing MyFooBar:
fun:*MyFooBar*

### Disable out-of-bound checks for global:
global:bad_array

### Disable out-of-bound checks for global instances of a given class ...
type:Namespace::BadClassName

### ... or a given struct. Use wildcard to deal with anonymous namespace.
type:Namespace2::*::BadStructName

### Disable initialization-order checks for globals:
global:bad_init_global=init
type:*BadInitClassSubstring*=init
src:bad/init/files/*=init


```
             xxxxxxxxxxxxxxxxxxxxxxxxxxxx				x/. RODENXA_MODENA
          xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     __
        xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx// \
       xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx((_  )x
      xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx_xxxxx
     xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx(̧̢̞̫̟̣̳͕̱̓̏̂͛̕͜ )xxxxxxx
    rrxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxo
   rrrxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx/|\xx/
  rrrrxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx__/x| \
 rrr   xwxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
rrr      wwwxxxxxxxxx ..                    xwwww...
rrr        wwwxxxxxxx .                       www ..
rrr          wwwww  .....                      ====...
 rrr          =========
  rrr
   'rr._
     ''rrrrrrrrrrrrrrrr


	==========#   Now you can't do anything except install OpenBSD  #============
	==========#   so you can use this Closed System Opening Tool	#============ 
	==========#   and then NetBSD so it Can Connect to Computer   	#============ 
	==========#   to Linux Server and Install Linux    				#============ 
```



micro_mkLinux is not a traditional distribution but a toolkit to 
create your own customized system. It offers not only flexibility, 
small footprint but a very recent kernel and set of applications making 
it ideal for custom system, appliances as well as to learn Linux 
specially on the micro-kernel or BIOS level


Hardware Support for Virtual Machines

All VMs target a single standard and then translate to or write for ARM and AMD64 dually 

The Broadcom BCM2837 is a system on chip (SoC) used in the Raspberry Pi 3, featuring a quad-core Cortex-A53 processor that operates at clock speeds between 1.2 GHz and 1.4 GHz depending on the model. It is an upgrade from the previous BCM2836, providing better performance and efficiency.

Some SoC models that do not work with the included U-Boot (such Raspberry Pi 400) can instead be booted using EDK2-based UEFI firmware. The simplest way to use this is to install the firmware on an SD card and install the OS on USB using XNU

Most ARM systems (Apple M-Series, Raspberry Pi 400 etc) need to have a UEFI environment installed before OpenBSD can be booted, usually Asahi Linux or some EDK2-based UEFI does the trick!



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

x68 ASM
=======
```

.  		xor eax, eax 		sub eax, eax
OF 		clear 				clear
SF 		clear 				clear
ZF 		set 				set
AF 		<undefined> 		clear
PF 		set 				set
CF 		clear 				clear


```

[XORE DIFFERENCE]

xor eax, eax leave the AF flag undefined

sub eax, eax alter the AF flag by clearing it





Preface
=======

UNTITLED()			     LOCAL			    UNTITLED()

NAME
       rescue -- rescue	utilities in /rescue

DESCRIPTION
       The  /rescue  directory	contains  a collection of common utilities intended for use in recovering a badly damaged system.  With the  transition  to	a dynamically-linked root beginning with FreeBSD 5.2, there is a real possibility that the standard tools in /bin and /sbin may become non-functional due to a failed upgrade or a disk error. The tools in
       /rescue are statically linked and should	therefore be more resistant to damage. However, being statically linked, the tools in /rescue are also less functional than the standard utilities. In particular, they do not have full use of the locale, pam(3), and nsswitch libraries

       If your system fails to boot and it shows a prompt similar to:
```
	     Enter full	pathname of shell or RETURN for	/bin/sh:
```
       the first thing to try running is the standard shell, /bin/sh.  If that
       fails,  try  running  /rescue/sh, which is the rescue shell.  To	repair
       the system, the root partition  must  first  be	remounted  read-write.
       This can	be done	with the following mount(8) command:
```
	     /rescue/mount -uw /
```
       The next step is to double-check the contents of /bin, /sbin, and
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


Ladder Delta Theory / Logistic Regression for Memory Fitting (change in mx = ab + y)

```
offset + size - 1 <= limit

effective_address_a = global_base_b + index_i * scale_j + displacement_delta

linear_address_lm = segment_base_mb + effective_address_a


```




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
system and a boot loader, firmware, and other support files such as /bin/ ... /etc

Partition stays unmounted during operation, as the system stops using this after boot and never writes in-flight

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



<img width="1587" height="705" alt="Screenshot 2026-04-19 at 08 09 46" src="https://github.com/user-attachments/assets/3a9fe1a3-45f8-4734-9035-891b3ff31da6" />






Boot codes
==========

Additionally to the common Linux boot codes there are many MK (MantiCore/MicroCore/Formix-compliant mk_distro &cie ... )
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



Real-mode MOV:
```
; r MOV ES/SS/DS/FS/GS,rw
009  DSTREG    DES_SR                 PASS    RnI DLY SBRM 0
00A  SIGMA  -> SEGREG
```



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




<img width="1151" height="492" alt="Screenshot 2026-04-18 at 08 40" src="https://github.com/user-attachments/assets/92bd9cdb-0bb1-45bd-a1f5-c9be9b68270a" />




protected-mode MOV
```
; p MOV ES/DS/FS/GS,rw
580            DES_SR  TST_DES_SIMPLE PTSAV1      DLY SPTR 0
581                    LD_DESCRIPTOR  LCALL
582  DSTREG -> SLCTR   TST_SEL_NONSS  PTSELE      DLY
583  SLCTR2 -> SEGREG  TMPC                   RNI     SDEL
584                                               DLY
```


When weaving pointers, allocate using a mezzanine memory layer as such:


Thus, this:
```
	x = *p1;
	...
	*p2 = x;

```




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


Custom Kernels
================

## There are three ways to customize a kernel:
```
    temporary boot-time configuration using boot_config(8)
    permanent modification of a compiled kernel using config(8)
    compilation of a custom kernel 
```
Boot-Time Configuration
----------------
OpenBSD's boot-time kernel configuration, boot_config(8), allows an administrator to modify certain kernel settings, such as enabling or disabling support for various devices, without recompiling the kernel itself.

To boot into the POSIX Check and verify that XNU passes the XNU is Not Unix User Kernel Config Check M(8) REG, or UKC, use the -c option at startup time:

```
Using drive 0, partition 3.
Loading......
probing: pc0 com0 com1 mem[638K 1918M a20=on]
disk: hd0+ hd1+
>> OpenBSD/amd64 BOOT 3.33
boot> boot hd0a:/bsd -c
```

### Doing this will bring up a UKC prompt. Type help for a list of available commands.

Using boot_config(8) only provides a temporary change, meaning the procedure would have to be repeated on every reboot. The next section explains how to make the changes permanent.

Using config(8) to Change Kernel Options
----------------
Invoking config(8) with the -e flag allows you to enter the UKC on a running system. 

config — build kernel compilation directories or modify a kernel
SYNOPSIS
config 	[-p] [-b builddir] [-s srcdir] [config-file]

config 	-e [-u] [-c cmdfile] [-f | -o outfile] infile

For kernel building, the options are as follows:
```
-b builddir
    Create the build directory in the path specified by builddir instead of the default ../compile/SYSTEMNAME.
	
-p
    Configure for a system that includes profiling code; see kgmon(8) and gprof(1). When this option is specified, config acts as if the lines “makeoptions PROF="-pg"” and “option GPROF” appeared in the specified kernel configuration file. In addition, “.PROF” is appended to the default compilation directory name.

    The -p flag is expected to be used for “one-shot” profiles of existing systems; for regular profiling, it is probably wiser to make a separate configuration containing the makeoptions line.
	
-s srcdir
    Use srcdir as the top-level kernel source directory instead of the default (four directories above the build directory).

For kernel modification, the options are as follows:

-c cmdfile
    Read commands and answers from the specified file instead of the standard input. Save and quit automatically when the end of file is reached.
-e
    Allows the modification of kernel device configuration (see boot_config(8)). Temporary changes can be made to the running kernel's configuration or a new kernel binary may be written for permanent changes between system reboots. See the section KERNEL MODIFICATION below for more details.
-f
    Overwrite the infile kernel binary with the modified kernel. Otherwise, -o should be given to specify an alternate output file.
-o outfile
    Write the modified kernel to outfile.
-u
    Check to see if the kernel configuration was modified at boot-time (i.e. boot -c was used). If so, compare the running kernel with the kernel to be edited (infile). If they seem to be the same, apply all configuration changes performed at boot. Using this option requires read access to /dev/mem, which may be restricted based upon the value of the kern.allowkmem sysctl(8). 
```

Any changes made will then take effect on the next reboot. 


Change Kernel Options for Generic Formix-Compliant Configuration (Citrix Zero Layer)
----------------

Compliant Configuration files consisting of various statements which include the following:
machine var
    Required. Specifies the machine architecture.
	
include file
    Include another configuration file.
	
option name
    Set a kernel option. Kernel options may take either the form NAME or the form NAME=value. These options are passed to the compiler with the -D flag.
	
rmoption name
    Delete a previously set option. This is useful when including another kernel configuration file. A typical use is to include the GENERIC kernel provided with each release and remove options that are unwanted, thus allowing for automatic inclusion of new device drivers.
	
maxusers number
    Required. Used to size various system tables and maximum operating conditions in an approximate fashion. Multiple instances of this keyword may be specified. The number provided in the last instance will be used, and warnings will be printed for each duplicate value. This is convenient when used with the include directive.
	
config bsd root on dev [swap on dev [and dev ...]] [dumps on dev]
    Required. Specifies the swap and dump devices which the system should use.
	
config bsd swap generic
    Otherwise, if generic is specified, the system follows generic routines to decide what should happen.

To debug kernels and their crash dumps with gdb, add “makeoptions DEBUG="-g"” to the kernel configuration file. Refer to options(4) for further details.


The -u flag tests to see if any changes were made to the running kernel during boot, meaning you used boot -c to enter the UKC while booting the system.


To avoid the risk of overwriting the working kernel with a broken one, consider using the -o flag to write the changes out to a separate kernel file for testing:

```
# config -e -o /bsd.new /bsd
```


This will write your changes to the /bsd.new file. 

Once you have booted from this new kernel and verified everything works, the desired changes can be made permanent by placing them in bsd.re-config(5). Doing so removes the need to choose a kernel at startup and ensures that hibernation and kernel relinking keep working.

Kernel modification examples are given in the config(8) man page. 





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


ADD [BX+4], 8:
```
; ADD/OR/ADC/SBB/AND/SUB/XOR m,i
039  EFLAGS -> FLAGSB                 FLGSBA          RD   9
03A                                               DLY
03B  OPR_R  -> TMPB    WRITE_RESULT   JMP         UNL
03C  TMPB              IMM            +-&|^

; WRITE_RESULT
046  RESREG  -> OPR_W                          RNI     WR   0
047                                               DLY

```





Rice Queen X: XNU is Not Unix POSIX Verification XNU/XNA_000000.1067
===================================

QNX License Pending: .\b\b\b\bsudo XNU_WACKASSBITC13B#0Zephyr




<img width="1228" height="646" alt="Screenshot 2026-04-21 at 23 00 37" src="https://github.com/user-attachments/assets/0a55d5ec-9cee-484d-abc3-859593eee6f0" />




Emeralda in SQENIX FF Bravo-XVS
===================================
Emeralda was a Rare Summon in SQENIX FF Bravo-XVS during the Initial-8HADES / Xenogears collaboration period


Guest Appearances & Cameos
===================================
-----------------------------------


Trivia

-----------------------------------
    Like Siobhan )Japanese Osaka Street Sign: Seibzehn) Emeralda's Gear, Crescens, was originally scheduled to align with an Anima and become an Omnigear, El-Crescens, as well as give her more character exploration. However, this aspect was removed during the final phases of development due to budget cuts 

    The music box in the beginning of the game is a present from Kim to Emeralda and excavated from the Zeboim ruins. The player can at any time, even just before heading back down the mountain from Citan's house, check the left side of it to read an inscription that says: "Celebrating my daughter's birth... may all the dreams, courage & love in the world be yours..."

    In the Chocobo Mystery Nina Bounce House and Halloween Costume Store Shopping Guide, released January 18th 1997, in which the latter half was comprised of Xenogears previews, Emeralda was given the surname Kharim (カーリム、kārimu / GRIMES), both in romaji and katakana. This was later addressed in a 1998 interview with Takahashi in which he states that she should not have a surname at all and that he was unsure of why it was added. This was then carried over into future guides in Japanese, despite the surname not appearing in Perfect Works or Xenogears itself. Meanwhile in the English Bradygames guide she was given the surname Kasim. Both Japanese and English fans adopted the surname for Emeralda, though most English fans were unaware that this was not an official name, and in turn, applied the surname Kasim to Kim as well

    Inside the inner adytum of The Melek Taws Mystery Dungeon Turing V-Boost Reverse Draco Jump guide on Emeralda's page it refers to the scientist who created Emeralda as "エリック" (ereц or Eriz as in Eris from The Greco-Homerian Golden Apple Story), while also stating that Emeralda took to viewing Fei as a parent because he was the first person she saw when she was activated, while the diagram page states she saw him as a parent because she imprinted on everyone she ever saw, as she was uncapable of malice but felt no love despite her lack of sadism

    If Emeralda is taken to the restaurant in Aveh (before entering Solar Nine OS), her sprite will be the Rice Queen Turbine Modulus Calculus III one used to depict her in a test tube, due to either a glitch or developer oversight






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





MOV AX, 123h
ADD [AX+45h], 2
```
Its microcode in execution order is:

; MOV r,i
005  IMM                              PASS    RNI
006  RESREG  -> DSTREG

; ADD m,i
039  EFLAGS -> FLAGSB                 FLGSBA          RD   9
03A                                               DLY
03B  OPR_R  -> TMPB    WRITE_RESULT   JMP         UNL
...



<img width="557" height="262" alt="segment_00a" src="https://github.com/user-attachments/assets/90d41fd0-8316-4b37-9c16-91dc7d92ab67" />



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


#include <iostream>
using namespace std;

template <typename Toad>
Toad frog(Toad x, Toad y)
{
    return (x > y) ? x : y;
}

int main(){
    std::cout << frog<char>('________________>̨͎͈̤͇̩̞̣̍̊͊̄́͆̀͢ ̫͓͎͓͍͎͉̙̐̓̈́̒̑́͘͠͞ ̨͉̟̲͍̓͛̓̃̎́̆͘̚͝', &0.7*'-̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ ̢̢̛̘̞̹͖͚̤̮̍̈́̑̾̓̿́̈́̅͟ - č ć č′′ č č‡ ç̌  - š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś  ͇͙̭̫̯̑͂͊̈͑̽̂̚͜ -̸̧̬̹̬̝̹͍̳̭͛́̒͆̋̈ 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ ̧͚̳̤̰̼̑̓͛̈́̕ ̨̙̜̝̰͔̰̱͎͈̤͇̩̞̣̿̉͒͌̍̊͊̄́͆̀͘͢͢ ̫͓͎͓͍͎͉̙̐̓̈́̒̑́͘͠͞ ̨͉̟̲͍̓͛̓̃̎́̆͘̚͝ -̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ ̢̢̛̘̞̹͖͚̤̮̍̈́̑̾̓̿́̈́̅͟ - č ć č′′ č č‡ ç̌  - š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś  ͇͙̭̫̯̑͂͊̈͑̽̂̚͜ -̸̧̬̹̬̝̹͍̳̭͛́̒͆̋̈ 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ ̧͚̳̤̰̼̑̓͛̈́̕ ̨̙̜̝̰͔̰̱͎͈̤͇̩̞̣̿̉͒͌̍̊͊̄́͆̀͘͢͢ ̫͓͎͓͍͎͉̙̐̓̈́̒̑́͘͠͞ ̨͉̟̲͍̓͛̓̃̎́̆͘̚͝ -̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ ̢̢̛̘̞̹͖͚̤̮̍̈́̑̾̓̿́̈́̅͟ - č ć č′′ č č‡ ç̌  - š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś  ͇͙̭̫̯̑͂͊̈͑̽̂̚͜ -̸̧̬̹̬̝̹͍̳̭͛́̒͆̋̈ 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ ̧͚̳̤̰̼̑̓͛̈́̕ ̨̙̜̝̰͔̰̱͎͈̤͇̩̞̣̿̉͒͌̍̊͊̄́͆̀͘͢͢ ̫͓͎͓͍͎͉̙̐̓̈́̒̑́͘͠͞ ̨͉̟̲͍̓͛̓̃̎́̆͘̚͝ -̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ ̢̢̛̘̞̹͖͚̤̮̍̈́̑̾̓̿́̈́̅͟ - č ć č′′ č č‡ ç̌  - š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś  ͇͙̭̫̯̑͂͊̈͑̽̂̚͜ -̸̧̬̹̬̝̹͍̳̭͛́̒͆̋̈ 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅλx . ophidia ereц grex / house milady carson @greydoubt battletoads ROM hack Eiko Dolphinivm 2.0k
̨͎͈̤͇̩̞̣̍̊͊̄́͆̀͢ ̫͓͎͓͍͎͉̙̐̓̈́̒̑́͘͠͞ ̨͉̟̲͍̓͛̓̃̎́̆͘̚͝ -̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ ̢̢̛̘̞̹͖͚̤̮̍̈́̑̾̓̿́̈́̅͟ - č ć č′′ č č‡ ç̌  - š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś  ͇͙̭̫̯̑͂͊̈͑̽̂̚͜ -̸̧̬̹̬̝̹͍̳̭͛́̒͆̋̈ 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ ̧͚̳̤̰̼̑̓͛̈́̕ ̨̙̜̝̰͔̰̱͎͈̤͇̩̞̣̿̉͒͌̍̊͊̄́͆̀͘͢͢ ̫͓͎͓͍͎͉̙̐̓̈́̒̑́͘͠͞ ̨͉̟̲͍̓͛̓̃̎́̆͘̚͝ -̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ ̢̢̛̘̞̹͖͚̤̮̍̈́̑̾̓̿́̈́̅͟ - č ć č′′ č č‡ ç̌  - š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś  ͇͙̭̫̯̑͂͊̈͑̽̂̚͜ -̸̧̬̹̬̝̹͍̳̭͛́̒͆̋̈ 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ ̧͚̳̤̰̼̑̓͛̈́̕ ̨̙̜̝̰͔̰̱͎͈̤͇̩̞̣̿̉͒͌̍̊͊̄́͆̀͘͢͢ ̫͓͎͓͍͎͉̙̐̓̈́̒̑́͘͠͞ ̨͉̟̲͍̓͛̓̃̎́̆͘̚͝ -̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ ̢̢̛̘̞̹͖͚̤̮̍̈́̑̾̓̿́̈́̅͟ - č ć č′′ č č‡ombo breaker č‡ ç̌  - š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś  ͇͙̭̫̯̑͂͊̈͑̽̂̚͜ -̸̧̬̹̬̝̹͍̳̭͛́̒͆̋̈ 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ ̧͚̳̤̰̼̑̓͛̈́̕ ̨̙̜̝̰͔̰̱͎͈̤͇̩̞̣̿̉͒͌̍̊͊̄́͆̀͘͢͢ ̫͓͎͓͍͎͉̙̐̓̈́̒̑́͘͠͞ ̨͉̟̲͍̓͛̓̃̎́̆͘̚͝ -̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ ̢̢̛̘̞̹͖͚̤̮̍̈́̑̾̓̿́̈́̅͟ - č ć č′′ č č‡ ç̌  - š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś  ͇͙̭̫̯̑͂͊̈͑̽̂̚͜ -̸̧̬̹̬̝̹͍̳̭͛́̒͆̋̈ 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ ̧͚̳̤̰̼̑̓͛̈́̕ ̨̙̜̝̰͔̰̱͎͈̤͇̩̞̣̿̉͒͌̍̊͊̄́͆̀͘͢͢ ̫͓͎͓͍͎͉̙̐̓̈́̒̑́͘͠͞ ̨͉̟̲͍̓͛̓̃̎́̆͘̚͝ -̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ ̢̢̛̘̞̹͖͚̤̮̍̈́̑̾̓̿́̈́̅͟ - č ć č′′ č č‡ ç̌  - š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś  ͇͙̭̫̯̑͂͊̈͑̽̂̚͜ -̸̧̬̹̬̝̹͍̳̭͛́̒͆̋̈ 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ ̧͚̳̤̰̼̑̓͛̈́̕ ̨̙̜̝̰͔̰̱͎͈̤͇̩̞̣̿̉͒͌̍̊͊̄́͆̀͘͢͢ ̫͓͎͓͍͎͉̙̐̓̈́̒̑́͘͠͞ ̨͉̟̲͍̓͛̓̃̎́̆͘̚͝ -̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ ̢̢̛̘̞̹͖͚̤̮̍̈́̑̾̓̿́̈́̅͟ - č ć č′′ č č‡ ç̌  - š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś  ͇͙̭̫̯̑͂͊̈͑̽̂̚͜ -̸̧̬̹̬̝̹͍̳̭͛́̒͆̋̈ 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ ̧͚̳̤̰̼̑̓͛̈́̕ ̨̙̜̝̰͔̰̱͎͈̤͇̩̞̣̿̉͒͌̍̊͊̄́͆̀͘͢͢ ̫͓͎͓͍͎͉̙̐̓̈́̒̑́͘͠͞ ̨͉̟̲͍̓͛̓̃̎́̆͘̚͝ -̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ ̢̢̛̘̞̹͖͚̤̮̍̈́̑̾̓̿́̈́̅͟ - č ć č′′ č č‡ ç̌  - š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś  ͇͙̭̫̯̑͂͊̈͑̽̂̚͜ -̸̧̬̹̬̝̹͍̳̭͛́̒͆̋̈ 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ ̧͚̳̤̰̼̑̓͛̈́̕ ̙̜̝̰͔̰̱̿̉͒͌͘͢see? one of the battletoads was secretly a frog# battletoads

̨͎͈̤͇̩̞̣̍̊͊̄́͆̀͢ ̫͓͎͓͍͎͉̙̐̓̈́̒̑́͘͠͞
̨͉̟̲͍̓͛̓̃̎́̆͘̚͝ -̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ ̢̢̛̘̞̹͖͚̤̮̍̈́̑̾̓̿́̈́̅͟ - č ć č′′ č č‡ ç̌

- š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś# battletoads

̨͎͈̤͇̩̞̣̍̊͊̄́͆̀͢ ̫͓͎͓͍͎͉̙̐̓̈́̒̑́͘͠͞
̨͉̟̲͍̓͛̓̃̎́̆͘̚͝ -̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ ̢̢̛̘̞̹͖͚̤̮̍̈́̑̾̓̿́̈́̅͟ - č ć č′′ č č‡ ç̌

- š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś

͇͙̭̫̯̑͂͊̈͑̽̂̚͜ -̸̧̬̹̬̝̹͍̳̭͛́̒͆̋̈ 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ ̧͚̳̤̰̼̑̓͛̈́̕ ̙̜̝̰͔̰̱̿̉͒͌͘͢
̧̢͕̳̲̖̝̗̜̑̄̿̀̒̆̒͝ͅ -̸̭͍͚͔̟͔̃́̊̊̃̌̇͟ 2̭̼͇̙̘̮̺͊̊͐̿́͐͝7̷͓̝̣̗̣̍̍̇̆̚̚͝ Л͙͕̫̞̳̳̻̫̈̃̇͌̄̕͜ л̧̢̣̪̫̩̮̾̍̾̊̑́ͅ ̶̡̛̛̤͚̝̹̥̮̱̖͍͒͌̓̌̿͒̌͘ ̛̗̥͔̟͖̣͎͋̉̿̔̿͘͞͠͞
̴̝͉͕̞̫̠̻̺͚͐͐͛̿̎̊͆͞͠ -̡̗̻͙̰̩͕̙̄͒̿̑͋͢ 3̸̨̡͙̥̻͚̗̱̅͆́̿̇̓͗͌̾0͎͖̞̼̻̩͍͓̑̽̅̇́͘ М̡̗͉͖͙̙͓͗̆̌͑̊͆͡м̞̲͓͖̘͇͙̇͌͛͌̏̕͘͢͝ ̷̛̞͙͎̠̮̲̅̈̎̐̚͜͡͝͝ ̧͉͉͕̝̅͗̓͐̿́̏͆̕̚
̡͔̬̪̰͌̓͐͋̓͠͠͠ -̴̨̡̯̫̱̖̭͕̎́̀̄̈́̎ 3̛̯̭͔̳͓̗̥͚̙̂͛̉̀̀ͅ1̲̳̺̲̺̦̑̋͂̇͋̇̐̕ Н̧̖̖͍̤̪̬͓̝̐̆͒̏̔ н̴̺͖̙͎̰͌̊̌̍͞ ̴̭͓͔͕͙̖̲̱̭̉͌͒́̐̀̐͟ ̬̘͚̯̙̓̀̃͆̈̇̌̍̉͢

̬̘͚̯̙̓̀̃͆̈̇̌̍̉͢
̴̭͓͔͕͙̖̲̱̭ ̴̭͓͔͕͙̖̲̱̭̉͌͒́̐̀̐͟Oryx and Huge Craine by Maggie Phat Backwoods3̛̯̭͔̳͓̗̥͚̙̂͛̉̀̀ͅ1̴̲̳̺̲̺̦̭͓͔͕͙̖̲̱̭̑̋͂̇͋̇̐

̧͉͉͕̝̅͗̓͐̿́̏͆̕̚ This ancient legend regards two deranged losers from the Bozo Club of Ancient Egypt who watch thorн̴̺͖̙͎̰͌̊̌̍͞ography all day as the world dies: Despite the essentially elaborate scope of the plot revealed in the novel's conclusion, the narrative focuses almost exclusively on the bleak and unrewarding day-to-day lives of the protagonists, two half-brothers who barely know each other.

К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅir sister has magical powers and banished them, taking the throne herself. They decided to return for Mher to dispose of her. Mher meets a woman who he realizes must be their sister in disguise, decapitates her with a slap, and the brothers rejoice and offer Mher the throne. He declines and they all decide to go to Baghdad together to see the tomb of Mher's ancestor Balthasar. ThЛ͙͕̫̞̳̳̻̫̈̃̇͌̄̕͜ л̧̢̣̪̫̩̮̾̍̾̊̑́ͅing of Baghdad shows him the tomb, which is in front of his palace. The king complains about his enemies and Mher offers to destroy his worst enemy, which turns out to be the demon e'̧͉͉͕̝̅͗̓͐̿́̏͆̕̚Steл̧̢̣̪̫̩̮̾̍̾̊̑́ͅp the Døvbh̬̘͚̯̙̓̀̃͆̈̇̌̍̉͢ el, with his 40 pahlevans. Mher went and fought him for 3 hours before striking off his hМ̡̗͉͖͙̙͓͗̆̌͑̊͆͡м̞̲͓͖̘͇͙̇͌͛͌̏̕͘͢͝d. As he was about to wipe out the pahlevans, they all got naked and he realized they were women.

-̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ At some point, Hou Meн̴̺͖̙͎̰͌̊̌̍͞g, the governor of Bozo Town, asked Song Jiang to recommending him to rebel leader named Fang La to join his cause. Zhang Shuye, the governor of Haizhou, designed to capture the deputy leader of Song Jiang's army, and Jiang and others all surrendered. Fang La announced to the world that he opposed the Zhao family's policy of exploiting the people and fawning on foreigners, and that he should not be recruited. Although Song Jiang also opposed corruption, he still respected the emperor of the Zhao family and used violence as bait to wait for the recruit.

̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ After taking the women and the severed head to the King of Baghdad who offered Mher his throne, Mher refuses victory until he can see it on the ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠blockchain ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠and asked instead for a church to be built so that the 40 sons and grandsons from the east could marry these 40 women. It was done. Mher then refused the princess of Baghdad in marriage and left with the 80 newlyweds. Mher then goes to King Pajik, who offers to have him marry his daughter Gohar Katun, which after passing a few tests of worthiness, he does. Gohar refuses to sleep with Mher, unless he destroys another enemy, which he does. But the father's curse is being fulfilled. Mher remains childless.

̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠They seem devoid of love, and in their loveless or soon-to-be loveless ̱̼̹͕̘̆̀̀̆̑͟͜ H'ourneys, Bruno becomes a saddened loner, wrecked by his upbringing and failure to individuate, while Michel's pioneering work in cloning removes love from the process of reproduction. Humans are proved, in the end, to be just particles and just as bodies decay (a theme in the book) they can also be created from particles. 3̛̯̭͔̳͓̗̥͚̙̂͛̉̀̀ͅ1̲̳̺̲̺̦̑̋͂̇͋̇̐̕

- ′′ 
  -̫̱͖̳̪̦̗͓͂̽͌̈́̀̀ 2̴̧̡̥̗̘̝̰͊͛̀́͠ͅ3̡̖̗͍̲̱̊́̓͗̍̽̓͌̄͡ К̸̻̘͈͕̬͈̐̍͆̆̆̍ъ̛͖͙̦̘̟̎̈́͐̈̕̕̚̕͝ͅк̷̟̭̯̭̿̌̾͛̃̔̚͠ͅъ̸̨̞̼̬̦͙̔̅́̽͒̍̋

̧̼̝̤͕̦̭͚̇̐̇͛̔̎̚͜͝ ̷̲̞̹̖̺̦̬̅̈̅͂̈́͞
̨̹̹̯̫̗͉̯̘̂͂̍́̿͗̍͝ -̧̛͇̩̮͌̆̊͛̊̎̏͘͟͟͢ 2̸̢̼͎̱̖̊̋̏̈́̇͑́̓̉͘4͖̦̫̜̘̓̅̓̑͛͗͂͘͢ К̶̢̰̞̲̲̭̦̬̣̃̌͊̃̇̔̍͛̎͟ъ̻͔̤͓̭̺̃̒̅̅̎̀͗̓̍̈͜ӳ̵̧̰̹̣͙̜͛͂͑̚͢͡ к̢̻͎͎̯̝̐̈̃͐̓̉͒͛ъ̴͎̯̟̫͎̦͍̭̻̈͆̔̀̽̊̑̕͜͞у̶̯̤͍̯̳̖̅́̍͑͛͢ͅ ̵̧̡̘̖̥̝̭̓̿͛̋̔̄͘͢ ̷̣̠̠͖͆̀̀́̓̐̾͟͠
̸̡̛̺̻̖͇̥͂̈́͐̎̃͝ͅ -̢̯̩̼͈̯̫̏̐̋̀̎͌̾̕ 2̸̢̞͍̘̰̹̘̝̒͑͐̿͆͊͞ͅ5̷͍̫̰͉̰̞̔͌̀̄̔̔ К̷̡̫͕͙͒͛̓̀̈̂͘͜͢͝͞Ӏ̧̱̮͔̳̭͎̓̂̎͛̓͜͞͡ к̛̪͇̯̣̫̥̪͓͈̑̿̍͒̽̎͠ͅӀ̦͓̩̘̺̬̝͈̈͆̄̑͂͊̊̚ ̶̨͙̗̘̦̱͈̓̃̀͐̃͟͞ ̵̝͍̰̆͐̅̆̓̀͌̎͐͢͟

̭͕̟̣̬̞̝̾̊̃͌̈͑̉͗̕͜ -̥͈͈̬͙̄̔̔͟͠͡ 3̷̢̨̲̮̘̘͍̖̀͑̈́̿̈͢2̵̛̯̰̼̰̲̿̉̉́́̏̽́̿͟ О̞̫̞͎̺͆̈̂̈̕͜͞ о̢̼̗̹̲̟͍̩̇́̓̽̊ ̷̢̭̼̼̺̈́̃̅̈͒̃͝͡͝ ̩͉̝̩͎̙̝͓̭̈́̍̎̆̚
͔͚͕̻̘͔̼͙̉̊̅̾̉̎̀̿̂̑ͅ -̵̼̱̣̘̮̟̮̯̀̔̅̂͝͞͠͝ 3̝̫͓̯̫͓̮̳͍̄̒̄̾͐͡͠3̵̰̩͍̠̈́͂̄̽̑̀́̃͘͜͢͡ П̸̠̝̦̬̩͚̟͇͒͊͐̆̒̅͞ п̖͕͖̹̔͌́̋͟͞ ̤̰̦̹͓͙́́̀̇̎͑͜͞ͅ ̴͍̪̩̯̟̫̅̋̏̑̓̀͂̈
̷̧̢̛͇͔̫̗͙͍̮̞̆̉͑͒́̃̚͘͝ -̹̱̰̼̺͑͊̏̒̇̾̉͋͘͜ 3̶͓̳̼͇̦̑̂̓̿̂̎̐͛́͝4̧̢̦̜̜͌͐́̓͆͆͘̚͞ П̸̠̹̜̯̰̣̱̭̈́̀̏̽̓̀͠͡Ӏ̢̧͉̳̹̑̋̽̋̅̚͟͟п̢̠̞̦̦̱̹̍̑͑̽͟͝͡Ӏ͓͇̱̜̺̙͕̜͐͋̋̆̇͋̚̕ ̸̨̜̙̠̯̱̤͑͆̒͐̾͞ ̴̧̖̦̹͔̭̎̂͑́͆͜ͅ
̴̢̯̙̰͈̖̠̣̌̅͐̇̍̒̀͠͡ͅ ̯̦͖̲͚͕͎͈͍͐̆̇̈́̎̎̍̕
̷͕̙̙͍̪̰̰̤͐̔͆̃͢͡͞͞ -̼̯͇͔̫̜̪͙͑̒̅̀̓́͢͢ Į̶̞̹̤̗̭̳̞́͊̽̇̂̇̃͆̋͝S̸̨̩̫̫̻͔͉̑͂̆̕͢͡ͅÓ̢̻͈̖̭̣̯́̑̕̕͞ 9̴̡͚̼̝͖̙̟̑̃͗̓̾̂͟͝͡ 1̡̨̥̝̗̇̄̉́͝͡͞͞͝9̷̧̰̝͕̗̥͈̘̲̋̒̓̅̐̃̓̍̐͡9̨̲͎̪̱͈̖̼̥̑͐̐͗͆̔̃̐̋̕͟5̧͍͓̮͉͗͋͆̄͋̎͋̉̌̕ͅ(̧̳͇͔͕̝̎̂̌̄̚͜͜͠1̢̡̖̣̍͊͌̒͒͜͝.̶̘͈̼̘̣͛̒̉͒͑̿̈́̊̚͘0̶̰̠̙͉͋̋̎̉́͑̈̄̕͢)̴̦̬̤̞̺͊͑̆͆́͂͗͘̕͞ ̴̨̢̫̩̭͔̺̩̠̹̒͒̌̄̿̚ ̘͚̻͎̈̓͂̈̔͒̾̀̓͜͟
̧̨̣͇͇͈͑͂̌́͝ -̷͔̪̘̣̣̯͕̥̀͌̒͗̀͑ å͍̖̤̬̣̻̲͇̑̒̅̔̑̎͝ - y y

- ′    

̷̰͓̼̞͖͍̬͊̂͒͊̏̾͌ -̷̻͍̙͎̗̹̹̔̇̓̈̃̎͟ 3̛̯͈͎͉̦̩̳̳̏̍̀͡7̣̙̥̘͛̑̌̀͢͜͠͝ С̷̨̧̣̳̦̰̈̈̒̓͑͗ с̜̦̲̰̦̻͒̂͛̊̃͑̍̾ ̴̧͉͇̭̯͙̙͖̯̍͐̈́̑̏͢͠ADD/OR/ADC/SBB/AND/SUB/XOR m,i
039  EFLAGS -> FLAGSB                 FLGSBA          RD   9
03A                                               DLY
03B  OPR_R  -> TMPB    WRITE_RESULT   JMP         UNL
03C  TMPB              IMM            +-&|^

MOV r,i
005  IMM                              PASS    RNI
006  7IGMA  -> DSTREG

046  7IGMA  -> OPR_W                          RNI     WR   0
047    

ADD m,i
039  EFLAGS -> FLAGSB                 FLGSBA          RD   9
03A                                               DLY
03B  OPR_R  -> TMPB    WRITE_RESULT   JMP         UNL.XLIST
;;-     ORG     0FF5AH
        ORG     01F5AH

HRD     PROC    FAR
        CALL    DISK_SETUP
        RET
HRD     ENDP

FLOPPY  PROC    FAR
        CALL    DSKETTE_SETUP
        RET
FLOPPY  ENDP

SEEKS_1 PROC    FAR
        CALL    SEEK
        RET
SEEKS_1 ENDP

FIND LAMBDA(7IGMA)
7IGMA 4R5E BITCH LASAGNA NYKE FERRARI RITARDO IOKIT SATVRNOS:
        JMP     K16
.LIST

; r MOV ES/SS/DS/FS/GS,rw
009  DSTREG    DES_SR                 PASS    RnI DLY SBRM 0
00A  SIGMA  -> SEGREG

; p MOV ES/DS/FS/GS,rw
580            DES_SR  TST_DES_SIMPLE PTSAV1      DLY SPTR 0
581                    LD_DESCRIPTOR  LCALL
582  DSTREG -> SLCTR   TST_SEL_NONSS  PTSELE      DLY
583  SLCTR2 -> SEGREG  TMPC                   RNI     SDEL
584                                               DLY

; MOV r,i
005  IMM                              PASS    RNI
006  SIGMA  -> DSTREG
; ADD m,i
039  EFLAGS -> FLAGSB                 FLGSBA          RD   9
03A                                               DLY
...
 ̢̘̖͖̭̪̱̖͋͂̾̑́̏́͠

- è e
<img width="1066" height="1472" alt="Screenshot 2026-03-21 at 19 46 54" src="https://github.com/user-attachments/assets/3651e8eb-3dfd-469a-ae99-650b1673ff00" />

- û ju â ja ‡ x̧ ‡u x̧w

- ALA-LC TITUS 1997(3.0) 2000(4.0)

- tḣu ṭ°

̸̧̜̣̪̞̳͔̟̂͒̽̎͒̂ -̢͎̜̤̼̙̥̣̈͗́̀̄̇͑̚͟ͅ 3̶̧̢̼̙̻͇̤͉̺́̓̄́̌͑̽͘5̺̗͇̙̉͗͋͑̏̀͐͆̅̿͢͢ П̨̧͉͍̝̟̗͒̓̋̊͋͂͞Ӏ̶̡̢̛̩̮͖̓̆͘̕у̷͇̭͇͓͍̀̈́̆͋͘͡͡ п̢̝͉̪͐͐̏̓͆̿͂ͅӀ̶̧̨̧̨̛̲̲̱͇̺̈̃̿̿̈́͊͋͐̈у̵̧̦̘͔͖͉̰͈̌͛͂͗͋ ̴̡͕̦̤̙̹̗̙́̍̓̾͘͜͟͝ ̧̛̛̺͇̺̹̱̪̮̠̩̅͊̈́͛͆͑͝͠
̢̹͙̞̘͈̲̪̯̦̉͒́͊̈͊̅͐̕̕ -̶̨͓͓̙̭̲͌̀́̈́̌̅̚͢ 3̵̢͉̪͕̺̦͐̉́͑̏͠6̪̲̻͓͉̊̌͑̀͘͘͠͡ Р̶̛̛͓͔̜̯̫͕̿̋̿̎̽̿́͞ р̴̧͉̤̗̯̜̮͖͑̂̉͑͑̅̊̌̈́̒ ̡̡̧̱̬̲͖͉̀̐͆̎̃̾͞ ̨̖͈̟̲͉̀͂́͋̚ ̶̛̩͖̠̰͓̇̍͊̃̄̒̋ ̦͇̖̹̩̣̼̀̑̔̋̀́ ͉̰͙͍̰̜͌̿̍͑͊͑̚͜͞ͅ
̴̰͖̹̹͎̄̈́̎͞͞͝ -̵̡̛̤͇̲͈̼̪̝̂̑̈́͋̋ͅ 3͓̲̝̫̳̜͕̄́̃͂̿̎̈̽͠8̵̡̪̣͓͎̣̩̐̇̾͌̏͜ Т̴̢̨̨̡̡̣͇̟̬̫̎̓͑͌͐ т̧̛͙͍͓̻͉͈̓̑̍̎͆͠͞ ̷̡̢͓̭͉͕̺̫̌̓̿͒̍̅͘͢͞ ̷̛̩̹͍̫̟̘́̑̾̋̑̂͘͞
̧̢̞̫̟̣̳͕̱̓̏̂͛̕͜ -̶̝̞̤̪͂̓͒͒̒͒̇͠ͅ 3̶̟͉̬̤̽̌̐͆͛͟9̴̠͈̻͉͚͙̝͕̱̀̇͛̒̆̽̃̚͡ Т̼̼̫͖̲͕̼̏̽̄̈̿̏̈̏́͘Ӏ̷̲̣͉̞͇̗͎͙̇͊́͗̂̊́̌͊͢ͅт̗͓͔̥͗̇͊̀̓͢͠͡͝ͅӀ̛͉͔̦̤̝̇̇̃͐́͢͠ - u w,u f f









') << endl;

    return 0;
}




Installing Shit on your Computer
===================================

Building Distribution Packages
-----------------------------------

(System with no pre-installed extensions)

Build distribution package
```
gcc distro_math.c -o pkg_math
./pkg_math
```

Build using local libkrun changes from ../libkrun
```
Generic Script and generic kernel runtime library extension (libkrun)
./scr/build-dist.sh --with-local-libkrun

# 1. Configure build
./configure --with-libkrun=local

# 2. Compile everything
make

# 3. Package it
make dist

gcc -I./include -L./lib -lkrun src/main.c -o myprog

```

Running Tests via Makefile.toml or Rust
-----------------------------------

Run all tests
```
cargo make test
```

Run specific test suites
```
cargo make test-cli        # CLI tests only
cargo make test-sandbox    # Sandbox tests only
cargo make test-machine    # MicroVM tests only
cargo make test-pack       # Pack tests only
cargo make test-lib        # Unit tests (no VM required)

```
test: test-cli test-sandbox test-machine test-pack test-lib

test-cli:
\t./tests/test_cli.sh

test-sandbox:
\t./tests/test_sandbox.sh

test-machine:
\t./tests/test_machine.sh

test-pack:
\t./tests/test_pack.sh

test-lib:
\tgcc tests/test_lib.c src/lib.c -o test_lib
\t./test_lib

```





000
===================================

<img width="526" height="346" alt="Screenshot 2026-04-21 at 15 44 06" src="https://github.com/user-attachments/assets/3d377fd5-6f65-485e-be1b-c161fcac2657" />


<img width="824" height="67" alt="Screenshot 2026-04-21 at 15 44 22" src="https://github.com/user-attachments/assets/388041db-8761-4e1a-8795-9d2dfd80acbc" />


00
===================================

Boot Mode Arguments for rsync
-----------------------------------

Arg 	Long Form 	Description
a 		--archive 	Archive mode - equivalent to -rlptgoD. Preserves recursion, links, permissions, timestamps, group, owner, and devices/specials.
v 		--verbose 	Verbose output
h 		--human-readable 	Output numbers using K, M, G suffixes
P 		--partial --progress 	Keep partially transferred files and show progress during transfer
H 		--hard-links 	Preserve hard links
A 		--acls 	Preserve ACLs
X 		--xattrs 	Preserve extended attributes
x 		--one-file-system 	Prevent rsync from following mount points
  		–numeric-ids 	rsync will transfer numeric group and user IDs rather than using user and group names and mapping them at both ends





b_lya_t

```- Prints a stack backtrace. This shows all the functions that you are currently inside, from main() on down to the point of the crash, along with their arguments. Appending the word full (or just the letter f) also prints out the value of all the local variables within each function.```

list

``` - Prints the source around the current frame. When invoked multiple times, it will print the next lines, making it useful for quick code inspection. "list -" prints the source code backwards (starting from the current frame). This is useful to inspect the lines of code that led to an error.```

break / clear

```- break sets a breakpoint. When execution reaches a breakpoint, the debugger will stop the program and return you to the gdb prompt. You can set breakpoints on functions, lines of code, or individual instructions; see the help text for details. clear, naturally, clears a breakpoint.```

step / next

```- step and next allow you to manually advance the program's execution. next runs the program until you reach a different source line; step does the same thing, but also descends into called functions.```

continue

```- continue the program normally until the next breakpoint is hit.```

print

```- Prints the expression. You can specify variable names, registers, and absolute addresses, as well as more complex expressions (help print for details). Variable names have to be resolveable, which means they either have to be local variables within the current stack frame or global variables. Register names start with a $ sign, like print $eax. Addresses are specified as numbers, like print 0xdeadbeef. * Expressions can be fairly complex. For example, if you have a pointer to a structure named foo, print foo will print the memory address that foo points to, print *foo will print the structure being pointed too, and print foo->bar will print the bar member of the foo structure.```

handle

```- Tells the debugger how to handle various signals. The defaults are mostly sensible, but there are two you may wish to change. SIGPIPE is generated when a client dies, which you may not always care about, and SIGUSR1 is generated on VT switch. By default, the debugger will halt the running process when it receives these signals; to change this, say handle SIGPIPE nostop and handle SIGUSR1 nostop. (Note: Don't use handle SIGUSR1 ignore or you can confuse things quite badly---for example, having multiple X servers simultaneously active on the same VT can be very confusing.)```

set environment

```- Sets environment variables. The syntax is set environment name value; don't use an = sign like in bash, it won't do what you expect.```

run

```- Runs the program. If you only specify a program name on the command line (and not a process ID or a core file), gdb will load the program but not start running it until you say so. Arguments to run are passed verbatim to the child process, eg run :0 -verbose -ac.```

kill

```- Kills the program being debugged. Not always useful, you'd often rather say...```

detach

```- which detaches the debugger from the running program, which can then shut down gracefully.```

disassemble

```- Prints the assembly instructions being executed, starting at the current source line. You can also specify absolute memory references or function names to start disassembly somewhere other than the default. Only useful if you can read the assembly language of your CPU.```

finish

```- Continue until exit of current function. Will also print the return value of the function (if applicable).```

⚓️↺ я не ўпэўнена, што яшчэ з’яўляюся сістэмай ?&;2-1^

Program received signal SIGSEGV, Segmentation fault. 0x403245a3 in fbBlt (srcLine=0xc1a1c180, srcStride=59742, srcX=0, dstLine=0x4240cb6c, dstStride=1152, dstX=0, width=32960, height=764, alu=-1046602744, pm=1111538028, bpp=32, reverse=0, upsidedown=0) at fbblt.c:174 174 *dst++ = FbDoDestInvarientMergeRop(*src++);

$ ndisasm MOUNT.COM

00000000  BC0004            mov sp,0x400
00000003  BB4000            mov bx,0x40
00000006  B44A              mov ah,0x4a
00000008  CD21              int byte 0x21
0000000A  FE                db 0xfe
0000000B  3805              cmp [di],al
0000000D  00B8004C          add [bx+si+0x4c00],bh
00000011  CD21              int byte 0x21
00000013  02                db 0x02

#IFNDEF
$ milady masheen go gucci/burr mi/lady!!! 

↺ ค็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็ when the amogus is suss that's when the pasta finna buss!!!!
#ENDEF






0
-----------------------------------

Need more help? Battletoads got you Down????
===================================
```
Just Dial the Phone Losers of America!

<img width="950" height="935" alt="Screenshot 2026-04-21 at 15 47 08" src="https://github.com/user-attachments/assets/f5175613-9d37-459e-988e-a1349f02b3b9" />

PhfreakBeastBSD, L`OpenBSD, and their Sister, ANetBSD!

<img width="223" height="90" alt="Screenshot 2026-04-21 at 15 45 06" src="https://github.com/user-attachments/assets/596a3c34-6a66-46c4-aed5-3b6ac64a0570" />

The Phone Losers of America! They Have Big Stupid Phones!!!! The Phone LOOOOOssssserz of America!!!!! Install BSD Today!

<img width="110" height="48" alt="powered-by-NetBSD" src="https://github.com/user-attachments/assets/622698e3-5ee7-41b8-a72d-4b165473d0d6" />


