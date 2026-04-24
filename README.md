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

Firstly one must ... download the fucking file set:


File Sets
---------
The complete OpenBSD installation is broken up into a number of file sets:
```
bsd 	The kernel (required)
bsd.mp 	The multi-processor kernel (only on some platforms)
bsd.rd 	The ramdisk kernel
base78.tgz 	The base system (required)
comp78.tgz 	The compiler collection, headers and libraries
man78.tgz 	Manual pages
game78.tgz 	Text-based games
xbase78.tgz 	Base libraries and utilities for X11 (requires xshare78.tgz)
xfont78.tgz 	Fonts used by X11
xserv78.tgz 	X11's X servers
xshare78.tgz 	X11's man pages, locale settings and includes 
```

And then act as the Shahan al-Shan bin JavaScript of Ancient Persia would and perform a check sum on that piece of shit to make sure the Tsar did not tamper with al-Gin:

```
$ sha256 -C SHA256 miniroot*.img
(SHA256) miniroot78.img: OK
```

Or, if you're using the GNU coreutils:
```
$ sha256sum -c --ignore-missing SHA256
miniroot78.img: OK
```

However, this only checks for accidental corruption aka "Good enough for the benchoades wanting to play my clown ass"

You can use signify(1) and the SHA256.sig file to cryptographically verify the downloaded image:
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
-------------------------------------

All VMs target a single standard and then translate to or write for ARM and AMD64 dually 

The Broadcom BCM2837 is a system on chip (SoC) used in the Raspberry Pi 3, featuring a quad-core Cortex-A53 processor that operates at clock speeds between 1.2 GHz and 1.4 GHz depending on the model. It is an upgrade from the previous BCM2836, providing better performance and efficiency.

Some SoC models that do not work with the included U-Boot (such Raspberry Pi 400) can instead be booted using EDK2-based UEFI firmware. The simplest way to use this is to install the firmware on an SD card and install the OS on USB using XNU

Most ARM systems (Apple M-Series, Raspberry Pi 400 etc) need to have a UEFI environment installed before OpenBSD can be booted, usually Asahi Linux or some EDK2-based UEFI does the trick!


The F Word that Rhymes with Suck Duck
-------------------------------------
fsck(8): You can mount partitions that you never or rarely need to write to as readonly most of the time, which will eliminate the need for a filesystem check after a crash or power interruption


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

HEX THAT SHIT with IOKit
===================================

(Hekit/Hecate Controller Potion Formula Scribe)



<img width="1499" height="1121" alt="Screenshot 2026-04-23 at 06 01 43" src="https://github.com/user-attachments/assets/8a80539b-d8e0-4c23-a8e7-c1b7997eb39f" />


Suppose you have a tiny 6x6 grid, it can be a PNG image or a JSON array: It just has to reduce to atomic components even if those can be represented in some other way, ergo it forms a dual-system. The core metaphor is that it is a 6 pixels by 6 pixels image normalised to a grid and quantised down to an atomic sub-unit (ie a pixel has 3 values for RGB colours)

That is why hexadecimal instead of base-AnythingElse is used: it forms a cubic grid, ie, allows for quantum operations on the lattice using functional operators at relativistic speeds.  Remember that two hex digits are one byte and can be encoded/decoded from the front or trailing end depending on how masochistic the device manufacturer felt that day. When we store it using little endian, we store the least significant byte (LSB) first in the file (or memory). For that reason, little endian can also be called LSB first. 

To obtain a hex dump use this command:
```
$ xxd 6x6_24bit.PNG
```

It will be more convenient to view in vim, do not omit the trailing -
```
$ xxd 6x6_24bit.png | vim -
```

<img width="964" height="900" alt="Screenshot 2026-04-23 at 06 10 23" src="https://github.com/user-attachments/assets/ee1c799e-9706-4409-a585-d0369f122b2e" />





Example BitMap (BMP) standard header specification
===================================
typedef struct {             // Total: 54 bytes
  uint16_t  type;             // Magic identifier: 0x4d42
  uint32_t  size;             // File size in bytes
  uint16_t  reserved1;        // Not used
  uint16_t  reserved2;        // Not used
  uint32_t  offset;           // Offset to image data in bytes from beginning of file (54 bytes)
  uint32_t  dib_header_size;  // DIB Header size in bytes (40 bytes)
  int32_t   width_px;         // Width of the image
  int32_t   height_px;        // Height of image
  uint16_t  num_planes;       // Number of color planes
  uint16_t  bits_per_pixel;   // Bits per pixel
  uint32_t  compression;      // Compression type
  uint32_t  image_size_bytes; // Image size in bytes
  int32_t   x_resolution_ppm; // Pixels per meter
  int32_t   y_resolution_ppm; // Pixels per meter
  uint32_t  num_colors;       // Number of colors  
  uint32_t  important_colors; // Important colors 
} BMPHeader;




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



# Installation of XNA BSD Microkernel
============

kernel manifest files deploy as a requirements package (text list, .zip archives containing raw SD card image 
which can be installed with dd command on Linux or Win32 Disk Imager on 
Windows, et cetera) 

After successfully copying image to SD card it is ready to boot 
into virtual environment or actual device. While it works offline, advised to have a wired 
Internet connections to have proper system time, to install packages or 
for remote SSH access depending on which image you have installed

## Installing Graphics Cards Drivers
============

This installs the basic drivers that will boot you into shitbox mode so you can download something better(tm)
```
# pkg install drm-kmod
```

Then add the module to /etc/rc.conf file, by executing the following command:
```
sysrc kld_list+=i915kms
sysrc kld_list+=amdgpu
```

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




CAPSICUM(4)		    Kernel Interfaces Manual		   CAPSICUM(4)

NAME
       Capsicum	-- lightweight OS capability and sandbox framework

SYNOPSIS
       options CAPABILITY_MODE
       options CAPABILITIES

DESCRIPTION
       Capsicum	 is  a	lightweight OS capability and sandbox framework	imple-
       menting a hybrid	capability system  model.   Capsicum  is  designed  to
       blend  capabilities  with  UNIX.	  This	approach  achieves many	of the
       benets of least-privilege operation,  while  preserving	existing  UNIX
       APIs and	performance, and presents application authors with an adoption
       path for	capability-oriented design.

       Capabilities  are unforgeable tokens of authority that can be delegated
       and must	be presented to	perform	an action.  Capsicum  makes  file  de-
       scriptors into capabilities.

       Capsicum	 can be	used for application and library compartmentalisation,
       the decomposition of larger bodies of  software	into  isolated	(sand-
       boxed) components in order to implement security	policies and limit the
       impact of software vulnerabilities.

       Capsicum	provides two core kernel primitives:

       capability mode
	       A  process mode,	entered	by invoking cap_enter(2), in which ac-
	       cess to global OS namespaces (such as the file system  and  PID
	       namespaces)  is	restricted;  only explicitly delegated rights,
	       referenced by memory mappings or	file descriptors, may be used.
	       Once set, the flag is inherited by future  children  processes,
	       and may not be cleared.

	       Access  to  system calls	in capability mode is restricted: some
	       system calls requiring global namespace access are unavailable,
	       while others are	constrained.  For instance, sysctl(2)  can  be
	       used  to	 query process-local information such as address space
	       layout, but also	to  monitor  a	systems	 network  connections.
	       sysctl(2)  is  constrained  by  explicitly marking ~~60 of over
	       15000 parameters	as permitted in	capability  mode;  all	others
	       are denied.

	       The  system  calls  which  require  constraints	are sysctl(2),
	       shm_open(2) (which is  permitted	 to  create  anonymous	memory
	       objects	but not	named ones) and	the openat(2) family of	system
	       calls.  The openat(2) calls already accept  a  file  descriptor
	       argument	 as  the  directory to perform the open(2), rename(2),
	       etc. relative to; in capability mode the	 openat(2)  family  of
	       system  calls  are constrained so that they can only operate on
	       objects under the provided file descriptor.

       capabilities
	       Limit operations	that can be called on file  descriptors.   For
	       example,	 a  file descriptor returned by	open(2)	may be refined
	       using cap_rights_limit(2) so that only read(2) and write(2) can
	       be called, but not fchmod(2).  The complete list	of  the	 capa-
	       bility rights can be found in the rights(4) manual page.

       In  some	 cases,	 Capsicum  requires use	of alternatives	to traditional
       POSIX APIs in order to name  objects  using  capabilities  rather  than
       global namespaces:

       process descriptors
	       File   descriptors   representing  processes,  allowing	parent
	       processes to manage child processes without requiring access to
	       the PID namespace; described in greater detail in procdesc(4).

       anonymous shared	memory
	       An extension to the POSIX shared	memory API to  support	anony-
	       mous  swap  objects associated with file	descriptors; described
	       in greater detail in shm_open(2).

       In some cases, Capsicum limits the valid	values of some	parameters  to
       traditional APIs	in order to restrict access to global namespaces:

       process IDs
	       Processes  can only act upon their own process ID with syscalls
	       such as cpuset_setaffinity(2).





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

Generic Microkernals Kernels *BECOME* Macrokernels
================

And then you can extend the generic microkernels into a set of macros, thus a macrokernel, and then add a functional bi-layer to this and you have immediate access to the power-duos of:

- Hardware + Software: Updateable Firmware
- Machine Learning and Statistics: Artificial Intelligence
- Object Oriented Programming and Algebra: Games
- Calculus and Statistical Lithography: Movies
- Operating Systems and Software: Everything else you could ever desire (BUTTS GALORE!!)

<img width="2048" height="1779" alt="HGjRiV-WAAAV0ZP" src="https://github.com/user-attachments/assets/e3a5434e-4ed3-43dd-9394-bac3f083d163" />




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



<img width="628" height="354" alt="Screenshot 2026-04-23 at 02 51 32" src="https://github.com/user-attachments/assets/e07c273b-6617-42e6-9f26-95c87850583a" />




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



<img width="919" height="659" alt="Screenshot 2026-04-22 at 13 23 35" src="https://github.com/user-attachments/assets/40e64889-068f-4758-b9b0-fab4fe71f0ea" />





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




<img width="1348" height="1790" alt="Screenshot 2026-04-22 at 13 22 52" src="https://github.com/user-attachments/assets/bda71e47-f1c0-42d2-a99f-bdca68061370" />



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



HOW TO CHECK THAT XNU IS NOT UNIX:
CAN IT DO ALL THIS SHIT???? THEN IT IS POSIX COMPLIANT
THUS XNU IS NOT UNIX IS ALSO UNIX BUT NOT UNIX BECAUSE THE NAME IS XNU IS NOT UNIX

Columns:
; Command: The text one enters to launch the command.
; Category: Functional categorization.
; Optionality: Indicates whether the command is mandatory or optional in order to achieve conformance. If the latter, then a code indicates the optional functionality group to which the command belongs.
:; Batch environment (BE): [[Batch processing |Batch job control]]. 
:; C‑language development (CD): For developing [[software]] in [[C (programming language) |C]].
:; FORTRAN development (FD): For developing software in [[FORTRAN]].
:; FORTRAN runtime (FR): Runtime‑support for FORTRAN.
:; Software development (SD): For developing software; not [[programming language |language]] specific.
:; User portability (UP): Addresses consistency at the [[user interface]] level.
:; X/Open System Interfaces (XSI): Historically UNIX-like features that were common on [[System V]]–style systems.
; Description: Describes what the command does.
; First appeared: Identifies an operating system version in which the command was first provided.

{{Sticky header}}
{{Table alignment}}
{|class="wikitable sortable sticky-header col3center"
|-
!scope="col" | Command
!scope="col" | Category
!scope="col" | Optionality
!scope="col" | Description
!scope="col" | First appeared
|-
!scope="row"| <span style="font-family: monospace">admin</span>
| SCCS
| {{Optional}} (XSI)
| Create and administer [[Source Code Control System|SCCS]] files
| PWB UNIX
|-
!scope="row"| [[alias (command)|<span style="font-family: monospace">alias</span>]]
| Misc
| {{needs|Mandatory}}
| Manage command aliases
| 
|-
!scope="row"| [[ar (Unix)|<span style="font-family: monospace">ar</span>]]
| Misc
| {{needs|Mandatory}}
| Manage [[Library (computing)|library]] archives
| Version 1 AT&T UNIX
|-
!scope="row"| <span style="font-family: monospace">asa</span>
| Text processing
| {{Optional}} (FR)
| Interpret [[ASA carriage control characters|carriage-control]] characters
| System V
|-
!scope="row"| [[at (command)|<span style="font-family: monospace">at</span>]]
| Process management
| {{needs|Mandatory}}
| Execute commands at a later time
| Version 7 AT&T UNIX
|-
!scope="row"| [[AWK|<span style="font-family: monospace">awk</span>]]
| Text processing
| {{needs|Mandatory}}
| Pattern scanning and processing language
| Version 7 AT&T UNIX
|-
!scope="row"| [[basename|<span style="font-family: monospace">basename</span>]]
| Filesystem
| {{needs|Mandatory}}
| Report non-directory portion of a pathname
| Version 7 AT&T UNIX
|-
!scope="row"| [[batch (Unix)|<span style="font-family: monospace">batch</span>]]
| Process management
| {{needs|Mandatory}}
| Schedule commands to be executed in a batch queue
| 
|-
!scope="row"| [[bc (programming language)|<span style="font-family: monospace">bc</span>]]
| Misc
| {{needs|Mandatory}}
| [[Arbitrary-precision arithmetic]] calculator
| Version 6 AT&T UNIX
|-
!scope="row"| [[bg (Unix)|<span style="font-family: monospace">bg</span>]]
| Process management
| {{Optional}} (UP)
| Move jobs to the background
| 
|-
!scope="row"| [[C compiler|<span style="font-family: monospace">cc</span>]]
| C programming
| {{Optional}} (CD)
| [[compiler|Compile]] [[C (programming language)|C]] [[source code]]
| IEEE Std 1003.1-2024
|-
!scope="row"| [[cal (command)|<span style="font-family: monospace">cal</span>]]
| Misc
| {{Optional}} (XSI)
| Print a calendar
| Version 5 AT&T UNIX
|-
!scope="row"| [[cat (Unix)|<span style="font-family: monospace">cat</span>]]
| Filesystem
| {{needs|Mandatory}}
| Concatenate and print files
| PDP-7 UNIX
|-
!scope="row"| [[cd (command)|<span style="font-family: monospace">cd</span>]]
| Filesystem
| {{needs|Mandatory}}
| Change the working directory
| Version 6 AT&T UNIX
|-
!scope="row"| [[cflow|<span style="font-family: monospace">cflow</span>]]
| C programming
| {{Optional}} (XSI)
| Generate a C-language [[call graph]]
| System V
|-
!scope="row"| [[chgrp|<span style="font-family: monospace">chgrp</span>]]
| Filesystem
| {{needs|Mandatory}}
| Change file group ownership
| PWB UNIX
|-
!scope="row"| [[chmod|<span style="font-family: monospace">chmod</span>]]
| Filesystem
| {{needs|Mandatory}}
| Change file modes/attributes/permissions
| PDP-7 UNIX
|-
!scope="row"| [[chown|<span style="font-family: monospace">chown</span>]]
| Filesystem
| {{needs|Mandatory}}
| Change file ownership
| PDP-7 UNIX
|-
!scope="row"| [[cksum|<span style="font-family: monospace">cksum</span>]]
| Filesystem
| {{needs|Mandatory}}
| Report file [[checksum]] and size
| 4.4BSD
|-
!scope="row"| [[cmp (Unix)|<span style="font-family: monospace">cmp</span>]]
| Filesystem
| {{needs|Mandatory}}
| Compare two files
| Version 1 AT&T UNIX
|-
!scope="row"| [[comm|<span style="font-family: monospace">comm</span>]]
| Text processing
| {{needs|Mandatory}}
| Select or reject lines common to two files
| Version 4 AT&T UNIX
|-
!scope="row"| [[command (Unix)|<span style="font-family: monospace">command</span>]]
| Shell programming
| {{needs|Mandatory}}
| Execute a simple command
| 
|-
!scope="row"| [[compress|<span style="font-family: monospace">compress</span>]]
| Filesystem
| {{Optional}} (XSI)
| Compress data
| 4.3BSD
|-
!scope="row"| [[cp (Unix)|<span style="font-family: monospace">cp</span>]]
| Filesystem
| {{needs|Mandatory}}
| Copy files
| PDP-7 UNIX
|-
!scope="row"| [[cron|<span style="font-family: monospace">cron</span>]]
| Misc
| {{needs|Mandatory}}
| Schedule periodic background work
| System V
|-
!scope="row"| [[csplit|<span style="font-family: monospace">csplit</span>]]
| Text processing
| {{needs|Mandatory}}
| Split files based on context
| PWB UNIX
|-
!scope="row"| [[ctags|<span style="font-family: monospace">ctags</span>]]
| C programming
| {{Optional}} (SD)
| Create a tags file
| 3BSD
|-
!scope="row"| [[cut (Unix)|<span style="font-family: monospace">cut</span>]]
| Text processing
| {{needs|Mandatory}}
| Cut out selected fields of each line of a file
| System III
|-
!scope="row"| <span style="font-family: monospace">cxref</span>
| C programming
| {{Optional}} (XSI)
| Generate a [[C (programming language)|C-language]] program cross-reference table
| System V
|-
!scope="row"| [[Date (Unix command)|<span style="font-family: monospace">date</span>]]
| Misc
| {{needs|Mandatory}}
| Report or change system date and time
| Version 1 AT&T UNIX
|-
!scope="row"| [[dd (Unix)|<span style="font-family: monospace">dd</span>]]
| Filesystem
| {{needs|Mandatory}}
| Convert and copy files
| Version 5 AT&T UNIX
|-
!scope="row"| <span style="font-family: monospace">delta</span>
| SCCS
| {{Optional}} (XSI)
| Make a delta (change) to an SCCS file
| PWB UNIX
|-
!scope="row"| [[df (Unix)|<span style="font-family: monospace">df</span>]]
| Filesystem
| {{needs|Mandatory}}
| Report free storage space
| Version 1 AT&T UNIX
|-
!scope="row"| [[diff|<span style="font-family: monospace">diff</span>]]
| Text processing
| {{needs|Mandatory}}
| Compare two files
| Version 5 AT&T UNIX
|-
!scope="row"| [[dirname|<span style="font-family: monospace">dirname</span>]]
| Filesystem
| {{needs|Mandatory}}
| Report the directory portion of a pathname
| System III
|-
!scope="row"| [[du (Unix)|<span style="font-family: monospace">du</span>]]
| Filesystem
| {{needs|Mandatory}}
| Estimate file space usage
| Version 1 AT&T UNIX
|-
!scope="row"| [[echo (command)|<span style="font-family: monospace">echo</span>]]
| Shell programming
| {{needs|Mandatory}}
| Write to standard output
| Version 2 AT&T UNIX
|-
!scope="row"| [[ed (text editor)|<span style="font-family: monospace">ed</span>]]
| Text processing
| {{needs|Mandatory}}
| The standard text editor
| PDP-7 UNIX
|-
!scope="row"| [[env (shell)|<span style="font-family: monospace">env</span>]]
| Misc
| {{needs|Mandatory}}
| Set the environment for command invocation
| System III
|-
!scope="row"| [[ex (text editor)|<span style="font-family: monospace">ex</span>]]
| Text processing
| {{Optional}} (UP)
| Text editor
| 1BSD
|-
!scope="row"| [[expand (Unix)|<span style="font-family: monospace">expand</span>]]
| Text processing
| {{needs|Mandatory}}
| Convert tabs to spaces
| 3BSD
|-
!scope="row"| [[expr|<span style="font-family: monospace">expr</span>]]
| Shell programming
| {{needs|Mandatory}}
| Evaluate arguments as an expression
| Version 7 AT&T UNIX
|-
!scope="row"| [[false (Unix)|<span style="font-family: monospace">false</span>]]
| Shell programming
| {{needs|Mandatory}}
| Exit immediately with [[exit status |status]] 1
| Version 7 AT&T UNIX
|-
!scope="row"| [[fc (Unix)|<span style="font-family: monospace">fc</span>]]
| Misc
| {{Optional}} (UP)
| Process the command history list
| 
|-
!scope="row"| [[fg (Unix)|<span style="font-family: monospace">fg</span>]]
| Process management
| {{Optional}} (UP)
| Move a job to the foreground
| 
|-
!scope="row"| [[file (command)|<span style="font-family: monospace">file</span>]]
| Filesystem
| {{needs|Mandatory}}
| Report type of files
| Version 4 AT&T UNIX
|-
!scope="row"| [[find (Unix)|<span style="font-family: monospace">find</span>]]
| Filesystem
| {{needs|Mandatory}}
| Find files
| Version 1 AT&T UNIX
|-
!scope="row"| [[fold (Unix)|<span style="font-family: monospace">fold</span>]]
| Text processing
| {{needs|Mandatory}}
| Filter for folding lines
| 1BSD
|-
!scope="row"| [[fuser (Unix)|<span style="font-family: monospace">fuser</span>]]
| Process management
| {{Optional}} (XSI)
| List [[Process identifier|process IDs]] of all processes that have one or more files open
| System V
|-
!scope="row"| <span style="font-family: monospace">gencat</span>
| Misc
| {{needs|Mandatory}}
| Generate a formatted message catalog
| 
|-
!scope="row"| <span style="font-family: monospace">get</span>
| SCCS
| {{Optional}} (XSI)
| Get a version of an SCCS file
| PWB UNIX
|-
!scope="row"| <span style="font-family: monospace">getconf</span>
| Misc
| {{needs|Mandatory}}
| Get configuration values
| 
|-
!scope="row"| [[getopts|<span style="font-family: monospace">getopts</span>]]
| Shell programming
| {{needs|Mandatory}}
| Parse utility options
| 
|-
!scope="row"| [[gettext|<span style="font-family: monospace">gettext</span>]]
| Misc
| {{needs|Mandatory}}
| Retrieve text string from messages object
| 
|-
!scope="row"| [[grep|<span style="font-family: monospace">grep</span>]]
| Misc
| {{needs|Mandatory}}
| Search text for a pattern
| Version 4 AT&T UNIX
|-
!scope="row"| [[hash (Unix)|<span style="font-family: monospace">hash</span>]]
| Misc
| {{needs|Mandatory}}
| Hash database access method
| 
|-
!scope="row"| [[head (Unix)|<span style="font-family: monospace">head</span>]]
| Text processing
| {{needs|Mandatory}}
| Copy the first part of files
| PWB UNIX{{citation needed|date=May 2009}}
|-
!scope="row"| [[iconv|<span style="font-family: monospace">iconv</span>]]
| Text processing
| {{needs|Mandatory}}
| Codeset conversion
| HP-UX
|-
!scope="row"| [[id (Unix)|<span style="font-family: monospace">id</span>]]
| Misc
| {{needs|Mandatory}}
| Report user identity
| System V
|-
!scope="row"| [[ipcrm|<span style="font-family: monospace">ipcrm</span>]]
| Misc
| {{Optional}} (XSI)
| Remove a message queue, semaphore set, or shared memory segment identifier
| System V
|-
!scope="row"| [[ipcs|<span style="font-family: monospace">ipcs</span>]]
| Misc
| {{Optional}} (XSI)
| Report interprocess communication facilities status
| System V
|-
!scope="row"| <span style="font-family: monospace">jobs</span>
| Process management
| {{Optional}} (UP)
| Report background jobs
| 
|-
!scope="row"| [[join (Unix)|<span style="font-family: monospace">join</span>]]
| Text processing
| {{needs|Mandatory}}
| Merges two sorted text files based on the presence of a common field
| Version 7 AT&T UNIX
|-
!scope="row"| [[kill (command)|<span style="font-family: monospace">kill</span>]]
| Process management
| {{needs|Mandatory}}
| Terminate or signal processes
| Version 4 AT&T UNIX
|-
!scope="row"| [[lex programming tool|<span style="font-family: monospace">lex</span>]]
| C programming
| {{Optional}} (CD)
| Generate programs for [[Lexical analyzer|lexical tasks]]
| Version 7 AT&T UNIX
|-
!scope="row"| [[link (Unix)|<span style="font-family: monospace">link</span>]]
| Filesystem
| {{Optional}} (XSI)
| Create a hard link to a file
| Version 1 AT&T UNIX
|-
!scope="row"| [[ln (Unix)|<span style="font-family: monospace">ln</span>]]
| Filesystem
| {{needs|Mandatory}}
| Link files
| Version 1 AT&T UNIX
|-
!scope="row"| <span style="font-family: monospace">locale</span>
| Misc
| {{needs|Mandatory}}
| Get locale-specific information
| 
|-
!scope="row"| [[localedef|<span style="font-family: monospace">localedef</span>]]
| Misc
| {{needs|Mandatory}}
| Define locale environment
| 
|-
!scope="row"| <span style="font-family: monospace">logger</span>
| Shell programming
| {{needs|Mandatory}}
| Log messages
| 4.3BSD
|-
!scope="row"| [[logname|<span style="font-family: monospace">logname</span>]]
| Misc
| {{needs|Mandatory}}
| Report the user's login name
| 4.4BSD
|-
!scope="row"| [[lp (Unix)|<span style="font-family: monospace">lp</span>]]
| Text processing
| {{needs|Mandatory}}
| Send files to a printer
| System V
|-
!scope="row"| [[ls|<span style="font-family: monospace">ls</span>]]
| Filesystem
| {{needs|Mandatory}}
| List directory contents
| Version 1 AT&T UNIX
|-
!scope="row"| [[M4 (computer language)|<span style="font-family: monospace">m4</span>]]
| Misc
| {{needs|Mandatory}}
| Macro processor
| PWB UNIX
|-
!scope="row"| [[mailx|<span style="font-family: monospace">mailx</span>]]
| Misc
| {{needs|Mandatory}}
| Process messages
| Version 1 AT&T UNIX
|-
!scope="row"| [[make (software)|<span style="font-family: monospace">make</span>]]
| Programming
| {{Optional}} (SD)
| Maintain, update, and regenerate groups of programs
| PWB UNIX
|-
!scope="row"| [[man page|<span style="font-family: monospace">man</span>]]
| Misc
| {{needs|Mandatory}}
| Display system documentation
| Version 2 AT&T UNIX
|-
!scope="row"| [[mesg|<span style="font-family: monospace">mesg</span>]]
| Misc
| {{needs|Mandatory}}
| Permit or deny messages
| Version 1 AT&T UNIX
|-
!scope="row"| [[mkdir|<span style="font-family: monospace">mkdir</span>]]
| Filesystem
| {{needs|Mandatory}}
| Make directories
| Version 1 AT&T UNIX
|-
!scope="row"| [[mkfifo|<span style="font-family: monospace">mkfifo</span>]]
| Filesystem
| {{needs|Mandatory}}
| Make [[FIFO (computing and electronics)|FIFO]] special files
| 4.4BSD{{dubious|mkfifo|date=April 2014}}
|-
!scope="row"| [[more (command)|<span style="font-family: monospace">more</span>]]
| Text processing
| {{Optional}} (UP)
| Display files on a page-by-page basis
| 3BSD
|-
!scope="row"| [[msgfmt|<span style="font-family: monospace">msgfmt</span>]]
| Misc
| {{needs|Mandatory}}
| Create messages objects from messages object files
|
|-
!scope="row"| [[Mv (Unix)|<span style="font-family: monospace">mv</span>]]
| Filesystem
| {{needs|Mandatory}}
| Move or rename files
| Version 1 AT&T UNIX
|-
!scope="row"| [[newgrp|<span style="font-family: monospace">newgrp</span>]]
| Misc
| {{needs|Mandatory}}
| Change to a new group
| Version 6 AT&T UNIX
|-
!scope="row"| [[gettext|<span style="font-family: monospace">ngettext</span>]]
| Misc
| {{needs|Mandatory}}
| Retrieve text string from messages object with plural form
| 
|-
!scope="row"| [[nice (Unix)|<span style="font-family: monospace">nice</span>]]
| Process management
| {{needs|Mandatory}}
| Invoke a utility with an altered nice value
| Version 4 AT&T UNIX
|-
!scope="row"| [[nl (Unix)|<span style="font-family: monospace">nl</span>]]
| Text processing
| {{Optional}} (XSI)
| Line numbering filter
| System III
|-
!scope="row"| [[nm (Unix)|<span style="font-family: monospace">nm</span>]]
| C programming
| {{Optional}}<br/>(SD, XSI)
| Write the name list of an [[object file]]
| Version 1 AT&T UNIX
|-
!scope="row"| [[nohup|<span style="font-family: monospace">nohup</span>]]
| Process management
| {{needs|Mandatory}}
| Invoke a utility immune to [[SIGHUP|hangups]]
| Version 4 AT&T UNIX
|-
!scope="row"| [[od (Unix)|<span style="font-family: monospace">od</span>]]
| Misc
| {{needs|Mandatory}}
| Dump files in various formats
| Version 1 AT&T UNIX
|-
!scope="row"| [[paste (Unix)|<span style="font-family: monospace">paste</span>]]
| Text processing
| {{needs|Mandatory}}
| Merge corresponding or subsequent lines of files
| Version 32V AT&T UNIX
|-
!scope="row"| [[patch (Unix)|<span style="font-family: monospace">patch</span>]]
| Text processing
| {{needs|Mandatory}}
| Apply changes to files
| 4.3BSD
|-
!scope="row"| [[pathchk|<span style="font-family: monospace">pathchk</span>]]
| Filesystem
| {{needs|Mandatory}}
| Check pathnames
| 
|-
!scope="row"| [[pax (command)|<span style="font-family: monospace">pax</span>]]
| Misc
| {{needs|Mandatory}}
| Portable archive interchange
| 4.4BSD{{citation needed|date=December 2014}}
|-
!scope="row"| [[pr (Unix)|<span style="font-family: monospace">pr</span>]]
| Text processing
| {{needs|Mandatory}}
| Paginate or columnate files for printing
| Version 1 AT&T UNIX
|-
!scope="row"| [[printf (Unix)|<span style="font-family: monospace">printf</span>]]
| Shell programming
| {{needs|Mandatory}}
| Write formatted output
| 4.3BSD-Reno
|-
!scope="row"| <span style="font-family: monospace">prs</span>
| SCCS
| {{Optional}} (XSI)
| Print an SCCS file
| PWB UNIX
|-
!scope="row"| [[ps (Unix)|<span style="font-family: monospace">ps</span>]]
| Process management
| {{needs|Mandatory}}
| Report process status
| Version 4 AT&T UNIX
|-
!scope="row"| [[pwd|<span style="font-family: monospace">pwd</span>]]
| Filesystem
| {{needs|Mandatory}}
| Print working directory
| Version 5 AT&T UNIX
|-
!scope="row"| [[read (Unix)|<span style="font-family: monospace">read</span>]]
| Shell programming
| {{needs|Mandatory}}
| Read a line from standard input
| 
|-
!scope="row"| <span style="font-family: monospace">readlink</span>
| Filesystem
| {{needs|Mandatory}}
| Print destination of a symbolic link
| 
|-
!scope="row"| <span style="font-family: monospace">realpath</span>
| Filesystem
| {{needs|Mandatory}}
| Report the [[Fully qualified name#Filenames and paths |fully qualified path]] of a file
| [[X/Open#X/Open Portability Guide|XPG4]]<ref name="realpath">{{Cite web|author=IEEE Computer Society|author-link=IEEE Computer Society|date=2008-12-01|title=POSIX.1-2008 System Interfaces: realpath()|website=The Open Group|url=https://pubs.opengroup.org/onlinepubs/9699919799.orig/functions/realpath.html|url-status=live|archive-url=https://web.archive.org/web/20240918051049if_/https://pubs.opengroup.org/onlinepubs/9699919799.orig/functions/realpath.html|archive-date=2024-09-18|series=Base Specifications (Issue 7)|doi=10.1109/IEEESTD.2008.4694976|isbn=978-0-7381-4048-3|access-date=2025-10-27|df=mdy-all|quote=First released in CAE Specification: System Interface Definitions (XBD), Issue 4, Version 2 (August 1994).}}</ref>
|-
!scope="row"| [[renice|<span style="font-family: monospace">renice</span>]]
| Process management
| {{needs|Mandatory}}
| Set nice values of running processes
| 4BSD
|-
!scope="row"| [[rm (Unix)|<span style="font-family: monospace">rm</span>]]
| Filesystem
| {{needs|Mandatory}}
| Remove file(s)
| Version 1 AT&T UNIX
|-
!scope="row"| [[rmdel|<span style="font-family: monospace">rmdel</span>]]
| SCCS
| {{Optional}} (XSI)
| Remove a delta from an SCCS file
| PWB UNIX
|-
!scope="row"| [[rmdir|<span style="font-family: monospace">rmdir</span>]]
| Filesystem
| {{needs|Mandatory}}
| Remove empty directory(ies)
| Version 1 AT&T UNIX
|-
!scope="row"| <span style="font-family: monospace">sact</span>
| SCCS
| {{Optional}} (XSI)
| Print current SCCS file-editing activity
| System III
|-
!scope="row"| [[Source Code Control System|<span style="font-family: monospace">sccs</span>]]
| SCCS
| {{Optional}} (XSI)
| Front end for the SCCS subsystem
| 4.3BSD
|-
!scope="row"| [[sed|<span style="font-family: monospace">sed</span>]]
| Text processing
| {{needs|Mandatory}}
| Stream editor
| Version 7 AT&T UNIX
|-
!scope="row"| [[Bourne shell|<span style="font-family: monospace">sh</span>]]
| Shell programming
| {{needs|Mandatory}}
| [[Unix shell|Shell]], the standard command language interpreter
| Version 7 AT&T UNIX<br/>(in earlier versions, sh was either the [[Thompson shell]] or the [[PWB shell]])
|-
!scope="row"| [[sleep (command)|<span style="font-family: monospace">sleep</span>]]
| Shell programming
| {{needs|Mandatory}}
| Suspend execution for an interval
| Version 4 AT&T UNIX
|-
!scope="row"| [[sort (Unix)|<span style="font-family: monospace">sort</span>]]
| Text processing
| {{needs|Mandatory}}
| Sort, merge, or sequence check text files
| Version 1 AT&T UNIX
|-
!scope="row"| [[split (Unix)|<span style="font-family: monospace">split</span>]]
| Misc
| {{needs|Mandatory}}
| Split files into pieces
| Version 3 AT&T UNIX
|-
!scope="row"| [[strings (Unix)|<span style="font-family: monospace">strings</span>]]
| C programming
| {{needs|Mandatory}}
| Find printable strings in files
| 2BSD
|-
!scope="row"| [[strip (Unix)|<span style="font-family: monospace">strip</span>]]
| C programming
| {{Optional}} (SD)
| Remove unnecessary information from executable files
| Version 1 AT&T UNIX
|-
!scope="row"| <span style="font-family: monospace">stty</span>
| Misc
| {{needs|Mandatory}}
| Set the options for a terminal
| Version 2 AT&T UNIX
|-
!scope="row"| <span style="font-family: monospace">tabs</span>
| Misc
| {{needs|Mandatory}}
| Set terminal tabs
| PWB UNIX
|-
!scope="row"| [[tail (Unix)|<span style="font-family: monospace">tail</span>]]
| Text processing
| {{needs|Mandatory}}
| Copy the last part of a file
| PWB UNIX{{citation needed|date=May 2009}}
|-
!scope="row"| [[talk (software)|<span style="font-family: monospace">talk</span>]]
| Misc
| {{Optional}} (UP)
| Talk to another user
| 4.2BSD
|-
!scope="row"| [[tee (command)|<span style="font-family: monospace">tee</span>]]
| Shell programming
| {{needs|Mandatory}}
| Duplicate the [[Standard streams|standard output]]
| Version 5 AT&T UNIX
|-
!scope="row"| [[test (Unix)|<span style="font-family: monospace">test</span>]]
| Shell programming
| {{needs|Mandatory}}
| Evaluate [[expression (computer science)|expression]]
| Version 7 AT&T UNIX
|-
!scope="row"| [[time (Unix)|<span style="font-family: monospace">time</span>]]
| Process management
| {{needs|Mandatory}}
| Display elapsed, system and kernel time used by the current shell or designated process. 
| Version 3 AT&T UNIX<ref>{{cite web |author=<!-- not stated --> |date=July 7, 2020 |title=FreeBSD Manual Pages: time |url=https://man.freebsd.org/cgi/man.cgi?query=time |website=man.freebsd.org|access-date=Mar 23, 2025}} </ref> 
|-
!scope="row"| <span style="font-family: monospace">timeout</span>
| Process management
| {{needs|Mandatory}}
| Run command with a time limit
| Version 3 AT&T UNIX
|-
!scope="row"| [[touch (command)|<span style="font-family: monospace">touch</span>]]
| Filesystem
| {{needs|Mandatory}}
| Change file access and modification times
| Version 7 AT&T UNIX
|-
!scope="row"| [[tput|<span style="font-family: monospace">tput</span>]]
| Misc
| {{needs|Mandatory}}
| Change [[Computer terminal|terminal]] characteristics
| System V
|-
!scope="row"| [[tr (Unix)|<span style="font-family: monospace">tr</span>]]
| Text processing
| {{needs|Mandatory}}
| Translate characters
| Version 4 AT&T UNIX
|-
!scope="row"| [[true (Unix)|<span style="font-family: monospace">true</span>]]
| Shell programming
| {{needs|Mandatory}}
| Exit immediately with [[exit status |status]] 0
| Version 7 AT&T UNIX
|-
!scope="row"| [[tsort (Unix)|<span style="font-family: monospace">tsort</span>]]
| Text processing
| {{needs|Mandatory}}
| Topological sort
| Version 7 AT&T UNIX
|-
!scope="row"| [[tty (unix)|<span style="font-family: monospace">tty</span>]]
| Misc
| {{needs|Mandatory}}
| Report user's [[Computer terminal|terminal]] name
| Version 1 AT&T UNIX
|-
!scope="row"| [[type (Unix)|<span style="font-family: monospace">type</span>]]
| Misc
| {{Optional}} (XSI)
| Displays how a name would be interpreted if used as a command
| 
|-
!scope="row"| <span style="font-family: monospace">ulimit</span>
| Misc
| {{Optional}} (XSI)
| Set or report file size limit
| 
|-
!scope="row"| [[umask|<span style="font-family: monospace">umask</span>]]
| Misc
| {{needs|Mandatory}}
| Get or set file mode creation mask
| System III
|-
!scope="row"| [[unalias|<span style="font-family: monospace">unalias</span>]]
| Misc
| {{needs|Mandatory}}
| Remove alias definitions
| 
|-
!scope="row"| [[uname|<span style="font-family: monospace">uname</span>]]
| Misc
| {{needs|Mandatory}}
| Report system name
| PWB UNIX
|-
!scope="row"| [[uncompress|<span style="font-family: monospace">uncompress</span>]]
| Misc
| {{Optional}} (XSI)
| Expand compressed data
| 4.3BSD
|-
!scope="row"| [[unexpand|<span style="font-family: monospace">unexpand</span>]]
| Text processing
| {{needs|Mandatory}}
| Convert spaces to tabs
| 3BSD
|-
!scope="row"| <span style="font-family: monospace">unget</span>
| SCCS
| {{Optional}} (XSI)
| Undo a previous get of an SCCS file
| System III
|-
!scope="row"| [[uniq|<span style="font-family: monospace">uniq</span>]]
| Text processing
| {{needs|Mandatory}}
| Report or filter out repeated lines in a file
| Version 3 AT&T UNIX
|-
!scope="row"| [[unlink (Unix)|<span style="font-family: monospace">unlink</span>]]
| Filesystem
| {{Optional}} (XSI)
| Call the unlink function
| Version 1 AT&T UNIX
|-
!scope="row"| [[uucp|<span style="font-family: monospace">uucp</span>]]
| Network
| {{Optional}} (UU)
| System-to-system copy
| Version 7 AT&T UNIX
|-
!scope="row"| [[uudecode|<span style="font-family: monospace">uudecode</span>]]
| Network
| {{needs|Mandatory}}
| Decode a binary file
| 4BSD
|-
!scope="row"| [[uuencode|<span style="font-family: monospace">uuencode</span>]]
| Network
| {{needs|Mandatory}}
| Encode a binary file
| 4BSD
|-
!scope="row"| [[uustat|<span style="font-family: monospace">uustat</span>]]
| Network
| {{Optional}} (UU)
| [[uucp]] status inquiry and job control
| System III
|-
!scope="row"| <span style="font-family: monospace">uux</span>
| Process management
| {{Optional}} (UU)
| Remote command execution
| Version 7 AT&T UNIX
|-
!scope="row"| <span style="font-family: monospace">val</span>
| SCCS
| {{Optional}} (XSI)
| Validate SCCS files
| System III
|-
!scope="row"| [[Vi (text editor)|<span style="font-family: monospace">vi</span>]]
| Text processing
| {{Optional}} (UP)
| Screen-oriented (visual) display editor
| 1BSD
|-
!scope="row"| [[wait (command)|<span style="font-family: monospace">wait</span>]]
| Process management
| {{needs|Mandatory}}
| Await process completion
| Version 4 AT&T UNIX
|-
!scope="row"| [[wc (Unix)|<span style="font-family: monospace">wc</span>]]
| Text processing
| {{needs|Mandatory}}
| Line, word and byte or character count
| Version 1 AT&T UNIX
|-
!scope="row"| <span style="font-family: monospace">what</span>
| SCCS
| {{Optional}} (XSI)
| Identify SCCS files
| PWB UNIX
|-
!scope="row"| [[who (Unix)|<span style="font-family: monospace">who</span>]]
| System administration
| {{Optional}} (XSI)
| Display who is on the system
| Version 1 AT&T UNIX
|-
!scope="row"| [[write (Unix)|<span style="font-family: monospace">write</span>]]
| Misc
| {{needs|Mandatory}}
| Write to another user's terminal
| Version 1 AT&T UNIX
|-
!scope="row"| [[xargs|<span style="font-family: monospace">xargs</span>]]
| Shell programming
| {{needs|Mandatory}}
| Construct argument lists and invoke utility
| PWB UNIX
|-
!scope="row"| [[gettext|<span style="font-family: monospace">xgettext</span>]]
| C programming
| {{Optional}} (CD)
| Extract gettext calls from C source code strings 
| IEEE Std 1003.1-2024
|-
!scope="row"| [[yacc|<span style="font-family: monospace">yacc</span>]]
| C programming
| {{Optional}} (CD)
| Yet another [[compiler]] compiler
| PWB UNIX
|-
!scope="row"| [[zcat|<span style="font-family: monospace">zcat</span>]]
| Text processing
| {{Optional}} (XSI)
| Expand and concatenate compressed data
| 4.3BSD
|-
|}



Making Open Standard Free Net Basic XNU Generic Containers for Kubernetes
===================================
-----------------------------------


# OCI Image Configuration

An OCI _Image_ is an ordered collection of root filesystem changes and the corresponding execution parameters for use within a container runtime.
This specification outlines the JSON format describing images for use with a container runtime and execution tool and its relationship to filesystem changesets, described in [Layers](layer.md).

This section defines the `application/vnd.oci.image.config.v1+json` [media type](media-types.md).

## Terminology

This specification uses the following terms:

### [Layer](layer.md)

- Image filesystems are composed of _layers_.
- Each layer represents a set of filesystem changes in a tar-based [layer format](layer.md), recording files to be added, changed, or deleted relative to its parent layer.
- Layers do not have configuration metadata such as environment variables or default arguments - these are properties of the image as a whole rather than any particular layer.
- Using a layer-based or union filesystem such as AUFS, or by computing the diff from filesystem snapshots, the filesystem changeset can be used to present a series of image layers as if they were one cohesive filesystem.

### Image JSON

- Each image has an associated JSON structure which describes some basic information about the image such as date created, author, as well as execution/runtime configuration like its entrypoint, default arguments, networking, and volumes.
- The JSON structure also references a cryptographic hash of each layer used by the image, and provides history information for those layers.
- This JSON is considered to be immutable, because changing it would change the computed [ImageID](#imageid).
- Changing it means creating a new derived image, instead of changing the existing image.

### Layer DiffID

A layer DiffID is the digest over the layer's uncompressed tar archive and serialized in the descriptor digest format, e.g., `sha256:a9561eb1b190625c9adb5a9513e72c4dedafc1cb2d4c5236c9a6957ec7dfd5a9`.
Layers SHOULD be packed and unpacked reproducibly to avoid changing the layer DiffID, for example by using [tar-split][] to save the tar headers.

NOTE: Do not confuse DiffIDs with [layer digests](manifest.md#image-manifest-property-descriptions), often referenced in the manifest, which are digests over compressed or uncompressed content.

### Layer ChainID

For convenience, it is sometimes useful to refer to a stack of layers with a single identifier.
While a layer's `DiffID` identifies a single changeset, the `ChainID` identifies the subsequent application of those changesets.
This ensures that we have handles referring to both the layer itself, as well as the result of the application of a series of changesets.
Use in combination with `rootfs.diff_ids` while applying layers to a root filesystem to uniquely and safely identify the result.

#### Definition

The `ChainID` of an applied set of layers is defined with the following recursion:

```text
ChainID(L₀) =  DiffID(L₀)
ChainID(L₀|...|Lₙ₋₁|Lₙ) = Digest(ChainID(L₀|...|Lₙ₋₁) + " " + DiffID(Lₙ))
```

For this, we define the binary `|` operation to be the result of applying the right operand to the left operand.
For example, given base layer `A` and a changeset `B`, we refer to the result of applying `B` to `A` as `A|B`.

Above, we define the `ChainID` for a single layer (`L₀`) as equivalent to the `DiffID` for that layer.
Otherwise, the `ChainID` for a set of applied layers (`L₀|...|Lₙ₋₁|Lₙ`) is defined as the recursion `Digest(ChainID(L₀|...|Lₙ₋₁) + " " + DiffID(Lₙ))`.

#### Explanation

Let's say we have layers A, B, C, ordered from bottom to top, where A is the base and C is the top.
Defining `|` as a binary application operator, the root filesystem may be `A|B|C`.
While it is implied that `C` is only useful when applied to `A|B`, the identifier `C` is insufficient to identify this result, as we'd have the equality `C = A|B|C`, which isn't true.

The main issue is when we have two definitions of `C`, `C = C` and `C = A|B|C`.
If this is true (with some handwaving), `C = x|C` where `x = any application`.
This means that if an attacker can define `x`, relying on `C` provides no guarantee that the layers were applied in any order.

The `ChainID` addresses this problem by being defined as a compound hash.
**We differentiate the changeset `C`, from the order-dependent application `A|B|C` by saying that the resulting rootfs is identified by ChainID(A|B|C), which can be calculated by `ImageConfig.rootfs`.**

Let's expand the definition of `ChainID(A|B|C)` to explore its internal structure:

```text
ChainID(A) = DiffID(A)
ChainID(A|B) = Digest(ChainID(A) + " " + DiffID(B))
ChainID(A|B|C) = Digest(ChainID(A|B) + " " + DiffID(C))
```

We can replace each definition and reduce to a single equality:

```text
ChainID(A|B|C) = Digest(Digest(DiffID(A) + " " + DiffID(B)) + " " + DiffID(C))
```

Hopefully, the above is illustrative of the _actual_ contents of the `ChainID`.
Most importantly, we can easily see that `ChainID(C) != ChainID(A|B|C)`, otherwise, `ChainID(C) = DiffID(C)`, which is the base case, could not be true.

### ImageID

Each image's ID is given by the SHA256 hash of its [configuration JSON](#image-json).
It is represented as a hexadecimal encoding of 256 bits, e.g., `sha256:a9561eb1b190625c9adb5a9513e72c4dedafc1cb2d4c5236c9a6957ec7dfd5a9`.
Since the [configuration JSON](#image-json) that gets hashed references hashes of each layer in the image, this formulation of the ImageID makes images content-addressable.

## Properties

Note: Any OPTIONAL field MAY also be set to null, which is equivalent to being absent.

- **created** _string_, OPTIONAL

  An combined date and time at which the image was created, formatted as defined by [RFC 3339, section 5.6][rfc3339-s5.6].

- **author** _string_, OPTIONAL

  Gives the name and/or email address of the person or entity which created and is responsible for maintaining the image.

- **architecture** _string_, REQUIRED

  The CPU architecture which the binaries in this image are built to run on.
  Configurations SHOULD use, and implementations SHOULD understand, values listed in the Go Language document for [`GOARCH`][go-environment].

- **os** _string_, REQUIRED

  The name of the operating system which the image is built to run on.
  Configurations SHOULD use, and implementations SHOULD understand, values listed in the Go Language document for [`GOOS`][go-environment].

- **os.version** _string_, OPTIONAL

  This OPTIONAL property specifies the version of the operating system targeted by the referenced blob.
  Implementations MAY refuse to use manifests where `os.version` is not known to work with the host OS version.
  Valid values are implementation-defined. e.g. `10.0.14393.1066` on `windows`.

- **os.features** _array of strings_, OPTIONAL

  This OPTIONAL property specifies an array of strings, each specifying a mandatory OS feature.
  When `os` is `windows`, image indexes SHOULD use, and implementations SHOULD understand the following values:

  - `win32k`: image requires `win32k.sys` on the host (Note: `win32k.sys` is missing on Nano Server)

- **variant** _string_, OPTIONAL

  The variant of the specified CPU architecture.
  Configurations SHOULD use, and implementations SHOULD understand, `variant` values listed in the [Platform Variants](image-index.md#platform-variants) table.

- **config** _object_, OPTIONAL

  The execution parameters which SHOULD be used as a base when running a container using the image.
  If the `config` object is omitted, any execution parameters should be specified at creation of the container.

  - **User** _string_, OPTIONAL

    The username or UID which is a platform-specific structure that allows specific control over which user the process run as.
    This acts as a default value to use when the value is not specified when creating a container.
    For Linux based systems, all of the following are valid: `user`, `uid`, `user:group`, `uid:gid`, `uid:group`, `user:gid`.
    If `group`/`gid` is not specified, the default group and supplementary groups of the given `user`/`uid` in `/etc/passwd` and `/etc/group` from the container are applied.
    If `group`/`gid` is specified, supplementary groups from the container are ignored.

  - **ExposedPorts** _object_, OPTIONAL

    A set of ports to expose from a container running this image.
    Its keys can be in the format of:
`port/tcp`, `port/udp`, `port` with the default protocol being `tcp` if not specified.
    These values act as defaults and are merged with any specified when creating a container.
    **NOTE:** This JSON structure value is unusual because it is a direct JSON serialization of the Go type `map[string]struct{}` and is represented in JSON as an object mapping its keys to an empty object.

  - **Env** _array of strings_, OPTIONAL

    Entries are in the format of `VARNAME=VARVALUE`.
    These values act as defaults and are merged with any specified when creating a container.

  - **Entrypoint** _array of strings_, OPTIONAL

    A list of arguments to use as the command to execute when the container starts.
    These values act as defaults and may be replaced by an entrypoint specified when creating a container.

  - **Cmd** _array of strings_, OPTIONAL

    Default arguments to the entrypoint of the container.
    These values act as defaults and may be replaced by any specified when creating a container.
    If an `Entrypoint` value is not specified, then the first entry of the `Cmd` array SHOULD be interpreted as the executable to run.

  - **Volumes** _object_, OPTIONAL

    A set of directories describing where the process is likely to write data specific to a container instance.
    **NOTE:** This JSON structure value is unusual because it is a direct JSON serialization of the Go type `map[string]struct{}` and is represented in JSON as an object mapping its keys to an empty object.

  - **WorkingDir** _string_, OPTIONAL

    Sets the current working directory of the entrypoint process in the container.
    This value acts as a default and may be replaced by a working directory specified when creating a container.

  - **Labels** _object_, OPTIONAL

    This field contains arbitrary metadata for the container.
    This property MUST use the [annotation rules](annotations.md#rules).

  - **StopSignal** _string_, OPTIONAL

    This field contains the system call signal that will be sent to the container to exit. The signal can be a signal name in the format `SIGNAME`, for instance `SIGKILL` or `SIGRTMIN+3`.

  - **ArgsEscaped** _boolean_, OPTIONAL

    `[Deprecated]` - This field is present only for legacy compatibility with Docker and should not be used by new image builders.
    It is used by Docker for Windows images to indicate that the `Entrypoint` or `Cmd` or both, contains only a single element array, that is a pre-escaped, and combined into a single string `CommandLine`.
    If `true` the value in `Entrypoint` or `Cmd` should be used as-is to avoid double escaping.
    Note, the exact behavior of `ArgsEscaped` is complex and subject to implementation details in Moby project.

  - **Memory** _integer_, OPTIONAL

    This property is _reserved_ for use, to [maintain compatibility](media-types.md#compatibility-matrix).

  - **MemorySwap** _integer_, OPTIONAL

    This property is _reserved_ for use, to [maintain compatibility](media-types.md#compatibility-matrix).

  - **CpuShares** _integer_, OPTIONAL

    This property is _reserved_ for use, to [maintain compatibility](media-types.md#compatibility-matrix).

  - **Healthcheck** _object_, OPTIONAL

    This property is _reserved_ for use, to [maintain compatibility](media-types.md#compatibility-matrix).

- **rootfs** _object_, REQUIRED

   The rootfs key references the layer content addresses used by the image.
   This makes the image config hash depend on the filesystem hash.

  - **type** _string_, REQUIRED

    MUST be set to `layers`.
    Implementations MUST generate an error if they encounter a unknown value while verifying or unpacking an image.

  - **diff_ids** _array of strings_, REQUIRED

    An array of layer content hashes (`DiffIDs`), in order from first to last.

- **history** _array of objects_, OPTIONAL

  Describes the history of each layer.
  The array is ordered from first to last.
  The object has the following fields:

  - **created** _string_, OPTIONAL

    A combined date and time at which the layer was created, formatted as defined by [RFC 3339, section 5.6][rfc3339-s5.6].

  - **author** _string_, OPTIONAL

    The author of the build point.

  - **created_by** _string_, OPTIONAL

    The command which created the layer.

  - **comment** _string_, OPTIONAL

    A custom message set when creating the layer.

  - **empty_layer** _boolean_, OPTIONAL

    This field is used to mark if the history item created a filesystem diff.
    It is set to true if this history item doesn't correspond to an actual layer in the rootfs section (for example, Dockerfile's [ENV](https://docs.docker.com/engine/reference/builder/#/env) command results in no change to the filesystem).

Any extra fields in the Image JSON struct are considered implementation specific and MUST NOT generate an error by any implementations which are unable to interpret them.

Whitespace is OPTIONAL and implementations MAY have compact JSON with no whitespace.

## Example

Here is an example image configuration JSON document:

```json,title=Image%20JSON&mediatype=application/vnd.oci.image.config.v1%2Bjson
{
    "created": "2015-10-31T22:22:56.015925234Z",
    "author": "Alyssa P. Hacker <alyspdev@example.com>",
    "architecture": "amd64",
    "os": "linux",
    "config": {
        "User": "alice",
        "ExposedPorts": {
            "8080/tcp": {}
        },
        "Env": [
            "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
            "FOO=oci_is_a",
            "BAR=well_written_spec"
        ],
        "Entrypoint": [
            "/bin/my-app-binary"
        ],
        "Cmd": [
            "--foreground",
            "--config",
            "/etc/my-app.d/default.cfg"
        ],
        "Volumes": {
            "/var/job-result-data": {},
            "/var/log/my-app-logs": {}
        },
        "WorkingDir": "/home/alice",
        "Labels": {
            "com.example.project.git.url": "https://example.com/project.git",
            "com.example.project.git.commit": "45a939b2999782a3f005621a8d0f29aa387e1d6b"
        }
    },
    "rootfs": {
      "diff_ids": [
        "sha256:c6f988f4874bb0add23a778f753c65efe992244e148a1d2ec2a8b664fb66bbd1",
        "sha256:5f70bf18a086007016e948b04aed3b82103a36bea41755b6cddfaf10ace3c6ef"
      ],
      "type": "layers"
    },
    "history": [
      {
        "created": "2015-10-31T22:22:54.690851953Z",
        "created_by": "/bin/sh -c #(nop) ADD file:a3bc1e842b69636f9df5256c49c5374fb4eef1e281fe3f282c65fb853ee171c5 in /"
      },
      {
        "created": "2015-10-31T22:22:55.613815829Z",
        "created_by": "/bin/sh -c #(nop) CMD [\"sh\"]",
        "empty_layer": true
      },
      {
        "created": "2015-10-31T22:22:56.329850019Z",
        "created_by": "/bin/sh -c apk add curl"
      }
    ]
}
```




===================================
-----------------------------------

generic XNU XNIJ microkernel # Suppress error reports for code in a file or in a function: src:bad_file.cpp # Ignore all functions with names containing SNU: fun:*XNU ERR* # Disable out-of-bound checks for global: global:bad_array # Disable out-of-bound checks for global instances of XNA POSIX REG

XNU IS NOT UNIX!!! DO A POSIX CHECK AND SEE FOR YOURSELF!

-----------------------------------
===================================

0
===================================
-----------------------------------

Need more help?
Battletoads got you Down????
===================================
```
Just Dial the Phone Losers of America!

<img width="950" height="935" alt="Screenshot 2026-04-21 at 15 47 08" src="https://github.com/user-attachments/assets/f5175613-9d37-459e-988e-a1349f02b3b9" />

PhfreakBeastBSD, L`OpenBSD, and their Sister, ANetBSD!

<img width="223" height="90" alt="Screenshot 2026-04-21 at 15 45 06" src="https://github.com/user-attachments/assets/596a3c34-6a66-46c4-aed5-3b6ac64a0570" />

The Phone Losers of America! They Have Big Stupid Phones!!!! The Phone LOOOOOssssserz of America!!!!! Install BSD Today!

<img width="110" height="48" alt="powered-by-NetBSD" src="https://github.com/user-attachments/assets/622698e3-5ee7-41b8-a72d-4b165473d0d6" />


