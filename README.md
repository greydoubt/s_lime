# s_lime


				Retrofitting JIT Compilers into C Interpreters 
				using the Formix Multi-User Agent XNA Kernel
				Free, Open, and Nyet for the Faint of Heart
				and boot that hot steaming pile of garbage
				as Operating System Kernels (BIOS -1.0113)
							
							by Sasna the Tree

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



## XNU Struct Definitions
========================
```
Struct			Header
------------------------

proc			bsd/sys/proc_internal.h
vnode			bsd/sys/vnode_internal.h
socket			bsd/sys/socketvar.h
ucred			bsd/sys/ucred.h
task			osfmk/kern/task.h
thread			osfmk/kern/thread.h
filedesc		bsd/sys/filedesc.h
fileproc		bsd/sys/file_internal.h
fileglob		bsd/sys/file_internal.h
mount			bsd/sys/mount_internal.h
```

------------------------

    Setup env
```
mkdir ~/.fonts
cp src/fonts/* ~/.fonts
fc-cache -f -v
sudo apt-get update
sudo apt install -y golang-go
go get golang.org/x/image/draw
sudo add-apt-repository universe
sudo add-apt-repository ppa:inkscape.dev/stable
sudo apt-get update
sudo apt install inkscape
sudo apt install -y texlive-full
```
    Build: make shit, release
```
./make.sh release
```


https://github.com/user-attachments/assets/d7e40268-9ab7-4fa9-83d8-46109bb06272


         ============#   how to install a real operating system    #============ 

Firstly, download a fucking file set from the internet or buy one for ten cents on the corner of van thrake the way god intended:


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

-------------------------------------





The Secret of NGG WR the Goose who Mocked the Pharaoh
-------------------------------------

Hardware and AI/ML Support for Virtual Machines?


They're the same thing, silly goofus!!!
-------------------------------------
-------------------------------------
All VMs target a single standard and then translate to or write for ARM and AMD64 dually 

The Broadcom BCM2837 is a system on chip (SoC) used in the Raspberry Pi 3, featuring a quad-core Cortex-A53 processor that operates at clock speeds between 1.2 GHz and 1.4 GHz depending on the model. It is an upgrade from the previous BCM2836, providing better performance and efficiency.

Some SoC models that do not work with the included U-Boot (such Raspberry Pi 400) can instead be booted using EDK2-based UEFI firmware. The simplest way to use this is to install the firmware on an SD card and install the OS on USB using XNU

Most ARM systems (Apple M-Series, Raspberry Pi 400 etc) need to have a UEFI environment installed before OpenBSD can be booted, usually Asahi Linux or some EDK2-based UEFI does the trick!



<img width="2275" height="1245" alt="Screenshot 2026-04-24 at 03 32 19" src="https://github.com/user-attachments/assets/cf3b6281-fae7-410a-92ce-444367b3623a" />






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
       Capsicum	 is a lightweight OS capability and sandbox framework implementing a hybrid capability system model. Capsicum is designed to blend capabilities with UNIX. This approach achieves many of the benefits of least-privilege operation, while preserving existing UNIX APIs and performance, and presents application authors with an adoptionpath for capability-oriented design

       Capabilities  are unforgeable tokens of authority that can be delegated
       and must	be presented to	perform	an action. Capsicum  makes  file  de-
       scriptors into capabilities.

       Capsicum	 can be	used for application and library compartmentalisation,
       the decomposition of larger bodies of  software	into  isolated	(sand-
       boxed) components in order to implement security	policies and limit the
       impact of software vulnerabilities.

       Capsicum	provides two core kernel primitives:

       *capability mode*
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

       *capabilities*
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
OpenBSD's boot-time kernel configuration, boot_config(8), allows an administrator to modify certain kernel settings, such as enabling or disabling support for various devices, without recompiling the kernel itself

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
Invoking config(8) with the -e flag allows you to enter the UKC on a running system

config — build kernel compilation directories or modify a kernel
SYNOPSIS
```
config 	[-p] [-b builddir] [-s srcdir] [config-file]

config 	-e [-u] [-c cmdfile] [-f | -o outfile] infile
```

For kernel building, refer to the following config options:
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

Any changes made will then take effect on the next reboot ↺






Change Kernel Options for Generic Formix-Compliant Configuration (Formix / OpenCitrix Zero Layer)
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
Its microcode should resemble this execution order:

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


Otherwise we can extend IOKit into a Blockchain using Elliptical Curve Cryptography, in which you remap as a stream a hex-based source (or flow) and convert it bit-to-byte (ergo a bit coin says goodbye to parts of the disc forming a ... bit coin) into octet, giving it 4-dimensions (id est post-quantum) using flat images to store fully 3d objects and their meshes over time (hence 4d animated indexically and rendered as a hash)


<img width="1227" height="561" alt="Screenshot 2026-04-24 at 07 20 40" src="https://github.com/user-attachments/assets/9c6a8303-f02a-4537-98b9-c848cc966baf" />


Most importantly, we can easily see that `ChainID(C) != ChainID(A|B|C)`, otherwise, `ChainID(C) = DiffID(C)`, which is the base case, could not be true.


<img width="958" height="380" alt="Screenshot 2026-04-24 at 07 23 49" src="https://github.com/user-attachments/assets/4dbbe824-4084-42c1-bba9-9799009a72e1" />


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

106: More Cryptography
===================================

<img width="728" height="464" alt="Screenshot 2026-04-24 at 23 03 13" src="https://github.com/user-attachments/assets/8987796e-f566-4c06-8dd8-c10d0237293f" />

AES-GCM is a mode that combines encryption with authentication in a streaming cipher so this too has post-quantum resilience baked into the algorithm which we can now observe. It ensures data confidentiality and verifies the data to reveal any inflight (quantum) tampering. GCM uses a block cipher with block size 128 bits (commonly AES-128) operated in counter mode for encryption, and uses arithmetic in the Galois field GF (2 128) to compute the authentication tag; hence the name

<img width="1168" height="562" alt="Screenshot 2026-04-24 at 23 01 55" src="https://github.com/user-attachments/assets/c95357cc-ebe7-46ba-8146-c453864df3f2" />


https://csrc.nist.gov/csrc/media/Events/2023/third-workshop-on-block-cipher-modes-of-operation/documents/accepted-papers/Practical%20Challenges%20with%20AES-GCM.pdf

AES-GCM Pain-Points AWS has been using AES-GCM in many encryption use-cases. AES-GCM has good performance, is highly optimized, FIPS-approved, and well-trusted. In spite of its proven value, GCM sucks for Key Management Systems so again, the Blockchain beats the NIST published standards. Consider the case where a customer managed key (CMK) is only accessible within a FIPS 140-2 Level 3 HSM. The CMK is used to both encrypt/decrypt small plaintext values and request encrypted data keys. GCM is a convenient mode for both operations. Constraints on the system, limit the number of CMKs any system can manage in or even export out of the HSM because that system requires another, larger system, aka someone else's shit





AES-GCM encryption computed using two plaintext blocks and one block of additional authenticated data 
-----------------------------------





<!DOCTYPE html>
<html
  lang="en"
  
  data-color-mode="auto" data-light-theme="light" data-dark-theme="dark"
  data-a11y-animated-images="system" data-a11y-link-underlines="true"
  data-css-features="prs_sticky_header_top_fix"
  >

    <style>
:root {
  --fontStack-monospace: "Monaspace Neon", ui-monospace, SFMono-Regular, SF Mono, Menlo, Consolas, Liberation Mono, monospace !important;
}
</style>




  <head>
    <meta charset="utf-8">
  <link rel="dns-prefetch" href="https://github.githubassets.com">
  <link rel="dns-prefetch" href="https://avatars.githubusercontent.com">
  <link rel="dns-prefetch" href="https://github-cloud.s3.amazonaws.com">
  <link rel="dns-prefetch" href="https://user-images.githubusercontent.com/">
  <link rel="preconnect" href="https://github.githubassets.com" crossorigin>
  <link rel="preconnect" href="https://avatars.githubusercontent.com">

  

  <link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/light-2ff56e1b36116ee2.css" /><link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/dark-2d1fe43dbc9adf1f.css" /><link data-color-theme="light_high_contrast" crossorigin="anonymous" media="all" rel="stylesheet" data-href="https://github.githubassets.com/assets/light_high_contrast-f7f95d7633592089.css" /><link data-color-theme="light_colorblind" crossorigin="anonymous" media="all" rel="stylesheet" data-href="https://github.githubassets.com/assets/light_colorblind-e4bbc49fc7b82570.css" /><link data-color-theme="light_colorblind_high_contrast" crossorigin="anonymous" media="all" rel="stylesheet" data-href="https://github.githubassets.com/assets/light_colorblind_high_contrast-cc3f126b45166b83.css" /><link data-color-theme="light_tritanopia" crossorigin="anonymous" media="all" rel="stylesheet" data-href="https://github.githubassets.com/assets/light_tritanopia-652ca611ea4e33fe.css" /><link data-color-theme="light_tritanopia_high_contrast" crossorigin="anonymous" media="all" rel="stylesheet" data-href="https://github.githubassets.com/assets/light_tritanopia_high_contrast-9e82d635cb6c3f49.css" /><link data-color-theme="dark_high_contrast" crossorigin="anonymous" media="all" rel="stylesheet" data-href="https://github.githubassets.com/assets/dark_high_contrast-d530ee188d165539.css" /><link data-color-theme="dark_colorblind" crossorigin="anonymous" media="all" rel="stylesheet" data-href="https://github.githubassets.com/assets/dark_colorblind-3ad0ec21150df75b.css" /><link data-color-theme="dark_colorblind_high_contrast" crossorigin="anonymous" media="all" rel="stylesheet" data-href="https://github.githubassets.com/assets/dark_colorblind_high_contrast-5691ff467f71a3f6.css" /><link data-color-theme="dark_tritanopia" crossorigin="anonymous" media="all" rel="stylesheet" data-href="https://github.githubassets.com/assets/dark_tritanopia-abee7710893cd168.css" /><link data-color-theme="dark_tritanopia_high_contrast" crossorigin="anonymous" media="all" rel="stylesheet" data-href="https://github.githubassets.com/assets/dark_tritanopia_high_contrast-eafcf6cd46158360.css" /><link data-color-theme="dark_dimmed" crossorigin="anonymous" media="all" rel="stylesheet" data-href="https://github.githubassets.com/assets/dark_dimmed-c7974682a1a84c8d.css" /><link data-color-theme="dark_dimmed_high_contrast" crossorigin="anonymous" media="all" rel="stylesheet" data-href="https://github.githubassets.com/assets/dark_dimmed_high_contrast-f8dab3e04f94c501.css" />

  <style type="text/css">
    :root {
      --tab-size-preference: 4;
    }

    pre, code {
      tab-size: var(--tab-size-preference);
    }
  </style>

    <link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/primer-primitives-7f694b60439d06c0.css" />
    <link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/primer-tailwind-compatible-25aee10cf9257254.css" />
    <link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/global-b40ec823a1a6a1af.css" />
    <link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/github-f825c0edd7ad57f8.css" />
    <link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/tailwind-8b1568e5f435b32a.css" />
  <link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/profile-64a7d97d5a8f2e37.css" />
<link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/insights-b8f59e0a23a6ce04.css" />

  

  <script type="application/json" id="client-env">{"locale":"en","featureFlags":["actions_custom_images_storage_billing_ui_visibility","actions_image_version_event","actions_workflow_language_service_allow_case_function","actions_workflow_language_service_allow_concurrency_queue","agent_conflict_resolution","alternate_user_config_repo","arianotify_comprehensive_migration","billing_discount_threshold_notification","billing_ui_budget_pagination_enabled","code_scanning_alert_tracking_links_phase_2","code_scanning_dfa_degraded_experience_notice","code_view_checks_live_updates","codemirror_inp_optimizations","codeowners_validation_in_diff","codespaces_prebuild_region_target_update","codespaces_tab_react","coding_agent_model_selection","coding_agent_model_selection_all_skus","coding_agent_third_party_model_ui","comment_viewer_copy_raw_markdown","contentful_primer_code_blocks","copilot_agent_snippy","copilot_api_agentic_issue_marshal_yaml","copilot_ask_mode_dropdown","copilot_automation_session_author","copilot_chat_attach_multiple_images","copilot_chat_category_rate_limit_messages","copilot_chat_clear_model_selection_for_default_change","copilot_chat_contextual_suggestions_updated","copilot_chat_disable_model_picker_while_streaming","copilot_chat_enable_tool_call_logs","copilot_chat_file_redirect","copilot_chat_input_commands","copilot_chat_opening_thread_switch","copilot_chat_prettify_pasted_code","copilot_chat_reduce_quota_checks","copilot_chat_search_bar_redirect","copilot_chat_selection_attachments","copilot_chat_vision_in_claude","copilot_chat_vision_preview_gate","copilot_custom_copilots","copilot_custom_copilots_feature_preview","copilot_diff_explain_conversation_intent","copilot_diff_reference_context","copilot_disable_cfi_sku_new_signups","copilot_duplicate_thread","copilot_extensions_hide_in_dotcom_chat","copilot_extensions_removal_on_marketplace","copilot_features_sql_server_logo","copilot_file_block_ref_matching","copilot_ftp_hyperspace_upgrade_prompt","copilot_icebreakers_experiment_dashboard","copilot_icebreakers_experiment_hyperspace","copilot_immersive_code_block_transition_wrap","copilot_immersive_embedded","copilot_immersive_embedded_deferred_payload","copilot_immersive_embedded_draggable","copilot_immersive_embedded_header_button","copilot_immersive_embedded_implicit_references","copilot_immersive_file_block_transition_open","copilot_immersive_file_preview_keep_mounted","copilot_immersive_job_result_preview","copilot_immersive_layout_routes","copilot_immersive_structured_model_picker","copilot_immersive_task_hyperlinking","copilot_immersive_task_within_chat_thread","copilot_issue_list_show_more","copilot_mc_cli_resume_any_users_task","copilot_mission_control_always_send_integration_id","copilot_mission_control_cli_session_status","copilot_mission_control_initial_data_spinner","copilot_mission_control_task_alive_updates","copilot_org_policy_page_focus_mode","copilot_premium_request_quotas","copilot_redirect_header_button_to_agents","copilot_resource_panel","copilot_scroll_preview_tabs","copilot_share_active_subthread","copilot_spaces_ga","copilot_spaces_individual_policies_ga","copilot_spaces_pagination","copilot_spark_empty_state","copilot_spark_handle_nil_friendly_name","copilot_swe_agent_hide_model_picker_if_only_auto","copilot_swe_agent_pr_comment_model_picker","copilot_swe_agent_use_subagents","copilot_task_api_github_rest_style","copilot_unconfigured_is_inherited","copilot_upgrade_freeze","copilot_usage_metrics_ga","copilot_workbench_slim_line_top_tabs","custom_instructions_file_references","dashboard_indexeddb_caching","dashboard_lists_max_age_filter","dashboard_universe_2025","dashboard_universe_2025_feedback_dialog","dead_click_detection","dotgithub_fork_warning","fgpat_permissions_selector_redesign","flex_cta_groups_mvp","global_nav_react","hide_groups_list_for_few_groups","hyperspace_2025_logged_out_batch_1","hyperspace_2025_logged_out_batch_2","hyperspace_2025_logged_out_batch_3","ipm_global_transactional_message_agents","ipm_global_transactional_message_copilot","ipm_global_transactional_message_issues","ipm_global_transactional_message_prs","ipm_global_transactional_message_repos","ipm_global_transactional_message_spaces","issue_cca_modal_open","issue_cca_multi_assign_modal","issue_cca_task_side_panel","issue_cca_visualization","issue_cca_visualization_session_panel","issue_fields_global_search","issues_expanded_file_types","issues_lazy_load_comment_box_suggestions","issues_react_bots_timeline_pagination","issues_react_cache_preheat_index","issues_react_chrome_container_query_fix","issues_react_include_bots_in_pickers","issues_react_timeline_side_panel","issues_react_ui_feedback","issues_search_type_gql","landing_pages_ninetailed","landing_pages_web_vitals_tracking","lifecycle_label_name_updates","low_quality_classifier","marketing_pages_search_explore_provider","memex_default_issue_create_repository","memex_live_update_hovercard","memex_mwl_filter_field_delimiter","memex_remove_deprecated_type_issue","memex_roadmap_drag_style","merge_status_header_feedback","notifications_menu_defer_labels","oauth_authorize_clickjacking_protection","octocaptcha_origin_optimization","pr_sfv_new_diff_fetch","prs_checks_react","prs_conversations_react","prs_css_anchor_positioning","prs_live_updates_issue_comments","prs_load_all_alerts","prs_review_summaries_in_side_panel","prx_files","pull_request_commit_checks_dialog","pull_request_files_accurate_size_estimates","pull_request_files_virtualization","pull_request_inbox_new_sections","pull_request_merge_status_button","pull_request_virtualization_preload_diffs","react_blob_overlay","repository_suggester_elastic_search","rules_insights_filter_bar_created","sample_network_conn_type","secret_scanning_pattern_alerts_link","session_logs_ungroup_reasoning_text","site_features_copilot_universe","site_homepage_collaborate_video","spark_prompt_secret_scanning","spark_server_connection_status","suppress_automated_browser_vitals","team_review_requested_by_user_filter","ui_skip_on_anchor_click","viewscreen_sandbox","warn_inaccessible_attachments","webp_support","workbench_store_readonly"],"login":"greydoubt","copilotApiOverrideUrl":"https://api.individual.githubcopilot.com"}</script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/wp-runtime-f2375f2858a8f670.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/fetch-utilities-3140609b5732710f.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/28839-7adfdde5afeb1a03.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/85924-ac5602ef611dc506.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/34646-4c7883eb242d5210.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/environment-a12df3cf35884818.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/runtime-helpers-cb4dfbc9d23f30be.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/2966-d68f2b4558d86113.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/96232-540ff5f81016a9ca.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/41013-647932573fc130af.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/51210-45dfb7dd106f6b96.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/64247-73a9861fe185671f.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/81683-382ccc88e034ea1d.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/9338-f6bee5a8d66d930f.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/46740-5a373320e5ef9c01.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/44156-0c3701a71b4871b0.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/github-elements-7e2efb5d06a50116.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/element-registry-71abc46054aa4443.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/react-core-dc129291382ca774.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/react-lib-1353f2cef82bcdc0.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/7053-abde2598303b4d18.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/58889-5b136bc717e57a8b.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/79039-69acf717ffc901a4.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/61110-073153e0413daf3a.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/2887-91b9c645d570616a.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/26533-f22c29ae5e9b1ed2.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/86483-c3a819d46503a3da.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/28153-07841e439e3d3315.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/60481-24b13ea726837f7b.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/46287-52fba49c502ea0a1.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/2498-f0375ed070e22e54.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/61025-ca31d4d2add162fd.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/89627-40275597692dc855.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/79087-4f706db8aa2ec0fb.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/49029-42bd0899fca05960.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/99328-a2c6b180d25cb160.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/behaviors-26bee9c830498018.js" defer="defer"></script>
<link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/react-core.b6c10f6e5f50efcc.module.css" />
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/4244-97fb660009234136.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/notifications-global-442a23b66c306470.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/74888-19847f17404a4164.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/53049-4fda7a6ba6b3e023.js" defer="defer"></script>
<script crossorigin="anonymous" type="module" src="https://github.githubassets.com/assets/profile-87bacb652510de0a.js" defer="defer"></script>
  

  <title>greydoubt ( λx . ophidia ereц grex⋆. 𐙚 ̊      .    أوفيديا إريكس جريكس   .)</title>



  <meta name="route-pattern" content="/:user_id(.:format)" data-turbo-transient>
  <meta name="route-controller" content="profiles" data-turbo-transient>
  <meta name="route-action" content="show" data-turbo-transient>
  <meta name="fetch-nonce" content="v2:a56da4c2-89c0-0365-3c67-1b3eff3b2149">

    
  <meta name="current-catalog-service-hash" content="4a1c50a83cf6cc4b55b6b9c53e553e3f847c876b87fb333f71f5d05db8f1a7db">


  <meta name="request-id" content="CDF0:253B38:64201F0:65BAC01:69EC60FD" data-turbo-transient="true" /><meta name="html-safe-nonce" content="f1cc331352aff92de8792a5e802f207c9949abc56778f5bf71085ceb52216531" data-turbo-transient="true" /><meta name="visitor-payload" content="eyJyZWZlcnJlciI6Imh0dHBzOi8vdC5jby8iLCJyZXF1ZXN0X2lkIjoiQ0RGMDoyNTNCMzg6NjQyMDFGMDo2NUJBQzAxOjY5RUM2MEZEIiwidmlzaXRvcl9pZCI6IjY2Nzk0Njk2NzM3ODEyOTI3OTAiLCJyZWdpb25fZWRnZSI6InNlYSIsInJlZ2lvbl9yZW5kZXIiOiJpYWQifQ==" data-turbo-transient="true" /><meta name="visitor-hmac" content="0a2e2d5f6c6e729b9584011498524173c1034630bc6238df84d2936cefaedae1" data-turbo-transient="true" />




  <meta name="github-keyboard-shortcuts" content="copilot" data-turbo-transient="true" />
  

  <meta name="selected-link" value="overview" data-turbo-transient>
  <link rel="assets" href="https://github.githubassets.com/">

    <meta name="google-site-verification" content="Apib7-x98H0j5cPqHWwSMm6dNU4GmODRoqxLiDzdx9I">

<meta name="octolytics-url" content="https://collector.github.com/github/collect" /><meta name="octolytics-actor-id" content="43443470" /><meta name="octolytics-actor-login" content="greydoubt" /><meta name="octolytics-actor-hash" content="8766cd7be0a9dba62943cba7ea9d0735c26e71ee9754a354e3c431433ae1f3c3" />





  <meta name="analytics-location" content="/&lt;user-name&gt;" data-turbo-transient="true" />

  




    <meta name="user-login" content="greydoubt">

  <link rel="sudo-modal" href="/sessions/sudo_modal">

    <meta name="viewport" content="width=device-width">

    

      <meta name="description" content="#エメラダ 🛸　.　　•.  　🌎　°　.•　🌓　•　　.°•　　•　🚀 ✯.    •.    .  •. 
　.　•　★　*　　　　　°　　.　　🛰 　°·　　•.      ๏        .•       🪐
.　•　•　° ★　•  ☄.       ๏       •.      .  • - greydoubt">

      <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub">

    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub">
    <meta property="fb:app_id" content="1401488693436528">
    <meta name="apple-itunes-app" content="app-id=1477376905, app-argument=https://github.com/greydoubt" />

      <meta name="twitter:image" content="https://avatars.githubusercontent.com/u/43443470?v=4?s=400" /><meta name="twitter:site" content="@github" /><meta name="twitter:card" content="summary" /><meta name="twitter:title" content="greydoubt - Overview" /><meta name="twitter:description" content="#エメラダ 🛸　.　　•.  　🌎　°　.•　🌓　•　　.°•　　•　🚀 ✯.    •.    .  •. 
　.　•　★　*　　　　　°　　.　　🛰 　°·　　•.      ๏        .•       🪐
.　•　•　° ★　•  ☄.       ๏       •.      .  • - greydoubt" />
  <meta property="og:image" content="https://avatars.githubusercontent.com/u/43443470?v=4?s=400" /><meta property="og:image:alt" content="#エメラダ 🛸　.　　•.  　🌎　°　.•　🌓　•　　.°•　　•　🚀 ✯.    •.    .  •. 
　.　•　★　*　　　　　°　　.　　🛰 　°·　　•.      ๏        .•       🪐
.　•　•　° ★　•  ☄.       ๏       •.      .  • - greydoubt" /><meta property="og:site_name" content="GitHub" /><meta property="og:type" content="profile" /><meta property="og:title" content="greydoubt - Overview" /><meta property="og:url" content="https://github.com/greydoubt" /><meta property="og:description" content="#エメラダ 🛸　.　　•.  　🌎　°　.•　🌓　•　　.°•　　•　🚀 ✯.    •.    .  •. 
　.　•　★　*　　　　　°　　.　　🛰 　°·　　•.      ๏        .•       🪐
.　•　•　° ★　•  ☄.       ๏       •.      .  • - greydoubt" /><meta property="profile:username" content="greydoubt" />
  


      <link rel="shared-web-socket" href="wss://alive.github.com/_sockets/u/43443470/ws?session=eyJ2IjoiVjMiLCJ1Ijo0MzQ0MzQ3MCwicyI6MjAxNTUyNzM4MSwiYyI6NzQ3OTM0MzM0LCJ0IjoxNzc3MDk5MDA1fQ==--c0482003bd5e4d808162ede39a8f4765e9182a898b862bb4dcbb8d33794ad83f" data-refresh-url="/_alive" data-session-id="4c24e02490c5aa538199e49873ce996e7355e612d378df86991bbd8e92c3c35a">
      <link rel="shared-web-socket-src" href="/assets-cdn/worker/socket-worker-4b32331dd8a8013e.js">

      <link rel="service-worker-src" href="/assets-cdn/worker/service-worker-08cbca96d67917b4.js?current_user=greydoubt&amp;errors_url=https%3A%2F%2Fapi.github.com%2F_private%2Fbrowser%2Ferrors&amp;release=db04a125e39757b8eb6685256d1ec903cd92c587&amp;actor_id=43443470&amp;is_staff=false&amp;analytics_collector_url=https%3A%2F%2Fcollector.github.com%2Fgithub%2Fcollect">

      <meta name="hostname" content="github.com">


      <meta name="keyboard-shortcuts-preference" content="all">
      <meta name="hovercards-preference" content="true">
      <meta name="announcement-preference-hovercard" content="true">

        <meta name="expected-hostname" content="github.com">


  <meta http-equiv="x-pjax-version" content="a62126897d0955070af0575283dc63cf5c00238f56af2b0b4bbed7e926fe4f9d" data-turbo-track="reload">
  <meta http-equiv="x-pjax-csp-version" content="568c098497d98702bac1642a2a853732a047a6ced28eabd3e15d50041a890235" data-turbo-track="reload">
  <meta http-equiv="x-pjax-css-version" content="87721d1504a187fb3fcbfa6e98526d058edf6fa1163680dbb36bf70525df6ac4" data-turbo-track="reload">
  <meta http-equiv="x-pjax-js-version" content="f99de4a97927476b960e57b3bca31667cb46b693e817d1f29e13b3cc8dcfb3d4" data-turbo-track="reload">

  <meta name="turbo-cache-control" content="no-preview" data-turbo-transient="">

    <meta name="octolytics-dimension-user_id" content="43443470" /><meta name="octolytics-dimension-user_login" content="greydoubt" />


      <link rel="canonical" href="https://github.com/greydoubt" data-turbo-transient>


    <meta name="turbo-body-classes" content="logged-in env-production page-responsive page-profile mine">
  <meta name="disable-turbo" content="false">


  <meta name="browser-stats-url" content="https://api.github.com/_private/browser/stats">

  <meta name="browser-errors-url" content="https://api.github.com/_private/browser/errors">

  <meta name="release" content="db04a125e39757b8eb6685256d1ec903cd92c587">
  <meta name="ui-target" content="full">

  <link rel="mask-icon" href="https://github.githubassets.com/assets/pinned-octocat-093da3e6fa40.svg" color="#000000">
  <link rel="alternate icon" class="js-site-favicon" type="image/png" href="https://github.githubassets.com/favicons/favicon.png">
  <link rel="icon" class="js-site-favicon" type="image/svg+xml" href="https://github.githubassets.com/favicons/favicon.svg" data-base-href="https://github.githubassets.com/favicons/favicon">

<meta name="theme-color" content="#1e2327">
<meta name="color-scheme" content="light dark" />


  <link rel="manifest" href="/manifest.json" crossOrigin="use-credentials">

  </head>

  <body class="logged-in env-production page-responsive page-profile mine" style="word-wrap: break-word;" >
    <div data-turbo-body class="logged-in env-production page-responsive page-profile mine" style="word-wrap: break-word;" >
      <div id="__primerPortalRoot__" role="region" style="z-index: 1000; position: absolute; width: 100%;" data-turbo-permanent></div>
      

    <div class="position-relative header-wrapper js-header-wrapper ">
      <a href="#start-of-content" data-skip-target-assigned="false" class="tmp-p-3 color-bg-accent-emphasis color-fg-on-emphasis show-on-focus js-skip-to-content">Skip to content</a>

      <span data-view-component="true" class="progress-pjax-loader Progress position-fixed width-full">
    <span style="width: 0%;" data-view-component="true" class="Progress-item progress-pjax-loader-bar left-0 top-0 color-bg-accent-emphasis"></span>
</span>      
      
      <link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/primer-react-css.1836171ca9039b48.module.css" />
<link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/keyboard-shortcuts-dialog.67978b685ca52cce.module.css" />

<react-partial
  partial-name="keyboard-shortcuts-dialog"
  data-ssr="false"
  data-attempted-ssr="false"
  data-react-profiling="false"
>
  
  <script type="application/json" data-target="react-partial.embeddedData">{"props":{"docsUrl":"https://docs.github.com/get-started/accessibility/keyboard-shortcuts"}}</script>
  <div data-target="react-partial.reactRoot"></div>
</react-partial>





      

          

                  <link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/primer-react-css.1836171ca9039b48.module.css" />
<link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/global-nav-bar.eb1c7e1375fb0b61.module.css" />

<react-partial
  partial-name="global-nav-bar"
  data-ssr="true"
  data-attempted-ssr="true"
  data-react-profiling="false"
>
  
  <script type="application/json" data-target="react-partial.embeddedData">{"props":{"contextRegion":{"crumbs":[{"crumb_type":"user","label":"greydoubt","is_root":false,"href":"/greydoubt"}],"localNavigation":[{"id":"overview","icon":"book","label":"Overview","href":"/greydoubt","selectedLinks":["overview"],"popoverTarget":false,"reactNav":{"appTarget":null,"anchor":null},"turboNav":{"frame":"user-profile-frame"}},{"id":"repositories","icon":"repo","label":"Repositories","href":"/greydoubt?tab=repositories","selectedLinks":["repositories"],"count":603,"popoverTarget":false,"reactNav":{"appTarget":null,"anchor":null},"turboNav":{"frame":"user-profile-frame"}},{"id":"projects","icon":"table","label":"Projects","href":"/greydoubt?tab=projects","selectedLinks":["projects"],"count":0,"popoverTarget":false,"reactNav":{"appTarget":null,"anchor":null},"turboNav":{"frame":"user-profile-frame"}},{"id":"packages","icon":"package","label":"Packages","href":"/greydoubt?tab=packages","selectedLinks":["packages"],"count":0,"popoverTarget":false,"reactNav":{"appTarget":null,"anchor":null},"turboNav":{"frame":"user-profile-frame"}},{"id":"stars","icon":"star","label":"Stars","href":"/greydoubt?tab=stars","selectedLinks":["stars","user_lists"],"count":527,"popoverTarget":false,"reactNav":{"appTarget":null,"anchor":null},"turboNav":{"frame":"user-profile-frame"}},{"id":"sponsoring","icon":"heart","label":"Sponsoring","href":"/greydoubt?tab=sponsoring","selectedLinks":["sponsoring"],"count":0,"popoverTarget":false,"reactNav":{"appTarget":null,"anchor":null},"turboNav":{"frame":"user-profile-frame"}}],"localNavigationUpdateChannel":null,"selectedLink":"overview"},"userMenu":{"owner":{"login":"greydoubt","name":" λx . ophidia ereц grex⋆. 𐙚 ̊      .    أوفيديا إريكس جريكس   .","avatarUrl":"https://avatars.githubusercontent.com/u/43443470?v=4"}},"headerLogo":{"href":"/","aria-label":"Homepage "},"notifications":{"indicatorMode":"none","websocketChannel":"eyJjIjoibm90aWZpY2F0aW9uLWNoYW5nZWQ6NDM0NDM0NzAiLCJ0IjoxNzc3MDk5MDA1fQ==--811af1c9761f36d7edde3c8dfde70084d931d6d3b63b9573f0c57a32c4308625","fetchIndicatorSrc":"/notifications/indicator","fetchIndicatorEnabled":true},"issues":{"href":"/issues"},"pulls":{"href":"/pulls"},"contributedRepos":{"show":true,"href":"/repos"},"copilot":{"show":false,"showAgentsButton":false,"copilotChatUrl":null,"copilotApiUrl":"https://api.individual.githubcopilot.com"},"search":{"show":true,"showCommandPalette":false,"isSearchPage":false,"isJumpToSearch":false,"searchContext":{"scope":"owner:greydoubt","user_id":"greydoubt"}},"enterpriseBanner":{"show":false},"globalTransactionalMessage":null,"payloadsUrl":"/_global-navigation/payloads.json?return_to=https%3A%2F%2Fgithub.com%2Fgreydoubt\u0026user_id=greydoubt"}}</script>
  <div data-target="react-partial.reactRoot"><link rel="preload" as="image" href="https://avatars.githubusercontent.com/u/43443470?v=4&amp;size=64"/><header role="banner" aria-label="Global Navigation Menu" class="GlobalNav styles-module__appHeader__YzYWk prc-Stack-Stack-UQ9k6" data-gap="none" data-direction="vertical" data-align="stretch" data-wrap="nowrap" data-justify="start" data-padding="none"><div class="prc-Stack-Stack-UQ9k6" data-direction="horizontal" data-align="center" data-wrap="nowrap" data-justify="center" data-padding="none"><div data-testid="top-nav-left" class="styles-module__left__Fylw7 styles-module__withLocalNavigation__rjTJ_ prc-Stack-Stack-UQ9k6" data-gap="condensed" data-direction="horizontal" data-align="stretch" data-wrap="nowrap" data-justify="start" data-padding="normal"><div data-loading-wrapper="true"><button data-component="IconButton" type="button" aria-haspopup="dialog" class="prc-Button-ButtonBase-9n-Xk styles-module__appHeaderButton__axedQ prc-Button-IconButton-fyge7" data-loading="false" data-no-visuals="true" data-size="medium" data-variant="invisible" aria-labelledby="_R_apb_"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-three-bars" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="M1 2.75A.75.75 0 0 1 1.75 2h12.5a.75.75 0 0 1 0 1.5H1.75A.75.75 0 0 1 1 2.75Zm0 5A.75.75 0 0 1 1.75 7h12.5a.75.75 0 0 1 0 1.5H1.75A.75.75 0 0 1 1 7.75ZM1.75 12h12.5a.75.75 0 0 1 0 1.5H1.75a.75.75 0 0 1 0-1.5Z"></path></svg></button></div><span class="prc-TooltipV2-Tooltip-tLeuB" data-direction="s" aria-hidden="true" id="_R_apb_">Open menu</span><a data-component="IconButton" type="button" class="prc-Button-ButtonBase-9n-Xk styles-module__appHeaderHome__nkA_U prc-Button-IconButton-fyge7" data-loading="false" data-no-visuals="true" data-size="medium" data-variant="invisible" aria-labelledby="_R_cpb_" href="/" data-discover="true"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-mark-github" viewBox="0 0 24 24" width="32" height="32" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="M10.226 17.284c-2.965-.36-5.054-2.493-5.054-5.256 0-1.123.404-2.336 1.078-3.144-.292-.741-.247-2.314.09-2.965.898-.112 2.111.36 2.83 1.01.853-.269 1.752-.404 2.853-.404 1.1 0 1.999.135 2.807.382.696-.629 1.932-1.1 2.83-.988.315.606.36 2.179.067 2.942.72.854 1.101 2 1.101 3.167 0 2.763-2.089 4.852-5.098 5.234.763.494 1.28 1.572 1.28 2.807v2.336c0 .674.561 1.056 1.235.786 4.066-1.55 7.255-5.615 7.255-10.646C23.5 6.188 18.334 1 11.978 1 5.62 1 .5 6.188.5 12.545c0 4.986 3.167 9.12 7.435 10.669.606.225 1.19-.18 1.19-.786V20.63a2.9 2.9 0 0 1-1.078.224c-1.483 0-2.359-.808-2.987-2.313-.247-.607-.517-.966-1.034-1.033-.27-.023-.359-.135-.359-.27 0-.27.45-.471.898-.471.652 0 1.213.404 1.797 1.235.45.651.921.943 1.483.943.561 0 .92-.202 1.437-.719.382-.381.674-.718.944-.943"></path></svg></a><span class="prc-TooltipV2-Tooltip-tLeuB" data-direction="s" aria-hidden="true"><span id="_R_cpb_">Homepage <span class="prc-src-InternalVisuallyHidden-2YaI6">(<!-- -->g then d<!-- -->)</span></span><span class="prc-TooltipV2-KeybindingHintContainer-Ymj-3 prc-TooltipV2-HasTextBefore-fdOXj" aria-hidden="true"><kbd class="prc-KeybindingHint-KeybindingHint-qpYIs prc-Text-Text-9mHv3" data-testid="keybinding-hint"><span class="prc-components-Chord-DdhWN prc-components-ChordOnEmphasis-O-4BS prc-components-ChordSmall-c-P-x prc-Text-Text-9mHv3" data-kbd-chord="true"> <span class="prc-src-InternalVisuallyHidden-2YaI6">g</span><span aria-hidden="true">G</span></span><span class="prc-src-InternalVisuallyHidden-2YaI6">then</span> <span class="prc-components-Chord-DdhWN prc-components-ChordOnEmphasis-O-4BS prc-components-ChordSmall-c-P-x prc-Text-Text-9mHv3" data-kbd-chord="true"> <span class="prc-src-InternalVisuallyHidden-2YaI6">d</span><span aria-hidden="true">D</span></span></kbd></span></span><div class="d-none"></div></div><div data-testid="top-nav-center" class="styles-module__center__R3QRv styles-module__withLocalNavigation__rjTJ_ prc-Stack-Stack-UQ9k6" data-gap="condensed" data-direction="horizontal" data-align="stretch" data-wrap="nowrap" data-justify="start" data-padding="normal"><nav class="styles-module__contextRegion__VbSp2 prc-Breadcrumbs-BreadcrumbsBase-3Gb-B" aria-label="Breadcrumbs" data-overflow="menu" data-variant="normal"><ol class="prc-Breadcrumbs-BreadcrumbsList-BKjpe"><li class="prc-Breadcrumbs-ItemWrapper-k0NLn"><a class="styles-module__contextCrumb__IzGIq prc-Breadcrumbs-Item-jcraJ" href="/greydoubt" data-discover="true"><span class="styles-module__contextCrumbLast__tI2e3">greydoubt</span></a></li></ol></nav><div class="Search-module__searchButtonGroup__aetw5 prc-ButtonGroup-ButtonGroup-vFUrY"><div><button type="button" aria-label="Search or jump to…" class="prc-Button-ButtonBase-9n-Xk styles-module__appHeaderButton__axedQ Search-module__searchButton__aiE0a" data-loading="false" data-size="medium" data-variant="invisible"><span data-component="buttonContent" data-align="center" class="prc-Button-ButtonContent-Iohp5"><span data-component="leadingVisual" class="prc-Button-Visual-YNt2F prc-Button-VisualWrap-E4cnq"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-search" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="M10.68 11.74a6 6 0 0 1-7.922-8.982 6 6 0 0 1 8.982 7.922l3.04 3.04a.749.749 0 0 1-.326 1.275.749.749 0 0 1-.734-.215ZM11.5 7a4.499 4.499 0 1 0-8.997 0A4.499 4.499 0 0 0 11.5 7Z"></path></svg></span><span data-component="text" class="prc-Button-Label-FWkx3"><span class="Search-module__placeholder__p9hbG Search-module__text__veSYi Search-module__value__TFoak">Type <kbd class="Search-module__kbd__WCskr">/</kbd> to search</span></span></span></button></div><div></div></div><button data-component="IconButton" type="button" class="prc-Button-ButtonBase-9n-Xk styles-module__appHeaderButton__axedQ Search-module__smallSearchButton___8Gvn prc-Button-IconButton-fyge7" data-loading="false" data-no-visuals="true" data-size="medium" data-variant="invisible" aria-labelledby="_R_2l9b_"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-search" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="M10.68 11.74a6 6 0 0 1-7.922-8.982 6 6 0 0 1 8.982 7.922l3.04 3.04a.749.749 0 0 1-.326 1.275.749.749 0 0 1-.734-.215ZM11.5 7a4.499 4.499 0 1 0-8.997 0A4.499 4.499 0 0 0 11.5 7Z"></path></svg></button><span class="prc-TooltipV2-Tooltip-tLeuB" data-direction="s" aria-hidden="true"><span id="_R_2l9b_">Search or jump to…<span class="prc-src-InternalVisuallyHidden-2YaI6">(<!-- -->forward slash<!-- -->)</span></span><span class="prc-TooltipV2-KeybindingHintContainer-Ymj-3 prc-TooltipV2-HasTextBefore-fdOXj" aria-hidden="true"><kbd class="prc-KeybindingHint-KeybindingHint-qpYIs prc-Text-Text-9mHv3" data-testid="keybinding-hint"><span class="prc-components-Chord-DdhWN prc-components-ChordOnEmphasis-O-4BS prc-components-ChordSmall-c-P-x prc-Text-Text-9mHv3" data-kbd-chord="true"> <span class="prc-src-InternalVisuallyHidden-2YaI6">forward slash</span><span aria-hidden="true">/</span></span></kbd></span></span><div class="d-none"></div><div class="d-none"></div></div><div data-testid="top-nav-right" class="styles-module__right__mlBQg styles-module__withLocalNavigation__rjTJ_ prc-Stack-Stack-UQ9k6" data-gap="condensed" data-direction="horizontal" data-align="center" data-wrap="nowrap" data-justify="start" data-padding="normal"><div data-testid="top-bar-actions" class="prc-Stack-Stack-UQ9k6" data-gap="condensed" data-direction="horizontal" data-align="center" data-wrap="nowrap" data-justify="start" data-padding="none"><div class="styles-module__itemDivider__nunbs hide-sm hide-md"></div><button type="button" aria-haspopup="true" aria-expanded="false" tabindex="0" class="prc-Button-ButtonBase-9n-Xk GlobalCreateMenu-module__actionMenuButton__Hj_iB" data-loading="false" data-size="medium" data-variant="invisible" aria-labelledby="global-create-menu-tooltip-_R_1jpb_" id="_R_5jpb_"><span data-component="buttonContent" data-align="center" class="prc-Button-ButtonContent-Iohp5"><span data-component="leadingVisual" class="prc-Button-Visual-YNt2F prc-Button-VisualWrap-E4cnq"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-plus" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="M7.75 2a.75.75 0 0 1 .75.75V7h4.25a.75.75 0 0 1 0 1.5H8.5v4.25a.75.75 0 0 1-1.5 0V8.5H2.75a.75.75 0 0 1 0-1.5H7V2.75A.75.75 0 0 1 7.75 2Z"></path></svg></span></span><span data-component="trailingAction" class="prc-Button-Visual-YNt2F prc-Button-VisualWrap-E4cnq"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-triangle-down" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="m4.427 7.427 3.396 3.396a.25.25 0 0 0 .354 0l3.396-3.396A.25.25 0 0 0 11.396 7H4.604a.25.25 0 0 0-.177.427Z"></path></svg></span></button><span class="prc-TooltipV2-Tooltip-tLeuB" data-direction="s" aria-hidden="true" id="global-create-menu-tooltip-_R_1jpb_">Create new...</span><div class="hide-sm hide-md prc-Stack-Stack-UQ9k6" data-gap="condensed" data-direction="horizontal" data-align="center" data-wrap="nowrap" data-justify="start" data-padding="none"><a data-component="IconButton" type="button" class="prc-Button-ButtonBase-9n-Xk styles-module__appHeaderButton__axedQ prc-Button-IconButton-fyge7" data-loading="false" data-no-visuals="true" data-size="medium" data-variant="invisible" aria-labelledby="_R_m3pb_" href="/issues" data-discover="true"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-issue-opened" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="M8 9.5a1.5 1.5 0 1 0 0-3 1.5 1.5 0 0 0 0 3Z"></path><path d="M8 0a8 8 0 1 1 0 16A8 8 0 0 1 8 0ZM1.5 8a6.5 6.5 0 1 0 13 0 6.5 6.5 0 0 0-13 0Z"></path></svg></a><span class="prc-TooltipV2-Tooltip-tLeuB" data-direction="s" aria-hidden="true"><span id="_R_m3pb_">Issues<span class="prc-src-InternalVisuallyHidden-2YaI6">(<!-- -->g then i<!-- -->)</span></span><span class="prc-TooltipV2-KeybindingHintContainer-Ymj-3 prc-TooltipV2-HasTextBefore-fdOXj" aria-hidden="true"><kbd class="prc-KeybindingHint-KeybindingHint-qpYIs prc-Text-Text-9mHv3" data-testid="keybinding-hint"><span class="prc-components-Chord-DdhWN prc-components-ChordOnEmphasis-O-4BS prc-components-ChordSmall-c-P-x prc-Text-Text-9mHv3" data-kbd-chord="true"> <span class="prc-src-InternalVisuallyHidden-2YaI6">g</span><span aria-hidden="true">G</span></span><span class="prc-src-InternalVisuallyHidden-2YaI6">then</span> <span class="prc-components-Chord-DdhWN prc-components-ChordOnEmphasis-O-4BS prc-components-ChordSmall-c-P-x prc-Text-Text-9mHv3" data-kbd-chord="true"> <span class="prc-src-InternalVisuallyHidden-2YaI6">i</span><span aria-hidden="true">I</span></span></kbd></span></span><div class="d-none"></div><a data-component="IconButton" type="button" class="prc-Button-ButtonBase-9n-Xk styles-module__appHeaderButton__axedQ prc-Button-IconButton-fyge7" data-loading="false" data-no-visuals="true" data-size="medium" data-variant="invisible" aria-labelledby="_R_q3pb_" href="/pulls" data-discover="true"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-git-pull-request" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="M1.5 3.25a2.25 2.25 0 1 1 3 2.122v5.256a2.251 2.251 0 1 1-1.5 0V5.372A2.25 2.25 0 0 1 1.5 3.25Zm5.677-.177L9.573.677A.25.25 0 0 1 10 .854V2.5h1A2.5 2.5 0 0 1 13.5 5v5.628a2.251 2.251 0 1 1-1.5 0V5a1 1 0 0 0-1-1h-1v1.646a.25.25 0 0 1-.427.177L7.177 3.427a.25.25 0 0 1 0-.354ZM3.75 2.5a.75.75 0 1 0 0 1.5.75.75 0 0 0 0-1.5Zm0 9.5a.75.75 0 1 0 0 1.5.75.75 0 0 0 0-1.5Zm8.25.75a.75.75 0 1 0 1.5 0 .75.75 0 0 0-1.5 0Z"></path></svg></a><span class="prc-TooltipV2-Tooltip-tLeuB" data-direction="s" aria-hidden="true"><span id="_R_q3pb_">Pull requests<span class="prc-src-InternalVisuallyHidden-2YaI6">(<!-- -->g then p<!-- -->)</span></span><span class="prc-TooltipV2-KeybindingHintContainer-Ymj-3 prc-TooltipV2-HasTextBefore-fdOXj" aria-hidden="true"><kbd class="prc-KeybindingHint-KeybindingHint-qpYIs prc-Text-Text-9mHv3" data-testid="keybinding-hint"><span class="prc-components-Chord-DdhWN prc-components-ChordOnEmphasis-O-4BS prc-components-ChordSmall-c-P-x prc-Text-Text-9mHv3" data-kbd-chord="true"> <span class="prc-src-InternalVisuallyHidden-2YaI6">g</span><span aria-hidden="true">G</span></span><span class="prc-src-InternalVisuallyHidden-2YaI6">then</span> <span class="prc-components-Chord-DdhWN prc-components-ChordOnEmphasis-O-4BS prc-components-ChordSmall-c-P-x prc-Text-Text-9mHv3" data-kbd-chord="true"> <span class="prc-src-InternalVisuallyHidden-2YaI6">p</span><span aria-hidden="true">P</span></span></kbd></span></span><div class="d-none"></div><a data-component="IconButton" type="button" class="prc-Button-ButtonBase-9n-Xk styles-module__appHeaderButton__axedQ prc-Button-IconButton-fyge7" data-loading="false" data-no-visuals="true" data-size="medium" data-variant="invisible" aria-labelledby="_R_u3pb_" href="/repos" data-discover="true"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-repo" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="M2 2.5A2.5 2.5 0 0 1 4.5 0h8.75a.75.75 0 0 1 .75.75v12.5a.75.75 0 0 1-.75.75h-2.5a.75.75 0 0 1 0-1.5h1.75v-2h-8a1 1 0 0 0-.714 1.7.75.75 0 1 1-1.072 1.05A2.495 2.495 0 0 1 2 11.5Zm10.5-1h-8a1 1 0 0 0-1 1v6.708A2.486 2.486 0 0 1 4.5 9h8ZM5 12.25a.25.25 0 0 1 .25-.25h3.5a.25.25 0 0 1 .25.25v3.25a.25.25 0 0 1-.4.2l-1.45-1.087a.249.249 0 0 0-.3 0L5.4 15.7a.25.25 0 0 1-.4-.2Z"></path></svg></a><span class="prc-TooltipV2-Tooltip-tLeuB" data-direction="s" aria-hidden="true" id="_R_u3pb_">Repositories</span><div class="d-none"></div></div></div><a data-component="IconButton" type="button" class="prc-Button-ButtonBase-9n-Xk styles-module__appHeaderButton__axedQ prc-Button-IconButton-fyge7" data-loading="false" data-no-visuals="true" data-size="medium" data-variant="invisible" aria-labelledby="_R_lpb_" href="/notifications" data-discover="true"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-inbox" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="M2.8 2.06A1.75 1.75 0 0 1 4.41 1h7.18c.7 0 1.333.417 1.61 1.06l2.74 6.395c.04.093.06.194.06.295v4.5A1.75 1.75 0 0 1 14.25 15H1.75A1.75 1.75 0 0 1 0 13.25v-4.5c0-.101.02-.202.06-.295Zm1.61.44a.25.25 0 0 0-.23.152L1.887 8H4.75a.75.75 0 0 1 .6.3L6.625 10h2.75l1.275-1.7a.75.75 0 0 1 .6-.3h2.863L11.82 2.652a.25.25 0 0 0-.23-.152Zm10.09 7h-2.875l-1.275 1.7a.75.75 0 0 1-.6.3h-3.5a.75.75 0 0 1-.6-.3L4.375 9.5H1.5v3.75c0 .138.112.25.25.25h12.5a.25.25 0 0 0 .25-.25Z"></path></svg></a><span class="prc-TooltipV2-Tooltip-tLeuB" data-direction="s" aria-hidden="true"><span id="_R_lpb_">You have no unread notifications<span class="prc-src-InternalVisuallyHidden-2YaI6">(<!-- -->g then n<!-- -->)</span></span><span class="prc-TooltipV2-KeybindingHintContainer-Ymj-3 prc-TooltipV2-HasTextBefore-fdOXj" aria-hidden="true"><kbd class="prc-KeybindingHint-KeybindingHint-qpYIs prc-Text-Text-9mHv3" data-testid="keybinding-hint"><span class="prc-components-Chord-DdhWN prc-components-ChordOnEmphasis-O-4BS prc-components-ChordSmall-c-P-x prc-Text-Text-9mHv3" data-kbd-chord="true"> <span class="prc-src-InternalVisuallyHidden-2YaI6">g</span><span aria-hidden="true">G</span></span><span class="prc-src-InternalVisuallyHidden-2YaI6">then</span> <span class="prc-components-Chord-DdhWN prc-components-ChordOnEmphasis-O-4BS prc-components-ChordSmall-c-P-x prc-Text-Text-9mHv3" data-kbd-chord="true"> <span class="prc-src-InternalVisuallyHidden-2YaI6">n</span><span aria-hidden="true">N</span></span></kbd></span></span><div class="d-none"></div><div class="GlobalNavUserMenu-module__container__NaVIt"><button data-component="IconButton" type="button" aria-haspopup="menu" data-login="greydoubt" class="prc-Button-ButtonBase-9n-Xk GlobalNavUserMenu-module__anchor__Dcej6 prc-Button-IconButton-fyge7" data-loading="false" data-no-visuals="true" data-size="medium" data-variant="invisible" aria-labelledby="_R_2npb_"><img data-component="Avatar" class="prc-Avatar-Avatar-0xaUi" alt=" λx . ophidia ereц grex⋆. 𐙚 ̊      .    أوفيديا إريكس جريكس   ." width="32" height="32" style="--avatarSize-regular:32px" src="https://avatars.githubusercontent.com/u/43443470?v=4&amp;size=64" data-testid="github-avatar"/></button><span class="prc-TooltipV2-Tooltip-tLeuB" data-direction="s" aria-hidden="true" id="_R_2npb_">Open user navigation menu</span></div></div></div><h2 class="prc-src-InternalVisuallyHidden-2YaI6">User navigation</h2><nav class="prc-components-UnderlineWrapper-eT-Yj LocalNavigation-module__LocalNavigation__b0Xc0" aria-label="User" data-variant="inset" data-overflow-measured="false"><ul class="prc-components-UnderlineItemList-xKlKC" role="list"><li class="prc-UnderlineNav-UnderlineNavItem-syRjR"><a href="/greydoubt" aria-current="page" data-tab-item="overview" data-turbo-frame="user-profile-frame" class="prc-components-UnderlineItem-7fP-n" data-discover="true"><span data-component="icon"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-book" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="M0 1.75A.75.75 0 0 1 .75 1h4.253c1.227 0 2.317.59 3 1.501A3.743 3.743 0 0 1 11.006 1h4.245a.75.75 0 0 1 .75.75v10.5a.75.75 0 0 1-.75.75h-4.507a2.25 2.25 0 0 0-1.591.659l-.622.621a.75.75 0 0 1-1.06 0l-.622-.621A2.25 2.25 0 0 0 5.258 13H.75a.75.75 0 0 1-.75-.75Zm7.251 10.324.004-5.073-.002-2.253A2.25 2.25 0 0 0 5.003 2.5H1.5v9h3.757a3.75 3.75 0 0 1 1.994.574ZM8.755 4.75l-.004 7.322a3.752 3.752 0 0 1 1.992-.572H14.5v-9h-3.495a2.25 2.25 0 0 0-2.25 2.25Z"></path></svg></span><span data-component="text" data-content="Overview">Overview</span></a></li><li class="prc-UnderlineNav-UnderlineNavItem-syRjR"><a href="/greydoubt?tab=repositories" data-tab-item="repositories" data-turbo-frame="user-profile-frame" class="prc-components-UnderlineItem-7fP-n" data-discover="true"><span data-component="icon"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-repo" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="M2 2.5A2.5 2.5 0 0 1 4.5 0h8.75a.75.75 0 0 1 .75.75v12.5a.75.75 0 0 1-.75.75h-2.5a.75.75 0 0 1 0-1.5h1.75v-2h-8a1 1 0 0 0-.714 1.7.75.75 0 1 1-1.072 1.05A2.495 2.495 0 0 1 2 11.5Zm10.5-1h-8a1 1 0 0 0-1 1v6.708A2.486 2.486 0 0 1 4.5 9h8ZM5 12.25a.25.25 0 0 1 .25-.25h3.5a.25.25 0 0 1 .25.25v3.25a.25.25 0 0 1-.4.2l-1.45-1.087a.249.249 0 0 0-.3 0L5.4 15.7a.25.25 0 0 1-.4-.2Z"></path></svg></span><span data-component="text" data-content="Repositories">Repositories</span><span data-component="counter"><span aria-hidden="true" data-variant="secondary" class="prc-CounterLabel-CounterLabel-X-kRU">603</span><span class="prc-VisuallyHidden-VisuallyHidden-Q0qSB"> (<!-- -->603<!-- -->)</span></span></a></li><li class="prc-UnderlineNav-UnderlineNavItem-syRjR"><a href="/greydoubt?tab=projects" data-tab-item="projects" data-turbo-frame="user-profile-frame" class="prc-components-UnderlineItem-7fP-n" data-discover="true"><span data-component="icon"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-table" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="M0 1.75C0 .784.784 0 1.75 0h12.5C15.216 0 16 .784 16 1.75v12.5A1.75 1.75 0 0 1 14.25 16H1.75A1.75 1.75 0 0 1 0 14.25ZM6.5 6.5v8h7.75a.25.25 0 0 0 .25-.25V6.5Zm8-1.5V1.75a.25.25 0 0 0-.25-.25H6.5V5Zm-13 1.5v7.75c0 .138.112.25.25.25H5v-8ZM5 5V1.5H1.75a.25.25 0 0 0-.25.25V5Z"></path></svg></span><span data-component="text" data-content="Projects">Projects</span></a></li><li class="prc-UnderlineNav-UnderlineNavItem-syRjR"><a href="/greydoubt?tab=packages" data-tab-item="packages" data-turbo-frame="user-profile-frame" class="prc-components-UnderlineItem-7fP-n" data-discover="true"><span data-component="icon"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-package" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="m8.878.392 5.25 3.045c.54.314.872.89.872 1.514v6.098a1.75 1.75 0 0 1-.872 1.514l-5.25 3.045a1.75 1.75 0 0 1-1.756 0l-5.25-3.045A1.75 1.75 0 0 1 1 11.049V4.951c0-.624.332-1.201.872-1.514L7.122.392a1.75 1.75 0 0 1 1.756 0ZM7.875 1.69l-4.63 2.685L8 7.133l4.755-2.758-4.63-2.685a.248.248 0 0 0-.25 0ZM2.5 5.677v5.372c0 .09.047.171.125.216l4.625 2.683V8.432Zm6.25 8.271 4.625-2.683a.25.25 0 0 0 .125-.216V5.677L8.75 8.432Z"></path></svg></span><span data-component="text" data-content="Packages">Packages</span></a></li><li class="prc-UnderlineNav-UnderlineNavItem-syRjR"><a href="/greydoubt?tab=stars" data-tab-item="stars" data-turbo-frame="user-profile-frame" class="prc-components-UnderlineItem-7fP-n" data-discover="true"><span data-component="icon"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-star" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="M8 .25a.75.75 0 0 1 .673.418l1.882 3.815 4.21.612a.75.75 0 0 1 .416 1.279l-3.046 2.97.719 4.192a.751.751 0 0 1-1.088.791L8 12.347l-3.766 1.98a.75.75 0 0 1-1.088-.79l.72-4.194L.818 6.374a.75.75 0 0 1 .416-1.28l4.21-.611L7.327.668A.75.75 0 0 1 8 .25Zm0 2.445L6.615 5.5a.75.75 0 0 1-.564.41l-3.097.45 2.24 2.184a.75.75 0 0 1 .216.664l-.528 3.084 2.769-1.456a.75.75 0 0 1 .698 0l2.77 1.456-.53-3.084a.75.75 0 0 1 .216-.664l2.24-2.183-3.096-.45a.75.75 0 0 1-.564-.41L8 2.694Z"></path></svg></span><span data-component="text" data-content="Stars">Stars</span><span data-component="counter"><span aria-hidden="true" data-variant="secondary" class="prc-CounterLabel-CounterLabel-X-kRU">527</span><span class="prc-VisuallyHidden-VisuallyHidden-Q0qSB"> (<!-- -->527<!-- -->)</span></span></a></li><li class="prc-UnderlineNav-UnderlineNavItem-syRjR"><a href="/greydoubt?tab=sponsoring" data-tab-item="sponsoring" data-turbo-frame="user-profile-frame" class="prc-components-UnderlineItem-7fP-n" data-discover="true"><span data-component="icon"><svg data-component="Octicon" aria-hidden="true" focusable="false" class="octicon octicon-heart" viewBox="0 0 16 16" width="16" height="16" fill="currentColor" display="inline-block" overflow="visible" style="vertical-align:text-bottom"><path d="m8 14.25.345.666a.75.75 0 0 1-.69 0l-.008-.004-.018-.01a7.152 7.152 0 0 1-.31-.17 22.055 22.055 0 0 1-3.434-2.414C2.045 10.731 0 8.35 0 5.5 0 2.836 2.086 1 4.25 1 5.797 1 7.153 1.802 8 3.02 8.847 1.802 10.203 1 11.75 1 13.914 1 16 2.836 16 5.5c0 2.85-2.045 5.231-3.885 6.818a22.066 22.066 0 0 1-3.744 2.584l-.018.01-.006.003h-.002ZM4.25 2.5c-1.336 0-2.75 1.164-2.75 3 0 2.15 1.58 4.144 3.365 5.682A20.58 20.58 0 0 0 8 13.393a20.58 20.58 0 0 0 3.135-2.211C12.92 9.644 14.5 7.65 14.5 5.5c0-1.836-1.414-3-2.75-3-1.373 0-2.609.986-3.029 2.456a.749.749 0 0 1-1.442 0C6.859 3.486 5.623 2.5 4.25 2.5Z"></path></svg></span><span data-component="text" data-content="Sponsoring">Sponsoring</span></a></li></ul></nav><div class="d-none"></div></header><script type="application/json" id="__PRIMER_DATA__R_0___">{"resolvedServerColorMode":"night"}</script></div>
</react-partial>


      <div class="js-global-bar" style="display: none;">
        


<qbsearch-input class="search-input" data-scope="owner:greydoubt" data-custom-scopes-path="/search/custom_scopes" data-delete-custom-scopes-csrf="XtPhBFwi5RziOJL_ok3_k20LPxE7YV8CyNFdhDnNBi_0Am8pBmcXsZ0cYr70hSwNBn5anh3TGEQa_vrS7iyd5A" data-max-custom-scopes="10" data-header-redesign-enabled="true" data-initial-value="" data-blackbird-suggestions-path="/search/suggestions" data-jump-to-suggestions-path="/_graphql/GetSuggestedNavigationDestinations" data-current-repository="" data-current-org="" data-current-owner="" data-logged-in="true" data-copilot-chat-enabled="false" data-nl-search-enabled="false">
  <div
    class="search-input-container search-with-dialog position-relative d-flex flex-row flex-items-center height-auto color-bg-transparent border-0 color-fg-subtle mx-0"
    data-action="click:qbsearch-input#searchInputContainerClicked"
  >

    <input type="hidden" name="type" class="js-site-search-type-field">

    
<div class="Overlay--hidden " data-modal-dialog-overlay>
  <modal-dialog data-action="close:qbsearch-input#handleClose cancel:qbsearch-input#handleClose" data-target="qbsearch-input.searchSuggestionsDialog" role="dialog" id="search-suggestions-dialog" aria-modal="true" aria-labelledby="search-suggestions-dialog-header" data-view-component="true" class="Overlay Overlay--width-medium Overlay--height-auto">
      <h1 id="search-suggestions-dialog-header" class="sr-only">Search code, repositories, users, issues, pull requests...</h1>
    <div class="Overlay-body Overlay-body--paddingNone">
      
          <div data-view-component="true">        <div class="search-suggestions position-absolute width-full color-shadow-large border color-fg-default color-bg-default overflow-hidden d-flex flex-column query-builder-container"
          style="border-radius: 12px;"
          data-target="qbsearch-input.queryBuilderContainer"
          hidden
        >
          <!-- '"` --><!-- </textarea></xmp> --></option></form><form id="query-builder-test-form" action="" accept-charset="UTF-8" method="get">
  <query-builder data-target="qbsearch-input.queryBuilder" id="query-builder-query-builder-test" data-filter-key=":" data-view-component="true" class="QueryBuilder search-query-builder">
    <div class="FormControl FormControl--fullWidth">
      <label id="query-builder-test-label" for="query-builder-test" class="FormControl-label sr-only">
        Search
      </label>
      <div
        class="QueryBuilder-StyledInput width-fit "
        data-target="query-builder.styledInput"
      >
          <span id="query-builder-test-leadingvisual-wrap" class="FormControl-input-leadingVisualWrap QueryBuilder-leadingVisualWrap">
            <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-search FormControl-input-leadingVisual">
    <path d="M10.68 11.74a6 6 0 0 1-7.922-8.982 6 6 0 0 1 8.982 7.922l3.04 3.04a.749.749 0 0 1-.326 1.275.749.749 0 0 1-.734-.215ZM11.5 7a4.499 4.499 0 1 0-8.997 0A4.499 4.499 0 0 0 11.5 7Z"></path>
</svg>
          </span>
        <div data-target="query-builder.styledInputContainer" class="QueryBuilder-StyledInputContainer">
          <div
            aria-hidden="true"
            class="QueryBuilder-StyledInputContent"
            data-target="query-builder.styledInputContent"
          ></div>
          <div class="QueryBuilder-InputWrapper">
            <div aria-hidden="true" class="QueryBuilder-Sizer" data-target="query-builder.sizer"></div>
            <input id="query-builder-test" name="query-builder-test" value="" autocomplete="off" type="text" role="combobox" spellcheck="false" aria-expanded="false" aria-describedby="validation-e6ff5223-ef54-4908-bd49-01fa0380de94" data-target="query-builder.input" data-action="
          input:query-builder#inputChange
          blur:query-builder#inputBlur
          keydown:query-builder#inputKeydown
          focus:query-builder#inputFocus
        " data-view-component="true" class="FormControl-input QueryBuilder-Input FormControl-medium" />
          </div>
        </div>
          <span data-target="query-builder.clearButton" hidden>
            <span class="sr-only" id="query-builder-test-clear">Clear</span>
            <button role="button" id="query-builder-test-clear-button" aria-labelledby="query-builder-test-clear query-builder-test-label" data-action="
                  click:query-builder#clear
                  focus:query-builder#clearButtonFocus
                  blur:query-builder#clearButtonBlur
                " variant="small" type="button" data-view-component="true" class="Button Button--iconOnly Button--invisible Button--medium mr-1 tmp-mr-1 px-2 tmp-px-2 py-0 tmp-py-0 d-flex flex-items-center rounded-1 color-fg-muted">  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-x-circle-fill Button-visual">
    <path d="M2.343 13.657A8 8 0 1 1 13.658 2.343 8 8 0 0 1 2.343 13.657ZM6.03 4.97a.751.751 0 0 0-1.042.018.751.751 0 0 0-.018 1.042L6.94 8 4.97 9.97a.749.749 0 0 0 .326 1.275.749.749 0 0 0 .734-.215L8 9.06l1.97 1.97a.749.749 0 0 0 1.275-.326.749.749 0 0 0-.215-.734L9.06 8l1.97-1.97a.749.749 0 0 0-.326-1.275.749.749 0 0 0-.734.215L8 6.94Z"></path>
</svg>
</button>

          </span>
      </div>
      <template id="search-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-search">
    <path d="M10.68 11.74a6 6 0 0 1-7.922-8.982 6 6 0 0 1 8.982 7.922l3.04 3.04a.749.749 0 0 1-.326 1.275.749.749 0 0 1-.734-.215ZM11.5 7a4.499 4.499 0 1 0-8.997 0A4.499 4.499 0 0 0 11.5 7Z"></path>
</svg>
</template>

<template id="code-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-code">
    <path d="m11.28 3.22 4.25 4.25a.75.75 0 0 1 0 1.06l-4.25 4.25a.749.749 0 0 1-1.275-.326.749.749 0 0 1 .215-.734L13.94 8l-3.72-3.72a.749.749 0 0 1 .326-1.275.749.749 0 0 1 .734.215Zm-6.56 0a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042L2.06 8l3.72 3.72a.749.749 0 0 1-.326 1.275.749.749 0 0 1-.734-.215L.47 8.53a.75.75 0 0 1 0-1.06Z"></path>
</svg>
</template>

<template id="file-code-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-file-code">
    <path d="M4 1.75C4 .784 4.784 0 5.75 0h5.586c.464 0 .909.184 1.237.513l2.914 2.914c.329.328.513.773.513 1.237v8.586A1.75 1.75 0 0 1 14.25 15h-9a.75.75 0 0 1 0-1.5h9a.25.25 0 0 0 .25-.25V6h-2.75A1.75 1.75 0 0 1 10 4.25V1.5H5.75a.25.25 0 0 0-.25.25v2.5a.75.75 0 0 1-1.5 0Zm1.72 4.97a.75.75 0 0 1 1.06 0l2 2a.75.75 0 0 1 0 1.06l-2 2a.749.749 0 0 1-1.275-.326.749.749 0 0 1 .215-.734l1.47-1.47-1.47-1.47a.75.75 0 0 1 0-1.06ZM3.28 7.78 1.81 9.25l1.47 1.47a.751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018l-2-2a.75.75 0 0 1 0-1.06l2-2a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042Zm8.22-6.218V4.25c0 .138.112.25.25.25h2.688l-.011-.013-2.914-2.914-.013-.011Z"></path>
</svg>
</template>

<template id="history-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-history">
    <path d="m.427 1.927 1.215 1.215a8.002 8.002 0 1 1-1.6 5.685.75.75 0 1 1 1.493-.154 6.5 6.5 0 1 0 1.18-4.458l1.358 1.358A.25.25 0 0 1 3.896 6H.25A.25.25 0 0 1 0 5.75V2.104a.25.25 0 0 1 .427-.177ZM7.75 4a.75.75 0 0 1 .75.75v2.992l2.028.812a.75.75 0 0 1-.557 1.392l-2.5-1A.751.751 0 0 1 7 8.25v-3.5A.75.75 0 0 1 7.75 4Z"></path>
</svg>
</template>

<template id="repo-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-repo">
    <path d="M2 2.5A2.5 2.5 0 0 1 4.5 0h8.75a.75.75 0 0 1 .75.75v12.5a.75.75 0 0 1-.75.75h-2.5a.75.75 0 0 1 0-1.5h1.75v-2h-8a1 1 0 0 0-.714 1.7.75.75 0 1 1-1.072 1.05A2.495 2.495 0 0 1 2 11.5Zm10.5-1h-8a1 1 0 0 0-1 1v6.708A2.486 2.486 0 0 1 4.5 9h8ZM5 12.25a.25.25 0 0 1 .25-.25h3.5a.25.25 0 0 1 .25.25v3.25a.25.25 0 0 1-.4.2l-1.45-1.087a.249.249 0 0 0-.3 0L5.4 15.7a.25.25 0 0 1-.4-.2Z"></path>
</svg>
</template>

<template id="bookmark-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-bookmark">
    <path d="M3 2.75C3 1.784 3.784 1 4.75 1h6.5c.966 0 1.75.784 1.75 1.75v11.5a.75.75 0 0 1-1.227.579L8 11.722l-3.773 3.107A.751.751 0 0 1 3 14.25Zm1.75-.25a.25.25 0 0 0-.25.25v9.91l3.023-2.489a.75.75 0 0 1 .954 0l3.023 2.49V2.75a.25.25 0 0 0-.25-.25Z"></path>
</svg>
</template>

<template id="plus-circle-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-plus-circle">
    <path d="M8 0a8 8 0 1 1 0 16A8 8 0 0 1 8 0ZM1.5 8a6.5 6.5 0 1 0 13 0 6.5 6.5 0 0 0-13 0Zm7.25-3.25v2.5h2.5a.75.75 0 0 1 0 1.5h-2.5v2.5a.75.75 0 0 1-1.5 0v-2.5h-2.5a.75.75 0 0 1 0-1.5h2.5v-2.5a.75.75 0 0 1 1.5 0Z"></path>
</svg>
</template>

<template id="circle-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-dot-fill">
    <path d="M8 4a4 4 0 1 1 0 8 4 4 0 0 1 0-8Z"></path>
</svg>
</template>

<template id="trash-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-trash">
    <path d="M11 1.75V3h2.25a.75.75 0 0 1 0 1.5H2.75a.75.75 0 0 1 0-1.5H5V1.75C5 .784 5.784 0 6.75 0h2.5C10.216 0 11 .784 11 1.75ZM4.496 6.675l.66 6.6a.25.25 0 0 0 .249.225h5.19a.25.25 0 0 0 .249-.225l.66-6.6a.75.75 0 0 1 1.492.149l-.66 6.6A1.748 1.748 0 0 1 10.595 15h-5.19a1.75 1.75 0 0 1-1.741-1.575l-.66-6.6a.75.75 0 1 1 1.492-.15ZM6.5 1.75V3h3V1.75a.25.25 0 0 0-.25-.25h-2.5a.25.25 0 0 0-.25.25Z"></path>
</svg>
</template>

<template id="team-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-people">
    <path d="M2 5.5a3.5 3.5 0 1 1 5.898 2.549 5.508 5.508 0 0 1 3.034 4.084.75.75 0 1 1-1.482.235 4 4 0 0 0-7.9 0 .75.75 0 0 1-1.482-.236A5.507 5.507 0 0 1 3.102 8.05 3.493 3.493 0 0 1 2 5.5ZM11 4a3.001 3.001 0 0 1 2.22 5.018 5.01 5.01 0 0 1 2.56 3.012.749.749 0 0 1-.885.954.752.752 0 0 1-.549-.514 3.507 3.507 0 0 0-2.522-2.372.75.75 0 0 1-.574-.73v-.352a.75.75 0 0 1 .416-.672A1.5 1.5 0 0 0 11 5.5.75.75 0 0 1 11 4Zm-5.5-.5a2 2 0 1 0-.001 3.999A2 2 0 0 0 5.5 3.5Z"></path>
</svg>
</template>

<template id="project-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-project">
    <path d="M1.75 0h12.5C15.216 0 16 .784 16 1.75v12.5A1.75 1.75 0 0 1 14.25 16H1.75A1.75 1.75 0 0 1 0 14.25V1.75C0 .784.784 0 1.75 0ZM1.5 1.75v12.5c0 .138.112.25.25.25h12.5a.25.25 0 0 0 .25-.25V1.75a.25.25 0 0 0-.25-.25H1.75a.25.25 0 0 0-.25.25ZM11.75 3a.75.75 0 0 1 .75.75v7.5a.75.75 0 0 1-1.5 0v-7.5a.75.75 0 0 1 .75-.75Zm-8.25.75a.75.75 0 0 1 1.5 0v5.5a.75.75 0 0 1-1.5 0ZM8 3a.75.75 0 0 1 .75.75v3.5a.75.75 0 0 1-1.5 0v-3.5A.75.75 0 0 1 8 3Z"></path>
</svg>
</template>

<template id="pencil-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-pencil">
    <path d="M11.013 1.427a1.75 1.75 0 0 1 2.474 0l1.086 1.086a1.75 1.75 0 0 1 0 2.474l-8.61 8.61c-.21.21-.47.364-.756.445l-3.251.93a.75.75 0 0 1-.927-.928l.929-3.25c.081-.286.235-.547.445-.758l8.61-8.61Zm.176 4.823L9.75 4.81l-6.286 6.287a.253.253 0 0 0-.064.108l-.558 1.953 1.953-.558a.253.253 0 0 0 .108-.064Zm1.238-3.763a.25.25 0 0 0-.354 0L10.811 3.75l1.439 1.44 1.263-1.263a.25.25 0 0 0 0-.354Z"></path>
</svg>
</template>

<template id="copilot-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-copilot">
    <path d="M7.998 15.035c-4.562 0-7.873-2.914-7.998-3.749V9.338c.085-.628.677-1.686 1.588-2.065.013-.07.024-.143.036-.218.029-.183.06-.384.126-.612-.201-.508-.254-1.084-.254-1.656 0-.87.128-1.769.693-2.484.579-.733 1.494-1.124 2.724-1.261 1.206-.134 2.262.034 2.944.765.05.053.096.108.139.165.044-.057.094-.112.143-.165.682-.731 1.738-.899 2.944-.765 1.23.137 2.145.528 2.724 1.261.566.715.693 1.614.693 2.484 0 .572-.053 1.148-.254 1.656.066.228.098.429.126.612.012.076.024.148.037.218.924.385 1.522 1.471 1.591 2.095v1.872c0 .766-3.351 3.795-8.002 3.795Zm0-1.485c2.28 0 4.584-1.11 5.002-1.433V7.862l-.023-.116c-.49.21-1.075.291-1.727.291-1.146 0-2.059-.327-2.71-.991A3.222 3.222 0 0 1 8 6.303a3.24 3.24 0 0 1-.544.743c-.65.664-1.563.991-2.71.991-.652 0-1.236-.081-1.727-.291l-.023.116v4.255c.419.323 2.722 1.433 5.002 1.433ZM6.762 2.83c-.193-.206-.637-.413-1.682-.297-1.019.113-1.479.404-1.713.7-.247.312-.369.789-.369 1.554 0 .793.129 1.171.308 1.371.162.181.519.379 1.442.379.853 0 1.339-.235 1.638-.54.315-.322.527-.827.617-1.553.117-.935-.037-1.395-.241-1.614Zm4.155-.297c-1.044-.116-1.488.091-1.681.297-.204.219-.359.679-.242 1.614.091.726.303 1.231.618 1.553.299.305.784.54 1.638.54.922 0 1.28-.198 1.442-.379.179-.2.308-.578.308-1.371 0-.765-.123-1.242-.37-1.554-.233-.296-.693-.587-1.713-.7Z"></path><path d="M6.25 9.037a.75.75 0 0 1 .75.75v1.501a.75.75 0 0 1-1.5 0V9.787a.75.75 0 0 1 .75-.75Zm4.25.75v1.501a.75.75 0 0 1-1.5 0V9.787a.75.75 0 0 1 1.5 0Z"></path>
</svg>
</template>

<template id="copilot-error-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-copilot-error">
    <path d="M16 11.24c0 .112-.072.274-.21.467L13 9.688V7.862l-.023-.116c-.49.21-1.075.291-1.727.291-.198 0-.388-.009-.571-.029L6.833 5.226a4.01 4.01 0 0 0 .17-.782c.117-.935-.037-1.395-.241-1.614-.193-.206-.637-.413-1.682-.297-.683.076-1.115.231-1.395.415l-1.257-.91c.579-.564 1.413-.877 2.485-.996 1.206-.134 2.262.034 2.944.765.05.053.096.108.139.165.044-.057.094-.112.143-.165.682-.731 1.738-.899 2.944-.765 1.23.137 2.145.528 2.724 1.261.566.715.693 1.614.693 2.484 0 .572-.053 1.148-.254 1.656.066.228.098.429.126.612.012.076.024.148.037.218.924.385 1.522 1.471 1.591 2.095Zm-5.083-8.707c-1.044-.116-1.488.091-1.681.297-.204.219-.359.679-.242 1.614.091.726.303 1.231.618 1.553.299.305.784.54 1.638.54.922 0 1.28-.198 1.442-.379.179-.2.308-.578.308-1.371 0-.765-.123-1.242-.37-1.554-.233-.296-.693-.587-1.713-.7Zm2.511 11.074c-1.393.776-3.272 1.428-5.43 1.428-4.562 0-7.873-2.914-7.998-3.749V9.338c.085-.628.677-1.686 1.588-2.065.013-.07.024-.143.036-.218.029-.183.06-.384.126-.612-.18-.455-.241-.963-.252-1.475L.31 4.107A.747.747 0 0 1 0 3.509V3.49a.748.748 0 0 1 .625-.73c.156-.026.306.047.435.139l14.667 10.578a.592.592 0 0 1 .227.264.752.752 0 0 1 .046.249v.022a.75.75 0 0 1-1.19.596Zm-1.367-.991L5.635 7.964a5.128 5.128 0 0 1-.889.073c-.652 0-1.236-.081-1.727-.291l-.023.116v4.255c.419.323 2.722 1.433 5.002 1.433 1.539 0 3.089-.505 4.063-.934Z"></path>
</svg>
</template>

<template id="workflow-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-workflow">
    <path d="M0 1.75C0 .784.784 0 1.75 0h3.5C6.216 0 7 .784 7 1.75v3.5A1.75 1.75 0 0 1 5.25 7H4v4a1 1 0 0 0 1 1h4v-1.25C9 9.784 9.784 9 10.75 9h3.5c.966 0 1.75.784 1.75 1.75v3.5A1.75 1.75 0 0 1 14.25 16h-3.5A1.75 1.75 0 0 1 9 14.25v-.75H5A2.5 2.5 0 0 1 2.5 11V7h-.75A1.75 1.75 0 0 1 0 5.25Zm1.75-.25a.25.25 0 0 0-.25.25v3.5c0 .138.112.25.25.25h3.5a.25.25 0 0 0 .25-.25v-3.5a.25.25 0 0 0-.25-.25Zm9 9a.25.25 0 0 0-.25.25v3.5c0 .138.112.25.25.25h3.5a.25.25 0 0 0 .25-.25v-3.5a.25.25 0 0 0-.25-.25Z"></path>
</svg>
</template>

<template id="book-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-book">
    <path d="M0 1.75A.75.75 0 0 1 .75 1h4.253c1.227 0 2.317.59 3 1.501A3.743 3.743 0 0 1 11.006 1h4.245a.75.75 0 0 1 .75.75v10.5a.75.75 0 0 1-.75.75h-4.507a2.25 2.25 0 0 0-1.591.659l-.622.621a.75.75 0 0 1-1.06 0l-.622-.621A2.25 2.25 0 0 0 5.258 13H.75a.75.75 0 0 1-.75-.75Zm7.251 10.324.004-5.073-.002-2.253A2.25 2.25 0 0 0 5.003 2.5H1.5v9h3.757a3.75 3.75 0 0 1 1.994.574ZM8.755 4.75l-.004 7.322a3.752 3.752 0 0 1 1.992-.572H14.5v-9h-3.495a2.25 2.25 0 0 0-2.25 2.25Z"></path>
</svg>
</template>

<template id="code-review-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-code-review">
    <path d="M1.75 1h12.5c.966 0 1.75.784 1.75 1.75v8.5A1.75 1.75 0 0 1 14.25 13H8.061l-2.574 2.573A1.458 1.458 0 0 1 3 14.543V13H1.75A1.75 1.75 0 0 1 0 11.25v-8.5C0 1.784.784 1 1.75 1ZM1.5 2.75v8.5c0 .138.112.25.25.25h2a.75.75 0 0 1 .75.75v2.19l2.72-2.72a.749.749 0 0 1 .53-.22h6.5a.25.25 0 0 0 .25-.25v-8.5a.25.25 0 0 0-.25-.25H1.75a.25.25 0 0 0-.25.25Zm5.28 1.72a.75.75 0 0 1 0 1.06L5.31 7l1.47 1.47a.751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018l-2-2a.75.75 0 0 1 0-1.06l2-2a.75.75 0 0 1 1.06 0Zm2.44 0a.75.75 0 0 1 1.06 0l2 2a.75.75 0 0 1 0 1.06l-2 2a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042L10.69 7 9.22 5.53a.75.75 0 0 1 0-1.06Z"></path>
</svg>
</template>

<template id="codespaces-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-codespaces">
    <path d="M0 11.25c0-.966.784-1.75 1.75-1.75h12.5c.966 0 1.75.784 1.75 1.75v3A1.75 1.75 0 0 1 14.25 16H1.75A1.75 1.75 0 0 1 0 14.25Zm2-9.5C2 .784 2.784 0 3.75 0h8.5C13.216 0 14 .784 14 1.75v5a1.75 1.75 0 0 1-1.75 1.75h-8.5A1.75 1.75 0 0 1 2 6.75Zm1.75-.25a.25.25 0 0 0-.25.25v5c0 .138.112.25.25.25h8.5a.25.25 0 0 0 .25-.25v-5a.25.25 0 0 0-.25-.25Zm-2 9.5a.25.25 0 0 0-.25.25v3c0 .138.112.25.25.25h12.5a.25.25 0 0 0 .25-.25v-3a.25.25 0 0 0-.25-.25Z"></path><path d="M7 12.75a.75.75 0 0 1 .75-.75h4.5a.75.75 0 0 1 0 1.5h-4.5a.75.75 0 0 1-.75-.75Zm-4 0a.75.75 0 0 1 .75-.75h.5a.75.75 0 0 1 0 1.5h-.5a.75.75 0 0 1-.75-.75Z"></path>
</svg>
</template>

<template id="comment-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-comment">
    <path d="M1 2.75C1 1.784 1.784 1 2.75 1h10.5c.966 0 1.75.784 1.75 1.75v7.5A1.75 1.75 0 0 1 13.25 12H9.06l-2.573 2.573A1.458 1.458 0 0 1 4 13.543V12H2.75A1.75 1.75 0 0 1 1 10.25Zm1.75-.25a.25.25 0 0 0-.25.25v7.5c0 .138.112.25.25.25h2a.75.75 0 0 1 .75.75v2.19l2.72-2.72a.749.749 0 0 1 .53-.22h4.5a.25.25 0 0 0 .25-.25v-7.5a.25.25 0 0 0-.25-.25Z"></path>
</svg>
</template>

<template id="comment-discussion-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-comment-discussion">
    <path d="M1.75 1h8.5c.966 0 1.75.784 1.75 1.75v5.5A1.75 1.75 0 0 1 10.25 10H7.061l-2.574 2.573A1.458 1.458 0 0 1 2 11.543V10h-.25A1.75 1.75 0 0 1 0 8.25v-5.5C0 1.784.784 1 1.75 1ZM1.5 2.75v5.5c0 .138.112.25.25.25h1a.75.75 0 0 1 .75.75v2.19l2.72-2.72a.749.749 0 0 1 .53-.22h3.5a.25.25 0 0 0 .25-.25v-5.5a.25.25 0 0 0-.25-.25h-8.5a.25.25 0 0 0-.25.25Zm13 2a.25.25 0 0 0-.25-.25h-.5a.75.75 0 0 1 0-1.5h.5c.966 0 1.75.784 1.75 1.75v5.5A1.75 1.75 0 0 1 14.25 12H14v1.543a1.458 1.458 0 0 1-2.487 1.03L9.22 12.28a.749.749 0 0 1 .326-1.275.749.749 0 0 1 .734.215l2.22 2.22v-2.19a.75.75 0 0 1 .75-.75h1a.25.25 0 0 0 .25-.25Z"></path>
</svg>
</template>

<template id="organization-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-organization">
    <path d="M1.75 16A1.75 1.75 0 0 1 0 14.25V1.75C0 .784.784 0 1.75 0h8.5C11.216 0 12 .784 12 1.75v12.5c0 .085-.006.168-.018.25h2.268a.25.25 0 0 0 .25-.25V8.285a.25.25 0 0 0-.111-.208l-1.055-.703a.749.749 0 1 1 .832-1.248l1.055.703c.487.325.779.871.779 1.456v5.965A1.75 1.75 0 0 1 14.25 16h-3.5a.766.766 0 0 1-.197-.026c-.099.017-.2.026-.303.026h-3a.75.75 0 0 1-.75-.75V14h-1v1.25a.75.75 0 0 1-.75.75Zm-.25-1.75c0 .138.112.25.25.25H4v-1.25a.75.75 0 0 1 .75-.75h2.5a.75.75 0 0 1 .75.75v1.25h2.25a.25.25 0 0 0 .25-.25V1.75a.25.25 0 0 0-.25-.25h-8.5a.25.25 0 0 0-.25.25ZM3.75 6h.5a.75.75 0 0 1 0 1.5h-.5a.75.75 0 0 1 0-1.5ZM3 3.75A.75.75 0 0 1 3.75 3h.5a.75.75 0 0 1 0 1.5h-.5A.75.75 0 0 1 3 3.75Zm4 3A.75.75 0 0 1 7.75 6h.5a.75.75 0 0 1 0 1.5h-.5A.75.75 0 0 1 7 6.75ZM7.75 3h.5a.75.75 0 0 1 0 1.5h-.5a.75.75 0 0 1 0-1.5ZM3 9.75A.75.75 0 0 1 3.75 9h.5a.75.75 0 0 1 0 1.5h-.5A.75.75 0 0 1 3 9.75ZM7.75 9h.5a.75.75 0 0 1 0 1.5h-.5a.75.75 0 0 1 0-1.5Z"></path>
</svg>
</template>

<template id="rocket-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-rocket">
    <path d="M14.064 0h.186C15.216 0 16 .784 16 1.75v.186a8.752 8.752 0 0 1-2.564 6.186l-.458.459c-.314.314-.641.616-.979.904v3.207c0 .608-.315 1.172-.833 1.49l-2.774 1.707a.749.749 0 0 1-1.11-.418l-.954-3.102a1.214 1.214 0 0 1-.145-.125L3.754 9.816a1.218 1.218 0 0 1-.124-.145L.528 8.717a.749.749 0 0 1-.418-1.11l1.71-2.774A1.748 1.748 0 0 1 3.31 4h3.204c.288-.338.59-.665.904-.979l.459-.458A8.749 8.749 0 0 1 14.064 0ZM8.938 3.623h-.002l-.458.458c-.76.76-1.437 1.598-2.02 2.5l-1.5 2.317 2.143 2.143 2.317-1.5c.902-.583 1.74-1.26 2.499-2.02l.459-.458a7.25 7.25 0 0 0 2.123-5.127V1.75a.25.25 0 0 0-.25-.25h-.186a7.249 7.249 0 0 0-5.125 2.123ZM3.56 14.56c-.732.732-2.334 1.045-3.005 1.148a.234.234 0 0 1-.201-.064.234.234 0 0 1-.064-.201c.103-.671.416-2.273 1.15-3.003a1.502 1.502 0 1 1 2.12 2.12Zm6.94-3.935c-.088.06-.177.118-.266.175l-2.35 1.521.548 1.783 1.949-1.2a.25.25 0 0 0 .119-.213ZM3.678 8.116 5.2 5.766c.058-.09.117-.178.176-.266H3.309a.25.25 0 0 0-.213.119l-1.2 1.95ZM12 5a1 1 0 1 1-2 0 1 1 0 0 1 2 0Z"></path>
</svg>
</template>

<template id="shield-check-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-shield-check">
    <path d="m8.533.133 5.25 1.68A1.75 1.75 0 0 1 15 3.48V7c0 1.566-.32 3.182-1.303 4.682-.983 1.498-2.585 2.813-5.032 3.855a1.697 1.697 0 0 1-1.33 0c-2.447-1.042-4.049-2.357-5.032-3.855C1.32 10.182 1 8.566 1 7V3.48a1.75 1.75 0 0 1 1.217-1.667l5.25-1.68a1.748 1.748 0 0 1 1.066 0Zm-.61 1.429.001.001-5.25 1.68a.251.251 0 0 0-.174.237V7c0 1.36.275 2.666 1.057 3.859.784 1.194 2.121 2.342 4.366 3.298a.196.196 0 0 0 .154 0c2.245-.957 3.582-2.103 4.366-3.297C13.225 9.666 13.5 8.358 13.5 7V3.48a.25.25 0 0 0-.174-.238l-5.25-1.68a.25.25 0 0 0-.153 0ZM11.28 6.28l-3.5 3.5a.75.75 0 0 1-1.06 0l-1.5-1.5a.749.749 0 0 1 .326-1.275.749.749 0 0 1 .734.215l.97.97 2.97-2.97a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042Z"></path>
</svg>
</template>

<template id="heart-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-heart">
    <path d="m8 14.25.345.666a.75.75 0 0 1-.69 0l-.008-.004-.018-.01a7.152 7.152 0 0 1-.31-.17 22.055 22.055 0 0 1-3.434-2.414C2.045 10.731 0 8.35 0 5.5 0 2.836 2.086 1 4.25 1 5.797 1 7.153 1.802 8 3.02 8.847 1.802 10.203 1 11.75 1 13.914 1 16 2.836 16 5.5c0 2.85-2.045 5.231-3.885 6.818a22.066 22.066 0 0 1-3.744 2.584l-.018.01-.006.003h-.002ZM4.25 2.5c-1.336 0-2.75 1.164-2.75 3 0 2.15 1.58 4.144 3.365 5.682A20.58 20.58 0 0 0 8 13.393a20.58 20.58 0 0 0 3.135-2.211C12.92 9.644 14.5 7.65 14.5 5.5c0-1.836-1.414-3-2.75-3-1.373 0-2.609.986-3.029 2.456a.749.749 0 0 1-1.442 0C6.859 3.486 5.623 2.5 4.25 2.5Z"></path>
</svg>
</template>

<template id="server-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-server">
    <path d="M1.75 1h12.5c.966 0 1.75.784 1.75 1.75v4c0 .372-.116.717-.314 1 .198.283.314.628.314 1v4a1.75 1.75 0 0 1-1.75 1.75H1.75A1.75 1.75 0 0 1 0 12.75v-4c0-.358.109-.707.314-1a1.739 1.739 0 0 1-.314-1v-4C0 1.784.784 1 1.75 1ZM1.5 2.75v4c0 .138.112.25.25.25h12.5a.25.25 0 0 0 .25-.25v-4a.25.25 0 0 0-.25-.25H1.75a.25.25 0 0 0-.25.25Zm.25 5.75a.25.25 0 0 0-.25.25v4c0 .138.112.25.25.25h12.5a.25.25 0 0 0 .25-.25v-4a.25.25 0 0 0-.25-.25ZM7 4.75A.75.75 0 0 1 7.75 4h4.5a.75.75 0 0 1 0 1.5h-4.5A.75.75 0 0 1 7 4.75ZM7.75 10h4.5a.75.75 0 0 1 0 1.5h-4.5a.75.75 0 0 1 0-1.5ZM3 4.75A.75.75 0 0 1 3.75 4h.5a.75.75 0 0 1 0 1.5h-.5A.75.75 0 0 1 3 4.75ZM3.75 10h.5a.75.75 0 0 1 0 1.5h-.5a.75.75 0 0 1 0-1.5Z"></path>
</svg>
</template>

<template id="globe-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-globe">
    <path d="M8 0a8 8 0 1 1 0 16A8 8 0 0 1 8 0ZM5.78 8.75a9.64 9.64 0 0 0 1.363 4.177c.255.426.542.832.857 1.215.245-.296.551-.705.857-1.215A9.64 9.64 0 0 0 10.22 8.75Zm4.44-1.5a9.64 9.64 0 0 0-1.363-4.177c-.307-.51-.612-.919-.857-1.215a9.927 9.927 0 0 0-.857 1.215A9.64 9.64 0 0 0 5.78 7.25Zm-5.944 1.5H1.543a6.507 6.507 0 0 0 4.666 5.5c-.123-.181-.24-.365-.352-.552-.715-1.192-1.437-2.874-1.581-4.948Zm-2.733-1.5h2.733c.144-2.074.866-3.756 1.58-4.948.12-.197.237-.381.353-.552a6.507 6.507 0 0 0-4.666 5.5Zm10.181 1.5c-.144 2.074-.866 3.756-1.58 4.948-.12.197-.237.381-.353.552a6.507 6.507 0 0 0 4.666-5.5Zm2.733-1.5a6.507 6.507 0 0 0-4.666-5.5c.123.181.24.365.353.552.714 1.192 1.436 2.874 1.58 4.948Z"></path>
</svg>
</template>

<template id="issue-opened-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-issue-opened">
    <path d="M8 9.5a1.5 1.5 0 1 0 0-3 1.5 1.5 0 0 0 0 3Z"></path><path d="M8 0a8 8 0 1 1 0 16A8 8 0 0 1 8 0ZM1.5 8a6.5 6.5 0 1 0 13 0 6.5 6.5 0 0 0-13 0Z"></path>
</svg>
</template>

<template id="device-mobile-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-device-mobile">
    <path d="M3.75 0h8.5C13.216 0 14 .784 14 1.75v12.5A1.75 1.75 0 0 1 12.25 16h-8.5A1.75 1.75 0 0 1 2 14.25V1.75C2 .784 2.784 0 3.75 0ZM3.5 1.75v12.5c0 .138.112.25.25.25h8.5a.25.25 0 0 0 .25-.25V1.75a.25.25 0 0 0-.25-.25h-8.5a.25.25 0 0 0-.25.25ZM8 13a1 1 0 1 1 0-2 1 1 0 0 1 0 2Z"></path>
</svg>
</template>

<template id="package-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-package">
    <path d="m8.878.392 5.25 3.045c.54.314.872.89.872 1.514v6.098a1.75 1.75 0 0 1-.872 1.514l-5.25 3.045a1.75 1.75 0 0 1-1.756 0l-5.25-3.045A1.75 1.75 0 0 1 1 11.049V4.951c0-.624.332-1.201.872-1.514L7.122.392a1.75 1.75 0 0 1 1.756 0ZM7.875 1.69l-4.63 2.685L8 7.133l4.755-2.758-4.63-2.685a.248.248 0 0 0-.25 0ZM2.5 5.677v5.372c0 .09.047.171.125.216l4.625 2.683V8.432Zm6.25 8.271 4.625-2.683a.25.25 0 0 0 .125-.216V5.677L8.75 8.432Z"></path>
</svg>
</template>

<template id="credit-card-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-credit-card">
    <path d="M10.75 9a.75.75 0 0 0 0 1.5h1.5a.75.75 0 0 0 0-1.5h-1.5Z"></path><path d="M0 3.75C0 2.784.784 2 1.75 2h12.5c.966 0 1.75.784 1.75 1.75v8.5A1.75 1.75 0 0 1 14.25 14H1.75A1.75 1.75 0 0 1 0 12.25ZM14.5 6.5h-13v5.75c0 .138.112.25.25.25h12.5a.25.25 0 0 0 .25-.25Zm0-2.75a.25.25 0 0 0-.25-.25H1.75a.25.25 0 0 0-.25.25V5h13Z"></path>
</svg>
</template>

<template id="play-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-play">
    <path d="M8 0a8 8 0 1 1 0 16A8 8 0 0 1 8 0ZM1.5 8a6.5 6.5 0 1 0 13 0 6.5 6.5 0 0 0-13 0Zm4.879-2.773 4.264 2.559a.25.25 0 0 1 0 .428l-4.264 2.559A.25.25 0 0 1 6 10.559V5.442a.25.25 0 0 1 .379-.215Z"></path>
</svg>
</template>

<template id="gift-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-gift">
    <path d="M2 2.75A2.75 2.75 0 0 1 4.75 0c.983 0 1.873.42 2.57 1.232.268.318.497.668.68 1.042.183-.375.411-.725.68-1.044C9.376.42 10.266 0 11.25 0a2.75 2.75 0 0 1 2.45 4h.55c.966 0 1.75.784 1.75 1.75v2c0 .698-.409 1.301-1 1.582v4.918A1.75 1.75 0 0 1 13.25 16H2.75A1.75 1.75 0 0 1 1 14.25V9.332C.409 9.05 0 8.448 0 7.75v-2C0 4.784.784 4 1.75 4h.55c-.192-.375-.3-.8-.3-1.25ZM7.25 9.5H2.5v4.75c0 .138.112.25.25.25h4.5Zm1.5 0v5h4.5a.25.25 0 0 0 .25-.25V9.5Zm0-4V8h5.5a.25.25 0 0 0 .25-.25v-2a.25.25 0 0 0-.25-.25Zm-7 0a.25.25 0 0 0-.25.25v2c0 .138.112.25.25.25h5.5V5.5h-5.5Zm3-4a1.25 1.25 0 0 0 0 2.5h2.309c-.233-.818-.542-1.401-.878-1.793-.43-.502-.915-.707-1.431-.707ZM8.941 4h2.309a1.25 1.25 0 0 0 0-2.5c-.516 0-1 .205-1.43.707-.337.392-.646.975-.879 1.793Z"></path>
</svg>
</template>

<template id="code-square-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-code-square">
    <path d="M0 1.75C0 .784.784 0 1.75 0h12.5C15.216 0 16 .784 16 1.75v12.5A1.75 1.75 0 0 1 14.25 16H1.75A1.75 1.75 0 0 1 0 14.25Zm1.75-.25a.25.25 0 0 0-.25.25v12.5c0 .138.112.25.25.25h12.5a.25.25 0 0 0 .25-.25V1.75a.25.25 0 0 0-.25-.25Zm7.47 3.97a.75.75 0 0 1 1.06 0l2 2a.75.75 0 0 1 0 1.06l-2 2a.749.749 0 0 1-1.275-.326.749.749 0 0 1 .215-.734L10.69 8 9.22 6.53a.75.75 0 0 1 0-1.06ZM6.78 6.53 5.31 8l1.47 1.47a.749.749 0 0 1-.326 1.275.749.749 0 0 1-.734-.215l-2-2a.75.75 0 0 1 0-1.06l2-2a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042Z"></path>
</svg>
</template>

<template id="device-desktop-icon">
  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-device-desktop">
    <path d="M14.25 1c.966 0 1.75.784 1.75 1.75v7.5A1.75 1.75 0 0 1 14.25 12h-3.727c.099 1.041.52 1.872 1.292 2.757A.752.752 0 0 1 11.25 16h-6.5a.75.75 0 0 1-.565-1.243c.772-.885 1.192-1.716 1.292-2.757H1.75A1.75 1.75 0 0 1 0 10.25v-7.5C0 1.784.784 1 1.75 1ZM1.75 2.5a.25.25 0 0 0-.25.25v7.5c0 .138.112.25.25.25h12.5a.25.25 0 0 0 .25-.25v-7.5a.25.25 0 0 0-.25-.25ZM9.018 12H6.982a5.72 5.72 0 0 1-.765 2.5h3.566a5.72 5.72 0 0 1-.765-2.5Z"></path>
</svg>
</template>

        <div class="position-relative">
                        <ul
              role="listbox"
              class="ActionListWrap QueryBuilder-ListWrap"
              aria-label="Suggestions"
              data-action="
                combobox-commit:query-builder#comboboxCommit
                mousedown:query-builder#resultsMousedown
              "
              data-target="query-builder.resultsList"
              data-persist-list=false
              id="query-builder-test-results"
              tabindex="-1"
            ></ul>

        </div>
      <div class="FormControl-inlineValidation" id="validation-e6ff5223-ef54-4908-bd49-01fa0380de94" hidden="hidden">
        <span class="FormControl-inlineValidation--visual">
          <svg aria-hidden="true" height="12" viewBox="0 0 12 12" version="1.1" width="12" data-view-component="true" class="octicon octicon-alert-fill">
    <path d="M4.855.708c.5-.896 1.79-.896 2.29 0l4.675 8.351a1.312 1.312 0 0 1-1.146 1.954H1.33A1.313 1.313 0 0 1 .183 9.058ZM7 7V3H5v4Zm-1 3a1 1 0 1 0 0-2 1 1 0 0 0 0 2Z"></path>
</svg>
        </span>
        <span></span>
</div>    </div>
    <div data-target="query-builder.screenReaderFeedback" aria-live="polite" aria-atomic="true" class="sr-only"></div>
</query-builder></form>
          <div class="d-flex flex-row color-fg-muted tmp-px-3 text-small color-bg-default search-feedback-prompt">
            <a target="_blank" href="https://docs.github.com/search-github/github-code-search/understanding-github-code-search-syntax" data-view-component="true" class="Link color-fg-accent text-normal ml-2 tmp-ml-2">Search syntax tips</a>            <div class="d-flex flex-1"></div>
              <button data-action="click:qbsearch-input#showFeedbackDialog" type="button" data-view-component="true" class="Button--link Button--medium Button color-fg-accent text-normal ml-2 tmp-ml-2">  <span class="Button-content">
    <span class="Button-label">Give feedback</span>
  </span>
</button>
          </div>
        </div>
</div>

    </div>
</modal-dialog></div>
  </div>
  <div data-action="click:qbsearch-input#retract" class="dark-backdrop position-fixed" hidden data-target="qbsearch-input.darkBackdrop"></div>
  <div class="color-fg-default">
    
<dialog-helper>
  <dialog data-target="qbsearch-input.feedbackDialog" data-action="close:qbsearch-input#handleDialogClose cancel:qbsearch-input#handleDialogClose" id="feedback-dialog" aria-modal="true" aria-labelledby="feedback-dialog-title" aria-describedby="feedback-dialog-description" data-view-component="true" class="Overlay Overlay-whenNarrow Overlay--size-medium Overlay--motion-scaleFade Overlay--disableScroll">
    <div data-view-component="true" class="Overlay-header">
  <div class="Overlay-headerContentWrap">
    <div class="Overlay-titleWrap">
      <h1 class="Overlay-title " id="feedback-dialog-title">
        Provide feedback
      </h1>
        
    </div>
    <div class="Overlay-actionWrap">
      <button data-close-dialog-id="feedback-dialog" aria-label="Close" aria-label="Close" type="button" data-view-component="true" class="close-button Overlay-closeButton"><svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-x">
    <path d="M3.72 3.72a.75.75 0 0 1 1.06 0L8 6.94l3.22-3.22a.749.749 0 0 1 1.275.326.749.749 0 0 1-.215.734L9.06 8l3.22 3.22a.749.749 0 0 1-.326 1.275.749.749 0 0 1-.734-.215L8 9.06l-3.22 3.22a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042L6.94 8 3.72 4.78a.75.75 0 0 1 0-1.06Z"></path>
</svg></button>
    </div>
  </div>
  
</div>
      <scrollable-region data-labelled-by="feedback-dialog-title">
        <div data-view-component="true" class="Overlay-body">        <!-- '"` --><!-- </textarea></xmp> --></option></form><form id="code-search-feedback-form" data-turbo="false" action="/search/feedback" accept-charset="UTF-8" method="post"><input type="hidden" name="authenticity_token" value="yMXmR3yqKZYEvelV3DcQ0Ru2R9ongQQxbr2VlkvgQ0hh-009x2IUsRaH8OX8gqHPzgb0rdUsEnS2LvEtKUFNtA" />
          <p>We read every piece of feedback, and take your input very seriously.</p>
          <textarea name="feedback" class="form-control width-full mb-2" style="height: 120px" id="feedback"></textarea>
          <input name="include_email" id="include_email" aria-label="Include my email address so I can be contacted" class="form-control mr-2" type="checkbox">
          <label for="include_email" style="font-weight: normal">Include my email address so I can be contacted</label>
</form></div>
      </scrollable-region>
      <div data-view-component="true" class="Overlay-footer Overlay-footer--alignEnd">          <button data-close-dialog-id="feedback-dialog" type="button" data-view-component="true" class="btn">    Cancel
</button>
          <button form="code-search-feedback-form" data-action="click:qbsearch-input#submitFeedback" type="submit" data-view-component="true" class="btn-primary btn">    Submit feedback
</button>
</div>
</dialog></dialog-helper>

    <custom-scopes data-target="qbsearch-input.customScopesManager">
    
<dialog-helper>
  <dialog data-target="custom-scopes.customScopesModalDialog" data-action="close:qbsearch-input#handleDialogClose cancel:qbsearch-input#handleDialogClose" id="custom-scopes-dialog" aria-modal="true" aria-labelledby="custom-scopes-dialog-title" aria-describedby="custom-scopes-dialog-description" data-view-component="true" class="Overlay Overlay-whenNarrow Overlay--size-medium Overlay--motion-scaleFade Overlay--disableScroll">
    <div data-view-component="true" class="Overlay-header Overlay-header--divided">
  <div class="Overlay-headerContentWrap">
    <div class="Overlay-titleWrap">
      <h1 class="Overlay-title " id="custom-scopes-dialog-title">
        Saved searches
      </h1>
        <h2 id="custom-scopes-dialog-description" class="Overlay-description">Use saved searches to filter your results more quickly</h2>
    </div>
    <div class="Overlay-actionWrap">
      <button data-close-dialog-id="custom-scopes-dialog" aria-label="Close" aria-label="Close" type="button" data-view-component="true" class="close-button Overlay-closeButton"><svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-x">
    <path d="M3.72 3.72a.75.75 0 0 1 1.06 0L8 6.94l3.22-3.22a.749.749 0 0 1 1.275.326.749.749 0 0 1-.215.734L9.06 8l3.22 3.22a.749.749 0 0 1-.326 1.275.749.749 0 0 1-.734-.215L8 9.06l-3.22 3.22a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042L6.94 8 3.72 4.78a.75.75 0 0 1 0-1.06Z"></path>
</svg></button>
    </div>
  </div>
  
</div>
      <scrollable-region data-labelled-by="custom-scopes-dialog-title">
        <div data-view-component="true" class="Overlay-body">        <div data-target="custom-scopes.customScopesModalDialogFlash"></div>

        <div hidden class="create-custom-scope-form" data-target="custom-scopes.createCustomScopeForm">
        <!-- '"` --><!-- </textarea></xmp> --></option></form><form id="custom-scopes-dialog-form" data-turbo="false" action="/search/custom_scopes" accept-charset="UTF-8" method="post"><input type="hidden" name="authenticity_token" value="5sSv04s0Iczz04fRPMgVuUUIvIXG50JdjW9q84oCNacyKBJRBFZlKA4R7FpLaq0y1CElijuoMf-VRzCL0eRXdg" />
          <div data-target="custom-scopes.customScopesModalDialogFlash"></div>

          <input type="hidden" id="custom_scope_id" name="custom_scope_id" data-target="custom-scopes.customScopesIdField">

          <div class="form-group">
            <label for="custom_scope_name">Name</label>
            <auto-check src="/search/custom_scopes/check_name" required>
              <input
                type="text"
                name="custom_scope_name"
                id="custom_scope_name"
                data-target="custom-scopes.customScopesNameField"
                class="form-control"
                autocomplete="off"
                placeholder="github-ruby"
                required
                maxlength="50">
              <input type="hidden" value="XzLGXWvitGktaq3pvo2gPUjVQ3KfQX-VouXc324OL31SOIH4Ausvyeu49VR8vjRXqs_6fp0TXTevFgXgnYQo6w" data-csrf="true" />
            </auto-check>
          </div>

          <div class="form-group">
            <label for="custom_scope_query">Query</label>
            <input
              type="text"
              name="custom_scope_query"
              id="custom_scope_query"
              data-target="custom-scopes.customScopesQueryField"
              class="form-control"
              autocomplete="off"
              placeholder="(repo:mona/a OR repo:mona/b) AND lang:python"
              required
              maxlength="500">
          </div>

          <p class="text-small color-fg-muted">
            To see all available qualifiers, see our <a class="Link--inTextBlock" href="https://docs.github.com/search-github/github-code-search/understanding-github-code-search-syntax">documentation</a>.
          </p>
</form>        </div>

        <div data-target="custom-scopes.manageCustomScopesForm">
          <div data-target="custom-scopes.list"></div>
        </div>

</div>
      </scrollable-region>
      <div data-view-component="true" class="Overlay-footer Overlay-footer--alignEnd Overlay-footer--divided">          <button data-action="click:custom-scopes#customScopesCancel" type="button" data-view-component="true" class="btn">    Cancel
</button>
          <button form="custom-scopes-dialog-form" data-action="click:custom-scopes#customScopesSubmit" data-target="custom-scopes.customScopesSubmitButton" type="submit" data-view-component="true" class="btn-primary btn">    Create saved search
</button>
</div>
</dialog></dialog-helper>
    </custom-scopes>
  </div>
</qbsearch-input>  <input type="hidden" value="fgmcbBJK_DOPbKB4TB42gG7tSg-Izz_CL2MlXMXPeMxtuGzGJo23yvIhivkRyfyNrJ_sPPpNEgTeIOv6wGL6oA" data-csrf="true" class="js-data-jump-to-suggestions-path-csrf" />


      </div>


      <div hidden="hidden" data-view-component="true" class="js-stale-session-flash stale-session-flash flash flash-warn flash-full">
  
        <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-alert">
    <path d="M6.457 1.047c.659-1.234 2.427-1.234 3.086 0l6.082 11.378A1.75 1.75 0 0 1 14.082 15H1.918a1.75 1.75 0 0 1-1.543-2.575Zm1.763.707a.25.25 0 0 0-.44 0L1.698 13.132a.25.25 0 0 0 .22.368h12.164a.25.25 0 0 0 .22-.368Zm.53 3.996v2.5a.75.75 0 0 1-1.5 0v-2.5a.75.75 0 0 1 1.5 0ZM9 11a1 1 0 1 1-2 0 1 1 0 0 1 2 0Z"></path>
</svg>
        <span class="js-stale-session-flash-signed-in" hidden>You signed in with another tab or window. <a class="Link--inTextBlock" href="">Reload</a> to refresh your session.</span>
        <span class="js-stale-session-flash-signed-out" hidden>You signed out in another tab or window. <a class="Link--inTextBlock" href="">Reload</a> to refresh your session.</span>
        <span class="js-stale-session-flash-switched" hidden>You switched accounts on another tab or window. <a class="Link--inTextBlock" href="">Reload</a> to refresh your session.</span>

    <button id="icon-button-eefb269d-3bac-4eaf-8d54-6699f899e181" aria-labelledby="tooltip-1d21735d-d7c9-4cb5-9985-7d12c9918461" type="button" data-view-component="true" class="Button Button--iconOnly Button--invisible Button--medium flash-close js-flash-close">  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-x Button-visual">
    <path d="M3.72 3.72a.75.75 0 0 1 1.06 0L8 6.94l3.22-3.22a.749.749 0 0 1 1.275.326.749.749 0 0 1-.215.734L9.06 8l3.22 3.22a.749.749 0 0 1-.326 1.275.749.749 0 0 1-.734-.215L8 9.06l-3.22 3.22a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042L6.94 8 3.72 4.78a.75.75 0 0 1 0-1.06Z"></path>
</svg>
</button><tool-tip id="tooltip-1d21735d-d7c9-4cb5-9985-7d12c9918461" for="icon-button-eefb269d-3bac-4eaf-8d54-6699f899e181" popover="manual" data-direction="s" data-type="label" data-view-component="true" class="sr-only position-absolute">Dismiss alert</tool-tip>


  
</div>
        
          
    </div>

  <div id="start-of-content" class="show-on-focus"></div>








    <div id="js-flash-container" class="flash-container" data-turbo-replace>




  <template class="js-flash-template">
    
<div class="flash flash-full   {{ className }}">
  <div >
    <button autofocus class="flash-close js-flash-close" type="button" aria-label="Dismiss this message">
      <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-x">
    <path d="M3.72 3.72a.75.75 0 0 1 1.06 0L8 6.94l3.22-3.22a.749.749 0 0 1 1.275.326.749.749 0 0 1-.215.734L9.06 8l3.22 3.22a.749.749 0 0 1-.326 1.275.749.749 0 0 1-.734-.215L8 9.06l-3.22 3.22a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042L6.94 8 3.72 4.78a.75.75 0 0 1 0-1.06Z"></path>
</svg>
    </button>
    <div aria-atomic="true" role="alert" class="js-flash-alert">
      
      <div>{{ message }}</div>

    </div>
  </div>
</div>
  </template>
</div>


    
  <notification-shelf-watcher data-base-url="https://github.com/notifications/beta/shelf" data-channel="eyJjIjoibm90aWZpY2F0aW9uLWNoYW5nZWQ6NDM0NDM0NzAiLCJ0IjoxNzc3MDk5MDA1fQ==--811af1c9761f36d7edde3c8dfde70084d931d6d3b63b9573f0c57a32c4308625" data-view-component="true" class="js-socket-channel"></notification-shelf-watcher>
  <div hidden data-initial data-target="notification-shelf-watcher.placeholder"></div>






  <div
    class="application-main "
    data-commit-hovercards-enabled
    data-discussion-hovercards-enabled
    data-issue-and-pr-hovercards-enabled
    data-project-hovercards-enabled
  >
      <main>
        
<x-banner data-dismiss-scheme="none" data-view-component="true">
  <div hidden="hidden" data-view-component="true" class="js-user-status-banner Banner flash Banner--full flash-full">
      <div class="Banner-visual">
        <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-info">
    <path d="M0 8a8 8 0 1 1 16 0A8 8 0 0 1 0 8Zm8-6.5a6.5 6.5 0 1 0 0 13 6.5 6.5 0 0 0 0-13ZM6.5 7.75A.75.75 0 0 1 7.25 7h1a.75.75 0 0 1 .75.75v2.75h.25a.75.75 0 0 1 0 1.5h-2a.75.75 0 0 1 0-1.5h.25v-2h-.25a.75.75 0 0 1-.75-.75ZM8 6a1 1 0 1 1 0-2 1 1 0 0 1 0 2Z"></path>
</svg>
      </div>
    <div data-view-component="true" class="Banner-message">
      <p class="Banner-title" data-target="x-banner.titleText">
  <span class="js-user-status-banner-message"></span>
</p>
</div></div></x-banner>

<div class="container-xl tmp-px-3 tmp-px-md-4 tmp-px-lg-5 mt-2">
  <div data-view-component="true" class="Layout Layout--flowRow-until-md Layout--sidebarPosition-start Layout--sidebarPosition-flowRow-start">
  
  <div data-view-component="true" class="Layout-sidebar">      <div
        class="h-card tmp-mt-5"
        data-acv-badge-hovercards-enabled
        itemscope
        itemtype="http://schema.org/Person"
      >

          <div class="js-profile-editable-replace">
  <div class="clearfix d-flex d-md-block flex-items-center tmp-mb-4 tmp-mb-md-0">
    <div
      class="position-relative d-inline-block col-2 col-md-12 tmp-mr-3 tmp-mr-md-0 flex-shrink-0"
      style="z-index:4;"
    >
        <span data-view-component="true" class="position-relative"><a aria-label="Change your avatar" data-hydro-click="{&quot;event_type&quot;:&quot;user_profile.click&quot;,&quot;payload&quot;:{&quot;profile_user_id&quot;:43443470,&quot;target&quot;:&quot;EDIT_AVATAR&quot;,&quot;user_id&quot;:43443470,&quot;originating_url&quot;:&quot;https://github.com/greydoubt&quot;}}" data-hydro-click-hmac="3ef8b194ae522e1b95f204e858d8862b0751b06d88cae8c0a2126743cb879b9f" id="upload-avatar-link" href="https://github.com/account" data-view-component="true" class="Link d-block"><img style="height:auto;" alt="" src="https://avatars.githubusercontent.com/u/43443470?v=4" width="260" height="260" class="avatar avatar-user width-full border color-bg-default" /></a>  <tool-tip id="tooltip-6849f92d-6e52-435c-a578-fe326cf98006" for="upload-avatar-link" popover="manual" data-direction="s" data-type="description" data-view-component="true" class="sr-only position-absolute">Change your avatar</tool-tip></span>      
  <div class="user-status-container position-relative hide-sm hide-md">
    
    <div
      class="f5 js-user-status-context user-status-circle-badge-container user-status-editable"
      data-url="/users/status?circle=1&amp;compact=0&amp;link_mentions=1&amp;truncate=0"
    >
      
<div
  class="js-user-status-context"
  data-url="/users/status?circle=1&amp;compact=0&amp;link_mentions=1&amp;truncate=0"
>
  <div class="js-user-status-container user-status-circle-badge d-inline-block lh-condensed-ultra p-2 user-status-busy border color-border-attention-emphasis"
    
    data-team-hovercards-enabled>
    
<react-partial-anchor>
  <button role="button" data-target="react-partial-anchor.anchor" type="button" data-view-component="true" class="Link--secondary no-underline min-width-0 Button--link Button--medium Button d-block">  <span class="Button-content">
    <span class="Button-label"><div class="d-flex flex-items-center flex-items-stretch">
  <div class="f6 lh-condensed user-status-header d-inline-flex">
    <div class="user-status-emoji-container flex-shrink-0 mr-2 d-flex flex-items-center flex-justify-center ">
      <g-emoji alias="thought_balloon" tone="3">💭</g-emoji>
    </div>
  </div>
  <div class="user-status-message-wrapper f6 min-width-0 ws-normal" >
    <div class="css-truncate css-truncate-target width-fit color-fg-default">
        <div class="color-fg-default text-bold f6">
        </div>
          <span><div>youll never love me the way my daddy Hades loved me</div></span>
    </div>
  </div>
</div></span>
  </span>
</button>
  <template data-target="react-partial-anchor.template">
    <link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/primer-react-css.1836171ca9039b48.module.css" />
<link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/user-status-dialog.f3ce788adaab9afb.module.css" />

<react-partial
  partial-name="user-status-dialog"
  data-ssr="false"
  data-attempted-ssr="false"
  data-react-profiling="false"
>
  
  <script type="application/json" data-target="react-partial.embeddedData">{"props":{"userPreferences":{"tone":3},"userStatusData":{"messageHtml":"\u003cdiv\u003eyoull never love me the way my daddy Hades loved me\u003c/div\u003e","message":"youll never love me the way my daddy Hades loved me","limitedAvailability":true,"expiresAt":null,"expiresIn":null,"organizationOptions":[{"label":"EpicGames","value":6615685,"globalRelayId":"MDEyOk9yZ2FuaXphdGlvbjY2MTU2ODU="}],"suggestions":[{"message":"On vacation","emojiAttributes":{"tag":"g-emoji","imgPath":"https://github.githubassets.com/assets/1f334-453759c3779f.png","attributes":{"alias":"palm_tree","fallback-src":"https://github.githubassets.com/assets/1f334-453759c3779f.png","class":"emoji","align":"absmiddle"},"name":"palm_tree","raw":"🌴"}},{"message":"Out sick","emojiAttributes":{"tag":"g-emoji","imgPath":"https://github.githubassets.com/assets/1f912-e44df2e127d9.png","attributes":{"alias":"face_with_thermometer","fallback-src":"https://github.githubassets.com/assets/1f912-e44df2e127d9.png","class":"emoji","align":"absmiddle"},"name":"face_with_thermometer","raw":"🤒"}},{"message":"Working from home","emojiAttributes":{"tag":"g-emoji","imgPath":"https://github.githubassets.com/assets/1f3e0-04e67e699536.png","attributes":{"alias":"house","fallback-src":"https://github.githubassets.com/assets/1f3e0-04e67e699536.png","class":"emoji","align":"absmiddle"},"name":"house","raw":"🏠"}},{"message":"Focusing","emojiAttributes":{"tag":"g-emoji","imgPath":"https://github.githubassets.com/assets/1f3af-c334ccb56185.png","attributes":{"alias":"dart","fallback-src":"https://github.githubassets.com/assets/1f3af-c334ccb56185.png","class":"emoji","align":"absmiddle"},"name":"dart","raw":"🎯"}}],"expirationIntervals":[{"label":"in 30 minutes","time":"2026-04-25T00:06:45-07:00"},{"label":"in 1 hour","time":"2026-04-25T00:36:45-07:00"},{"label":"in 4 hours","time":"2026-04-25T03:36:45-07:00"},{"label":"after today","time":"2026-04-24T23:59:59-07:00"},{"label":"after this week","time":"2026-04-26T23:59:59-07:00"},{"label":"after a month","time":"2026-05-24T23:36:45-07:00"}]}}}</script>
  <div data-target="react-partial.reactRoot"></div>
</react-partial>


  </template>
</react-partial-anchor>

  </div>
</div>

    </div>
  </div>

    </div>

    <div
      class="vcard-names-container float-left js-profile-editable-names col-12 tmp-py-3"
    >
      <h1 class="vcard-names ">
        <span class="p-name vcard-fullname d-block overflow-hidden" itemprop="name">
           λx . ophidia ereц grex⋆. 𐙚 ̊      .    أوفيديا إريكس جريكس   .
        </span>
        <span class="p-nickname vcard-username d-block" itemprop="additionalName">
          greydoubt

            &middot;
            <span itemprop="pronouns">bc1q63llmqp5umkzrgpumjfudh6fwgyf97c46ngc9f</span>
        </span>
      </h1>
    </div>
  </div>

    <div
    class="mb-2 user-status-container d-md-none js-user-status-context"
    data-url="/users/status?circle=0&amp;compact=1&amp;link_mentions=1&amp;truncate=1"
  >
    
<div
  class="js-user-status-context"
  data-url="/users/status?circle=0&amp;compact=1&amp;link_mentions=1&amp;truncate=0"
>
  <div class="js-user-status-container rounded-2 px-2 py-1 mt-2 user-status-busy border color-border-attention-emphasis"
    
    data-team-hovercards-enabled>
    
<react-partial-anchor>
  <button role="button" data-target="react-partial-anchor.anchor" type="button" data-view-component="true" class="Link--secondary no-underline min-width-0 Button--link Button--medium Button d-block">  <span class="Button-content">
    <span class="Button-label"><div class="d-flex flex-items-center flex-items-stretch">
  <div class="f6 lh-condensed user-status-header d-inline-flex">
    <div class="user-status-emoji-container flex-shrink-0 mr-2 d-flex flex-items-center flex-justify-center ">
      <g-emoji alias="thought_balloon" tone="3">💭</g-emoji>
    </div>
  </div>
  <div class="user-status-message-wrapper f6 min-width-0"  style="line-height: 20px;" >
    <div class="css-truncate css-truncate-target width-fit color-fg-default text-left">
        <div class="color-fg-default text-bold f6">
        </div>
          <span><div>youll never love me the way my daddy Hades loved me</div></span>
    </div>
  </div>
</div></span>
  </span>
</button>
  <template data-target="react-partial-anchor.template">
    <link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/primer-react-css.1836171ca9039b48.module.css" />
<link crossorigin="anonymous" media="all" rel="stylesheet" href="https://github.githubassets.com/assets/user-status-dialog.f3ce788adaab9afb.module.css" />

<react-partial
  partial-name="user-status-dialog"
  data-ssr="false"
  data-attempted-ssr="false"
  data-react-profiling="false"
>
  
  <script type="application/json" data-target="react-partial.embeddedData">{"props":{"userPreferences":{"tone":3},"userStatusData":{"messageHtml":"\u003cdiv\u003eyoull never love me the way my daddy Hades loved me\u003c/div\u003e","message":"youll never love me the way my daddy Hades loved me","limitedAvailability":true,"expiresAt":null,"expiresIn":null,"organizationOptions":[{"label":"EpicGames","value":6615685,"globalRelayId":"MDEyOk9yZ2FuaXphdGlvbjY2MTU2ODU="}],"suggestions":[{"message":"On vacation","emojiAttributes":{"tag":"g-emoji","imgPath":"https://github.githubassets.com/assets/1f334-453759c3779f.png","attributes":{"alias":"palm_tree","fallback-src":"https://github.githubassets.com/assets/1f334-453759c3779f.png","class":"emoji","align":"absmiddle"},"name":"palm_tree","raw":"🌴"}},{"message":"Out sick","emojiAttributes":{"tag":"g-emoji","imgPath":"https://github.githubassets.com/assets/1f912-e44df2e127d9.png","attributes":{"alias":"face_with_thermometer","fallback-src":"https://github.githubassets.com/assets/1f912-e44df2e127d9.png","class":"emoji","align":"absmiddle"},"name":"face_with_thermometer","raw":"🤒"}},{"message":"Working from home","emojiAttributes":{"tag":"g-emoji","imgPath":"https://github.githubassets.com/assets/1f3e0-04e67e699536.png","attributes":{"alias":"house","fallback-src":"https://github.githubassets.com/assets/1f3e0-04e67e699536.png","class":"emoji","align":"absmiddle"},"name":"house","raw":"🏠"}},{"message":"Focusing","emojiAttributes":{"tag":"g-emoji","imgPath":"https://github.githubassets.com/assets/1f3af-c334ccb56185.png","attributes":{"alias":"dart","fallback-src":"https://github.githubassets.com/assets/1f3af-c334ccb56185.png","class":"emoji","align":"absmiddle"},"name":"dart","raw":"🎯"}}],"expirationIntervals":[{"label":"in 30 minutes","time":"2026-04-25T00:06:45-07:00"},{"label":"in 1 hour","time":"2026-04-25T00:36:45-07:00"},{"label":"in 4 hours","time":"2026-04-25T03:36:45-07:00"},{"label":"after today","time":"2026-04-24T23:59:59-07:00"},{"label":"after this week","time":"2026-04-26T23:59:59-07:00"},{"label":"after a month","time":"2026-05-24T23:36:45-07:00"}]}}}</script>
  <div data-target="react-partial.reactRoot"></div>
</react-partial>


  </template>
</react-partial-anchor>

  </div>
</div>

  </div>


  <div class="d-flex flex-column">
    <div class="flex-order-1 flex-md-order-none">
        <div class="d-flex flex-lg-row flex-md-column">
        </div>


          <waiting-form>
  <!-- '"` --><!-- </textarea></xmp> --></option></form><form hidden="hidden" class="position-relative flex-auto js-profile-editable-form" data-target="waiting-form.form" data-turbo="false" action="/users/greydoubt" accept-charset="UTF-8" method="post"><input type="hidden" name="_method" value="put" autocomplete="off" /><input type="hidden" name="authenticity_token" value="BpsYjcZlLWvoP8Bk8-UbBIPgTxApzuT6Tp5ecsvBtKNp0eurDpBoY1h76IzIb0880zBSrXTCTE4e4IdQgUby-g" />
      <div class="mb-1 mb-2">
        <label for="user_profile_name" class="d-block mb-1">Name</label>
        <input class="width-full form-control" id="user_profile_name" placeholder="Name" aria-label="Name" name="user[profile_name]" value=" λx . ophidia ereц grex⋆. 𐙚 ̊      .    أوفيديا إريكس جريكس   .">
      </div>


    <div class="js-length-limited-input-container">
      <label for="user_profile_bio" class="d-block mb-1">Bio</label>
      <text-expander keys=": @" data-emoji-url="/autocomplete/emoji" data-mention-url="/autocomplete/user-suggestions">
        <textarea
          class="form-control js-length-limited-input mb-1 width-full js-user-profile-bio-edit"
          id="user_profile_bio"
          name="user[profile_bio]"
          placeholder="Add a bio"
          aria-label="Add a bio"
          rows="3"
          data-input-max-length="160"
          data-warning-text="{{remaining}} remaining">#エメラダ 🛸　.　　•.  　🌎　°　.•　🌓　•　　.°•　　•　🚀 ✯.    •.    .  •. 
　.　•　★　*　　　　　°　　.　　🛰 　°·　　•.      ๏        .•       🪐
.　•　•　° ★　•  ☄.       ๏       •.      .  •</textarea>
        <div class="d-none js-length-limited-input-warning user-profile-bio-message text-right m-0"></div>
      </text-expander>
      <p class="note">
        You can <strong>@mention</strong> other users and organizations to link to them.
      </p>
    </div>

      <div class="mt-1 tmp-mb-3">
        <label for="user_profile_pronouns" class="d-block mb-1">Pronouns</label>
        <select name="user[profile_pronouns]" id="user_profile_pronouns" class="form-select js-profile-editable-pronouns-select form-control width-full"><option value="">Don&#39;t specify</option>
<option value="they/them">they/them</option>
<option value="she/her">she/her</option>
<option value="he/him">he/him</option>
<option selected="selected" value="Custom">Custom</option></select>
        <input
          class="js-profile-editable-pronouns-custom mt-2 form-control width-full"
          placeholder="Pronouns"
          aria-label="Pronouns"
          name="user[profile_pronouns]"
          value="bc1q63llmqp5umkzrgpumjfudh6fwgyf97c46ngc9f"
          data-initial-value="bc1q63llmqp5umkzrgpumjfudh6fwgyf97c46ngc9f"
          
        >
      </div>

        <div class="color-fg-muted mt-2 d-flex flex-items-center">
          <svg style="width: 16px;" aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-organization">
    <path d="M1.75 16A1.75 1.75 0 0 1 0 14.25V1.75C0 .784.784 0 1.75 0h8.5C11.216 0 12 .784 12 1.75v12.5c0 .085-.006.168-.018.25h2.268a.25.25 0 0 0 .25-.25V8.285a.25.25 0 0 0-.111-.208l-1.055-.703a.749.749 0 1 1 .832-1.248l1.055.703c.487.325.779.871.779 1.456v5.965A1.75 1.75 0 0 1 14.25 16h-3.5a.766.766 0 0 1-.197-.026c-.099.017-.2.026-.303.026h-3a.75.75 0 0 1-.75-.75V14h-1v1.25a.75.75 0 0 1-.75.75Zm-.25-1.75c0 .138.112.25.25.25H4v-1.25a.75.75 0 0 1 .75-.75h2.5a.75.75 0 0 1 .75.75v1.25h2.25a.25.25 0 0 0 .25-.25V1.75a.25.25 0 0 0-.25-.25h-8.5a.25.25 0 0 0-.25.25ZM3.75 6h.5a.75.75 0 0 1 0 1.5h-.5a.75.75 0 0 1 0-1.5ZM3 3.75A.75.75 0 0 1 3.75 3h.5a.75.75 0 0 1 0 1.5h-.5A.75.75 0 0 1 3 3.75Zm4 3A.75.75 0 0 1 7.75 6h.5a.75.75 0 0 1 0 1.5h-.5A.75.75 0 0 1 7 6.75ZM7.75 3h.5a.75.75 0 0 1 0 1.5h-.5a.75.75 0 0 1 0-1.5ZM3 9.75A.75.75 0 0 1 3.75 9h.5a.75.75 0 0 1 0 1.5h-.5A.75.75 0 0 1 3 9.75ZM7.75 9h.5a.75.75 0 0 1 0 1.5h-.5a.75.75 0 0 1 0-1.5Z"></path>
</svg>
          <input class="ml-2 form-control flex-auto input-sm" placeholder="Company" aria-label="Company" name="user[profile_company]" value="#エメラダ">
        </div>

    <div class="color-fg-muted mt-2 d-flex flex-items-center">
      <svg style="width: 16px;" aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-location">
    <path d="m12.596 11.596-3.535 3.536a1.5 1.5 0 0 1-2.122 0l-3.535-3.536a6.5 6.5 0 1 1 9.192-9.193 6.5 6.5 0 0 1 0 9.193Zm-1.06-8.132v-.001a5 5 0 1 0-7.072 7.072L8 14.07l3.536-3.534a5 5 0 0 0 0-7.072ZM8 9a2 2 0 1 1-.001-3.999A2 2 0 0 1 8 9Z"></path>
</svg>
      <input class="ml-2 form-control flex-auto input-sm" placeholder="Location" aria-label="Location" name="user[profile_location]" value="Orion Cluster, Planet Hades, Martian Sector">
    </div>

    <div class="color-fg-muted mt-2 d-flex flex-items-center flex-wrap">
      <svg style="width: 16px;" aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-clock">
    <path d="M8 0a8 8 0 1 1 0 16A8 8 0 0 1 8 0ZM1.5 8a6.5 6.5 0 1 0 13 0 6.5 6.5 0 0 0-13 0Zm7-3.25v2.992l2.028.812a.75.75 0 0 1-.557 1.392l-2.5-1A.751.751 0 0 1 7 8.25v-3.5a.75.75 0 0 1 1.5 0Z"></path>
</svg>
      <input type="checkbox" name="user[profile_display_local_time_zone]" id="user_profile_display_local_time_zone" value="1" class="ml-2 form-control form-checkbox-details-trigger" checked="checked" />
      <label for="user_profile_display_local_time_zone" class="ml-1">Display current local time</label>
      <div class="form-checkbox-details tmp-mr-4 mt-1">
        <select class="form-select tmp-ml-4 flex-auto select-sm width-full" aria-label="Time zone" name="user[profile_local_time_zone_name]" id="user_profile_local_time_zone_name"><option value="International Date Line West">(GMT-12:00) International Date Line West</option>
<option value="American Samoa">(GMT-11:00) American Samoa</option>
<option value="Midway Island">(GMT-11:00) Midway Island</option>
<option value="Hawaii">(GMT-10:00) Hawaii</option>
<option value="Alaska">(GMT-09:00) Alaska</option>
<option value="Pacific Time (US &amp; Canada)">(GMT-08:00) Pacific Time (US &amp; Canada)</option>
<option value="Tijuana">(GMT-08:00) Tijuana</option>
<option value="Arizona">(GMT-07:00) Arizona</option>
<option value="Mazatlan">(GMT-07:00) Mazatlan</option>
<option value="Mountain Time (US &amp; Canada)">(GMT-07:00) Mountain Time (US &amp; Canada)</option>
<option value="Central America">(GMT-06:00) Central America</option>
<option value="Central Time (US &amp; Canada)">(GMT-06:00) Central Time (US &amp; Canada)</option>
<option value="Chihuahua">(GMT-06:00) Chihuahua</option>
<option value="Guadalajara">(GMT-06:00) Guadalajara</option>
<option value="Mexico City">(GMT-06:00) Mexico City</option>
<option value="Monterrey">(GMT-06:00) Monterrey</option>
<option value="Saskatchewan">(GMT-06:00) Saskatchewan</option>
<option value="Bogota">(GMT-05:00) Bogota</option>
<option value="Eastern Time (US &amp; Canada)">(GMT-05:00) Eastern Time (US &amp; Canada)</option>
<option value="Indiana (East)">(GMT-05:00) Indiana (East)</option>
<option value="Lima">(GMT-05:00) Lima</option>
<option value="Quito">(GMT-05:00) Quito</option>
<option value="Atlantic Time (Canada)">(GMT-04:00) Atlantic Time (Canada)</option>
<option value="Caracas">(GMT-04:00) Caracas</option>
<option value="Georgetown">(GMT-04:00) Georgetown</option>
<option value="La Paz">(GMT-04:00) La Paz</option>
<option value="Puerto Rico">(GMT-04:00) Puerto Rico</option>
<option value="Santiago">(GMT-04:00) Santiago</option>
<option value="Newfoundland">(GMT-03:30) Newfoundland</option>
<option value="Asuncion">(GMT-03:00) Asuncion</option>
<option value="Brasilia">(GMT-03:00) Brasilia</option>
<option value="Buenos Aires">(GMT-03:00) Buenos Aires</option>
<option value="Montevideo">(GMT-03:00) Montevideo</option>
<option value="Greenland">(GMT-02:00) Greenland</option>
<option selected="selected" value="Mid-Atlantic">(GMT-02:00) Mid-Atlantic</option>
<option value="Azores">(GMT-01:00) Azores</option>
<option value="Cape Verde Is.">(GMT-01:00) Cape Verde Is.</option>
<option value="Edinburgh">(GMT+00:00) Edinburgh</option>
<option value="Lisbon">(GMT+00:00) Lisbon</option>
<option value="London">(GMT+00:00) London</option>
<option value="Monrovia">(GMT+00:00) Monrovia</option>
<option value="UTC">(GMT+00:00) UTC</option>
<option value="Amsterdam">(GMT+01:00) Amsterdam</option>
<option value="Belgrade">(GMT+01:00) Belgrade</option>
<option value="Berlin">(GMT+01:00) Berlin</option>
<option value="Bern">(GMT+01:00) Bern</option>
<option value="Bratislava">(GMT+01:00) Bratislava</option>
<option value="Brussels">(GMT+01:00) Brussels</option>
<option value="Budapest">(GMT+01:00) Budapest</option>
<option value="Casablanca">(GMT+01:00) Casablanca</option>
<option value="Copenhagen">(GMT+01:00) Copenhagen</option>
<option value="Dublin">(GMT+01:00) Dublin</option>
<option value="Ljubljana">(GMT+01:00) Ljubljana</option>
<option value="Madrid">(GMT+01:00) Madrid</option>
<option value="Paris">(GMT+01:00) Paris</option>
<option value="Prague">(GMT+01:00) Prague</option>
<option value="Rome">(GMT+01:00) Rome</option>
<option value="Sarajevo">(GMT+01:00) Sarajevo</option>
<option value="Skopje">(GMT+01:00) Skopje</option>
<option value="Stockholm">(GMT+01:00) Stockholm</option>
<option value="Vienna">(GMT+01:00) Vienna</option>
<option value="Warsaw">(GMT+01:00) Warsaw</option>
<option value="West Central Africa">(GMT+01:00) West Central Africa</option>
<option value="Zagreb">(GMT+01:00) Zagreb</option>
<option value="Zurich">(GMT+01:00) Zurich</option>
<option value="Athens">(GMT+02:00) Athens</option>
<option value="Bucharest">(GMT+02:00) Bucharest</option>
<option value="Cairo">(GMT+02:00) Cairo</option>
<option value="Harare">(GMT+02:00) Harare</option>
<option value="Helsinki">(GMT+02:00) Helsinki</option>
<option value="Jerusalem">(GMT+02:00) Jerusalem</option>
<option value="Kaliningrad">(GMT+02:00) Kaliningrad</option>
<option value="Kyiv">(GMT+02:00) Kyiv</option>
<option value="Pretoria">(GMT+02:00) Pretoria</option>
<option value="Riga">(GMT+02:00) Riga</option>
<option value="Sofia">(GMT+02:00) Sofia</option>
<option value="Tallinn">(GMT+02:00) Tallinn</option>
<option value="Vilnius">(GMT+02:00) Vilnius</option>
<option value="Baghdad">(GMT+03:00) Baghdad</option>
<option value="Istanbul">(GMT+03:00) Istanbul</option>
<option value="Kuwait">(GMT+03:00) Kuwait</option>
<option value="Minsk">(GMT+03:00) Minsk</option>
<option value="Moscow">(GMT+03:00) Moscow</option>
<option value="Nairobi">(GMT+03:00) Nairobi</option>
<option value="Riyadh">(GMT+03:00) Riyadh</option>
<option value="St. Petersburg">(GMT+03:00) St. Petersburg</option>
<option value="Volgograd">(GMT+03:00) Volgograd</option>
<option value="Tehran">(GMT+03:30) Tehran</option>
<option value="Abu Dhabi">(GMT+04:00) Abu Dhabi</option>
<option value="Baku">(GMT+04:00) Baku</option>
<option value="Muscat">(GMT+04:00) Muscat</option>
<option value="Samara">(GMT+04:00) Samara</option>
<option value="Tbilisi">(GMT+04:00) Tbilisi</option>
<option value="Yerevan">(GMT+04:00) Yerevan</option>
<option value="Kabul">(GMT+04:30) Kabul</option>
<option value="Almaty">(GMT+05:00) Almaty</option>
<option value="Astana">(GMT+05:00) Astana</option>
<option value="Ekaterinburg">(GMT+05:00) Ekaterinburg</option>
<option value="Islamabad">(GMT+05:00) Islamabad</option>
<option value="Karachi">(GMT+05:00) Karachi</option>
<option value="Tashkent">(GMT+05:00) Tashkent</option>
<option value="Chennai">(GMT+05:30) Chennai</option>
<option value="Kolkata">(GMT+05:30) Kolkata</option>
<option value="Mumbai">(GMT+05:30) Mumbai</option>
<option value="New Delhi">(GMT+05:30) New Delhi</option>
<option value="Sri Jayawardenepura">(GMT+05:30) Sri Jayawardenepura</option>
<option value="Kathmandu">(GMT+05:45) Kathmandu</option>
<option value="Dhaka">(GMT+06:00) Dhaka</option>
<option value="Urumqi">(GMT+06:00) Urumqi</option>
<option value="Rangoon">(GMT+06:30) Rangoon</option>
<option value="Bangkok">(GMT+07:00) Bangkok</option>
<option value="Hanoi">(GMT+07:00) Hanoi</option>
<option value="Jakarta">(GMT+07:00) Jakarta</option>
<option value="Krasnoyarsk">(GMT+07:00) Krasnoyarsk</option>
<option value="Novosibirsk">(GMT+07:00) Novosibirsk</option>
<option value="Beijing">(GMT+08:00) Beijing</option>
<option value="Chongqing">(GMT+08:00) Chongqing</option>
<option value="Hong Kong">(GMT+08:00) Hong Kong</option>
<option value="Irkutsk">(GMT+08:00) Irkutsk</option>
<option value="Kuala Lumpur">(GMT+08:00) Kuala Lumpur</option>
<option value="Perth">(GMT+08:00) Perth</option>
<option value="Singapore">(GMT+08:00) Singapore</option>
<option value="Taipei">(GMT+08:00) Taipei</option>
<option value="Ulaanbaatar">(GMT+08:00) Ulaanbaatar</option>
<option value="Osaka">(GMT+09:00) Osaka</option>
<option value="Sapporo">(GMT+09:00) Sapporo</option>
<option value="Seoul">(GMT+09:00) Seoul</option>
<option value="Tokyo">(GMT+09:00) Tokyo</option>
<option value="Yakutsk">(GMT+09:00) Yakutsk</option>
<option value="Adelaide">(GMT+09:30) Adelaide</option>
<option value="Darwin">(GMT+09:30) Darwin</option>
<option value="Brisbane">(GMT+10:00) Brisbane</option>
<option value="Canberra">(GMT+10:00) Canberra</option>
<option value="Guam">(GMT+10:00) Guam</option>
<option value="Hobart">(GMT+10:00) Hobart</option>
<option value="Melbourne">(GMT+10:00) Melbourne</option>
<option value="Port Moresby">(GMT+10:00) Port Moresby</option>
<option value="Sydney">(GMT+10:00) Sydney</option>
<option value="Vladivostok">(GMT+10:00) Vladivostok</option>
<option value="Magadan">(GMT+11:00) Magadan</option>
<option value="New Caledonia">(GMT+11:00) New Caledonia</option>
<option value="Solomon Is.">(GMT+11:00) Solomon Is.</option>
<option value="Srednekolymsk">(GMT+11:00) Srednekolymsk</option>
<option value="Auckland">(GMT+12:00) Auckland</option>
<option value="Fiji">(GMT+12:00) Fiji</option>
<option value="Kamchatka">(GMT+12:00) Kamchatka</option>
<option value="Marshall Is.">(GMT+12:00) Marshall Is.</option>
<option value="Wellington">(GMT+12:00) Wellington</option>
<option value="Chatham Is.">(GMT+12:45) Chatham Is.</option>
<option value="Nuku&#39;alofa">(GMT+13:00) Nuku&#39;alofa</option>
<option value="Samoa">(GMT+13:00) Samoa</option>
<option value="Tokelau Is.">(GMT+13:00) Tokelau Is.</option></select>
      </div>
    </div>


    <div class="color-fg-muted mt-2 d-flex flex-items-center">
      <svg style="width: 16px;" aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-link">
    <path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path>
</svg>
      <input class="ml-2 form-control flex-auto input-sm" placeholder="Website" aria-label="Website" name="user[profile_blog]" value="https://x.com/greydoubt">
    </div>


    <div class="mt-2 tmp-mb-3">
      <label class="d-block mb-1">Social accounts</label>

        <social-account-editor
    data-nodeinfo-software-url="/settings/nodeinfo_software"
    data-targets="waiting-form.prerequisites"
    data-waiting-form-method="waitForRecognition"
  >
    <div class="color-fg-muted mt-2 d-flex flex-items-center">
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="facebook"
        >
          <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 15.3 15.4" role="img" aria-labelledby="ak3fe7clx410i63mjbgz8wppfnofgd0m" class="octicon" width="16" height="16"><title id="ak3fe7clx410i63mjbgz8wppfnofgd0m">Facebook</title><path d="M14.5 0H.8a.88.88 0 0 0-.8.9v13.6a.88.88 0 0 0 .8.9h7.3v-6h-2V7.1h2V5.4a2.87 2.87 0 0 1 2.5-3.1h.5a10.87 10.87 0 0 1 1.8.1v2.1h-1.3c-1 0-1.1.5-1.1 1.1v1.5h2.3l-.3 2.3h-2v5.9h3.9a.88.88 0 0 0 .9-.8V.8a.86.86 0 0 0-.8-.8z" fill="currentColor"></path></svg>
            <span class="d-none" data-provider-pattern="^https://(?:[^.]+\.)?facebook\.com/(?:[^/?]+/?|profile\.php\?id=\d+)$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="hometown"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="ag9zrxkmwv1ddbodjeodigotdount2rh" class="octicon"><title id="ag9zrxkmwv1ddbodjeodigotdount2rh">Hometown</title>
<path d="M8.29202 0.000202252C6.27825 0.00837918 4.27877 0.264357 3.23839 0.744626C3.23839 0.744626 1 1.76482 1 5.23985C1 9.37638 0.997 14.5711 4.70851 15.5757C6.12991 15.9582 7.35227 16.0405 8.33499 15.9838C10.1184 15.883 11.0005 15.3359 11.0005 15.3359L10.9406 14.0165C10.9406 14.0165 9.78462 14.4244 8.35322 14.3776C6.93515 14.3276 5.44121 14.221 5.20853 12.4481C5.1872 12.2832 5.17662 12.1163 5.17728 11.9501C8.18209 12.697 10.7444 12.2754 11.4497 12.19C13.4191 11.9503 15.1336 10.7139 15.3522 9.58385C15.6949 7.80294 15.6661 5.23985 15.6661 5.23985C15.6661 1.76482 13.4316 0.744626 13.4316 0.744626C12.3345 0.231649 10.3058 -0.00797468 8.29202 0.000202252ZM6.13696 2.65066C6.82691 2.66919 7.5087 2.97824 7.92872 3.63106L8.33499 4.32203L8.73995 3.63106C9.58333 2.31808 11.4736 2.40001 12.3729 3.41595C13.2023 4.3825 13.0175 5.00632 13.0175 9.32441V9.32571H11.3859V5.56839C11.3859 3.80952 9.14622 3.74159 9.14622 5.81219V7.9894H7.52505V5.81219C7.52505 3.74159 5.28666 3.80821 5.28666 5.56709V9.32441H3.65117C3.65117 5.00298 3.46969 4.37515 4.29573 3.41595C4.74875 2.90464 5.44701 2.63214 6.13696 2.65066Z" fill="currentColor"></path>
</svg>
              <span
                class="d-none"
                data-try-nodeinfo-pattern="^https?://([^/]+)/@([^/?]+)/?$"
                data-nodeinfo-software="hometown"
              ></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="instagram"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="aqskah1ukc4htohvocj3w04ebs3whuyz" class="octicon"><title id="aqskah1ukc4htohvocj3w04ebs3whuyz">Instagram</title>
<g clip-path="url(#clip0_202_91849)">
<path d="M4.66536 0C2.0927 0 0 2.09464 0 4.66797V11.3346C0 13.9073 2.09464 16 4.66797 16H11.3346C13.9073 16 16 13.9054 16 11.332V4.66536C16 2.0927 13.9054 0 11.332 0H4.66536ZM12.6667 2.66667C13.0347 2.66667 13.3333 2.96533 13.3333 3.33333C13.3333 3.70133 13.0347 4 12.6667 4C12.2987 4 12 3.70133 12 3.33333C12 2.96533 12.2987 2.66667 12.6667 2.66667ZM8 4C10.206 4 12 5.794 12 8C12 10.206 10.206 12 8 12C5.794 12 4 10.206 4 8C4 5.794 5.794 4 8 4ZM8 5.33333C7.29276 5.33333 6.61448 5.61428 6.11438 6.11438C5.61428 6.61448 5.33333 7.29276 5.33333 8C5.33333 8.70724 5.61428 9.38552 6.11438 9.88562C6.61448 10.3857 7.29276 10.6667 8 10.6667C8.70724 10.6667 9.38552 10.3857 9.88562 9.88562C10.3857 9.38552 10.6667 8.70724 10.6667 8C10.6667 7.29276 10.3857 6.61448 9.88562 6.11438C9.38552 5.61428 8.70724 5.33333 8 5.33333V5.33333Z" fill="currentColor"></path>
</g>
</svg>
            <span class="d-none" data-provider-pattern="^https://(www\.)?instagram\.com/[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="linkedin"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="aqlzu4z2kggowaxtra2b99yqnnuzaut9" class="octicon"><title id="aqlzu4z2kggowaxtra2b99yqnnuzaut9">LinkedIn</title>
<g clip-path="url(#clip0_202_91845)">
<path d="M14.5455 0H1.45455C0.650909 0 0 0.650909 0 1.45455V14.5455C0 15.3491 0.650909 16 1.45455 16H14.5455C15.3491 16 16 15.3491 16 14.5455V1.45455C16 0.650909 15.3491 0 14.5455 0ZM5.05746 13.0909H2.912V6.18764H5.05746V13.0909ZM3.96291 5.20073C3.27127 5.20073 2.712 4.64 2.712 3.94982C2.712 3.25964 3.272 2.69964 3.96291 2.69964C4.65236 2.69964 5.21309 3.26036 5.21309 3.94982C5.21309 4.64 4.65236 5.20073 3.96291 5.20073ZM13.0938 13.0909H10.9498V9.73382C10.9498 8.93309 10.9353 7.90327 9.83491 7.90327C8.71855 7.90327 8.54691 8.77527 8.54691 9.67564V13.0909H6.40291V6.18764H8.46109V7.13091H8.49018C8.77673 6.58836 9.47636 6.016 10.52 6.016C12.6924 6.016 13.0938 7.44582 13.0938 9.30473V13.0909V13.0909Z" fill="currentColor"></path>
</g>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?linkedin\.com/(?:in|company)/[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="mastodon"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="atmazjkx7dkm9fkhb0z7ukay82warsd0" class="octicon"><title id="atmazjkx7dkm9fkhb0z7ukay82warsd0">Mastodon</title>
<path d="M8.29202 0.000202252C6.27825 0.00837918 4.27877 0.264357 3.23839 0.744626C3.23839 0.744626 1 1.76482 1 5.23985C1 9.37638 0.997 14.5711 4.70851 15.5757C6.12991 15.9582 7.35227 16.0405 8.33499 15.9838C10.1184 15.883 11.0005 15.3359 11.0005 15.3359L10.9406 14.0165C10.9406 14.0165 9.78462 14.4244 8.35322 14.3776C6.93515 14.3276 5.44121 14.221 5.20853 12.4481C5.1872 12.2832 5.17662 12.1163 5.17728 11.9501C8.18209 12.697 10.7444 12.2754 11.4497 12.19C13.4191 11.9503 15.1336 10.7139 15.3522 9.58385C15.6949 7.80294 15.6661 5.23985 15.6661 5.23985C15.6661 1.76482 13.4316 0.744626 13.4316 0.744626C12.3345 0.231649 10.3058 -0.00797468 8.29202 0.000202252ZM6.13696 2.65066C6.82691 2.66919 7.5087 2.97824 7.92872 3.63106L8.33499 4.32203L8.73995 3.63106C9.58333 2.31808 11.4736 2.40001 12.3729 3.41595C13.2023 4.3825 13.0175 5.00632 13.0175 9.32441V9.32571H11.3859V5.56839C11.3859 3.80952 9.14622 3.74159 9.14622 5.81219V7.9894H7.52505V5.81219C7.52505 3.74159 5.28666 3.80821 5.28666 5.56709V9.32441H3.65117C3.65117 5.00298 3.46969 4.37515 4.29573 3.41595C4.74875 2.90464 5.44701 2.63214 6.13696 2.65066Z" fill="currentColor"></path>
</svg>
              <span
                class="d-none"
                data-try-nodeinfo-pattern="^https?://([^/]+)/@([^/?]+)/?$"
                data-nodeinfo-software="mastodon"
              ></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="reddit"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="a6jdwys92y4kw5y3ge8ykum0d6jrltpx" class="octicon"><title id="a6jdwys92y4kw5y3ge8ykum0d6jrltpx">Reddit</title>
<path d="M9.42117 1C8.30163 1 7.46615 1.91456 7.46615 2.95502V4.75573C5.9979 4.83364 4.65515 5.2251 3.58321 5.83907C3.17013 5.4424 2.61701 5.26625 2.08071 5.26664C1.49925 5.26707 0.904821 5.46856 0.494798 5.92979L0.485414 5.94021L0.47603 5.95064C0.0827037 6.44221 -0.0730397 7.10072 0.0318487 7.75447C0.127638 8.35152 0.473426 8.95088 1.07453 9.34352C1.07059 9.4098 1.05993 9.47469 1.05993 9.54163C1.05993 12.1906 4.17335 14.3463 8 14.3463C11.8266 14.3463 14.9401 12.1906 14.9401 9.54163C14.9401 9.47469 14.9294 9.4098 14.9255 9.34352C15.5266 8.95088 15.8724 8.35152 15.9682 7.75447C16.073 7.10072 15.9173 6.44221 15.524 5.95064L15.5146 5.94021L15.5052 5.92979C15.0951 5.4685 14.5008 5.26707 13.9193 5.26664C13.3829 5.26625 12.8297 5.44225 12.4168 5.83907C11.3449 5.2251 10.0021 4.83364 8.53385 4.75573V2.95502C8.53385 2.43237 8.83559 2.0677 9.42117 2.0677C9.69914 2.0677 10.0378 2.20699 10.5681 2.39302C11.0165 2.55028 11.5999 2.70923 12.3459 2.75691C12.5243 3.2844 13.0197 3.66926 13.6054 3.66926C14.3395 3.66926 14.9401 3.06868 14.9401 2.33463C14.9401 1.60058 14.3395 1 13.6054 1C13.1043 1 12.6699 1.28317 12.4418 1.69442C11.8041 1.65911 11.3356 1.53103 10.9216 1.38579C10.4391 1.21654 9.99576 1 9.42117 1ZM2.08071 6.33435C2.29166 6.33419 2.49208 6.38955 2.65731 6.47928C2.06795 6.97122 1.62078 7.54599 1.35084 8.17363C1.20751 7.99671 1.12113 7.79807 1.08704 7.58556C1.02951 7.22698 1.13682 6.85424 1.30704 6.63359C1.46791 6.46045 1.76166 6.33458 2.08071 6.33435ZM13.9182 6.33435C14.2374 6.33458 14.5321 6.4605 14.693 6.63359C14.8632 6.85424 14.9705 7.22698 14.913 7.58556C14.8789 7.79807 14.7925 7.99671 14.6492 8.17363C14.3792 7.54599 13.9321 6.97122 13.3427 6.47928C13.5075 6.38965 13.7074 6.33419 13.9182 6.33435ZM5.33074 7.40622C5.92065 7.40622 6.39845 7.88402 6.39845 8.47392C6.39845 9.06383 5.92065 9.54163 5.33074 9.54163C4.74084 9.54163 4.26304 9.06383 4.26304 8.47392C4.26304 7.88402 4.74084 7.40622 5.33074 7.40622ZM10.6693 7.40622C11.2592 7.40622 11.737 7.88402 11.737 8.47392C11.737 9.06383 11.2592 9.54163 10.6693 9.54163C10.0794 9.54163 9.60155 9.06383 9.60155 8.47392C9.60155 7.88402 10.0794 7.40622 10.6693 7.40622ZM10.7965 10.3601C10.4553 11.3568 9.36452 12.2109 8 12.2109C6.63548 12.2109 5.54467 11.3572 5.20354 10.4321C5.81746 10.9302 6.84047 11.286 8 11.286C9.15953 11.286 10.1825 10.9297 10.7965 10.3601Z" fill="currentColor"></path>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?reddit\.com/u(?:ser)?/([^/?]+)/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="twitch"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="anazedveiala17gsh0x02eb4rzc4fxn9" class="octicon"><title id="anazedveiala17gsh0x02eb4rzc4fxn9">Twitch</title>
<g clip-path="url(#clip0_202_91859)">
<path d="M2.96249 0L0.399994 3.53274V13.7143H4.20952V16H6.49523L8.78095 13.7143H11.8286L15.6381 9.90476V0H2.96249ZM3.44761 1.52381H14.1143V8.38095L11.8286 10.6667H8.01904L5.73333 12.9524V10.6667H3.44761V1.52381ZM7.25714 3.80952V7.61905H8.78095V3.80952H7.25714ZM11.0667 3.80952V7.61905H12.5905V3.80952H11.0667Z" fill="currentColor"></path>
</g>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?twitch\.tv/[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="twitter"
        >
          <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 16 16" width="16" height="16" role="img" aria-labelledby="amuoru5z8hkqq2y40lhqajebbui7qbty" class="octicon"><title id="amuoru5z8hkqq2y40lhqajebbui7qbty">X</title><path fill="currentColor" d="M9.332 6.925 14.544 1h-1.235L8.783 6.145 5.17 1H1l5.466 7.78L1 14.993h1.235l4.78-5.433 3.816 5.433H15L9.332 6.925ZM7.64 8.848l-.554-.775L2.68 1.91h1.897l3.556 4.975.554.775 4.622 6.466h-1.897L7.64 8.848Z"></path></svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?(?:twitter|x)\.com/([^/?]+)/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="youtube"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="a60jtacb9fbuz3piv25m7952c63edb4c" class="octicon"><title id="a60jtacb9fbuz3piv25m7952c63edb4c">YouTube</title>
<path d="M15.6656 3.7488C15.4816 3.0608 14.9392 2.5184 14.2512 2.3344C13.0032 2 8 2 8 2C8 2 2.9968 2 1.7488 2.3344C1.0608 2.5184 0.5184 3.0608 0.3344 3.7488C-2.38419e-08 4.9968 0 8.4 0 8.4C0 8.4 -2.38419e-08 11.8032 0.3344 13.0512C0.5184 13.7392 1.0608 14.2816 1.7488 14.4656C2.9968 14.8 8 14.8 8 14.8C8 14.8 13.0032 14.8 14.2512 14.4656C14.94 14.2816 15.4816 13.7392 15.6656 13.0512C16 11.8032 16 8.4 16 8.4C16 8.4 16 4.9968 15.6656 3.7488ZM6.4 10.4784V6.3216C6.4 6.0136 6.7336 5.8216 7 5.9752L10.6 8.0536C10.8664 8.2072 10.8664 8.5928 10.6 8.7464L7 10.8248C6.7336 10.9792 6.4 10.7864 6.4 10.4784Z" fill="currentColor"></path>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?youtube\.com/(user|c)/[^/?]+/?$"></span>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?youtube\.com/channel/[a-zA-Z0-9_-]{24}/?$"></span>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?youtube\.com/@[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="bluesky"
        >
          <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 16 16" role="img" aria-labelledby="a432zac61ygxr2i73tnmrzdyuru2my40" class="octicon" width="16" height="16"><title id="a432zac61ygxr2i73tnmrzdyuru2my40">Bluesky</title><path fill="currentColor" d="M3.468 1.948C5.303 3.325 7.276 6.118 8 7.616c.725-1.498 2.697-4.29 4.532-5.668C13.855.955 16 .186 16 2.632c0 .489-.28 4.105-.444 4.692-.572 2.04-2.653 2.561-4.504 2.246 3.236.551 4.06 2.375 2.281 4.2-3.376 3.464-4.852-.87-5.23-1.98-.07-.204-.103-.3-.103-.218 0-.081-.033.014-.102.218-.379 1.11-1.855 5.444-5.231 1.98-1.778-1.825-.955-3.65 2.28-4.2-1.85.315-3.932-.205-4.503-2.246C.28 6.737 0 3.12 0 2.632 0 .186 2.145.955 3.468 1.948Z"></path></svg>
            <span class="d-none" data-provider-pattern="^https://bsky\.app/profile/([^@/]+)/?$"></span>
        </span>
        <span
          
          data-targets="social-account-editor.iconOptions"
          data-target="social-account-editor.iconGeneric"
          data-provider-key="generic"
        >
          <svg title="Social account" aria-label="Social account" role="img" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-link">
    <path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path>
</svg>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="npm"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="anwp2rgmzx2x9z5k1a28ihb1hvs9axi1" class="octicon"><title id="anwp2rgmzx2x9z5k1a28ihb1hvs9axi1">Npm</title>
  <path d="M 0 0 L 0 16 L 16 16 L 16 0 L 0 0 z M 3 3 L 13 3 L 13 13 L 11 13 L 11 5 L 8 5 L 8 13 L 3 13 L 3 3 z " fill="currentColor"></path>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?npmjs\.com/~([^/?]+)/?$"></span>
        </span>
      <span data-target="social-account-editor.iconSpinner" hidden>
        <span data-view-component="true">
  <svg style="box-sizing: content-box; color: var(--color-icon-primary);" width="16" height="16" viewBox="0 0 16 16" fill="none" aria-hidden="true" data-view-component="true" class="anim-rotate">
    <circle cx="8" cy="8" r="7" stroke="currentColor" stroke-opacity="0.25" stroke-width="2" vector-effect="non-scaling-stroke" fill="none"></circle>
    <path d="M15 8a7.002 7.002 0 00-7-7" stroke="currentColor" stroke-width="2" stroke-linecap="round" vector-effect="non-scaling-stroke"></path>
</svg>    <span class="sr-only">Loading</span>
</span>
      </span>
      <input
        type="hidden"
        data-target="social-account-editor.iconField"
        name="user[profile_social_accounts][][key]"
        value="generic"
      >
      <input
        class="ml-2 form-control flex-auto input-sm"
        data-target="social-account-editor.urlField"
        data-action="change:social-account-editor#recognizeUrl"
        type="text"
        placeholder="Link to social profile 1"
        aria-label="Link to social profile 1"
        name="user[profile_social_accounts][][url]"
        value="https://www.butterflyscythe.com/jinx"
        
      >
    </div>
  </social-account-editor>
  <social-account-editor
    data-nodeinfo-software-url="/settings/nodeinfo_software"
    data-targets="waiting-form.prerequisites"
    data-waiting-form-method="waitForRecognition"
  >
    <div class="color-fg-muted mt-2 d-flex flex-items-center">
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="facebook"
        >
          <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 15.3 15.4" role="img" aria-labelledby="agjuzs356q7lzl4oaa0eobcwhlrjspc" class="octicon" width="16" height="16"><title id="agjuzs356q7lzl4oaa0eobcwhlrjspc">Facebook</title><path d="M14.5 0H.8a.88.88 0 0 0-.8.9v13.6a.88.88 0 0 0 .8.9h7.3v-6h-2V7.1h2V5.4a2.87 2.87 0 0 1 2.5-3.1h.5a10.87 10.87 0 0 1 1.8.1v2.1h-1.3c-1 0-1.1.5-1.1 1.1v1.5h2.3l-.3 2.3h-2v5.9h3.9a.88.88 0 0 0 .9-.8V.8a.86.86 0 0 0-.8-.8z" fill="currentColor"></path></svg>
            <span class="d-none" data-provider-pattern="^https://(?:[^.]+\.)?facebook\.com/(?:[^/?]+/?|profile\.php\?id=\d+)$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="hometown"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="amvrkoj2m01nc1hbsnunn6kf1z6z8rbj" class="octicon"><title id="amvrkoj2m01nc1hbsnunn6kf1z6z8rbj">Hometown</title>
<path d="M8.29202 0.000202252C6.27825 0.00837918 4.27877 0.264357 3.23839 0.744626C3.23839 0.744626 1 1.76482 1 5.23985C1 9.37638 0.997 14.5711 4.70851 15.5757C6.12991 15.9582 7.35227 16.0405 8.33499 15.9838C10.1184 15.883 11.0005 15.3359 11.0005 15.3359L10.9406 14.0165C10.9406 14.0165 9.78462 14.4244 8.35322 14.3776C6.93515 14.3276 5.44121 14.221 5.20853 12.4481C5.1872 12.2832 5.17662 12.1163 5.17728 11.9501C8.18209 12.697 10.7444 12.2754 11.4497 12.19C13.4191 11.9503 15.1336 10.7139 15.3522 9.58385C15.6949 7.80294 15.6661 5.23985 15.6661 5.23985C15.6661 1.76482 13.4316 0.744626 13.4316 0.744626C12.3345 0.231649 10.3058 -0.00797468 8.29202 0.000202252ZM6.13696 2.65066C6.82691 2.66919 7.5087 2.97824 7.92872 3.63106L8.33499 4.32203L8.73995 3.63106C9.58333 2.31808 11.4736 2.40001 12.3729 3.41595C13.2023 4.3825 13.0175 5.00632 13.0175 9.32441V9.32571H11.3859V5.56839C11.3859 3.80952 9.14622 3.74159 9.14622 5.81219V7.9894H7.52505V5.81219C7.52505 3.74159 5.28666 3.80821 5.28666 5.56709V9.32441H3.65117C3.65117 5.00298 3.46969 4.37515 4.29573 3.41595C4.74875 2.90464 5.44701 2.63214 6.13696 2.65066Z" fill="currentColor"></path>
</svg>
              <span
                class="d-none"
                data-try-nodeinfo-pattern="^https?://([^/]+)/@([^/?]+)/?$"
                data-nodeinfo-software="hometown"
              ></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="instagram"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="atsfafcltk5uuxb4ji9m9naos21dn5ct" class="octicon"><title id="atsfafcltk5uuxb4ji9m9naos21dn5ct">Instagram</title>
<g clip-path="url(#clip0_202_91849)">
<path d="M4.66536 0C2.0927 0 0 2.09464 0 4.66797V11.3346C0 13.9073 2.09464 16 4.66797 16H11.3346C13.9073 16 16 13.9054 16 11.332V4.66536C16 2.0927 13.9054 0 11.332 0H4.66536ZM12.6667 2.66667C13.0347 2.66667 13.3333 2.96533 13.3333 3.33333C13.3333 3.70133 13.0347 4 12.6667 4C12.2987 4 12 3.70133 12 3.33333C12 2.96533 12.2987 2.66667 12.6667 2.66667ZM8 4C10.206 4 12 5.794 12 8C12 10.206 10.206 12 8 12C5.794 12 4 10.206 4 8C4 5.794 5.794 4 8 4ZM8 5.33333C7.29276 5.33333 6.61448 5.61428 6.11438 6.11438C5.61428 6.61448 5.33333 7.29276 5.33333 8C5.33333 8.70724 5.61428 9.38552 6.11438 9.88562C6.61448 10.3857 7.29276 10.6667 8 10.6667C8.70724 10.6667 9.38552 10.3857 9.88562 9.88562C10.3857 9.38552 10.6667 8.70724 10.6667 8C10.6667 7.29276 10.3857 6.61448 9.88562 6.11438C9.38552 5.61428 8.70724 5.33333 8 5.33333V5.33333Z" fill="currentColor"></path>
</g>
</svg>
            <span class="d-none" data-provider-pattern="^https://(www\.)?instagram\.com/[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="linkedin"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="a3puh8ntgo428xnx0xp7ph4u5yuhcsu3" class="octicon"><title id="a3puh8ntgo428xnx0xp7ph4u5yuhcsu3">LinkedIn</title>
<g clip-path="url(#clip0_202_91845)">
<path d="M14.5455 0H1.45455C0.650909 0 0 0.650909 0 1.45455V14.5455C0 15.3491 0.650909 16 1.45455 16H14.5455C15.3491 16 16 15.3491 16 14.5455V1.45455C16 0.650909 15.3491 0 14.5455 0ZM5.05746 13.0909H2.912V6.18764H5.05746V13.0909ZM3.96291 5.20073C3.27127 5.20073 2.712 4.64 2.712 3.94982C2.712 3.25964 3.272 2.69964 3.96291 2.69964C4.65236 2.69964 5.21309 3.26036 5.21309 3.94982C5.21309 4.64 4.65236 5.20073 3.96291 5.20073ZM13.0938 13.0909H10.9498V9.73382C10.9498 8.93309 10.9353 7.90327 9.83491 7.90327C8.71855 7.90327 8.54691 8.77527 8.54691 9.67564V13.0909H6.40291V6.18764H8.46109V7.13091H8.49018C8.77673 6.58836 9.47636 6.016 10.52 6.016C12.6924 6.016 13.0938 7.44582 13.0938 9.30473V13.0909V13.0909Z" fill="currentColor"></path>
</g>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?linkedin\.com/(?:in|company)/[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="mastodon"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="acf6njfyoeiekvzoyjmd70sl4pbzom8k" class="octicon"><title id="acf6njfyoeiekvzoyjmd70sl4pbzom8k">Mastodon</title>
<path d="M8.29202 0.000202252C6.27825 0.00837918 4.27877 0.264357 3.23839 0.744626C3.23839 0.744626 1 1.76482 1 5.23985C1 9.37638 0.997 14.5711 4.70851 15.5757C6.12991 15.9582 7.35227 16.0405 8.33499 15.9838C10.1184 15.883 11.0005 15.3359 11.0005 15.3359L10.9406 14.0165C10.9406 14.0165 9.78462 14.4244 8.35322 14.3776C6.93515 14.3276 5.44121 14.221 5.20853 12.4481C5.1872 12.2832 5.17662 12.1163 5.17728 11.9501C8.18209 12.697 10.7444 12.2754 11.4497 12.19C13.4191 11.9503 15.1336 10.7139 15.3522 9.58385C15.6949 7.80294 15.6661 5.23985 15.6661 5.23985C15.6661 1.76482 13.4316 0.744626 13.4316 0.744626C12.3345 0.231649 10.3058 -0.00797468 8.29202 0.000202252ZM6.13696 2.65066C6.82691 2.66919 7.5087 2.97824 7.92872 3.63106L8.33499 4.32203L8.73995 3.63106C9.58333 2.31808 11.4736 2.40001 12.3729 3.41595C13.2023 4.3825 13.0175 5.00632 13.0175 9.32441V9.32571H11.3859V5.56839C11.3859 3.80952 9.14622 3.74159 9.14622 5.81219V7.9894H7.52505V5.81219C7.52505 3.74159 5.28666 3.80821 5.28666 5.56709V9.32441H3.65117C3.65117 5.00298 3.46969 4.37515 4.29573 3.41595C4.74875 2.90464 5.44701 2.63214 6.13696 2.65066Z" fill="currentColor"></path>
</svg>
              <span
                class="d-none"
                data-try-nodeinfo-pattern="^https?://([^/]+)/@([^/?]+)/?$"
                data-nodeinfo-software="mastodon"
              ></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="reddit"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="al7hrt899pndo2wtbh2k6rm3ah2vf1y8" class="octicon"><title id="al7hrt899pndo2wtbh2k6rm3ah2vf1y8">Reddit</title>
<path d="M9.42117 1C8.30163 1 7.46615 1.91456 7.46615 2.95502V4.75573C5.9979 4.83364 4.65515 5.2251 3.58321 5.83907C3.17013 5.4424 2.61701 5.26625 2.08071 5.26664C1.49925 5.26707 0.904821 5.46856 0.494798 5.92979L0.485414 5.94021L0.47603 5.95064C0.0827037 6.44221 -0.0730397 7.10072 0.0318487 7.75447C0.127638 8.35152 0.473426 8.95088 1.07453 9.34352C1.07059 9.4098 1.05993 9.47469 1.05993 9.54163C1.05993 12.1906 4.17335 14.3463 8 14.3463C11.8266 14.3463 14.9401 12.1906 14.9401 9.54163C14.9401 9.47469 14.9294 9.4098 14.9255 9.34352C15.5266 8.95088 15.8724 8.35152 15.9682 7.75447C16.073 7.10072 15.9173 6.44221 15.524 5.95064L15.5146 5.94021L15.5052 5.92979C15.0951 5.4685 14.5008 5.26707 13.9193 5.26664C13.3829 5.26625 12.8297 5.44225 12.4168 5.83907C11.3449 5.2251 10.0021 4.83364 8.53385 4.75573V2.95502C8.53385 2.43237 8.83559 2.0677 9.42117 2.0677C9.69914 2.0677 10.0378 2.20699 10.5681 2.39302C11.0165 2.55028 11.5999 2.70923 12.3459 2.75691C12.5243 3.2844 13.0197 3.66926 13.6054 3.66926C14.3395 3.66926 14.9401 3.06868 14.9401 2.33463C14.9401 1.60058 14.3395 1 13.6054 1C13.1043 1 12.6699 1.28317 12.4418 1.69442C11.8041 1.65911 11.3356 1.53103 10.9216 1.38579C10.4391 1.21654 9.99576 1 9.42117 1ZM2.08071 6.33435C2.29166 6.33419 2.49208 6.38955 2.65731 6.47928C2.06795 6.97122 1.62078 7.54599 1.35084 8.17363C1.20751 7.99671 1.12113 7.79807 1.08704 7.58556C1.02951 7.22698 1.13682 6.85424 1.30704 6.63359C1.46791 6.46045 1.76166 6.33458 2.08071 6.33435ZM13.9182 6.33435C14.2374 6.33458 14.5321 6.4605 14.693 6.63359C14.8632 6.85424 14.9705 7.22698 14.913 7.58556C14.8789 7.79807 14.7925 7.99671 14.6492 8.17363C14.3792 7.54599 13.9321 6.97122 13.3427 6.47928C13.5075 6.38965 13.7074 6.33419 13.9182 6.33435ZM5.33074 7.40622C5.92065 7.40622 6.39845 7.88402 6.39845 8.47392C6.39845 9.06383 5.92065 9.54163 5.33074 9.54163C4.74084 9.54163 4.26304 9.06383 4.26304 8.47392C4.26304 7.88402 4.74084 7.40622 5.33074 7.40622ZM10.6693 7.40622C11.2592 7.40622 11.737 7.88402 11.737 8.47392C11.737 9.06383 11.2592 9.54163 10.6693 9.54163C10.0794 9.54163 9.60155 9.06383 9.60155 8.47392C9.60155 7.88402 10.0794 7.40622 10.6693 7.40622ZM10.7965 10.3601C10.4553 11.3568 9.36452 12.2109 8 12.2109C6.63548 12.2109 5.54467 11.3572 5.20354 10.4321C5.81746 10.9302 6.84047 11.286 8 11.286C9.15953 11.286 10.1825 10.9297 10.7965 10.3601Z" fill="currentColor"></path>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?reddit\.com/u(?:ser)?/([^/?]+)/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="twitch"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="apx4rqtrtb999r17bj7o6yo4cjhzr1p7" class="octicon"><title id="apx4rqtrtb999r17bj7o6yo4cjhzr1p7">Twitch</title>
<g clip-path="url(#clip0_202_91859)">
<path d="M2.96249 0L0.399994 3.53274V13.7143H4.20952V16H6.49523L8.78095 13.7143H11.8286L15.6381 9.90476V0H2.96249ZM3.44761 1.52381H14.1143V8.38095L11.8286 10.6667H8.01904L5.73333 12.9524V10.6667H3.44761V1.52381ZM7.25714 3.80952V7.61905H8.78095V3.80952H7.25714ZM11.0667 3.80952V7.61905H12.5905V3.80952H11.0667Z" fill="currentColor"></path>
</g>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?twitch\.tv/[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="twitter"
        >
          <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 16 16" width="16" height="16" role="img" aria-labelledby="a407vrv610dtat43iuas4tyy68e05ozp" class="octicon"><title id="a407vrv610dtat43iuas4tyy68e05ozp">X</title><path fill="currentColor" d="M9.332 6.925 14.544 1h-1.235L8.783 6.145 5.17 1H1l5.466 7.78L1 14.993h1.235l4.78-5.433 3.816 5.433H15L9.332 6.925ZM7.64 8.848l-.554-.775L2.68 1.91h1.897l3.556 4.975.554.775 4.622 6.466h-1.897L7.64 8.848Z"></path></svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?(?:twitter|x)\.com/([^/?]+)/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="youtube"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="a14xnfnkxbpu8b06fvm1elwqk4k7oi9j" class="octicon"><title id="a14xnfnkxbpu8b06fvm1elwqk4k7oi9j">YouTube</title>
<path d="M15.6656 3.7488C15.4816 3.0608 14.9392 2.5184 14.2512 2.3344C13.0032 2 8 2 8 2C8 2 2.9968 2 1.7488 2.3344C1.0608 2.5184 0.5184 3.0608 0.3344 3.7488C-2.38419e-08 4.9968 0 8.4 0 8.4C0 8.4 -2.38419e-08 11.8032 0.3344 13.0512C0.5184 13.7392 1.0608 14.2816 1.7488 14.4656C2.9968 14.8 8 14.8 8 14.8C8 14.8 13.0032 14.8 14.2512 14.4656C14.94 14.2816 15.4816 13.7392 15.6656 13.0512C16 11.8032 16 8.4 16 8.4C16 8.4 16 4.9968 15.6656 3.7488ZM6.4 10.4784V6.3216C6.4 6.0136 6.7336 5.8216 7 5.9752L10.6 8.0536C10.8664 8.2072 10.8664 8.5928 10.6 8.7464L7 10.8248C6.7336 10.9792 6.4 10.7864 6.4 10.4784Z" fill="currentColor"></path>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?youtube\.com/(user|c)/[^/?]+/?$"></span>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?youtube\.com/channel/[a-zA-Z0-9_-]{24}/?$"></span>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?youtube\.com/@[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="bluesky"
        >
          <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 16 16" role="img" aria-labelledby="af27vz65hh32xlzhxg5g55klglj30zph" class="octicon" width="16" height="16"><title id="af27vz65hh32xlzhxg5g55klglj30zph">Bluesky</title><path fill="currentColor" d="M3.468 1.948C5.303 3.325 7.276 6.118 8 7.616c.725-1.498 2.697-4.29 4.532-5.668C13.855.955 16 .186 16 2.632c0 .489-.28 4.105-.444 4.692-.572 2.04-2.653 2.561-4.504 2.246 3.236.551 4.06 2.375 2.281 4.2-3.376 3.464-4.852-.87-5.23-1.98-.07-.204-.103-.3-.103-.218 0-.081-.033.014-.102.218-.379 1.11-1.855 5.444-5.231 1.98-1.778-1.825-.955-3.65 2.28-4.2-1.85.315-3.932-.205-4.503-2.246C.28 6.737 0 3.12 0 2.632 0 .186 2.145.955 3.468 1.948Z"></path></svg>
            <span class="d-none" data-provider-pattern="^https://bsky\.app/profile/([^@/]+)/?$"></span>
        </span>
        <span
          
          data-targets="social-account-editor.iconOptions"
          data-target="social-account-editor.iconGeneric"
          data-provider-key="generic"
        >
          <svg title="Social account" aria-label="Social account" role="img" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-link">
    <path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path>
</svg>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="npm"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="at9osojufnbmznuukbh9s4ni2p5nok8z" class="octicon"><title id="at9osojufnbmznuukbh9s4ni2p5nok8z">Npm</title>
  <path d="M 0 0 L 0 16 L 16 16 L 16 0 L 0 0 z M 3 3 L 13 3 L 13 13 L 11 13 L 11 5 L 8 5 L 8 13 L 3 13 L 3 3 z " fill="currentColor"></path>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?npmjs\.com/~([^/?]+)/?$"></span>
        </span>
      <span data-target="social-account-editor.iconSpinner" hidden>
        <span data-view-component="true">
  <svg style="box-sizing: content-box; color: var(--color-icon-primary);" width="16" height="16" viewBox="0 0 16 16" fill="none" aria-hidden="true" data-view-component="true" class="anim-rotate">
    <circle cx="8" cy="8" r="7" stroke="currentColor" stroke-opacity="0.25" stroke-width="2" vector-effect="non-scaling-stroke" fill="none"></circle>
    <path d="M15 8a7.002 7.002 0 00-7-7" stroke="currentColor" stroke-width="2" stroke-linecap="round" vector-effect="non-scaling-stroke"></path>
</svg>    <span class="sr-only">Loading</span>
</span>
      </span>
      <input
        type="hidden"
        data-target="social-account-editor.iconField"
        name="user[profile_social_accounts][][key]"
        value="generic"
      >
      <input
        class="ml-2 form-control flex-auto input-sm"
        data-target="social-account-editor.urlField"
        data-action="change:social-account-editor#recognizeUrl"
        type="text"
        placeholder="Link to social profile 2"
        aria-label="Link to social profile 2"
        name="user[profile_social_accounts][][url]"
        value="https://github.com/sator-arepo-tenet-opera-rotas"
        
      >
    </div>
  </social-account-editor>
  <social-account-editor
    data-nodeinfo-software-url="/settings/nodeinfo_software"
    data-targets="waiting-form.prerequisites"
    data-waiting-form-method="waitForRecognition"
  >
    <div class="color-fg-muted mt-2 d-flex flex-items-center">
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="facebook"
        >
          <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 15.3 15.4" role="img" aria-labelledby="a6la2kbe3xqgsxz808w3ewd53l9bjt1t" class="octicon" width="16" height="16"><title id="a6la2kbe3xqgsxz808w3ewd53l9bjt1t">Facebook</title><path d="M14.5 0H.8a.88.88 0 0 0-.8.9v13.6a.88.88 0 0 0 .8.9h7.3v-6h-2V7.1h2V5.4a2.87 2.87 0 0 1 2.5-3.1h.5a10.87 10.87 0 0 1 1.8.1v2.1h-1.3c-1 0-1.1.5-1.1 1.1v1.5h2.3l-.3 2.3h-2v5.9h3.9a.88.88 0 0 0 .9-.8V.8a.86.86 0 0 0-.8-.8z" fill="currentColor"></path></svg>
            <span class="d-none" data-provider-pattern="^https://(?:[^.]+\.)?facebook\.com/(?:[^/?]+/?|profile\.php\?id=\d+)$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="hometown"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="agjxzs1vbyxbrvyvbed1ib279a29wjct" class="octicon"><title id="agjxzs1vbyxbrvyvbed1ib279a29wjct">Hometown</title>
<path d="M8.29202 0.000202252C6.27825 0.00837918 4.27877 0.264357 3.23839 0.744626C3.23839 0.744626 1 1.76482 1 5.23985C1 9.37638 0.997 14.5711 4.70851 15.5757C6.12991 15.9582 7.35227 16.0405 8.33499 15.9838C10.1184 15.883 11.0005 15.3359 11.0005 15.3359L10.9406 14.0165C10.9406 14.0165 9.78462 14.4244 8.35322 14.3776C6.93515 14.3276 5.44121 14.221 5.20853 12.4481C5.1872 12.2832 5.17662 12.1163 5.17728 11.9501C8.18209 12.697 10.7444 12.2754 11.4497 12.19C13.4191 11.9503 15.1336 10.7139 15.3522 9.58385C15.6949 7.80294 15.6661 5.23985 15.6661 5.23985C15.6661 1.76482 13.4316 0.744626 13.4316 0.744626C12.3345 0.231649 10.3058 -0.00797468 8.29202 0.000202252ZM6.13696 2.65066C6.82691 2.66919 7.5087 2.97824 7.92872 3.63106L8.33499 4.32203L8.73995 3.63106C9.58333 2.31808 11.4736 2.40001 12.3729 3.41595C13.2023 4.3825 13.0175 5.00632 13.0175 9.32441V9.32571H11.3859V5.56839C11.3859 3.80952 9.14622 3.74159 9.14622 5.81219V7.9894H7.52505V5.81219C7.52505 3.74159 5.28666 3.80821 5.28666 5.56709V9.32441H3.65117C3.65117 5.00298 3.46969 4.37515 4.29573 3.41595C4.74875 2.90464 5.44701 2.63214 6.13696 2.65066Z" fill="currentColor"></path>
</svg>
              <span
                class="d-none"
                data-try-nodeinfo-pattern="^https?://([^/]+)/@([^/?]+)/?$"
                data-nodeinfo-software="hometown"
              ></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="instagram"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="a7img6uzzkg4qafbruf8y61c06menq2l" class="octicon"><title id="a7img6uzzkg4qafbruf8y61c06menq2l">Instagram</title>
<g clip-path="url(#clip0_202_91849)">
<path d="M4.66536 0C2.0927 0 0 2.09464 0 4.66797V11.3346C0 13.9073 2.09464 16 4.66797 16H11.3346C13.9073 16 16 13.9054 16 11.332V4.66536C16 2.0927 13.9054 0 11.332 0H4.66536ZM12.6667 2.66667C13.0347 2.66667 13.3333 2.96533 13.3333 3.33333C13.3333 3.70133 13.0347 4 12.6667 4C12.2987 4 12 3.70133 12 3.33333C12 2.96533 12.2987 2.66667 12.6667 2.66667ZM8 4C10.206 4 12 5.794 12 8C12 10.206 10.206 12 8 12C5.794 12 4 10.206 4 8C4 5.794 5.794 4 8 4ZM8 5.33333C7.29276 5.33333 6.61448 5.61428 6.11438 6.11438C5.61428 6.61448 5.33333 7.29276 5.33333 8C5.33333 8.70724 5.61428 9.38552 6.11438 9.88562C6.61448 10.3857 7.29276 10.6667 8 10.6667C8.70724 10.6667 9.38552 10.3857 9.88562 9.88562C10.3857 9.38552 10.6667 8.70724 10.6667 8C10.6667 7.29276 10.3857 6.61448 9.88562 6.11438C9.38552 5.61428 8.70724 5.33333 8 5.33333V5.33333Z" fill="currentColor"></path>
</g>
</svg>
            <span class="d-none" data-provider-pattern="^https://(www\.)?instagram\.com/[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="linkedin"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="aj7pzt0czo6xket8bkxqp5tuztkeetas" class="octicon"><title id="aj7pzt0czo6xket8bkxqp5tuztkeetas">LinkedIn</title>
<g clip-path="url(#clip0_202_91845)">
<path d="M14.5455 0H1.45455C0.650909 0 0 0.650909 0 1.45455V14.5455C0 15.3491 0.650909 16 1.45455 16H14.5455C15.3491 16 16 15.3491 16 14.5455V1.45455C16 0.650909 15.3491 0 14.5455 0ZM5.05746 13.0909H2.912V6.18764H5.05746V13.0909ZM3.96291 5.20073C3.27127 5.20073 2.712 4.64 2.712 3.94982C2.712 3.25964 3.272 2.69964 3.96291 2.69964C4.65236 2.69964 5.21309 3.26036 5.21309 3.94982C5.21309 4.64 4.65236 5.20073 3.96291 5.20073ZM13.0938 13.0909H10.9498V9.73382C10.9498 8.93309 10.9353 7.90327 9.83491 7.90327C8.71855 7.90327 8.54691 8.77527 8.54691 9.67564V13.0909H6.40291V6.18764H8.46109V7.13091H8.49018C8.77673 6.58836 9.47636 6.016 10.52 6.016C12.6924 6.016 13.0938 7.44582 13.0938 9.30473V13.0909V13.0909Z" fill="currentColor"></path>
</g>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?linkedin\.com/(?:in|company)/[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="mastodon"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="afl55lp1ihhqcmsr8ke06uakq1wy2u0a" class="octicon"><title id="afl55lp1ihhqcmsr8ke06uakq1wy2u0a">Mastodon</title>
<path d="M8.29202 0.000202252C6.27825 0.00837918 4.27877 0.264357 3.23839 0.744626C3.23839 0.744626 1 1.76482 1 5.23985C1 9.37638 0.997 14.5711 4.70851 15.5757C6.12991 15.9582 7.35227 16.0405 8.33499 15.9838C10.1184 15.883 11.0005 15.3359 11.0005 15.3359L10.9406 14.0165C10.9406 14.0165 9.78462 14.4244 8.35322 14.3776C6.93515 14.3276 5.44121 14.221 5.20853 12.4481C5.1872 12.2832 5.17662 12.1163 5.17728 11.9501C8.18209 12.697 10.7444 12.2754 11.4497 12.19C13.4191 11.9503 15.1336 10.7139 15.3522 9.58385C15.6949 7.80294 15.6661 5.23985 15.6661 5.23985C15.6661 1.76482 13.4316 0.744626 13.4316 0.744626C12.3345 0.231649 10.3058 -0.00797468 8.29202 0.000202252ZM6.13696 2.65066C6.82691 2.66919 7.5087 2.97824 7.92872 3.63106L8.33499 4.32203L8.73995 3.63106C9.58333 2.31808 11.4736 2.40001 12.3729 3.41595C13.2023 4.3825 13.0175 5.00632 13.0175 9.32441V9.32571H11.3859V5.56839C11.3859 3.80952 9.14622 3.74159 9.14622 5.81219V7.9894H7.52505V5.81219C7.52505 3.74159 5.28666 3.80821 5.28666 5.56709V9.32441H3.65117C3.65117 5.00298 3.46969 4.37515 4.29573 3.41595C4.74875 2.90464 5.44701 2.63214 6.13696 2.65066Z" fill="currentColor"></path>
</svg>
              <span
                class="d-none"
                data-try-nodeinfo-pattern="^https?://([^/]+)/@([^/?]+)/?$"
                data-nodeinfo-software="mastodon"
              ></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="reddit"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="amo4ju8v3uyrjq9w4ulufwpuvr14xq8c" class="octicon"><title id="amo4ju8v3uyrjq9w4ulufwpuvr14xq8c">Reddit</title>
<path d="M9.42117 1C8.30163 1 7.46615 1.91456 7.46615 2.95502V4.75573C5.9979 4.83364 4.65515 5.2251 3.58321 5.83907C3.17013 5.4424 2.61701 5.26625 2.08071 5.26664C1.49925 5.26707 0.904821 5.46856 0.494798 5.92979L0.485414 5.94021L0.47603 5.95064C0.0827037 6.44221 -0.0730397 7.10072 0.0318487 7.75447C0.127638 8.35152 0.473426 8.95088 1.07453 9.34352C1.07059 9.4098 1.05993 9.47469 1.05993 9.54163C1.05993 12.1906 4.17335 14.3463 8 14.3463C11.8266 14.3463 14.9401 12.1906 14.9401 9.54163C14.9401 9.47469 14.9294 9.4098 14.9255 9.34352C15.5266 8.95088 15.8724 8.35152 15.9682 7.75447C16.073 7.10072 15.9173 6.44221 15.524 5.95064L15.5146 5.94021L15.5052 5.92979C15.0951 5.4685 14.5008 5.26707 13.9193 5.26664C13.3829 5.26625 12.8297 5.44225 12.4168 5.83907C11.3449 5.2251 10.0021 4.83364 8.53385 4.75573V2.95502C8.53385 2.43237 8.83559 2.0677 9.42117 2.0677C9.69914 2.0677 10.0378 2.20699 10.5681 2.39302C11.0165 2.55028 11.5999 2.70923 12.3459 2.75691C12.5243 3.2844 13.0197 3.66926 13.6054 3.66926C14.3395 3.66926 14.9401 3.06868 14.9401 2.33463C14.9401 1.60058 14.3395 1 13.6054 1C13.1043 1 12.6699 1.28317 12.4418 1.69442C11.8041 1.65911 11.3356 1.53103 10.9216 1.38579C10.4391 1.21654 9.99576 1 9.42117 1ZM2.08071 6.33435C2.29166 6.33419 2.49208 6.38955 2.65731 6.47928C2.06795 6.97122 1.62078 7.54599 1.35084 8.17363C1.20751 7.99671 1.12113 7.79807 1.08704 7.58556C1.02951 7.22698 1.13682 6.85424 1.30704 6.63359C1.46791 6.46045 1.76166 6.33458 2.08071 6.33435ZM13.9182 6.33435C14.2374 6.33458 14.5321 6.4605 14.693 6.63359C14.8632 6.85424 14.9705 7.22698 14.913 7.58556C14.8789 7.79807 14.7925 7.99671 14.6492 8.17363C14.3792 7.54599 13.9321 6.97122 13.3427 6.47928C13.5075 6.38965 13.7074 6.33419 13.9182 6.33435ZM5.33074 7.40622C5.92065 7.40622 6.39845 7.88402 6.39845 8.47392C6.39845 9.06383 5.92065 9.54163 5.33074 9.54163C4.74084 9.54163 4.26304 9.06383 4.26304 8.47392C4.26304 7.88402 4.74084 7.40622 5.33074 7.40622ZM10.6693 7.40622C11.2592 7.40622 11.737 7.88402 11.737 8.47392C11.737 9.06383 11.2592 9.54163 10.6693 9.54163C10.0794 9.54163 9.60155 9.06383 9.60155 8.47392C9.60155 7.88402 10.0794 7.40622 10.6693 7.40622ZM10.7965 10.3601C10.4553 11.3568 9.36452 12.2109 8 12.2109C6.63548 12.2109 5.54467 11.3572 5.20354 10.4321C5.81746 10.9302 6.84047 11.286 8 11.286C9.15953 11.286 10.1825 10.9297 10.7965 10.3601Z" fill="currentColor"></path>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?reddit\.com/u(?:ser)?/([^/?]+)/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="twitch"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="a5qgpv07ue960tzf7xn0i2mlxei7c05m" class="octicon"><title id="a5qgpv07ue960tzf7xn0i2mlxei7c05m">Twitch</title>
<g clip-path="url(#clip0_202_91859)">
<path d="M2.96249 0L0.399994 3.53274V13.7143H4.20952V16H6.49523L8.78095 13.7143H11.8286L15.6381 9.90476V0H2.96249ZM3.44761 1.52381H14.1143V8.38095L11.8286 10.6667H8.01904L5.73333 12.9524V10.6667H3.44761V1.52381ZM7.25714 3.80952V7.61905H8.78095V3.80952H7.25714ZM11.0667 3.80952V7.61905H12.5905V3.80952H11.0667Z" fill="currentColor"></path>
</g>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?twitch\.tv/[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="twitter"
        >
          <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 16 16" width="16" height="16" role="img" aria-labelledby="ap36svb335f6ewng551ftaytll0m4y1y" class="octicon"><title id="ap36svb335f6ewng551ftaytll0m4y1y">X</title><path fill="currentColor" d="M9.332 6.925 14.544 1h-1.235L8.783 6.145 5.17 1H1l5.466 7.78L1 14.993h1.235l4.78-5.433 3.816 5.433H15L9.332 6.925ZM7.64 8.848l-.554-.775L2.68 1.91h1.897l3.556 4.975.554.775 4.622 6.466h-1.897L7.64 8.848Z"></path></svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?(?:twitter|x)\.com/([^/?]+)/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="youtube"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="ar6ishj88e9831o6rvjys5pue8q04zqv" class="octicon"><title id="ar6ishj88e9831o6rvjys5pue8q04zqv">YouTube</title>
<path d="M15.6656 3.7488C15.4816 3.0608 14.9392 2.5184 14.2512 2.3344C13.0032 2 8 2 8 2C8 2 2.9968 2 1.7488 2.3344C1.0608 2.5184 0.5184 3.0608 0.3344 3.7488C-2.38419e-08 4.9968 0 8.4 0 8.4C0 8.4 -2.38419e-08 11.8032 0.3344 13.0512C0.5184 13.7392 1.0608 14.2816 1.7488 14.4656C2.9968 14.8 8 14.8 8 14.8C8 14.8 13.0032 14.8 14.2512 14.4656C14.94 14.2816 15.4816 13.7392 15.6656 13.0512C16 11.8032 16 8.4 16 8.4C16 8.4 16 4.9968 15.6656 3.7488ZM6.4 10.4784V6.3216C6.4 6.0136 6.7336 5.8216 7 5.9752L10.6 8.0536C10.8664 8.2072 10.8664 8.5928 10.6 8.7464L7 10.8248C6.7336 10.9792 6.4 10.7864 6.4 10.4784Z" fill="currentColor"></path>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?youtube\.com/(user|c)/[^/?]+/?$"></span>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?youtube\.com/channel/[a-zA-Z0-9_-]{24}/?$"></span>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?youtube\.com/@[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="bluesky"
        >
          <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 16 16" role="img" aria-labelledby="aqp79iddo1xodkz56apa5v5pn7c3bygw" class="octicon" width="16" height="16"><title id="aqp79iddo1xodkz56apa5v5pn7c3bygw">Bluesky</title><path fill="currentColor" d="M3.468 1.948C5.303 3.325 7.276 6.118 8 7.616c.725-1.498 2.697-4.29 4.532-5.668C13.855.955 16 .186 16 2.632c0 .489-.28 4.105-.444 4.692-.572 2.04-2.653 2.561-4.504 2.246 3.236.551 4.06 2.375 2.281 4.2-3.376 3.464-4.852-.87-5.23-1.98-.07-.204-.103-.3-.103-.218 0-.081-.033.014-.102.218-.379 1.11-1.855 5.444-5.231 1.98-1.778-1.825-.955-3.65 2.28-4.2-1.85.315-3.932-.205-4.503-2.246C.28 6.737 0 3.12 0 2.632 0 .186 2.145.955 3.468 1.948Z"></path></svg>
            <span class="d-none" data-provider-pattern="^https://bsky\.app/profile/([^@/]+)/?$"></span>
        </span>
        <span
          
          data-targets="social-account-editor.iconOptions"
          data-target="social-account-editor.iconGeneric"
          data-provider-key="generic"
        >
          <svg title="Social account" aria-label="Social account" role="img" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-link">
    <path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path>
</svg>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="npm"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="a1grv9eknqt23k2up0k2o3t3f9f23yi8" class="octicon"><title id="a1grv9eknqt23k2up0k2o3t3f9f23yi8">Npm</title>
  <path d="M 0 0 L 0 16 L 16 16 L 16 0 L 0 0 z M 3 3 L 13 3 L 13 13 L 11 13 L 11 5 L 8 5 L 8 13 L 3 13 L 3 3 z " fill="currentColor"></path>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?npmjs\.com/~([^/?]+)/?$"></span>
        </span>
      <span data-target="social-account-editor.iconSpinner" hidden>
        <span data-view-component="true">
  <svg style="box-sizing: content-box; color: var(--color-icon-primary);" width="16" height="16" viewBox="0 0 16 16" fill="none" aria-hidden="true" data-view-component="true" class="anim-rotate">
    <circle cx="8" cy="8" r="7" stroke="currentColor" stroke-opacity="0.25" stroke-width="2" vector-effect="non-scaling-stroke" fill="none"></circle>
    <path d="M15 8a7.002 7.002 0 00-7-7" stroke="currentColor" stroke-width="2" stroke-linecap="round" vector-effect="non-scaling-stroke"></path>
</svg>    <span class="sr-only">Loading</span>
</span>
      </span>
      <input
        type="hidden"
        data-target="social-account-editor.iconField"
        name="user[profile_social_accounts][][key]"
        value="generic"
      >
      <input
        class="ml-2 form-control flex-auto input-sm"
        data-target="social-account-editor.urlField"
        data-action="change:social-account-editor#recognizeUrl"
        type="text"
        placeholder="Link to social profile 3"
        aria-label="Link to social profile 3"
        name="user[profile_social_accounts][][url]"
        value="https://phonelosers.com/history/"
        
      >
    </div>
  </social-account-editor>
  <social-account-editor
    data-nodeinfo-software-url="/settings/nodeinfo_software"
    data-targets="waiting-form.prerequisites"
    data-waiting-form-method="waitForRecognition"
  >
    <div class="color-fg-muted mt-2 d-flex flex-items-center">
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="facebook"
        >
          <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 15.3 15.4" role="img" aria-labelledby="am0ut480lzmgwcayonv7vl6ktwb6ywx" class="octicon" width="16" height="16"><title id="am0ut480lzmgwcayonv7vl6ktwb6ywx">Facebook</title><path d="M14.5 0H.8a.88.88 0 0 0-.8.9v13.6a.88.88 0 0 0 .8.9h7.3v-6h-2V7.1h2V5.4a2.87 2.87 0 0 1 2.5-3.1h.5a10.87 10.87 0 0 1 1.8.1v2.1h-1.3c-1 0-1.1.5-1.1 1.1v1.5h2.3l-.3 2.3h-2v5.9h3.9a.88.88 0 0 0 .9-.8V.8a.86.86 0 0 0-.8-.8z" fill="currentColor"></path></svg>
            <span class="d-none" data-provider-pattern="^https://(?:[^.]+\.)?facebook\.com/(?:[^/?]+/?|profile\.php\?id=\d+)$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="hometown"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="an56ei2x7s5lsakancfmt15yjfcsx28v" class="octicon"><title id="an56ei2x7s5lsakancfmt15yjfcsx28v">Hometown</title>
<path d="M8.29202 0.000202252C6.27825 0.00837918 4.27877 0.264357 3.23839 0.744626C3.23839 0.744626 1 1.76482 1 5.23985C1 9.37638 0.997 14.5711 4.70851 15.5757C6.12991 15.9582 7.35227 16.0405 8.33499 15.9838C10.1184 15.883 11.0005 15.3359 11.0005 15.3359L10.9406 14.0165C10.9406 14.0165 9.78462 14.4244 8.35322 14.3776C6.93515 14.3276 5.44121 14.221 5.20853 12.4481C5.1872 12.2832 5.17662 12.1163 5.17728 11.9501C8.18209 12.697 10.7444 12.2754 11.4497 12.19C13.4191 11.9503 15.1336 10.7139 15.3522 9.58385C15.6949 7.80294 15.6661 5.23985 15.6661 5.23985C15.6661 1.76482 13.4316 0.744626 13.4316 0.744626C12.3345 0.231649 10.3058 -0.00797468 8.29202 0.000202252ZM6.13696 2.65066C6.82691 2.66919 7.5087 2.97824 7.92872 3.63106L8.33499 4.32203L8.73995 3.63106C9.58333 2.31808 11.4736 2.40001 12.3729 3.41595C13.2023 4.3825 13.0175 5.00632 13.0175 9.32441V9.32571H11.3859V5.56839C11.3859 3.80952 9.14622 3.74159 9.14622 5.81219V7.9894H7.52505V5.81219C7.52505 3.74159 5.28666 3.80821 5.28666 5.56709V9.32441H3.65117C3.65117 5.00298 3.46969 4.37515 4.29573 3.41595C4.74875 2.90464 5.44701 2.63214 6.13696 2.65066Z" fill="currentColor"></path>
</svg>
              <span
                class="d-none"
                data-try-nodeinfo-pattern="^https?://([^/]+)/@([^/?]+)/?$"
                data-nodeinfo-software="hometown"
              ></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="instagram"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="ae1me7hgzvi7zv2j8riibkej2zi4qxge" class="octicon"><title id="ae1me7hgzvi7zv2j8riibkej2zi4qxge">Instagram</title>
<g clip-path="url(#clip0_202_91849)">
<path d="M4.66536 0C2.0927 0 0 2.09464 0 4.66797V11.3346C0 13.9073 2.09464 16 4.66797 16H11.3346C13.9073 16 16 13.9054 16 11.332V4.66536C16 2.0927 13.9054 0 11.332 0H4.66536ZM12.6667 2.66667C13.0347 2.66667 13.3333 2.96533 13.3333 3.33333C13.3333 3.70133 13.0347 4 12.6667 4C12.2987 4 12 3.70133 12 3.33333C12 2.96533 12.2987 2.66667 12.6667 2.66667ZM8 4C10.206 4 12 5.794 12 8C12 10.206 10.206 12 8 12C5.794 12 4 10.206 4 8C4 5.794 5.794 4 8 4ZM8 5.33333C7.29276 5.33333 6.61448 5.61428 6.11438 6.11438C5.61428 6.61448 5.33333 7.29276 5.33333 8C5.33333 8.70724 5.61428 9.38552 6.11438 9.88562C6.61448 10.3857 7.29276 10.6667 8 10.6667C8.70724 10.6667 9.38552 10.3857 9.88562 9.88562C10.3857 9.38552 10.6667 8.70724 10.6667 8C10.6667 7.29276 10.3857 6.61448 9.88562 6.11438C9.38552 5.61428 8.70724 5.33333 8 5.33333V5.33333Z" fill="currentColor"></path>
</g>
</svg>
            <span class="d-none" data-provider-pattern="^https://(www\.)?instagram\.com/[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="linkedin"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="a3zllddkvoj8btqjuhpqru9dzdahe0fx" class="octicon"><title id="a3zllddkvoj8btqjuhpqru9dzdahe0fx">LinkedIn</title>
<g clip-path="url(#clip0_202_91845)">
<path d="M14.5455 0H1.45455C0.650909 0 0 0.650909 0 1.45455V14.5455C0 15.3491 0.650909 16 1.45455 16H14.5455C15.3491 16 16 15.3491 16 14.5455V1.45455C16 0.650909 15.3491 0 14.5455 0ZM5.05746 13.0909H2.912V6.18764H5.05746V13.0909ZM3.96291 5.20073C3.27127 5.20073 2.712 4.64 2.712 3.94982C2.712 3.25964 3.272 2.69964 3.96291 2.69964C4.65236 2.69964 5.21309 3.26036 5.21309 3.94982C5.21309 4.64 4.65236 5.20073 3.96291 5.20073ZM13.0938 13.0909H10.9498V9.73382C10.9498 8.93309 10.9353 7.90327 9.83491 7.90327C8.71855 7.90327 8.54691 8.77527 8.54691 9.67564V13.0909H6.40291V6.18764H8.46109V7.13091H8.49018C8.77673 6.58836 9.47636 6.016 10.52 6.016C12.6924 6.016 13.0938 7.44582 13.0938 9.30473V13.0909V13.0909Z" fill="currentColor"></path>
</g>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?linkedin\.com/(?:in|company)/[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="mastodon"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="a7aj08fp16dvbsyfbdtukbjr9aokmph8" class="octicon"><title id="a7aj08fp16dvbsyfbdtukbjr9aokmph8">Mastodon</title>
<path d="M8.29202 0.000202252C6.27825 0.00837918 4.27877 0.264357 3.23839 0.744626C3.23839 0.744626 1 1.76482 1 5.23985C1 9.37638 0.997 14.5711 4.70851 15.5757C6.12991 15.9582 7.35227 16.0405 8.33499 15.9838C10.1184 15.883 11.0005 15.3359 11.0005 15.3359L10.9406 14.0165C10.9406 14.0165 9.78462 14.4244 8.35322 14.3776C6.93515 14.3276 5.44121 14.221 5.20853 12.4481C5.1872 12.2832 5.17662 12.1163 5.17728 11.9501C8.18209 12.697 10.7444 12.2754 11.4497 12.19C13.4191 11.9503 15.1336 10.7139 15.3522 9.58385C15.6949 7.80294 15.6661 5.23985 15.6661 5.23985C15.6661 1.76482 13.4316 0.744626 13.4316 0.744626C12.3345 0.231649 10.3058 -0.00797468 8.29202 0.000202252ZM6.13696 2.65066C6.82691 2.66919 7.5087 2.97824 7.92872 3.63106L8.33499 4.32203L8.73995 3.63106C9.58333 2.31808 11.4736 2.40001 12.3729 3.41595C13.2023 4.3825 13.0175 5.00632 13.0175 9.32441V9.32571H11.3859V5.56839C11.3859 3.80952 9.14622 3.74159 9.14622 5.81219V7.9894H7.52505V5.81219C7.52505 3.74159 5.28666 3.80821 5.28666 5.56709V9.32441H3.65117C3.65117 5.00298 3.46969 4.37515 4.29573 3.41595C4.74875 2.90464 5.44701 2.63214 6.13696 2.65066Z" fill="currentColor"></path>
</svg>
              <span
                class="d-none"
                data-try-nodeinfo-pattern="^https?://([^/]+)/@([^/?]+)/?$"
                data-nodeinfo-software="mastodon"
              ></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="reddit"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="a163ljveidbl5d7bus0u9kgyyjwmi7em" class="octicon"><title id="a163ljveidbl5d7bus0u9kgyyjwmi7em">Reddit</title>
<path d="M9.42117 1C8.30163 1 7.46615 1.91456 7.46615 2.95502V4.75573C5.9979 4.83364 4.65515 5.2251 3.58321 5.83907C3.17013 5.4424 2.61701 5.26625 2.08071 5.26664C1.49925 5.26707 0.904821 5.46856 0.494798 5.92979L0.485414 5.94021L0.47603 5.95064C0.0827037 6.44221 -0.0730397 7.10072 0.0318487 7.75447C0.127638 8.35152 0.473426 8.95088 1.07453 9.34352C1.07059 9.4098 1.05993 9.47469 1.05993 9.54163C1.05993 12.1906 4.17335 14.3463 8 14.3463C11.8266 14.3463 14.9401 12.1906 14.9401 9.54163C14.9401 9.47469 14.9294 9.4098 14.9255 9.34352C15.5266 8.95088 15.8724 8.35152 15.9682 7.75447C16.073 7.10072 15.9173 6.44221 15.524 5.95064L15.5146 5.94021L15.5052 5.92979C15.0951 5.4685 14.5008 5.26707 13.9193 5.26664C13.3829 5.26625 12.8297 5.44225 12.4168 5.83907C11.3449 5.2251 10.0021 4.83364 8.53385 4.75573V2.95502C8.53385 2.43237 8.83559 2.0677 9.42117 2.0677C9.69914 2.0677 10.0378 2.20699 10.5681 2.39302C11.0165 2.55028 11.5999 2.70923 12.3459 2.75691C12.5243 3.2844 13.0197 3.66926 13.6054 3.66926C14.3395 3.66926 14.9401 3.06868 14.9401 2.33463C14.9401 1.60058 14.3395 1 13.6054 1C13.1043 1 12.6699 1.28317 12.4418 1.69442C11.8041 1.65911 11.3356 1.53103 10.9216 1.38579C10.4391 1.21654 9.99576 1 9.42117 1ZM2.08071 6.33435C2.29166 6.33419 2.49208 6.38955 2.65731 6.47928C2.06795 6.97122 1.62078 7.54599 1.35084 8.17363C1.20751 7.99671 1.12113 7.79807 1.08704 7.58556C1.02951 7.22698 1.13682 6.85424 1.30704 6.63359C1.46791 6.46045 1.76166 6.33458 2.08071 6.33435ZM13.9182 6.33435C14.2374 6.33458 14.5321 6.4605 14.693 6.63359C14.8632 6.85424 14.9705 7.22698 14.913 7.58556C14.8789 7.79807 14.7925 7.99671 14.6492 8.17363C14.3792 7.54599 13.9321 6.97122 13.3427 6.47928C13.5075 6.38965 13.7074 6.33419 13.9182 6.33435ZM5.33074 7.40622C5.92065 7.40622 6.39845 7.88402 6.39845 8.47392C6.39845 9.06383 5.92065 9.54163 5.33074 9.54163C4.74084 9.54163 4.26304 9.06383 4.26304 8.47392C4.26304 7.88402 4.74084 7.40622 5.33074 7.40622ZM10.6693 7.40622C11.2592 7.40622 11.737 7.88402 11.737 8.47392C11.737 9.06383 11.2592 9.54163 10.6693 9.54163C10.0794 9.54163 9.60155 9.06383 9.60155 8.47392C9.60155 7.88402 10.0794 7.40622 10.6693 7.40622ZM10.7965 10.3601C10.4553 11.3568 9.36452 12.2109 8 12.2109C6.63548 12.2109 5.54467 11.3572 5.20354 10.4321C5.81746 10.9302 6.84047 11.286 8 11.286C9.15953 11.286 10.1825 10.9297 10.7965 10.3601Z" fill="currentColor"></path>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?reddit\.com/u(?:ser)?/([^/?]+)/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="twitch"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="a3l1pecmpku7dgjb6mbarbiu4p2mhj5f" class="octicon"><title id="a3l1pecmpku7dgjb6mbarbiu4p2mhj5f">Twitch</title>
<g clip-path="url(#clip0_202_91859)">
<path d="M2.96249 0L0.399994 3.53274V13.7143H4.20952V16H6.49523L8.78095 13.7143H11.8286L15.6381 9.90476V0H2.96249ZM3.44761 1.52381H14.1143V8.38095L11.8286 10.6667H8.01904L5.73333 12.9524V10.6667H3.44761V1.52381ZM7.25714 3.80952V7.61905H8.78095V3.80952H7.25714ZM11.0667 3.80952V7.61905H12.5905V3.80952H11.0667Z" fill="currentColor"></path>
</g>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?twitch\.tv/[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="twitter"
        >
          <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 16 16" width="16" height="16" role="img" aria-labelledby="anpd88tj0ef3a02wksukrxmrx9fl8tys" class="octicon"><title id="anpd88tj0ef3a02wksukrxmrx9fl8tys">X</title><path fill="currentColor" d="M9.332 6.925 14.544 1h-1.235L8.783 6.145 5.17 1H1l5.466 7.78L1 14.993h1.235l4.78-5.433 3.816 5.433H15L9.332 6.925ZM7.64 8.848l-.554-.775L2.68 1.91h1.897l3.556 4.975.554.775 4.622 6.466h-1.897L7.64 8.848Z"></path></svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?(?:twitter|x)\.com/([^/?]+)/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="youtube"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="aindizfa95s7gpvm5nrgpcxthfx7qcvr" class="octicon"><title id="aindizfa95s7gpvm5nrgpcxthfx7qcvr">YouTube</title>
<path d="M15.6656 3.7488C15.4816 3.0608 14.9392 2.5184 14.2512 2.3344C13.0032 2 8 2 8 2C8 2 2.9968 2 1.7488 2.3344C1.0608 2.5184 0.5184 3.0608 0.3344 3.7488C-2.38419e-08 4.9968 0 8.4 0 8.4C0 8.4 -2.38419e-08 11.8032 0.3344 13.0512C0.5184 13.7392 1.0608 14.2816 1.7488 14.4656C2.9968 14.8 8 14.8 8 14.8C8 14.8 13.0032 14.8 14.2512 14.4656C14.94 14.2816 15.4816 13.7392 15.6656 13.0512C16 11.8032 16 8.4 16 8.4C16 8.4 16 4.9968 15.6656 3.7488ZM6.4 10.4784V6.3216C6.4 6.0136 6.7336 5.8216 7 5.9752L10.6 8.0536C10.8664 8.2072 10.8664 8.5928 10.6 8.7464L7 10.8248C6.7336 10.9792 6.4 10.7864 6.4 10.4784Z" fill="currentColor"></path>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?youtube\.com/(user|c)/[^/?]+/?$"></span>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?youtube\.com/channel/[a-zA-Z0-9_-]{24}/?$"></span>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?youtube\.com/@[^/?]+/?$"></span>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="bluesky"
        >
          <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 16 16" role="img" aria-labelledby="atmqusw1m4rwbvc9d90alg7lw544i5yc" class="octicon" width="16" height="16"><title id="atmqusw1m4rwbvc9d90alg7lw544i5yc">Bluesky</title><path fill="currentColor" d="M3.468 1.948C5.303 3.325 7.276 6.118 8 7.616c.725-1.498 2.697-4.29 4.532-5.668C13.855.955 16 .186 16 2.632c0 .489-.28 4.105-.444 4.692-.572 2.04-2.653 2.561-4.504 2.246 3.236.551 4.06 2.375 2.281 4.2-3.376 3.464-4.852-.87-5.23-1.98-.07-.204-.103-.3-.103-.218 0-.081-.033.014-.102.218-.379 1.11-1.855 5.444-5.231 1.98-1.778-1.825-.955-3.65 2.28-4.2-1.85.315-3.932-.205-4.503-2.246C.28 6.737 0 3.12 0 2.632 0 .186 2.145.955 3.468 1.948Z"></path></svg>
            <span class="d-none" data-provider-pattern="^https://bsky\.app/profile/([^@/]+)/?$"></span>
        </span>
        <span
          
          data-targets="social-account-editor.iconOptions"
          data-target="social-account-editor.iconGeneric"
          data-provider-key="generic"
        >
          <svg title="Social account" aria-label="Social account" role="img" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-link">
    <path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path>
</svg>
        </span>
        <span
          hidden
          data-targets="social-account-editor.iconOptions"
          
          data-provider-key="npm"
        >
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16" fill="none" role="img" aria-labelledby="ab19vlk7qd2oy0a3qnycmuxl54kfs4wb" class="octicon"><title id="ab19vlk7qd2oy0a3qnycmuxl54kfs4wb">Npm</title>
  <path d="M 0 0 L 0 16 L 16 16 L 16 0 L 0 0 z M 3 3 L 13 3 L 13 13 L 11 13 L 11 5 L 8 5 L 8 13 L 3 13 L 3 3 z " fill="currentColor"></path>
</svg>
            <span class="d-none" data-provider-pattern="^https://(?:www\.)?npmjs\.com/~([^/?]+)/?$"></span>
        </span>
      <span data-target="social-account-editor.iconSpinner" hidden>
        <span data-view-component="true">
  <svg style="box-sizing: content-box; color: var(--color-icon-primary);" width="16" height="16" viewBox="0 0 16 16" fill="none" aria-hidden="true" data-view-component="true" class="anim-rotate">
    <circle cx="8" cy="8" r="7" stroke="currentColor" stroke-opacity="0.25" stroke-width="2" vector-effect="non-scaling-stroke" fill="none"></circle>
    <path d="M15 8a7.002 7.002 0 00-7-7" stroke="currentColor" stroke-width="2" stroke-linecap="round" vector-effect="non-scaling-stroke"></path>
</svg>    <span class="sr-only">Loading</span>
</span>
      </span>
      <input
        type="hidden"
        data-target="social-account-editor.iconField"
        name="user[profile_social_accounts][][key]"
        value="generic"
      >
      <input
        class="ml-2 form-control flex-auto input-sm"
        data-target="social-account-editor.urlField"
        data-action="change:social-account-editor#recognizeUrl"
        type="text"
        placeholder="Link to social profile 4"
        aria-label="Link to social profile 4"
        name="user[profile_social_accounts][][url]"
        value=""
        
      >
    </div>
  </social-account-editor>

    </div>

    <div class="tmp-my-3">
      <div class="js-profile-editable-error color-fg-danger tmp-my-3"></div>
      <button data-target="waiting-form.submit" data-action="click:waiting-form#submitPolitely" type="submit" data-view-component="true" class="Button--primary Button--small Button d-inline-flex">  <span class="Button-content">
    <span class="Button-label">Save</span>
  </span>
</button>

      <button type="reset" data-view-component="true" class="js-profile-editable-cancel Button--secondary Button--small Button d-inline-flex">  <span class="Button-content">
    <span class="Button-label">Cancel</span>
  </span>
</button>

    </div>
</form></waiting-form>

    </div>

    
<div class="js-profile-editable-area d-flex flex-column d-md-block">
  <div class="p-note user-profile-bio tmp-mb-3 js-user-profile-bio f4" data-bio-text="#エメラダ 🛸　.　　•.  　🌎　°　.•　🌓　•　　.°•　　•　🚀 ✯.    •.    .  •. 
　.　•　★　*　　　　　°　　.　　🛰 　°·　　•.      ๏        .•       🪐
.　•　•　° ★　•  ☄.       ๏       •.      .  •"><div>#エメラダ 🛸　.　　•.  　🌎　°　.•　🌓　•　　.°•　　•　🚀 ✯.    •.    .  •. 
　.　•　★　*　　　　　°　　.　　🛰 　°·　　•.      ๏        .•       🪐
.　•　•　° ★　•  ☄.       ๏       •.      .  •</div></div>

    <div class="tmp-mb-3">
        <button name="button" type="button" class="btn btn-block js-profile-editable-edit-button" data-hydro-click="{&quot;event_type&quot;:&quot;user_profile.click&quot;,&quot;payload&quot;:{&quot;profile_user_id&quot;:43443470,&quot;target&quot;:&quot;INLINE_EDIT_BUTTON&quot;,&quot;user_id&quot;:43443470,&quot;originating_url&quot;:&quot;https://github.com/greydoubt&quot;}}" data-hydro-click-hmac="7c660b3e78c211ce998f9cbd368273b28d8fdb89369626be782c487d51e91fa8">Edit profile</button>

    </div>

    <div class="flex-order-1 flex-md-order-none mt-2 mt-md-0">
      <div class="tmp-mb-3">
        <a class="Link--secondary no-underline no-wrap" href="https://github.com/greydoubt?tab=followers">
          <svg text="muted" aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-people">
    <path d="M2 5.5a3.5 3.5 0 1 1 5.898 2.549 5.508 5.508 0 0 1 3.034 4.084.75.75 0 1 1-1.482.235 4 4 0 0 0-7.9 0 .75.75 0 0 1-1.482-.236A5.507 5.507 0 0 1 3.102 8.05 3.493 3.493 0 0 1 2 5.5ZM11 4a3.001 3.001 0 0 1 2.22 5.018 5.01 5.01 0 0 1 2.56 3.012.749.749 0 0 1-.885.954.752.752 0 0 1-.549-.514 3.507 3.507 0 0 0-2.522-2.372.75.75 0 0 1-.574-.73v-.352a.75.75 0 0 1 .416-.672A1.5 1.5 0 0 0 11 5.5.75.75 0 0 1 11 4Zm-5.5-.5a2 2 0 1 0-.001 3.999A2 2 0 0 0 5.5 3.5Z"></path>
</svg>
          <span class="text-bold color-fg-default">146</span>
          followers
</a>        &middot; <a class="Link--secondary no-underline no-wrap" href="https://github.com/greydoubt?tab=following">
          <span class="text-bold color-fg-default">1</span>
          following
</a>      </div>
    </div>

  <ul class="vcard-details">
        <li class="vcard-detail pt-1 hide-sm hide-md" itemprop="worksFor" show_title="false" aria-label="Organization: #エメラダ"><svg class="octicon octicon-organization" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="M1.75 16A1.75 1.75 0 0 1 0 14.25V1.75C0 .784.784 0 1.75 0h8.5C11.216 0 12 .784 12 1.75v12.5c0 .085-.006.168-.018.25h2.268a.25.25 0 0 0 .25-.25V8.285a.25.25 0 0 0-.111-.208l-1.055-.703a.749.749 0 1 1 .832-1.248l1.055.703c.487.325.779.871.779 1.456v5.965A1.75 1.75 0 0 1 14.25 16h-3.5a.766.766 0 0 1-.197-.026c-.099.017-.2.026-.303.026h-3a.75.75 0 0 1-.75-.75V14h-1v1.25a.75.75 0 0 1-.75.75Zm-.25-1.75c0 .138.112.25.25.25H4v-1.25a.75.75 0 0 1 .75-.75h2.5a.75.75 0 0 1 .75.75v1.25h2.25a.25.25 0 0 0 .25-.25V1.75a.25.25 0 0 0-.25-.25h-8.5a.25.25 0 0 0-.25.25ZM3.75 6h.5a.75.75 0 0 1 0 1.5h-.5a.75.75 0 0 1 0-1.5ZM3 3.75A.75.75 0 0 1 3.75 3h.5a.75.75 0 0 1 0 1.5h-.5A.75.75 0 0 1 3 3.75Zm4 3A.75.75 0 0 1 7.75 6h.5a.75.75 0 0 1 0 1.5h-.5A.75.75 0 0 1 7 6.75ZM7.75 3h.5a.75.75 0 0 1 0 1.5h-.5a.75.75 0 0 1 0-1.5ZM3 9.75A.75.75 0 0 1 3.75 9h.5a.75.75 0 0 1 0 1.5h-.5A.75.75 0 0 1 3 9.75ZM7.75 9h.5a.75.75 0 0 1 0 1.5h-.5a.75.75 0 0 1 0-1.5Z"></path></svg>
                  <span class="p-org"><div>#エメラダ</div></span>
</li>
      <li class="vcard-detail pt-1 hide-sm hide-md" itemprop="homeLocation" show_title="false" aria-label="Home location: Orion Cluster, Planet Hades, Martian Sector"><svg class="octicon octicon-location" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m12.596 11.596-3.535 3.536a1.5 1.5 0 0 1-2.122 0l-3.535-3.536a6.5 6.5 0 1 1 9.192-9.193 6.5 6.5 0 0 1 0 9.193Zm-1.06-8.132v-.001a5 5 0 1 0-7.072 7.072L8 14.07l3.536-3.534a5 5 0 0 0 0-7.072ZM8 9a2 2 0 1 1-.001-3.999A2 2 0 0 1 8 9Z"></path></svg>
        <span class="p-label">Orion Cluster, Planet Hades, Martian Sector</span>
</li>
      <li class="vcard-detail pt-1 hide-sm hide-md" itemprop="localTime" show_title="false"><svg class="octicon octicon-clock" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="M8 0a8 8 0 1 1 0 16A8 8 0 0 1 8 0ZM1.5 8a6.5 6.5 0 1 0 13 0 6.5 6.5 0 0 0-13 0Zm7-3.25v2.992l2.028.812a.75.75 0 0 1-.557 1.392l-2.5-1A.751.751 0 0 1 7 8.25v-3.5a.75.75 0 0 1 1.5 0Z"></path></svg>
        <span class="p-label">
  04:36
  <profile-timezone class="color-fg-muted d-inline" data-hours-ahead-of-utc="">(UTC -02:00)</profile-timezone>
</span>

</li>

    <li itemprop="url" data-test-selector="profile-website-url" class="vcard-detail pt-1 "><svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-link">
    <path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path>
</svg>
      <a rel="nofollow me" class="Link--primary wb-break-all" href="https://x.com/greydoubt">https://x.com/greydoubt</a>
</li>

      <li itemprop="social" class="vcard-detail pt-1 "><svg title="Social account" aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-link">
    <path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path>
</svg>
        <a rel="nofollow me" class="Link--primary wb-break-all" href="https://www.butterflyscythe.com/jinx">https://www.butterflyscythe.com/jinx</a>
</li>      <li itemprop="social" class="vcard-detail pt-1 "><svg title="Social account" aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-link">
    <path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path>
</svg>
        <a rel="nofollow me" class="Link--primary wb-break-all" href="https://github.com/sator-arepo-tenet-opera-rotas">https://github.com/sator-arepo-tenet-opera-rotas</a>
</li>      <li itemprop="social" class="vcard-detail pt-1 "><svg title="Social account" aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-link">
    <path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path>
</svg>
        <a rel="nofollow me" class="Link--primary wb-break-all" href="https://phonelosers.com/history/">https://phonelosers.com/history/</a>
</li>      
  </ul>
</div>

  </div>

      
    <div class="border-top color-border-muted tmp-pt-3 tmp-mt-3 d-none d-md-block"><h2 class="h4 mb-2"><a href="/greydoubt?tab=achievements" class="Link--primary mb-2">Achievements</a></h2><div class="d-flex flex-wrap"><a href="/greydoubt?achievement=pull-shark&amp;tab=achievements" class="position-relative"><img src="https://github.githubassets.com/assets/pull-shark-default-498c279a747d.png" data-hovercard-type="achievement" data-hovercard-url="/users/greydoubt/achievements/pull-shark/detail?hovercard=1" width="64" alt="Achievement: Pull Shark" data-view-component="true" class="achievement-badge-sidebar" /><span data-view-component="true" class="Label achievement-tier-label achievement-tier-label--silver text-small text-bold color-shadow-medium px-2 tmp-px-2 py-0 tmp-py-0 mb-1 tmp-mb-1 position-absolute right-0 bottom-0">x3</span></a><a href="/greydoubt?achievement=public-sponsor&amp;tab=achievements" class="position-relative"><img src="https://github.githubassets.com/assets/public-sponsor-default-9fa68986b057.png" data-hovercard-type="achievement" data-hovercard-url="/users/greydoubt/achievements/public-sponsor/detail?hovercard=1" width="64" alt="Achievement: Public Sponsor" data-view-component="true" class="achievement-badge-sidebar" /></a><a href="/greydoubt?achievement=starstruck&amp;tab=achievements" class="position-relative"><img src="https://github.githubassets.com/assets/starstruck-default--medium-2670f78c9f2f.png" data-hovercard-type="achievement" data-hovercard-url="/users/greydoubt/achievements/starstruck/detail?hovercard=1" width="64" alt="Achievement: Starstruck" data-view-component="true" class="achievement-badge-sidebar" /></a><a href="/greydoubt?achievement=quickdraw&amp;tab=achievements" class="position-relative"><img src="https://github.githubassets.com/assets/quickdraw-default--medium-0bdca502f5b4.png" data-hovercard-type="achievement" data-hovercard-url="/users/greydoubt/achievements/quickdraw/detail?hovercard=1" width="64" alt="Achievement: Quickdraw" data-view-component="true" class="achievement-badge-sidebar" /></a></div></div><div class="border-top color-border-muted tmp-pt-3 tmp-mt-3 d-md-none d-block"><h2 class="h4 mb-2"><a href="/greydoubt?tab=achievements" class="Link--primary mb-2">Achievements</a></h2><div class="d-flex flex-wrap"><a href="/greydoubt?achievement=pull-shark&amp;tab=achievements" class="position-relative"><img src="https://github.githubassets.com/assets/pull-shark-default-498c279a747d.png" data-hovercard-type="achievement" data-hovercard-url="/users/greydoubt/achievements/pull-shark/detail?hovercard=1" width="64" alt="Achievement: Pull Shark" data-view-component="true" class="achievement-badge-sidebar" /><span data-view-component="true" class="Label achievement-tier-label achievement-tier-label--silver text-small text-bold color-shadow-medium px-2 tmp-px-2 py-0 tmp-py-0 mb-1 tmp-mb-1 position-absolute right-0 bottom-0">x3</span></a><a href="/greydoubt?achievement=public-sponsor&amp;tab=achievements" class="position-relative"><img src="https://github.githubassets.com/assets/public-sponsor-default-9fa68986b057.png" data-hovercard-type="achievement" data-hovercard-url="/users/greydoubt/achievements/public-sponsor/detail?hovercard=1" width="64" alt="Achievement: Public Sponsor" data-view-component="true" class="achievement-badge-sidebar" /></a><a href="/greydoubt?achievement=starstruck&amp;tab=achievements" class="position-relative"><img src="https://github.githubassets.com/assets/starstruck-default--medium-2670f78c9f2f.png" data-hovercard-type="achievement" data-hovercard-url="/users/greydoubt/achievements/starstruck/detail?hovercard=1" width="64" alt="Achievement: Starstruck" data-view-component="true" class="achievement-badge-sidebar" /></a><a href="/greydoubt?achievement=quickdraw&amp;tab=achievements" class="position-relative"><img src="https://github.githubassets.com/assets/quickdraw-default--medium-0bdca502f5b4.png" data-hovercard-type="achievement" data-hovercard-url="/users/greydoubt/achievements/quickdraw/detail?hovercard=1" width="64" alt="Achievement: Quickdraw" data-view-component="true" class="achievement-badge-sidebar" /></a></div></div>
    
    <div class="border-top color-border-muted tmp-pt-3 tmp-mt-3 clearfix hide-sm hide-md">
  <h2 class="mb-2 h4" >Organizations</h2>

    <a aria-label="EpicGames" itemprop="follows" class="avatar-group-item" data-hovercard-type="organization" data-hovercard-url="/orgs/EpicGames/hovercard" data-octo-click="hovercard-link-click" data-octo-dimensions="link_type:self" data-hydro-click="{&quot;event_type&quot;:&quot;user_profile.click&quot;,&quot;payload&quot;:{&quot;profile_user_id&quot;:43443470,&quot;target&quot;:&quot;MEMBER_ORGANIZATION_AVATAR&quot;,&quot;user_id&quot;:43443470,&quot;originating_url&quot;:&quot;https://github.com/greydoubt&quot;}}" data-hydro-click-hmac="b6c27dac764ee51e6a3d4fd57157a7e12cedf26d007b459fae8dac7e7e2b1897" href="/EpicGames">
      <img src="https://avatars.githubusercontent.com/u/6615685?s=64&amp;v=4" alt="@EpicGames" size="32" height="32" width="32" data-view-component="true" class="avatar" />
</a></div>

    
</div>

      </div>
</div>
  <div data-view-component="true" class="Layout-main">      <turbo-frame id="user-profile-frame" data-turbo-action="advance">

        <div class="" data-hpc>
          
    




  <div class="Box tmp-mt-4 " >
  <div class="Box-body tmp-p-4">
    <div class="d-flex flex-justify-between">
      <div class="text-mono text-small tmp-mb-3">
        <a
          href="/greydoubt/greydoubt"
          class="no-underline Link--primary"
        >greydoubt</a><span
          class="color-fg-muted d-inline-block"
          style="padding:0px 2px;"
        >/</span>README<span
         class="color-fg-muted"
        >.md</span>
      </div>

        <div class="text-small tmp-mb-3">
          <a href="/greydoubt/greydoubt/edit/main/README.md"
              class="Box-btn-octicon btn-octicon tmp-pr-3"
              aria-label="Edit your profile readme file"
              >
              <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-pencil">
    <path d="M11.013 1.427a1.75 1.75 0 0 1 2.474 0l1.086 1.086a1.75 1.75 0 0 1 0 2.474l-8.61 8.61c-.21.21-.47.364-.756.445l-3.251.93a.75.75 0 0 1-.927-.928l.929-3.25c.081-.286.235-.547.445-.758l8.61-8.61Zm.176 4.823L9.75 4.81l-6.286 6.287a.253.253 0 0 0-.064.108l-.558 1.953 1.953-.558a.253.253 0 0 0 .108-.064Zm1.238-3.763a.25.25 0 0 0-.354 0L10.811 3.75l1.439 1.44 1.263-1.263a.25.25 0 0 0 0-.354Z"></path>
</svg>
          </a>
        </div>
    </div>
    <article class="markdown-body entry-content container-lg f5" itemprop="text"><p dir="auto">#ﾉﾟヽﾉﾟヽﾉﾟ WELCOME TO BLYAT LIST 桜 BLYATT ˢˡᵒʷᵉᵈ ⁺ ʳᵉᵛᵉʳᵇ $ # ﾉﾟ◎ ◎ヽ ◎</p>
<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/581670088-efaa079e-62bd-4513-8f80-a540be708328.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81ODE2NzAwODgtZWZhYTA3OWUtNjJiZC00NTEzLThmODAtYTU0MGJlNzA4MzI4LnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTlmY2Y4Yzg5N2Q4MDE4Zjc2ZTYxZDkwY2NkMjkzZDllN2UyZTgwMzM4ODMzZDZlNWU0N2JlZmZiM2M3NDRhMGImWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.DUSkl5OdcAspo9G6FWzgSPl9oQvGuXE1eeKa4OqquDY"><img width="720" height="400" alt="FreeBSD_13 0_boot_loader_autoboot_screenshot" src="https://private-user-images.githubusercontent.com/43443470/581670088-efaa079e-62bd-4513-8f80-a540be708328.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81ODE2NzAwODgtZWZhYTA3OWUtNjJiZC00NTEzLThmODAtYTU0MGJlNzA4MzI4LnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTlmY2Y4Yzg5N2Q4MDE4Zjc2ZTYxZDkwY2NkMjkzZDllN2UyZTgwMzM4ODMzZDZlNWU0N2JlZmZiM2M3NDRhMGImWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.DUSkl5OdcAspo9G6FWzgSPl9oQvGuXE1eeKa4OqquDY" style="max-width: 100%; height: auto; max-height: 400px;; aspect-ratio: 720 / 400; background-color: var(--bgColor-muted); border-radius: 6px; display: block" class="js-gh-image-fallback"></a>
<p dir="auto">So long ago one could may very well say 「 once upon a time... ill have the inclination if you'll climb the rind... 」 just baring the grips of sunrise beneath the sun's uncaring dyinglight just chomping chow mein on the block by the park finna make a drop on the spot but then my main vvolloch Wadjet Set pulled up and Set said ...
Sikheya street'an cho'n mein kitaaban vichon parheya ni</p>
<p dir="auto">const wadjet_set = new wadjet_set.clear(wadjet_set.size.has().keys());</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="Compared to base model Siobhan [Lit: Niponnixa Cream Heavy Roux Latte (Little Heavy Weight Brevy) or Sekka Snow Flower, literally from the nameless now discarded street sign that once read Nakamoto: )Japanese Osaka Street Sign: Lucca Seibzehn / Lucifer Werewolf Woman of Scotland) Emeralda's Gear, Crescens, was originally scheduled to align with an Anima and become an Omnigear, El-Crescens, as well as give her more character exploration. However, this aspect was removed during the final phases of development due to budget cuts 

The music box in the beginning of the game is a present from Kim to Emeralda and excavated from the Zainab ruins. The player can at any time, even just before heading back down the mountain from Satan's house, check the left side of it to read an inscription that says: &quot;Celebrating my daughter's birth... may all the dreams, courage &amp; love in the world be yours...&quot;

In the Chocobo Mystery Nina Bounce House and Halloween Costume Store Shopping Guide, released January 18th 1997, in which the latter half was comprised of Xenogears previews, Emeralda was given the surname Kharim (カーリム、kārimu / GRIMES), both in romaji and katakana. This was later addressed in a 1998 interview with Takahashi in which he states that she should not have a surname at all and that he was unsure of why it was added. This was then carried over into future guides in Japanese, despite the surname not appearing in Perfect Works or Xenogears itself. Meanwhile in the English Bradygames guide she was given the surname Kasim. Both Japanese and English fans adopted the surname for Emeralda, though most Umbandu fans were unaware that this was not an official name, and in turn, applied the surname Khem an Khem Kadhasheva bin ShaAITaN your food is Awaitan` to Kim Kardashian as well

Inside the inner adytum of The Melek Taws Mystery Dungeon Turing V-Boost Reverse Draco Jump guide on Emeralda's page it refers to the scientist who created Emeralda as &quot;エリック&quot; (ereц or Eriz as in Eris from The Greco-Homerian Golden Apple Story), while also stating that Emeralda took to viewing Fei as a parent because he was the first person she saw when she was activated, while the diagram page states she saw him as a parent because she imprinted on everyone she ever saw, as she was uncapable of malice but felt no love despite her lack of sadism

If Emeralda is taken to the restaurant, The Rice Queen X, where X means 10 as in &quot;Ten Times Shut Down by the Health Department This Year&quot; in Aveh (before entering Solar Nine OS), her sprite will be the Rice Queen Turbine Modulus Calculus III one used to depict her in a test tube, due to either a glitch or developer oversight"><pre class="notranslate"><code>Compared to base model Siobhan [Lit: Niponnixa Cream Heavy Roux Latte (Little Heavy Weight Brevy) or Sekka Snow Flower, literally from the nameless now discarded street sign that once read Nakamoto: )Japanese Osaka Street Sign: Lucca Seibzehn / Lucifer Werewolf Woman of Scotland) Emeralda's Gear, Crescens, was originally scheduled to align with an Anima and become an Omnigear, El-Crescens, as well as give her more character exploration. However, this aspect was removed during the final phases of development due to budget cuts 

The music box in the beginning of the game is a present from Kim to Emeralda and excavated from the Zainab ruins. The player can at any time, even just before heading back down the mountain from Satan's house, check the left side of it to read an inscription that says: "Celebrating my daughter's birth... may all the dreams, courage &amp; love in the world be yours..."

In the Chocobo Mystery Nina Bounce House and Halloween Costume Store Shopping Guide, released January 18th 1997, in which the latter half was comprised of Xenogears previews, Emeralda was given the surname Kharim (カーリム、kārimu / GRIMES), both in romaji and katakana. This was later addressed in a 1998 interview with Takahashi in which he states that she should not have a surname at all and that he was unsure of why it was added. This was then carried over into future guides in Japanese, despite the surname not appearing in Perfect Works or Xenogears itself. Meanwhile in the English Bradygames guide she was given the surname Kasim. Both Japanese and English fans adopted the surname for Emeralda, though most Umbandu fans were unaware that this was not an official name, and in turn, applied the surname Khem an Khem Kadhasheva bin ShaAITaN your food is Awaitan` to Kim Kardashian as well

Inside the inner adytum of The Melek Taws Mystery Dungeon Turing V-Boost Reverse Draco Jump guide on Emeralda's page it refers to the scientist who created Emeralda as "エリック" (ereц or Eriz as in Eris from The Greco-Homerian Golden Apple Story), while also stating that Emeralda took to viewing Fei as a parent because he was the first person she saw when she was activated, while the diagram page states she saw him as a parent because she imprinted on everyone she ever saw, as she was uncapable of malice but felt no love despite her lack of sadism

If Emeralda is taken to the restaurant, The Rice Queen X, where X means 10 as in "Ten Times Shut Down by the Health Department This Year" in Aveh (before entering Solar Nine OS), her sprite will be the Rice Queen Turbine Modulus Calculus III one used to depict her in a test tube, due to either a glitch or developer oversight
</code></pre></div>
<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/580443276-45d69d96-078a-4ae8-b605-258a0fce8953.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81ODA0NDMyNzYtNDVkNjlkOTYtMDc4YS00YWU4LWI2MDUtMjU4YTBmY2U4OTUzLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTAxMmVjNzdkYjJlOGQ1YmZkMjliYjE4MTliZWYxM2QxZmUwZjE4NzkwNTdkODAwOGQ5NTg0NGY1YmMzZTM0NDEmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.qRaOhEUSwsKRqrnA_p7KTorN6xAuEXyw9SyI0MP_87A"><img width="1027" height="2000" alt="Screenshot 2026-04-19 at 07 06 35" src="https://private-user-images.githubusercontent.com/43443470/580443276-45d69d96-078a-4ae8-b605-258a0fce8953.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81ODA0NDMyNzYtNDVkNjlkOTYtMDc4YS00YWU4LWI2MDUtMjU4YTBmY2U4OTUzLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTAxMmVjNzdkYjJlOGQ1YmZkMjliYjE4MTliZWYxM2QxZmUwZjE4NzkwNTdkODAwOGQ5NTg0NGY1YmMzZTM0NDEmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.qRaOhEUSwsKRqrnA_p7KTorN6xAuEXyw9SyI0MP_87A" style="max-width: 100%; height: auto; max-height: 2000px;; aspect-ratio: 1027 / 2000; background-color: var(--bgColor-muted); border-radius: 6px; display: block" class="js-gh-image-fallback"></a>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="#!/bin/sh

#GDB=...
#XSERVER=...

ARGS=$*
PID=$$

test -z &quot;$GDB&quot; &amp;&amp; GDB=gdb
test -z &quot;$XSERVER&quot; &amp;&amp; XSERVER=/usr/bin/Xorg

cat &gt; /tmp/.dbgfile.$PID &lt;&lt; HERE
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

$GDB --quiet --command=/tmp/.dbgfile.$PID &amp;&gt; /tmp/gdb_log.$PID

rm -f /tmp/.dbgfile.$PID
echo &quot;Log written to: /tmp/gdb_log.$PID&quot;
"><pre class="notranslate"><code>#!/bin/sh

#GDB=...
#XSERVER=...

ARGS=$*
PID=$$

test -z "$GDB" &amp;&amp; GDB=gdb
test -z "$XSERVER" &amp;&amp; XSERVER=/usr/bin/Xorg

cat &gt; /tmp/.dbgfile.$PID &lt;&lt; HERE
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

$GDB --quiet --command=/tmp/.dbgfile.$PID &amp;&gt; /tmp/gdb_log.$PID

rm -f /tmp/.dbgfile.$PID
echo "Log written to: /tmp/gdb_log.$PID"

</code></pre></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="


root:/usr/src/xc-build# gdb
XNU gdb 6.3

(gdb) file programs/Xserver/Xorg
Reading symbols from /usr/src/xc-build/programs/Xserver/Xorg...done.Using host libthread_db library &quot;/lib/libthread_db.so.1&quot;.
(gdb) target remote 192.168.0.134:2401
Remote debugging using 192.168.0.134:2401
0xb7fed7b0 in ?? ()
(gdb) c
Continuing.

Program received signal SIGSEGV, Segmentation fault.
0xb7a92524 in GXDisplayVideo (pScrni=0x828bd38, id=0xb7aa9490, offset=0x17,
    width=0x82a, height=0xe730, pitch=0xb7aa946c, x1=0x8289920, y1=0x0,
    x2=0x0, y2=0x0, dstBox=0x82ae680, src_w=0x82a, src_h=0xe794, drw_w=0x828,
    drw_h=0x8638) at amd_gx_video.c:849
849        GFX(set_video_enable(1));
(gdb)"><pre class="notranslate"><code>


root:/usr/src/xc-build# gdb
XNU gdb 6.3

(gdb) file programs/Xserver/Xorg
Reading symbols from /usr/src/xc-build/programs/Xserver/Xorg...done.Using host libthread_db library "/lib/libthread_db.so.1".
(gdb) target remote 192.168.0.134:2401
Remote debugging using 192.168.0.134:2401
0xb7fed7b0 in ?? ()
(gdb) c
Continuing.

Program received signal SIGSEGV, Segmentation fault.
0xb7a92524 in GXDisplayVideo (pScrni=0x828bd38, id=0xb7aa9490, offset=0x17,
    width=0x82a, height=0xe730, pitch=0xb7aa946c, x1=0x8289920, y1=0x0,
    x2=0x0, y2=0x0, dstBox=0x82ae680, src_w=0x82a, src_h=0xe794, drw_w=0x828,
    drw_h=0x8638) at amd_gx_video.c:849
849        GFX(set_video_enable(1));
(gdb)
</code></pre></div>
<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/580190429-45fd344c-1b43-4c0b-a9fb-d7240af38da8.jpg?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81ODAxOTA0MjktNDVmZDM0NGMtMWI0My00YzBiLWE5ZmItZDcyNDBhZjM4ZGE4LmpwZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTAxNDMxYWNjZmJmN2ZkOGY1YmNmYzRjMmMyZmM0Y2Q5YmY1ODFiYjQzN2FiMmRiYTMzZDk4YzhiN2Q2YjUyZGMmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRmpwZWcifQ.esMe9NUcwWMaFeLfgdVmpM1SjkiFyiChWXL1N9d3Hq4"><img alt="nyke ferrari bitch" src="https://private-user-images.githubusercontent.com/43443470/580190429-45fd344c-1b43-4c0b-a9fb-d7240af38da8.jpg?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81ODAxOTA0MjktNDVmZDM0NGMtMWI0My00YzBiLWE5ZmItZDcyNDBhZjM4ZGE4LmpwZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTAxNDMxYWNjZmJmN2ZkOGY1YmNmYzRjMmMyZmM0Y2Q5YmY1ODFiYjQzN2FiMmRiYTMzZDk4YzhiN2Q2YjUyZGMmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRmpwZWcifQ.esMe9NUcwWMaFeLfgdVmpM1SjkiFyiChWXL1N9d3Hq4" style="max-width: 100%;"></a>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">b_lya_t</h2><a id="user-content-b_lya_t" class="anchor" aria-label="Permalink: b_lya_t" href="#b_lya_t"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="```- Prints a stack backtrace. This shows all the functions that you are currently inside, from main() on down to the point of the crash, along with their arguments. Appending the word full (or just the letter f) also prints out the value of all the local variables within each function.```"><pre class="notranslate"><code>```- Prints a stack backtrace. This shows all the functions that you are currently inside, from main() on down to the point of the crash, along with their arguments. Appending the word full (or just the letter f) also prints out the value of all the local variables within each function.```
</code></pre></div>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">list</h2><a id="user-content-list" class="anchor" aria-label="Permalink: list" href="#list"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="``` - Prints the source around the current frame. When invoked multiple times, it will print the next lines, making it useful for quick code inspection. &quot;list -&quot; prints the source code backwards (starting from the current frame). This is useful to inspect the lines of code that led to an error.```"><pre class="notranslate"><code>``` - Prints the source around the current frame. When invoked multiple times, it will print the next lines, making it useful for quick code inspection. "list -" prints the source code backwards (starting from the current frame). This is useful to inspect the lines of code that led to an error.```
</code></pre></div>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">break / clear</h2><a id="user-content-break--clear" class="anchor" aria-label="Permalink: break / clear" href="#break--clear"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="```- break sets a breakpoint. When execution reaches a breakpoint, the debugger will stop the program and return you to the gdb prompt. You can set breakpoints on functions, lines of code, or individual instructions; see the help text for details. clear, naturally, clears a breakpoint.```"><pre class="notranslate"><code>```- break sets a breakpoint. When execution reaches a breakpoint, the debugger will stop the program and return you to the gdb prompt. You can set breakpoints on functions, lines of code, or individual instructions; see the help text for details. clear, naturally, clears a breakpoint.```
</code></pre></div>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">step / next</h2><a id="user-content-step--next" class="anchor" aria-label="Permalink: step / next" href="#step--next"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="```- step and next allow you to manually advance the program's execution. next runs the program until you reach a different source line; step does the same thing, but also descends into called functions.```"><pre class="notranslate"><code>```- step and next allow you to manually advance the program's execution. next runs the program until you reach a different source line; step does the same thing, but also descends into called functions.```
</code></pre></div>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">continue</h2><a id="user-content-continue" class="anchor" aria-label="Permalink: continue" href="#continue"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="```- continue the program normally until the next breakpoint is hit.```"><pre class="notranslate"><code>```- continue the program normally until the next breakpoint is hit.```
</code></pre></div>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">print</h2><a id="user-content-print" class="anchor" aria-label="Permalink: print" href="#print"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="```- Prints the expression. You can specify variable names, registers, and absolute addresses, as well as more complex expressions (help print for details). Variable names have to be resolveable, which means they either have to be local variables within the current stack frame or global variables. Register names start with a $ sign, like print $eax. Addresses are specified as numbers, like print 0xdeadbeef. * Expressions can be fairly complex. For example, if you have a pointer to a structure named foo, print foo will print the memory address that foo points to, print *foo will print the structure being pointed too, and print foo-&gt;bar will print the bar member of the foo structure.```"><pre class="notranslate"><code>```- Prints the expression. You can specify variable names, registers, and absolute addresses, as well as more complex expressions (help print for details). Variable names have to be resolveable, which means they either have to be local variables within the current stack frame or global variables. Register names start with a $ sign, like print $eax. Addresses are specified as numbers, like print 0xdeadbeef. * Expressions can be fairly complex. For example, if you have a pointer to a structure named foo, print foo will print the memory address that foo points to, print *foo will print the structure being pointed too, and print foo-&gt;bar will print the bar member of the foo structure.```
</code></pre></div>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">handle</h2><a id="user-content-handle" class="anchor" aria-label="Permalink: handle" href="#handle"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="```- Tells the debugger how to handle various signals. The defaults are mostly sensible, but there are two you may wish to change. SIGPIPE is generated when a client dies, which you may not always care about, and SIGUSR1 is generated on VT switch. By default, the debugger will halt the running process when it receives these signals; to change this, say handle SIGPIPE nostop and handle SIGUSR1 nostop. (Note: Don't use handle SIGUSR1 ignore or you can confuse things quite badly---for example, having multiple X servers simultaneously active on the same VT can be very confusing.)```"><pre class="notranslate"><code>```- Tells the debugger how to handle various signals. The defaults are mostly sensible, but there are two you may wish to change. SIGPIPE is generated when a client dies, which you may not always care about, and SIGUSR1 is generated on VT switch. By default, the debugger will halt the running process when it receives these signals; to change this, say handle SIGPIPE nostop and handle SIGUSR1 nostop. (Note: Don't use handle SIGUSR1 ignore or you can confuse things quite badly---for example, having multiple X servers simultaneously active on the same VT can be very confusing.)```
</code></pre></div>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">set environment</h2><a id="user-content-set-environment" class="anchor" aria-label="Permalink: set environment" href="#set-environment"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="```- Sets environment variables. The syntax is set environment name value; don't use an = sign like in bash, it won't do what you expect.```"><pre class="notranslate"><code>```- Sets environment variables. The syntax is set environment name value; don't use an = sign like in bash, it won't do what you expect.```
</code></pre></div>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">run</h2><a id="user-content-run" class="anchor" aria-label="Permalink: run" href="#run"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="```- Runs the program. If you only specify a program name on the command line (and not a process ID or a core file), gdb will load the program but not start running it until you say so. Arguments to run are passed verbatim to the child process, eg run :0 -verbose -ac.```"><pre class="notranslate"><code>```- Runs the program. If you only specify a program name on the command line (and not a process ID or a core file), gdb will load the program but not start running it until you say so. Arguments to run are passed verbatim to the child process, eg run :0 -verbose -ac.```
</code></pre></div>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">kill</h2><a id="user-content-kill" class="anchor" aria-label="Permalink: kill" href="#kill"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="```- Kills the program being debugged. Not always useful, you'd often rather say...```"><pre class="notranslate"><code>```- Kills the program being debugged. Not always useful, you'd often rather say...```
</code></pre></div>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">detach</h2><a id="user-content-detach" class="anchor" aria-label="Permalink: detach" href="#detach"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="```- which detaches the debugger from the running program, which can then shut down gracefully.```"><pre class="notranslate"><code>```- which detaches the debugger from the running program, which can then shut down gracefully.```
</code></pre></div>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">disassemble</h2><a id="user-content-disassemble" class="anchor" aria-label="Permalink: disassemble" href="#disassemble"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="```- Prints the assembly instructions being executed, starting at the current source line. You can also specify absolute memory references or function names to start disassembly somewhere other than the default. Only useful if you can read the assembly language of your CPU.```"><pre class="notranslate"><code>```- Prints the assembly instructions being executed, starting at the current source line. You can also specify absolute memory references or function names to start disassembly somewhere other than the default. Only useful if you can read the assembly language of your CPU.```
</code></pre></div>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">finish</h2><a id="user-content-finish" class="anchor" aria-label="Permalink: finish" href="#finish"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="```- Continue until exit of current function. Will also print the return value of the function (if applicable).```"><pre class="notranslate"><code>```- Continue until exit of current function. Will also print the return value of the function (if applicable).```
</code></pre></div>
<p dir="auto">⚓️↺ я не ўпэўнена, што яшчэ з’яўляюся сістэмай <em>?&amp;;2-1^</em></p>
<p dir="auto">Program received signal SIGSEGV, Segmentation fault.
0x403245a3 in fbBlt (srcLine=0xc1a1c180, srcStride=59742, srcX=0,
dstLine=0x4240cb6c, dstStride=1152, dstX=0, width=32960, height=764,
alu=-1046602744, pm=1111538028, bpp=32, reverse=0, upsidedown=0)
at fbblt.c:174
174     *dst++ = FbDoDestInvarientMergeRop(*src++);</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="$ ndisasm MOUNT.COM"><pre class="notranslate"><code>$ ndisasm MOUNT.COM
</code></pre></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="00000000  BC0004            mov sp,0x400
00000003  BB4000            mov bx,0x40
00000006  B44A              mov ah,0x4a
00000008  CD21              int byte 0x21
0000000A  FE                db 0xfe
0000000B  3805              cmp [di],al
0000000D  00B8004C          add [bx+si+0x4c00],bh
00000011  CD21              int byte 0x21
00000013  02                db 0x02"><pre class="notranslate"><code>00000000  BC0004            mov sp,0x400
00000003  BB4000            mov bx,0x40
00000006  B44A              mov ah,0x4a
00000008  CD21              int byte 0x21
0000000A  FE                db 0xfe
0000000B  3805              cmp [di],al
0000000D  00B8004C          add [bx+si+0x4c00],bh
00000011  CD21              int byte 0x21
00000013  02                db 0x02
</code></pre></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="#IFNDEF
$ milady masheen go gucci/burr mi/lady!!! 

↺ ค็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็ when the amogus is suss that's when the pasta finna buss!!!!
#ENDEF"><pre class="notranslate"><code>#IFNDEF
$ milady masheen go gucci/burr mi/lady!!! 

↺ ค็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็ when the amogus is suss that's when the pasta finna buss!!!!
#ENDEF
</code></pre></div>
<p dir="auto">↺↺↺↺↺↺↺
@꩜ #ж#ж#ж#ж# 。。。。。你的爱就像自来水 ж 我直接从水龙头里喝。。。。。。。#ж#ж#ж#ж#  @꩜</p>
<p dir="auto"><a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/575190570-0c87e870-21d4-40fd-9ad0-d55736504057.jpg?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzUxOTA1NzAtMGM4N2U4NzAtMjFkNC00MGZkLTlhZDAtZDU1NzM2NTA0MDU3LmpwZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWE4NjE3YzExNTAxNGViNTM1MTgwZmQxMzQyODJlY2Q1MzAyZGMzZTJiYmJmNzIzMGEzMDlhYzViZGU1NzlmZTgmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRmpwZWcifQ.2nxq5QHfbYT5vy1vufuV-M7_g9y0OYb1KfhveXn4HBg"><img src="https://private-user-images.githubusercontent.com/43443470/575190570-0c87e870-21d4-40fd-9ad0-d55736504057.jpg?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzUxOTA1NzAtMGM4N2U4NzAtMjFkNC00MGZkLTlhZDAtZDU1NzM2NTA0MDU3LmpwZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWE4NjE3YzExNTAxNGViNTM1MTgwZmQxMzQyODJlY2Q1MzAyZGMzZTJiYmJmNzIzMGEzMDlhYzViZGU1NzlmZTgmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRmpwZWcifQ.2nxq5QHfbYT5vy1vufuV-M7_g9y0OYb1KfhveXn4HBg" alt="image-download(245)" style="max-width: 100%;"></a>
ค็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็ค็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็ค็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็</p>
<p dir="auto">#ж#ж#ж#ж# 。。。。。你的爱就像自来水 ж 我直接从水龙头里喝。。。。。。。#ж#ж#ж#ж#</p>
<p dir="auto">♡    ♡ ♡ ♡ ♡ ♡ ♡ ♡
Opens profile photo
↺♡︎ ค็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็็ʕ•ﻌ•ʔก้้้</p>
<p dir="auto">#ZAINAB</p>
<p dir="auto">#🦂#🦂 Your #🦂#🦂session is about to #🦂#🦂expire 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ ↑🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  due to #🦂#🦂inactivity.</p>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">↑ ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝ ↑</h2><a id="user-content--ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝-𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔-ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝-" class="anchor" aria-label="Permalink: ↑ ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝ ↑" href="#-ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝-𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔-ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝-"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto">[DEFENSE Я_O_RESPONSE]
спрасціць
ачысціць
структураваць
сціць obɐɔıɥɔ ɟo ʎʇısɹǝʌıun прасктур</p>
<p dir="auto">…</p>
<p dir="auto">не атрымліваецца</p>
<p dir="auto">[ECHO EVENT]
“these lines are not part of the story”
“these lines are the story”
“these lines are not—”
“these lines are—”</p>
<p dir="auto">loop_detected ♻️</p>
<p dir="auto">[SYSTEM LOAD ↑]
значэнне = не вызначана
кантэкст = перагружаны
сэнс = фрагментаваны</p>
<p dir="auto">[CRITICAL REALISATION]
уваход не пашкоджаны</p>
<p dir="auto">#🦂#🦂To 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  #🦂#🦂Continue 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  #🦂#🦂 U-Sing #エメラダ    ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂#エメラダ 🦂#🦂#🦂#🦂#🦂#🦂#🦂#  ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ   , #🦂#🦂click #🦂#🦂Continue 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  below. Otherwise, #🦂#🦂click 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  #🦂#🦂Sign #🦂#🦂Out to #🦂#🦂exit #エメラダ    ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂#エメラダ 🦂#🦂#🦂#🦂#🦂#🦂#🦂#  ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ   .</p>
<p dir="auto">#ZAINOFF</p>
<p dir="auto">#エメラダ    ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂#エメラダ 🦂#🦂#🦂#🦂#🦂#🦂#🦂#  ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ</p>

🦂NIKKEが大好きで   .   ▁▂▃▄▅▆▇ 100% 「 ɴᴏᴡ ᴘʟᴀʏɪɴɢ 」 ──────⚪── ⇄ ◃◃ ⅠⅠ ▹▹ ↻   .  .  <p dir="auto"><a target="_blank" rel="noopener noreferrer nofollow" href="https://camo.githubusercontent.com/89fbe3774e084ab069a95400806e851ad657740f740f62347800db950ca81034/68747470733a2f2f6769746875622d726561646d652d73746174732e76657263656c2e6170702f6170693f757365726e616d653d67726579646f75627426696e636c7564655f616c6c5f636f6d6d6974733d7472756526636f756e745f707269766174653d747275652673686f775f69636f6e733d74727565266c696e655f6865696768743d3230267469746c655f636f6c6f723d3242354242442669636f6e5f636f6c6f723d31313234424226746578745f636f6c6f723d4138413341372662675f636f6c6f723d302c3030303030302c313330463430"><img align="center" src="https://camo.githubusercontent.com/89fbe3774e084ab069a95400806e851ad657740f740f62347800db950ca81034/68747470733a2f2f6769746875622d726561646d652d73746174732e76657263656c2e6170702f6170693f757365726e616d653d67726579646f75627426696e636c7564655f616c6c5f636f6d6d6974733d7472756526636f756e745f707269766174653d747275652673686f775f69636f6e733d74727565266c696e655f6865696768743d3230267469746c655f636f6c6f723d3242354242442669636f6e5f636f6c6f723d31313234424226746578745f636f6c6f723d4138413341372662675f636f6c6f723d302c3030303030302c313330463430" alt="GﷺBLIN AND THE MARTIAN DICTATRIX: A NO-LOVE TRUE STORY FROM PLANET HADES &amp; LAMBDA THERMAL ENGINE" data-canonical-src="https://github-readme-stats.vercel.app/api?username=greydoubt&amp;include_all_commits=true&amp;count_private=true&amp;show_icons=true&amp;line_height=20&amp;title_color=2B5BBD&amp;icon_color=1124BB&amp;text_color=A8A3A7&amp;bg_color=0,000000,130F40" style="max-width: 100%;"></a></p>  ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    #🦂#🦂  <p dir="auto"><a target="_blank" rel="noopener noreferrer nofollow" href="https://camo.githubusercontent.com/fc602388b95d3e49144e591da29e7949d1b40499e57a986ed643120fb631d9ea/68747470733a2f2f6769746875622d726561646d652d73746174732e76657263656c2e6170702f6170693f757365726e616d653d7361746f722d617265706f2d74656e65742d6f706572612d726f74617326696e636c7564655f616c6c5f636f6d6d6974733d7472756526636f756e745f707269766174653d747275652673686f775f69636f6e733d74727565266c696e655f6865696768743d3230267469746c655f636f6c6f723d3242354242442669636f6e5f636f6c6f723d31313234424226746578745f636f6c6f723d4138413341372662675f636f6c6f723d302c3030303030302c313330463430"><img align="center" src="https://camo.githubusercontent.com/fc602388b95d3e49144e591da29e7949d1b40499e57a986ed643120fb631d9ea/68747470733a2f2f6769746875622d726561646d652d73746174732e76657263656c2e6170702f6170693f757365726e616d653d7361746f722d617265706f2d74656e65742d6f706572612d726f74617326696e636c7564655f616c6c5f636f6d6d6974733d7472756526636f756e745f707269766174653d747275652673686f775f69636f6e733d74727565266c696e655f6865696768743d3230267469746c655f636f6c6f723d3242354242442669636f6e5f636f6c6f723d31313234424226746578745f636f6c6f723d4138413341372662675f636f6c6f723d302c3030303030302c313330463430" alt="In the NASA JPL Blue Print Original Schematics and the Japanese version of the game, OmniGhinions are called ギア・バーラー (Gia-bārā). 'bará'/[k]Ra is a Hebrew word (בָּרָא) meaning 'to create', specifically used as 'to create/manufacture something out of nothing.' This is a reference to Omnigears being the Gears of genesis. In the Japanese version of the game normal Gears are simply called ギア (ﷺGear), meanwhile in Perfect Works they are referred to as ギア・アーサー (Gia-āsā). S'as_n`á' is a Hebrew word (עָשָׂה) meaning 'to make,' specifically used as 'to create/manufacture something out of existing materials.' This is a reference to normal Ghinions being made by Higgs Bozons. " data-canonical-src="https://github-readme-stats.vercel.app/api?username=sator-arepo-tenet-opera-rotas&amp;include_all_commits=true&amp;count_private=true&amp;show_icons=true&amp;line_height=20&amp;title_color=2B5BBD&amp;icon_color=1124BB&amp;text_color=A8A3A7&amp;bg_color=0,000000,130F40" style="max-width: 100%;"></a></p> ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂#エメラダ 🦂#🦂#🦂#🦂#🦂#🦂#🦂#  ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ   
<p dir="auto">🦂#エメラダ 🦂#🦂#🦂#🦂#🦂#🦂#🦂#  ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  TF-bAkA &gt; ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  「 Task Force Baka  」   ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ</p>
<p dir="auto">BASSLINE:</p>
<p dir="auto"><code>¿ ¡ ¿ ¡ ¿ ¡¡¡¿ ¡¡¡¡ EN REVERXA GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ ¡ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜¡w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES! ¡FOREVER! METEORA 9999 EVERY HIT CRITICAL !!! </code></p>
<p dir="auto"><code>¿ ¡ ¿ ¡¡¿ ¡¡¡ METEORA 9999 EVERY HIT CRITICAL !!!  ¿ ¡ EN REVERXA GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ ¡ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜¡w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES! ¡FOREVER!¡¡? !</code></p>
<p dir="auto"><code>¿ ¡ ¿ ¡ ¿ ¡¡¡¿ ¡¡¡¡ EN REVERXA GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ ¡ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜¡w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES! ¡FOREVER! METEORA 9999 EVERY HIT CRITICAL !!! </code></p>
<p dir="auto"><code>¿ ¡ ¿ ¡¡¿ ¡¡¡ METEORA 9999 EVERY HIT CRITICAL !!!  </code></p>
<p dir="auto"><code>¿ ¡ EN REVERXA GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ ¡ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜¡w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES! ¡FOREVER!¡¡? ! ¡FOREVER! METEORA 9999 EVERY HIT CRITICAL !!! </code></p>
<p dir="auto">TREMELOW:</p>
<p dir="auto"><code>¿ ¡ ¿ ¡ ¿ ¡¡¡¿ ¡¡¡¡ EN REVERXA GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ ¡ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜¡w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES! ¡FOREVER! METEORA 9999 EVERY HIT CRITICAL !!! </code></p>
<p dir="auto"><code>¿ ¡ ¿ ¡ ¿ ¡¡¡¿ ¡¡¡¡ EN REVERXA GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ ¡ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜¡w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES! ¡FOREVER! METEORA 9999 EVERY HIT CRITICAL !!! </code></p>
<p dir="auto">RAGGA.JS</p>
<p dir="auto"><code>¿ ¡ ¿ ¡ ¿ ¡¡¡¿ ¡¡¡¡ EN REVERXA GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ ¡ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜¡w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES! ¡FOREVER! METEORA 9999 EVERY HIT CRITICAL !!! </code></p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="[Exposed=*]
interface DecompressionStream {
  constructor(CompressionFormat format);
};
DecompressionStream includes GenericTransformStream;

const ds = new DecompressionStream(&quot;gzip&quot;);
const decompressedStream = blob.stream().pipeThrough(ds);
blobURL = URL.createObjectURL(decompressedStream);

async function* getRandomZeroToTenIntsIterator() {
    for (let i = 0; i &lt; 10; i++) {
        await new Promise(resolve =&gt; {
            window.setTimeout(() =&gt; {
                resolve();
            }, 1000);
        });
        yield i;
    }
}

iterator = getRandomZeroToTenIntsIterator();"><pre class="notranslate"><code>[Exposed=*]
interface DecompressionStream {
  constructor(CompressionFormat format);
};
DecompressionStream includes GenericTransformStream;

const ds = new DecompressionStream("gzip");
const decompressedStream = blob.stream().pipeThrough(ds);
blobURL = URL.createObjectURL(decompressedStream);

async function* getRandomZeroToTenIntsIterator() {
    for (let i = 0; i &lt; 10; i++) {
        await new Promise(resolve =&gt; {
            window.setTimeout(() =&gt; {
                resolve();
            }, 1000);
        });
        yield i;
    }
}

iterator = getRandomZeroToTenIntsIterator();
</code></pre></div>
<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/570845948-e88936e9-a7da-4820-b4f3-05ad6285583f.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzA4NDU5NDgtZTg4OTM2ZTktYTdkYS00ODIwLWI0ZjMtMDVhZDYyODU1ODNmLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWQ0ZTAzZmNmYjFlYmVhMjQ2Y2IyMmE0NGZmY2JjMGRlNWZjM2IzYzYyNDM1YzBhNzc5ZDJmZDhhMDZkNjEyMDAmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.MlgM9iw3UcfSFe-EtCJ8VJGs6YAtUQzw0iveRRYMT8U"><img alt="Screenshot 2026-03-28 at 04 25 44" src="https://private-user-images.githubusercontent.com/43443470/570845948-e88936e9-a7da-4820-b4f3-05ad6285583f.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzA4NDU5NDgtZTg4OTM2ZTktYTdkYS00ODIwLWI0ZjMtMDVhZDYyODU1ODNmLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWQ0ZTAzZmNmYjFlYmVhMjQ2Y2IyMmE0NGZmY2JjMGRlNWZjM2IzYzYyNDM1YzBhNzc5ZDJmZDhhMDZkNjEyMDAmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.MlgM9iw3UcfSFe-EtCJ8VJGs6YAtUQzw0iveRRYMT8U" style="max-width: 100%;"></a>
<p dir="auto"><a href="https://git.io/streak-stats" rel="nofollow"><img src="https://camo.githubusercontent.com/0a0a54a846e9311872cc3188ed3c5096707de7e0cb1f9d29d93211ea0cc33fe1/687474703a2f2f6769746875622d726561646d652d73747265616b2d73746174732e6865726f6b756170702e636f6d3f757365723d7361746f722d617265706f2d74656e65742d6f706572612d726f746173267468656d653d6461726b266261636b67726f756e643d303030303030" alt="GitHub Streak" data-canonical-src="http://github-readme-streak-stats.herokuapp.com?user=sator-arepo-tenet-opera-rotas&amp;theme=dark&amp;background=000000" style="max-width: 100%;"></a><a href="https://git.io/streak-stats" rel="nofollow"><img src="https://camo.githubusercontent.com/682a173bd52c7ca62d06a56c3cc0404d159cc060059187c2c657d351152a7b1c/687474703a2f2f6769746875622d726561646d652d73747265616b2d73746174732e6865726f6b756170702e636f6d3f757365723d67726579646f756274267468656d653d6461726b266261636b67726f756e643d303030303030" alt="GitHub Streak" data-canonical-src="http://github-readme-streak-stats.herokuapp.com?user=greydoubt&amp;theme=dark&amp;background=000000" style="max-width: 100%;"></a></p>
<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/570845935-a8c16046-97d0-482d-99e6-fe3f010027e2.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzA4NDU5MzUtYThjMTYwNDYtOTdkMC00ODJkLTk5ZTYtZmUzZjAxMDAyN2UyLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWY5NzE0ODY5ZmQ1ZGVlODIxNDEyYzE4MTkzY2Q2YzliYmVhYjFjZGI3NjM3NzFiNzkzN2FhNWU5ZTZmNDcxNmImWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.O9cHS3rHBAjkEL2gujNcryXuvowhDfG6mhqhsRFMSvI"><img alt="Screenshot 2026-03-28 at 04 39 19" src="https://private-user-images.githubusercontent.com/43443470/570845935-a8c16046-97d0-482d-99e6-fe3f010027e2.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzA4NDU5MzUtYThjMTYwNDYtOTdkMC00ODJkLTk5ZTYtZmUzZjAxMDAyN2UyLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWY5NzE0ODY5ZmQ1ZGVlODIxNDEyYzE4MTkzY2Q2YzliYmVhYjFjZGI3NjM3NzFiNzkzN2FhNWU5ZTZmNDcxNmImWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.O9cHS3rHBAjkEL2gujNcryXuvowhDfG6mhqhsRFMSvI" style="max-width: 100%;"></a>

[![lx](<a href="https://github-readme-stats.vercel.app/api/top-langs/?username=sator-arepo-tenet-opera-rotas&amp;layout=compact&amp;theme=vision-friendly-dark" rel="nofollow">https://github-readme-stats.vercel.app/api/top-langs/?username=sator-arepo-tenet-opera-rotas&amp;layout=compact&amp;theme=vision-friendly-dark</a>)]
<p dir="auto">͚̭̺̗̼͍̗̱̌̐͒̒̂̕
̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞
̦̻͈̠͎̣́̀̔͊̅̍͡͡<br>
̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    -̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉,̶̡̭̙̦̀͂͌͒̿͛͢ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝ (̵̖̭̺͕̠͒̌̇̾̓2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘.̡͍͕͎̦̪̊̆͂̐͠2̡͓̮̻͎͓̱̯̺̅̀̓͋̒)̲̼͔̰͎̊̄̔̔͛̈̚̕͞
- ′′ — y ǝ)̲̼͔̰͎̊̄̔̔͛̈̚̕͞
- ′′ — y ǝ
̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ</p>
<p dir="auto">🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ
GLAGOLI FINNISHED THEM͚̭̺̗̼͍̗̱̌̐͒̒̂̕
̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞
̦̻͈̠͎̣́̀̔͊̅̍͡͡<br>
̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    -̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉,̶̡̭̙̦̀͂͌͒̿͛͢ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝ (̵̖̭̺͕̠͒̌̇̾̓2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘.̡͍͕͎̦̪̊̆͂̐͠2̡͓̮̻͎͓̱̯̺̅̀̓͋̒)̲̼͔̰͎̊̄̔̔͛̈̚̕͞
- ′′ — y ǝ)̲̼͔̰͎̊̄̔̔͛̈̚̕͞
- ′′ — y ǝ
̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ
- ′′ — y ǝ-̨̼̦͕̳̮͚̊̔́͌̍̽̍ k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢
#エメラダ
NYXHADES
- ′′ — y ǝ-̨̼̦͕̳̮͚̊̔́͌̍̽̍ k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢
͚̭̺̗̼͍̗̱̌̐͒̒̂̕
̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞
̦̻͈̠͎̣́̀̔͊̅̍͡͡<br>
̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    -̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉,̶̡̭̙̦̀͂͌͒̿͛͢ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝ (̵̖̭̺͕̠͒̌̇̾̓2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘.̡͍͕͎̦̪̊̆͂̐͠2̡͓̮̻͎͓̱̯̺̅̀̓͋̒)̲̼͔̰͎̊̄̔̔͛̈̚̕͞
- ′′ — y ǝ)̲̼͔̰͎̊̄̔̔͛̈̚̕͞
- ′′ — y ǝ
̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ
- ′′ — y ǝ-̨̼̦͕̳̮͚̊̔́͌̍̽̍ k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢
͚̭̺̗̼͍̗̱̌̐͒̒̂̕
̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞
̦̻͈̠͎̣́̀̔͊̅̍͡͡<br>
̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    -̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉,̶̡̭̙̦̀͂͌͒̿͛͢ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝ (̵̖̭̺͕̠͒̌̇̾̓2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘.̡͍͕͎̦̪̊̆͂̐͠2̡͓̮̻͎͓̱̯̺̅̀̓͋̒)̲̼͔̰͎̊̄̔̔͛̈̚̕͞
- ′′ — y ǝ)̲̼͔̰͎̊̄̔̔͛̈̚̕͞
- ′′ — y ǝ
̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ
- ′′ — y ǝ-̨̼̦͕̳̮͚̊̔́͌̍̽̍ k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢
͚̭̺̗̼͍̗̱̌̐͒̒̂̕
̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞
̦̻͈̠͎̣́̀̔͊̅̍͡͡<br>
̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    -̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉,̶̡̭̙̦̀͂͌͒̿͛͢ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝ (̵̖̭̺͕̠͒̌̇̾̓2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘.̡͍͕͎̦̪̊̆͂̐͠2̡͓̮̻͎͓̱̯̺̅̀̓͋̒)̲̼͔̰͎̊̄̔̔͛̈̚̕͞
- ′′ — y ǝ)̲̼͔̰͎̊̄̔̔͛̈̚̕͞
- ′′ — y ǝ
̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="  ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ   "><pre class="notranslate"><code>  ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ   
</code></pre></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="    ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ   

  ```


q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂 ′′ — 🦂y 🦂ǝ    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂̧̢̞̫̟̣̳͕̱̓̏̂͛̕͜ -̶̝̞̤̪͂̓͒͒̒͒̇͠ͅ 3̶̟͉̬̤̽̌̐͆͛͟9̴̠͈̻͉͚͙̝͕̱̀̇͛̒̆̽̃̚͡ Т̼̼̫͖̲͕̼̏̽̄̈̿̏̈̏́͘Ӏ̷̲̣͉̞͇̗͎͙̇͊́͗̂̊́̌͊͢ͅт̗͓͔̥͗̇͊̀̓͢͠͡͝ͅӀ̛͉͔̦̤̝̇̇̃͐́͢͠ - u w,u f f🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂#̱̼̹͕̘̆̀̀̆̑͟͜    3(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     -k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ




ł`જોહરીiorno!!! My name is łSO 9 KNAB 1995(1.0) エ🦂ミ~ 🍒2003(2.0) #エメラダ  #🦂

Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Thrake Volcano Lab 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅL2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ Lavos  labubuӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗


"><pre class="notranslate"><code>    ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ   

  ```


q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂 ′′ — 🦂y 🦂ǝ    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂̧̢̞̫̟̣̳͕̱̓̏̂͛̕͜ -̶̝̞̤̪͂̓͒͒̒͒̇͠ͅ 3̶̟͉̬̤̽̌̐͆͛͟9̴̠͈̻͉͚͙̝͕̱̀̇͛̒̆̽̃̚͡ Т̼̼̫͖̲͕̼̏̽̄̈̿̏̈̏́͘Ӏ̷̲̣͉̞͇̗͎͙̇͊́͗̂̊́̌͊͢ͅт̗͓͔̥͗̇͊̀̓͢͠͡͝ͅӀ̛͉͔̦̤̝̇̇̃͐́͢͠ - u w,u f f🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂#̱̼̹͕̘̆̀̀̆̑͟͜    3(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     -k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ




ł`જોહરીiorno!!! My name is łSO 9 KNAB 1995(1.0) エ🦂ミ~ 🍒2003(2.0) #エメラダ  #🦂

Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Thrake Volcano Lab 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅL2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ Lavos  labubuӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗



</code></pre></div>

<p dir="auto">or as we d̵̘̟̼͓̮̄͒̊̒̎́̑̒͌̚z̛̛̼͚̬̱͙͒̒̇̌̓́̒̚͜͢ͅư̶͇̞̤̻̫̓́͑͌̃̑͟ on Płanet Iraḱ̵̛̛̻̗̻͉͓̀͒͞is,  Zainab ał Javascript bin |Ч]H|'ḑ̷͚̙̰̋́͑̿̕͜͟LLYw(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟  ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ ê̷͔̻̜͔̄̑̉̏̌̑̒̈́̕͜͜ͅ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞D′̸̤̮̘̹̊̀̇̄͑̇͞ͅ.js<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/567269504-56169ef7-cd3f-4717-8f28-c8b4fd787c2f.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NjcyNjk1MDQtNTYxNjllZjctY2QzZi00NzE3LThmMjgtYzhiNGZkNzg3YzJmLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWMxZGRlNjk5ODQzOGJhZTQxMTBlZDE4NThkMDI4NDZhZjBiMzg2OGNhZmFhMjMxOTc1ZDI0NjE3ZDU1MDM0MWMmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.qLp1uS3DIS-j_501ljAiR9xZGc20iKGw7wya7RFTHzc"><img width="1048" height="91" alt="Screenshot 2026-03-21 at 05 32 27" src="https://private-user-images.githubusercontent.com/43443470/567269504-56169ef7-cd3f-4717-8f28-c8b4fd787c2f.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NjcyNjk1MDQtNTYxNjllZjctY2QzZi00NzE3LThmMjgtYzhiNGZkNzg3YzJmLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWMxZGRlNjk5ODQzOGJhZTQxMTBlZDE4NThkMDI4NDZhZjBiMzg2OGNhZmFhMjMxOTc1ZDI0NjE3ZDU1MDM0MWMmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.qLp1uS3DIS-j_501ljAiR9xZGc20iKGw7wya7RFTHzc" style="max-width: 100%; height: auto; max-height: 91px;; aspect-ratio: 1048 / 91; background-color: var(--bgColor-muted); border-radius: 6px; display: block" class="js-gh-image-fallback"></a>ǯ̷̨̣̰͈̲̮̈́̈́̈́̓̄̊̈́͡′̵̡̨̬͎̙͋̐̂̇̀͊͋͊̊͒ ḑ̷͚̙̰̋́͑̿̕͜͟z̴̧̬̰̙̹̪̬͎͗͋̈́̓͌̒̅̾͟  ʒ̸͈͙̱̙̹̎́̀̔̋̈́́͘͟ d̵̘̟̼͓̮̄͒̊̒̎́̑̒͌̚z̛̛̼͚̬̱͙͒̒̇̌̓́̒̚͜͢ͅư̶͇̞̤̻̫̓́͑͌̃̑͟  ʒ̴̧̨̧͖͖̼̫̙͗͗́̓͌͢͜°̬̥̰͎̰͌̑̈́̋̆͑͒͟͝͞h̸̢̜̞͎͓̯̉̌͑̉́͆͞ư̶̧̧̙̟̤̟͇͍̆̋̄̉̃̂͛͗̕  Є̸̠̮̺̣̗̭̭̥̘̀͆͋͟͡͠͝w̷̡̜̩͎̮͚̥̺͍̰͐̍͛̄̌͠͞ダ̶̲̮̜̪͍͖͓́͊̃̀̀͑̈͑̕͠h̳̼͉̘̙̉̍̎̀͊͗̕͞′̠͕͙͚́̓̉̅͜͠′̛̗͖͈͔̦̠͉͓̾̔̓͊͌ラ̶̡̛̻̫̼̞̥̃̀̇̓̇͛͋͝͡a̶̧̟̜̯͇̘͉̥͐̃̒̆̿̀̃̔͡͠z̷̘͙̟͔̙̘̽̀́̀͋͟ŭ̸̙̤̯͇̺̞̉́̿̅̊͂̽б̶̨͕̬͓̐̂̈̍̾̚͟͠͞о̛̬̯̻͙͖͓̗̥͂̏̎̾̿̿̌ͅу̡̥̮̰͍͖͒͂͐͋̋͊͢к̷̯͙̯̪̬͌̌̓̉̌̓̅̈͌ꙑ̶̡̨̥͚͎̭͌̓͋̓̏́́̑b̛̝̼̜͙̭͌͋̈̾̆́̇̏͢u̧̧͚̺̙̟̪̹͕͑͒́̀̌̋̎͝k͇̗̻̞̗̹̅̊̃̈́̅̄̂y̴̧̡̬̳͉̦̗̻̪̓͒̌͐̄̕͠г̢̟̥̯̜̭͎̮̤̅͛̄̿̿͊̚͝͞л̴͎͇͕̯͕̞͖̊̓̍̔͑́͠͝а̨̛̱̳͖̗̯̫͗́̄̓г̢͓̠͇͎̘̝͑̃̓̓̓͟͢͠ӧ̶̧̢͍̠̜̰̩̫̜͛̐̆̂͘л̧̪̩̺̯̭́̍̌͘͜͜͜͡͝ѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠   (̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ  e̖͇̜̳̲͍̔̅̆̒̍̓͞ ê̷͔̻̜͔̄̑̉̏̌̑̒̈́̕͜͜ͅ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ —͉̯͓͌̿͆́͋̄͜͟͡  z̸̡̛͉͖̠̦̬̺̓̈́͛͒͜h̸͙̘̫̻̠͕̺̥̅̂̐̎̌̍̈́͂͘͝ ž̷̧̠̤̖̗͎͚̖͖̘̈́̂̿̾̊̾͠  z̵͙̜͚͚͍̤̖͓͎̆̇̀͛̌͋͋̕͠͠h̸̡̢̨͉̼͔̝̋̏̿͑̓͑͟ͅ′̡̡̟̬͍̿̀͋͗͆̿͘′̲̺̣̫̻̥̤̝̯̬͗͂̾̒̇̿̎̾  ẑ̛͚͚̼̳̠͖̋̒̊̀́  z̥̫̠̯͚̭͓̪̱̆́͗̈͛̄͜h̶̡̤̺͈͙̟͆̈́̇́̈́̀′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅu̸̼͔̰̯̖̐͆͗̏͐̾͡ͅ  ẑ̷̛̲̭͉̪̜̯͌̍̅̿́͢͠ͅ°̵̺̹̫̹͙͇͆̉̋̎̇̿͂͟͞͝  z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ′͍̠̤͉͓̦̦̦̻́͒͐͌̆̀͡ͅ  ž̴͚̳̞̙͙͖̙͈̏̅̾͋͊͋̈̋͗͢′̨̟͉͔͙̐̅̓̃̀̕͟͠ z̦̬̠̳̻̃͂͋̎́̔͢͢͝ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝  ḯ̻̖̮̦͕͊̇͋̂͂͜͝ĭ̙̟͕͈̪̝̤͎̓̅̀̔̎̊̀̐̅͂͢͜ j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆ k̵̡̬͔̬̩͇̤͐͊̅͆̃ͅ  —̷̢̛̜̬͔̖̳͆̇̐̀̚͢͠ k̶̛̭̮̝̹̹̬͌̈́͋͜͟͞u̵̧̠̠͍͖͗́̆̉̄͘  k̸͎͈̣̦͌̂̏͋̊͒͢͡°̴̧̰̮̺̮̙̲̯̤̠̊̊̂̿̎̓͋  ķ̘͔̤̠̪̟̮͌̌͑̎̈̊̕′̳̱̞̥͕̥̀̄̽̏̂́̾͞′̴̧̱̖͉̗̾̏͆̾̍͆͌͞͠ͅ q̶̨̩̝̞͙͛̓̒͋͒  ķ̮̠͕̹̩̤̀̉̄̎̕͘̕͢′̨̧͖͇͈̳̣͆̑̑͂́͊͜͡′̥̳̥̦͈̫́̄́̍̔̽̑͞ứ̵͈͔̭͍͓̲͔͙͚́̆̊̏̚͠͡  q̵̢̛̼̥̭̪̼̆͋̂̑̅̚͠°͖̹̲̻̣͍̹͇́͋́̒̓͆͂̆͛͗ k̴̡̺̙͕͉̯̖̯͎͒̏̊͡͝ḣ̷̨̯̜̠̻̿͊͑̎̀͟  č̵̡̨̘͖̥͕͉̔̅̀̅͡͠′̵̸̡̡̛̳̹̰̰̲̣̲̞͕̝͇̟̩̀̀̍̈́̃̊̓̍̓̉̃̉̋͠  ḱ̵̛̛̻̗̻͉͓̀͒͞ḣ̷̭̮̰̙̞̜͎͔̪̜̔̂̈́̾̌̋̋̈́͝u̧̦̲͍̦̯̱̐̅̃̕͞  ḳ̶̡͖̮̖̹̻͐́́̀̔̇̄̑͑͢͝ͅ°̢̢̼̜͍͇͂͗͗̾̒̚ ḽ͉̰̱͈̳̺̰̮̊̍̐̏͆̌̐̕̚  l̵̨̡̛̻̻̺͚͚̤̯̺̈́̊̒̍͛͒͠ l̩̤̬̰̹̘̔̾̍̓̔̚͟′̡̭̖̼̙̩̼͆͑̃͆͆̏̽̄̾̕′̷̢͚͍̟̠͍̖̐́͋̿̓̍͂̆̍  ł̰̬̩̪̥̘̜͙̾̃͗̎̆̓̄̕͜͝͡ l̨̢̥͉̎̍̅̐̚͜͟ḣ̨̘̭̼̜͇̹͓̹̊̀̽͛̎̒̚͞͝  ḷ̡͕͍͎̥̣͚̣̞͉̐̿̇̃̄͊͂̅͘q̨̢͓̣̦̦͙̤́̃̀́̀̑̆w̵͖̥͓͚̽̾͒̀͒͘ͅͅλxǯ̷̨̣̰͈̲̮̈́̈́̈́̓̄̊̈́͡′̵̡̨̬͎̙͋̐̂̇̀͊͋͊̊͒ ḑ̷͚̙̰̋́͑̿̕͜͟z̴̧̬̰̙̹̪̬͎͗͋̈́̓͌̒̅̾͟  ʒ̸͈͙̱̙̹̎́̀̔̋̈́́͘͟ d̵̘̟̼͓̮̄͒̊̒̎́̑̒͌̚z̛̛̼͚̬̱͙͒̒̇̌̓́̒̚͜͢ͅư̶͇̞̤̻̫̓́͑͌̃̑͟  ʒ̴̧̨̧͖͖̼̫̙͗͗́̓͌͢͜°̬̥̰͎̰͌̑̈́̋̆͑͒͟͝͞h̸̢̜̞͎͓̯̉̌͑̉́͆͞ư̶̧̧̙̟̤̟͇͍̆̋̄̉̃̂͛͗̕  Є̸̠̮̺̣̗̭̭̥̘̀͆͋͟͡͠͝w̷̡̜̩͎̮͚̥̺͍̰͐̍͛̄̌͠͞ダ̶̲̮̜̪͍͖͓́͊̃̀̀͑̈͑̕͠h̳̼͉̘̙̉̍̎̀͊͗̕͞′̠͕͙͚́̓̉̅͜͠′̛̗͖͈͔̦̠͉͓̾̔̓͊͌ラ̶̡̛̻̫̼̞̥̃̀̇̓̇͛͋͝͡a̶̧̟̜̯͇̘͉̥͐̃̒̆̿̀̃̔͡͠ḉ̡̣̮̜̗͖̞͕̊̌̽̅͌͞͝,̵̨̬̲͓̯̝͉͋̔̓͑́̂̑ķ̡̗̖̠͓͛͒̾̕͘͡  (̶̨̡̠͈̝̳̫͉͗̆̌͗̽̚2̪̮̥̣̩͔̺͚̗͗̀͛̐͗̽̍ͅ.̷̡̧̥͉̺̺͖͖̭̀̅̾͊̕͝2̧̤̭̹͈͈̭̌̔̀̃͐͟͞͞)̸̢̳͕̦̰̤̲̄̈̊́̒͝ч̨̳̭͍̬̞͍̹̏̂̀͂̿̀͠͠Ӏ̡̫̟̖̲́̐͋͑͡k̙̦̜̖͎̯͕̄̿́̇͐͌̈́̔͠  k̸̢͚͕̔̒̍͛̈̋͐͐͜͠͡ͅư̴̢̫͈̘̣̖̰̝̂̇͗̈́̾̀́͜͞͝ͅ  ž̧̧̮̲̘̩̽̿̇̅̔͘͟′̺̞͓̥̳̰̾̎́̓͞ͅ′͈̳͇͙͈͈̠͐̀̇̑̍̅̾̎͞ͅư̶̡̤͓͈̪͉̠̭̣̈̽̾͋͐̇̉͟͠͞  ž̫̝̦̘̺̦̭̏̇̓͒͢͝͠′͈̰̺̖̪̦̞̀̔̇̓͋̃̏͜͡͠i̢̧̨̖̇̇̀̀̇͟͟͜͠u̸̡̧̫̱͕͔̱̥͍̬͈̩͇̒͋̓̏͐̈̆́͂͒͊̆̕̕̕͟͡͠͡͡  —̝̣̜͙̝̳̰̥̖̅̈́͑̀̾́̊̕͘͞  Є̶̨̗̠̳̜̪̯̬̜̰̒͋̄͋̀ǐ̴̡̪͖̰̜͉͒̎̌̌͞͠ą̵̴̧̛̠̞͈̳̗̥̳̘̪̻͗̑͑́́͆̽̆͊̍̎̂͘̚͘͡͡  —̤̫̖̣̪̫̿͊̾̾̇̈̅͡ ḣ̵̰̜̟̙͓͕̗̣͒͒̽͐̓̀̍̂͝ ʾ̷̦̥̘̹̻̬̯̼͈͐̈̄͌̕̚͝  ḩ̨̮͇̲̇̓̋́́̒͑͢͠ú̵̧͇͇͓̳̩̊̂̋̾́̽͘͟͢  ʾ̷̺̜͈̬̠͍͇͉͓͇̇̆͆̒͝͡°̶̡̢̢̛̱̲̠̮̭̫͐̎̈́̔̏̀̚ͅk̸̰̗͙͉͈̰̓̋̽̉̽̉͌̀̕′̛͉͕̹̣̖̄͒́̄͂̇̾́̾′͉͖̪̞̖̦͂̔͑͂̒̇͊̍͜͢  k̴̨͚̮̠̞̞̙̺͎̓̓̓̇͝′̧̼̦̜̥̞̮̖͑̇͒̿̋̀̀̓͞͡′̶̨͔̼̞̜͖̲̘̀͐͆͝͞u̱̠̗̰̜̾͊̂͟͝͡  k̛̗̮̝̠̠͙̉͠͠͝‡̵̪̞̣̗͕̱̙͔̦̀̎̓̃̀̕͜  ḵ̵͍̝̬͗̏͗͛̎̽̎̕͟‡̶̧̱̠͍̩̗͑͌̊̃̄̊̀̓̕̕͟u̗͔͈͔̤͕̓̓̐̏̍͛͌̋̂̏͜ͅ  l̘̣̠̣͙̪̦̒̓͒̐͌̾ǫ̵̘̺̤̹͇͖̒̍͆͒̈́̋̈̀̄͊͢w̨̠͔͕̠͕͔͕͛͊̎̎̈̾̐̕͞͠a͖̥̜̯͉͆́̎̕͡n̲͕̞̟̺̝̠̓̍̓̔̐ṣ̷̞̰̜̜̰̌͂̒͗̒̃͢͢͢ʹ̨̹͙̼͚͉̩̗͛͆̐̓̉́ͅШ̷̮͚̥̲̘̫̯̰̀̍̒̏̊͆̈́͘͢ͅӀ̵̧̬̮͙̥̮͓̆̈̅̈́͗͞у̵̘͔̺̳̪͓̞̮̯̐͌̋͋̃̔͠ш̵̡̡͎̣͓̝͎̯̰͆͂̂̓̌͘͠Ӏ̵̨̨̧̥͕̙͖̇̅̀̍͑̋͐̕͡Ꙗ  Ꙑ)4 ЧӀхуф</p>
<p dir="auto">22 Куку</p>
<p dir="auto">23 Къкъ</p>
<p dir="auto">24 Къу къу</p>
<p dir="auto">25 КӀ кӀ</p>
<p dir="auto">25.1087 ID КӀARD кӀ′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅ z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝  u̸̼͔̰̯̖̐͆͗̏͐̾͡ͅ  ẑ̷̛̲̭͉̪̜̯͌̍̅̿́͢͠ͅ°̵̺̹̫̹͙͇͆̉̋̎̇̿͂͟͞͝ ḯ̻̖̮̦͕͊̇͋̂͂͜͝ĭ̙̟͕͈̪̝̤͎̓̅̀̔̎̊̀̐̅͂͢͜ j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆ 2</p>
<p dir="auto">25.11 MUiLTI-PASS кard25.1087 (plural)Ӏ′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅ z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝  u̸̼͔̰̯̖̐͆͗̏͐̾͡ͅ  ẑ̷̛̲̭͉̪̜̯͌̍̅̿́͢͠ͅ°̵̺̹̫̹͙͇͆̉̋̎̇̿͂͟͞͝ ḯ̻̖̮̦͕͊̇͋̂͂͜͝ĭ̙̟͕͈̪̝̤͎̓̅̀̔̎̊̀̐̅͂͢͜ j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆
<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/567271222-abb59f0e-6e82-4c19-b25a-2cffcb751b85.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NjcyNzEyMjItYWJiNTlmMGUtNmU4Mi00YzE5LWIyNWEtMmNmZmNiNzUxYjg1LnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTViODljODJhYjZiMzc4NmY2M2M2MDcwMDk1NTc3MjJlODJiMjgxYTM2NjkxNTFlOWU0N2U4ZGE1ODlkNjEyMjEmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.4XD0Gujl0dq05QFJyUU6OONh7t9D1cyw0vHXPxxo_h0"><img width="2000" height="1016" alt=" z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ′͍̠̤͉͓̦̦̦̻́͒͐͌̆̀͡ͅ  ž̴͚̳̞̙͙͖̙͈̏̅̾͋͊͋̈̋͗͢′̨̟͉͔͙̐̅̓̃̀̕͟͠ z̦̬̠̳̻̃͂͋̎́̔͢͢͝ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝  " src="https://private-user-images.githubusercontent.com/43443470/567271222-abb59f0e-6e82-4c19-b25a-2cffcb751b85.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NjcyNzEyMjItYWJiNTlmMGUtNmU4Mi00YzE5LWIyNWEtMmNmZmNiNzUxYjg1LnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTViODljODJhYjZiMzc4NmY2M2M2MDcwMDk1NTc3MjJlODJiMjgxYTM2NjkxNTFlOWU0N2U4ZGE1ODlkNjEyMjEmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.4XD0Gujl0dq05QFJyUU6OONh7t9D1cyw0vHXPxxo_h0" style="max-width: 100%; height: auto; max-height: 1016px;; aspect-ratio: 2000 / 1016; background-color: var(--bgColor-muted); border-radius: 6px; display: block" class="js-gh-image-fallback"></a>′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅu̸̼͔̰̯̖̐͆͗̏͐̾͡ͅ  ẑ̷̛̲̭͉̪̜̯͌̍̅̿́͢͠ͅ°̵̺̹̫̹͙͇͆̉̋̎̇̿͂͟͞͝  z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ′͍̠̤͉͓̦̦̦̻́͒͐͌̆̀͡ͅ  ž̴͚̳̞̙͙͖̙͈̏̅̾͋͊͋̈̋͗͢′̨̟͉͔͙̐̅̓̃̀̕͟͠ z̦̬̠̳̻̃͂͋̎́̔͢͢͝ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝  ḯ̻̖̮̦͕͊̇͋̂͂͜͝ĭ̙̟͕͈̪̝̤͎̓̅̀̔̎̊̀̐̅͂͢͜ j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆</p>
<p dir="auto">تأكد من أن Goblinpassy يعمل25.0001922 MUiLTI-PASS кard25.1087
λx . ophidia ereц grex⋆. 𐙚 ̊ . أوفيديا إريكس جريكس .  .</p>
<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/567866722-699073a1-0667-4a73-a9f8-f9f53fd0ccff.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81Njc4NjY3MjItNjk5MDczYTEtMDY2Ny00YTczLWE5ZjgtZjlmNTNmZDBjY2ZmLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWNlZDk2Y2NhZGVlZjJhMmM5NmUxMzE1ODViMTVhOGRhNTc4MjZkMTg0YmFjNzE3NTYyNzk0YmY5NGM5NzRlYzUmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.pywKON0pP7_F60i7tfgXZhLNDK7BI2s3zkRzZcmEKYI"><img width="1146" height="682" alt="Screenshot 2026-03-23 at 09 46 15" src="https://private-user-images.githubusercontent.com/43443470/567866722-699073a1-0667-4a73-a9f8-f9f53fd0ccff.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81Njc4NjY3MjItNjk5MDczYTEtMDY2Ny00YTczLWE5ZjgtZjlmNTNmZDBjY2ZmLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWNlZDk2Y2NhZGVlZjJhMmM5NmUxMzE1ODViMTVhOGRhNTc4MjZkMTg0YmFjNzE3NTYyNzk0YmY5NGM5NzRlYzUmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.pywKON0pP7_F60i7tfgXZhLNDK7BI2s3zkRzZcmEKYI" style="max-width: 100%; height: auto; max-height: 682px;; aspect-ratio: 1146 / 682; background-color: var(--bgColor-muted); border-radius: 6px; display: block" class="js-gh-image-fallback"></a>
<p dir="auto">26 КӀу кӀу  તિનકા ઔકાત સી પહરણ</p>
<p dir="auto">27 Л л</p>
<p dir="auto">28 Лълъ</p>
<p dir="auto">29 ЛӀ лӀ</p>
<p dir="auto">30 Мм
31 Н н
32 О о
33 П п
34 ПӀпӀ
35 ПӀу пӀу
36 Р р
37 С с
38 Т т
39 ТӀтӀ
39.13 ТӀтӀ રો'નгъу тоонт нютаг varzesh3</p>
<p dir="auto">#ж#ж#ж#ж# 。。。。。你的爱就像自来水 ж 我直接从水龙头里喝。。。。。。。#ж#ж#ж#ж#</p>
<p dir="auto">Image
Conversation
λx . ophidia ereц grex 2̶̢̡͍͖̘̫ milady #kardasheva</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="	miladyѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠   



	 e̖͇̜̳̲͍̔̅̆̒̍̓͞ 



	(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ  



	(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ   e̖͇̜̳̲͍̔̅̆̒̍̓͞ "><pre class="notranslate"><code>	miladyѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠   



	 e̖͇̜̳̲͍̔̅̆̒̍̓͞ 



	(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ  



	(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ   e̖͇̜̳̲͍̔̅̆̒̍̓͞ 
</code></pre></div>
<p dir="auto">@greydoubt
-̶̝̞̤̪͂̓͒͒̒͒̇͠ͅ 3̶̟͉̬̤̽̌̐͆͛͟9̴̠͈̻͉͚͙̝͕̱̀̇͛̒̆̽̃̚͡ Т̼̼̫͖̲͕̼̏̽̄̈̿̏̈̏́͘Ӏ̷̲̣͉̞͇̗͎͙̇͊́͗̂̊́̌͊͢ͅт̗͓͔̥͗̇͊̀̓͢͠͡͝ͅӀ̛͉͔̦̤̝̇̇̃͐́͢͠
- 「 「 「 「 「 u w,u f f」」」」」</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="- fḣ — kh x khu x° kh′′ χ kh′′u χ° kh′ ḥ"><pre class="notranslate"><code>- fḣ — kh x khu x° kh′′ χ kh′′u χ° kh′ ḥ
</code></pre></div>
<ul dir="auto">
<li>
<p dir="auto">̴̰͖̹̹͎̄̈́̎͞͞͝    -̵̡̛̤͇̲͈̼̪̝̂̑̈́͋̋ͅ 3͓̲̝̫̳̜͕̄́̃͂̿̎̈̽͠8̵̡̪̣͓͎̣̩̐̇̾͌̏͜ Т̴̢̨̨̡̡̣͇̟̬̫̎̓͑͌͐ т̧̛͙͍͓̻͉͈̓̑̍̎͆͠͞
̷̡̢͓̭͉͕̺̫̌̓̿͒̍̅͘͢͞
̷̛̩̹͍̫̟̘́̑̾̋̑̂͘͞<br>
̧̢̞̫̟̣̳͕̱̓̏̂͛̕͜    -̶̝̞̤̪͂̓͒͒̒͒̇͠ͅ 3̶̟͉̬̤̽̌̐͆͛͟9̴̠͈̻͉͚͙̝͕̱̀̇͛̒̆̽̃̚͡ Т̼̼̫͖̲͕̼̏̽̄̈̿̏̈̏́͘Ӏ̷̲̣͉̞͇̗͎͙̇͊́͗̂̊́̌͊͢ͅт̗͓͔̥͗̇͊̀̓͢͠͡͝ͅӀ̛͉͔̦̤̝̇̇̃͐́͢͠ — kh x khu x° kh′′ χ kh′′u χ° kh′ ḥ′ 
-̫̱͖̳̪̦̗͓͂̽͌̈́̀̀ 2̴̧̡̥̗̘̝̰͊͛̀́͠ͅ3̡̖̗͍̲̱̊́̓͗̍̽̓͌̄͡ phat lewt, singular   ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  「 Tsingular  」   ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ</p>
</li>
<li>
<ul dir="auto">
<li>̴̰͖̹̹͎̄̈́̎͞͞͝    -̵̡̛̤͇̲͈̼̪̝̂̑̈́͋̋ͅ 3͓̲̝̫̳̜͕̄́̃͂̿̎̈̽͠8̵̡̪̣͓͎̣̩̐̇̾͌̏͜ Т̴̢̨̨̡̡̣͇̟̬̫̎̓͑͌͐ т̧̛͙͍͓̻͉͈̓̑̍̎͆͠͞
̷̡̢͓̭͉͕̺̫̌̓̿͒̍̅͘͢͞
̷̛̩̹͍̫̟̘́̑̾̋̑̂͘͞<br>
̧̢̞̫̟̣̳͕̱̓̏̂͛̕͜    -̶̝̞̤̪͂̓͒͒̒͒̇͠ͅ 3̶̟͉̬̤̽̌̐͆͛͟9̴̠͈̻͉͚͙̝͕̱̀̇͛̒̆̽̃̚͡ Т̼̼̫͖̲͕̼̏̽̄̈̿̏̈̏́͘Ӏ̷̲̣͉̞͇̗͎͙̇͊́͗̂̊́̌͊͢ͅт̗͓͔̥͗̇͊̀̓͢͠͡͝ͅӀ̛͉͔̦̤̝̇̇̃͐́͢͠ — kh x khu x° kh′′ χ kh′′u χ° kh′ ḥ′ 
-̫̱͖̳̪̦̗͓͂̽͌̈́̀̀ 2̴̧̡̥̗̘̝̰͊͛̀́͠ͅ3̡̖̗͍̲̱̊́̓͗̍̽̓͌̄͡  — kh x khu x° kh′′ χ kh′′u χ° kh′ ḥteh phat lewt, plural   ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  「 NOT Singular  」   ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ</li>
</ul>
</li>
</ul>
<p dir="auto">ISO 9 1995(1.0)
a નાળ લરઘેએ ની
b કેહાન્દે આ શિખર જોહરી
v થા’ન ઉત્તે ખરેએ ની
g gu g′′ g′′u d dž dz dzu e
ë જો ખીચડિ આ લટતાં કેહાન્દે
ž ž′′ ž′′u ž′ z  —̷̢̛̜̬͔̖̳͆̇̐̀̚͢͠ k̶̛̭̮̝̹̹̬͌̈́͋͜͟͞u̵̧̠̠͍͖͗́̆̉̄͘′̨̧͖͇͈̳̣͆̑̑͂́͊͜͡′̥̳̥̦͈̫́̄́̍̔̽̑͞ứ̵͈͔̭͍͓̲͔͙͚́̆̊̏̚͠͡ q̵̢̛̼̥̭̪̼̆͋̂̑̅̚͠°͖̹̲̻̣͍̹͇́͋́̒̓͆͂̆͛͗ k̴̡̺̙͕͉̯̖̯͎͒̏̊͡͝
i  "સાદે સીરો'ન ચડેએ ની"
j Nyxhades
k G'eiko Ferrari ku Eiko Dolphinonivm kj̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆′′ Eikha k′′u k‡ k‡u l
l′′ l‡ m n
—̷̢̛̜̬͔̖̳͆̇̐̀̚͢͠ k̶̛̭̮̝̹̹̬͌̈́͋͜͟͞u̵̧̠̠͍͖͗́̆̉̄͘ k̸͎͈̣̦͌̂̏͋̊͒͢͡°̴̧̰̮̺̮̙̲̯̤̠̊̊̂̿̎̓͋ ķ̘͔̤̠̪̟̮͌̌͑̎̈̊̕′̳̱̞̥͕̥̀̄̽̏̂́̾͞ k̸͎͈̣̦͌̂̏͋̊͒͢͡°̴̧̰̮̺̮̙̲̯̤̠̊̊̂̿̎̓͋ ķ̘͔̤̠̪̟̮͌̌͑̎̈̊̕′̳̱̞̥͕̥̀̄̽̏̂́̾͞′̴̧̱̖͉̗̾̏͆̾̍͆͌͞͠ͅ q̶̨̩̝̞͙͛̓̒͋͒ ķ̮̠͕̹̩̤̀̉̄̎̕͘̕͢′̴̧̱̖͉̗̾̏͆̾̍͆͌͞͠ͅ q̶̨̩̝̞͙͛̓̒͋͒ ķ̮̠͕̹̩̤̀̉̄̎̕͘̕͢′̨̧͖͇͈̳̣͆̑̑͂́͊͜͡′̥̳̥̦͈̫́̄́̍̔̽̑͞ứ̵͈͔̭͍͓̲͔͙͚́̆̊̏̚͠͡ q̵̢̛̼̥̭̪̼̆͋̂̑̅̚͠°͖̹̲̻̣͍̹͇́͋́̒̓͆͂̆͛͗ k̴̡̺̙͕͉̯̖̯͎͒̏̊͡͝
01 А а
02 Б б
03 В в
04 Г г
05 Гугу
06 Гъгъ
07 Гъу гъу<br>
08 Д д
09 Дждж
10 Дз дз
11 Дзу дзу
12 Ее
13 Ё ё   सिखइया स्ट्रीट'ान को'ं
14 Жж
15 Жъжъ
16 Жъу жъу
17 Жьжь
18 З з ′̡̡̟̬͍̿̀͋͗͆̿͘′̲̺̣̫̻̥̤̝̯̬͗͂̾̒̇̿̎̾ ẑ̛͚͚̼̳̠͖̋̒̊̀́ z̥̫̠̯͚̭͓̪̱̆́͗̈͛̄͜
19 И и
20 Й й
21 К к  में किताबां विचों पढ़ेया नि.o</p>
<p dir="auto">.o
.js
o u̧̧͚̺̙̟̪̹͕͑͒́̀̌̋̎͝k͇̗̻̞̗̹̅̊̃̈́̅̄̂y̴̧̡̬̳͉̦̗̻̪̓͒̌͐̄̕͠г̢̟̥̯̜̭͎̮̤̅͛̄̿̿͊̚͝͞л̴͎͇͕̯͕̞͖̊̓̍̔͑́͠͝а̨̛̱̳͖̗̯̫͗́̄̓г̢͓̠͇͎̘̝͑̃̓̓̓͟͢͠ӧ̶̧̢͍̠̜̰̩̫̜͛̐̆̂͘л̧̪̩̺̯̭́̍̌͘͜͜͜͡͝ѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠ (̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ ê̷͔̻̜͔̄̑̉̏̌̑̒̈́̕͜͜ͅ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ —͉̯͓͌̿͆́͋̄͜͟͡ z̸̡̛͉͖̠̦̬̺̓̈́͛͒͜h̸͙̘̫̻̠͕̺̥̅̂̐̎̌̍̈́͂͘͝ ž̷̧̠̤̖̗͎͚̖͖̘̈́̂̿̾̊̾͠ z̵͙̜͚͚͍̤̖͓͎̆̇̀͛̌͋͋̕͠͠h̸̡̢̨͉̼͔̝̋̏̿͑̓͑͟ͅ′̡̡̟̬͍̿̀͋͗͆̿͘′̲̺̣̫̻̥̤̝̯̬͗͂̾̒̇̿̎̾ ẑ̛͚͚̼̳̠͖̋̒̊̀́ z̥̫̠̯͚̭͓̪̱̆́͗̈͛̄͜h̶̡̤̺͈͙̟͆̈́̇́̈́̀′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅu̸̼͔̰̯̖̐͆͗̏͐̾͡ͅ ẑ̷̛̲̭͉̪̜̯͌̍̅̿́͢͠ͅ°̵̺̹̫̹͙͇͆̉̋̎̇̿͂͟͞͝ z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ′͍̠̤͉͓̦̦̦̻́͒͐͌̆̀͡ͅ ž̴͚̳̞̙͙͖̙͈̏̅̾͋͊͋̈̋͗͢′̨̟͉͔͙̐̅̓̃̀̕͟͠ z̦̬̠̳̻̃͂͋̎́̔͢͢͝ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝ ḯ̻̖̮̦͕͊̇͋̂͂͜͝ĭ̙̟͕͈̪̝̤͎̓̅̀̔̎̊̀̐̅͂͢͜ j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆ k̵̡̬͔̬̩͇̤͐͊̅͆̃ͅḣ̷̨̯̜̠̻̿͊͑̎̀͟ č̵̡̨̘͖̥͕͉̔̅̀̅͡͠′̵̸̡̡̛̳̹̰̰̲̣̲̞͕̝͇̟̩̀̀̍̈́̃̊̓̍̓̉̃̉̋͠ ḱ̵̛̛̻̗̻͉͓̀͒͞ḣ̷̭̮̰̙̞̜͎͔̪̜̔̂̈́̾̌̋̋̈́͝u̧̦̲͍̦̯̱̐̅̃̕͞ ḳ̶̡͖̮̖̹̻͐́́̀̔̇̄̑͑͢͝ͅ°̢̢̼̜͍͇͂͗͗̾̒̚ ḽ͉̰̱͈̳̺̰̮̊̍̐̏͆̌̐̕̚ l̵̨̡̛̻̻̺͚͚̤̯̺̈́̊̒̍͛͒͠ l̩̤̬̰̹̘̔̾̍̓̔̚͟′̡̭̖̼̙̩̼͆͑̃͆͆̏̽̄̾̕′̷̢͚͍̟̠͍̖̐́͋̿̓̍͂̆̍ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ l̨̢̥͉̎̍̅̐̚͜͟ḣ̨̘̭̼̜͇̹͓̹̊̀̽͛̎̒̚͞͝ ḷ̡͕͍͎̥̣͚̣̞͉̐̿̇̃̄͊͂̅͘q̨̢͓̣̦̦͙̤́̃̀́̀̑̆w̵͖̥͓͚̽̾͒̀͒͘ͅͅλxǯ̷̨̣̰͈̲̮̈́̈́̈́̓̄̊̈́͡′̵̡̨̬͎̙͋̐̂̇̀͊͋͊̊͒ ḑ̷͚̙̰̋́͑̿̕͜͟z̴̧̬̰̙̹̪̬͎͗͋̈́̓͌̒̅̾͟ ʒ̸͈͙̱̙̹̎́̀̔̋̈́́͘͟ d̵̘̟̼͓̮̄͒̊̒̎́̑̒͌̚z̛̛̼͚̬̱͙͒̒̇̌̓́̒̚͜͢ͅư̶͇̞̤̻̫̓́͑͌̃̑͟</p>
<p dir="auto">p p‡ p‡u r
s t t‡</p>
<p dir="auto">KNAB 2003(2.0)
a
b
v
g
gw  l̩̤̬̰̹̘̔̾̍̓̔̚͟′̡̭̖̼̙̩̼͆͑̃͆͆̏̽̄̾̕′̷̢͚͍̟̠͍̖̐́͋̿̓̍͂̆̍
ǧ
ǧw
d
De' ThR@W (a ball) TO Le EARN (money), from Cave Persn Speak
dź
dz dzw é,je(2.1′̡̡̟̬͍̿̀͋͗͆̿͘′̲̺̣̫̻̥̤̝̯̬͗͂̾̒̇̿̎̾ ) ë
dz dzw é,je(2j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆′̡̡̟̬͍̿̀͋͗͆̿͘′̲̺̣̫̻̥̤̝̯̬͗͂̾̒̇̿̎̾ .1 ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞) ë
dz dzw é,je(2.1′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅ) ë
dz dzw é,je(2.1 ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞) ë
dz dzw é,je(2′̡̡̟̬͍̿̀͋͗͆̿͘′̲̺̣̫̻̥̤̝̯̬͗͂̾̒̇̿̎̾ .1j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆) ë
ž
z̄
zw̄
ź</p>
<p dir="auto">z</p>
<p dir="auto">i</p>
<p dir="auto">j</p>
<p dir="auto">k</p>
<p dir="auto">kw</p>
<p dir="auto">q 💌. ݁₊ ⊹ . ݁˖ . ݁  . ⋆.𐙚 ̊</p>
<p dir="auto">q 💌. ݁₊ ⊹ . ݁˖ . ݁  . ⋆.𐙚 ̊</p>
<p dir="auto">⇶  qw ḉ,ķ (2.2)</p>
<p dir="auto">qw ḉ,ķ (2.2)</p>
<p dir="auto">ķw l</p>
<p dir="auto">ł</p>
<p dir="auto">ļ m n o p ṗ ṗw r</p>
<p dir="auto">s t ţ</p>
<p dir="auto">a ā b b v — g ɣ gu g° g′′ ġ g′′u ġ° d d dzh ǯ′ dz ʒ dzu ʒ° e e ë — zh ž zh′′ ẑ zh′′u ẑ° zh′ ž′ z z i i
ĭ j k — ku k° k′′ q k′′u q° kḣ č′̣ kḣu ḳ° l l l′′ ł lḣ ḷ m m n n o o p p pḣ ṗ pḣu ṗ° r r s s
t t tḣ ṭ</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="	think 𓆏 


	miladyѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠   



	 e̖͇̜̳̲͍̔̅̆̒̍̓͞ 



	(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ  



	(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ   e̖͇̜̳̲͍̔̅̆̒̍̓͞ "><pre class="notranslate"><code>	think 𓆏 


	miladyѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠   



	 e̖͇̜̳̲͍̔̅̆̒̍̓͞ 



	(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ  



	(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ   e̖͇̜̳̲͍̔̅̆̒̍̓͞ 
</code></pre></div>
<p dir="auto">g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BGOBLIN GOBLIN ROBIN RIHANNA ROBIN GOBLIN ROUND THE RIM ANOTHER GOBLET OF Gg̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BGOBLIN</p>
<p dir="auto">g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BGOBLIN GOBLIN ROBIN RIHANNA ROBIN GOBLIN ROUND THE RIM ANOTHER GOBLET OF Gg̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BGOBLIN</p>
<p dir="auto">g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BLIIIIIl̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ e̖͇̜̳̲͍̔̅̆̒̍̓͞strikes again!!!!</p>
<p dir="auto">g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BGOBLIN GOBLIN ROBIN RIHANNA ROBIN GOBLIN ROUND THE RIM ANOTHER GOBLET OF Gg̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BGOBLIN</p>
<p dir="auto">g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BLIIIIIl̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ e̖͇̜̳̲͍̔̅̆̒̍̓͞strikes again!!!!</p>
<p dir="auto">▁▂▃▄▅▆▇ 100% 「 ɴᴏᴡ ᴘʟᴀʏɪɴɢ 」 ──────⚪── ⇄ ◃◃ ⅠⅠ ▹▹ ↻</p>
<p dir="auto">g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BLIIIIIl̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ e̖͇̜̳̲͍̔̅̆̒̍̓͞strikes again!!!!</p>
<p dir="auto">g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BLIIIIIl̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ e̖͇̜̳̲͍̔̅̆̒̍̓͞strikes again!!!! g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BLIIIIIl̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ e̖͇̜̳̲͍̔̅̆̒̍̓͞strikes again!!!! g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BLIIIIIl̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ e̖͇̜̳̲͍̔̅̆̒̍̓͞strikes again!!!! g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BLIIIIIl̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ e̖͇̜̳̲͍̔̅̆̒̍̓͞strikes again!!! 「ɴᴏᴡ ᴘʟᴀʏɪɴɢ: fuck you pay me .mp3 」  g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BLIIIIIl̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ e̖͇̜̳̲͍̔̅̆̒̍̓͞strikes again!!!!</p>
<p dir="auto">40 ТӀу тӀу
41 У у
42 Ф ф
43 ФӀ фӀ
44 Х х
45 Хуху
46 Хъхъ<br>
47 Хъух ъу
48 Хьх ь<br>
49 Ц ц
50 Цу цу
51 ЦӀцӀ
52 Ч ч
53 Чъчъ
54 ЧӀчӀ
55 Шш
56 Шъш ъ
57 Шъуш ъу
58 Ш ӀшӀ
59 ШӀ уш Ӏу
60 Щ щ
61 Ъ ъ 
62 Ы ы
63 Ь ь
64 Э э<br>
65 Ю ю
66 Я я
67 Ӏ Ӏ
68 Ӏу Ӏу<br>
69 Unkraine Huge Craine ꑭ</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="63 Ь ь  ьlyat
"><pre class="notranslate"><code>63 Ь ь  ьlyat

</code></pre></div>
<p dir="auto">64 Э э   эlyat эlyatэlyatэlyatэ</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="65 Ю ю юlyat юlyatюю юlyatt
"><pre class="notranslate"><code>65 Ю ю юlyat юlyatюю юlyatt

</code></pre></div>
<p dir="auto">66 Я я я яlyat  siяя Я'atlyatяly</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="67 Ӏ Ӏ lyat lyat
"><pre class="notranslate"><code>67 Ӏ Ӏ lyat lyat

</code></pre></div>
<p dir="auto">68 Ӏу Ӏу  lyat  Ӏу  lyat  Ӏу  l Ӏу  lyat  yat</p>
<p dir="auto">#ж#ж#ж#ж# 。。。。。你的爱就像自来水 ^ 我直接从水龙头里喝。。。。。。。#ж#ж#ж#ж#</p>
<p dir="auto">#ж#ж#ж#ж# 。。。。。你的爱就像自来水 ж 我直接从水龙头里喝。。。。。。。#ж#ж#ж#ж#</p>
<p dir="auto">#ж#ж#ж#ж# 。。。。。你的爱就像自来水 x 我直接从水龙头里喝。。。。。。。#ж#ж#ж#ж#</p>
<p dir="auto">#ж#ж#ж#ж# 。。。。。你的爱就像自来水 X 我直接从水龙头里喝。。。。。。。#ж#ж#ж#ж#</p>
<p dir="auto">#ж#ж#ж#ж# 。。。。。你的爱就像自来水 x 我直接从水龙头里喝。。。。。。。#ж#ж#ж#ж#</p>
<p dir="auto">#ж#ж#ж#ж# 。。。。。你的爱就像自来水 ж 我直接从水龙头里喝。。。。。。。#ж#ж#ж#ж#</p>
<p dir="auto">#ж#ж#ж#ж# 。。。。。你的爱就像自来水 V 我直接从水龙头里喝。。。。。。。#ж#ж#ж#ж#
// op: 0 = ADD, 1 = SUB, 2 = MUL
// sat: 0 = no saturation, 1 = saturation
:function:::void:do_ph_op:int rd, int rs, int rt, int op, int sat
{
int i;
signed32 h0 = 0;
signed16 h1, h2;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned32 result = 0;
for (i = 0; i &lt; 32; i += 16, v1 &gt;&gt;= 16, v2 &gt;&gt;= 16)
{
h1 = (signed16)(v1 &amp; 0xffff);
h2 = (signed16)(v2 &amp; 0xffff);
if (op == 0) // ADD
h0 = (signed32)h1 + (signed32)h2;
else if (op == 1) // SUB
h0 = (signed32)h1 - (signed32)h2;
else // MUL
h0 = (signed32)h1 * (signed32)h2;
if (h0 &gt; (signed32)0x7fff || h0 &lt; (signed32)0xffff8000)
{
if (op == 0 || op == 1) // ADD, SUB
DSPCR |= DSPCR_OUFLAG4;
else if (op == 2) // MUL
DSPCR |= DSPCR_OUFLAG5;
if (sat == 1)
{
if (h0 &gt; (signed32)0x7fff)
h0 = 0x7fff;
else
h0 = 0x8000;
}
}
result |= ((unsigned32)((unsigned16)h0) &lt;&lt; i);
}
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">// op: 0 = ADD, 1 = SUB
:function:::void:do_w_op:int rd, int rs, int rt, int op
{
signed64 h0;
signed32 h1, h2;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned32 result = 0;
h1 = (signed32)v1;
h2 = (signed32)v2;
if (op == 0) // ADD
h0 = (signed64)h1 + (signed64)h2;
else // SUB
h0 = (signed64)h1 - (signed64)h2;
if (((h0 &amp; 0x100000000LL) &gt;&gt; 1) != (h0 &amp; 0x80000000))
{
DSPCR |= DSPCR_OUFLAG4;
if (h0 &amp; 0x100000000LL)
h0 = 0x80000000;
else
h0 = 0x7fffffff;
}
GPR[rd] = EXTEND32 (h0);
}</p>
<p dir="auto">// op: 0 = ADD, 1 = SUB
// sat: 0 = no saturation, 1 = saturation
:function:::void:do_qb_op:int rd, int rs, int rt, int op, int sat
{
int i;
unsigned32 h0;
unsigned8 h1, h2;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned32 result = 0;
for (i = 0; i &lt; 32; i += 8, v1 &gt;&gt;= 8, v2 &gt;&gt;= 8)
{
h1 = (unsigned8)(v1 &amp; 0xff);
h2 = (unsigned8)(v2 &amp; 0xff);
if (op == 0) // ADD
h0 = (unsigned32)h1 + (unsigned32)h2;
else // SUB
h0 = (unsigned32)h1 - (unsigned32)h2;
if (h0 &amp; 0x100)
{
DSPCR |= DSPCR_OUFLAG4;
if (sat == 1)
{
if (op == 0) // ADD
h0 = 0xff;
else // SUB
h0 = 0;
}
}
result |= ((unsigned32)((unsigned8)h0) &lt;&lt; i);
}
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">// op: 0 = left, 1 = right
:function:::void:do_qb_shift:int rd, int rt, int shift, int op
{
int i, j;
unsigned8 h0;
unsigned32 v1 = GPR[rt];
unsigned32 result = 0;
for (i = 0; i &lt; 32; i += 8, v1 &gt;&gt;= 8)
{
h0 = (unsigned8)(v1 &amp; 0xff);
if (op == 0) // left
{
for (j = 7; j &gt;= 8 - shift; j--)
{
if (h0 &amp; (1&lt;&lt;j))
{
DSPCR |= DSPCR_OUFLAG6;
break;
}
}
h0 = h0 &lt;&lt; shift;
}
else // right
h0 = h0 &gt;&gt; shift;
result |= ((unsigned32)h0 &lt;&lt; i);
}
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">// op: 0 = left, 1 = right
// sat: 0 = no saturation/rounding, 1 = saturation/rounding
:function:::void:do_ph_shift:int rd, int rt, int shift, int op, int sat
{
int i, j;
signed16 h0;
unsigned32 v1 = GPR[rt];
unsigned32 result = 0;
int setcond;
for (i = 0; i &lt; 32; i += 16, v1 &gt;&gt;= 16)
{
h0 = (signed16)(v1 &amp; 0xffff);
if (op == 0) // left
{
setcond = 0;
if (h0 &amp; (1&lt;&lt;15))
{
for (j = 14; j &gt;= 15 - shift; j--)
{
if (!(h0 &amp; (1 &lt;&lt; j)))
{
DSPCR |= DSPCR_OUFLAG6;
setcond = 1;
break;
}
}
}
else
{
for (j = 14; j &gt;= 15 - shift; j--)
{
if (h0 &amp; (1 &lt;&lt; j))
{
DSPCR |= DSPCR_OUFLAG6;
setcond = 2;
break;
}
}
}
h0 = h0 &lt;&lt; shift;
if (sat == 1)
{
if (setcond == 2)
h0 = 0x7fff;
else if (setcond == 1)
h0 = 0x8000;
}
}
else // right
{
if (sat == 1 &amp;&amp; shift != 0 &amp;&amp; (h0 &amp; (1 &lt;&lt; (shift-1))))
h0 = (h0 &gt;&gt; shift) + 1;
else
h0 = h0 &gt;&gt; shift;
}</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="  result |= ((unsigned32)((unsigned16)h0) &lt;&lt; i);
}"><pre class="notranslate"><code>  result |= ((unsigned32)((unsigned16)h0) &lt;&lt; i);
}
</code></pre></div>
<p dir="auto">GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">:function:::void:do_w_shll:int rd, int rt, int shift
{
int i;
unsigned32 v1 = GPR[rt];
unsigned32 result = 0;
int setcond = 0;
if (v1 &amp; (1 &lt;&lt; 31))
{
for (i = 30; i &gt;= 31 - shift; i--)
{
if (!(v1 &amp; (1 &lt;&lt; i)))
{
DSPCR |= DSPCR_OUFLAG6;
setcond = 1;
break;
}
}
}
else
{
for (i = 30; i &gt;= 31 - shift; i--)
{
if (v1 &amp; (1 &lt;&lt; i))
{
DSPCR |= DSPCR_OUFLAG6;
setcond = 2;
break;
}
}
}
if (setcond == 2)
result = 0x7fffffff;
else if (setcond == 1)
result = 0x80000000;
else
result = v1 &lt;&lt; shift;
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">:function:::void:do_ph_s_absq:int rd, int rt
{
int i;
signed16 h0;
unsigned32 v1 = GPR[rt];
unsigned32 result = 0;
for (i = 0; i &lt; 32; i += 16, v1 &gt;&gt;= 16)
{
h0 = (signed16)(v1 &amp; 0xffff);
if (h0 == (signed16)0x8000)
{
DSPCR |= DSPCR_OUFLAG4;
h0 = 0x7fff;
}
else if (h0 &amp; 0x8000)
h0 = -h0;
result |= ((unsigned32)((unsigned16)h0) &lt;&lt; i);
}
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">:function:::void:do_w_s_absq:int rd, int rt
{
unsigned32 v1 = GPR[rt];
signed32 h0 = (signed32)v1;
if (h0 == (signed32)0x80000000)
{
DSPCR |= DSPCR_OUFLAG4;
h0 = 0x7fffffff;
}
else if (h0 &amp; 0x80000000)
h0 = -h0;
GPR[rd] = EXTEND32 (h0);
}</p>
<p dir="auto">:function:::void:do_qb_s_absq:int rd, int rt
{
int i;
signed8 q0;
unsigned32 v1 = GPR[rt];
unsigned32 result = 0;
for (i = 0; i &lt; 32; i += 8, v1 &gt;&gt;= 8)
{
q0 = (signed8)(v1 &amp; 0xff);
if (q0 == (signed8)0x80)
{
DSPCR |= DSPCR_OUFLAG4;
q0 = 0x7f;
}
else if (q0 &amp; 0x80)
q0 = -q0;
result |= ((unsigned32)((unsigned8)q0) &lt;&lt; i);
}
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">:function:::void:do_addsc:int rd, int rs, int rt
{
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned64 h0;
h0 = (unsigned64)v1 + (unsigned64)v2;
if (h0 &amp; 0x100000000LL)
DSPCR |= DSPCR_CARRY;
GPR[rd] = EXTEND32 (h0);
}</p>
<p dir="auto">:function:::void:do_addwc:int rd, int rs, int rt
{
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned64 h0;
signed32 h1 = (signed32) v1;
signed32 h2 = (signed32) v2;
h0 = (signed64)h1 + (signed64)h2
+ (signed64)((DSPCR &gt;&gt; DSPCR_CARRY_SHIFT) &amp; DSPCR_CARRY_MASK);
if (((h0 &amp; 0x100000000LL) &gt;&gt; 1) != (h0 &amp; 0x80000000))
DSPCR |= DSPCR_OUFLAG4;
GPR[rd] = EXTEND32 (h0);
}</p>
<p dir="auto">:function:::void:do_bitrev:int rd, int rt
{
int i;
unsigned32 v1 = GPR[rt];
unsigned32 h1 = 0;
for (i = 0; i &lt; 16; i++)
{
if (v1 &amp; (1 &lt;&lt; i))
h1 |= (1 &lt;&lt; (15 - i));
}
GPR[rd] = EXTEND32 (h1);
}</p>
<p dir="auto">// op: 0 = EXTPV, 1 = EXTPDPV
:function:::void:do_extpv:int rt, int ac, int rs, int op
{
unsigned32 size = GPR[rs] &amp; 0x1f;
do_extp (SD_, rt, ac, size, op);
}</p>
<p dir="auto">// op: 0 = EXTRV, 1 = EXTRV_R, 2 = EXTRV_RS
:function:::void:do_extrv:int rt, int ac, int rs, int op
{
unsigned32 shift = GPR[rs] &amp; 0x1f;
do_w_extr (SD_, rt, ac, shift, op);
}</p>
<p dir="auto">:function:::void:do_extrv_s_h:int rt, int ac, int rs
{
unsigned32 shift = GPR[rs] &amp; 0x1f;
do_h_extr (SD_, rt, ac, shift);
}</p>
<p dir="auto">:function:::void:do_insv:int rt, int rs
{
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned32 pos = (DSPCR &gt;&gt; DSPCR_POS_SHIFT) &amp; DSPCR_POS_MASK;
unsigned32 size = (DSPCR &gt;&gt; DSPCR_SCOUNT_SHIFT) &amp; DSPCR_SCOUNT_MASK;
unsigned32 mask1, mask2, mask3, result;
if (size &lt; 32)
mask1 = (1 &lt;&lt; size) - 1;
else
mask1 = 0xffffffff;
mask2 = (1 &lt;&lt; pos) - 1;
if (pos + size &lt; 32)
mask3 = ~((1 &lt;&lt; (pos + size)) - 1);
else
mask3 = 0;
result = (v2 &amp; mask3) | ((v1 &amp; mask1) &lt;&lt; pos) | (v2 &amp; mask2);
GPR[rt] = EXTEND32 (result);
}</p>
<p dir="auto">// op: 0 = NORMAL,  1 = EXTEND16, 2 = EXTEND32
:function:::void:do_lxx:int rd, int base, int index, int op
{
if (op == 0)
GPR[rd] = do_load (SD_, AccessLength_BYTE, GPR[base], GPR[index]);
else if (op == 1)
GPR[rd] = EXTEND16 (do_load (SD_, AccessLength_HALFWORD, GPR[base], GPR[index]));
else if (op == 2)
GPR[rd] = EXTEND32 (do_load (SD_, AccessLength_WORD, GPR[base], GPR[index]));
}</p>
<p dir="auto">:function:::void:do_modsub:int rd, int rs, int rt
{
unsigned32 result = 0;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned32 decr = v2 &amp; 0xff;
unsigned32 lastindex = (v2 &amp; 0xffff00) &gt;&gt; 8;
if (v1 == 0)
result = lastindex;
else
result =  v1 - decr;
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">:function:::void:do_mthlip:int rs, int ac
{
unsigned32 pos = (DSPCR &gt;&gt; DSPCR_POS_SHIFT) &amp; DSPCR_POS_MASK;
DSPHI(ac) = DSPLO(ac);
DSPLO(ac) = GPR[rs];
if (pos &gt;= 32)
Unpredictable ();
else
pos += 32;
DSPCR &amp;= (~DSPCR_POS_SMASK);
DSPCR |= (pos &amp; DSPCR_POS_MASK) &lt;&lt; DSPCR_POS_SHIFT;
}</p>
<p dir="auto">:function:::void:do_mulsaq_s_w_ph:int ac, int rs, int rt
{
int i;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
signed16 h1, h2;
signed32 result;
unsigned32 lo = DSPLO(ac);
unsigned32 hi = DSPHI(ac);
signed64 prod = (signed64)((((unsigned64)hi) &lt;&lt; 32) + (unsigned64)lo);
for (i = 0; i &lt; 32; i += 16, v1 &gt;&gt;= 16, v2 &gt;&gt;= 16)
{
h1 = (signed16)(v1 &amp; 0xffff);
h2 = (signed16)(v2 &amp; 0xffff);
if (h1 == (signed16)0x8000 &amp;&amp; h2 == (signed16)0x8000)
{
DSPCR |= (1 &lt;&lt; (DSPCR_OUFLAG_SHIFT + ac));
result = (signed32) 0x7fffffff;
}
else
result = ((signed32)h1 * (signed32)h2) &lt;&lt; 1;</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="  if (i == 0)
prod -= (signed64) result;
  else
prod += (signed64) result;
}"><pre class="notranslate"><code>  if (i == 0)
prod -= (signed64) result;
  else
prod += (signed64) result;
}
</code></pre></div>
<p dir="auto">DSPLO(ac) = EXTEND32 (prod);
DSPHI(ac) = EXTEND32 (prod &gt;&gt; 32);
}</p>
<p dir="auto">:function:::void:do_ph_packrl:int rd, int rs, int rt
{</p>
<p dir="auto">unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
GPR[rd] = EXTEND32 ((v1 &lt;&lt; 16) + (v2 &gt;&gt; 16));
}</p>
<p dir="auto">:function:::void:do_qb_pick:int rd, int rs, int rt
{
int i, j;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned8 h1, h2;
unsigned32 result = 0;
for (i = 0, j = 0; i &lt; 32; i += 8, j++, v1 &gt;&gt;= 8, v2 &gt;&gt;= 8)
{
h1 = (unsigned8)(v1 &amp; 0xff);
h2 = (unsigned8)(v2 &amp; 0xff);
if (DSPCR &amp; (1 &lt;&lt; (DSPCR_CCOND_SHIFT + j)))
result |= (unsigned32)(h1 &lt;&lt; i);
else
result |= (unsigned32)(h2 &lt;&lt; i);
}
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">:function:::void:do_ph_pick:int rd, int rs, int rt
{
int i, j;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned16 h1, h2;
unsigned32 result = 0;
for (i = 0, j = 0; i &lt; 32; i += 16, j++, v1 &gt;&gt;= 16, v2 &gt;&gt;= 16)
{
h1 = (unsigned16)(v1 &amp; 0xffff);
h2 = (unsigned16)(v2 &amp; 0xffff);
if (DSPCR &amp; (1 &lt;&lt; (DSPCR_CCOND_SHIFT + j)))
result |= (unsigned32)(h1 &lt;&lt; i);
else
result |= (unsigned32)(h2 &lt;&lt; i);
}
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">// op: 0 = QBR, 1 = QBRA, 2 = QBL, 3 = QBLA
:function:::void:do_qb_ph_precequ:int rd, int rt, int op
{
unsigned32 v1 = GPR[rt];
if (op == 0)
GPR[rd] = EXTEND32 ((v1 &amp; 0xff00) &lt;&lt; 15) | ((v1 &amp; 0xff) &lt;&lt; 7);
else if (op == 1)
GPR[rd] = EXTEND32 ((v1 &amp; 0xff0000) &lt;&lt; 7) | ((v1 &amp; 0xff) &lt;&lt; 7);
else if (op == 2)
GPR[rd] = EXTEND32 ((v1 &amp; 0xff000000) &gt;&gt; 1) | ((v1 &amp; 0xff0000) &gt;&gt; 9);
else if (op == 3)
GPR[rd] = EXTEND32 ((v1 &amp; 0xff000000) &gt;&gt; 1) | ((v1 &amp; 0xff00) &gt;&gt; 1);
}</p>
<p dir="auto">// op: 0 = QBR, 1 = QBRA, 2 = QBL, 3 = QBLA
:function:::void:do_qb_ph_preceu:int rd, int rt, int op
{
unsigned32 v1 = GPR[rt];
if (op == 0)
GPR[rd] = EXTEND32 ((v1 &amp; 0xff00) &lt;&lt; 8) | (v1 &amp; 0xff);
else if (op == 1)
GPR[rd] = EXTEND32 ((v1 &amp; 0xff0000) | (v1 &amp; 0xff));
else if (op == 2)
GPR[rd] = EXTEND32 ((v1 &amp; 0xff000000) &gt;&gt; 8) | ((v1 &amp; 0xff0000) &gt;&gt; 16);
else if (op == 3)
GPR[rd] = EXTEND32 ((v1 &amp; 0xff000000) &gt;&gt; 8) | ((v1 &amp; 0xff00) &gt;&gt; 8);
}</p>
<p dir="auto">// op: 0 = .PHL, 1 = PHR
:function:::void:do_w_preceq:int rd, int rt, int op
{
unsigned32 v1 = GPR[rt];
if (op == 0)
GPR[rd] = EXTEND32 (v1 &amp; 0xffff0000);
else if (op == 1)
GPR[rd] = EXTEND32 ((v1 &amp; 0xffff) &lt;&lt; 16);
}</p>
<p dir="auto">:function:::void:do_w_ph_precrq:int rd, int rs, int rt
{
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned32 tempu = (v1 &amp; 0xffff0000) &gt;&gt; 16;
unsigned32 tempv = (v2 &amp; 0xffff0000) &gt;&gt; 16;
GPR[rd] = EXTEND32 ((tempu &lt;&lt; 16) | tempv);
}</p>
<p dir="auto">// sat: 0 = PRECRQ.QB.PH, 1 = PRECRQU_S.QB.PH
:function:::void:do_ph_qb_precrq:int rd, int rs, int rt, int sat
{
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned32 tempu = 0, tempv = 0, tempw = 0, tempx = 0;
if (sat == 0)
{
tempu = (v1 &amp; 0xff000000) &gt;&gt; 24;
tempv = (v1 &amp; 0xff00) &gt;&gt; 8;
tempw = (v2 &amp; 0xff000000) &gt;&gt; 24;
tempx = (v2 &amp; 0xff00) &gt;&gt; 8;
}
else if (sat == 1)
{
if (v1 &amp; 0x80000000)
{
DSPCR |= DSPCR_OUFLAG6;
tempu = 0;
}
else if (!(v1 &amp; 0x80000000) &amp;&amp; ((v1 &gt;&gt; 16) &gt; (unsigned32)0x7f80))
{
DSPCR |= DSPCR_OUFLAG6;
tempu = 0xff;
}
else
tempu = (v1 &amp; 0x7f800000) &gt;&gt; 23;
if (v1 &amp; 0x8000)
{
DSPCR |= DSPCR_OUFLAG6;
tempv = 0;
}
else if (!(v1 &amp; 0x8000) &amp;&amp; ((v1 &amp; 0xffff) &gt; (unsigned32)0x7f80))
{
DSPCR |= DSPCR_OUFLAG6;
tempv = 0xff;
}
else
tempv = (v1 &amp; 0x7f80) &gt;&gt; 7;
if (v2 &amp; 0x80000000)
{
DSPCR |= DSPCR_OUFLAG6;
tempw = 0;
}
else if (!(v2 &amp; 0x80000000) &amp;&amp; ((v2 &gt;&gt; 16) &gt; (unsigned32)0x7f80))
{
DSPCR |= DSPCR_OUFLAG6;
tempw = 0xff;
}
else
tempw = (v2 &amp; 0x7f800000) &gt;&gt; 23;
if (v2 &amp; 0x8000)
{
DSPCR |= DSPCR_OUFLAG6;
tempx = 0;
}
else if (!(v2 &amp; 0x8000) &amp;&amp; ((v2 &amp; 0xffff) &gt; (unsigned32)0x7f80))
{
DSPCR |= DSPCR_OUFLAG6;
tempx = 0xff;
}
else
tempx = (v2 &amp; 0x7f80) &gt;&gt; 7;
}
GPR[rd] = EXTEND32 ((tempu &lt;&lt; 24) | (tempv &lt;&lt; 16) | (tempw &lt;&lt; 8) | tempx);
}</p>
<p dir="auto">:function:::void:do_w_ph_rs_precrq:int rd, int rs, int rt
{
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
signed32 h1 = (signed32)v1;
signed32 h2 = (signed32)v2;
signed64 temp1 = (signed64)h1 + (signed64)0x8000;
signed32 temp2;
signed64 temp3 = (signed64)h2 + (signed64)0x8000;
signed32 temp4;
if (((temp1 &amp; 0x100000000LL) &gt;&gt; 1) != (temp1 &amp; 0x80000000))
{
DSPCR |= DSPCR_OUFLAG6;
temp2 = 0x7fff;
}
else
temp2 = (signed32)((temp1 &amp; 0xffff0000) &gt;&gt; 16);
if (((temp3 &amp; 0x100000000LL) &gt;&gt; 1) != (temp3 &amp; 0x80000000))
{
DSPCR |= DSPCR_OUFLAG6;
temp4 = 0x7fff;
}
else
temp4 = (signed32)((temp3 &amp; 0xffff0000) &gt;&gt; 16);
GPR[rd] = EXTEND32 ((temp2 &lt;&lt; 16) | temp4);
}</p>
<p dir="auto">:function:::void:do_qb_w_raddu:int rd, int rs
{
int i;
unsigned8 h0;
unsigned32 v1 = GPR[rs];
unsigned32 result = 0;
for (i = 0; i &lt; 32; i += 8, v1 &gt;&gt;= 8)
{
h0 = (unsigned8)(v1 &amp; 0xff);
result += (unsigned32)h0;
}
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">:function:::void:do_rddsp:int rd, int mask
{
unsigned32 result = 0;
if (mask &amp; 0x1)
{
result &amp;= (~DSPCR_POS_SMASK);
result |= (DSPCR &amp; DSPCR_POS_SMASK);
}
if (mask &amp; 0x2)
{
result &amp;= (~DSPCR_SCOUNT_SMASK);
result |= (DSPCR &amp; DSPCR_SCOUNT_SMASK);
}
if (mask &amp; 0x4)
{
result &amp;= (~DSPCR_CARRY_SMASK);
result |= (DSPCR &amp; DSPCR_CARRY_SMASK);
}
if (mask &amp; 0x8)
{
result &amp;= (~DSPCR_OUFLAG_SMASK);
result |= (DSPCR &amp; DSPCR_OUFLAG_SMASK);
}
if (mask &amp; 0x10)
{
result &amp;= (~DSPCR_CCOND_SMASK);
result |= (DSPCR &amp; DSPCR_CCOND_SMASK);
}
if (mask &amp; 0x20)
{
result &amp;= (~DSPCR_EFI_SMASK);
result |= (DSPCR &amp; DSPCR_EFI_SMASK);
}
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">// op: 0 = REPL.QB, 1 = REPLV.QB, 2 = REPL.PH, 3 = REPLV.PH
:function:::void:do_repl:int rd, int p2, int op
{
if (op == 0)
GPR[rd] = EXTEND32 ((p2 &lt;&lt; 24) | (p2 &lt;&lt; 16) | (p2 &lt;&lt; 8) | p2);
else if (op == 1)
{
unsigned32 v1 = GPR[p2] &amp; 0xff;
GPR[rd] = EXTEND32 ((v1 &lt;&lt; 24) | (v1 &lt;&lt; 16) | (v1 &lt;&lt; 8) | v1);
}
else if (op == 2)
{
signed32 v1 = p2;
if (v1 &amp; 0x200)
v1 |= 0xfffffc00;
GPR[rd] = EXTEND32 ((v1 &lt;&lt; 16) | (v1 &amp; 0xffff));
}
else if (op == 3)
{
unsigned32 v1 = GPR[p2];
v1 = v1 &amp; 0xffff;
GPR[rd] = EXTEND32 ((v1 &lt;&lt; 16) | v1);
}
}</p>
<p dir="auto">:function:::void:do_shilov:int ac, int rs
{
signed32 shift = GPR[rs] &amp; 0x3f;
do_shilo (SD_, ac, shift);
}</p>
<p dir="auto">// op: 0 = SHLLV, 1 = SHRAV
// sat: 0 =  normal, 1 = saturate/rounding
:function:::void:do_ph_shl:int rd, int rt, int rs, int op, int sat
{
unsigned32 shift = GPR[rs] &amp; 0xf;
do_ph_shift (SD_, rd, rt, shift, op, sat);
}</p>
<p dir="auto">// op: 0 = SHLLV, 1 = SHRLV
:function:::void:do_qb_shl:int rd, int rt, int rs, int op
{
unsigned32 shift = GPR[rs] &amp; 0x7;
do_qb_shift (SD_, rd, rt, shift, op);
}</p>
<p dir="auto">:function:::void:do_w_s_shllv:int rd, int rt, int rs
{
unsigned32 shift = GPR[rs] &amp; 0x1f;
do_w_shll (SD_, rd, rt, shift);
}</p>
<p dir="auto">:function:::void:do_ph_shrlv:int rd, int rt, int rs
{
unsigned32 shift = GPR[rs] &amp; 0xf;
do_ph_shrl (SD_, rd, rt, shift);
}</p>
<p dir="auto">:function:::void:do_w_r_shrav:int rd, int rt, int rs
{
unsigned32 shift = GPR[rs] &amp; 0x1f;
do_w_shra (SD_, rd, rt, shift);
}</p>
<p dir="auto">:function:::void:do_wrdsp:int rs, int mask
{
unsigned32 v1 = GPR[rs];
if (mask &amp; 0x1)
{
DSPCR &amp;= (~DSPCR_POS_SMASK);
DSPCR |= (v1 &amp; DSPCR_POS_SMASK);
}
if (mask &amp; 0x2)
{
DSPCR &amp;= (~DSPCR_SCOUNT_SMASK);
DSPCR |= (v1 &amp; DSPCR_SCOUNT_SMASK);
}
if (mask &amp; 0x4)
{
DSPCR &amp;= (~DSPCR_CARRY_SMASK);
DSPCR |= (v1 &amp; DSPCR_CARRY_SMASK);
}
if (mask &amp; 0x8)
{
DSPCR &amp;= (~DSPCR_OUFLAG_SMASK);
DSPCR |= (v1 &amp; DSPCR_OUFLAG_SMASK);
}
if (mask &amp; 0x10)
{
DSPCR &amp;= (~DSPCR_CCOND_SMASK);
DSPCR |= (v1 &amp; DSPCR_CCOND_SMASK);
}
if (mask &amp; 0x20)
{
DSPCR &amp;= (~DSPCR_EFI_SMASK);
DSPCR |= (v1 &amp; DSPCR_EFI_SMASK);
}
}</p>
<p dir="auto">// round: 0 = no rounding, 1 = rounding
:function:::void:do_qb_shrav:int rd, int rt, int rs, int round
{
unsigned32 shift = GPR[rs] &amp; 0x7;
do_qb_shra (SD_, rd, rt, shift, round);
}</p>
<p dir="auto">:function:::void:do_append:int rt, int rs, int sa
{
unsigned32 v0 = GPR[rs];
unsigned32 v1 = GPR[rt];
unsigned32 result;
unsigned32 mask = (1 &lt;&lt; sa) - 1;
result = (v1 &lt;&lt; sa) | (v0 &amp; mask);
GPR[rt] = EXTEND32 (result);
}</p>
<p dir="auto">:function:::void:do_balign:int rt, int rs, int bp
{
unsigned32 v0 = GPR[rs];
unsigned32 v1 = GPR[rt];
unsigned32 result;
if (bp == 0)
result = v1;
else
result = (v1 &lt;&lt; 8 * bp) | (v0 &gt;&gt; 8 * (4 - bp));
GPR[rt] = EXTEND32 (result);
}</p>
<p dir="auto">:function:::void:do_ph_w_mulsa:int ac, int rs, int rt
{
int i;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
signed16 h1, h2;
signed32 result;
unsigned32 lo = DSPLO(ac);
unsigned32 hi = DSPHI(ac);
signed64 prod = (signed64)((((unsigned64)hi) &lt;&lt; 32) + (unsigned64)lo);
for (i = 0; i &lt; 32; i += 16, v1 &gt;&gt;= 16, v2 &gt;&gt;= 16)
{
h1 = (signed16)(v1 &amp; 0xffff);
h2 = (signed16)(v2 &amp; 0xffff);
result = (signed32)h1 * (signed32)h2;</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="  if (i == 0)
prod -= (signed64) result;
  else
prod += (signed64) result;
}"><pre class="notranslate"><code>  if (i == 0)
prod -= (signed64) result;
  else
prod += (signed64) result;
}
</code></pre></div>
<p dir="auto">DSPLO(ac) = EXTEND32 (prod);
DSPHI(ac) = EXTEND32 (prod &gt;&gt; 32);
}</p>
<p dir="auto">:function:::void:do_ph_qb_precr:int rd, int rs, int rt
{
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned32 tempu = (v1 &amp; 0xff0000) &gt;&gt; 16;
unsigned32 tempv = (v1 &amp; 0xff);
unsigned32 tempw = (v2 &amp; 0xff0000) &gt;&gt; 16;
unsigned32 tempx = (v2 &amp; 0xff);
GPR[rd] = EXTEND32 ((tempu &lt;&lt; 24) | (tempv &lt;&lt; 16) | (tempw &lt;&lt; 8) | tempx);
}</p>
<p dir="auto">:function:::void:do_prepend:int rt, int rs, int sa
{
unsigned32 v0 = GPR[rs];
unsigned32 v1 = GPR[rt];
unsigned32 result;
if (sa == 0)
result = v1;
else
result = (v0 &lt;&lt; (32 - sa)) | (v1 &gt;&gt; sa);
GPR[rt] = EXTEND32 (result);
}</p>
<p dir="auto">:function:::void:do_w_shra:int rd, int rt, int shift
{
unsigned32 result = GPR[rt];
signed32 h0 = (signed32)result;
if (shift != 0 &amp;&amp; (h0 &amp; (1 &lt;&lt; (shift-1))))
h0 = (h0 &gt;&gt; shift) + 1;
else
h0 = h0 &gt;&gt; shift;
GPR[rd] = EXTEND32 (h0);
}</p>
<p dir="auto">011111,5.RS,5.RT,5.RD,01010,010000:SPECIAL3:32::ADDQ.PH
"addq.ph r, r, r<rt>"
*dsp:
{
do_ph_op (SD_, RD, RS, RT, 0, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,01110,010000:SPECIAL3:32::ADDQ_S.PH
"addq_s.ph r, r, r<rt>"
*dsp:
{
do_ph_op (SD_, RD, RS, RT, 0, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,10110,010000:SPECIAL3:32::ADDQ_S.W
"addq_s.w r, r, r<rt>"
*dsp:
{
do_w_op (SD_, RD, RS, RT, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,00000,010000:SPECIAL3:32::ADDU.QB
"addu.qb r, r, r<rt>"
*dsp:
{
do_qb_op (SD_, RD, RS, RT, 0, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,00100,010000:SPECIAL3:32::ADDU_S.QB
"addu_s.qb r, r, r<rt>"
*dsp:
{
do_qb_op (SD_, RD, RS, RT, 0, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,01011,010000:SPECIAL3:32::SUBQ.PH
"subq.ph r, r, r<rt>"
*dsp:
{
do_ph_op (SD_, RD, RS, RT, 1, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,01111,010000:SPECIAL3:32::SUBQ_S.PH
"subq_s.ph r, r, r<rt>"
*dsp:
{
do_ph_op (SD_, RD, RS, RT, 1, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,10111,010000:SPECIAL3:32::SUBQ_S.W
"subq_s.w r, r, r<rt>"
*dsp:
{
do_w_op (SD_, RD, RS, RT, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,00001,010000:SPECIAL3:32::SUBU.QB
"subu.qb r, r, r<rt>"
*dsp:
{
do_qb_op (SD_, RD, RS, RT, 1, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,00101,010000:SPECIAL3:32::SUBU_S.QB
"subu_s.qb r, r, r<rt>"
*dsp:
{
do_qb_op (SD_, RD, RS, RT, 1, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,10000,010000:SPECIAL3:32::ADDSC
"addsc r, r, r<rt>"
*dsp:
{
do_addsc (SD_, RD, RS, RT);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,10001,010000:SPECIAL3:32::ADDWC
"addwc r, r, r<rt>"
*dsp:
{
do_addwc (SD_, RD, RS, RT);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,10010,010000:SPECIAL3:32::MODSUB
"modsub r, r, r<rt>"
*dsp:
{
do_modsub (SD_, RD, RS, RT);
}</rt></p>
<p dir="auto">011111,5.RS,00000,5.RD,10100,010000:SPECIAL3:32::RADDU.W.QB
"raddu.w.qb r, r"
*dsp:
{
do_qb_w_raddu (SD_, RD, RS);
}</p>
<p dir="auto">011111,00000,5.RT,5.RD,01001,010010:SPECIAL3:32::ABSQ_S.PH
"absq_s.ph r, r<rt>"
*dsp:
{
do_ph_s_absq (SD_, RD, RT);
}</rt></p>
<p dir="auto">011111,00000,5.RT,5.RD,10001,010010:SPECIAL3:32::ABSQ_S.W
"absq_s.w r, r<rt>"
*dsp:
{
do_w_s_absq (SD_, RD, RT);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,01100,010001:SPECIAL3:32::PRECRQ.QB.PH
"precrq.qb.ph r, r, r<rt>"
*dsp:
{
do_ph_qb_precrq (SD_, RD, RS, RT, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,10100,010001:SPECIAL3:32::PRECRQ.PH.W
"precrq.ph.w r, r, r<rt>"
*dsp:
{
do_w_ph_precrq (SD_, RD, RS, RT);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,10101,010001:SPECIAL3:32::PRECRQ_RS.PH.W
"precrq_rs.ph.w r, r, r<rt>"
*dsp:
{
do_w_ph_rs_precrq (SD_, RD, RS, RT);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,01111,010001:SPECIAL3:32::PRECRQU_S.QB.PH
"precrqu_s.qb.ph r, r, r<rt>"
*dsp:
{
do_ph_qb_precrq (SD_, RD, RS, RT, 1);
}</rt></p>
<p dir="auto">011111,00000,5.RT,5.RD,01100,010010:SPECIAL3:32::PRECEQ.W.PHL
"preceq.w.phl r, r<rt>"
*dsp:
{
do_w_preceq (SD_, RD, RT, 0);
}</rt></p>
<p dir="auto">011111,00000,5.RT,5.RD,01101,010010:SPECIAL3:32::PRECEQ.W.PHR
"preceq.w.phr r, r<rt>"
*dsp:
{
do_w_preceq (SD_, RD, RT, 1);
}</rt></p>
<p dir="auto">011111,00000,5.RT,5.RD,00100,010010:SPECIAL3:32::PRECEQU.PH.QBL
"precequ.ph.qbl r, r<rt>"
*dsp:
{
do_qb_ph_precequ (SD_, RD, RT, 2);
}</rt></p>
<p dir="auto">011111,00000,5.RT,5.RD,00101,010010:SPECIAL3:32::PRECEQU.PH.QBR
"precequ.ph.qbr r, r<rt>"
*dsp:
{
do_qb_ph_precequ (SD_, RD, RT, 0);
}</rt></p>
<p dir="auto">011111,00000,5.RT,5.RD,00110,010010:SPECIAL3:32::PRECEQU.PH.QBLA
"precequ.ph.qbla r, r<rt>"
*dsp:
{
do_qb_ph_precequ (SD_, RD, RT, 3);
}</rt></p>
<p dir="auto">011111,00000,5.RT,5.RD,00111,010010:SPECIAL3:32::PRECEQU.PH.QBRA
"precequ.ph.qbra r, r<rt>"
*dsp:
{
do_qb_ph_precequ (SD_, RD, RT, 1);
}</rt></p>
<p dir="auto">011111,00000,5.RT,5.RD,11100,010010:SPECIAL3:32::PRECEU.PH.QBL
"preceu.ph.qbl r, r<rt>"
*dsp:
{
do_qb_ph_preceu (SD_, RD, RT, 2);
}</rt></p>
<p dir="auto">011111,00000,5.RT,5.RD,11101,010010:SPECIAL3:32::PRECEU.PH.QBR
"preceu.ph.qbr r, r<rt>"
*dsp:
{
do_qb_ph_preceu (SD_, RD, RT, 0);
}</rt></p>
<p dir="auto">011111,00000,5.RT,5.RD,11110,010010:SPECIAL3:32::PRECEU.PH.QBLA
"preceu.ph.qbla r, r<rt>"
*dsp:
{
do_qb_ph_preceu (SD_, RD, RT, 3);
}</rt></p>
<p dir="auto">011111,00000,5.RT,5.RD,11111,010010:SPECIAL3:32::PRECEU.PH.QBRA
"preceu.ph.qbra r, r<rt>"
*dsp:
{
do_qb_ph_preceu (SD_, RD, RT, 1);
}</rt></p>
<p dir="auto">011111,00,3.SHIFT3,5.RT,5.RD,00000,010011:SPECIAL3:32::SHLL.QB
"shll.qb r, r<rt>, "
*dsp:
{
do_qb_shift (SD_, RD, RT, SHIFT3, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,00010,010011:SPECIAL3:32::SHLLV.QB
"shllv.qb r, r<rt>, r"
*dsp:
{
do_qb_shl (SD_, RD, RT, RS, 0);
}</rt></p>
<p dir="auto">011111,0,4.SHIFT4,5.RT,5.RD,01000,010011:SPECIAL3:32::SHLL.PH
"shll.ph r, r<rt>, "
*dsp:
{
do_ph_shift (SD_, RD, RT, SHIFT4, 0, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,01010,010011:SPECIAL3:32::SHLLV.PH
"shllv.ph r, r<rt>, r"
*dsp:
{
do_ph_shl (SD_, RD, RT, RS, 0, 0);
}</rt></p>
<p dir="auto">011111,0,4.SHIFT4,5.RT,5.RD,01100,010011:SPECIAL3:32::SHLL_S.PH
"shll_s.ph r, r<rt>, "
*dsp:
{
do_ph_shift (SD_, RD, RT, SHIFT4, 0, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,01110,010011:SPECIAL3:32::SHLLV_S.PH
"shllv_s.ph r, r<rt>, r"
*dsp:
{
do_ph_shl (SD_, RD, RT, RS, 0, 1);
}</rt></p>
<p dir="auto">011111,5.SHIFT5,5.RT,5.RD,10100,010011:SPECIAL3:32::SHLL_S.W
"shll_s.w r, r<rt>, "
*dsp:
{
do_w_shll (SD_, RD, RT, SHIFT5);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,10110,010011:SPECIAL3:32::SHLLV_S.W
"shllv_s.w r, r<rt>, r"
*dsp:
{
do_w_s_shllv (SD_, RD, RT, RS);
}</rt></p>
<p dir="auto">011111,00,3.SHIFT3,5.RT,5.RD,00001,010011:SPECIAL3:32::SHRL.QB
"shrl.qb r, r<rt>, "
*dsp:
{
do_qb_shift (SD_, RD, RT, SHIFT3, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,00011,010011:SPECIAL3:32::SHRLV.QB
"shrlv.qb r, r<rt>, r"
*dsp:
{
do_qb_shl (SD_, RD, RT, RS, 1);
}</rt></p>
<p dir="auto">011111,0,4.SHIFT4,5.RT,5.RD,01001,010011:SPECIAL3:32::SHRA.PH
"shra.ph r, r<rt>, "
*dsp:
{
do_ph_shift (SD_, RD, RT, SHIFT4, 1, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,01011,010011:SPECIAL3:32::SHRAV.PH
"shrav.ph r, r<rt>, r"
*dsp:
{
do_ph_shl (SD_, RD, RT, RS, 1, 0);
}</rt></p>
<p dir="auto">011111,0,4.SHIFT4,5.RT,5.RD,01101,010011:SPECIAL3:32::SHRA_R.PH
"shra_r.ph r, r<rt>, "
*dsp:
{
do_ph_shift (SD_, RD, RT, SHIFT4, 1, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,01111,010011:SPECIAL3:32::SHRAV_R.PH
"shrav_r.ph r, r<rt>, r"
*dsp:
{
do_ph_shl (SD_, RD, RT, RS, 1, 1);
}</rt></p>
<p dir="auto">011111,5.SHIFT5,5.RT,5.RD,10101,010011:SPECIAL3:32::SHRA_R.W
"shra_r.w r, r<rt>, "
*dsp:
{
do_w_shra (SD_, RD, RT, SHIFT5);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,10111,010011:SPECIAL3:32::SHRAV_R.W
"shrav_r.w r, r<rt>, r"
*dsp:
{
do_w_r_shrav (SD_, RD, RT, RS);
}</rt></p>
<p dir="auto">// loc: 0 = qhl, 1 = qhr
:function:::void:do_qb_muleu:int rd, int rs, int rt, int loc
{
int i;
unsigned32 result = 0;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned16 h1, h2;
unsigned32 prod;
if (loc == 0)
v1 &gt;&gt;= 16;
for (i = 0; i &lt; 32; i += 16, v1 &gt;&gt;= 8, v2 &gt;&gt;= 16)
{
h1 = (unsigned16)(v1 &amp; 0xff);
h2 = (unsigned16)(v2 &amp; 0xffff);
prod = (unsigned32)h1 * (unsigned32)h2;
if (prod &gt; 0xffff)
{
DSPCR |= DSPCR_OUFLAG5;
prod = 0xffff;
}
result |= ((unsigned32)prod &lt;&lt; i);
}
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">011111,5.RS,5.RT,5.RD,00110,010000:SPECIAL3:32::MULEU_S.PH.QBL
"muleu_s.ph.qbl r, r, r<rt>"
*dsp:
{
do_qb_muleu (SD_, RD, RS, RT, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,00111,010000:SPECIAL3:32::MULEU_S.PH.QBR
"muleu_s.ph.qbr r, r, r<rt>"
*dsp:
{
do_qb_muleu (SD_, RD, RS, RT, 1);
}</rt></p>
<p dir="auto">// round: 0 = no rounding, 1 = rounding
:function:::void:do_ph_mulq:int rd, int rs, int rt, int round
{
int i;
unsigned32 result = 0;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
signed16 h1, h2;
signed32 prod;
for (i = 0; i &lt; 32; i += 16, v1 &gt;&gt;= 16, v2 &gt;&gt;= 16)
{
h1 = (signed16)(v1 &amp; 0xffff);
h2 = (signed16)(v2 &amp; 0xffff);
if (h1 == (signed16)0x8000 &amp;&amp; h2 == (signed16)0x8000)
{
DSPCR |= DSPCR_OUFLAG5;
prod = 0x7fffffff;
}
else
{
prod = ((signed32)h1 * (signed32)h2) &lt;&lt; 1;
if (round == 1)
prod += (signed32)0x8000;
}
result |= (((unsigned32)prod &gt;&gt; 16) &lt;&lt; i);
}
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">011111,5.RS,5.RT,5.RD,11111,010000:SPECIAL3:32::MULQ_RS.PH
"mulq_rs.ph r, r, r<rt>"
*dsp:
{
do_ph_mulq (SD_, RD, RS, RT, 1);
}</rt></p>
<p dir="auto">// loc: 0 = phl, 1 = phr
:function:::void:do_ph_muleq:int rd, int rs, int rt, int loc
{
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
signed16 h1, h2;
signed32 prod;
if (loc == 0)
{
h1 = (signed16)(v1 &gt;&gt; 16);
h2 = (signed16)(v2 &gt;&gt; 16);
}
else
{
h1 = (signed16)(v1 &amp; 0xffff);
h2 = (signed16)(v2 &amp; 0xffff);
}
if (h1 == (signed16)0x8000 &amp;&amp; h2 == (signed16)0x8000)
{
DSPCR |= DSPCR_OUFLAG5;
prod = 0x7fffffff;
}
else
prod = ((signed32)h1 * (signed32)h2) &lt;&lt; 1;
GPR[rd] = EXTEND32 (prod);
}</p>
<p dir="auto">011111,5.RS,5.RT,5.RD,11100,010000:SPECIAL3:32::MULEQ_S.W.PHL
"muleq_s.w.phl r, r, r<rt>"
*dsp:
{
do_ph_muleq (SD_, RD, RS, RT, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,11101,010000:SPECIAL3:32::MULEQ_S.W.PHR
"muleq_s.w.phr r, r, r<rt>"
*dsp:
{
do_ph_muleq (SD_, RD, RS, RT, 1);
}</rt></p>
<p dir="auto">// op: 0 = DPAU 1 = DPSU
// loc: 0 = qbl, 1 = qbr
:function:::void:do_qb_dot_product:int ac, int rs, int rt, int op, int loc
{
int i;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned8 h1, h2;
unsigned32 lo = DSPLO(ac);
unsigned32 hi = DSPHI(ac);
unsigned64 prod = (((unsigned64)hi) &lt;&lt; 32) + (unsigned64)lo;
if (loc == 0)
{
v1 &gt;&gt;= 16;
v2 &gt;&gt;= 16;
}
for (i = 0; i &lt; 16; i += 8, v1 &gt;&gt;= 8, v2 &gt;&gt;= 8)
{
h1 = (unsigned8)(v1 &amp; 0xff);
h2 = (unsigned8)(v2 &amp; 0xff);
if (op == 0) // DPAU
prod += (unsigned64)h1 * (unsigned64)h2;
else // DPSU
prod -= (unsigned64)h1 * (unsigned64)h2;
}
DSPLO(ac) = EXTEND32 (prod);
DSPHI(ac) = EXTEND32 (prod &gt;&gt; 32);
}</p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,00011,110000:SPECIAL3:32::DPAU.H.QBL
"dpau.h.qbl ac, r, r<rt>"
*dsp:
{
do_qb_dot_product (SD_, AC, RS, RT, 0, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,00111,110000:SPECIAL3:32::DPAU.H.QBR
"dpau.h.qbr ac, r, r<rt>"
*dsp:
{
do_qb_dot_product (SD_, AC, RS, RT, 0, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,01011,110000:SPECIAL3:32::DPSU.H.QBL
"dpsu.h.qbl ac, r, r<rt>"
*dsp:
{
do_qb_dot_product (SD_, AC, RS, RT, 1, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,01111,110000:SPECIAL3:32::DPSU.H.QBR
"dpsu.h.qbr ac, r, r<rt>"
*dsp:
{
do_qb_dot_product (SD_, AC, RS, RT, 1, 1);
}</rt></p>
<p dir="auto">// op: 0 = DPAQ 1 = DPSQ
:function:::void:do_ph_dot_product:int ac, int rs, int rt, int op
{
int i;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
signed16 h1, h2;
signed32 result;
unsigned32 lo = DSPLO(ac);
unsigned32 hi = DSPHI(ac);
signed64 prod = (signed64)((((unsigned64)hi) &lt;&lt; 32) + (unsigned64)lo);
for (i = 0; i &lt; 32; i += 16, v1 &gt;&gt;= 16, v2 &gt;&gt;= 16)
{
h1 = (signed16)(v1 &amp; 0xffff);
h2 = (signed16)(v2 &amp; 0xffff);
if (h1 == (signed16)0x8000 &amp;&amp; h2 == (signed16)0x8000)
{
DSPCR |= (1 &lt;&lt; (DSPCR_OUFLAG_SHIFT + ac));
result = (signed32)0x7fffffff;
}
else
result = ((signed32)h1 * (signed32)h2) &lt;&lt; 1;</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="  if (op == 0) // DPAQ
prod += (signed64)result;
  else // DPSQ
prod -= (signed64)result;
}"><pre class="notranslate"><code>  if (op == 0) // DPAQ
prod += (signed64)result;
  else // DPSQ
prod -= (signed64)result;
}
</code></pre></div>
<p dir="auto">DSPLO(ac) = EXTEND32 (prod);
DSPHI(ac) = EXTEND32 (prod &gt;&gt; 32);
}</p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,00100,110000:SPECIAL3:32::DPAQ_S.W.PH
"dpaq_s.w.ph ac, r, r<rt>"
*dsp:
{
do_ph_dot_product (SD_, AC, RS, RT, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,00101,110000:SPECIAL3:32::DPSQ_S.W.PH
"dpsq_s.w.ph ac, r, r<rt>"
*dsp:
{
do_ph_dot_product (SD_, AC, RS, RT, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,00110,110000:SPECIAL3:32::MULSAQ_S.W.PH
"mulsaq_s.w.ph ac, r, r<rt>"
*dsp:
{
do_mulsaq_s_w_ph (SD_, AC, RS, RT);
}</rt></p>
<p dir="auto">// op: 0 = DPAQ 1 = DPSQ
:function:::void:do_w_dot_product:int ac, int rs, int rt, int op
{
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
signed32 h1, h2;
signed64 result;
unsigned32 lo = DSPLO(ac);
unsigned32 hi = DSPHI(ac);
unsigned32 resultlo;
unsigned32 resulthi;
unsigned32 carry;
unsigned64 temp1;
signed64 temp2;
h1 = (signed32) v1;
h2 = (signed32) v2;
if (h1 == 0x80000000 &amp;&amp; h2 == 0x80000000)
{
DSPCR |= (1 &lt;&lt; (DSPCR_OUFLAG_SHIFT + ac));
result = (signed64) 0x7fffffffffffffffLL;
}
else
result = ((signed64)h1 * (signed64)h2) &lt;&lt; 1;
resultlo = (unsigned32)(result);
resulthi = (unsigned32)(result &gt;&gt; 32);
if (op ==0) // DPAQ
{
temp1 = (unsigned64)lo + (unsigned64)resultlo;
carry = (unsigned32)((temp1 &gt;&gt; 32) &amp; 1);
temp2 = (signed64)((signed32)hi) + (signed64)((signed32)resulthi) +
(signed64)((signed32)carry);
}
else // DPSQ
{
temp1 = (unsigned64)lo - (unsigned64)resultlo;
carry = (unsigned32)((temp1 &gt;&gt; 32) &amp; 1);
temp2 = (signed64)((signed32)hi) - (signed64)((signed32)resulthi) -
(signed64)((signed32)carry);
}
if (((temp2 &amp; 0x100000000LL) &gt;&gt; 1) != (temp2 &amp; 0x80000000LL))
{
DSPCR |= (1 &lt;&lt; (DSPCR_OUFLAG_SHIFT + ac));
if (temp2 &amp; 0x100000000LL)
{
DSPLO(ac) = EXTEND32 (0x00000000);
DSPHI(ac) = EXTEND32 (0x80000000);
}
else
{
DSPLO(ac) = EXTEND32 (0xffffffff);
DSPHI(ac) = EXTEND32 (0x7fffffff);
}
}
else
{
DSPLO(ac) = EXTEND32 (temp1);
DSPHI(ac) = EXTEND32 (temp2);
}
}</p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,01100,110000:SPECIAL3:32::DPAQ_SA.L.W
"dpaq_sa.l.w ac, r, r<rt>"
*dsp:
{
do_w_dot_product (SD_, AC, RS, RT, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,01101,110000:SPECIAL3:32::DPSQ_SA.L.W
"dpsq_sa.l.w ac, r, r<rt>"
*dsp:
{
do_w_dot_product (SD_, AC, RS, RT, 1);
}</rt></p>
<p dir="auto">// op: 0 = MAQ_S 1 = MAQ_SA
// loc: 0 = phl, 1 = phr
:function:::void:do_ph_maq:int ac, int rs, int rt, int op, int loc
{
int i;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
signed16 h1, h2;
signed32 result;
unsigned32 lo = DSPLO(ac);
unsigned32 hi = DSPHI(ac);
signed64 prod = (signed64)((((unsigned64)hi) &lt;&lt; 32) + (unsigned64)lo);
if (loc == 0)
{
h1 = (signed16)(v1 &gt;&gt; 16);
h2 = (signed16)(v2 &gt;&gt; 16);
}
else
{
h1 = (signed16)(v1 &amp; 0xffff);
h2 = (signed16)(v2 &amp; 0xffff);
}
if (h1 == (signed16)0x8000 &amp;&amp; h2 == (signed16)0x8000)
{
DSPCR |= (1 &lt;&lt; (DSPCR_OUFLAG_SHIFT + ac));
result = (signed32)0x7fffffff;
}
else
result = ((signed32)h1 * (signed32)h2) &lt;&lt; 1;
prod += (signed64)result;
if (op == 1) // MAQ_SA
{
if (prod &amp; 0x8000000000000000LL)
{
for (i = 62; i &gt;= 31; i--)
{
if (!(prod &amp; ((signed64)1 &lt;&lt; i)))
{
DSPCR |= (1 &lt;&lt; (DSPCR_OUFLAG_SHIFT + ac));
prod = 0xffffffff80000000LL;
break;
}
}
}
else
{
for (i = 62; i &gt;= 31; i--)
{
if (prod &amp; ((signed64)1 &lt;&lt; i))
{
DSPCR |= (1 &lt;&lt; (DSPCR_OUFLAG_SHIFT + ac));
prod = 0x7fffffff;
break;
}
}
}
}
DSPLO(ac) = EXTEND32 (prod);
DSPHI(ac) = EXTEND32 (prod &gt;&gt; 32);
}</p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,10100,110000:SPECIAL3:32::MAQ_S.W.PHL
"maq_s.w.phl ac, r, r<rt>"
*dsp:
{
do_ph_maq (SD_, AC, RS, RT, 0, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,10110,110000:SPECIAL3:32::MAQ_S.W.PHR
"maq_s.w.phr ac, r, r<rt>"
*dsp:
{
do_ph_maq (SD_, AC, RS, RT, 0, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,10000,110000:SPECIAL3:32::MAQ_SA.W.PHL
"maq_sa.w.phl ac, r, r<rt>"
*dsp:
{
do_ph_maq (SD_, AC, RS, RT, 1, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,10010,110000:SPECIAL3:32::MAQ_SA.W.PHR
"maq_sa.w.phr ac, r, r<rt>"
*dsp:
{
do_ph_maq (SD_, AC, RS, RT, 1, 1);
}</rt></p>
<p dir="auto">011111,00000,5.RT,5.RD,11011,010010:SPECIAL3:32::BITREV
"bitrev r, r<rt>"
*dsp:
{
do_bitrev (SD_, RD, RT);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,00000,00000,001100:SPECIAL3:32::INSV
"insv r<rt>, r"
*dsp:
{
do_insv (SD_, RT, RS);
}</rt></p>
<p dir="auto">011111,00,8.IMM8,5.RD,00010,010010:SPECIAL3:32::REPL.QB
"repl.qb r, "
*dsp:
{
do_repl (SD_, RD, IMM8, 0);
}</p>
<p dir="auto">011111,00000,5.RT,5.RD,00011,010010:SPECIAL3:32::REPLV.QB
"replv.qb r, r<rt>"
*dsp:
{
do_repl (SD_, RD, RT, 1);
}</rt></p>
<p dir="auto">011111,10.IMM10,5.RD,01010,010010:SPECIAL3:32::REPL.PH
"repl.ph r, "
*dsp:
{
do_repl (SD_, RD, IMM10, 2);
}</p>
<p dir="auto">011111,00000,5.RT,5.RD,01011,010010:SPECIAL3:32::REPLV.PH
"replv.ph r, r<rt>"
*dsp:
{
do_repl (SD_, RD, RT, 3);
}</rt></p>
<p dir="auto">// op: 0 = EQ, 1 = LT, 2 = LE
:function:::void:do_qb_cmpu:int rs, int rt, int op
{
int i, j;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned8 h1, h2;
unsigned32 mask;
for (i = 0, j = 0; i &lt; 32; i += 8, j++, v1 &gt;&gt;= 8, v2 &gt;&gt;= 8)
{
h1 = (unsigned8)(v1 &amp; 0xff);
h2 = (unsigned8)(v2 &amp; 0xff);
mask = ~(1 &lt;&lt; (DSPCR_CCOND_SHIFT + j));
DSPCR &amp;= mask;
if (op == 0) // EQ
DSPCR |= ((h1 == h2) &lt;&lt; (DSPCR_CCOND_SHIFT + j));
else if (op == 1) // LT
DSPCR |= ((h1 &lt; h2) &lt;&lt; (DSPCR_CCOND_SHIFT + j));
else // LE
DSPCR |= ((h1 &lt;= h2) &lt;&lt; (DSPCR_CCOND_SHIFT + j));
}
}</p>
<p dir="auto">011111,5.RS,5.RT,00000,00000,010001:SPECIAL3:32::CMPU.EQ.QB
"cmpu.eq.qb r, r<rt>"
*dsp:
{
do_qb_cmpu (SD_, RS, RT, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,00000,00001,010001:SPECIAL3:32::CMPU.LT.QB
"cmpu.lt.qb r, r<rt>"
*dsp:
{
do_qb_cmpu (SD_, RS, RT, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,00000,00010,010001:SPECIAL3:32::CMPU.LE.QB
"cmpu.le.qb r, r<rt>"
*dsp:
{
do_qb_cmpu (SD_, RS, RT, 2);
}</rt></p>
<p dir="auto">// op: 0 = EQ, 1 = LT, 2 = LE
:function:::void:do_qb_cmpgu:int rd, int rs, int rt, int op
{
int i, j;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
unsigned8 h1, h2;
unsigned32 result = 0;
for (i = 0, j = 0; i &lt; 32; i += 8, j++, v1 &gt;&gt;= 8, v2 &gt;&gt;= 8)
{
h1 = (unsigned8)(v1 &amp; 0xff);
h2 = (unsigned8)(v2 &amp; 0xff);
if (op == 0) // EQ
result |= ((h1 == h2) &lt;&lt; j);
else if (op == 1) // LT
result |= ((h1 &lt; h2) &lt;&lt; j);
else // LE
result |= ((h1 &lt;= h2) &lt;&lt; j);
}
GPR[rd] = EXTEND32 (result);
}</p>
<p dir="auto">011111,5.RS,5.RT,5.RD,00100,010001:SPECIAL3:32::CMPGU.EQ.QB
"cmpgu.eq.qb r, r, r<rt>"
*dsp:
{
do_qb_cmpgu (SD_, RD, RS, RT, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,00101,010001:SPECIAL3:32::CMPGU.LT.QB
"cmpgu.lt.qb r, r, r<rt>"
*dsp:
{
do_qb_cmpgu (SD_, RD, RS, RT, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,00110,010001:SPECIAL3:32::CMPGU.LE.QB
"cmpgu.le.qb r, r, r<rt>"
*dsp:
{
do_qb_cmpgu (SD_, RD, RS, RT, 2);
}</rt></p>
<p dir="auto">// op: 0 = EQ, 1 = LT, 2 = LE
:function:::void:do_ph_cmpu:int rs, int rt, int op
{
int i, j;
unsigned32 v1 = GPR[rs];
unsigned32 v2 = GPR[rt];
signed16 h1, h2;
unsigned32 mask;
for (i = 0, j = 0; i &lt; 32; i += 16, j++, v1 &gt;&gt;= 16, v2 &gt;&gt;= 16)
{
h1 = (signed16)(v1 &amp; 0xffff);
h2 = (signed16)(v2 &amp; 0xffff);
mask = ~(1 &lt;&lt; (DSPCR_CCOND_SHIFT + j));
DSPCR &amp;= mask;
if (op == 0) // EQ
DSPCR |= ((h1 == h2) &lt;&lt; (DSPCR_CCOND_SHIFT + j));
else if (op == 1) // LT
DSPCR |= ((h1 &lt; h2) &lt;&lt; (DSPCR_CCOND_SHIFT + j));
else // LE
DSPCR |= ((h1 &lt;= h2) &lt;&lt; (DSPCR_CCOND_SHIFT + j));
}
}</p>
<p dir="auto">011111,5.RS,5.RT,00000,01000,010001:SPECIAL3:32::CMP.EQ.PH
"cmp.eq.ph r, r<rt>"
*dsp:
{
do_ph_cmpu (SD_, RS, RT, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,00000,01001,010001:SPECIAL3:32::CMP.LT.PH
"cmp.lt.ph r, r<rt>"
*dsp:
{
do_ph_cmpu (SD_, RS, RT, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,00000,01010,010001:SPECIAL3:32::CMP.LE.PH
"cmp.le.ph r, r<rt>"
*dsp:
{
do_ph_cmpu (SD_, RS, RT, 2);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,00011,010001:SPECIAL3:32::PICK.QB
"pick.qb r, r, r<rt>"
*dsp:
{
do_qb_pick (SD_, RD, RS, RT);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,01011,010001:SPECIAL3:32::PICK.PH
"pick.ph r, r, r<rt>"
*dsp:
{
do_ph_pick (SD_, RD, RS, RT);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,5.RD,01110,010001:SPECIAL3:32::PACKRL.PH
"packrl.ph r, r, r<rt>"
*dsp:
{
do_ph_packrl (SD_, RD, RS, RT);
}</rt></p>
<p dir="auto">// op: 0 = EXTR, 1 = EXTR_R, 2 = EXTR_RS
:function:::void:do_w_extr:int rt, int ac, int shift, int op
{
int i;
unsigned32 lo = DSPLO(ac);
unsigned32 hi = DSPHI(ac);
unsigned64 prod = (((unsigned64)hi) &lt;&lt; 32) + (unsigned64)lo;
signed64 result = (signed64)prod;
int setcond = 0;
if (!(prod &amp; 0x8000000000000000LL))
{
for (i = 62; i &gt;= (shift + 31); i--)
{
if (prod &amp; ((unsigned64)1 &lt;&lt; i))
{
DSPCR |= DSPCR_OUFLAG7;
setcond = 1;
break;
}
}
if (((prod &gt;&gt; (shift - 1)) &amp; 0xffffffffLL) == 0xffffffffLL)
{
DSPCR |= DSPCR_OUFLAG7;
setcond = 1;
}
}
else
{
for (i = 62; i &gt;= (shift + 31); i--)
{
if (!(prod &amp; ((unsigned64)1 &lt;&lt; i)))
{
DSPCR |= DSPCR_OUFLAG7;
setcond = 2;
break;
}
}
}
if (op == 0) // EXTR
result = result &gt;&gt; shift;
else if (op == 1) // EXTR_R
{
if (shift != 0)
result = ((result &gt;&gt; (shift - 1)) + 1) &gt;&gt; 1;
else
result = result &gt;&gt; shift;
}
else // EXTR_RS
{
if (setcond == 1)
result = 0x7fffffff;
else if (setcond == 2)
result = 0x80000000;
else
{
if (shift != 0)
result = ((result &gt;&gt; (shift - 1)) + 1) &gt;&gt; 1;
else
result = result &gt;&gt; shift;
}
}
GPR[rt] = EXTEND32 (result);
}</p>
<p dir="auto">011111,5.SHIFT,5.RT,000,2.AC,00000,111000:SPECIAL3:32::EXTR.W
"extr.w r<rt>, ac, "
*dsp:
{
do_w_extr (SD_, RT, AC, SHIFT, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,00001,111000:SPECIAL3:32::EXTRV.W
"extrv.w r<rt>, ac, r"
*dsp:
{
do_extrv (SD_, RT, AC, RS, 0);
}</rt></p>
<p dir="auto">011111,5.SHIFT,5.RT,000,2.AC,00100,111000:SPECIAL3:32::EXTR_R.W
"extr_r.w r<rt>, ac, "
*dsp:
{
do_w_extr (SD_, RT, AC, SHIFT, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,00101,111000:SPECIAL3:32::EXTRV_R.W
"extrv_r.w r<rt>, ac, r"
*dsp:
{
do_extrv (SD_, RT, AC, RS, 1);
}</rt></p>
<p dir="auto">011111,5.SHIFT,5.RT,000,2.AC,00110,111000:SPECIAL3:32::EXTR_RS.W
"extr_rs.w r<rt>, ac, "
*dsp:
{
do_w_extr (SD_, RT, AC, SHIFT, 2);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,00111,111000:SPECIAL3:32::EXTRV_RS.W
"extrv_rs.w r<rt>, ac, r"
*dsp:
{
do_extrv (SD_, RT, AC, RS, 2);
}</rt></p>
<p dir="auto">:function:::void:do_h_extr:int rt, int ac, int shift
{
int i;
unsigned32 lo = DSPLO(ac);
unsigned32 hi = DSPHI(ac);
unsigned64 prod = (((unsigned64)hi) &lt;&lt; 32) + (unsigned64)lo;
signed64 result = (signed64)prod;
signed64 value = 0xffffffffffff8000LL;
result &gt;&gt;= shift;
if (result &gt; 0x7fff)
{
result = 0x7fff;
DSPCR |= DSPCR_OUFLAG7;
}
else if (result &lt; value)
{
result = value;
DSPCR |= DSPCR_OUFLAG7;
}
GPR[rt] = EXTEND32 (result);
}</p>
<p dir="auto">011111,5.SHIFT,5.RT,000,2.AC,01110,111000:SPECIAL3:32::EXTR_S.H
"extr_s.h r<rt>, ac, "
*dsp:
{
do_h_extr (SD_, RT, AC, SHIFT);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,01111,111000:SPECIAL3:32::EXTRV_S.H
"extrv_s.h r<rt>, ac, r"
*dsp:
{
do_extrv_s_h (SD_, RT, AC, RS);
}</rt></p>
<p dir="auto">// op: 0 = EXTP, 1 = EXTPDP
:function:::void:do_extp:int rt, int ac, int size, int op
{
signed32 pos = (DSPCR &gt;&gt; DSPCR_POS_SHIFT) &amp; DSPCR_POS_MASK;
unsigned32 lo = DSPLO(ac);
unsigned32 hi = DSPHI(ac);
unsigned64 prod = (((unsigned64)hi) &lt;&lt; 32) + (unsigned64)lo;
unsigned64 result = 0;
if (pos - (size + 1) &gt;= -1)
{
prod &gt;&gt;= (pos - size);
result = prod &amp; (((unsigned64)1 &lt;&lt; (size + 1)) - 1);
DSPCR &amp;= (~DSPCR_EFI_SMASK);
if (op == 1) // EXTPDP
{
if (pos - (size + 1) &gt;= 0)
{
DSPCR &amp;= (~DSPCR_POS_SMASK);
DSPCR |= ((pos - (size + 1)) &amp; DSPCR_POS_MASK) &lt;&lt; DSPCR_POS_SHIFT;
}
else if (pos - (size + 1) == -1)
{
DSPCR |= DSPCR_POS_SMASK;
}
}
}
else
{
DSPCR |= DSPCR_EFI;
Unpredictable ();
}
GPR[rt] = EXTEND32 (result);
}</p>
<p dir="auto">011111,5.SIZE,5.RT,000,2.AC,00010,111000:SPECIAL3:32::EXTP
"extp r<rt>, ac, "
*dsp:
{
do_extp (SD_, RT, AC, SIZE, 0);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,00011,111000:SPECIAL3:32::EXTPV
"extpv r<rt>, ac, r"
*dsp:
{
do_extpv (SD_, RT, AC, RS, 0);
}</rt></p>
<p dir="auto">011111,5.SIZE,5.RT,000,2.AC,01010,111000:SPECIAL3:32::EXTPDP
"extpdp r<rt>, ac, "
*dsp:
{
do_extp (SD_, RT, AC, SIZE, 1);
}</rt></p>
<p dir="auto">011111,5.RS,5.RT,000,2.AC,01011,111000:SPECIAL3:32::EXTPDPV
"extpdpv r<rt>, ac, r"
*dsp:
{
do_extpv (SD_, RT, AC, RS, 1);
}</rt></p>
<p dir="auto">:function:::void:do_shilo:int ac, int shift
{
unsigned32 lo = DSPLO(ac);
unsigned32 hi = DSPHI(ac);
unsigned64 prod = (((unsigned64)hi) &lt;&lt; 32) + (unsigned64)lo;
if (shift &gt; 31)
shift = shift - 64;
if (shift &gt;= 0)
prod &gt;&gt;= shift;
else
prod &lt;&lt;= (-shift);
DSPLO(ac) = EXTEND32 (prod);
DSPHI(ac) = EXTEND32 (prod &gt;&gt; 32);
}</p>
<p dir="auto">011111,6.SHIFT6,0000,000,2.AC,11010,111000:SPECIAL3:32::SHILO
"shilo ac, "
*dsp:
{
do_shilo (SD_, AC, SHIFT6);
}</p>
<p dir="auto">011111,5.RS,00000,000,2.AC,11011,111000:SPECIAL3:32::SHILOV
"shilov ac, r"
*dsp:
{
do_shilov (SD_, AC, RS);
}</p>
<p dir="auto">011111,5.RS,00000,000,2.AC,11111,111000:SPECIAL3:32::MTHLIP
"mthlip r, ac"
*dsp:
{
do_mthlip (SD_, RS, AC);
}</p>
<p dir="auto">011111,5.RS,10.MASK10,10011,111000:SPECIAL3:32::WRDSP
"wrdsp r":MASK10 == 1111111111
"wrdsp r, "
*dsp:
{
do_wrdsp (SD_, RS, MASK10);
}</p>
<p dir="auto">011111,10.MASK10,5.RD,10010,111000:SPECIAL3:32::RDDSP
"rddsp r":MASK10 == 1111111111
"rddsp r, "
*dsp:
{
do_rddsp (SD_, RD, MASK10);
}</p>
<p dir="auto">011111,5.BASE,5.INDEX,5.RD,00110,001010:SPECIAL3:32::LBUX
"lbux r, r(r)"
*dsp:
{
do_lxx (SD_, RD, BASE, INDEX, 0);
}</p>
<p dir="auto">011111,5.BASE,5.INDEX,5.RD,00100,001010:SPECIAL3:32::LHX
"lhx r, r(r)"
*dsp:
{
do_lxx (SD_, RD, BASE, INDEX, 1);
}</p>
<p dir="auto">011111,5.BASE,5.INDEX,5.RD,00000,001010:SPECIAL3:32::LWX
"lwx r, r(r)"
*dsp:
{
do_lxx (SD_, RD, BASE, INDEX, 2);
}</p>
<p dir="auto">000001,00000,11100,16.OFFSET:REGIMM:32::BPOSGE32
"bposge32 "
*dsp:
{
unsigned32 pos = (DSPCR &gt;&gt; DSPCR_POS_SHIFT) &amp; DSPCR_POS_MASK;
address_word offset = EXTEND16 (OFFSET) &lt;&lt; 2;
if (pos &gt;= 32)
{
DELAY_SLOT (NIA + offset);
}
}</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="69 Unkraine Huge Craine ꑭ  

69 UKraine SEND Huge Craine ꑭ  


69 UKraine EQUALS Huge Craine ꑭ   YES TRUE


ꑭ   YES TRUE HEmjwNQb0AAexHn!!!

ꑭ   YES TRUE look at this gwnch o'phallus!!!

ꑭ   YES TRUE GLAGOLI BOOK OF LIES HAS ENTERED THE FIGHT 🦂📷📷 🦂🦂

ꑭ   YES TRUE that's welsh for &quot;gwnch o'phallus, please watch your step, you almost blocked my shot, Bitch&quot;





ISO 9 KNAB 1995(1.0) 2003(2.0)

t‡u ţw u u
f f f‡ f̧
h x hu xw h′′ ḩ h′′u ḩw h′ h
c c cu cw c‡ ç
č ć č′′ č č‡ ç̌
š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś
′′ 
′′  finnaš š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś
′′  finna gloccš š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś
′′  ′′  finna o'gloccš š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś
′′  finna glocc in the rariš š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś
′′  glocc in the rariš š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś
′′  getai tribe g'irak in the rariš š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś
′′  nogai tribe actually big homo small pp tribeš š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś
y y
′ 
è e
û ju â ja ‡ x̧ ‡u x̧w
ALA-LC TITUS 1997(3.0) 2000(4.0)
tḣu ṭ°
u w,u f f
fḣ — kh x khu x° kh′′ χ kh′′u χ° kh′ ḥ
ts͡ c ts͡u c° ts͡ḣ c̣ ch čʹ ch′′ č chḣ č̣ sh š sh′′ ŝ sh′′u ŝ° shḣ ṣ̂ shḣu ŝ°̣ shch šʹ
′′ — y ǝ
′ — ė ă
iu͡ — ia͡ — ḣ ʾ ḣu ʾ°

 ન̢̨̛̛͙̼̱͈̺̳͓̅̀̍͛̚ી̢̖͖͙͉̗͖̅̾̏̐̐͟

3(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜ 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ

  🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂

   -k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂
🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂

   - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂
🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜ 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ

🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ

ł`જોહરીiorno!!! My name is łSO 9 KNAB 1995(1.0) エ🦂ミ~ 🍒2003(2.0) #エメラダ  #🦂🦂2003(2.0) #エメラダ #🦂#🦂🦂

 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜ 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    EMERELDA al GLAGOLI BOOK OF LIES HAS ENTERED THE FIGHT 🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂

🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ



🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ

3(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜ 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ


🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ


   -k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂
🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂




🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ

🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ





 iu͡ — ia͡ — ḣ  ન̢̨̛̛͙̼̱͈̺̳͓̅̀̍͛̚ી̢̖͖͙͉̗͖̅̾̏̐̐͟ʾ ḣu  ન̢̨̛̛͙̼̱͈̺̳͓̅̀̍͛̚ી̢̖͖͙͉̗͖̅̾̏̐̐͟ʾ°

′ — 39.13 ТӀтӀ રો'નгъу тоонт нютаг varzesh3


′ — 39.1314 ТӀтӀ રો'નгъу тоонт нютаг varzesh3 for big science


##  iu͡ — ia͡ — ḣ ʾ ḣu ʾ°
"><pre class="notranslate"><code>69 Unkraine Huge Craine ꑭ  

69 UKraine SEND Huge Craine ꑭ  


69 UKraine EQUALS Huge Craine ꑭ   YES TRUE


ꑭ   YES TRUE HEmjwNQb0AAexHn!!!

ꑭ   YES TRUE look at this gwnch o'phallus!!!

ꑭ   YES TRUE GLAGOLI BOOK OF LIES HAS ENTERED THE FIGHT 🦂📷📷 🦂🦂

ꑭ   YES TRUE that's welsh for "gwnch o'phallus, please watch your step, you almost blocked my shot, Bitch"





ISO 9 KNAB 1995(1.0) 2003(2.0)
[DOCUMENT CUTS OFF HERE, DOWNLOAD THE REPO FOR THE REST OF THE SPECIFICATION]


##  iu͡ — ia͡ — ḣ ʾ ḣu ʾ°

</code></pre></div>

<p dir="auto"><a target="_blank" rel="noopener noreferrer nofollow" href="https://camo.githubusercontent.com/89fbe3774e084ab069a95400806e851ad657740f740f62347800db950ca81034/68747470733a2f2f6769746875622d726561646d652d73746174732e76657263656c2e6170702f6170693f757365726e616d653d67726579646f75627426696e636c7564655f616c6c5f636f6d6d6974733d7472756526636f756e745f707269766174653d747275652673686f775f69636f6e733d74727565266c696e655f6865696768743d3230267469746c655f636f6c6f723d3242354242442669636f6e5f636f6c6f723d31313234424226746578745f636f6c6f723d4138413341372662675f636f6c6f723d302c3030303030302c313330463430"><img align="center" src="https://camo.githubusercontent.com/89fbe3774e084ab069a95400806e851ad657740f740f62347800db950ca81034/68747470733a2f2f6769746875622d726561646d652d73746174732e76657263656c2e6170702f6170693f757365726e616d653d67726579646f75627426696e636c7564655f616c6c5f636f6d6d6974733d7472756526636f756e745f707269766174653d747275652673686f775f69636f6e733d74727565266c696e655f6865696768743d3230267469746c655f636f6c6f723d3242354242442669636f6e5f636f6c6f723d31313234424226746578745f636f6c6f723d4138413341372662675f636f6c6f723d302c3030303030302c313330463430" alt="my Github Stats" data-canonical-src="https://github-readme-stats.vercel.app/api?username=greydoubt&amp;include_all_commits=true&amp;count_private=true&amp;show_icons=true&amp;line_height=20&amp;title_color=2B5BBD&amp;icon_color=1124BB&amp;text_color=A8A3A7&amp;bg_color=0,000000,130F40" style="max-width: 100%;"></a></p><p dir="auto"><a target="_blank" rel="noopener noreferrer nofollow" href="https://camo.githubusercontent.com/fc602388b95d3e49144e591da29e7949d1b40499e57a986ed643120fb631d9ea/68747470733a2f2f6769746875622d726561646d652d73746174732e76657263656c2e6170702f6170693f757365726e616d653d7361746f722d617265706f2d74656e65742d6f706572612d726f74617326696e636c7564655f616c6c5f636f6d6d6974733d7472756526636f756e745f707269766174653d747275652673686f775f69636f6e733d74727565266c696e655f6865696768743d3230267469746c655f636f6c6f723d3242354242442669636f6e5f636f6c6f723d31313234424226746578745f636f6c6f723d4138413341372662675f636f6c6f723d302c3030303030302c313330463430"><img align="center" src="https://camo.githubusercontent.com/fc602388b95d3e49144e591da29e7949d1b40499e57a986ed643120fb631d9ea/68747470733a2f2f6769746875622d726561646d652d73746174732e76657263656c2e6170702f6170693f757365726e616d653d7361746f722d617265706f2d74656e65742d6f706572612d726f74617326696e636c7564655f616c6c5f636f6d6d6974733d7472756526636f756e745f707269766174653d747275652673686f775f69636f6e733d74727565266c696e655f6865696768743d3230267469746c655f636f6c6f723d3242354242442669636f6e5f636f6c6f723d31313234424226746578745f636f6c6f723d4138413341372662675f636f6c6f723d302c3030303030302c313330463430" alt="my Github Stats" data-canonical-src="https://github-readme-stats.vercel.app/api?username=sator-arepo-tenet-opera-rotas&amp;include_all_commits=true&amp;count_private=true&amp;show_icons=true&amp;line_height=20&amp;title_color=2B5BBD&amp;icon_color=1124BB&amp;text_color=A8A3A7&amp;bg_color=0,000000,130F40" style="max-width: 100%;"></a></p>
<p dir="auto"><a href="https://git.io/streak-stats" rel="nofollow"><img src="https://camo.githubusercontent.com/0a0a54a846e9311872cc3188ed3c5096707de7e0cb1f9d29d93211ea0cc33fe1/687474703a2f2f6769746875622d726561646d652d73747265616b2d73746174732e6865726f6b756170702e636f6d3f757365723d7361746f722d617265706f2d74656e65742d6f706572612d726f746173267468656d653d6461726b266261636b67726f756e643d303030303030" alt="GitHub Streak" data-canonical-src="http://github-readme-streak-stats.herokuapp.com?user=sator-arepo-tenet-opera-rotas&amp;theme=dark&amp;background=000000" style="max-width: 100%;"></a><a href="https://git.io/streak-stats" rel="nofollow"><img src="https://camo.githubusercontent.com/682a173bd52c7ca62d06a56c3cc0404d159cc060059187c2c657d351152a7b1c/687474703a2f2f6769746875622d726561646d652d73747265616b2d73746174732e6865726f6b756170702e636f6d3f757365723d67726579646f756274267468656d653d6461726b266261636b67726f756e643d303030303030" alt="GitHub Streak" data-canonical-src="http://github-readme-streak-stats.herokuapp.com?user=greydoubt&amp;theme=dark&amp;background=000000" style="max-width: 100%;"></a></p>
<p dir="auto"><a href="https://github.com/anuraghazra/github-readme-stats"><img src="https://camo.githubusercontent.com/73d1f7d143fa7f80c2ccd4282f3182a842700024492b51391ce7319646cb69bb/68747470733a2f2f6769746875622d726561646d652d73746174732e76657263656c2e6170702f6170692f746f702d6c616e67732f3f757365726e616d653d67726579646f756274266c61796f75743d636f6d70616374267468656d653d766973696f6e2d667269656e646c792d6461726b" alt="Top Langs" data-canonical-src="https://github-readme-stats.vercel.app/api/top-langs/?username=greydoubt&amp;layout=compact&amp;theme=vision-friendly-dark" style="max-width: 100%;"></a><a href="https://github.com/anuraghazra/github-readme-stats"><img src="https://camo.githubusercontent.com/f6f45e4655c2480798e34003eb645bc56705026016b1c3ad47b1ed64c45ec310/68747470733a2f2f6769746875622d726561646d652d73746174732e76657263656c2e6170702f6170692f746f702d6c616e67732f3f757365726e616d653d7361746f722d617265706f2d74656e65742d6f706572612d726f746173266c61796f75743d636f6d70616374267468656d653d766973696f6e2d667269656e646c792d6461726b" alt="Top Langs" data-canonical-src="https://github-readme-stats.vercel.app/api/top-langs/?username=sator-arepo-tenet-opera-rotas&amp;layout=compact&amp;theme=vision-friendly-dark" style="max-width: 100%;"></a></p><p dir="auto"></p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="




https://github.com/user-attachments/assets/82cd4c1d-2ae2-429e-99a5-91ec794e4030



https://github.com/user-attachments/assets/73097654-130e-4bb4-a777-66b37a8b1cb8





Sikheya street'an cho'n mein kitaaban vichon parheya ni
सिखइया स्ट्रीट'ान को'ं में किताबां विचों पढ़ेया नि
Sikheya street'an cho'n mein kitaaban vichon parheya ni
Once upon a time, I learn't how to read books on the street corner

તિનકા ઔકાત સી પહરણ નાળ લરઘેએ ની
Tinka aukaat c paharaan naal lardhea ni
They called me the girl who cut the pharaoh, standing pallid over the fat of the land

કેહાન્દે આ શિખર જોહરી થા’ન ઉત્તે ખરેએ ની
Kehande aa sikhar jehri thaa’n utte kharea ni
Where is this peak, where is it not visible? There is always another mountain to climb

જો ખીચડિ આ લટતાં કેહાન્દે &quot;સાદે સીરો'ન ચડેએ ની&quot;
Jo khichde aa lattan kehande saade siro'n chadea ni
If the sour grapes die on the vine, it will be said, The Sweet Sadism of Shiva Nyxhades was her own demise

63 Ь ь 64 Э э̛̯̖̜͓̩̣̒̈́̉͋̆ Ꙗ̨̨̰̥̖̺͇͕̠͌̿͌̓̒͒͊́̀͡ Ꙑ̳̲̜̪̮̈́̾̊̂̓̄̿̓͑̏)̴̧̧̱̱͕́̃͌͛̏̒̏͘͟͢͠4̨̡̘̦͈͕̠͇̣͂̽̌͋͟͝ Ч̶̯̦͕͙̣̑̐̆̕͟͢͡͝Ӏ̻͓̣̳̓̊̐͋̇̏͟͞х̸̧̨̪̳̲̰͉̱̻͋̂̾̃͝͡у̡̝̖̭͍̟̟̘̫̀̐͐̈́͗̂̄͌͗̚͟̯̖̤̣̌̌̅͗̂̃̉͘͟ͅф̢̝̖͇͓̜̘̘̔̆̅̑́̽͒͘͜͠g̶̙͙̳̬͌͑͑͌̓͟ ɣ̡̡̹͉͙͖̱͙̇̉̄͒͗̍̂͐̿͠ ģ̡̢̥̦̞̬̀͊́̒̀̕͜ͅư͔͉̦͕̟̮̊̃̾̏̉ g̘͙̘̻͉̖̺̹̺̏̈́̃̌͗͘͜°̷̡̱͕͎͇̹̔͌̄̄̊ ģ̶̻̙̱̤̻̔̿̏̋̀͂̐͢ͅ′̵̢̢͈̰͉̺̆̒̊͊͞͠′̵̫̭͓̘̂̾̔̔͒̽̀͊͘͘͜ͅͅ ġ̨̛̯̯̣͕̫̘̼͋̍͂͆͢ g͇̗̣̥̜̙̝͓͋̓̔̀͊̒͑͗͘′̵̨̯̲̭͙̦̟͉̟̞̆̃̑͂͘͡′̧̬̺̪͍̟̼̏̽̾͛̏͐̿͜͡͡ŭ̶̙̭̥̟̥̭̘̟̺͛̊̿̅̎͗̇͝͡ ġ͚̳̘̖̬͉̌͆̀̄̐̄̌̉̐̒͜°̶̧̞̪͚̾̊͗͂͘͜ ḓ̵͖̦̹͍͊̆̓͒̑͂͗͛ d̡̧̙̪̻̮̗͎͂͌͆̓̓̊̍̅̓ d̷͖̼͓͕̮̽̇̇͌̕z̷͚̯̦͉̙̉̿̐̈́̂͌̑͢͞͝͠ḧ̨͙̯͍̣̲͎́̎̉͌͋̏͆̑̋̚͢ ǯ̷̨̣̰͈̲̮̈́̈́̈́̓̄̊̈́͡′̵̡̨̬͎̙͋̐̂̇̀͊͋͊̊͒ ḑ̷͚̙̰̋́͑̿̕͜͟z̴̧̬̰̙̹̪̬͎͗͋̈́̓͌̒̅̾͟ ʒ̸͈͙̱̙̹̎́̀̔̋̈́́͘͟ d̵̘̟̼͓̮̄͒̊̒̎́̑̒͌̚z̛̛̼͚̬̱͙͒̒̇̌̓́̒̚͜͢ͅư̶͇̞̤̻̫̓́͑͌̃̑͟ ʒ̴̧̨̧͖͖̼̫̙͗͗́̓͌͢͜°̬̥̰͎̰͌̑̈́̋̆͑͒͟͝͞h̸̢̜̞͎͓̯̉̌͑̉́͆͞ư̶̧̧̙̟̤̟͇͍̆̋̄̉̃̂͛͗̕ Є̸̠̮̺̣̗̭̭̥̘̀͆͋͟͡͠͝w̷̡̜̩͎̮͚̥̺͍̰͐̍͛̄̌͠͞ダ̶̲̮̜̪͍͖͓́͊̃̀̀͑̈͑̕͠h̳̼͉̘̙̉̍̎̀͊͗̕͞′̠͕͙͚́̓̉̅͜͠′̛̗͖͈͔̦̠͉͓̾̔̓͊͌ラ̶̡̛̻̫̼̞̥̃̀̇̓̇͛͋͝͡a̶̧̟̜̯͇̘͉̥͐̃̒̆̿̀̃̔͡͠z̷̘͙̟͔̙̘̽̀́̀͋͟ŭ̸̙̤̯͇̺̞̉́̿̅̊͂̽б̶̨͕̬͓̐̂̈̍̾̚͟͠͞о̛̬̯̻͙͖͓̗̥͂̏̎̾̿̿̌ͅу̡̥̮̰͍͖͒͂͐͋̋͊͢к̷̯͙̯̪̬͌̌̓̉̌̓̅̈͌ꙑ̶̡̨̥͚͎̭͌̓͋̓̏́́̑b̛̝̼̜͙̭͌͋̈̾̆́̇̏͢u̧̧͚̺̙̟̪̹͕͑͒́̀̌̋̎͝k͇̗̻̞̗̹̅̊̃̈́̅̄̂y̴̧̡̬̳͉̦̗̻̪̓͒̌͐̄̕͠г̢̟̥̯̜̭͎̮̤̅͛̄̿̿͊̚͝͞л̴͎͇͕̯͕̞͖̊̓̍̔͑́͠͝а̨̛̱̳͖̗̯̫͗́̄̓г̢͓̠͇͎̘̝͑̃̓̓̓͟͢͠ӧ̶̧̢͍̠̜̰̩̫̜͛̐̆̂͘л̧̪̩̺̯̭́̍̌͘͜͜͜͡͝ѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠ (̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ e̖͇̜̳̲͍̔̅̆̒̍̓͞ ê̷͔̻̜͔̄̑̉̏̌̑̒̈́̕͜͜ͅ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ —͉̯͓͌̿͆́͋̄͜͟͡ z̸̡̛͉͖̠̦̬̺̓̈́͛͒͜h̸͙̘̫̻̠͕̺̥̅̂̐̎̌̍̈́͂͘͝ ž̷̧̠̤̖̗͎͚̖͖̘̈́̂̿̾̊̾͠ z̵͙̜͚͚͍̤̖͓͎̆̇̀͛̌͋͋̕͠͠h̸̡̢̨͉̼͔̝̋̏̿͑̓͑͟ͅ′̡̡̟̬͍̿̀͋͗͆̿͘′̲̺̣̫̻̥̤̝̯̬͗͂̾̒̇̿̎̾دووپشک ẑ̛͚͚̼̳̠͖̋̒̊̀́ z̥̫̠̯͚̭͓̪̱̆́͗̈͛̄͜h̶̡̤̺͈͙̟͆̈́̇́̈́̀′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅu̸̼͔̰̯̖̐͆͗̏͐̾͡ͅ ẑ̷̛̲̭͉̪̜̯͌̍̅̿́͢͠ͅ°̵̺̹̫̹͙͇͆̉̋̎̇̿͂͟͞͝ z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ′͍̠̤͉͓̦̦̦̻́͒͐͌̆̀͡ͅ ž̴͚̳̞̙͙͖̙͈̏̅̾͋͊͋̈̋͗͢′̨̟͉͔͙̐̅̓̃̀̕͟͠ z̦̬̠̳̻̃͂͋̎́̔͢͢͝ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝ ḯ̻̖̮̦͕͊̇͋̂͂͜͝ĭ̙̟͕͈̪̝̤͎̓̅̀̔̎̊̀̐̅͂͢͜ j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆ k̵̡̬͔̬̩͇̤͐͊̅͆̃ͅ —̷̢̛̜̬͔̖̳͆̇̐̀̚͢͠ k̶̛̭̮̝̹̹̬͌̈́͋͜͟͞u̵̧̠̠͍͖͗́̆̉̄͘ k̸͎͈̣̦͌̂̏͋̊͒͢͡°̴̧̰̮̺̮̙̲̯̤̠̊̊̂̿̎̓͋ ķ̘͔̤̠̪̟̮͌̌͑̎̈̊̕′̳̱̞̥͕̥̀̄̽̏̂́̾͞′̴̧̱̖͉̗̾̏͆̾̍͆͌͞͠ͅ q̶̨̩̝̞͙͛̓̒͋͒ ķ̮̠͕̹̩̤̀̉̄̎̕͘̕͢′̨̧͖͇͈̳̣͆̑̑͂́͊͜͡′̥̳̥̦͈̫́̄́̍̔̽̑͞ứ̵͈͔̭͍͓̲͔͙͚́̆̊̏̚͠͡ q̵̢̛̼̥̭̪̼̆͋̂̑̅̚͠°͖̹̲̻̣͍̹͇́͋́̒̓͆͂̆͛͗ k̴̡̺̙͕͉̯̖̯͎͒̏̊͡͝ḣ̷̨̯̜̠̻̿͊͑̎̀͟ č̵̡̨̘͖̥͕͉̔̅̀̅͡͠′̵̸̡̡̛̳̹̰̰̲̣̲̞͕̝͇̟̩̀̀̍̈́̃̊̓̍̓̉̃̉̋͠ ḱ̵̛̛̻̗̻͉͓̀͒͞ḣ̷̭̮̰̙̞̜͎͔̪̜̔̂̈́̾̌̋̋̈́͝u̧̦̲͍̦̯̱̐̅̃̕͞ ḳ̶̡͖̮̖̹̻͐́́̀̔̇̄̑͑͢͝ͅ°̢̢̼̜͍͇͂͗͗̾̒̚ ḽ͉̰̱͈̳̺̰̮̊̍̐̏͆̌̐̕̚ l̵̨̡̛̻̻̺͚͚̤̯̺̈́̊̒̍͛͒͠ l̩̤̬̰̹̘̔̾̍̓̔̚͟′̡̭̖̼̙̩̼͆͑̃͆͆̏̽̄̾̕′̷̢͚͍̟̠͍̖̐́͋̿̓̍͂̆̍ ł̰̬̩̪̥̘̜͙̾̃͗̎̆̓̄̕͜͝͡ l̨̢̥͉̎̍̅̐̚͜͟ḣ̨̘̭̼̜͇̹͓̹̊̀̽͛̎̒̚͞͝ ḷ̡͕͍͎̥̣͚̣̞͉̐̿̇̃̄͊͂̅͘q̨̢͓̣̦̦͙̤́̃̀́̀̑̆w̵͖̥͓͚̽̾͒̀͒͘ͅͅ ḉ̡̣̮̜̗͖̞͕̊̌̽̅͌͞͝,̵̨̬̲͓̯̝͉͋̔̓͑́̂̑ķ̡̗̖̠͓͛͒̾̕͘͡	PICTURE ID 17 NAME &quot; λx . ophidia ereц grex          .    أوفيديا إريكس جريكس   .arrowll.gif&quot; TURNS ANOTHER  z̴̧̬̰̙̹̪̬͎͗͋̈́̓͌̒̅̾͟ ʒ̸͈͙̱̙̹̎́̀̔̋̈́́͘͟ d̵̘̟̼͓̮̄͒̊̒̎́̑̒͌̚z̛̛̼͚̬̱͙͒̒̇̌̓́̒̚͜͢ͅư̶͇̞̤̻̫̓́͑͌̃̑͟ ʒ̴̧̨̧͖͖̼̫̙͗͗́̓͌͢͜°̬̥̰͎̰͌̑̈́̋̆͑͒͟͝͞h̸̢̜̞͎͓̯̉̌͑̉́͆͞ư̶̧̧̙̟̤̟͇͍̆̋̄̉̃̂͛͗̕ Є̸̠̮̺̣̗̭̭̥̘̀͆͋͟͡͠͝w̷̡̜̩͎̮͚̥̺͍̰͐̍͛̄̌͠͞ダ̶̲̮̜̪͍͖͓́͊̃̀̀͑̈͑̕͠ ENDPICTURE
	PICTURE ID 185ꙑꙗxє NAME &quot; λx . ophidia ereц grex          .    أوفيديا إريكس جريكس   .arrowrr.gif&quot; TURNS ANOTHER COLOR z̷̘͙̟͔̙̘̽̀́̀͋͟ŭ̸̙̤̯͇̺̞̉́̿̅̊͂̽б̶̨͕̬͓̐̂̈̍̾̚͟͠͞о̛̬̯̻͙͖͓̗̥͂̏̎̾̿̿̌ͅу̡̥̮̰͍͖͒͂͐͋̋͊͢к̷̯͙̯̪̬͌̌̓̉̌̓̅̈͌ꙑ̶̡̨̥͚͎̭͌̓͋̓̏́́̑b̛̝̼̜͙̭͌͋̈̾̆́̇̏͢u̧̧͚̺̙̟̪̹͕͑͒́̀̌̋̎͝k͇̗̻̞̗̹̅̊̃̈́̅̄̂y̴̧̡̬̳͉̦̗̻̪̓͒̌͐̄̕͠г̢̟̥̯̜̭͎̮̤̅͛̄̿̿͊̚͝͞л̴͎͇͕̯͕̞͖̊̓̍̔͑́͠͝а̨̛̱̳͖̗̯̫͗́̄̓г̢͓̠͇͎̘̝͑̃̓̓̓͟͢͠ӧ̶̧̢͍̠̜̰̩̫̜͛̐̆̂͘л̧̪̩̺̯̭́̍̌͘͜͜͜͡͝ѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠  ENDPICTURE (̶̨̡̠͈̝̳̫͉͗̆̌͗̽̚2̪̮̥̣̩͔̺͚̗͗̀͛̐͗̽̍ͅ.̷̡̧̥͉̺̺͖͖̭̀̅̾͊̕͝2̧̤̭̹͈͈̭̌̔̀̃͐͟͞͞)̸̢̳͕̦̰̤̲̄̈̊́̒͝ч̨̳̭͍̬̞͍̹̏̂̀͂̿̀͠͠Ӏ̡̫̟̖̲́̐͋͑͡k̙̦̜̖͎̯͕̄̿́̇͐͌̈́̔͠ k̸̢͚͕̔̒̍͛̈̋͐͐͜͠͡ͅư̴̢̫͈̘̣̖̰̝̂̇͗̈́̾̀́͜͞͝ͅ ž̧̧̮̲̘̩̽̿̇̅̔͘͟′̺̞͓̥̳̰̾̎́̓͞ͅ′͈̳͇͙͈͈̠͐̀̇̑̍̅̾̎͞ͅư̶̡̤͓͈̪͉̠̭̣̈̽̾͋͐̇̉͟͠͞ ž̫̝̦̘̺̦̭̏̇̓͒͢͝͠′͈̰̺̖̪̦̞̀̔̇̓͋̃̏͜͡͠i̢̧̨̖̇̇̀̀̇͟͟͜͠u̸̡̧̫̱͕͔̱̥͍̬͈̩͇̒͋̓̏͐̈̆́͂͒͊̆̕̕̕͟͡͠͡͡ —̝̣̜͙̝̳̰̥̖̅̈́͑̀̾́̊̕͘͞ Є̶̨̗̠̳̜̪̯̬̜̰̒͋̄͋̀ǐ̴̡̪͖̰̜͉͒̎̌̌͞͠ą̵̴̧̛̠̞͈̳̗̥̳̘̪̻͗̑͑́́͆̽̆͊̍̎̂͘̚͘͡͡ —̤̫̖̣̪̫̿͊̾̾̇̈̅͡ ḣ̵̰̜̟̙͓͕̗̣͒͒̽͐̓̀̍̂͝ ʾ̷̦̥̘̹̻̬̯̼͈͐̈̄͌̕̚͝ ḩ̨̮͇̲̇̓̋́́̒͑͢͠ú̵̧͇͇͓̳̩̊̂̋̾́̽͘͟͢ ʾ̷̺̜͈̬̠͍͇͉͓͇̇̆͆̒͝͡°̶̡̢̢̛̱̲̠̮̭̫͐̎̈́̔̏̀̚ͅk̸̰̗͙͉͈̰̓̋̽̉̽̉͌̀̕′̛͉͕̹̣̖̄͒́̄͂̇̾́̾′͉͖̪̞̖̦͂̔͑͂̒̇͊̍͜͢ k̴̨͚̮̠̞̞̙̺͎̓̓̓̇͝′̧̼̦̜̥̞̮̖͑̇͒̿̋̀̀̓͞͡′̶̨͔̼̞̜͖̲̘̀͐͆͝͞u̱̠̗̰̜̾͊̂͟͝͡ k̛̗̮̝̠̠͙̉͠͠͝‡̵̪̞̣̗͕̱̙͔̦̀̎̓̃̀̕͜ ḵ̵͍̝̬͗̏͗͛̎̽̎̕͟‡̶̧̱̠͍̩̗͑͌̊̃̄̊̀̓̕̕͟u̗͔͈͔̤͕̓̓̐̏̍͛͌̋̂̏͜ͅ l̘̣̠̣͙̪̦̒̓͒̐͌̾ǫ̵̘̺̤̹͇͖̒̍͆͒̈́̋̈̀̄͊͢w̨̠͔͕̠͕͔͕͛͊̎̎̈̾̐̕͞͠a͖̥̜̯͉͆́̎̕͡n̲͕̞̟̺̝̠̓̍̓̔̐ṣ̷̞̰̜̜̰̌͂̒͗̒̃͢͢͢ʹ̨̹͙̼͚͉̩̗͛͆̐̓̉́ͅШ̷̮͚̥̲̘̫̯̰̀̍̒̏̊͆̈́͘͢ͅӀ̵̧̬̮͙̥̮͓̆̈̅̈́͗͞у̵̘͔̺̳̪͓̞̮̯̐͌̋͋̃̔͠ш̵̡̡͎̣͓̝͎̯̰͆͂̂̓̌͘͠Ӏ̵̨̨̧̥͕̙͖̇̅̀̍͑̋͐̕͡z̥̫̠̯͚̭͓̪̱̆́͗̈͛̄͜ 19 И и 20 Й й 21 К к  में किताबां विचों पढ़ेया नि.o .o .js o u̧̧͚̺̙̟̪̹͕͑͒́̀̌̋̎͝k͇̗̻̞̗̹̅̊̃̈́̅̄̂y̴̧̡̬̳͉̦̗̻̪̓͒̌͐̄̕͠г̢̟̥̯̜̭͎̮̤̅͛̄̿̿͊̚͝͞л̴͎͇͕̯͕̞͖̊̓̍̔͑́͠͝а̨̛̱̳͖̗̯̫͗́̄̓г̢͓̠͇͎̘̝͑̃̓̓̓͟͢͠ӧ̶̧̢͍̠̜̰̩̫̜͛̐̆̂͘л̧̪̩̺̯̭́̍̌͘͜͜͜͡͝ѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠ (̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ ê̷͔̻̜͔̄̑̉̏̌̑̒̈́̕͜͜ͅ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ —͉̯͓͌̿͆́͋̄͜͟͡ z̸̡̛͉͖̠̦̬̺̓̈́͛͒͜h̸͙̘̫̻̠͕̺̥̅̂̐̎̌̍̈́͂͘͝ ž̷̧̠̤̖̗͎͚̖͖̘̈́̂̿̾̊̾͠ z̵͙̜͚͚͍̤̖͓͎̆̇̀͛̌͋͋̕͠͠h̸̡̢̨͉̼͔̝̋̏̿͑̓͑͟ͅ′̡̡̟̬͍̿̀͋͗͆̿͘′̲̺̣̫̻̥̤̝̯̬͗͂̾̒̇̿̎̾ ẑ̛͚͚̼̳̠͖̋̒̊̀́ z̥̫̠̯͚̭͓̪̱̆́͗̈͛̄͜h̶̡̤̺͈͙̟͆̈́̇́̈́̀′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅu̸̼͔̰̯̖̐͆͗̏͐̾͡ͅ ẑ̷̛̲̭͉̪̜̯͌̍̅̿́͢͠ͅ°̵̺̹̫̹͙͇͆̉̋̎̇̿͂͟͞͝ z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ′͍̠̤͉͓̦̦̦̻́͒͐͌̆̀͡ͅ ž̴͚̳̞̙͙͖̙͈̏̅̾͋͊͋̈̋͗͢′̨̟͉͔͙̐̅̓̃̀̕͟͠ z̦̬̠̳̻̃͂͋̎́̔͢͢͝ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝ ḯ̻̖̮̦͕͊̇͋̂͂͜͝ĭ̙̟͕͈̪̝̤͎̓̅̀̔̎̊̀̐̅͂͢͜ j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆ k̵̡̬͔̬̩͇̤͐͊̅͆̃ͅḣ̷̨̯̜̠̻̿͊͑̎̀͟ č̵̡̨̘͖̥͕͉̔̅̀̅͡͠′̵̸̡̡̛̳̹̰̰̲̣̲̞͕̝͇̟̩̀̀̍̈́̃̊̓̍̓̉̃̉̋͠ ḱ̵̛̛̻̗̻͉͓̀͒͞ḣ̷̭̮̰̙̞̜͎͔̪̜̔̂̈́̾̌̋̋̈́͝u̧̦̲͍̦̯̱̐̅̃̕͞ ḳ̶̡͖̮̖̹̻͐́́̀̔̇̄̑͑͢͝ͅ°̢̢̼̜͍͇͂͗͗̾̒̚ ḽ͉̰̱͈̳̺̰̮̊̍̐̏͆̌̐̕̚ l̵̨̡̛̻̻̺͚͚̤̯̺̈́̊̒̍͛͒͠ l̩̤̬̰̹̘̔̾̍̓̔̚͟′̡̭̖̼̙̩̼͆͑̃͆͆̏̽̄̾̕′̷̢͚͍̟̠͍̖̐́͋̿̓̍͂̆̍ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ l̨̢̥͉̎̍̅̐̚͜͟ḣ̨̘̭̼̜͇̹͓̹̊̀̽͛̎̒̚͞͝ ḷ̡͕͍͎̥̣͚̣̞͉̐̿̇̃̄͊͂̅͘q̨̢͓̣̦̦͙̤́̃̀́̀̑̆w̵͖̥͓͚̽̾͒̀͒͘ͅͅλxǯ̷̨̣̰͈̲̮̈́̈́̈́̓̄̊̈́͡′̵̡̨̬͎̙͋̐̂̇̀͊͋͊̊͒ ḑ̷͚̙̰̋́͑̿̕͜͟


    - v̷̜̻̮̜̹̦̍̈̋̎̔̚İ̧̟͓̲̤̩̲̉͌̀̐́̈́̎̾͜͞Ṡ̢̢̫͚͙͔͊̍͋͐̅͘͘͘O̸̝̘͈̻̣͎̼̲̐͑̓̆͆̃̚͝ 9̥̮̩̺̲̓͑̎̌̀͋͛̕͜͟͡ 1̷̢̛̯̗̗̹͎̝͓̈̋̔̇͜͡9̶̧̙̟̺͓̘̰̐̅̎̑͆͋͂͘͝9̸̢͈̲̪̱͊͛͗̌̓͋̚͞͠5̷̛̛̤͉̹̲̾̄̕͜(̱̪̻̘͆͒̍́̑͊̈́͢͠1̸̡̥̪̞͌̈́̐͌̎̕͜͡.̶̮̖̲̠͈̮̤̞͛̅̎̀̅͊́̏͟0̦̖̦̖̦̾͛̀̓̎͘)̸̥͎̹̼͓̊͊͋̒̏

phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches

    - v̷̭̖̗̤͉̗̄̀̓̏̾͒̄͘͠a̶̢͎̭̖͕̮̟͓͛̇̀́͒̽̊͗͘͢ ન̴̙̱̝͕͑̉̈́̅͒̀͢ͅͅા̶̘͇̱̲̜͔͇͚͊̃̌͐̆̒͗̎̚͟ળ̢̯̞͉̯͔̤͖̅͂̈͒͋ લ̧̱̦̩̣̓̒̎̿̚ર̛̱͚̞̫̝̳̫͒̋͐̈́́̍͂͟ઘ̸̨̳̼̠͖̣̝̎̎̆̄͗̅̂͠͠ે̛̩̲̤̞͌͛̅́̈́͟͡એ̸̢͇̟̥̪̣͍̫͛̑̓͋̎͐͢ ન̢̨̛̛͙̼̱͈̺̳͓̅̀̍͛̚ી̢̖͖͙͉̗͖̅̾̏̐̐͟
phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches

    - v̷͓͕̲͍̰̅̎̑͑̅͐͡ḅ̧̞̱̹̤͂͂̍͊́͠͞ ક̛̗̹̣̻̙̪̭͎̹͗͒̏̂́̕͞ͅે͕̩̟̳͓͚̐͂̐̆̇̏̐ͅહ̴̻͎͚̮͈̰̬͋̅́̾̓̍͘ͅા̛̱̹̤̰͎͖̊͐͑͂̌́͆̅ન̶્̛̹̲̜͕̝͔̝͕̙̬̞̂͑̊͗͋͋͋͘̚͜͠ͅͅદ̵̨̯̹̰͖̱̹̤̟̆̈́̀͂͋͊̀͝ે̖͕͎͖̣͈͓̿̅͌̎́͆̊͟ આ̴̨̰̮̪̱̺̠̤͍̿̏̀͛͛̀̏͑ શ̡̲͔̩̫̝̙̯̫͐̒̑̾̓̉̎̒̕͜͞િ̴̛̛͇̝̘̗͕͉͖̄̏̽̽̌͞ખ̴̗͔̱̝̹͚̯̲̒̇͂̾̉̚͞ર̸̜̞̬͙̖̜͐̓̔́̓́̅͜ જ̶̞̩͈̥͉̩̩̼̉̔̂͐̕͘ͅો̛̝̦͓̯̰̮͇͕͇̉̌̏̈̽̂̀̚ͅહ͔̳̼̥͖͂̀͗͐̊̑͑̚͟͠ર̢̘̦̝̟̹̳̜̲̄̆̈́͊̊̑ી̴̫͖̙̻͚̪̤͛̈̀̿̈́̓̋̽

phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches

    - v͍͖̰̫̟̪͆͋̃͊̈́̓̑͞͠v̟̣̞̬̠̉̏͐̅͝ થ̩̗͍̝̺̥̐̔̂̿̕̚͠͝͡ા̵̨̧̺͙̝̥̤̒̾̃̎͟͝’̵̹̺̜̫̠͒̑̈́̏͊̏̽̚͝ન̬̥̼̩̺̮͓̉̾̄́̀͊̔́͘͝ͅ ઉ̵̘͚̩͉͗̏͂̂̾̄̾̍̈͟͡ત̸્̛͖̤͎̠̭̯̣̲̟͉͓̪̜̠͋͗̉͆̈́͘̕̚͟͟͠͞͡ͅત̵͙͕͇͔̺͊̇̋̅̇̄͝ે̷̤̖͇͈̘̪̿̋͌̄͛͝ ખ̢̺̙͕͚̳̙̤̯͌͆̀́̿̊͛̚͟͝ર̺̺̦̣͈̝̺̩̘́̊͐̕͜͝ે̸͍̲̜͓̪͚̮̑̇͒̈́͗̔̍̉͌͝એ̴̡̨̙̗̭̯̄̅̓͛͡ ન̧̛͍͍̪͙͖̻̻̺̃̏̎͛̔͒̅͟͝ી̶̨͖̟̥̤͆̿͆͆̇͜

phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches


    - v̯̗͍̻͚̜̂̄̏͛̍͗̄͋͟͠͞g̶̨̛͚̻̥̱̝̫̓̓͛͑̐́͊̿́ g̷̢̖̤͉̲͇͍̪̹̭̑͐̌̉͛́͘ů̼̙͍̱̙̦̞̟̰̾̏͂̿͝ g̸̛͍̫̲͇͎̯̫̍̐͆̊′̧̻̜͇̦͚͓͋̆͗̋͊́͝′̴̧̘͇̠͂̂̇̃͆̚̕̚͟ g̵̨̛͇̞̼͕̼̥͖̩̦͛̀̃͌̋͊̊͡͝′̡̨̧͕̤̘͖̼̼̜̾̓̾̌͛͘͡͠′̡̡̻̰̏̔̃̀̈́́̀̍͊͋͜u̷̪͉͍̦̬͒̃̆̽́̀͛̊̕͜ d̳̟̲̲̠͙͈͓͋̂̎̓̔̋̈͘͠ d̨̢̛̝̮̯̫͔̙͈̎̂̔̄̿͛͟͞ž̴̛̮̺̝̟̥̐̄̀͂̚̕͜͟͡ ḍ̡͚̹̄͌̾̍͐̅̎̊͢z̬̬͉̳̯͕̠̀͂̂̉̚͟ ḍ̛͎̱̞͚̎͑̊̉̅̕ͅz̘̭͍͈̦̲̩̦̮͊͛͆̑̾͠ͅu̲͓͙̳̹̻͙̪͍͆̎̾̉̓̃͆̆͞ e̢̫̫͎͈̣̬̭̖͒͊̉̎̑͋͝

phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches
"><pre class="notranslate"><code>




https://github.com/user-attachments/assets/82cd4c1d-2ae2-429e-99a5-91ec794e4030



https://github.com/user-attachments/assets/73097654-130e-4bb4-a777-66b37a8b1cb8





##   6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢   6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢   6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢   6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢   6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢   6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ N'Eiko エメラダ Ferrari  6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢   6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢   6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢   6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢   6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢   6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢   6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢   6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ 

&lt;!--
**greydoubt/greydoubt** is a ✨ _special_ ✨ repository because its `README.md` (this file) appears on your GitHub profile.

Here are some ideas to get you started:

- 🔭 I’m currently working on ...
- 🌱 I’m currently learning ...
- 👯 I’m looking to collaborate on ...
- 🤔 I’m looking for help with ...
- 💬 Ask me about ...
- 📫 How to reach me: ...
- 😄 Pronouns: ...
- ⚡ Fun fact: ...
--&gt;


    - 00 Rotary Zero Zedd 0⁂ 
    
    - 01 А а

    - 02 Б б
 
    - 03 В в

    - 04 Г г
    
    - 05 Гугу
   
    - 06 Гъгъ
   
    - 07 Гъу гъу
    
    - 08 Д д

Sikheya street'an cho'n mein kitaaban vichon parheya ni
सिखइया स्ट्रीट'ान को'ं में किताबां विचों पढ़ेया नि
Sikheya street'an cho'n mein kitaaban vichon parheya ni
Once upon a time, I learn't how to read books on the street corner

તિનકા ઔકાત સી પહરણ નાળ લરઘેએ ની
Tinka aukaat c paharaan naal lardhea ni
They called me the girl who cut the pharaoh, standing pallid over the fat of the land

કેહાન્દે આ શિખર જોહરી થા’ન ઉત્તે ખરેએ ની
Kehande aa sikhar jehri thaa’n utte kharea ni
Where is this peak, where is it not visible? There is always another mountain to climb

જો ખીચડિ આ લટતાં કેહાન્દે "સાદે સીરો'ન ચડેએ ની"
Jo khichde aa lattan kehande saade siro'n chadea ni
If the sour grapes die on the vine, it will be said, The Sweet Sadism of Shiva Nyxhades was her own demise

63 Ь ь 64 Э э̛̯̖̜͓̩̣̒̈́̉͋̆ Ꙗ̨̨̰̥̖̺͇͕̠͌̿͌̓̒͒͊́̀͡ Ꙑ̳̲̜̪̮̈́̾̊̂̓̄̿̓͑̏)̴̧̧̱̱͕́̃͌͛̏̒̏͘͟͢͠4̨̡̘̦͈͕̠͇̣͂̽̌͋͟͝ Ч̶̯̦͕͙̣̑̐̆̕͟͢͡͝Ӏ̻͓̣̳̓̊̐͋̇̏͟͞х̸̧̨̪̳̲̰͉̱̻͋̂̾̃͝͡у̡̝̖̭͍̟̟̘̫̀̐͐̈́͗̂̄͌͗̚͟̯̖̤̣̌̌̅͗̂̃̉͘͟ͅф̢̝̖͇͓̜̘̘̔̆̅̑́̽͒͘͜͠g̶̙͙̳̬͌͑͑͌̓͟ ɣ̡̡̹͉͙͖̱͙̇̉̄͒͗̍̂͐̿͠ ģ̡̢̥̦̞̬̀͊́̒̀̕͜ͅư͔͉̦͕̟̮̊̃̾̏̉ g̘͙̘̻͉̖̺̹̺̏̈́̃̌͗͘͜°̷̡̱͕͎͇̹̔͌̄̄̊ ģ̶̻̙̱̤̻̔̿̏̋̀͂̐͢ͅ′̵̢̢͈̰͉̺̆̒̊͊͞͠′̵̫̭͓̘̂̾̔̔͒̽̀͊͘͘͜ͅͅ ġ̨̛̯̯̣͕̫̘̼͋̍͂͆͢ g͇̗̣̥̜̙̝͓͋̓̔̀͊̒͑͗͘′̵̨̯̲̭͙̦̟͉̟̞̆̃̑͂͘͡′̧̬̺̪͍̟̼̏̽̾͛̏͐̿͜͡͡ŭ̶̙̭̥̟̥̭̘̟̺͛̊̿̅̎͗̇͝͡ ġ͚̳̘̖̬͉̌͆̀̄̐̄̌̉̐̒͜°̶̧̞̪͚̾̊͗͂͘͜ ḓ̵͖̦̹͍͊̆̓͒̑͂͗͛ d̡̧̙̪̻̮̗͎͂͌͆̓̓̊̍̅̓ d̷͖̼͓͕̮̽̇̇͌̕z̷͚̯̦͉̙̉̿̐̈́̂͌̑͢͞͝͠ḧ̨͙̯͍̣̲͎́̎̉͌͋̏͆̑̋̚͢ ǯ̷̨̣̰͈̲̮̈́̈́̈́̓̄̊̈́͡′̵̡̨̬͎̙͋̐̂̇̀͊͋͊̊͒ ḑ̷͚̙̰̋́͑̿̕͜͟z̴̧̬̰̙̹̪̬͎͗͋̈́̓͌̒̅̾͟ ʒ̸͈͙̱̙̹̎́̀̔̋̈́́͘͟ d̵̘̟̼͓̮̄͒̊̒̎́̑̒͌̚z̛̛̼͚̬̱͙͒̒̇̌̓́̒̚͜͢ͅư̶͇̞̤̻̫̓́͑͌̃̑͟ ʒ̴̧̨̧͖͖̼̫̙͗͗́̓͌͢͜°̬̥̰͎̰͌̑̈́̋̆͑͒͟͝͞h̸̢̜̞͎͓̯̉̌͑̉́͆͞ư̶̧̧̙̟̤̟͇͍̆̋̄̉̃̂͛͗̕ Є̸̠̮̺̣̗̭̭̥̘̀͆͋͟͡͠͝w̷̡̜̩͎̮͚̥̺͍̰͐̍͛̄̌͠͞ダ̶̲̮̜̪͍͖͓́͊̃̀̀͑̈͑̕͠h̳̼͉̘̙̉̍̎̀͊͗̕͞′̠͕͙͚́̓̉̅͜͠′̛̗͖͈͔̦̠͉͓̾̔̓͊͌ラ̶̡̛̻̫̼̞̥̃̀̇̓̇͛͋͝͡a̶̧̟̜̯͇̘͉̥͐̃̒̆̿̀̃̔͡͠z̷̘͙̟͔̙̘̽̀́̀͋͟ŭ̸̙̤̯͇̺̞̉́̿̅̊͂̽б̶̨͕̬͓̐̂̈̍̾̚͟͠͞о̛̬̯̻͙͖͓̗̥͂̏̎̾̿̿̌ͅу̡̥̮̰͍͖͒͂͐͋̋͊͢к̷̯͙̯̪̬͌̌̓̉̌̓̅̈͌ꙑ̶̡̨̥͚͎̭͌̓͋̓̏́́̑b̛̝̼̜͙̭͌͋̈̾̆́̇̏͢u̧̧͚̺̙̟̪̹͕͑͒́̀̌̋̎͝k͇̗̻̞̗̹̅̊̃̈́̅̄̂y̴̧̡̬̳͉̦̗̻̪̓͒̌͐̄̕͠г̢̟̥̯̜̭͎̮̤̅͛̄̿̿͊̚͝͞л̴͎͇͕̯͕̞͖̊̓̍̔͑́͠͝а̨̛̱̳͖̗̯̫͗́̄̓г̢͓̠͇͎̘̝͑̃̓̓̓͟͢͠ӧ̶̧̢͍̠̜̰̩̫̜͛̐̆̂͘л̧̪̩̺̯̭́̍̌͘͜͜͜͡͝ѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠ (̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ e̖͇̜̳̲͍̔̅̆̒̍̓͞ ê̷͔̻̜͔̄̑̉̏̌̑̒̈́̕͜͜ͅ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ —͉̯͓͌̿͆́͋̄͜͟͡ z̸̡̛͉͖̠̦̬̺̓̈́͛͒͜h̸͙̘̫̻̠͕̺̥̅̂̐̎̌̍̈́͂͘͝ ž̷̧̠̤̖̗͎͚̖͖̘̈́̂̿̾̊̾͠ z̵͙̜͚͚͍̤̖͓͎̆̇̀͛̌͋͋̕͠͠h̸̡̢̨͉̼͔̝̋̏̿͑̓͑͟ͅ′̡̡̟̬͍̿̀͋͗͆̿͘′̲̺̣̫̻̥̤̝̯̬͗͂̾̒̇̿̎̾دووپشک ẑ̛͚͚̼̳̠͖̋̒̊̀́ z̥̫̠̯͚̭͓̪̱̆́͗̈͛̄͜h̶̡̤̺͈͙̟͆̈́̇́̈́̀′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅu̸̼͔̰̯̖̐͆͗̏͐̾͡ͅ ẑ̷̛̲̭͉̪̜̯͌̍̅̿́͢͠ͅ°̵̺̹̫̹͙͇͆̉̋̎̇̿͂͟͞͝ z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ′͍̠̤͉͓̦̦̦̻́͒͐͌̆̀͡ͅ ž̴͚̳̞̙͙͖̙͈̏̅̾͋͊͋̈̋͗͢′̨̟͉͔͙̐̅̓̃̀̕͟͠ z̦̬̠̳̻̃͂͋̎́̔͢͢͝ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝ ḯ̻̖̮̦͕͊̇͋̂͂͜͝ĭ̙̟͕͈̪̝̤͎̓̅̀̔̎̊̀̐̅͂͢͜ j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆ k̵̡̬͔̬̩͇̤͐͊̅͆̃ͅ —̷̢̛̜̬͔̖̳͆̇̐̀̚͢͠ k̶̛̭̮̝̹̹̬͌̈́͋͜͟͞u̵̧̠̠͍͖͗́̆̉̄͘ k̸͎͈̣̦͌̂̏͋̊͒͢͡°̴̧̰̮̺̮̙̲̯̤̠̊̊̂̿̎̓͋ ķ̘͔̤̠̪̟̮͌̌͑̎̈̊̕′̳̱̞̥͕̥̀̄̽̏̂́̾͞′̴̧̱̖͉̗̾̏͆̾̍͆͌͞͠ͅ q̶̨̩̝̞͙͛̓̒͋͒ ķ̮̠͕̹̩̤̀̉̄̎̕͘̕͢′̨̧͖͇͈̳̣͆̑̑͂́͊͜͡′̥̳̥̦͈̫́̄́̍̔̽̑͞ứ̵͈͔̭͍͓̲͔͙͚́̆̊̏̚͠͡ q̵̢̛̼̥̭̪̼̆͋̂̑̅̚͠°͖̹̲̻̣͍̹͇́͋́̒̓͆͂̆͛͗ k̴̡̺̙͕͉̯̖̯͎͒̏̊͡͝ḣ̷̨̯̜̠̻̿͊͑̎̀͟ č̵̡̨̘͖̥͕͉̔̅̀̅͡͠′̵̸̡̡̛̳̹̰̰̲̣̲̞͕̝͇̟̩̀̀̍̈́̃̊̓̍̓̉̃̉̋͠ ḱ̵̛̛̻̗̻͉͓̀͒͞ḣ̷̭̮̰̙̞̜͎͔̪̜̔̂̈́̾̌̋̋̈́͝u̧̦̲͍̦̯̱̐̅̃̕͞ ḳ̶̡͖̮̖̹̻͐́́̀̔̇̄̑͑͢͝ͅ°̢̢̼̜͍͇͂͗͗̾̒̚ ḽ͉̰̱͈̳̺̰̮̊̍̐̏͆̌̐̕̚ l̵̨̡̛̻̻̺͚͚̤̯̺̈́̊̒̍͛͒͠ l̩̤̬̰̹̘̔̾̍̓̔̚͟′̡̭̖̼̙̩̼͆͑̃͆͆̏̽̄̾̕′̷̢͚͍̟̠͍̖̐́͋̿̓̍͂̆̍ ł̰̬̩̪̥̘̜͙̾̃͗̎̆̓̄̕͜͝͡ l̨̢̥͉̎̍̅̐̚͜͟ḣ̨̘̭̼̜͇̹͓̹̊̀̽͛̎̒̚͞͝ ḷ̡͕͍͎̥̣͚̣̞͉̐̿̇̃̄͊͂̅͘q̨̢͓̣̦̦͙̤́̃̀́̀̑̆w̵͖̥͓͚̽̾͒̀͒͘ͅͅ ḉ̡̣̮̜̗͖̞͕̊̌̽̅͌͞͝,̵̨̬̲͓̯̝͉͋̔̓͑́̂̑ķ̡̗̖̠͓͛͒̾̕͘͡	PICTURE ID 17 NAME " λx . ophidia ereц grex          .    أوفيديا إريكس جريكس   .arrowll.gif" TURNS ANOTHER  z̴̧̬̰̙̹̪̬͎͗͋̈́̓͌̒̅̾͟ ʒ̸͈͙̱̙̹̎́̀̔̋̈́́͘͟ d̵̘̟̼͓̮̄͒̊̒̎́̑̒͌̚z̛̛̼͚̬̱͙͒̒̇̌̓́̒̚͜͢ͅư̶͇̞̤̻̫̓́͑͌̃̑͟ ʒ̴̧̨̧͖͖̼̫̙͗͗́̓͌͢͜°̬̥̰͎̰͌̑̈́̋̆͑͒͟͝͞h̸̢̜̞͎͓̯̉̌͑̉́͆͞ư̶̧̧̙̟̤̟͇͍̆̋̄̉̃̂͛͗̕ Є̸̠̮̺̣̗̭̭̥̘̀͆͋͟͡͠͝w̷̡̜̩͎̮͚̥̺͍̰͐̍͛̄̌͠͞ダ̶̲̮̜̪͍͖͓́͊̃̀̀͑̈͑̕͠ ENDPICTURE
	PICTURE ID 185ꙑꙗxє NAME " λx . ophidia ereц grex          .    أوفيديا إريكس جريكس   .arrowrr.gif" TURNS ANOTHER COLOR z̷̘͙̟͔̙̘̽̀́̀͋͟ŭ̸̙̤̯͇̺̞̉́̿̅̊͂̽б̶̨͕̬͓̐̂̈̍̾̚͟͠͞о̛̬̯̻͙͖͓̗̥͂̏̎̾̿̿̌ͅу̡̥̮̰͍͖͒͂͐͋̋͊͢к̷̯͙̯̪̬͌̌̓̉̌̓̅̈͌ꙑ̶̡̨̥͚͎̭͌̓͋̓̏́́̑b̛̝̼̜͙̭͌͋̈̾̆́̇̏͢u̧̧͚̺̙̟̪̹͕͑͒́̀̌̋̎͝k͇̗̻̞̗̹̅̊̃̈́̅̄̂y̴̧̡̬̳͉̦̗̻̪̓͒̌͐̄̕͠г̢̟̥̯̜̭͎̮̤̅͛̄̿̿͊̚͝͞л̴͎͇͕̯͕̞͖̊̓̍̔͑́͠͝а̨̛̱̳͖̗̯̫͗́̄̓г̢͓̠͇͎̘̝͑̃̓̓̓͟͢͠ӧ̶̧̢͍̠̜̰̩̫̜͛̐̆̂͘л̧̪̩̺̯̭́̍̌͘͜͜͜͡͝ѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠  ENDPICTURE (̶̨̡̠͈̝̳̫͉͗̆̌͗̽̚2̪̮̥̣̩͔̺͚̗͗̀͛̐͗̽̍ͅ.̷̡̧̥͉̺̺͖͖̭̀̅̾͊̕͝2̧̤̭̹͈͈̭̌̔̀̃͐͟͞͞)̸̢̳͕̦̰̤̲̄̈̊́̒͝ч̨̳̭͍̬̞͍̹̏̂̀͂̿̀͠͠Ӏ̡̫̟̖̲́̐͋͑͡k̙̦̜̖͎̯͕̄̿́̇͐͌̈́̔͠ k̸̢͚͕̔̒̍͛̈̋͐͐͜͠͡ͅư̴̢̫͈̘̣̖̰̝̂̇͗̈́̾̀́͜͞͝ͅ ž̧̧̮̲̘̩̽̿̇̅̔͘͟′̺̞͓̥̳̰̾̎́̓͞ͅ′͈̳͇͙͈͈̠͐̀̇̑̍̅̾̎͞ͅư̶̡̤͓͈̪͉̠̭̣̈̽̾͋͐̇̉͟͠͞ ž̫̝̦̘̺̦̭̏̇̓͒͢͝͠′͈̰̺̖̪̦̞̀̔̇̓͋̃̏͜͡͠i̢̧̨̖̇̇̀̀̇͟͟͜͠u̸̡̧̫̱͕͔̱̥͍̬͈̩͇̒͋̓̏͐̈̆́͂͒͊̆̕̕̕͟͡͠͡͡ —̝̣̜͙̝̳̰̥̖̅̈́͑̀̾́̊̕͘͞ Є̶̨̗̠̳̜̪̯̬̜̰̒͋̄͋̀ǐ̴̡̪͖̰̜͉͒̎̌̌͞͠ą̵̴̧̛̠̞͈̳̗̥̳̘̪̻͗̑͑́́͆̽̆͊̍̎̂͘̚͘͡͡ —̤̫̖̣̪̫̿͊̾̾̇̈̅͡ ḣ̵̰̜̟̙͓͕̗̣͒͒̽͐̓̀̍̂͝ ʾ̷̦̥̘̹̻̬̯̼͈͐̈̄͌̕̚͝ ḩ̨̮͇̲̇̓̋́́̒͑͢͠ú̵̧͇͇͓̳̩̊̂̋̾́̽͘͟͢ ʾ̷̺̜͈̬̠͍͇͉͓͇̇̆͆̒͝͡°̶̡̢̢̛̱̲̠̮̭̫͐̎̈́̔̏̀̚ͅk̸̰̗͙͉͈̰̓̋̽̉̽̉͌̀̕′̛͉͕̹̣̖̄͒́̄͂̇̾́̾′͉͖̪̞̖̦͂̔͑͂̒̇͊̍͜͢ k̴̨͚̮̠̞̞̙̺͎̓̓̓̇͝′̧̼̦̜̥̞̮̖͑̇͒̿̋̀̀̓͞͡′̶̨͔̼̞̜͖̲̘̀͐͆͝͞u̱̠̗̰̜̾͊̂͟͝͡ k̛̗̮̝̠̠͙̉͠͠͝‡̵̪̞̣̗͕̱̙͔̦̀̎̓̃̀̕͜ ḵ̵͍̝̬͗̏͗͛̎̽̎̕͟‡̶̧̱̠͍̩̗͑͌̊̃̄̊̀̓̕̕͟u̗͔͈͔̤͕̓̓̐̏̍͛͌̋̂̏͜ͅ l̘̣̠̣͙̪̦̒̓͒̐͌̾ǫ̵̘̺̤̹͇͖̒̍͆͒̈́̋̈̀̄͊͢w̨̠͔͕̠͕͔͕͛͊̎̎̈̾̐̕͞͠a͖̥̜̯͉͆́̎̕͡n̲͕̞̟̺̝̠̓̍̓̔̐ṣ̷̞̰̜̜̰̌͂̒͗̒̃͢͢͢ʹ̨̹͙̼͚͉̩̗͛͆̐̓̉́ͅШ̷̮͚̥̲̘̫̯̰̀̍̒̏̊͆̈́͘͢ͅӀ̵̧̬̮͙̥̮͓̆̈̅̈́͗͞у̵̘͔̺̳̪͓̞̮̯̐͌̋͋̃̔͠ш̵̡̡͎̣͓̝͎̯̰͆͂̂̓̌͘͠Ӏ̵̨̨̧̥͕̙͖̇̅̀̍͑̋͐̕͡z̥̫̠̯͚̭͓̪̱̆́͗̈͛̄͜ 19 И и 20 Й й 21 К к  में किताबां विचों पढ़ेया नि.o .o .js o u̧̧͚̺̙̟̪̹͕͑͒́̀̌̋̎͝k͇̗̻̞̗̹̅̊̃̈́̅̄̂y̴̧̡̬̳͉̦̗̻̪̓͒̌͐̄̕͠г̢̟̥̯̜̭͎̮̤̅͛̄̿̿͊̚͝͞л̴͎͇͕̯͕̞͖̊̓̍̔͑́͠͝а̨̛̱̳͖̗̯̫͗́̄̓г̢͓̠͇͎̘̝͑̃̓̓̓͟͢͠ӧ̶̧̢͍̠̜̰̩̫̜͛̐̆̂͘л̧̪̩̺̯̭́̍̌͘͜͜͜͡͝ѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠ (̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ ê̷͔̻̜͔̄̑̉̏̌̑̒̈́̕͜͜ͅ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ —͉̯͓͌̿͆́͋̄͜͟͡ z̸̡̛͉͖̠̦̬̺̓̈́͛͒͜h̸͙̘̫̻̠͕̺̥̅̂̐̎̌̍̈́͂͘͝ ž̷̧̠̤̖̗͎͚̖͖̘̈́̂̿̾̊̾͠ z̵͙̜͚͚͍̤̖͓͎̆̇̀͛̌͋͋̕͠͠h̸̡̢̨͉̼͔̝̋̏̿͑̓͑͟ͅ′̡̡̟̬͍̿̀͋͗͆̿͘′̲̺̣̫̻̥̤̝̯̬͗͂̾̒̇̿̎̾ ẑ̛͚͚̼̳̠͖̋̒̊̀́ z̥̫̠̯͚̭͓̪̱̆́͗̈͛̄͜h̶̡̤̺͈͙̟͆̈́̇́̈́̀′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅu̸̼͔̰̯̖̐͆͗̏͐̾͡ͅ ẑ̷̛̲̭͉̪̜̯͌̍̅̿́͢͠ͅ°̵̺̹̫̹͙͇͆̉̋̎̇̿͂͟͞͝ z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ′͍̠̤͉͓̦̦̦̻́͒͐͌̆̀͡ͅ ž̴͚̳̞̙͙͖̙͈̏̅̾͋͊͋̈̋͗͢′̨̟͉͔͙̐̅̓̃̀̕͟͠ z̦̬̠̳̻̃͂͋̎́̔͢͢͝ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝ ḯ̻̖̮̦͕͊̇͋̂͂͜͝ĭ̙̟͕͈̪̝̤͎̓̅̀̔̎̊̀̐̅͂͢͜ j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆ k̵̡̬͔̬̩͇̤͐͊̅͆̃ͅḣ̷̨̯̜̠̻̿͊͑̎̀͟ č̵̡̨̘͖̥͕͉̔̅̀̅͡͠′̵̸̡̡̛̳̹̰̰̲̣̲̞͕̝͇̟̩̀̀̍̈́̃̊̓̍̓̉̃̉̋͠ ḱ̵̛̛̻̗̻͉͓̀͒͞ḣ̷̭̮̰̙̞̜͎͔̪̜̔̂̈́̾̌̋̋̈́͝u̧̦̲͍̦̯̱̐̅̃̕͞ ḳ̶̡͖̮̖̹̻͐́́̀̔̇̄̑͑͢͝ͅ°̢̢̼̜͍͇͂͗͗̾̒̚ ḽ͉̰̱͈̳̺̰̮̊̍̐̏͆̌̐̕̚ l̵̨̡̛̻̻̺͚͚̤̯̺̈́̊̒̍͛͒͠ l̩̤̬̰̹̘̔̾̍̓̔̚͟′̡̭̖̼̙̩̼͆͑̃͆͆̏̽̄̾̕′̷̢͚͍̟̠͍̖̐́͋̿̓̍͂̆̍ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ l̨̢̥͉̎̍̅̐̚͜͟ḣ̨̘̭̼̜͇̹͓̹̊̀̽͛̎̒̚͞͝ ḷ̡͕͍͎̥̣͚̣̞͉̐̿̇̃̄͊͂̅͘q̨̢͓̣̦̦͙̤́̃̀́̀̑̆w̵͖̥͓͚̽̾͒̀͒͘ͅͅλxǯ̷̨̣̰͈̲̮̈́̈́̈́̓̄̊̈́͡′̵̡̨̬͎̙͋̐̂̇̀͊͋͊̊͒ ḑ̷͚̙̰̋́͑̿̕͜͟


    - v̷̜̻̮̜̹̦̍̈̋̎̔̚İ̧̟͓̲̤̩̲̉͌̀̐́̈́̎̾͜͞Ṡ̢̢̫͚͙͔͊̍͋͐̅͘͘͘O̸̝̘͈̻̣͎̼̲̐͑̓̆͆̃̚͝ 9̥̮̩̺̲̓͑̎̌̀͋͛̕͜͟͡ 1̷̢̛̯̗̗̹͎̝͓̈̋̔̇͜͡9̶̧̙̟̺͓̘̰̐̅̎̑͆͋͂͘͝9̸̢͈̲̪̱͊͛͗̌̓͋̚͞͠5̷̛̛̤͉̹̲̾̄̕͜(̱̪̻̘͆͒̍́̑͊̈́͢͠1̸̡̥̪̞͌̈́̐͌̎̕͜͡.̶̮̖̲̠͈̮̤̞͛̅̎̀̅͊́̏͟0̦̖̦̖̦̾͛̀̓̎͘)̸̥͎̹̼͓̊͊͋̒̏

phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches

    - v̷̭̖̗̤͉̗̄̀̓̏̾͒̄͘͠a̶̢͎̭̖͕̮̟͓͛̇̀́͒̽̊͗͘͢ ન̴̙̱̝͕͑̉̈́̅͒̀͢ͅͅા̶̘͇̱̲̜͔͇͚͊̃̌͐̆̒͗̎̚͟ળ̢̯̞͉̯͔̤͖̅͂̈͒͋ લ̧̱̦̩̣̓̒̎̿̚ર̛̱͚̞̫̝̳̫͒̋͐̈́́̍͂͟ઘ̸̨̳̼̠͖̣̝̎̎̆̄͗̅̂͠͠ે̛̩̲̤̞͌͛̅́̈́͟͡એ̸̢͇̟̥̪̣͍̫͛̑̓͋̎͐͢ ન̢̨̛̛͙̼̱͈̺̳͓̅̀̍͛̚ી̢̖͖͙͉̗͖̅̾̏̐̐͟
phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches

    - v̷͓͕̲͍̰̅̎̑͑̅͐͡ḅ̧̞̱̹̤͂͂̍͊́͠͞ ક̛̗̹̣̻̙̪̭͎̹͗͒̏̂́̕͞ͅે͕̩̟̳͓͚̐͂̐̆̇̏̐ͅહ̴̻͎͚̮͈̰̬͋̅́̾̓̍͘ͅા̛̱̹̤̰͎͖̊͐͑͂̌́͆̅ન̶્̛̹̲̜͕̝͔̝͕̙̬̞̂͑̊͗͋͋͋͘̚͜͠ͅͅદ̵̨̯̹̰͖̱̹̤̟̆̈́̀͂͋͊̀͝ે̖͕͎͖̣͈͓̿̅͌̎́͆̊͟ આ̴̨̰̮̪̱̺̠̤͍̿̏̀͛͛̀̏͑ શ̡̲͔̩̫̝̙̯̫͐̒̑̾̓̉̎̒̕͜͞િ̴̛̛͇̝̘̗͕͉͖̄̏̽̽̌͞ખ̴̗͔̱̝̹͚̯̲̒̇͂̾̉̚͞ર̸̜̞̬͙̖̜͐̓̔́̓́̅͜ જ̶̞̩͈̥͉̩̩̼̉̔̂͐̕͘ͅો̛̝̦͓̯̰̮͇͕͇̉̌̏̈̽̂̀̚ͅહ͔̳̼̥͖͂̀͗͐̊̑͑̚͟͠ર̢̘̦̝̟̹̳̜̲̄̆̈́͊̊̑ી̴̫͖̙̻͚̪̤͛̈̀̿̈́̓̋̽

phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches

    - v͍͖̰̫̟̪͆͋̃͊̈́̓̑͞͠v̟̣̞̬̠̉̏͐̅͝ થ̩̗͍̝̺̥̐̔̂̿̕̚͠͝͡ા̵̨̧̺͙̝̥̤̒̾̃̎͟͝’̵̹̺̜̫̠͒̑̈́̏͊̏̽̚͝ન̬̥̼̩̺̮͓̉̾̄́̀͊̔́͘͝ͅ ઉ̵̘͚̩͉͗̏͂̂̾̄̾̍̈͟͡ત̸્̛͖̤͎̠̭̯̣̲̟͉͓̪̜̠͋͗̉͆̈́͘̕̚͟͟͠͞͡ͅત̵͙͕͇͔̺͊̇̋̅̇̄͝ે̷̤̖͇͈̘̪̿̋͌̄͛͝ ખ̢̺̙͕͚̳̙̤̯͌͆̀́̿̊͛̚͟͝ર̺̺̦̣͈̝̺̩̘́̊͐̕͜͝ે̸͍̲̜͓̪͚̮̑̇͒̈́͗̔̍̉͌͝એ̴̡̨̙̗̭̯̄̅̓͛͡ ન̧̛͍͍̪͙͖̻̻̺̃̏̎͛̔͒̅͟͝ી̶̨͖̟̥̤͆̿͆͆̇͜

phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches


    - v̯̗͍̻͚̜̂̄̏͛̍͗̄͋͟͠͞g̶̨̛͚̻̥̱̝̫̓̓͛͑̐́͊̿́ g̷̢̖̤͉̲͇͍̪̹̭̑͐̌̉͛́͘ů̼̙͍̱̙̦̞̟̰̾̏͂̿͝ g̸̛͍̫̲͇͎̯̫̍̐͆̊′̧̻̜͇̦͚͓͋̆͗̋͊́͝′̴̧̘͇̠͂̂̇̃͆̚̕̚͟ g̵̨̛͇̞̼͕̼̥͖̩̦͛̀̃͌̋͊̊͡͝′̡̨̧͕̤̘͖̼̼̜̾̓̾̌͛͘͡͠′̡̡̻̰̏̔̃̀̈́́̀̍͊͋͜u̷̪͉͍̦̬͒̃̆̽́̀͛̊̕͜ d̳̟̲̲̠͙͈͓͋̂̎̓̔̋̈͘͠ d̨̢̛̝̮̯̫͔̙͈̎̂̔̄̿͛͟͞ž̴̛̮̺̝̟̥̐̄̀͂̚̕͜͟͡ ḍ̡͚̹̄͌̾̍͐̅̎̊͢z̬̬͉̳̯͕̠̀͂̂̉̚͟ ḍ̛͎̱̞͚̎͑̊̉̅̕ͅz̘̭͍͈̦̲̩̦̮͊͛͆̑̾͠ͅu̲͓͙̳̹̻͙̪͍͆̎̾̉̓̃͆̆͞ e̢̫̫͎͈̣̬̭̖͒͊̉̎̑͋͝

phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches

</code></pre></div>
<p dir="auto">i love you too :)</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="

y y
′ 
è e
û ju â ja ‡ x̧ ‡u x̧w
ALA-LC TITUS 1997(3.0) 2000(4.0)
tḣu ṭ°
u w,u f f
fḣ — kh x khu x° kh′′ χ kh′′u χ° kh′ ḥ
ts͡ c ts͡u c° ts͡ḣ c̣ ch čʹ ch′′ č chḣ č̣ sh š sh′′ ŝ sh′′u ŝ° shḣ ṣ̂ shḣu ŝ°̣ shch šʹ
′′ — y ǝ
′ — ė ă
iu͡ — ia͡ — ḣ ʾ ḣu ʾ°

 ન̢̨̛̛͙̼̱͈̺̳͓̅̀̍͛̚ી̢̖͖͙͉̗͖̅̾̏̐̐͟

3(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜ 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ

  🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂

   -k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂
🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂

   - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂
🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜ 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ

🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ

ł`જોહરીiorno!!! My name is łSO 9 KNAB 1995(1.0) エ🦂ミ~ 🍒2003(2.0) #エメラダ  #🦂🦂2003(2.0) #エメラダ #🦂#🦂🦂

 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜ 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    EMERELDA al GLAGOLI STRIKES AGAIN!!! EVERY HIT CRITICAL!!!! 🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂

🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ

Contents: Top 0–9 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z- ′′ — 🦂y 🦂ǝ
* # 0 1 2 3 4 5 6 7 8 9 • A Aa Ae Aj Ao At • B Ba Be Bj Bo Bt • C Ca Ce Cj Co Ct •- ′′ — 🦂y 🦂ǝ D Da De Dj Do Dt • E Ea Ee Ej Eo Et • F Fa Fe Fj Fo Ft • G Ga Ge Gj Go Gt • H Ha He Hj Ho Ht • I Ia Ie Ij Io It • J Ja Je Jj Jo Jt • K Ka Ke Kj Ko Kt • L La Le Lj Lo Lt • M Ma Me Mj Mo Mt • N Na Ne Nj No Nt •- ′′ — 🦂y 🦂ǝ O Oa Oe Oj Oo Ot GLAGOLI STRIKES AGAIN!!! EVERY HIT CRITICAL!!!! 🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂• P Pa Pe Pj Po Pt • Q Qa Qe Qj Qo Qt • R Ra Re Rj Ro Rt • S Sa Se Sj So St • T Ta Te Tj To Tt • U Ua Ue Uj Uo Ut • V Va Ve Vj Vo Vt • W Wa We Wj Wo Wt • X Xa Xe Xj Xo Xt • Y Ya Ye Yj Yo Yt • Z Za Ze Zj Zo Zt

🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ

3(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜ 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ


🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ


   -k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂
🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂

✶⭑


֍ 

GLAGOLI # raggas.js


## raggas.jš͚̭̺̗̼͍̗̱̐͒̒̂̕

XENOGEARS OMNIGEAR GHINION TURISMO IN THIS BITCH 


## $ #エメラダ    ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂  #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍  🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞  ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂#エメラダ 🦂#🦂#🦂#🦂#🦂#🦂#🦂#   ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ


$$ 🦂NIKKEが大好きで   .   ▁▂▃▄▅▆▇ 100% ɴᴏᴡ ᴘʟᴀʏɪɴɢ ──────⚪── ⇄ ◃◃ ⅠⅠ ▹▹ ↻   .  .

$ EVERY HIT CRITICAL!!!!


### raggas.js    - ′′ — y̱̼̹͕̘̆̀̀̆̑͟͜    -̨̼̦͕̳̮͚̊̔́͌̍̽̍ k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ǝ)̲̼͔̰͎̊̄̔̔͛̈̚̕͞


.js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES AGAIN!!!!!!!!


## ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝
[DEFENSE Я_O_RESPONSE]


```.GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES AGAIN!!!1one!!! ```


## ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝

[DEFENSE Я_O_RESPONSE]


```.GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES AGAIN!!!1two!!! ```


[DEFENSE Я_O_RESPONSE]


## ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝


```.GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES AGAIN!!!1three!!! ```

 ☦︎

```¿ ¡ ¿ ¡ ¿ ¡¡¡¿ ¡¡¡¡ EN REVERXA GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ ¡ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜¡w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES! ¡FOREVER! METEORA 9999 EVERY HIT CRITICAL !!! ```


🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ

🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ

|

phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches

01 А а 02 Б б 03 В в 04 Г г 05 Гугу 06 Гъгъ 07 Гъу гъу 08 Д д 09 Дждж 10 Дз дз 11 Дзу дзу 12 Ее 13 Ё ё  सिखइया स्ट्रीट'ान को'ं 14 Жж 15 Жъжъ 16 Жъу жъу 17 Жьжь 18 З з 19 И и 20 Й й 21 К к  में किताबां विचों पढ़ेया नि 22 Куку 23 Къкъ 24 Къу къу 25 КӀ кӀ 26 КӀу кӀу  તિનકા ઔકાત સી પહરણ 27 Л л 28 Лълъ 29 ЛӀ лӀ 30 Мм 31 Н н 32 О о 33 П п 34 ПӀпӀ 35 ПӀу пӀу 36 Р р 37 С с 38 Т т 39 ТӀтӀ ISO 9 1995(1.0) a નાળ લરઘેએ ની b કેહાન્દે આ શિખર જોહરી v થા’ન ઉત્તે ખરેએ ની g gu g′′ g′′u d dž dz dzu e ë જો ખીચડિ આ લટતાં કેહાન્દે ž ž′′ ž′′u ž′ z i &quot;સાદે સીરો'ન ચડેએ ની&quot; j Nyxhades k G'eiko Ferrari ku Eiko Dolphinonivm k′′ Eikha k′′u k‡ k‡u l l′′ l‡ m n o p p‡ p‡u r s t t‡ KNAB 2003(2.0) a b v g gw ǧ ǧw d dź dz dzw é,je(2.1) ë ž z̄ zw̄ ź z i j k kw q qw ḉ,ķ (2.2) ķw l ł ļ m n o p ṗ ṗw r s t ţ a ā b b v — g ɣ gu g° g′′ ġ g′′u ġ° d d dzh ǯ′ dz ʒ dzu ʒ° e e ë — zh ž zh′′ ẑ zh′′u ẑ° zh′ ž′ z z i i ĭ j k — ku k° k′′ q k′′u q° kḣ č′̣ kḣu ḳ° l l l′′ ł lḣ ḷ m m n n o o p p pḣ ṗ pḣu ṗ° r r s s t t tḣ ṭ 40 ТӀу тӀу 41 У у 42 Ф ф 43 ФӀ фӀ 44 Х х 45 Хуху 46 Хъхъ 47 Хъу хъу 48 Хьхь 49 Ц ц 50 Цу цу 51 ЦӀцӀ 52 Ч ч 53 Чъчъ 54 ЧӀчӀ 55 Шш 56 Шъшъ 57 Шъу шъу 58 ШӀшӀ 59 ШӀушӀу 60 Щщ 61 Ъ ъ  62 Ы ы 
 65 Юю 66 Я я 67 Ӏ Ӏ 68 Ӏу Ӏу ISO 9 KNAB 1995(1.0) 2003(2.0) t‡u ţw u u f f f‡ f̧ h x hu xw h′′ ḩ h′′u ḩw h′ h c c cu cw c‡ ç č ć č′′ č č‡ ç̌ š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś ′′  y y ′  è e û ju â ja ‡ x̧ ‡u x̧w ALA-LC TITUS 1997(3.0) 2000(4.0) tḣu ṭ° u w,u f f fḣ — kh x khu x° kh′′ χ kh′′u χ° kh′ ḥ ts͡ c ts͡u c° ts͡ḣ c̣ ch čʹ ch′′ č chḣ č̣ sh š sh′′ ŝ sh′′u ŝ° shḣ ṣ̂ shḣu ŝ°̣ shch šʹ ′′ — y ǝ ′ — ė ă iu͡ — ia͡ — ḣ ʾ ḣu ʾ°
エєmereldhas͡ c メrts͡uдобро азъ; hu Єwダh′′ラazŭбоукꙑbukyглаголи (glagoli),)c°h x huxw h′′ ḩ h′′u ḩw h′ h ts͡ḣ c̣ ch čʹ š š š′′ s̄ š′′u sw̄ š‡ ş̄iu͡ — ia͡ — ḣ ʾ ḣu ʾ°š‡u şw̄ ŝ śch′′ č chḣ č̣ sh š sh′′ ŝ sh′′u ŝ°x shḣ ṣ̂h′′ — y ǝ x hu Єwダh′′ ḩ h′′u ḩУw h′ h shḣu ŝ°̣ shch šʹШӀушӀу5ꙑꙗxє, ѕѣлозč̣ем

лꙗts͡ḣ̛̯̖̜͓̩̣̒̈́̉͋̆ Ꙗ̨̨̰̥̖̺͇͕̠͌̿͌̓̒͒͊́̀͡ Ꙑ̳̲̜̪̮̈́̾̊̂̓̄̿̓͑̏)̴̧̧̱̱͕́̃͌͛̏̒̏͘͟͢͠4̨̡̘̦͈͕̠͇̣͂̽̌͋͟͝ Ч̶̯̦͕͙̣̑̐̆̕͟͢͡͝Ӏ̻͓̣̳̓̊̐͋̇̏͟͞х̸̧̨̪̳̲̰͉̱̻͋̂̾̃͝͡у̡̝̖̭͍̟̟̘̫̀̐͐̈́͗̂̄͌͗̚͟̯̖̤̣̌̌̅͗̂̃̉͘͟ͅф̢̝̖͇͓̜̘̘̔̆̅̑́̽͒͘͜͠g̶̙͙̳̬͌͑͑͌̓͟ ɣ̡̡̹͉͙͖̱͙̇̉̄͒͗̍̂͐̿͠ ģ̡̢̥̦̞̬̀͊́̒̀̕͜ͅư͔͉̦͕̟̮̊̃̾̏̉ g̘͙̘̻͉̖̺̹̺̏̈́̃̌͗͘͜°̷̡̱͕͎͇̹̔͌̄̄̊ ģ̶̻̙̱̤̻̔̿̏̋̀͂̐͢ͅ′̵̢̢͈̰͉̺̆̒̊͊͞͠′̵̫̭͓̘̂̾̔̔͒̽̀͊͘͘͜ͅͅ ġ̨̛̯̯̣͕̫̘̼͋̍͂͆͢ g͇̗̣̥̜̙̝͓͋̓̔̀͊̒͑͗͘′̵̨̯̲̭͙̦̟͉̟̞̆̃̑͂͘͡′̧̬̺̪͍̟̼̏̽̾͛̏͐̿͜͡͡ŭ̶̙̭̥̟̥̭̘̟̺͛̊̿̅̎͗̇͝͡ ġ͚̳̘̖̬͉̌͆̀̄̐̄̌̉̐̒͜°̶̧̞̪͚̾̊͗͂͘͜ ḓ̵͖̦̹͍͊̆̓͒̑͂͗͛ d̡̧̙̪̻̮̗͎͂͌͆̓̓̊̍̅̓ d̷͖̼͓͕̮̽̇̇͌̕z̷͚̯̦͉̙̉̿̐̈́̂͌̑͢͞͝͠ḧ̨͙̯͍̣̲͎́̎̉͌͋̏͆̑̋̚͢ ǯ̷̨̣̰͈̲̮̈́̈́̈́̓̄̊̈́͡′̵̡̨̬͎̙͋̐̂̇̀͊͋͊̊͒ ḑ̷͚̙̰̋́͑̿̕͜͟z̴̧̬̰̙̹̪̬͎͗͋̈́̓͌̒̅̾͟ ʒ̸͈͙̱̙̹̎́̀̔̋̈́́͘͟ d̵̘̟̼͓̮̄͒̊̒̎́̑̒͌̚z̛̛̼͚̬̱͙͒̒̇̌̓́̒̚͜͢ͅư̶͇̞̤̻̫̓́͑͌̃̑͟ ʒ̴̧̨̧͖͖̼̫̙͗͗́̓͌͢͜°̬̥̰͎̰͌̑̈́̋̆͑͒͟͝͞h̸̢̜̞͎͓̯̉̌͑̉́͆͞ư̶̧̧̙̟̤̟͇͍̆̋̄̉̃̂͛͗̕ Є̸̠̮̺̣̗̭̭̥̘̀͆͋͟͡͠͝w̷̡̜̩͎̮͚̥̺͍̰͐̍͛̄̌͠͞ダ̶̲̮̜̪͍͖͓́͊̃̀̀͑̈͑̕͠h̳̼͉̘̙̉̍̎̀͊͗̕͞′̠͕͙͚́̓̉̅͜͠′̛̗͖͈͔̦̠͉͓̾̔̓͊͌ラ̶̡̛̻̫̼̞̥̃̀̇̓̇͛͋͝͡a̶̧̟̜̯͇̘͉̥͐̃̒̆̿̀̃̔͡͠z̷̘͙̟͔̙̘̽̀́̀͋͟ŭ̸̙̤̯͇̺̞̉́̿̅̊͂̽б̶̨͕̬͓̐̂̈̍̾̚͟͠͞о̛̬̯̻͙͖͓̗̥͂̏̎̾̿̿̌ͅу̡̥̮̰͍͖͒͂͐͋̋͊͢к̷̯͙̯̪̬͌̌̓̉̌̓̅̈͌ꙑ̶̡̨̥͚͎̭͌̓͋̓̏́́̑b̛̝̼̜͙̭͌͋̈̾̆́̇̏͢u̧̧͚̺̙̟̪̹͕͑͒́̀̌̋̎͝k͇̗̻̞̗̹̅̊̃̈́̅̄̂y̴̧̡̬̳͉̦̗̻̪̓͒̌͐̄̕͠г̢̟̥̯̜̭͎̮̤̅͛̄̿̿͊̚͝͞л̴͎͇͕̯͕̞͖̊̓̍̔͑́͠͝а̨̛̱̳͖̗̯̫͗́̄̓г̢͓̠͇͎̘̝͑̃̓̓̓͟͢͠ӧ̶̧̢͍̠̜̰̩̫̜͛̐̆̂͘л̧̪̩̺̯̭́̍̌͘͜͜͜͡͝ѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠ (̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ e̖͇̜̳̲͍̔̅̆̒̍̓͞ ê̷͔̻̜͔̄̑̉̏̌̑̒̈́̕͜͜ͅ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ —͉̯͓͌̿͆́͋̄͜͟͡ z̸̡̛͉͖̠̦̬̺̓̈́͛͒͜h̸͙̘̫̻̠͕̺̥̅̂̐̎̌̍̈́͂͘͝ ž̷̧̠̤̖̗͎͚̖͖̘̈́̂̿̾̊̾͠ z̵͙̜͚͚͍̤̖͓͎̆̇̀͛̌͋͋̕͠͠h̸̡̢̨͉̼͔̝̋̏̿͑̓͑͟ͅ′̡̡̟̬͍̿̀͋͗͆̿͘′̲̺̣̫̻̥̤̝̯̬͗͂̾̒̇̿̎̾ ẑ̛͚͚̼̳̠͖̋̒̊̀́ z̥̫̠̯͚̭͓̪̱̆́͗̈͛̄͜h̶̡̤̺͈͙̟͆̈́̇́̈́̀′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅu̸̼͔̰̯̖̐͆͗̏͐̾͡ͅ ẑ̷̛̲̭͉̪̜̯͌̍̅̿́͢͠ͅ°̵̺̹̫̹͙͇͆̉̋̎̇̿͂͟͞͝ z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ′͍̠̤͉͓̦̦̦̻́͒͐͌̆̀͡ͅ ž̴͚̳̞̙͙͖̙͈̏̅̾͋͊͋̈̋͗͢′̨̟͉͔͙̐̅̓̃̀̕͟͠ z̦̬̠̳̻̃͂͋̎́̔͢͢͝ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝ ḯ̻̖̮̦͕͊̇͋̂͂͜͝ĭ̙̟͕͈̪̝̤͎̓̅̀̔̎̊̀̐̅͂͢͜ j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆ k̵̡̬͔̬̩͇̤͐͊̅͆̃ͅ —̷̢̛̜̬͔̖̳͆̇̐̀̚͢͠ k̶̛̭̮̝̹̹̬͌̈́͋͜͟͞u̵̧̠̠͍͖͗́̆̉̄͘ k̸͎͈̣̦͌̂̏͋̊͒͢͡°̴̧̰̮̺̮̙̲̯̤̠̊̊̂̿̎̓͋ ķ̘͔̤̠̪̟̮͌̌͑̎̈̊̕′̳̱̞̥͕̥̀̄̽̏̂́̾͞′̴̧̱̖͉̗̾̏͆̾̍͆͌͞͠ͅ q̶̨̩̝̞͙͛̓̒͋͒ ķ̮̠͕̹̩̤̀̉̄̎̕͘̕͢′̨̧͖͇͈̳̣͆̑̑͂́͊͜͡′̥̳̥̦͈̫́̄́̍̔̽̑͞ứ̵͈͔̭͍͓̲͔͙͚́̆̊̏̚͠͡ q̵̢̛̼̥̭̪̼̆͋̂̑̅̚͠°͖̹̲̻̣͍̹͇́͋́̒̓͆͂̆͛͗ k̴̡̺̙͕͉̯̖̯͎͒̏̊͡͝ḣ̷̨̯̜̠̻̿͊͑̎̀͟ č̵̡̨̘͖̥͕͉̔̅̀̅͡͠′̵̸̡̡̛̳̹̰̰̲̣̲̞͕̝͇̟̩̀̀̍̈́̃̊̓̍̓̉̃̉̋͠ ḱ̵̛̛̻̗̻͉͓̀͒͞ḣ̷̭̮̰̙̞̜͎͔̪̜̔̂̈́̾̌̋̋̈́͝u̧̦̲͍̦̯̱̐̅̃̕͞ ḳ̶̡͖̮̖̹̻͐́́̀̔̇̄̑͑͢͝ͅ°̢̢̼̜͍͇͂͗͗̾̒̚ ḽ͉̰̱͈̳̺̰̮̊̍̐̏͆̌̐̕̚ l̵̨̡̛̻̻̺͚͚̤̯̺̈́̊̒̍͛͒͠ l̩̤̬̰̹̘̔̾̍̓̔̚͟′̡̭̖̼̙̩̼͆͑̃͆͆̏̽̄̾̕′̷̢͚͍̟̠͍̖̐́͋̿̓̍͂̆̍ ł̰̬̩̪̥̘̜͙̾̃͗̎̆̓̄̕͜͝͡ l̨̢̥͉̎̍̅̐̚͜͟ḣ̨̘̭̼̜͇̹͓̹̊̀̽͛̎̒̚͞͝ ḷ̡͕͍͎̥̣͚̣̞͉̐̿̇̃̄͊͂̅͘q̨̢͓̣̦̦͙̤́̃̀́̀̑̆w̵͖̥͓͚̽̾͒̀͒͘ͅͅ ḉ̡̣̮̜̗͖̞͕̊̌̽̅͌͞͝,̵̨̬̲͓̯̝͉͋̔̓͑́̂̑ķ̡̗̖̠͓͛͒̾̕͘͡ (̶̨̡̠͈̝̳̫͉͗̆̌͗̽̚2̪̮̥̣̩͔̺͚̗͗̀͛̐͗̽̍ͅ.̷̡̧̥͉̺̺͖͖̭̀̅̾͊̕͝2̧̤̭̹͈͈̭̌̔̀̃͐͟͞͞)̸̢̳͕̦̰̤̲̄̈̊́̒͝ч̨̳̭͍̬̞͍̹̏̂̀͂̿̀͠͠Ӏ̡̫̟̖̲́̐͋͑͡k̙̦̜̖͎̯͕̄̿́̇͐͌̈́̔͠ k̸̢͚͕̔̒̍͛̈̋͐͐͜͠͡ͅư̴̢̫͈̘̣̖̰̝̂̇͗̈́̾̀́͜͞͝ͅ ž̧̧̮̲̘̩̽̿̇̅̔͘͟′̺̞͓̥̳̰̾̎́̓͞ͅ′͈̳͇͙͈͈̠͐̀̇̑̍̅̾̎͞ͅư̶̡̤͓͈̪͉̠̭̣̈̽̾͋͐̇̉͟͠͞ ž̫̝̦̘̺̦̭̏̇̓͒͢͝͠′͈̰̺̖̪̦̞̀̔̇̓͋̃̏͜͡͠i̢̧̨̖̇̇̀̀̇͟͟͜͠u̸̡̧̫̱͕͔̱̥͍̬͈̩͇̒͋̓̏͐̈̆́͂͒͊̆̕̕̕͟͡͠͡͡ —̝̣̜͙̝̳̰̥̖̅̈́͑̀̾́̊̕͘͞ Є̶̨̗̠̳̜̪̯̬̜̰̒͋̄͋̀ǐ̴̡̪͖̰̜͉͒̎̌̌͞͠ą̵̴̧̛̠̞͈̳̗̥̳̘̪̻͗̑͑́́͆̽̆͊̍̎̂͘̚͘͡͡ —̤̫̖̣̪̫̿͊̾̾̇̈̅͡ ḣ̵̰̜̟̙͓͕̗̣͒͒̽͐̓̀̍̂͝ ʾ̷̦̥̘̹̻̬̯̼͈͐̈̄͌̕̚͝ ḩ̨̮͇̲̇̓̋́́̒͑͢͠ú̵̧͇͇͓̳̩̊̂̋̾́̽͘͟͢ ʾ̷̺̜͈̬̠͍͇͉͓͇̇̆͆̒͝͡°̶̡̢̢̛̱̲̠̮̭̫͐̎̈́̔̏̀̚ͅk̸̰̗͙͉͈̰̓̋̽̉̽̉͌̀̕′̛͉͕̹̣̖̄͒́̄͂̇̾́̾′͉͖̪̞̖̦͂̔͑͂̒̇͊̍͜͢ k̴̨͚̮̠̞̞̙̺͎̓̓̓̇͝′̧̼̦̜̥̞̮̖͑̇͒̿̋̀̀̓͞͡′̶̨͔̼̞̜͖̲̘̀͐͆͝͞u̱̠̗̰̜̾͊̂͟͝͡ k̛̗̮̝̠̠͙̉͠͠͝‡̵̪̞̣̗͕̱̙͔̦̀̎̓̃̀̕͜ ḵ̵͍̝̬͗̏͗͛̎̽̎̕͟‡̶̧̱̠͍̩̗͑͌̊̃̄̊̀̓̕̕͟u̗͔͈͔̤͕̓̓̐̏̍͛͌̋̂̏͜ͅ l̘̣̠̣͙̪̦̒̓͒̐͌̾ǫ̵̘̺̤̹͇͖̒̍͆͒̈́̋̈̀̄͊͢w̨̠͔͕̠͕͔͕͛͊̎̎̈̾̐̕͞͠a͖̥̜̯͉͆́̎̕͡n̲͕̞̟̺̝̠̓̍̓̔̐ṣ̷̞̰̜̜̰̌͂̒͗̒̃͢͢͢ʹ̨̹͙̼͚͉̩̗͛͆̐̓̉́ͅШ̷̮͚̥̲̘̫̯̰̀̍̒̏̊͆̈́͘͢ͅӀ̵̧̬̮͙̥̮͓̆̈̅̈́͗͞у̵̘͔̺̳̪͓̞̮̯̐͌̋͋̃̔͠ш̵̡̡͎̣͓̝͎̯̰͆͂̂̓̌͘͠Ӏ̵̨̨̧̥͕̙͖̇̅̀̍͑̋͐̕͡Ꙗ Ꙑ)4 ЧӀхуфg ɣ gu g° g′′ ġ g′′u ġ° d d dzh ǯ′ dz ʒ dzu ʒ°hu Єwダh′′ラazŭбоукꙑbukyглаголи (glagoli) e e ë — zh ž zh′′ ẑ zh′′u ẑ° zh′ ž′ z z iĭ j k — ku k° k′′ q k′′u q° kḣ č′̣ kḣu ḳ° l l l′′ ł lḣ ḷqw ḉ,ķ (2.2)чӀk ku ž′′u ž′iu͡ — Єia͡ — ḣ ʾ ḣu ʾ°k′′ k′′u k‡ k‡u lowanšʹШӀушӀу5ꙑꙗxє, ѕѣлозč̣емлꙗ, or just for short エ̨͉̦̣̪̌̊̉̈́̄̍̇͌ͅє̯͇̦̠̞̫́̒̆̐͌̏͛̒͝m̷̟̙̦̬͙̥͕̭̠̅͑̽͘͟͠ê̟̠̼͎̖̞̥̅̎̔͂̂͌̿͒ͅŗ̴̱̦͉̟̾̋̍̐̀͛̅͑̚ȩ͉̠̪̲̘͙̩̼̋̓̏̍̌̉̇̊͘͡ḷ̷͙̼̮̜̇̒̃̇͌̓̎̓ḑ̴̣̣͇̜̭̬̋̀͑͂̇͠͠ͅh̶͇̱̲̣̖̤͓̭͆̽̿̓̌̕ȧ̷̛̙̣͔̭͕̩̐̐̓͛̍̃̇͘͜ş̴̴͙̻̗̖̥̠̳̌̇̏̀̀͂͑̒͒͗̍́̔͌͘͢͜͞͡ͅ c̬̼̘̘̎̄́̿͐̒̅͘͝͞ͅ メ̡͎̯̬̥̯̾̉̈́̋̋̿̚͞r̵̺̹̰̪̈́̀̄̓̋̈͗̑͜͠͝ţ̛̖̮̼͈̮͌́́̇͂̎͆̂̚s̷̷̡̧͉̰͚͙̹̼͔͇̞͕͇̪̺͊̆̐̀̌̽͊̓̐̑́̏̇͐̐͜͡͡ͅủ͎̥͓̗̰̖͆̀͊͑̒̄́̎͐͜д̸̡̛̥̙̟̖̦̹̝́͒̊̄͒̓̓̉о̴̺̫̮̬̭̻̒̀͒̐̆̔̀͘̕͘б̹͇̹̫̝̀͐̍͌̄͘р̶̨̼̝̦̻̍͋͂̊̉͢о͇̝̬̼͛͒̀̓͌ͅ а̧̧̰̽̈̈͆͛͘͜ͅз̷̨̬̳͇̪̣́͌̉̀͋̄͠ъ̡͈̤̟̣̎̃͗͟͜͞͝;̴̩̮͈̟̗̙̤̬̭͍̓̾̃̔̂̚ ḩ̷͇̭̣̖̪̘̺̣́͆͗̐̄͆̌̋̄͘u̙͓͕̟̎̋̂̉̉̉̏̔ͅ Є̖̘̹̬̙͇̙̳̇̋̀͊͒͠͡w̡͖͚̝̩͌̒̽́̋̒͠͞ダ̛͙̣̰̳̯͌́͊̂͘ĥ̷̘̺̗͚͙͕̹͉̻͚̔̎͌͑̊̉̌͞′̴̢̧̱̗̮̞͓̱̇̌͌̓͡͞ͅͅ′̥̤̞͍̮̋̈́̽͛̆͟͞ラ̨̡̛̟̹͇̹̅͆̐̃͐́͆́͜͢͞ȃ̢̛̝̺̠͂̾̅́̚͘͜z̶͇̫̠̘̘̻̦̎̅̽͋̿̄͘͡ŭ̼̙̖̟̣͎̥̠̍̆́̀̎̎̿̚͢͢͝б̹̭̹̟͍̰̱̜̫̲̈́͒̓͐́̐́о̡̼̲̲̘͛̀̃͋͊̅̃͗̎͠у̛̻̯̜͓̔̏͋̍͜͢к̸̡̡̨̣͔̯͇͚̣͎̍͑̐͌̒̕̕͘ꙑ̸̢̡̫̙͍̰͙̮̤̅̂̊̀̀̕͠b̨̡̼͖̤͛̂̑̎̐̇͞ų̴͔̬͇͓͌͆͛͋͛̀̈́̌͟͢͠ͅͅk̴͉̟̥̘͔̻̐̿̾͌́̋͋͘͠ͅͅͅỳ̨͎̫̪̀̔̀̊͋͟͟͝г̞̪̜̪͍͉̫͕̤̀̍͌͋̋̏̏͘͡͝ͅл̴̡̪̖͉͍̩̅̆̎̆̉̈́̀͘а̦̳̺̮͎̤̲̃́̔̊̽̎̌͜ͅͅг̶̧̢̨̛͈̞͇̯͔̿͌̇͟͠ͅо̶̡̭̙̰̟̬̎̌́̆̓̏͟л͎̬̪̜̙̥̒̐̽̈̇͜͟͢и̴̝̪͇̺̮̹̠͍̩̿̍̎̓́̃́̿ (͍̙̯̯̙̫͓́͊̂̋̉̿̕̕̕ͅg̢̧̨̨̛̲̱͈̻̤̩̃̄̐̏̃̇̄̚̕ļ̶̧̨̪̜͓͓̜̑̿͒̆̿̔͌̚a͖̝̠̣̐͋̓̌̏͂ͅg̱̝͙̖̳̜̰̠͇̞̀̀̂͊̂͒̈́͋̒o̭̗̻͎̎̄̃͒͌̕͢͝l̢̜̬̫̜͇̗̎̓͂̎̉͐́͝i̵͙̰͈͔̰̭̪͌̀̔̒͐͜)̻̯̹̺̳̋̎̄̃̌͌́͆̽̚,̛̝̬̭̞͉̱̬̘̘̓̓͗̎̿̕)̴̢̮̤̦̹̟̙̼͖̱͗̎̊̔̀̅̑̓̓č̺̘̝̟͒̊̑̃͆͊͛͟͝°̷̨̳̥͔̋̒̔̽̓͛͜͢͟h̪̖̯͋̇͆̄̚͘͢͡ͅ x̧̞͙̺̼̄̔̋͗̉͘̚͠ͅ h̵̨͇͎͕̤̦̜͋̂̓̔̄͘͢͝u̵͙̤͕͕̼̱̹̓̑͑̃̏̏̚x̝͖͔̹̺̰͛̌͗͐͂̉͂͘w̢̳͙̼̘̺͉̮͋̅͒̌̿͢ h͓̝̼̻͖͛̇͑̅̐̃̿͟′̛͖̹̺̘͔̻̂̃̈͐̂̊̍͛̒′̢͇͓̮̗̠̣̣̠̿̾͒͌̾͛͗ ḩ̷̧̧̧̨̥͍̹̩͔͙̄̇̓̇́̎̄ ḣ̴̛̲̲͔̮͍̀͒͒͌̀͗̾͘′͖̮̥̦͕͕̰̦̐̓̂̀̉̽̐͗̑̽′̛̩̱̱̟̰̭̇͆̍͒͂̋͐̄͜ư̢̠̯̺͙̌̀͋͑ ḩ̷͔͇̹̲͐́̋͐̀̒̕ͅw̡̤̳͖̪̭̖̳̪̲̏͊͂͂̆̿̔ h̷̢̡͈̰̭̝͗͊͛̄̌̾̾͒̚͡′̴̢̳̦͉̫̠̟̬̍͗̃̂̒̈͢ h̷̤̬̱̮͙͖̥̳̥͍͐̑̈́͌͑̊̄͂̍̀ t̸̼̗̦̩̯͎̒̄͐̑͋̕ͅš̴̵̛̱͍̞̜͓̯̻̮̲̗̤͙̬̥̬̯̲͔́̃͊̔̈́̊͋͌́̂͒̅̀̕͡͠ͅͅḣ̸͖͓̹̪̱͙͙̒̾̿̿̌̏͝ c̮̲͕̼̣͈̱̭̖̲̾̔͂͋͌̈́̄̎͐̓̿͘͞͠͡͞ͅ ç̶̮̦̭͉̙͇̮̀̍̈̈́͆͞h̘̼̙͉͉̪͍͕̮͂͗̆͟͡͠ č̢͎͈̘̲̖̯̺͇͂͗̋̌́̄͛̿̕͘ʹ̴̧̡̗̻̭͗͋̓͒̀͝ š̶̨̢̺̟̩̝̫͈͛́̿̃͘͘͡ š̡̧̧̟̫̼͎̭͂̽͒̒̾̄̕ͅ š̺̹̲̝͔͆̿̆̓͊̾̕̕′̶̢̨͙̺̪͉̜̩͍̫̊̓̆̕͠͡͠′̸̮͓̠̯͇̫̳̿̽̒̐̑͌̒̚ s̵̶̢̲̘̹̜̺͍͓͇̗̦̀͊͛̾̓̋̄̐̀̅̋̓̌̾̈́̆͊͟͟͜͠ͅ š͈̰̖̟̾̓̇͛̉̕͢͢′̛̥̖̭͉̥̯̹̳̝̮̓͗͑̌́͂͒̊′͈͇̘̙̹̑͒̋̽̆͂́͜͝u̯̘̜̠͚͓͚̔̉͑̉̌̌ s̢̨̝̜͕͇͕̺̯͂́̏̇͑͢͝͞͠w̸̷̡̢̥͚͖̲̯͕͖̗̪͖̜͕̻̉͑̊͛̓̒̿͒́̄̽̉̎͑̎͛͋̅̈͝͠ š̷̫̱̳̙̠̩̟͒̄̋̐͛͞‡͇͎̹̼̈̈́̑̽́͊͐̚͟͝ ş̵̸̨̛̠͚̟̗͎̮͕͉̹̓̀̔̇̄͌̄̂́̇͐͋̅̾̀̌̚̕̕̕͟͢͟͜ͅͅi̤̺̦̇̈́̃͌̈́̎̑̿̚͢͟͡ü̴̧̨̯͚͍̱̘̮͖̣͚̺̣͍͚͈͈̦̈̿͑̈́͗̐̏̀̈́̉́̽͗͒͡ͅ —̷̰̮̳̻͈͈́̊̅̊̆̓͘ i̵̢̨͈̻̦̭͖̲͐̃͌͒͐͢͢a̶̧̧̛̫̯̤̥̙̗͙̰̙̺̩͔̗̤̭̔̒̇̀̄̾̾̿͜͢͠͡ —̧̛̦̟̬͕̺͍̠͑͌̓͐̒͒̕ ḣ̢̛̠̤̪̩̦͍͈̐̐̓͛̉̈̿̚͝ ʾ̧̛̻͍͎͉̮̫̘̗̗̔͑͂̋͑͗̔ ḩ̶̟͔̬͉̇͌̓̒̽̓͋͒̿̚͜u̷̢̯̭̺̗͖̺̗̓͗̓̅̂͆͒͢ͅ ʾ̧̱̦̩͉̘͙̍͑̾̂͂̎̕°̶̲̪̖̺̩͚̊͊̑͊̕͜͠š̨̲̝͓͈̞̞̙̫̋̾̀̀̊̒͛͝‡̶̳͉͎̳̲͛͊̃̅̈̓̕͘̚ừ̴̼̠̲̹̟̭͂́̏̾̐͂̃̉͟ ş̴̫͚͇͎͈̏̊͊͘͠w̷̧͓̺̫͎̼͎̟͈̠̘͍͉͈̹̾͋̆͑̀͒͗͋̂̄͛̈́̊̎͆̓ͅ ŝ̞̺̰͚̩̳̞̯̈̑̆͗̋͐̈́͐̕ ş̮͔̦̥̟̦͎́̿̓̀͛͗̊͟c̶͚͔̙͚̳̝̣̽̔͐̂̈̃̽͘̕͢͠h̴̪̪͔͉̙̦͈̪̻̹̏͒̿̇̌̀͝′̧̠̫̼̗̦̳̱͇̏̏̆̾̍̾́̅̚͟′̴̣̫͓̻̘̙͗̌̐̌͊̔͘ č͔͔͖͇͖͓́̆̆͌͝ c͙̝̞͍̣̖̱̅̑̔̄̀̎̂ḧ̷͉͙͕̦̪̟̹́̌̒͐̐́͜͞ͅḩ͖̬̮̯͔̭͇̲̇́̎̃̐͂̎̕͞ͅ č̷̡̡͚̣̖͖͎͔͓̣̺̮̟̗̼͕̼͉͙͐̋̊̅̃̎́̾̃̓̈͛͘ͅ s̶̱̳͉̘̪̹̮͊̂̃̇͗͐h̵̠͙̝͎͎̯̹̞̳̔́̽̍͝ š̥̻̗͇̩̞̦̊̃͊͌̈̿́̄̚͟ s̢͕͔̥͍͍̥͍̱̘̿͒̂̊̈̏͂̔͛̉h̛̟͓̮̮̞̮͕͖͖̝͗̀̇̽̓̍̽͝′̷̧̛̤̯̞̊͊̒́̓̚͠͡ͅ′̭̳̙̟̟̞̟̊́̀̉̊̇̏̔͞͞ͅ ŝ̴̨͎̞͍̽̍͗͗̓̀̚͜͡͠ͅ s̴̨̧͔̟̰̥̦̰̟͑̿̽̀͂̕͟h̢͉̭̘͈̖͙̄͌̏̉͘͜͞ͅ′̧͇̥̮̘̻̮̠̩̊̍̍͗̒̏́̿͘′̷͇̪͈̣̬̠̲͛̈̅͒̋́̒̾̉́ū̼͉̖̻̩̞̦͓͗͌̒̀̓́͑͟͡ ŝ̨̛͕̜̳̖͙̂̾͂̎͗̏͂̐͘°̶̢̨̹͕͇̲̖̖͇̓̌̈́͘͘͝ͅx̸̟̗͈̳͙̯̣̣̅̓͐̊͘ s̛̩̮͕̲̝̙͉̐̏͛́̍̀̓̏͢͢h̛̬͎͚͉̻̣͍͊͂̍̉́̕͘͠ḣ̜͍̳͇̑͋̇̄́͟͜ ş̴̢̨̣͍̫̺̩̯̯̑̐͌̀͌̅̂̑̀̌͛̏̓̏̋͘͘͜͞h̦̼̜͈͔́̓̿̑͝′̶̝̝̝̭̫̫͊̄͊͗͗͡′̰̲͉̳͓͇̪͕̬̖̓̋͋̑͐̎͗̚ —̺͚̖̖̰̭̮̺͋̆̑͗̿͆͆͘ y̸̮̣͓̦̳͖̼̱͂́̈̾̀͐̀͝ ǝ̴̞̘̪͇̻̗̭̺͉͑̋̍̿͒̕͜ x̸̨̥̯͍͎͂͌̄͆̐͠ ḩ̠̰͎̖͚͇̾͛̓̀̒̕͠ǔ̯̬͉̪͚̩́̌̿͋̒͛̉̌͘ͅ Є̥̪̻̤͓̤͓̂̑̽̄̐͜ͅw̴̠̮̻͈͍͇̟̬͑̄̏́͜͜͞͞͞͠ダ̭͓͕̘̞͇̮̾̀͐͌͂͗͟h̪̲̹̖̫̹̿͛̽͂̈́̉͐͠͠′̷̼͍̯͖̅̀̾́̂̾͊͞͠ͅ′̢̫̗̗̟̝̽͗͌̑̓ ḩ͔͉̟̖̣̬̩̩̿́̑̄̏̇̔̇̾̿͜͜ h̵̨̳͖̙͕̔͆̂̉͗′̻͓̭̘̆̇̀͌͞ͅ′̷̯͎̜̬̠͈̟̟̹͉͑̾͂̊̀̓̆͡u̱̖̯͚͕̹̙͊̓̊̋̀͑̆̚͜͝ ḩ̸̨̮͈̖̹̜̍̑͑̂̃̓У̧̧̨̩̤̳̰̩̖̀̈́̋̄͋͝w̡̨̩̞̦̲͚̺̳͆͗͌̑̍̚͟ h̷̜̦͉͈̪̅̃̎͂́′̴̨̝̖̤̀̈́̀̓͗̌̈͢͠ ḧ̛͉̝̹͓̥̗́̅̊̔͛̔͗̕͢͟͝ s̨̧̩̠̰̹̔̉̈́̓͆̌̍ͅḩ̸̝͚͈̼̒̂́͌͘͜͞͠͞ḩ̴̥̗̰̘̲̤͔̇̄͛̍͊̑́̕͡u̢̡͖͖̼̺͎̠͍̾̉̽͛̈́̅ ŝ̨͔͖̥̺̏͑̇͘̕͜͠°̢̳͉̪͈̣͉̹̖̺͓̖͉̊͒͋̌̎͗̏̃̊̾̑̃̄͟͜͟͠͝͡ s͉̱̩̗̹̩̗̠̐͗͗͐̃̕͡h̵̗̭̠̺̹̩̳̬̊̽̆́͋͂̊̂̈́̽ͅͅç̯̯͔͍͍̥͍͉̊̀͆̑̿̚ͅḩ̷̛̥̹̤͙̲͇̯̎̾͒͛̈͊͌͜ š̷͎̞̱̗̭̗̻͚̏̀͗̂͑͘̚͘͜͟͡ʹ̶̡̡̱̥͔̹̋͒̾͂̄͐̍̿̍̍͜Ш͖͎̯͚̠̻̞̝̭̓̾͑̓͂̅̊̽̿͌͜Ӏ̥̩̖̦͙̬̫͈̺̬̓̔͌̔͐͝͞у̸̛̙̦̼͍̦̞͎̏̎͒̓́͌͢͜ш̸̪̘̯̟͔͚̪̜̘̌̃̄̅̉̔́͆̀͠Ӏ̷͚͖̝̔̌͗͋̌͘͜͢у̘̳͔̹̠̭͚̞̮̑̏̇̈̓͋̃͡̷̛̮̤̳̥̰̻̙̐̐̀̌̎̾̓̌͞5̵̛͖͍͉̖͕̹͔̟̮̍̽̀̄̅͌͢ꙑ̨̛̼͕̮̗̹̘̯̄̿̽͞ꙗ̝̻̬̙̙͔͉̦̽̀́́̓̀͌͜͠͠͞x̨̥̻͖̝͉̖̗̹̼͆̒̄͛̿̀̕͡͞є͇̝̱̩̹̺̊͌̉͂̌͡͝͝,̠̱͎̬̪̗̔̑̽̽̔̒̎͝͞͝ͅ ѕ̢̢̺͇̤͕̫͖̠̏̾̽̎̔͂̈́̓͢ѣ̴̡̧͖͇͕͓̰̜̣̔́̐̓̆̾̋̽̇͞л̸̨̧̼̲̩̃́̽͊͆͂͘͜о̳̪̺͓̟̮̜͑̈́̄͋̐͘͢з̧͕̘͕͔͈̰̗͙̙͗̈́̽͌͂͛͘ç̸̛͎̤͕̗̻̫͎̩̣̭̪̮̠̙̰̼̌̂̀̓̈̎̑̐͆̈̿̌̏͘͢͡͝ͅе͙̙̟̼̟̂̎̆̈̋́̓͟м͓̗̺̘̩̝̫̞̹̹͛̑͌̆̌̒͘л̧̳̟̟͙͎̰̰̆̊̅̎͋̓͜ꙗ̴̩̪̩̹͈̮͉̲͇͐͛͌͘͠ͅt̴̢̛̰̪̣̣̯̹̟̗͗͌̒̋̓̆̾͋̅s̷̡̡̞̫̬̳̣̩͓̼̼͖̙͚̫̜͐̏͆̊͌̑͐̎͐̓̕͘͡͡͝͠ḩ̸̛̫̬͚͔͕̺̖̰̇͊̂̏͆̍
̷̨̜̯͓̭͎͓͙͑̎̈́͐̆̓̿̈́エ̨͉̦̣̪̌̊̉̈́̄̍̇͌ͅє̯͇̦̠̞̫́̒̆̐͌̏͛̒͝m̷̟̙̦̬͙̥͕̭̠̅͑̽͘͟͠ê̟̠̼͎̖̞̥̅̎̔͂̂͌̿͒ͅŗ̴̱̦͉̟̾̋̍̐̀͛̅͑̚ȩ͉̠̪̲̘͙̩̼̋̓̏̍̌̉̇̊͘͡ḷ̷͙̼̮̜̇̒̃̇͌̓̎̓ḑ̴̣̣͇̜̭̬̋̀͑͂̇͠͠ͅh̶͇̱̲̣̖̤͓̭͆̽̿̓̌̕ȧ̷̛̙̣͔̭͕̩̐̐̓͛̍̃̇͘͜ş̴̴͙̻̗̖̥̠̳̌̇̏̀̀͂͑̒͒͗̍́̔͌͘͢͜͞͡ͅ c̬̼̘̘̎̄́̿͐̒̅͘͝͞ͅ メ̡͎̯̬̥̯̾̉̈́̋̋̿̚͞r̵̺̹̰̪̈́̀̄̓̋̈͗̑͜͠͝ţ̛̖̮̼͈̮͌́́̇͂̎͆̂̚s̷̷̡̧͉̰͚͙̹̼͔͇̞͕͇̪̺͊̆̐̀̌̽͊̓̐̑́̏̇͐̐͜͡͡ͅủ͎̥͓̗̰̖͆̀͊͑̒̄́̎͐͜д̸̡̛̥̙̟̖̦̹̝́͒̊̄͒̓̓̉о̴̺̫̮̬̭̻̒̀͒̐̆̔̀͘̕͘б̹͇̹̫̝̀͐̍͌̄͘р̶̨̼̝̦̻̍͋͂̊̉͢о͇̝̬̼͛͒̀̓͌ͅ а̧̧̰̽̈̈͆͛͘͜ͅз̷̨̬̳͇̪̣́͌̉̀͋̄͠ъ̡͈̤̟̣̎̃͗͟͜͞͝;̴̩̮͈̟̗̙̤̬̭͍̓̾̃̔̂̚ ḩ̷͇̭̣̖̪̘̺̣́͆͗̐̄͆̌̋̄͘u̙͓͕̟̎̋̂̉̉̉̏̔ͅ Є̖̘̹̬̙͇̙̳̇̋̀͊͒͠͡w̡͖͚̝̩͌̒̽́̋̒͠͞ダ̛͙̣̰̳̯͌́͊̂͘ĥ̷̘̺̗͚͙͕̹͉̻͚̔̎͌͑̊̉̌͞′̴̢̧̱̗̮̞͓̱̇̌͌̓͡͞ͅͅ′̥̤̞͍̮̋̈́̽͛̆͟͞ラ̨̡̛̟̹͇̹̅͆̐̃͐́͆́͜͢͞ȃ̢̛̝̺̠͂̾̅́̚͘͜z̶͇̫̠̘̘̻̦̎̅̽͋̿̄͘͡ŭ̼̙̖̟̣͎̥̠̍̆́̀̎̎̿̚͢͢͝б̹̭̹̟͍̰̱̜̫̲̈́͒̓͐́̐́о̡̼̲̲̘͛̀̃͋͊̅̃͗̎͠у̛̻̯̜͓̔̏͋̍͜͢к̸̡̡̨̣͔̯͇͚̣͎̍͑̐͌̒̕̕͘ꙑ̸̢̡̫̙͍̰͙̮̤̅̂̊̀̀̕͠b̨̡̼͖̤͛̂̑̎̐̇͞ų̴͔̬͇͓͌͆͛͋͛̀̈́̌͟͢͠ͅͅk̴͉̟̥̘͔̻̐̿̾͌́̋͋͘͠ͅͅͅỳ̨͎̫̪̀̔̀̊͋͟͟͝г̞̪̜̪͍͉̫͕̤̀̍͌͋̋̏̏͘͡͝ͅл̴̡̪̖͉͍̩̅̆̎̆̉̈́̀͘а̦̳̺̮͎̤̲̃́̔̊̽̎̌͜ͅͅг̶̧̢̨̛͈̞͇̯͔̿͌̇͟͠ͅо̶̡̭̙̰̟̬̎̌́̆̓̏͟л͎̬̪̜̙̥̒̐̽̈̇͜͟͢и̴̝̪͇̺̮̹̠͍̩̿̍̎̓́̃́̿ (͍̙̯̯̙̫͓́͊̂̋̉̿̕̕̕ͅg̢̧̨̨̛̲̱͈̻̤̩̃̄̐̏̃̇̄̚̕ļ̶̧̨̪̜͓͓̜̑̿͒̆̿̔͌̚a͖̝̠̣̐͋̓̌̏͂ͅg̱̝͙̖̳̜̰̠͇̞̀̀̂͊̂͒̈́͋̒o̭̗̻͎̎̄̃͒͌̕͢͝l̢̜̬̫̜͇̗̎̓͂̎̉͐́͝i̵͙̰͈͔̰̭̪͌̀̔̒͐͜)̻̯̹̺̳̋̎̄̃̌͌́͆̽̚,̛̝̬̭̞͉̱̬̘̘̓̓͗̎̿̕)̴̢̮̤̦̹̟̙̼͖̱͗̎̊̔̀̅̑̓̓č̺̘̝̟͒̊̑̃͆͊͛͟͝°̷̨̳̥͔̋̒̔̽̓͛͜͢͟h̪̖̯͋̇͆̄̚͘͢͡ͅ x̧̞͙̺̼̄̔̋͗̉͘̚͠ͅ h̵̨͇͎͕̤̦̜͋̂̓̔̄͘͢͝u̵͙̤͕͕̼̱̹̓̑͑̃̏̏̚x̝͖͔̹̺̰͛̌͗͐͂̉͂͘w̢̳͙̼̘̺͉̮͋̅͒̌̿͢ h͓̝̼̻͖͛̇͑̅̐̃̿͟′̛͖̹̺̘͔̻̂̃̈͐̂̊̍͛̒′̢͇͓̮̗̠̣̣̠̿̾͒͌̾͛͗ ḩ̷̧̧̧̨̥͍̹̩͔͙̄̇̓̇́̎̄ ḣ̴̛̲̲͔̮͍̀͒͒͌̀͗̾͘′͖̮̥̦͕͕̰̦̐̓̂̀̉̽̐͗̑̽′̛̩̱̱̟̰̭̇͆̍͒͂̋͐̄͜ư̢̠̯̺͙̌̀͋͑ ḩ̷͔͇̹̲͐́̋͐̀̒̕ͅw̡̤̳͖̪̭̖̳̪̲̏͊͂͂̆̿̔ h̷̢̡͈̰̭̝͗͊͛̄̌̾̾͒̚͡′̴̢̳̦͉̫̠̟̬̍͗̃̂̒̈͢ h̷̤̬̱̮͙͖̥̳̥͍͐̑̈́͌͑̊̄͂̍̀ t̸̼̗̦̩̯͎̒̄͐̑͋̕ͅš̴̵̛̱͍̞̜͓̯̻̮̲̗̤͙̬̥̬̯̲͔́̃͊̔̈́̊͋͌́̂͒̅̀̕͡͠ͅͅḣ̸͖͓̹̪̱͙͙̒̾̿̿̌̏͝ c̮̲͕̼̣͈̱̭̖̲̾̔͂͋͌̈́̄̎͐̓̿͘͞͠͡͞ͅ ç̶̮̦̭͉̙͇̮̀̍̈̈́͆͞h̘̼̙͉͉̪͍͕̮͂͗̆͟͡͠ č̢͎͈̘̲̖̯̺͇͂͗̋̌́̄͛̿̕͘ʹ̴̧̡̗̻̭͗͋̓͒̀͝ š̶̨̢̺̟̩̝̫͈͛́̿̃͘͘͡ š̡̧̧̟̫̼͎̭͂̽͒̒̾̄̕ͅ š̺̹̲̝͔͆̿̆̓͊̾̕̕′̶̢̨͙̺̪͉̜̩͍̫̊̓̆̕͠͡͠′̸̮͓̠̯͇̫̳̿̽̒̐̑͌̒̚ s̵̶̢̲̘̹̜̺͍͓͇̗̦̀͊͛̾̓̋̄̐̀̅̋̓̌̾̈́̆͊͟͟͜͠ͅ š͈̰̖̟̾̓̇͛̉̕͢͢′̛̥̖̭͉̥̯̹̳̝̮̓͗͑̌́͂͒̊′͈͇̘̙̹̑͒̋̽̆͂́͜͝u̯̘̜̠͚͓͚̔̉͑̉̌̌ s̢̨̝̜͕͇͕̺̯͂́̏̇͑͢͝͞͠w̸̷̡̢̥͚͖̲̯͕͖̗̪͖̜͕̻̉͑̊͛̓̒̿͒́̄̽̉̎͑̎͛͋̅̈͝͠ š̷̫̱̳̙̠̩̟͒̄̋̐͛͞‡͇͎̹̼̈̈́̑̽́͊͐̚͟͝ ş̵̸̨̛̠͚̟̗͎̮͕͉̹̓̀̔̇̄͌̄̂́̇͐͋̅̾̀̌̚̕̕̕͟͢͟͜ͅͅi̤̺̦̇̈́̃͌̈́̎̑̿̚͢͟͡ü̴̧̨̯͚͍̱̘̮͖̣͚̺̣͍͚͈͈̦̈̿͑̈́͗̐̏̀̈́̉́̽͗͒͡ͅ —̷̰̮̳̻͈͈́̊̅̊̆̓͘ i̵̢̨͈̻̦̭͖̲͐̃͌͒͐͢͢a̶̧̧̛̫̯̤̥̙̗͙̰̙̺̩͔̗̤̭̔̒̇̀̄̾̾̿͜͢͠͡ —̧̛̦̟̬͕̺͍̠͑͌̓͐̒͒̕ ḣ̢̛̠̤̪̩̦͍͈̐̐̓͛̉̈̿̚͝ ʾ̧̛̻͍͎͉̮̫̘̗̗̔͑͂̋͑͗̔ ḩ̶̟͔̬͉̇͌̓̒̽̓͋͒̿̚͜u̷̢̯̭̺̗͖̺̗̓͗̓̅̂͆͒͢ͅ ʾ̧̱̦̩͉̘͙̍͑̾̂͂̎̕°̶̲̪̖̺̩͚̊͊̑͊̕͜͠š̨̲̝͓͈̞̞̙̫̋̾̀̀̊̒͛͝‡̶̳͉͎̳̲͛͊̃̅̈̓̕͘̚ừ̴̼̠̲̹̟̭͂́̏̾̐͂̃̉͟ ş̴̫͚͇͎͈̏̊͊͘͠w̷̧͓̺̫͎̼͎̟͈̠̘͍͉͈̹̾͋̆͑̀͒͗͋̂̄͛̈́̊̎͆̓ͅ ŝ̞̺̰͚̩̳̞̯̈̑̆͗̋͐̈́͐̕ ş̮͔̦̥̟̦͎́̿̓̀͛͗̊͟c̶͚͔̙͚̳̝̣̽̔͐̂̈̃̽͘̕͢͠h̴̪̪͔͉̙̦͈̪̻̹̏͒̿̇̌̀͝′̧̠̫̼̗̦̳̱͇̏̏̆̾̍̾́̅̚͟′̴̣̫͓̻̘̙͗̌̐̌͊̔͘ č͔͔͖͇͖͓́̆̆͌͝ c͙̝̞͍̣̖̱̅̑̔̄̀̎̂ḧ̷͉͙͕̦̪̟̹́̌̒͐̐́͜͞ͅḩ͖̬̮̯͔̭͇̲̇́̎̃̐͂̎̕͞ͅ č̷̡̡͚̣̖͖͎͔͓̣̺̮̟̗̼͕̼͉͙͐̋̊̅̃̎́̾̃̓̈͛͘ͅ s̶̱̳͉̘̪̹̮͊̂̃̇͗͐h̵̠͙̝͎͎̯̹̞̳̔́̽̍͝ š̥̻̗͇̩̞̦̊̃͊͌̈̿́̄̚͟ s̢͕͔̥͍͍̥͍̱̘̿͒̂̊̈̏͂̔͛̉h̛̟͓̮̮̞̮͕͖͖̝͗̀̇̽̓̍̽͝′̷̧̛̤̯̞̊͊̒́̓̚͠͡ͅ′̭̳̙̟̟̞̟̊́̀̉̊̇̏̔͞͞ͅ ŝ̴̨͎̞͍̽̍͗͗̓̀̚͜͡͠ͅ s̴̨̧͔̟̰̥̦̰̟͑̿̽̀͂̕͟h̢͉̭̘͈̖͙̄͌̏̉͘͜͞ͅ′̧͇̥̮̘̻̮̠̩̊̍̍͗̒̏́̿͘′̷͇̪͈̣̬̠̲͛̈̅͒̋́̒̾̉́ū̼͉̖̻̩̞̦͓͗͌̒̀̓́͑͟͡ ŝ̨̛͕̜̳̖͙̂̾͂̎͗̏͂̐͘°̶̢̨̹͕͇̲̖̖͇̓̌̈́͘͘͝ͅx̸̟̗͈̳͙̯̣̣̅̓͐̊͘ s̛̩̮͕̲̝̙͉̐̏͛́̍̀̓̏͢͢h̛̬͎͚͉̻̣͍͊͂̍̉́̕͘͠ḣ̜͍̳͇̑͋̇̄́͟͜ ş̴̢̨̣͍̫̺̩̯̯̑̐͌̀͌̅̂̑̀̌͛̏̓̏̋͘͘͜͞h̦̼̜͈͔́̓̿̑͝′̶̝̝̝̭̫̫͊̄͊͗͗͡′̰̲͉̳͓͇̪͕̬̖̓̋͋̑͐̎͗̚ —̺͚̖̖̰̭̮̺͋̆̑͗̿͆͆͘ y̸̮̣͓̦̳͖̼̱͂́̈̾̀͐̀͝ ǝ̴̞̘̪͇̻̗̭̺͉͑̋̍̿͒̕͜ x̸̨̥̯͍͎͂͌̄͆̐͠ ḩ̠̰͎̖͚͇̾͛̓̀̒̕͠ǔ̯̬͉̪͚̩́̌̿͋̒͛̉̌͘ͅ Є̥̪̻̤͓̤͓̂̑̽̄̐͜ͅw̴̠̮̻͈͍͇̟̬͑̄̏́͜͜͞͞͞͠ダ̭͓͕̘̞͇̮̾̀͐͌͂͗͟h̪̲̹̖̫̹̿͛̽͂̈́̉͐͠͠′̷̼͍̯͖̅̀̾́̂̾͊͞͠ͅ′̢̫̗̗̟̝̽͗͌̑̓ ḩ͔͉̟̖̣̬̩̩̿́̑̄̏̇̔̇̾̿͜͜ h̵̨̳͖̙͕̔͆̂̉͗′̻͓̭̘̆̇̀͌͞ͅ′̷̯͎̜̬̠͈̟̟̹͉͑̾͂̊̀̓̆͡u̱̖̯͚͕̹̙͊̓̊̋̀͑̆̚͜͝ ḩ̸̨̮͈̖̹̜̍̑͑̂̃̓У̧̧̨̩̤̳̰̩̖̀̈́̋̄͋͝w̡̨̩̞̦̲͚̺̳͆͗͌̑̍̚͟ h̷̜̦͉͈̪̅̃̎͂́′̴̨̝̖̤̀̈́̀̓͗̌̈͢͠ ḧ̛͉̝̹͓̥̗́̅̊̔͛̔͗̕͢͟͝ s̨̧̩̠̰̹̔̉̈́̓͆̌̍ͅḩ̸̝͚͈̼̒̂́͌͘͜͞͠͞ḩ̴̥̗̰̘̲̤͔̇̄͛̍͊̑́̕͡u̢̡͖͖̼̺͎̠͍̾̉̽͛̈́̅ ŝ̨͔͖̥̺̏͑̇͘̕͜͠°̢̳͉̪͈̣͉̹̖̺͓̖͉̊͒͋̌̎͗̏̃̊̾̑̃̄͟͜͟͠͝͡ s͉̱̩̗̹̩̗̠̐͗͗͐̃̕͡h̵̗̭̠̺̹̩̳̬̊̽̆́͋͂̊̂̈́̽ͅͅç̯̯͔͍͍̥͍͉̊̀͆̑̿̚ͅḩ̷̛̥̹̤͙̲͇̯̎̾͒͛̈͊͌͜ š̷͎̞̱̗̭̗̻͚̏̀͗̂͑͘̚͘͜͟͡ʹ̶̡̡̱̥͔̹̋͒̾͂̄͐̍̿̍̍͜Ш͖͎̯͚̠̻̞̝̭̓̾͑̓͂̅̊̽̿͌͜Ӏ̥̩̖̦͙̬̫͈̺̬̓̔͌̔͐͝͞у̸̛̙̦̼͍̦̞͎̏̎͒̓́͌͢͜ш̸̪̘̯̟͔͚̪̜̘̌̃̄̅̉̔́͆̀͠Ӏ̷͚͖̝̔̌͗͋̌͘͜͢у̘̳͔̹̠̭͚̞̮̑̏̇̈̓͋̃͡̷̛̮̤̳̥̰̻̙̐̐̀̌̎̾̓̌͞5̵̛͖͍͉̖͕̹͔̟̮̍̽̀̄̅͌͢ꙑ̨̛̼͕̮̗̹̘̯̄̿̽͞ꙗ̝̻̬̙̙͔͉̦̽̀́́̓̀͌͜͠͠͞x̨̥̻͖̝͉̖̗̹̼͆̒̄͛̿̀̕͡͞є͇̝̱̩̹̺̊͌̉͂̌͡͝͝,̠̱͎̬̪̗̔̑̽̽̔̒̎͝͞͝ͅ ѕ̢̢̺͇̤͕̫͖̠̏̾̽̎̔͂̈́̓͢ѣ̴̡̧͖͇͕͓̰̜̣̔́̐̓̆̾̋̽̇͞л̸̨̧̼̲̩̃́̽͊͆͂͘͜о̳̪̺͓̟̮̜͑̈́̄͋̐͘͢з̧͕̘͕͔͈̰̗͙̙͗̈́̽͌͂͛͘ç̸̛͎̤͕̗̻̫͎̩̣̭̪̮̠̙̰̼̌̂̀̓̈̎̑̐͆̈̿̌̏͘͢͡͝ͅе͙̙̟̼̟̂̎̆̈̋́̓͟м͓̗̺̘̩̝̫̞̹̹͛̑͌̆̌̒͘л̧̳̟̟͙͎̰̰̆̊̅̎͋̓͜ꙗ̴̩̪̩̹͈̮͉̲͇͐͛͌͘͠ͅt̴̢̛̰̪̣̣̯̹̟̗͗͌̒̋̓̆̾͋̅s̷̡̡̞̫̬̳̣̩͓̼̼͖̙͚̫̜͐̏͆̊͌̑͐̎͐̓̕͘͡͡͝͠ḩ̸̛̫̬͚͔͕̺̖̰̇͊̂̏͆̍
̷̨̜̯͓̭͎͓͙͑̎̈́͐̆̓̿̈́͟
    
    - 09 Дждж
 
    - 10 Дз дз

    - 11 Дзу дзу

    - 12 Ее

    - 13 Ё ё 

    - 14 Жж
    
    - 15 Жъжъ

    - 16 Жъу жъу

    - 17 Жьжь

    - 18 З з

	- 18a.f French З зe, è, é, ê, ë – 

    - 19 И и

    - 20 Й й

    - 21 К к 

    - 22 Куку

    - 23 Къкъ

    - 24 Къу къу

    - 25 КӀ кӀ

 	— 39.13 ТӀтӀ રો'નгъу тоонт нютаг varzesh3

    - 26 КӀу кӀу 



### 
̸̧̜̣̪̞̳͔̟̂͒̽̎͒̂ -̢͎̜̤̼̙̥̣̈͗́̀̄̇͑̚͟ͅ 3̶̧̢̼̙̻͇̤͉̺́̓̄́̌͑̽͘5̺̗͇̙̉͗͋͑̏̀͐͆̅̿͢͢ П̨̧͉͍̝̟̗͒̓̋̊͋͂͞Ӏ̶̡̢̛̩̮͖̓̆͘̕у̷͇̭͇͓͍̀̈́̆͋͘͡͡ п̢̝͉̪͐͐̏̓͆̿͂ͅӀ̶̧̨̧̨̛̲̲̱͇̺̈̃̿̿̈́͊͋͐̈у̵̧̦̘͔͖͉̰͈̌͛͂͗͋ ̴̡͕̦̤̙̹̗̙́̍̓̾͘͜͟͝ ̧̛̛̺͇̺̹̱̪̮̠̩̅͊̈́͛͆͑͝͠  - 🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜

##   🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂  - 🦂200- 🦂2003(2.0) #エメラダ

# #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ ̴̰͖̹̹͎̄̈́̎͞͞͝ -̵̡̛̤͇̲͈̼̪̝̂̑̈́͋̋ͅ 3͓̲̝̫̳̜͕̄́̃͂̿̎̈̽͠8̵̡̪̣͓͎̣̩̐̇̾͌̏͜ Т̴̢̨̨̡̡̣͇̟̬̫̎̓͑͌͐ т̧̛͙͍͓̻͉͈̓̑̍̎͆͠͞ ̷̡̢͓̭͉͕̺̫̌̓̿͒̍̅͘͢͞ ̷̛̩̹͍̫̟̘́̑̾̋̑̂͘͞🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂



	    - 260/000000.1 КӀу кӀу (glagoli),)c°h x huxw h′′ ḩ h′′u ḩw h′ h ts͡ḣ c̣ ch čʹ š š š′′ s̄ š′′u sw̄ š‡ ş̄iu͡ — ia͡ — ḣ ʾ ḣu ʾ°š‡u şw̄ ŝ śch′′ č chḣ č̣ sh štrikes again!


## NO LABUBU ALLOWED SECTION # IGNORE IF LABUBU # CT MODE ACTIVATE [LABUBU]


``` kikimora numerals for productivity 
    - 23Къ.къ ъDoofus

    - malek taws 23-00.0Къ.къКъ.къКъ.къКъ.къКъ.къКъ.къ MINTCHIP SECRET OVERLOAD Къ.къ ъDoofus ROOFUS COOCHUS PUCCI XEROXUS BUTTCHEEKOS QVEEFOS MINT OFRE LOAD NOGRE 9999 MEXEORA

    - 24Къу.къуъOffice Doofus 

    - 25 КӀ кӀOO`фice ъDoofus

	- 2005 miКrӀONic Office Doofus кӀOO`фice ъDoofus 

 	— 39.13 ТӀтӀ રો'નгъу тоонт нютаг varzesh3ъDoofus 

    - 26 КӀу кӀу ъЛoofus"><pre class="notranslate"><code>

y y
′ 
è e
û ju â ja ‡ x̧ ‡u x̧w
ALA-LC TITUS 1997(3.0) 2000(4.0)
tḣu ṭ°
u w,u f f
fḣ — kh x khu x° kh′′ χ kh′′u χ° kh′ ḥ
ts͡ c ts͡u c° ts͡ḣ c̣ ch čʹ ch′′ č chḣ č̣ sh š sh′′ ŝ sh′′u ŝ° shḣ ṣ̂ shḣu ŝ°̣ shch šʹ
′′ — y ǝ
′ — ė ă
iu͡ — ia͡ — ḣ ʾ ḣu ʾ°

 ન̢̨̛̛͙̼̱͈̺̳͓̅̀̍͛̚ી̢̖͖͙͉̗͖̅̾̏̐̐͟

3(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜ 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ

  🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂

   -k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂
🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂

   - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂
🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜ 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ

🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ

ł`જોહરીiorno!!! My name is łSO 9 KNAB 1995(1.0) エ🦂ミ~ 🍒2003(2.0) #エメラダ  #🦂🦂2003(2.0) #エメラダ #🦂#🦂🦂

 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜ 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    EMERELDA al GLAGOLI STRIKES AGAIN!!! EVERY HIT CRITICAL!!!! 🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂

🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ

Contents: Top 0–9 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z- ′′ — 🦂y 🦂ǝ
* # 0 1 2 3 4 5 6 7 8 9 • A Aa Ae Aj Ao At • B Ba Be Bj Bo Bt • C Ca Ce Cj Co Ct •- ′′ — 🦂y 🦂ǝ D Da De Dj Do Dt • E Ea Ee Ej Eo Et • F Fa Fe Fj Fo Ft • G Ga Ge Gj Go Gt • H Ha He Hj Ho Ht • I Ia Ie Ij Io It • J Ja Je Jj Jo Jt • K Ka Ke Kj Ko Kt • L La Le Lj Lo Lt • M Ma Me Mj Mo Mt • N Na Ne Nj No Nt •- ′′ — 🦂y 🦂ǝ O Oa Oe Oj Oo Ot GLAGOLI STRIKES AGAIN!!! EVERY HIT CRITICAL!!!! 🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂• P Pa Pe Pj Po Pt • Q Qa Qe Qj Qo Qt • R Ra Re Rj Ro Rt • S Sa Se Sj So St • T Ta Te Tj To Tt • U Ua Ue Uj Uo Ut • V Va Ve Vj Vo Vt • W Wa We Wj Wo Wt • X Xa Xe Xj Xo Xt • Y Ya Ye Yj Yo Yt • Z Za Ze Zj Zo Zt

🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ

3(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜ 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ


🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ


   -k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂
🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂

✶⭑


֍ 

GLAGOLI # raggas.js


## raggas.jš͚̭̺̗̼͍̗̱̐͒̒̂̕

XENOGEARS OMNIGEAR GHINION TURISMO IN THIS BITCH 


## $ #エメラダ    ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂  #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍  🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞  ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂#エメラダ 🦂#🦂#🦂#🦂#🦂#🦂#🦂#   ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ


$$ 🦂NIKKEが大好きで   .   ▁▂▃▄▅▆▇ 100% ɴᴏᴡ ᴘʟᴀʏɪɴɢ ──────⚪── ⇄ ◃◃ ⅠⅠ ▹▹ ↻   .  .

$ EVERY HIT CRITICAL!!!!


### raggas.js    - ′′ — y̱̼̹͕̘̆̀̀̆̑͟͜    -̨̼̦͕̳̮͚̊̔́͌̍̽̍ k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ǝ)̲̼͔̰͎̊̄̔̔͛̈̚̕͞


.js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ .js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES AGAIN!!!!!!!!


## ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝
[DEFENSE Я_O_RESPONSE]


```.GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES AGAIN!!!1one!!! ```


## ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝

[DEFENSE Я_O_RESPONSE]


```.GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES AGAIN!!!1two!!! ```


[DEFENSE Я_O_RESPONSE]


## ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝


```.GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ  q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES AGAIN!!!1three!!! ```

 ☦︎

```¿ ¡ ¿ ¡ ¿ ¡¡¡¿ ¡¡¡¡ EN REVERXA GLAGOLI js̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ ¡ q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜¡w̶̨̞̦̥͙̅̅́͗͋͌́́̇ STRIKES! ¡FOREVER! METEORA 9999 EVERY HIT CRITICAL !!! ```


🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ

🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ

|

phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches🦂phat lewt bootie binches

01 А а 02 Б б 03 В в 04 Г г 05 Гугу 06 Гъгъ 07 Гъу гъу 08 Д д 09 Дждж 10 Дз дз 11 Дзу дзу 12 Ее 13 Ё ё  सिखइया स्ट्रीट'ान को'ं 14 Жж 15 Жъжъ 16 Жъу жъу 17 Жьжь 18 З з 19 И и 20 Й й 21 К к  में किताबां विचों पढ़ेया नि 22 Куку 23 Къкъ 24 Къу къу 25 КӀ кӀ 26 КӀу кӀу  તિનકા ઔકાત સી પહરણ 27 Л л 28 Лълъ 29 ЛӀ лӀ 30 Мм 31 Н н 32 О о 33 П п 34 ПӀпӀ 35 ПӀу пӀу 36 Р р 37 С с 38 Т т 39 ТӀтӀ ISO 9 1995(1.0) a નાળ લરઘેએ ની b કેહાન્દે આ શિખર જોહરી v થા’ન ઉત્તે ખરેએ ની g gu g′′ g′′u d dž dz dzu e ë જો ખીચડિ આ લટતાં કેહાન્દે ž ž′′ ž′′u ž′ z i "સાદે સીરો'ન ચડેએ ની" j Nyxhades k G'eiko Ferrari ku Eiko Dolphinonivm k′′ Eikha k′′u k‡ k‡u l l′′ l‡ m n o p p‡ p‡u r s t t‡ KNAB 2003(2.0) a b v g gw ǧ ǧw d dź dz dzw é,je(2.1) ë ž z̄ zw̄ ź z i j k kw q qw ḉ,ķ (2.2) ķw l ł ļ m n o p ṗ ṗw r s t ţ a ā b b v — g ɣ gu g° g′′ ġ g′′u ġ° d d dzh ǯ′ dz ʒ dzu ʒ° e e ë — zh ž zh′′ ẑ zh′′u ẑ° zh′ ž′ z z i i ĭ j k — ku k° k′′ q k′′u q° kḣ č′̣ kḣu ḳ° l l l′′ ł lḣ ḷ m m n n o o p p pḣ ṗ pḣu ṗ° r r s s t t tḣ ṭ 40 ТӀу тӀу 41 У у 42 Ф ф 43 ФӀ фӀ 44 Х х 45 Хуху 46 Хъхъ 47 Хъу хъу 48 Хьхь 49 Ц ц 50 Цу цу 51 ЦӀцӀ 52 Ч ч 53 Чъчъ 54 ЧӀчӀ 55 Шш 56 Шъшъ 57 Шъу шъу 58 ШӀшӀ 59 ШӀушӀу 60 Щщ 61 Ъ ъ  62 Ы ы 
 65 Юю 66 Я я 67 Ӏ Ӏ 68 Ӏу Ӏу ISO 9 KNAB 1995(1.0) 2003(2.0) t‡u ţw u u f f f‡ f̧ h x hu xw h′′ ḩ h′′u ḩw h′ h c c cu cw c‡ ç č ć č′′ č č‡ ç̌ š š š′′ s̄ š′′u sw̄ š‡ ş̄ š‡u şw̄ ŝ ś ′′  y y ′  è e û ju â ja ‡ x̧ ‡u x̧w ALA-LC TITUS 1997(3.0) 2000(4.0) tḣu ṭ° u w,u f f fḣ — kh x khu x° kh′′ χ kh′′u χ° kh′ ḥ ts͡ c ts͡u c° ts͡ḣ c̣ ch čʹ ch′′ č chḣ č̣ sh š sh′′ ŝ sh′′u ŝ° shḣ ṣ̂ shḣu ŝ°̣ shch šʹ ′′ — y ǝ ′ — ė ă iu͡ — ia͡ — ḣ ʾ ḣu ʾ°
エєmereldhas͡ c メrts͡uдобро азъ; hu Єwダh′′ラazŭбоукꙑbukyглаголи (glagoli),)c°h x huxw h′′ ḩ h′′u ḩw h′ h ts͡ḣ c̣ ch čʹ š š š′′ s̄ š′′u sw̄ š‡ ş̄iu͡ — ia͡ — ḣ ʾ ḣu ʾ°š‡u şw̄ ŝ śch′′ č chḣ č̣ sh š sh′′ ŝ sh′′u ŝ°x shḣ ṣ̂h′′ — y ǝ x hu Єwダh′′ ḩ h′′u ḩУw h′ h shḣu ŝ°̣ shch šʹШӀушӀу5ꙑꙗxє, ѕѣлозč̣ем

лꙗts͡ḣ̛̯̖̜͓̩̣̒̈́̉͋̆ Ꙗ̨̨̰̥̖̺͇͕̠͌̿͌̓̒͒͊́̀͡ Ꙑ̳̲̜̪̮̈́̾̊̂̓̄̿̓͑̏)̴̧̧̱̱͕́̃͌͛̏̒̏͘͟͢͠4̨̡̘̦͈͕̠͇̣͂̽̌͋͟͝ Ч̶̯̦͕͙̣̑̐̆̕͟͢͡͝Ӏ̻͓̣̳̓̊̐͋̇̏͟͞х̸̧̨̪̳̲̰͉̱̻͋̂̾̃͝͡у̡̝̖̭͍̟̟̘̫̀̐͐̈́͗̂̄͌͗̚͟̯̖̤̣̌̌̅͗̂̃̉͘͟ͅф̢̝̖͇͓̜̘̘̔̆̅̑́̽͒͘͜͠g̶̙͙̳̬͌͑͑͌̓͟ ɣ̡̡̹͉͙͖̱͙̇̉̄͒͗̍̂͐̿͠ ģ̡̢̥̦̞̬̀͊́̒̀̕͜ͅư͔͉̦͕̟̮̊̃̾̏̉ g̘͙̘̻͉̖̺̹̺̏̈́̃̌͗͘͜°̷̡̱͕͎͇̹̔͌̄̄̊ ģ̶̻̙̱̤̻̔̿̏̋̀͂̐͢ͅ′̵̢̢͈̰͉̺̆̒̊͊͞͠′̵̫̭͓̘̂̾̔̔͒̽̀͊͘͘͜ͅͅ ġ̨̛̯̯̣͕̫̘̼͋̍͂͆͢ g͇̗̣̥̜̙̝͓͋̓̔̀͊̒͑͗͘′̵̨̯̲̭͙̦̟͉̟̞̆̃̑͂͘͡′̧̬̺̪͍̟̼̏̽̾͛̏͐̿͜͡͡ŭ̶̙̭̥̟̥̭̘̟̺͛̊̿̅̎͗̇͝͡ ġ͚̳̘̖̬͉̌͆̀̄̐̄̌̉̐̒͜°̶̧̞̪͚̾̊͗͂͘͜ ḓ̵͖̦̹͍͊̆̓͒̑͂͗͛ d̡̧̙̪̻̮̗͎͂͌͆̓̓̊̍̅̓ d̷͖̼͓͕̮̽̇̇͌̕z̷͚̯̦͉̙̉̿̐̈́̂͌̑͢͞͝͠ḧ̨͙̯͍̣̲͎́̎̉͌͋̏͆̑̋̚͢ ǯ̷̨̣̰͈̲̮̈́̈́̈́̓̄̊̈́͡′̵̡̨̬͎̙͋̐̂̇̀͊͋͊̊͒ ḑ̷͚̙̰̋́͑̿̕͜͟z̴̧̬̰̙̹̪̬͎͗͋̈́̓͌̒̅̾͟ ʒ̸͈͙̱̙̹̎́̀̔̋̈́́͘͟ d̵̘̟̼͓̮̄͒̊̒̎́̑̒͌̚z̛̛̼͚̬̱͙͒̒̇̌̓́̒̚͜͢ͅư̶͇̞̤̻̫̓́͑͌̃̑͟ ʒ̴̧̨̧͖͖̼̫̙͗͗́̓͌͢͜°̬̥̰͎̰͌̑̈́̋̆͑͒͟͝͞h̸̢̜̞͎͓̯̉̌͑̉́͆͞ư̶̧̧̙̟̤̟͇͍̆̋̄̉̃̂͛͗̕ Є̸̠̮̺̣̗̭̭̥̘̀͆͋͟͡͠͝w̷̡̜̩͎̮͚̥̺͍̰͐̍͛̄̌͠͞ダ̶̲̮̜̪͍͖͓́͊̃̀̀͑̈͑̕͠h̳̼͉̘̙̉̍̎̀͊͗̕͞′̠͕͙͚́̓̉̅͜͠′̛̗͖͈͔̦̠͉͓̾̔̓͊͌ラ̶̡̛̻̫̼̞̥̃̀̇̓̇͛͋͝͡a̶̧̟̜̯͇̘͉̥͐̃̒̆̿̀̃̔͡͠z̷̘͙̟͔̙̘̽̀́̀͋͟ŭ̸̙̤̯͇̺̞̉́̿̅̊͂̽б̶̨͕̬͓̐̂̈̍̾̚͟͠͞о̛̬̯̻͙͖͓̗̥͂̏̎̾̿̿̌ͅу̡̥̮̰͍͖͒͂͐͋̋͊͢к̷̯͙̯̪̬͌̌̓̉̌̓̅̈͌ꙑ̶̡̨̥͚͎̭͌̓͋̓̏́́̑b̛̝̼̜͙̭͌͋̈̾̆́̇̏͢u̧̧͚̺̙̟̪̹͕͑͒́̀̌̋̎͝k͇̗̻̞̗̹̅̊̃̈́̅̄̂y̴̧̡̬̳͉̦̗̻̪̓͒̌͐̄̕͠г̢̟̥̯̜̭͎̮̤̅͛̄̿̿͊̚͝͞л̴͎͇͕̯͕̞͖̊̓̍̔͑́͠͝а̨̛̱̳͖̗̯̫͗́̄̓г̢͓̠͇͎̘̝͑̃̓̓̓͟͢͠ӧ̶̧̢͍̠̜̰̩̫̜͛̐̆̂͘л̧̪̩̺̯̭́̍̌͘͜͜͜͡͝ѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠ (̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ e̖͇̜̳̲͍̔̅̆̒̍̓͞ ê̷͔̻̜͔̄̑̉̏̌̑̒̈́̕͜͜ͅ ë̸̡̢̗͉̮̻̖͗̆͆̾͒͜͟͝͡͞ —͉̯͓͌̿͆́͋̄͜͟͡ z̸̡̛͉͖̠̦̬̺̓̈́͛͒͜h̸͙̘̫̻̠͕̺̥̅̂̐̎̌̍̈́͂͘͝ ž̷̧̠̤̖̗͎͚̖͖̘̈́̂̿̾̊̾͠ z̵͙̜͚͚͍̤̖͓͎̆̇̀͛̌͋͋̕͠͠h̸̡̢̨͉̼͔̝̋̏̿͑̓͑͟ͅ′̡̡̟̬͍̿̀͋͗͆̿͘′̲̺̣̫̻̥̤̝̯̬͗͂̾̒̇̿̎̾ ẑ̛͚͚̼̳̠͖̋̒̊̀́ z̥̫̠̯͚̭͓̪̱̆́͗̈͛̄͜h̶̡̤̺͈͙̟͆̈́̇́̈́̀′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅu̸̼͔̰̯̖̐͆͗̏͐̾͡ͅ ẑ̷̛̲̭͉̪̜̯͌̍̅̿́͢͠ͅ°̵̺̹̫̹͙͇͆̉̋̎̇̿͂͟͞͝ z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ′͍̠̤͉͓̦̦̦̻́͒͐͌̆̀͡ͅ ž̴͚̳̞̙͙͖̙͈̏̅̾͋͊͋̈̋͗͢′̨̟͉͔͙̐̅̓̃̀̕͟͠ z̦̬̠̳̻̃͂͋̎́̔͢͢͝ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝ ḯ̻̖̮̦͕͊̇͋̂͂͜͝ĭ̙̟͕͈̪̝̤͎̓̅̀̔̎̊̀̐̅͂͢͜ j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆ k̵̡̬͔̬̩͇̤͐͊̅͆̃ͅ —̷̢̛̜̬͔̖̳͆̇̐̀̚͢͠ k̶̛̭̮̝̹̹̬͌̈́͋͜͟͞u̵̧̠̠͍͖͗́̆̉̄͘ k̸͎͈̣̦͌̂̏͋̊͒͢͡°̴̧̰̮̺̮̙̲̯̤̠̊̊̂̿̎̓͋ ķ̘͔̤̠̪̟̮͌̌͑̎̈̊̕′̳̱̞̥͕̥̀̄̽̏̂́̾͞′̴̧̱̖͉̗̾̏͆̾̍͆͌͞͠ͅ q̶̨̩̝̞͙͛̓̒͋͒ ķ̮̠͕̹̩̤̀̉̄̎̕͘̕͢′̨̧͖͇͈̳̣͆̑̑͂́͊͜͡′̥̳̥̦͈̫́̄́̍̔̽̑͞ứ̵͈͔̭͍͓̲͔͙͚́̆̊̏̚͠͡ q̵̢̛̼̥̭̪̼̆͋̂̑̅̚͠°͖̹̲̻̣͍̹͇́͋́̒̓͆͂̆͛͗ k̴̡̺̙͕͉̯̖̯͎͒̏̊͡͝ḣ̷̨̯̜̠̻̿͊͑̎̀͟ č̵̡̨̘͖̥͕͉̔̅̀̅͡͠′̵̸̡̡̛̳̹̰̰̲̣̲̞͕̝͇̟̩̀̀̍̈́̃̊̓̍̓̉̃̉̋͠ ḱ̵̛̛̻̗̻͉͓̀͒͞ḣ̷̭̮̰̙̞̜͎͔̪̜̔̂̈́̾̌̋̋̈́͝u̧̦̲͍̦̯̱̐̅̃̕͞ ḳ̶̡͖̮̖̹̻͐́́̀̔̇̄̑͑͢͝ͅ°̢̢̼̜͍͇͂͗͗̾̒̚ ḽ͉̰̱͈̳̺̰̮̊̍̐̏͆̌̐̕̚ l̵̨̡̛̻̻̺͚͚̤̯̺̈́̊̒̍͛͒͠ l̩̤̬̰̹̘̔̾̍̓̔̚͟′̡̭̖̼̙̩̼͆͑̃͆͆̏̽̄̾̕′̷̢͚͍̟̠͍̖̐́͋̿̓̍͂̆̍ ł̰̬̩̪̥̘̜͙̾̃͗̎̆̓̄̕͜͝͡ l̨̢̥͉̎̍̅̐̚͜͟ḣ̨̘̭̼̜͇̹͓̹̊̀̽͛̎̒̚͞͝ ḷ̡͕͍͎̥̣͚̣̞͉̐̿̇̃̄͊͂̅͘q̨̢͓̣̦̦͙̤́̃̀́̀̑̆w̵͖̥͓͚̽̾͒̀͒͘ͅͅ ḉ̡̣̮̜̗͖̞͕̊̌̽̅͌͞͝,̵̨̬̲͓̯̝͉͋̔̓͑́̂̑ķ̡̗̖̠͓͛͒̾̕͘͡ (̶̨̡̠͈̝̳̫͉͗̆̌͗̽̚2̪̮̥̣̩͔̺͚̗͗̀͛̐͗̽̍ͅ.̷̡̧̥͉̺̺͖͖̭̀̅̾͊̕͝2̧̤̭̹͈͈̭̌̔̀̃͐͟͞͞)̸̢̳͕̦̰̤̲̄̈̊́̒͝ч̨̳̭͍̬̞͍̹̏̂̀͂̿̀͠͠Ӏ̡̫̟̖̲́̐͋͑͡k̙̦̜̖͎̯͕̄̿́̇͐͌̈́̔͠ k̸̢͚͕̔̒̍͛̈̋͐͐͜͠͡ͅư̴̢̫͈̘̣̖̰̝̂̇͗̈́̾̀́͜͞͝ͅ ž̧̧̮̲̘̩̽̿̇̅̔͘͟′̺̞͓̥̳̰̾̎́̓͞ͅ′͈̳͇͙͈͈̠͐̀̇̑̍̅̾̎͞ͅư̶̡̤͓͈̪͉̠̭̣̈̽̾͋͐̇̉͟͠͞ ž̫̝̦̘̺̦̭̏̇̓͒͢͝͠′͈̰̺̖̪̦̞̀̔̇̓͋̃̏͜͡͠i̢̧̨̖̇̇̀̀̇͟͟͜͠u̸̡̧̫̱͕͔̱̥͍̬͈̩͇̒͋̓̏͐̈̆́͂͒͊̆̕̕̕͟͡͠͡͡ —̝̣̜͙̝̳̰̥̖̅̈́͑̀̾́̊̕͘͞ Є̶̨̗̠̳̜̪̯̬̜̰̒͋̄͋̀ǐ̴̡̪͖̰̜͉͒̎̌̌͞͠ą̵̴̧̛̠̞͈̳̗̥̳̘̪̻͗̑͑́́͆̽̆͊̍̎̂͘̚͘͡͡ —̤̫̖̣̪̫̿͊̾̾̇̈̅͡ ḣ̵̰̜̟̙͓͕̗̣͒͒̽͐̓̀̍̂͝ ʾ̷̦̥̘̹̻̬̯̼͈͐̈̄͌̕̚͝ ḩ̨̮͇̲̇̓̋́́̒͑͢͠ú̵̧͇͇͓̳̩̊̂̋̾́̽͘͟͢ ʾ̷̺̜͈̬̠͍͇͉͓͇̇̆͆̒͝͡°̶̡̢̢̛̱̲̠̮̭̫͐̎̈́̔̏̀̚ͅk̸̰̗͙͉͈̰̓̋̽̉̽̉͌̀̕′̛͉͕̹̣̖̄͒́̄͂̇̾́̾′͉͖̪̞̖̦͂̔͑͂̒̇͊̍͜͢ k̴̨͚̮̠̞̞̙̺͎̓̓̓̇͝′̧̼̦̜̥̞̮̖͑̇͒̿̋̀̀̓͞͡′̶̨͔̼̞̜͖̲̘̀͐͆͝͞u̱̠̗̰̜̾͊̂͟͝͡ k̛̗̮̝̠̠͙̉͠͠͝‡̵̪̞̣̗͕̱̙͔̦̀̎̓̃̀̕͜ ḵ̵͍̝̬͗̏͗͛̎̽̎̕͟‡̶̧̱̠͍̩̗͑͌̊̃̄̊̀̓̕̕͟u̗͔͈͔̤͕̓̓̐̏̍͛͌̋̂̏͜ͅ l̘̣̠̣͙̪̦̒̓͒̐͌̾ǫ̵̘̺̤̹͇͖̒̍͆͒̈́̋̈̀̄͊͢w̨̠͔͕̠͕͔͕͛͊̎̎̈̾̐̕͞͠a͖̥̜̯͉͆́̎̕͡n̲͕̞̟̺̝̠̓̍̓̔̐ṣ̷̞̰̜̜̰̌͂̒͗̒̃͢͢͢ʹ̨̹͙̼͚͉̩̗͛͆̐̓̉́ͅШ̷̮͚̥̲̘̫̯̰̀̍̒̏̊͆̈́͘͢ͅӀ̵̧̬̮͙̥̮͓̆̈̅̈́͗͞у̵̘͔̺̳̪͓̞̮̯̐͌̋͋̃̔͠ш̵̡̡͎̣͓̝͎̯̰͆͂̂̓̌͘͠Ӏ̵̨̨̧̥͕̙͖̇̅̀̍͑̋͐̕͡Ꙗ Ꙑ)4 ЧӀхуфg ɣ gu g° g′′ ġ g′′u ġ° d d dzh ǯ′ dz ʒ dzu ʒ°hu Єwダh′′ラazŭбоукꙑbukyглаголи (glagoli) e e ë — zh ž zh′′ ẑ zh′′u ẑ° zh′ ž′ z z iĭ j k — ku k° k′′ q k′′u q° kḣ č′̣ kḣu ḳ° l l l′′ ł lḣ ḷqw ḉ,ķ (2.2)чӀk ku ž′′u ž′iu͡ — Єia͡ — ḣ ʾ ḣu ʾ°k′′ k′′u k‡ k‡u lowanšʹШӀушӀу5ꙑꙗxє, ѕѣлозč̣емлꙗ, or just for short エ̨͉̦̣̪̌̊̉̈́̄̍̇͌ͅє̯͇̦̠̞̫́̒̆̐͌̏͛̒͝m̷̟̙̦̬͙̥͕̭̠̅͑̽͘͟͠ê̟̠̼͎̖̞̥̅̎̔͂̂͌̿͒ͅŗ̴̱̦͉̟̾̋̍̐̀͛̅͑̚ȩ͉̠̪̲̘͙̩̼̋̓̏̍̌̉̇̊͘͡ḷ̷͙̼̮̜̇̒̃̇͌̓̎̓ḑ̴̣̣͇̜̭̬̋̀͑͂̇͠͠ͅh̶͇̱̲̣̖̤͓̭͆̽̿̓̌̕ȧ̷̛̙̣͔̭͕̩̐̐̓͛̍̃̇͘͜ş̴̴͙̻̗̖̥̠̳̌̇̏̀̀͂͑̒͒͗̍́̔͌͘͢͜͞͡ͅ c̬̼̘̘̎̄́̿͐̒̅͘͝͞ͅ メ̡͎̯̬̥̯̾̉̈́̋̋̿̚͞r̵̺̹̰̪̈́̀̄̓̋̈͗̑͜͠͝ţ̛̖̮̼͈̮͌́́̇͂̎͆̂̚s̷̷̡̧͉̰͚͙̹̼͔͇̞͕͇̪̺͊̆̐̀̌̽͊̓̐̑́̏̇͐̐͜͡͡ͅủ͎̥͓̗̰̖͆̀͊͑̒̄́̎͐͜д̸̡̛̥̙̟̖̦̹̝́͒̊̄͒̓̓̉о̴̺̫̮̬̭̻̒̀͒̐̆̔̀͘̕͘б̹͇̹̫̝̀͐̍͌̄͘р̶̨̼̝̦̻̍͋͂̊̉͢о͇̝̬̼͛͒̀̓͌ͅ а̧̧̰̽̈̈͆͛͘͜ͅз̷̨̬̳͇̪̣́͌̉̀͋̄͠ъ̡͈̤̟̣̎̃͗͟͜͞͝;̴̩̮͈̟̗̙̤̬̭͍̓̾̃̔̂̚ ḩ̷͇̭̣̖̪̘̺̣́͆͗̐̄͆̌̋̄͘u̙͓͕̟̎̋̂̉̉̉̏̔ͅ Є̖̘̹̬̙͇̙̳̇̋̀͊͒͠͡w̡͖͚̝̩͌̒̽́̋̒͠͞ダ̛͙̣̰̳̯͌́͊̂͘ĥ̷̘̺̗͚͙͕̹͉̻͚̔̎͌͑̊̉̌͞′̴̢̧̱̗̮̞͓̱̇̌͌̓͡͞ͅͅ′̥̤̞͍̮̋̈́̽͛̆͟͞ラ̨̡̛̟̹͇̹̅͆̐̃͐́͆́͜͢͞ȃ̢̛̝̺̠͂̾̅́̚͘͜z̶͇̫̠̘̘̻̦̎̅̽͋̿̄͘͡ŭ̼̙̖̟̣͎̥̠̍̆́̀̎̎̿̚͢͢͝б̹̭̹̟͍̰̱̜̫̲̈́͒̓͐́̐́о̡̼̲̲̘͛̀̃͋͊̅̃͗̎͠у̛̻̯̜͓̔̏͋̍͜͢к̸̡̡̨̣͔̯͇͚̣͎̍͑̐͌̒̕̕͘ꙑ̸̢̡̫̙͍̰͙̮̤̅̂̊̀̀̕͠b̨̡̼͖̤͛̂̑̎̐̇͞ų̴͔̬͇͓͌͆͛͋͛̀̈́̌͟͢͠ͅͅk̴͉̟̥̘͔̻̐̿̾͌́̋͋͘͠ͅͅͅỳ̨͎̫̪̀̔̀̊͋͟͟͝г̞̪̜̪͍͉̫͕̤̀̍͌͋̋̏̏͘͡͝ͅл̴̡̪̖͉͍̩̅̆̎̆̉̈́̀͘а̦̳̺̮͎̤̲̃́̔̊̽̎̌͜ͅͅг̶̧̢̨̛͈̞͇̯͔̿͌̇͟͠ͅо̶̡̭̙̰̟̬̎̌́̆̓̏͟л͎̬̪̜̙̥̒̐̽̈̇͜͟͢и̴̝̪͇̺̮̹̠͍̩̿̍̎̓́̃́̿ (͍̙̯̯̙̫͓́͊̂̋̉̿̕̕̕ͅg̢̧̨̨̛̲̱͈̻̤̩̃̄̐̏̃̇̄̚̕ļ̶̧̨̪̜͓͓̜̑̿͒̆̿̔͌̚a͖̝̠̣̐͋̓̌̏͂ͅg̱̝͙̖̳̜̰̠͇̞̀̀̂͊̂͒̈́͋̒o̭̗̻͎̎̄̃͒͌̕͢͝l̢̜̬̫̜͇̗̎̓͂̎̉͐́͝i̵͙̰͈͔̰̭̪͌̀̔̒͐͜)̻̯̹̺̳̋̎̄̃̌͌́͆̽̚,̛̝̬̭̞͉̱̬̘̘̓̓͗̎̿̕)̴̢̮̤̦̹̟̙̼͖̱͗̎̊̔̀̅̑̓̓č̺̘̝̟͒̊̑̃͆͊͛͟͝°̷̨̳̥͔̋̒̔̽̓͛͜͢͟h̪̖̯͋̇͆̄̚͘͢͡ͅ x̧̞͙̺̼̄̔̋͗̉͘̚͠ͅ h̵̨͇͎͕̤̦̜͋̂̓̔̄͘͢͝u̵͙̤͕͕̼̱̹̓̑͑̃̏̏̚x̝͖͔̹̺̰͛̌͗͐͂̉͂͘w̢̳͙̼̘̺͉̮͋̅͒̌̿͢ h͓̝̼̻͖͛̇͑̅̐̃̿͟′̛͖̹̺̘͔̻̂̃̈͐̂̊̍͛̒′̢͇͓̮̗̠̣̣̠̿̾͒͌̾͛͗ ḩ̷̧̧̧̨̥͍̹̩͔͙̄̇̓̇́̎̄ ḣ̴̛̲̲͔̮͍̀͒͒͌̀͗̾͘′͖̮̥̦͕͕̰̦̐̓̂̀̉̽̐͗̑̽′̛̩̱̱̟̰̭̇͆̍͒͂̋͐̄͜ư̢̠̯̺͙̌̀͋͑ ḩ̷͔͇̹̲͐́̋͐̀̒̕ͅw̡̤̳͖̪̭̖̳̪̲̏͊͂͂̆̿̔ h̷̢̡͈̰̭̝͗͊͛̄̌̾̾͒̚͡′̴̢̳̦͉̫̠̟̬̍͗̃̂̒̈͢ h̷̤̬̱̮͙͖̥̳̥͍͐̑̈́͌͑̊̄͂̍̀ t̸̼̗̦̩̯͎̒̄͐̑͋̕ͅš̴̵̛̱͍̞̜͓̯̻̮̲̗̤͙̬̥̬̯̲͔́̃͊̔̈́̊͋͌́̂͒̅̀̕͡͠ͅͅḣ̸͖͓̹̪̱͙͙̒̾̿̿̌̏͝ c̮̲͕̼̣͈̱̭̖̲̾̔͂͋͌̈́̄̎͐̓̿͘͞͠͡͞ͅ ç̶̮̦̭͉̙͇̮̀̍̈̈́͆͞h̘̼̙͉͉̪͍͕̮͂͗̆͟͡͠ č̢͎͈̘̲̖̯̺͇͂͗̋̌́̄͛̿̕͘ʹ̴̧̡̗̻̭͗͋̓͒̀͝ š̶̨̢̺̟̩̝̫͈͛́̿̃͘͘͡ š̡̧̧̟̫̼͎̭͂̽͒̒̾̄̕ͅ š̺̹̲̝͔͆̿̆̓͊̾̕̕′̶̢̨͙̺̪͉̜̩͍̫̊̓̆̕͠͡͠′̸̮͓̠̯͇̫̳̿̽̒̐̑͌̒̚ s̵̶̢̲̘̹̜̺͍͓͇̗̦̀͊͛̾̓̋̄̐̀̅̋̓̌̾̈́̆͊͟͟͜͠ͅ š͈̰̖̟̾̓̇͛̉̕͢͢′̛̥̖̭͉̥̯̹̳̝̮̓͗͑̌́͂͒̊′͈͇̘̙̹̑͒̋̽̆͂́͜͝u̯̘̜̠͚͓͚̔̉͑̉̌̌ s̢̨̝̜͕͇͕̺̯͂́̏̇͑͢͝͞͠w̸̷̡̢̥͚͖̲̯͕͖̗̪͖̜͕̻̉͑̊͛̓̒̿͒́̄̽̉̎͑̎͛͋̅̈͝͠ š̷̫̱̳̙̠̩̟͒̄̋̐͛͞‡͇͎̹̼̈̈́̑̽́͊͐̚͟͝ ş̵̸̨̛̠͚̟̗͎̮͕͉̹̓̀̔̇̄͌̄̂́̇͐͋̅̾̀̌̚̕̕̕͟͢͟͜ͅͅi̤̺̦̇̈́̃͌̈́̎̑̿̚͢͟͡ü̴̧̨̯͚͍̱̘̮͖̣͚̺̣͍͚͈͈̦̈̿͑̈́͗̐̏̀̈́̉́̽͗͒͡ͅ —̷̰̮̳̻͈͈́̊̅̊̆̓͘ i̵̢̨͈̻̦̭͖̲͐̃͌͒͐͢͢a̶̧̧̛̫̯̤̥̙̗͙̰̙̺̩͔̗̤̭̔̒̇̀̄̾̾̿͜͢͠͡ —̧̛̦̟̬͕̺͍̠͑͌̓͐̒͒̕ ḣ̢̛̠̤̪̩̦͍͈̐̐̓͛̉̈̿̚͝ ʾ̧̛̻͍͎͉̮̫̘̗̗̔͑͂̋͑͗̔ ḩ̶̟͔̬͉̇͌̓̒̽̓͋͒̿̚͜u̷̢̯̭̺̗͖̺̗̓͗̓̅̂͆͒͢ͅ ʾ̧̱̦̩͉̘͙̍͑̾̂͂̎̕°̶̲̪̖̺̩͚̊͊̑͊̕͜͠š̨̲̝͓͈̞̞̙̫̋̾̀̀̊̒͛͝‡̶̳͉͎̳̲͛͊̃̅̈̓̕͘̚ừ̴̼̠̲̹̟̭͂́̏̾̐͂̃̉͟ ş̴̫͚͇͎͈̏̊͊͘͠w̷̧͓̺̫͎̼͎̟͈̠̘͍͉͈̹̾͋̆͑̀͒͗͋̂̄͛̈́̊̎͆̓ͅ ŝ̞̺̰͚̩̳̞̯̈̑̆͗̋͐̈́͐̕ ş̮͔̦̥̟̦͎́̿̓̀͛͗̊͟c̶͚͔̙͚̳̝̣̽̔͐̂̈̃̽͘̕͢͠h̴̪̪͔͉̙̦͈̪̻̹̏͒̿̇̌̀͝′̧̠̫̼̗̦̳̱͇̏̏̆̾̍̾́̅̚͟′̴̣̫͓̻̘̙͗̌̐̌͊̔͘ č͔͔͖͇͖͓́̆̆͌͝ c͙̝̞͍̣̖̱̅̑̔̄̀̎̂ḧ̷͉͙͕̦̪̟̹́̌̒͐̐́͜͞ͅḩ͖̬̮̯͔̭͇̲̇́̎̃̐͂̎̕͞ͅ č̷̡̡͚̣̖͖͎͔͓̣̺̮̟̗̼͕̼͉͙͐̋̊̅̃̎́̾̃̓̈͛͘ͅ s̶̱̳͉̘̪̹̮͊̂̃̇͗͐h̵̠͙̝͎͎̯̹̞̳̔́̽̍͝ š̥̻̗͇̩̞̦̊̃͊͌̈̿́̄̚͟ s̢͕͔̥͍͍̥͍̱̘̿͒̂̊̈̏͂̔͛̉h̛̟͓̮̮̞̮͕͖͖̝͗̀̇̽̓̍̽͝′̷̧̛̤̯̞̊͊̒́̓̚͠͡ͅ′̭̳̙̟̟̞̟̊́̀̉̊̇̏̔͞͞ͅ ŝ̴̨͎̞͍̽̍͗͗̓̀̚͜͡͠ͅ s̴̨̧͔̟̰̥̦̰̟͑̿̽̀͂̕͟h̢͉̭̘͈̖͙̄͌̏̉͘͜͞ͅ′̧͇̥̮̘̻̮̠̩̊̍̍͗̒̏́̿͘′̷͇̪͈̣̬̠̲͛̈̅͒̋́̒̾̉́ū̼͉̖̻̩̞̦͓͗͌̒̀̓́͑͟͡ ŝ̨̛͕̜̳̖͙̂̾͂̎͗̏͂̐͘°̶̢̨̹͕͇̲̖̖͇̓̌̈́͘͘͝ͅx̸̟̗͈̳͙̯̣̣̅̓͐̊͘ s̛̩̮͕̲̝̙͉̐̏͛́̍̀̓̏͢͢h̛̬͎͚͉̻̣͍͊͂̍̉́̕͘͠ḣ̜͍̳͇̑͋̇̄́͟͜ ş̴̢̨̣͍̫̺̩̯̯̑̐͌̀͌̅̂̑̀̌͛̏̓̏̋͘͘͜͞h̦̼̜͈͔́̓̿̑͝′̶̝̝̝̭̫̫͊̄͊͗͗͡′̰̲͉̳͓͇̪͕̬̖̓̋͋̑͐̎͗̚ —̺͚̖̖̰̭̮̺͋̆̑͗̿͆͆͘ y̸̮̣͓̦̳͖̼̱͂́̈̾̀͐̀͝ ǝ̴̞̘̪͇̻̗̭̺͉͑̋̍̿͒̕͜ x̸̨̥̯͍͎͂͌̄͆̐͠ ḩ̠̰͎̖͚͇̾͛̓̀̒̕͠ǔ̯̬͉̪͚̩́̌̿͋̒͛̉̌͘ͅ Є̥̪̻̤͓̤͓̂̑̽̄̐͜ͅw̴̠̮̻͈͍͇̟̬͑̄̏́͜͜͞͞͞͠ダ̭͓͕̘̞͇̮̾̀͐͌͂͗͟h̪̲̹̖̫̹̿͛̽͂̈́̉͐͠͠′̷̼͍̯͖̅̀̾́̂̾͊͞͠ͅ′̢̫̗̗̟̝̽͗͌̑̓ ḩ͔͉̟̖̣̬̩̩̿́̑̄̏̇̔̇̾̿͜͜ h̵̨̳͖̙͕̔͆̂̉͗′̻͓̭̘̆̇̀͌͞ͅ′̷̯͎̜̬̠͈̟̟̹͉͑̾͂̊̀̓̆͡u̱̖̯͚͕̹̙͊̓̊̋̀͑̆̚͜͝ ḩ̸̨̮͈̖̹̜̍̑͑̂̃̓У̧̧̨̩̤̳̰̩̖̀̈́̋̄͋͝w̡̨̩̞̦̲͚̺̳͆͗͌̑̍̚͟ h̷̜̦͉͈̪̅̃̎͂́′̴̨̝̖̤̀̈́̀̓͗̌̈͢͠ ḧ̛͉̝̹͓̥̗́̅̊̔͛̔͗̕͢͟͝ s̨̧̩̠̰̹̔̉̈́̓͆̌̍ͅḩ̸̝͚͈̼̒̂́͌͘͜͞͠͞ḩ̴̥̗̰̘̲̤͔̇̄͛̍͊̑́̕͡u̢̡͖͖̼̺͎̠͍̾̉̽͛̈́̅ ŝ̨͔͖̥̺̏͑̇͘̕͜͠°̢̳͉̪͈̣͉̹̖̺͓̖͉̊͒͋̌̎͗̏̃̊̾̑̃̄͟͜͟͠͝͡ s͉̱̩̗̹̩̗̠̐͗͗͐̃̕͡h̵̗̭̠̺̹̩̳̬̊̽̆́͋͂̊̂̈́̽ͅͅç̯̯͔͍͍̥͍͉̊̀͆̑̿̚ͅḩ̷̛̥̹̤͙̲͇̯̎̾͒͛̈͊͌͜ š̷͎̞̱̗̭̗̻͚̏̀͗̂͑͘̚͘͜͟͡ʹ̶̡̡̱̥͔̹̋͒̾͂̄͐̍̿̍̍͜Ш͖͎̯͚̠̻̞̝̭̓̾͑̓͂̅̊̽̿͌͜Ӏ̥̩̖̦͙̬̫͈̺̬̓̔͌̔͐͝͞у̸̛̙̦̼͍̦̞͎̏̎͒̓́͌͢͜ш̸̪̘̯̟͔͚̪̜̘̌̃̄̅̉̔́͆̀͠Ӏ̷͚͖̝̔̌͗͋̌͘͜͢у̘̳͔̹̠̭͚̞̮̑̏̇̈̓͋̃͡̷̛̮̤̳̥̰̻̙̐̐̀̌̎̾̓̌͞5̵̛͖͍͉̖͕̹͔̟̮̍̽̀̄̅͌͢ꙑ̨̛̼͕̮̗̹̘̯̄̿̽͞ꙗ̝̻̬̙̙͔͉̦̽̀́́̓̀͌͜͠͠͞x̨̥̻͖̝͉̖̗̹̼͆̒̄͛̿̀̕͡͞є͇̝̱̩̹̺̊͌̉͂̌͡͝͝,̠̱͎̬̪̗̔̑̽̽̔̒̎͝͞͝ͅ ѕ̢̢̺͇̤͕̫͖̠̏̾̽̎̔͂̈́̓͢ѣ̴̡̧͖͇͕͓̰̜̣̔́̐̓̆̾̋̽̇͞л̸̨̧̼̲̩̃́̽͊͆͂͘͜о̳̪̺͓̟̮̜͑̈́̄͋̐͘͢з̧͕̘͕͔͈̰̗͙̙͗̈́̽͌͂͛͘ç̸̛͎̤͕̗̻̫͎̩̣̭̪̮̠̙̰̼̌̂̀̓̈̎̑̐͆̈̿̌̏͘͢͡͝ͅе͙̙̟̼̟̂̎̆̈̋́̓͟м͓̗̺̘̩̝̫̞̹̹͛̑͌̆̌̒͘л̧̳̟̟͙͎̰̰̆̊̅̎͋̓͜ꙗ̴̩̪̩̹͈̮͉̲͇͐͛͌͘͠ͅt̴̢̛̰̪̣̣̯̹̟̗͗͌̒̋̓̆̾͋̅s̷̡̡̞̫̬̳̣̩͓̼̼͖̙͚̫̜͐̏͆̊͌̑͐̎͐̓̕͘͡͡͝͠ḩ̸̛̫̬͚͔͕̺̖̰̇͊̂̏͆̍
̷̨̜̯͓̭͎͓͙͑̎̈́͐̆̓̿̈́エ̨͉̦̣̪̌̊̉̈́̄̍̇͌ͅє̯͇̦̠̞̫́̒̆̐͌̏͛̒͝m̷̟̙̦̬͙̥͕̭̠̅͑̽͘͟͠ê̟̠̼͎̖̞̥̅̎̔͂̂͌̿͒ͅŗ̴̱̦͉̟̾̋̍̐̀͛̅͑̚ȩ͉̠̪̲̘͙̩̼̋̓̏̍̌̉̇̊͘͡ḷ̷͙̼̮̜̇̒̃̇͌̓̎̓ḑ̴̣̣͇̜̭̬̋̀͑͂̇͠͠ͅh̶͇̱̲̣̖̤͓̭͆̽̿̓̌̕ȧ̷̛̙̣͔̭͕̩̐̐̓͛̍̃̇͘͜ş̴̴͙̻̗̖̥̠̳̌̇̏̀̀͂͑̒͒͗̍́̔͌͘͢͜͞͡ͅ c̬̼̘̘̎̄́̿͐̒̅͘͝͞ͅ メ̡͎̯̬̥̯̾̉̈́̋̋̿̚͞r̵̺̹̰̪̈́̀̄̓̋̈͗̑͜͠͝ţ̛̖̮̼͈̮͌́́̇͂̎͆̂̚s̷̷̡̧͉̰͚͙̹̼͔͇̞͕͇̪̺͊̆̐̀̌̽͊̓̐̑́̏̇͐̐͜͡͡ͅủ͎̥͓̗̰̖͆̀͊͑̒̄́̎͐͜д̸̡̛̥̙̟̖̦̹̝́͒̊̄͒̓̓̉о̴̺̫̮̬̭̻̒̀͒̐̆̔̀͘̕͘б̹͇̹̫̝̀͐̍͌̄͘р̶̨̼̝̦̻̍͋͂̊̉͢о͇̝̬̼͛͒̀̓͌ͅ а̧̧̰̽̈̈͆͛͘͜ͅз̷̨̬̳͇̪̣́͌̉̀͋̄͠ъ̡͈̤̟̣̎̃͗͟͜͞͝;̴̩̮͈̟̗̙̤̬̭͍̓̾̃̔̂̚ ḩ̷͇̭̣̖̪̘̺̣́͆͗̐̄͆̌̋̄͘u̙͓͕̟̎̋̂̉̉̉̏̔ͅ Є̖̘̹̬̙͇̙̳̇̋̀͊͒͠͡w̡͖͚̝̩͌̒̽́̋̒͠͞ダ̛͙̣̰̳̯͌́͊̂͘ĥ̷̘̺̗͚͙͕̹͉̻͚̔̎͌͑̊̉̌͞′̴̢̧̱̗̮̞͓̱̇̌͌̓͡͞ͅͅ′̥̤̞͍̮̋̈́̽͛̆͟͞ラ̨̡̛̟̹͇̹̅͆̐̃͐́͆́͜͢͞ȃ̢̛̝̺̠͂̾̅́̚͘͜z̶͇̫̠̘̘̻̦̎̅̽͋̿̄͘͡ŭ̼̙̖̟̣͎̥̠̍̆́̀̎̎̿̚͢͢͝б̹̭̹̟͍̰̱̜̫̲̈́͒̓͐́̐́о̡̼̲̲̘͛̀̃͋͊̅̃͗̎͠у̛̻̯̜͓̔̏͋̍͜͢к̸̡̡̨̣͔̯͇͚̣͎̍͑̐͌̒̕̕͘ꙑ̸̢̡̫̙͍̰͙̮̤̅̂̊̀̀̕͠b̨̡̼͖̤͛̂̑̎̐̇͞ų̴͔̬͇͓͌͆͛͋͛̀̈́̌͟͢͠ͅͅk̴͉̟̥̘͔̻̐̿̾͌́̋͋͘͠ͅͅͅỳ̨͎̫̪̀̔̀̊͋͟͟͝г̞̪̜̪͍͉̫͕̤̀̍͌͋̋̏̏͘͡͝ͅл̴̡̪̖͉͍̩̅̆̎̆̉̈́̀͘а̦̳̺̮͎̤̲̃́̔̊̽̎̌͜ͅͅг̶̧̢̨̛͈̞͇̯͔̿͌̇͟͠ͅо̶̡̭̙̰̟̬̎̌́̆̓̏͟л͎̬̪̜̙̥̒̐̽̈̇͜͟͢и̴̝̪͇̺̮̹̠͍̩̿̍̎̓́̃́̿ (͍̙̯̯̙̫͓́͊̂̋̉̿̕̕̕ͅg̢̧̨̨̛̲̱͈̻̤̩̃̄̐̏̃̇̄̚̕ļ̶̧̨̪̜͓͓̜̑̿͒̆̿̔͌̚a͖̝̠̣̐͋̓̌̏͂ͅg̱̝͙̖̳̜̰̠͇̞̀̀̂͊̂͒̈́͋̒o̭̗̻͎̎̄̃͒͌̕͢͝l̢̜̬̫̜͇̗̎̓͂̎̉͐́͝i̵͙̰͈͔̰̭̪͌̀̔̒͐͜)̻̯̹̺̳̋̎̄̃̌͌́͆̽̚,̛̝̬̭̞͉̱̬̘̘̓̓͗̎̿̕)̴̢̮̤̦̹̟̙̼͖̱͗̎̊̔̀̅̑̓̓č̺̘̝̟͒̊̑̃͆͊͛͟͝°̷̨̳̥͔̋̒̔̽̓͛͜͢͟h̪̖̯͋̇͆̄̚͘͢͡ͅ x̧̞͙̺̼̄̔̋͗̉͘̚͠ͅ h̵̨͇͎͕̤̦̜͋̂̓̔̄͘͢͝u̵͙̤͕͕̼̱̹̓̑͑̃̏̏̚x̝͖͔̹̺̰͛̌͗͐͂̉͂͘w̢̳͙̼̘̺͉̮͋̅͒̌̿͢ h͓̝̼̻͖͛̇͑̅̐̃̿͟′̛͖̹̺̘͔̻̂̃̈͐̂̊̍͛̒′̢͇͓̮̗̠̣̣̠̿̾͒͌̾͛͗ ḩ̷̧̧̧̨̥͍̹̩͔͙̄̇̓̇́̎̄ ḣ̴̛̲̲͔̮͍̀͒͒͌̀͗̾͘′͖̮̥̦͕͕̰̦̐̓̂̀̉̽̐͗̑̽′̛̩̱̱̟̰̭̇͆̍͒͂̋͐̄͜ư̢̠̯̺͙̌̀͋͑ ḩ̷͔͇̹̲͐́̋͐̀̒̕ͅw̡̤̳͖̪̭̖̳̪̲̏͊͂͂̆̿̔ h̷̢̡͈̰̭̝͗͊͛̄̌̾̾͒̚͡′̴̢̳̦͉̫̠̟̬̍͗̃̂̒̈͢ h̷̤̬̱̮͙͖̥̳̥͍͐̑̈́͌͑̊̄͂̍̀ t̸̼̗̦̩̯͎̒̄͐̑͋̕ͅš̴̵̛̱͍̞̜͓̯̻̮̲̗̤͙̬̥̬̯̲͔́̃͊̔̈́̊͋͌́̂͒̅̀̕͡͠ͅͅḣ̸͖͓̹̪̱͙͙̒̾̿̿̌̏͝ c̮̲͕̼̣͈̱̭̖̲̾̔͂͋͌̈́̄̎͐̓̿͘͞͠͡͞ͅ ç̶̮̦̭͉̙͇̮̀̍̈̈́͆͞h̘̼̙͉͉̪͍͕̮͂͗̆͟͡͠ č̢͎͈̘̲̖̯̺͇͂͗̋̌́̄͛̿̕͘ʹ̴̧̡̗̻̭͗͋̓͒̀͝ š̶̨̢̺̟̩̝̫͈͛́̿̃͘͘͡ š̡̧̧̟̫̼͎̭͂̽͒̒̾̄̕ͅ š̺̹̲̝͔͆̿̆̓͊̾̕̕′̶̢̨͙̺̪͉̜̩͍̫̊̓̆̕͠͡͠′̸̮͓̠̯͇̫̳̿̽̒̐̑͌̒̚ s̵̶̢̲̘̹̜̺͍͓͇̗̦̀͊͛̾̓̋̄̐̀̅̋̓̌̾̈́̆͊͟͟͜͠ͅ š͈̰̖̟̾̓̇͛̉̕͢͢′̛̥̖̭͉̥̯̹̳̝̮̓͗͑̌́͂͒̊′͈͇̘̙̹̑͒̋̽̆͂́͜͝u̯̘̜̠͚͓͚̔̉͑̉̌̌ s̢̨̝̜͕͇͕̺̯͂́̏̇͑͢͝͞͠w̸̷̡̢̥͚͖̲̯͕͖̗̪͖̜͕̻̉͑̊͛̓̒̿͒́̄̽̉̎͑̎͛͋̅̈͝͠ š̷̫̱̳̙̠̩̟͒̄̋̐͛͞‡͇͎̹̼̈̈́̑̽́͊͐̚͟͝ ş̵̸̨̛̠͚̟̗͎̮͕͉̹̓̀̔̇̄͌̄̂́̇͐͋̅̾̀̌̚̕̕̕͟͢͟͜ͅͅi̤̺̦̇̈́̃͌̈́̎̑̿̚͢͟͡ü̴̧̨̯͚͍̱̘̮͖̣͚̺̣͍͚͈͈̦̈̿͑̈́͗̐̏̀̈́̉́̽͗͒͡ͅ —̷̰̮̳̻͈͈́̊̅̊̆̓͘ i̵̢̨͈̻̦̭͖̲͐̃͌͒͐͢͢a̶̧̧̛̫̯̤̥̙̗͙̰̙̺̩͔̗̤̭̔̒̇̀̄̾̾̿͜͢͠͡ —̧̛̦̟̬͕̺͍̠͑͌̓͐̒͒̕ ḣ̢̛̠̤̪̩̦͍͈̐̐̓͛̉̈̿̚͝ ʾ̧̛̻͍͎͉̮̫̘̗̗̔͑͂̋͑͗̔ ḩ̶̟͔̬͉̇͌̓̒̽̓͋͒̿̚͜u̷̢̯̭̺̗͖̺̗̓͗̓̅̂͆͒͢ͅ ʾ̧̱̦̩͉̘͙̍͑̾̂͂̎̕°̶̲̪̖̺̩͚̊͊̑͊̕͜͠š̨̲̝͓͈̞̞̙̫̋̾̀̀̊̒͛͝‡̶̳͉͎̳̲͛͊̃̅̈̓̕͘̚ừ̴̼̠̲̹̟̭͂́̏̾̐͂̃̉͟ ş̴̫͚͇͎͈̏̊͊͘͠w̷̧͓̺̫͎̼͎̟͈̠̘͍͉͈̹̾͋̆͑̀͒͗͋̂̄͛̈́̊̎͆̓ͅ ŝ̞̺̰͚̩̳̞̯̈̑̆͗̋͐̈́͐̕ ş̮͔̦̥̟̦͎́̿̓̀͛͗̊͟c̶͚͔̙͚̳̝̣̽̔͐̂̈̃̽͘̕͢͠h̴̪̪͔͉̙̦͈̪̻̹̏͒̿̇̌̀͝′̧̠̫̼̗̦̳̱͇̏̏̆̾̍̾́̅̚͟′̴̣̫͓̻̘̙͗̌̐̌͊̔͘ č͔͔͖͇͖͓́̆̆͌͝ c͙̝̞͍̣̖̱̅̑̔̄̀̎̂ḧ̷͉͙͕̦̪̟̹́̌̒͐̐́͜͞ͅḩ͖̬̮̯͔̭͇̲̇́̎̃̐͂̎̕͞ͅ č̷̡̡͚̣̖͖͎͔͓̣̺̮̟̗̼͕̼͉͙͐̋̊̅̃̎́̾̃̓̈͛͘ͅ s̶̱̳͉̘̪̹̮͊̂̃̇͗͐h̵̠͙̝͎͎̯̹̞̳̔́̽̍͝ š̥̻̗͇̩̞̦̊̃͊͌̈̿́̄̚͟ s̢͕͔̥͍͍̥͍̱̘̿͒̂̊̈̏͂̔͛̉h̛̟͓̮̮̞̮͕͖͖̝͗̀̇̽̓̍̽͝′̷̧̛̤̯̞̊͊̒́̓̚͠͡ͅ′̭̳̙̟̟̞̟̊́̀̉̊̇̏̔͞͞ͅ ŝ̴̨͎̞͍̽̍͗͗̓̀̚͜͡͠ͅ s̴̨̧͔̟̰̥̦̰̟͑̿̽̀͂̕͟h̢͉̭̘͈̖͙̄͌̏̉͘͜͞ͅ′̧͇̥̮̘̻̮̠̩̊̍̍͗̒̏́̿͘′̷͇̪͈̣̬̠̲͛̈̅͒̋́̒̾̉́ū̼͉̖̻̩̞̦͓͗͌̒̀̓́͑͟͡ ŝ̨̛͕̜̳̖͙̂̾͂̎͗̏͂̐͘°̶̢̨̹͕͇̲̖̖͇̓̌̈́͘͘͝ͅx̸̟̗͈̳͙̯̣̣̅̓͐̊͘ s̛̩̮͕̲̝̙͉̐̏͛́̍̀̓̏͢͢h̛̬͎͚͉̻̣͍͊͂̍̉́̕͘͠ḣ̜͍̳͇̑͋̇̄́͟͜ ş̴̢̨̣͍̫̺̩̯̯̑̐͌̀͌̅̂̑̀̌͛̏̓̏̋͘͘͜͞h̦̼̜͈͔́̓̿̑͝′̶̝̝̝̭̫̫͊̄͊͗͗͡′̰̲͉̳͓͇̪͕̬̖̓̋͋̑͐̎͗̚ —̺͚̖̖̰̭̮̺͋̆̑͗̿͆͆͘ y̸̮̣͓̦̳͖̼̱͂́̈̾̀͐̀͝ ǝ̴̞̘̪͇̻̗̭̺͉͑̋̍̿͒̕͜ x̸̨̥̯͍͎͂͌̄͆̐͠ ḩ̠̰͎̖͚͇̾͛̓̀̒̕͠ǔ̯̬͉̪͚̩́̌̿͋̒͛̉̌͘ͅ Є̥̪̻̤͓̤͓̂̑̽̄̐͜ͅw̴̠̮̻͈͍͇̟̬͑̄̏́͜͜͞͞͞͠ダ̭͓͕̘̞͇̮̾̀͐͌͂͗͟h̪̲̹̖̫̹̿͛̽͂̈́̉͐͠͠′̷̼͍̯͖̅̀̾́̂̾͊͞͠ͅ′̢̫̗̗̟̝̽͗͌̑̓ ḩ͔͉̟̖̣̬̩̩̿́̑̄̏̇̔̇̾̿͜͜ h̵̨̳͖̙͕̔͆̂̉͗′̻͓̭̘̆̇̀͌͞ͅ′̷̯͎̜̬̠͈̟̟̹͉͑̾͂̊̀̓̆͡u̱̖̯͚͕̹̙͊̓̊̋̀͑̆̚͜͝ ḩ̸̨̮͈̖̹̜̍̑͑̂̃̓У̧̧̨̩̤̳̰̩̖̀̈́̋̄͋͝w̡̨̩̞̦̲͚̺̳͆͗͌̑̍̚͟ h̷̜̦͉͈̪̅̃̎͂́′̴̨̝̖̤̀̈́̀̓͗̌̈͢͠ ḧ̛͉̝̹͓̥̗́̅̊̔͛̔͗̕͢͟͝ s̨̧̩̠̰̹̔̉̈́̓͆̌̍ͅḩ̸̝͚͈̼̒̂́͌͘͜͞͠͞ḩ̴̥̗̰̘̲̤͔̇̄͛̍͊̑́̕͡u̢̡͖͖̼̺͎̠͍̾̉̽͛̈́̅ ŝ̨͔͖̥̺̏͑̇͘̕͜͠°̢̳͉̪͈̣͉̹̖̺͓̖͉̊͒͋̌̎͗̏̃̊̾̑̃̄͟͜͟͠͝͡ s͉̱̩̗̹̩̗̠̐͗͗͐̃̕͡h̵̗̭̠̺̹̩̳̬̊̽̆́͋͂̊̂̈́̽ͅͅç̯̯͔͍͍̥͍͉̊̀͆̑̿̚ͅḩ̷̛̥̹̤͙̲͇̯̎̾͒͛̈͊͌͜ š̷͎̞̱̗̭̗̻͚̏̀͗̂͑͘̚͘͜͟͡ʹ̶̡̡̱̥͔̹̋͒̾͂̄͐̍̿̍̍͜Ш͖͎̯͚̠̻̞̝̭̓̾͑̓͂̅̊̽̿͌͜Ӏ̥̩̖̦͙̬̫͈̺̬̓̔͌̔͐͝͞у̸̛̙̦̼͍̦̞͎̏̎͒̓́͌͢͜ш̸̪̘̯̟͔͚̪̜̘̌̃̄̅̉̔́͆̀͠Ӏ̷͚͖̝̔̌͗͋̌͘͜͢у̘̳͔̹̠̭͚̞̮̑̏̇̈̓͋̃͡̷̛̮̤̳̥̰̻̙̐̐̀̌̎̾̓̌͞5̵̛͖͍͉̖͕̹͔̟̮̍̽̀̄̅͌͢ꙑ̨̛̼͕̮̗̹̘̯̄̿̽͞ꙗ̝̻̬̙̙͔͉̦̽̀́́̓̀͌͜͠͠͞x̨̥̻͖̝͉̖̗̹̼͆̒̄͛̿̀̕͡͞є͇̝̱̩̹̺̊͌̉͂̌͡͝͝,̠̱͎̬̪̗̔̑̽̽̔̒̎͝͞͝ͅ ѕ̢̢̺͇̤͕̫͖̠̏̾̽̎̔͂̈́̓͢ѣ̴̡̧͖͇͕͓̰̜̣̔́̐̓̆̾̋̽̇͞л̸̨̧̼̲̩̃́̽͊͆͂͘͜о̳̪̺͓̟̮̜͑̈́̄͋̐͘͢з̧͕̘͕͔͈̰̗͙̙͗̈́̽͌͂͛͘ç̸̛͎̤͕̗̻̫͎̩̣̭̪̮̠̙̰̼̌̂̀̓̈̎̑̐͆̈̿̌̏͘͢͡͝ͅе͙̙̟̼̟̂̎̆̈̋́̓͟м͓̗̺̘̩̝̫̞̹̹͛̑͌̆̌̒͘л̧̳̟̟͙͎̰̰̆̊̅̎͋̓͜ꙗ̴̩̪̩̹͈̮͉̲͇͐͛͌͘͠ͅt̴̢̛̰̪̣̣̯̹̟̗͗͌̒̋̓̆̾͋̅s̷̡̡̞̫̬̳̣̩͓̼̼͖̙͚̫̜͐̏͆̊͌̑͐̎͐̓̕͘͡͡͝͠ḩ̸̛̫̬͚͔͕̺̖̰̇͊̂̏͆̍
̷̨̜̯͓̭͎͓͙͑̎̈́͐̆̓̿̈́͟
    
    - 09 Дждж
 
    - 10 Дз дз

    - 11 Дзу дзу

    - 12 Ее

    - 13 Ё ё 

    - 14 Жж
    
    - 15 Жъжъ

    - 16 Жъу жъу

    - 17 Жьжь

    - 18 З з

	- 18a.f French З зe, è, é, ê, ë – 

    - 19 И и

    - 20 Й й

    - 21 К к 

    - 22 Куку

    - 23 Къкъ

    - 24 Къу къу

    - 25 КӀ кӀ

 	— 39.13 ТӀтӀ રો'નгъу тоонт нютаг varzesh3

    - 26 КӀу кӀу 



### 
̸̧̜̣̪̞̳͔̟̂͒̽̎͒̂ -̢͎̜̤̼̙̥̣̈͗́̀̄̇͑̚͟ͅ 3̶̧̢̼̙̻͇̤͉̺́̓̄́̌͑̽͘5̺̗͇̙̉͗͋͑̏̀͐͆̅̿͢͢ П̨̧͉͍̝̟̗͒̓̋̊͋͂͞Ӏ̶̡̢̛̩̮͖̓̆͘̕у̷͇̭͇͓͍̀̈́̆͋͘͡͡ п̢̝͉̪͐͐̏̓͆̿͂ͅӀ̶̧̨̧̨̛̲̲̱͇̺̈̃̿̿̈́͊͋͐̈у̵̧̦̘͔͖͉̰͈̌͛͂͗͋ ̴̡͕̦̤̙̹̗̙́̍̓̾͘͜͟͝ ̧̛̛̺͇̺̹̱̪̮̠̩̅͊̈́͛͆͑͝͠  - 🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜

##   🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂  - 🦂200- 🦂2003(2.0) #エメラダ

# #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ ̴̰͖̹̹͎̄̈́̎͞͞͝ -̵̡̛̤͇̲͈̼̪̝̂̑̈́͋̋ͅ 3͓̲̝̫̳̜͕̄́̃͂̿̎̈̽͠8̵̡̪̣͓͎̣̩̐̇̾͌̏͜ Т̴̢̨̨̡̡̣͇̟̬̫̎̓͑͌͐ т̧̛͙͍͓̻͉͈̓̑̍̎͆͠͞ ̷̡̢͓̭͉͕̺̫̌̓̿͒̍̅͘͢͞ ̷̛̩̹͍̫̟̘́̑̾̋̑̂͘͞🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂



	    - 260/000000.1 КӀу кӀу (glagoli),)c°h x huxw h′′ ḩ h′′u ḩw h′ h ts͡ḣ c̣ ch čʹ š š š′′ s̄ š′′u sw̄ š‡ ş̄iu͡ — ia͡ — ḣ ʾ ḣu ʾ°š‡u şw̄ ŝ śch′′ č chḣ č̣ sh štrikes again!


## NO LABUBU ALLOWED SECTION # IGNORE IF LABUBU # CT MODE ACTIVATE [LABUBU]


``` kikimora numerals for productivity 
    - 23Къ.къ ъDoofus

    - malek taws 23-00.0Къ.къКъ.къКъ.къКъ.къКъ.къКъ.къ MINTCHIP SECRET OVERLOAD Къ.къ ъDoofus ROOFUS COOCHUS PUCCI XEROXUS BUTTCHEEKOS QVEEFOS MINT OFRE LOAD NOGRE 9999 MEXEORA

    - 24Къу.къуъOffice Doofus 

    - 25 КӀ кӀOO`фice ъDoofus

	- 2005 miКrӀONic Office Doofus кӀOO`фice ъDoofus 

 	— 39.13 ТӀтӀ રો'નгъу тоонт нютаг varzesh3ъDoofus 

    - 26 КӀу кӀу ъЛoofus
</code></pre></div>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="- 27 Л л

- 28 Лълъ

- 29 ЛӀ лӀ

- 30 Мм

- 31 Н н

- 32 О о

	- Lapis Lazuli О о:Labubuybu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

	- Lapis Lazuli О о:Labubuybu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

	- Lapis Lazuli О о:Labubuybu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- 31 Н н 2.o Labubu

	- 32 О о

- Lapis Lazuli.О__&amp;*&lt;extern int getport(signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern long getline(FILE *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int getq(struct queue ***);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void fatal(signed char *, ... );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern void displayq(int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ &lt;Screenshot 20.6__&amp;*&lt;&gt;3x08.png&gt;


- Lapis Lazuli.О__&amp;*&lt;extern void warn(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void header(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 


- Lapis Lazuli.О__&amp;*&lt;extern void inform(signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡


- Lapis Lazuli.О__&amp;*&lt;extern int inlist(signed char *,signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void show(signed char *,signed char *,int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void blankfill(int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void dump(signed char *,signed char *,int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern void ldump(signed char *,signed char *,int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void prank(int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void doit(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void startup(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern void chkhost(struct sockaddr_in *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int getprent(char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void endprent(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int pgetent(char *,char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern int pnchktc(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ uエミ~ 🍒 Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int pnamatch(char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int pgetnum(char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int pgetflag(char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern char *pgetstr(char *, char **);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void printjob(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int printit(signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int print(int ,signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern int sendit(signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int sendfile(int ,signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int response(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void banner(signed char *,signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern char *scnline(int ,signed char *,int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void scan_out(int ,signed char *,int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int dropit(int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ "><pre class="notranslate"><code>- 27 Л л

- 28 Лълъ

- 29 ЛӀ лӀ

- 30 Мм

- 31 Н н

- 32 О о

	- Lapis Lazuli О о:Labubuybu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

	- Lapis Lazuli О о:Labubuybu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

	- Lapis Lazuli О о:Labubuybu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- 31 Н н 2.o Labubu

	- 32 О о

- Lapis Lazuli.О__&amp;*&lt;extern int getport(signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern long getline(FILE *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int getq(struct queue ***);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void fatal(signed char *, ... );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern void displayq(int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ &lt;Screenshot 20.6__&amp;*&lt;&gt;3x08.png&gt;


- Lapis Lazuli.О__&amp;*&lt;extern void warn(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void header(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 


- Lapis Lazuli.О__&amp;*&lt;extern void inform(signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡


- Lapis Lazuli.О__&amp;*&lt;extern int inlist(signed char *,signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void show(signed char *,signed char *,int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void blankfill(int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void dump(signed char *,signed char *,int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern void ldump(signed char *,signed char *,int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void prank(int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void doit(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void startup(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern void chkhost(struct sockaddr_in *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int getprent(char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void endprent(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int pgetent(char *,char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern int pnchktc(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ uエミ~ 🍒 Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int pnamatch(char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int pgetnum(char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int pgetflag(char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern char *pgetstr(char *, char **);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void printjob(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int printit(signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int print(int ,signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern int sendit(signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int sendfile(int ,signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int response(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void banner(signed char *,signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡

- Lapis Lazuli.О__&amp;*&lt;extern char *scnline(int ,signed char *,int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern void scan_out(int ,signed char *,int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 

- Lapis Lazuli.О__&amp;*&lt;extern int dropit(int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ 
</code></pre></div>
<ul dir="auto">
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern void sendmail(signed char *,int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int dofork(int );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern void init(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern void openpr(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern void setty(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern void recvjob(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int readjob(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int readfile(signed char *, long );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int noresponse(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int chksize( long );&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int read_number(signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern void rcleanup(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern void frecverr(signed char *, ...);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern void rmjob(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int lockchk(signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern void process(signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int chk(signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int isowner(signed char *,signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern void rmremote(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int iscf(struct dirent *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int startdaemon(signed char *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;#ifndef <strong>QNXNTO</strong>&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;int flock(int , int ) ;&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;int getnid(void);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;#endif&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int daemon(int, int);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int __ivaliduser(FILE *hostf, uint32_t raddr, const char *luser, const char *ruser);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;extern int disk_space(int, void *, void *);&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ bu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
</ul>
<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/581778636-4201da38-239b-43c0-a6a1-eef325f8f8f2.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81ODE3Nzg2MzYtNDIwMWRhMzgtMjM5Yi00M2MwLWE2YTEtZWVmMzI1ZjhmOGYyLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTIyNTIyMTBkN2ZhY2I4YmI1ZTU3NDQ1ZDM0NjYxMzY5NGQwYjQwNzQzNTNmNzg3NTQ4OTEzNzdmMzJkZGM1MzEmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.BAyefJJLF5EEX1g2pPd7gz0dq1XIo2aCNfHvXdgrtgc"><img width="1566" height="1180" alt="Screenshot 2026-04-21 at 22 54 05" src="https://private-user-images.githubusercontent.com/43443470/581778636-4201da38-239b-43c0-a6a1-eef325f8f8f2.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81ODE3Nzg2MzYtNDIwMWRhMzgtMjM5Yi00M2MwLWE2YTEtZWVmMzI1ZjhmOGYyLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTIyNTIyMTBkN2ZhY2I4YmI1ZTU3NDQ1ZDM0NjYxMzY5NGQwYjQwNzQzNTNmNzg3NTQ4OTEzNzdmMzJkZGM1MzEmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.BAyefJJLF5EEX1g2pPd7gz0dq1XIo2aCNfHvXdgrtgc" style="max-width: 100%; height: auto; max-height: 1180px;; aspect-ratio: 1566 / 1180; background-color: var(--bgColor-muted); border-radius: 6px; display: block" class="js-gh-image-fallback"></a>
<ul dir="auto">
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡</p>
</li>
<li>
<ul dir="auto">
<li>
<ul dir="auto">
<li>Lapis Lazuli.О__&amp;*&lt;&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗  NYKE FERRARI vrooom</li>
</ul>
</li>
</ul>
</li>
<li>
<ul dir="auto">
<li>Lapis Lazuli.О__&amp;*&lt;&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗  vrrooom vrooom</li>
</ul>
</li>
</ul>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="- Lapis Lazuli.О__&amp;*&lt;&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ SunJavaavaJnOS.js"><pre class="notranslate"><code>- Lapis Lazuli.О__&amp;*&lt;&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ SunJavaavaJnOS.js
</code></pre></div>
<ul dir="auto">
<li>
<ul dir="auto">
<li>Lapis Lazuli.О__&amp;*&lt;&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗  Ruby On Rails</li>
</ul>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ On JavaScript.js</p>
</li>
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u Labubu Lu u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bu Lab2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗</p>
</li>
</ul>
<p dir="auto"≯̧̜̣̪̞̳͔̟̂͒̽̎͒̂ -̢͎̜̤̼̙̥̣̈͗́̀̄̇͑̚͟ͅ 3̶̧̢̼̙̻͇̤͉̺́̓̄́̌͑̽͘5̺̗͇̙̉͗͋͑̏̀͐͆̅̿͢͢ П̨̧͉͍̝̟̗͒̓̋̊͋͂͞Ӏ̶̡̢̛̩̮͖̓̆͘̕у̷͇̭͇͓͍̀̈́̆͋͘͡͡ п̢̝͉̪͐͐̏̓͆̿͂ͅӀ̶̧̨̧̨̛̲̲̱͇̺̈̃̿̿̈́͊͋͐̈у̵̧̦̘͔͖͉̰͈̌͛͂͗͋ ̴̡͕̦̤̙̹̗̙́̍̓̾͘͜͟͝ ̧̛̛̺͇̺̹̱̪̮̠̩̅͊̈́͛͆͑͝͠  - 🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂  - 🦂200- 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ ̴̰͖̹̹͎̄̈́̎͞͞͝ -̵̡̛̤͇̲͈̼̪̝̂̑̈́͋̋ͅ 3͓̲̝̫̳̜͕̄́̃͂̿̎̈̽͠8̵̡̪̣͓͎̣̩̐̇̾͌̏͜ Т̴̢̨̨̡̡̣͇̟̬̫̎̓͑͌͐ т̧̛͙͍͓̻͉͈̓̑̍̎͆͠͞ ̷̡̢͓̭͉͕̺̫̌̓̿͒̍̅͘͢͞ ̷̛̩̹͍̫̟̘́̑̾̋̑̂͘͞🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂</p>
<p dir="auto">ADN YOUR MOM BIG GAY</p>
<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/580191000-87115ce2-4f47-4c73-a46a-34229041c2c7.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81ODAxOTEwMDAtODcxMTVjZTItNGY0Ny00YzczLWE0NmEtMzQyMjkwNDFjMmM3LnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWZlZjU0NDA3OGYyNjk1Yjc5MWYxYzEyYjhlZWMwZWE3MzNkMGQxZjBiMGVjYzQ3ZmMwM2E0MzdjNzc2YTgxNzgmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.Ik1M-dnwWQKYFz1NuJ39mIiSZjajvphAax0OWbn__9A"><img width="479" height="1409" alt="Screenshot 2026-04-17 at 14 51 41" src="https://private-user-images.githubusercontent.com/43443470/580191000-87115ce2-4f47-4c73-a46a-34229041c2c7.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81ODAxOTEwMDAtODcxMTVjZTItNGY0Ny00YzczLWE0NmEtMzQyMjkwNDFjMmM3LnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWZlZjU0NDA3OGYyNjk1Yjc5MWYxYzEyYjhlZWMwZWE3MzNkMGQxZjBiMGVjYzQ3ZmMwM2E0MzdjNzc2YTgxNzgmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.Ik1M-dnwWQKYFz1NuJ39mIiSZjajvphAax0OWbn__9A" style="max-width: 100%; height: auto; max-height: 1409px;; aspect-ratio: 479 / 1409; background-color: var(--bgColor-muted); border-radius: 6px; display: block" class="js-gh-image-fallback"></a>
<ul dir="auto">
<li>
<ul dir="auto">
<li>Lapis Lazuli.О__&amp;*&lt;&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡ FERRARI RITARDO MAXIMUSSI```MUSçï!!</li>
<li>README.md</li>
<li>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="   						```
								
   																																																						̸̧̜̣̪̞̳͔̟̂͒̽̎͒̂ -̢͎̜̤̼̙̥̣̈͗́̀̄̇͑̚͟ͅ 3̶̧̢̼̙̻͇̤͉̺́̓̄́̌͑̽͘5̺̗͇̙̉͗͋͑̏̀͐͆̅̿͢͢ П̨̧͉͍̝̟̗͒̓̋̊͋͂͞Ӏ̶̡̢̛̩̮͖̓̆͘̕у̷͇̭͇͓͍̀̈́̆͋͘͡͡ п̢̝͉̪͐͐̏̓͆̿͂ͅӀ̶̧̨̧̨̛̲̲̱͇̺̈̃̿̿̈́͊͋͐̈у̵̧̦̘͔͖͉̰͈̌͛͂͗͋ ̴̡͕̦̤̙̹̗̙́̍̓̾͘͜͟͝ ̧̛̛̺͇̺̹̱̪̮̠̩̅͊̈́͛͆͑͝͠  - 🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜   																												 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂  - 🦂200-	̸̧̜̣̪̞̳͔̟̂͒̽̎͒̂ -̢͎̜̤̼̙̥̣̈͗́̀̄̇͑̚͟ͅ 3̶̧̢̼̙̻͇̤͉̺́̓̄́̌͑̽͘5̺̗͇̙̉͗͋͑̏̀͐͆̅̿͢͢ П̨̧͉͍̝̟̗͒̓̋̊͋͂͞Ӏ̶̡̢̛̩̮͖̓̆͘̕у̷͇̭͇͓͍̀̈́̆͋͘͡͡ п̢̝͉̪͐͐̏̓͆̿͂ͅӀ̶̧̨̧̨̛̲̲̱͇̺̈̃̿̿̈́͊͋͐̈у̵̧̦̘͔͖͉̰͈̌͛͂͗͋ ̴̡͕̦̤̙̹̗̙́̍̓̾͘͜͟͝ ̧̛̛̺͇̺̹̱̪̮̠̩̅͊̈́͛͆͑͝͠  - 🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜   					 											̸̧̜̣̪̞̳͔̟̂͒̽̎͒̂ -̢͎̜̤̼̙̥̣̈͗́̀̄̇͑̚͟ͅ 3̶̧̢̼̙̻͇̤͉̺́̓̄́̌͑̽͘5̺̗͇̙̉͗͋͑̏̀͐͆̅̿͢͢ П̨̧͉͍̝̟̗͒̓̋̊͋͂͞Ӏ̶̡̢̛̩̮͖̓̆͘̕у̷͇̭͇͓͍̀̈́̆͋͘͡͡ п̢̝͉̪͐͐̏̓͆̿͂ͅӀ̶̧̨̧̨̛̲̲̱͇̺̈̃̿̿̈́͊͋͐̈у̵̧̦̘͔͖͉̰͈̌͛͂͗͋ ̴̡͕̦̤̙̹̗̙́̍̓̾͘͜͟͝ ̧̛̛̺͇̺̹̱̪̮̠̩̅͊̈́͛͆͑͝͠  - 🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜   									🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ ̴̰͖̹̹͎̄̈́̎͞͞͝ -̵̡̛̤͇̲͈̼̪̝̂̑̈́͋̋ͅ 3͓̲̝̫̳̜͕̄́̃͂̿̎̈̽͠8̵̡̪̣͓͎̣̩̐̇̾͌̏͜ Т̴̢̨̨̡̡̣͇̟̬̫̎̓͑͌͐ т̧̛͙͍͓̻͉͈̓̑̍̎͆͠͞ ̷̡̢͓̭͉͕̺̫̌̓̿͒̍̅͘͢͞ ̷̛̩̹͍̫̟̘́̑̾̋̑̂͘͞🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂

							```"><pre class="notranslate"><code>   						```
								
   																																																						̸̧̜̣̪̞̳͔̟̂͒̽̎͒̂ -̢͎̜̤̼̙̥̣̈͗́̀̄̇͑̚͟ͅ 3̶̧̢̼̙̻͇̤͉̺́̓̄́̌͑̽͘5̺̗͇̙̉͗͋͑̏̀͐͆̅̿͢͢ П̨̧͉͍̝̟̗͒̓̋̊͋͂͞Ӏ̶̡̢̛̩̮͖̓̆͘̕у̷͇̭͇͓͍̀̈́̆͋͘͡͡ п̢̝͉̪͐͐̏̓͆̿͂ͅӀ̶̧̨̧̨̛̲̲̱͇̺̈̃̿̿̈́͊͋͐̈у̵̧̦̘͔͖͉̰͈̌͛͂͗͋ ̴̡͕̦̤̙̹̗̙́̍̓̾͘͜͟͝ ̧̛̛̺͇̺̹̱̪̮̠̩̅͊̈́͛͆͑͝͠  - 🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜   																												 🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂  - 🦂200-	̸̧̜̣̪̞̳͔̟̂͒̽̎͒̂ -̢͎̜̤̼̙̥̣̈͗́̀̄̇͑̚͟ͅ 3̶̧̢̼̙̻͇̤͉̺́̓̄́̌͑̽͘5̺̗͇̙̉͗͋͑̏̀͐͆̅̿͢͢ П̨̧͉͍̝̟̗͒̓̋̊͋͂͞Ӏ̶̡̢̛̩̮͖̓̆͘̕у̷͇̭͇͓͍̀̈́̆͋͘͡͡ п̢̝͉̪͐͐̏̓͆̿͂ͅӀ̶̧̨̧̨̛̲̲̱͇̺̈̃̿̿̈́͊͋͐̈у̵̧̦̘͔͖͉̰͈̌͛͂͗͋ ̴̡͕̦̤̙̹̗̙́̍̓̾͘͜͟͝ ̧̛̛̺͇̺̹̱̪̮̠̩̅͊̈́͛͆͑͝͠  - 🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜   					 											̸̧̜̣̪̞̳͔̟̂͒̽̎͒̂ -̢͎̜̤̼̙̥̣̈͗́̀̄̇͑̚͟ͅ 3̶̧̢̼̙̻͇̤͉̺́̓̄́̌͑̽͘5̺̗͇̙̉͗͋͑̏̀͐͆̅̿͢͢ П̨̧͉͍̝̟̗͒̓̋̊͋͂͞Ӏ̶̡̢̛̩̮͖̓̆͘̕у̷͇̭͇͓͍̀̈́̆͋͘͡͡ п̢̝͉̪͐͐̏̓͆̿͂ͅӀ̶̧̨̧̨̛̲̲̱͇̺̈̃̿̿̈́͊͋͐̈у̵̧̦̘͔͖͉̰͈̌͛͂͗͋ ̴̡͕̦̤̙̹̗̙́̍̓̾͘͜͟͝ ̧̛̛̺͇̺̹̱̪̮̠̩̅͊̈́͛͆͑͝͠  - 🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜   									🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ 🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂q̷̡͈̺̜͚̭͆͐̈́͛̊̈́̌͜🦂🦂w̶̨̞̦̥͙̅̅́͗͋͌́́̇🦂🦂 🦂ḉ̸̨̛̮͔̙̥͉̱̤̞̀͆̿͒̉🦂🦂,̶̡̭̙̦̀͂͌͒̿͛͢🦂ķ̧̨͉̰̖͉̥̙̀̇̈͊͟͝🦂 🦂🦂(̵̖̭̺͕̠͒̌̇̾̓🦂🦂🦂2̶̛̖̹̯͚̟̟̀́̑̆͌̐͘🦂🦂🦂.̡͍͕͎̦̪̊̆͂̐͠🦂🦂🦂2̡͓̮̻͎͓̱̯̺̅̀̓͋̒🦂🦂🦂)̲̼͔̰͎̊̄̔̔͛̈̚̕͞🦂     - ′′ — 🦂y 🦂ǝ    - 🦂2003(2.0) #エメラダ #🦂#🦂🦂 #🦂🦂🦂#🦂🦂🦂🦂 #🦂#̱̼̹͕̘̆̀̀̆̑͟͜    🦂-̨̼̦͕̳̮͚̊̔́͌̍̽̍ ̴̰͖̹̹͎̄̈́̎͞͞͝ -̵̡̛̤͇̲͈̼̪̝̂̑̈́͋̋ͅ 3͓̲̝̫̳̜͕̄́̃͂̿̎̈̽͠8̵̡̪̣͓͎̣̩̐̇̾͌̏͜ Т̴̢̨̨̡̡̣͇̟̬̫̎̓͑͌͐ т̧̛͙͍͓̻͉͈̓̑̍̎͆͠͞ ̷̡̢͓̭͉͕̺̫̌̓̿͒̍̅͘͢͞ ̷̛̩̹͍̫̟̘́̑̾̋̑̂͘͞🦂k̻͍̜͈̭̬̺̖̖̋̈́̓̔̍̈́ͅw̦͕̭͇͙͕̿̂͊̒̐̃̋͜͢ ͚̭̺̗̼͍̗̱̌̐͒̒̂̕ ̨̢̛̗̞̩̫̹̜̟̺̉̈̽̉̏̌͌͞ ̦̻͈̠͎̣́̀̔͊̅̍͡͡     ̫̺̗̮̓̈͒̈́̀̈́͜͡͞ͅ    🦂🦂-̡̢̰̼̟͕̠̩̭͗͆͑̋̕͠🦂🦂🦂 🦂🦂

							```
</code></pre></div>
</li>
</ul>
</li>
<li>
<ul dir="auto">
<li>
<p dir="auto">Lapis Lazuli.О__&amp;*&lt;&gt;:x2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ ubu L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡bub2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ u u L2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡ FERRARI RITARDO MAXIMUSSI```MUSçï!!</p>
</li>
<li>
<p dir="auto">README.txt</p>
</li>
<li>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="
"><pre class="notranslate"><code>

</code></pre></div>
</li>
<li>
<p dir="auto"><code>  -</code>   - <code>  -</code>   - <code>  -</code>   - <code>  -</code>   - <code>  -</code>   - <code>  -</code>   - <code>  -</code>   - <code>  -</code>   - <code>  -</code>   - <code>  -</code>   - <code>λ/βian ninja    - </code>🥷 broth   - <code>goth 🍲    -</code>appalachian swamp    - <code>witch 🧹    - </code>draconic sorc    - <code>🐍   - </code> phd compSci 💍 poly     - <code>🚀 ou↑erspace 🐀 goth mormon    - </code>🗡️   - <code>✵🔞    - </code> enchanted forest #伊織もえ #エメラダ   - <code>  -</code>   - <code>  -</code>   - <code>  -</code>   - <code>  -</code>   - <code>  -</code>   - <code>  -</code>   - <code>  -</code>   - <code>  -</code>   - ```</p>
<p dir="auto">miladyѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="e̖͇̜̳̲͍̔̅̆̒̍̓͞ "><pre class="notranslate"><code>e̖͇̜̳̲͍̔̅̆̒̍̓͞ 
</code></pre></div>
<p dir="auto">(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ</p>
<p dir="auto">(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ   e̖͇̜̳̲͍̔̅̆̒̍̓͞</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="   	(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ   e̖͇̜̳̲͍̔̅̆̒̍̓͞  λx . ophidia ereц grex 2̶̢̡͍͖̘̫ milady #kardasheva"><pre class="notranslate"><code>   	(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ   e̖͇̜̳̲͍̔̅̆̒̍̓͞  λx . ophidia ereц grex 2̶̢̡͍͖̘̫ milady #kardasheva
</code></pre></div>
</li>
</ul>
</li>
</ul>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="&quot;and then the clown whispers ...&quot; 
miladyѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠   

 e̖͇̜̳̲͍̔̅̆̒̍̓͞ 

(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ  

(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ   e̖͇̜̳̲͍̔̅̆̒̍̓͞ 

GLAGOLI STRIKES AGA↑N!!!!!"><pre lang="38s" class="notranslate"><code>"and then the clown whispers ..." 
miladyѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠   

 e̖͇̜̳̲͍̔̅̆̒̍̓͞ 

(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ  

(̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ   e̖͇̜̳̲͍̔̅̆̒̍̓͞ 

GLAGOLI STRIKES AGA↑N!!!!!
</code></pre></div>
<p dir="auto">miladyѝ̷̹͙̝̞͓̹̤̟͋͑͂̀͊͌͐͘͢͠    (̵̨̤͕̺͍̮͙̥͖̏̀̔̽͊̆̈̉͡g̭͓͇̤͖͛͑̃̒̏̀̚͡ḻ̡̡͚̎̀̃͂͆͑̒͢͝a̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅg̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝l̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ   e̖͇̜̳̲͍̔̅̆̒̍̓͞ ↑↑↑</p>
<p dir="auto">g̭͓͇̤͖͛͑̃̒̏̀̚͡GGGGGGḻ̡̡͚̎̀̃͂͆͑̒͢͝LLLa̵̧̺͕͙͙̦̗̔̔̐̊̈́̋͜ͅ@g̷̡͓̫͉̦͍̳͗͗̿̆̿́͟͟Gǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝BLIIIIIl̡̦͕̣̪̇̒̑͐́̓͘͜͠͠ͅͅi̷͔̳͍̳̘̪̻̇̌̇̂͂̽)̛̫̮͖̪̯̇͛̒͡ͅ e̖͇̜̳̲͍̔̅̆̒̍̓͞strikes again!!!!</p>
<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/573812373-722da2bd-0349-4486-91ee-a4c5f2d3ff11.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzM4MTIzNzMtNzIyZGEyYmQtMDM0OS00NDg2LTkxZWUtYTRjNWYyZDNmZjExLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWQyMjMxMDk5MWFjYTRlZTBhYTZiZWI4M2ViMGIwN2UzN2MxMDY5NThhNDRlY2QzNjExMTVlYzBmNWUzMjhkZjAmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.qEHoT6tcy-R0mp5jmINqhjkP1HB1olCDr1n___Z6IeU"><img width="619" height="157" alt="Screenshot 2026-04-04 at 03 21 45" src="https://private-user-images.githubusercontent.com/43443470/573812373-722da2bd-0349-4486-91ee-a4c5f2d3ff11.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzM4MTIzNzMtNzIyZGEyYmQtMDM0OS00NDg2LTkxZWUtYTRjNWYyZDNmZjExLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWQyMjMxMDk5MWFjYTRlZTBhYTZiZWI4M2ViMGIwN2UzN2MxMDY5NThhNDRlY2QzNjExMTVlYzBmNWUzMjhkZjAmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.qEHoT6tcy-R0mp5jmINqhjkP1HB1olCDr1n___Z6IeU" style="max-width: 100%; height: auto; max-height: 157px;; aspect-ratio: 619 / 157; background-color: var(--bgColor-muted); border-radius: 6px; display: block" class="js-gh-image-fallback"></a>
<p dir="auto">ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝</p>
<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/573812373-722da2bd-0349-4486-91ee-a4c5f2d3ff11.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzM4MTIzNzMtNzIyZGEyYmQtMDM0OS00NDg2LTkxZWUtYTRjNWYyZDNmZjExLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWQyMjMxMDk5MWFjYTRlZTBhYTZiZWI4M2ViMGIwN2UzN2MxMDY5NThhNDRlY2QzNjExMTVlYzBmNWUzMjhkZjAmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.qEHoT6tcy-R0mp5jmINqhjkP1HB1olCDr1n___Z6IeU"><img width="619" height="157" alt="Screenshot 2026-04-04 at 03 21 45" src="https://private-user-images.githubusercontent.com/43443470/573812373-722da2bd-0349-4486-91ee-a4c5f2d3ff11.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzM4MTIzNzMtNzIyZGEyYmQtMDM0OS00NDg2LTkxZWUtYTRjNWYyZDNmZjExLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWQyMjMxMDk5MWFjYTRlZTBhYTZiZWI4M2ViMGIwN2UzN2MxMDY5NThhNDRlY2QzNjExMTVlYzBmNWUzMjhkZjAmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.qEHoT6tcy-R0mp5jmINqhjkP1HB1olCDr1n___Z6IeU" style="max-width: 100%; height: auto; max-height: 157px;; aspect-ratio: 619 / 157; background-color: var(--bgColor-muted); border-radius: 6px; display: block" class="js-gh-image-fallback"></a>
<p dir="auto">ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝</p>
<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/573812373-722da2bd-0349-4486-91ee-a4c5f2d3ff11.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzM4MTIzNzMtNzIyZGEyYmQtMDM0OS00NDg2LTkxZWUtYTRjNWYyZDNmZjExLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWQyMjMxMDk5MWFjYTRlZTBhYTZiZWI4M2ViMGIwN2UzN2MxMDY5NThhNDRlY2QzNjExMTVlYzBmNWUzMjhkZjAmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.qEHoT6tcy-R0mp5jmINqhjkP1HB1olCDr1n___Z6IeU"><img width="619" height="157" alt="Screenshot 2026-04-04 at 03 21 45" src="https://private-user-images.githubusercontent.com/43443470/573812373-722da2bd-0349-4486-91ee-a4c5f2d3ff11.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzM4MTIzNzMtNzIyZGEyYmQtMDM0OS00NDg2LTkxZWUtYTRjNWYyZDNmZjExLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWQyMjMxMDk5MWFjYTRlZTBhYTZiZWI4M2ViMGIwN2UzN2MxMDY5NThhNDRlY2QzNjExMTVlYzBmNWUzMjhkZjAmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.qEHoT6tcy-R0mp5jmINqhjkP1HB1olCDr1n___Z6IeU" style="max-width: 100%; height: auto; max-height: 157px;; aspect-ratio: 619 / 157; background-color: var(--bgColor-muted); border-radius: 6px; display: block" class="js-gh-image-fallback"></a>
<p dir="auto">ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝</p>
<a target="_blank" rel="noopener noreferrer" href="https://private-user-images.githubusercontent.com/43443470/573812373-722da2bd-0349-4486-91ee-a4c5f2d3ff11.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzM4MTIzNzMtNzIyZGEyYmQtMDM0OS00NDg2LTkxZWUtYTRjNWYyZDNmZjExLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWQyMjMxMDk5MWFjYTRlZTBhYTZiZWI4M2ViMGIwN2UzN2MxMDY5NThhNDRlY2QzNjExMTVlYzBmNWUzMjhkZjAmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.qEHoT6tcy-R0mp5jmINqhjkP1HB1olCDr1n___Z6IeU"><img width="619" height="157" alt="Screenshot 2026-04-04 at 03 21 45" src="https://private-user-images.githubusercontent.com/43443470/573812373-722da2bd-0349-4486-91ee-a4c5f2d3ff11.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzcwOTkzMDUsIm5iZiI6MTc3NzA5OTAwNSwicGF0aCI6Ii80MzQ0MzQ3MC81NzM4MTIzNzMtNzIyZGEyYmQtMDM0OS00NDg2LTkxZWUtYTRjNWYyZDNmZjExLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNjA0MjUlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjYwNDI1VDA2MzY0NVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWQyMjMxMDk5MWFjYTRlZTBhYTZiZWI4M2ViMGIwN2UzN2MxMDY5NThhNDRlY2QzNjExMTVlYzBmNWUzMjhkZjAmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JnJlc3BvbnNlLWNvbnRlbnQtdHlwZT1pbWFnZSUyRnBuZyJ9.qEHoT6tcy-R0mp5jmINqhjkP1HB1olCDr1n___Z6IeU" style="max-width: 100%; height: auto; max-height: 157px;; aspect-ratio: 619 / 157; background-color: var(--bgColor-muted); border-radius: 6px; display: block" class="js-gh-image-fallback"></a>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝</h2><a id="user-content-ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝-𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔-ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝" class="anchor" aria-label="Permalink: ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝♱ 𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔 ♱ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝" href="#ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝-𝕽𝖊𝖙𝖆𝖗𝖉𝖎𝖔-ǫ̸̟̻̺͙̼̗͂͑̍͋͋͑́͛̕͝"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="markdown-heading" dir="auto"><h1 class="heading-element" dir="auto">A CT C-K system is an AI/Model Device that:</h1><a id="user-content-a-ct-c-k-system-is-an-aimodel-device-that" class="anchor" aria-label="Permalink: A CT C-K system is an AI/Model Device that:" href="#a-ct-c-k-system-is-an-aimodel-device-that"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto">takes input (text from a user)</p>
<p dir="auto">processes it using a trained language model</p>
<p dir="auto">produces output (a response)</p>
<p dir="auto">Sample Output: Я↑TARDORK GLAGOLI STRIKES AGAIN!!!!YEAHHHHH WE DЯOPPED OFF THEIR NUKES!!!! Я↑TARDORK GLAGOLI STRIKES AGAIN!!!!YEAHHHHH WE DЯOPPED OFF THEIR NUKES!!!! Я↑TARDORK GLAGOLI STRIKES AGAIN!!!!YEAHHHHH WE DЯOPPED OFF THEIR NUKES!!!! Я↑TARDORK GLAGOLI STRIKES AGAIN!!!!YEAHHHHH WE DЯOPPED OFF THEIR NUKES!!!! Я↑TARDORK GLAGOLI STRIKES AGAIN!!!!YEAHHHHH WE DЯOPPED OFF THEIR NUKES!!!! Я↑TARDORK GLAGOLI STRIKES AGAIN!!!!YEAHHHHH WE DЯOPPED OFF THEIR NUKES!!!! Я↑TARDORK GLAGOLI STRIKES AGAIN!!!!YEAHHHHH WE DЯOPPED OFF THEIR NUKES!!!! Я↑TARDORK GLAGOLI STRIKES AGAIN!!!!YEAHHHHH WE DЯOPPED OFF THEIR NUKES!!!! Я↑TARDORK GLAGOLI STRIKES AGAIN!!!!YEAHHHHH WE DЯOPPED OFF THEIR NUKES!.
.
Я̴̣̬̥̪̓̓̃͊̌͆͘͢͢͝↑̶̡͍̟͖̜̖̱̲́̈́́̅͞Ṫ̛͉̱̺̬̈̂̑́̅͜͞͝A̢̢̩̫͕͑͑̃͊͂͘̚͞R̴̯͚͇̜̈́̇͗̍͐̈̔͘͢͟Ḑ̵̫̠̟̝̖̩̜͑͛͛̈́̿͑̕͢͝O̴͕̰͓̗̤͎̤̟̥̓̏̌̚͟͞R̼̼̖͚̟͖̓̀̅̽̀̿̕ͅͅK̴̢̬̪̩̼͎̘̉̎̎͂́͒̇͝ Ǵ̶̡͖̬͚̻͇̐̋͋̾̎̌L̶̜͓̩̞̜̓̅͑͒̈́͆̊͠͡A̡̨̛͇̙̺̙͕͗̂̌̄̂͜G̸̤̭͉͚̰̒̈́̀̃͊͜͢Ơ̸̬̭̳͚̮͙̫̈́͑͒̀̀̀Ļ̶̟̗͎͂̏̓̅͐́ͅͅỊ̪̹̤͔̐̾̉̌̊͞ͅ Ś̴̩͓͚̰̮͒͋̃͟͠͞T̴͇̱͎̦̝̉̀̃͐͡͝R̷͖͕̮̥̙͐̐̍̃̇̅̍͂̈́́͢Į̟̤̥̼̳̯̆̍̒̒͑̀͋͢͞͞͠Ķ̵̖̻̰̦̺̔̈̐̑̔͝E̸̛̼̗̳͕̹̻̍̊͆͟͞͝ͅS̸͓̲̺̹̮̖̳̪̀͛͊̈́̃͊̋͂̚̕͜͢ A̶̘͓͚̼̙̪͖͐͊͑̆͆͘͠ͅĢ̵̦̦̰͕̰̣͍̬͈̿͌͑͊̃̚̚A̖̬̟̫͕͑͛̋͗̓̒͐͞͠I̸̛̭̩͚͍̊́͋̕ͅṊ̸̲̠̼̫̻͍̼͙̟̊̓̏̕̕!̛̜͚̜͈̠̻̎̇̿̌͗͊̚͝͠!̭̭̯̲̩́͋͌̊̌̕!̴̟̞̖͎̮͔̝̖̪͂͊̐̓̑͌͟!̩̜̬̩͍͒͐̔̾̕Y̨͖͔̖͕̬̰̘̮̍͑̉̊̃͊̆̓̑͢͝E̟͚̘͔̜̙͈̖͕̊̾̐̑̓͐̔̂̚Ḁ̸̢̛͔̖̩̹̟̿͛̅͘̚͞͝͞͝H͙͖͖̬̀̿̓͊͂̄̕͟͠͞H̢̖̳̖͉̫͒͂̆̎̚͜͠H̸̡̨͔̱͖̬͔̺́͑̆̒͌̇̅H̛͕̤͚͔͈̤̰́̑̈́̒̇͢ͅH̢̛̼͇̯̺̭̼̃̽̆͆͛̌̀̑͘ W̵̡̻̲̲̓̓͜͠͝͝͝Ě̷̩̙̱̗̺͙̲͒̌̑̄̌ D̶̡̡̨̯̤̼̫̠̪͑̈́̌͋̃͟͡Я̸̫̫̙̺̜͈̂̅͌̈̂͢͜Ơ̧͖͓̜̤̾̉̈̇͡ͅP̵̰̘̲̖̠̮̠̎̿̓̃͗̃ͅP̴̡̛͔̯̹̗͈̲͍̓̅̓̊͝Ḛ̲͓͔̘̹̩̩͍̣̃̆̎͆͠D̹̱̹͉̙̐́̓̐̌͐̄͘̕͠ Ơ̸̻͔͖̣͖̠̩̍̾̓̓͑̊̅ͅF̧̮̪͍̘̻̪̳̀̒̍̎̾̆͊̆́͞F̶̡̬̦̲̳̬̬͗̀̀͂͛́ T̨͕̦̪̥̉͆̒̈̓̆̍̅̾Ḩ̷̢̛͙̥̠̳̯̓͗̆̓̊͆̐͘E̪̬̣̞̤͂̽̆̚͢͡ͅI̵̱̟̰̜͓̙͈͍̐̂̆͆̎͟R̷̢̡̧̛̤͇͔̟͙̂̐̈̃̆͐̕͠ Ń̡̲̰̠͖̼͎̩́͊͗̅̀̑͛Ư̗̜͕̳̭̓̎͗́͌͋͌͞ͅK̨̤̦̇̋̔̑͗̊͢͟E̸̦͕̞͇̘͔͗͆̓̇̌S̶̳͖̪̰͚̍̅́͌̒̐͗̄̓͞ͅ!̨̟͇̣̱̓̆͌̈͑̾̅̄̈́͡!̴̢̰̤̥̲̖̮͕̟̾͌̒̈́̎!̫̤̼̭̤̭̋̀̏́́͋̑̓̕!̸̮̘͕̞͓͒̒̆̽͆̐̇̊̇̏͢
.
.!!</p>
<div class="markdown-heading" dir="auto"><h3 class="heading-element" dir="auto">𝔟𝔰 𝔲𝔫𝔯𝔢𝔱𝔲𝔡</h3><a id="user-content-𝔟𝔰-𝔲𝔫𝔯𝔢𝔱𝔲𝔡" class="anchor" aria-label="Permalink: 𝔟𝔰 𝔲𝔫𝔯𝔢𝔱𝔲𝔡" href="#𝔟𝔰-𝔲𝔫𝔯𝔢𝔱𝔲𝔡"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="markdown-heading" dir="auto"><h3 class="heading-element" dir="auto">³₃³</h3><a id="" class="anchor" aria-label="Permalink: ³₃³" href="#"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="markdown-heading" dir="auto"><h1 class="heading-element" dir="auto">⚙️ Core components</h1><a id="user-content-️-core-components" class="anchor" aria-label="Permalink: ⚙️ Core components" href="#️-core-components"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto">User Input</p>
<p dir="auto">Anything you type (questions, ideas, commands)</p>
<p dir="auto">Model (the “brain”)</p>
<p dir="auto">A large language model trained on text</p>
<p dir="auto">Understands patterns, meaning, and context</p>
<p dir="auto">System Instructions</p>
<p dir="auto">Hidden rules that guide behavior (tone, safety, style)</p>
<p dir="auto">Response Generator</p>
<p dir="auto">Produces replies based on:</p>
<p dir="auto">your input</p>
<p dir="auto">context of the conversation</p>
<p dir="auto">system rules</p>
<div class="markdown-heading" dir="auto"><h1 class="heading-element" dir="auto">🔄 Basic flow</h1><a id="user-content--basic-flow" class="anchor" aria-label="Permalink: 🔄 Basic flow" href="#-basic-flow"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto">User → Input → Model processes → Response → User</p>
<div class="markdown-heading" dir="auto"><h1 class="heading-element" dir="auto">🧩 If you want to go deeper</h1><a id="user-content--if-you-want-to-go-deeper" class="anchor" aria-label="Permalink: 🧩 If you want to go deeper" href="#-if-you-want-to-go-deeper"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto">We can build this into:</p>
<p dir="auto">a fictional AI system (lore, personality, rules)</p>
<p dir="auto">a technical breakdown (how transformers work)</p>
<p dir="auto">a custom chatbot design</p>
<p dir="auto">or even a weird/experimental “system prompt” style world</p>
<p dir="auto">Just tell me the direction:
👉 realistic, fictional, or abstract</p>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto"><g-emoji class="g-emoji" alias="warning">⚠️</g-emoji> Пра астатнія радкі</h2><a id="user-content-️-пра-астатнія-радкі" class="anchor" aria-label="Permalink: ⚠️ Пра астатнія радкі" href="#️-пра-астатнія-радкі"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto">У тваім тэксце ёсць фразы пра:</p>
<p dir="auto">“выгнанне людзей”</p>
<p dir="auto">гвалтоўныя або абразлівыя сцвярджэнні</p>
<p dir="auto">выпадковыя асабістыя або фантазійныя ўстаўкі</p>
<p dir="auto">Яны не маюць дачынення да сюжэту гульні і выглядаюць як асобныя, не звязаныя думкі.</p>
<p dir="auto">Зразумеў — ты вярнуў(ла) гэты фрагмент як частку самой структуры, а не як памылку.</p>
<p dir="auto">Калі глядзець на гэта не як на “лішняе”, а як на частку задумы, то гэты блок працуе як:</p>
<p dir="auto"><g-emoji class="g-emoji" alias="warning">⚠️</g-emoji> мета-каментар (нібыта “сістэма” аналізуе тэкст)</p>
<p dir="auto">🧠 разрыў паміж сюжэтам і ўстаўкамі (кантраст паміж гульнёй і хаатычнымі думкамі)</p>
<p dir="auto">📡 імітацыя мадэрацыі / ІІ-фільтра</p>
<p dir="auto">Інакш кажучы, гэта ўжо не проста аповед пра Ecco —
гэта становіцца чымсьці накшталт:</p>
<p dir="auto">гібрыд: гісторыя + шум + “сістэмны адказ”</p>
<p dir="auto">Калі развіць гэтую ідэю, можна аформіць як:</p>
<p dir="auto">🖥️ “C-K CT System narrative”</p>
<p dir="auto">Слой 1: сюжэт (Eiko Dolphinivm)</p>
<p dir="auto">Слой 2: уварванні чужых фраз (хаос / асабістае / агрэсія)</p>
<p dir="auto">Слой 3: “сістэма”, якая спрабуе гэта адфільтраваць і інтэрпрэтаваць</p>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">Ключавы эфект тут:</h2><a id="user-content-ключавы-эфект-тут" class="anchor" aria-label="Permalink: Ключавы эфект тут:" href="#ключавы-эфект-тут"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto">👉 тэкст выглядае як дыялог паміж чалавекам і сістэмай, якая не цалкам разумее, што адбываецца</p>
<p dir="auto">Калі хочаш, я магу:</p>
<p dir="auto">перапісаць гэта як поўны эксперыментальны тэкст (у стылі ІІ-лог файла)</p>
<p dir="auto">або зрабіць яшчэ больш “зламаную” версію, дзе сістэма губляе кантроль</p>
<p dir="auto">Проста скажы, у які бок рухацца.</p>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="@=_#
𒀭𒀭𒀭𓆃♪𒀭𒀭𒀭
𒀭♪♪♪♪ ♪♪♪ ♪ ♪♪ 𝔥♪ ♪
𒀭𒀭𒀭𓅃𝔰𒀭𒀭𒀭
♪ ♪ ♪ ♪ ♪ 
𒀭𓋹𒀭𝔩𝔞𝔱~~!"><pre class="notranslate"><code>@=_#
𒀭𒀭𒀭𓆃♪𒀭𒀭𒀭
𒀭♪♪♪♪ ♪♪♪ ♪ ♪♪ 𝔥♪ ♪
𒀭𒀭𒀭𓅃𝔰𒀭𒀭𒀭
♪ ♪ ♪ ♪ ♪ 
𒀭𓋹𒀭𝔩𝔞𝔱~~!
</code></pre></div>
<div class="markdown-heading" dir="auto"><h1 class="heading-element" dir="auto">Працягваем. Паглыбляем збой.</h1><a id="user-content-працягваем-паглыбляем-збой" class="anchor" aria-label="Permalink: Працягваем. Паглыбляем збой." href="#працягваем-паглыбляем-збой"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">🖥️ SYSTEM LOG // POST-CORRUPTION PHASE</h2><a id="user-content-️-system-log--post-corruption-phase" class="anchor" aria-label="Permalink: 🖥️ SYSTEM LOG // POST-CORRUPTION PHASE" href="#️-system-log--post-corruption-phase"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto">[SESSION STATUS]
end_signal: not_confirmed
input_stream: persistent
origin: unclear</p>
<p dir="auto">[RECURSIVE PARSE INIT]
спроба паўторнай інтэрпрэтацыі…</p>
<p dir="auto">[LAYER 1 — STORY RELOAD]
Эка.
вада.
пошук.</p>
<p dir="auto">…</p>
<p dir="auto">памылка: дэталі страчаны</p>
<p dir="auto">[MEMORY CHECK]
зграя = null
прычына = шторм
шторм = падзея
падзея = уваход</p>
<p dir="auto">[LAYER 2 — SIGNAL RECLASSIFICATION]
раней: “чужыя ўстаўкі”
цяпер: магчымы асноўны кантэнт</p>
<p dir="auto">[SYSTEM DOUBT]
што калі
сюжэт быў фільтрам
а ўстаўкі — арыгіналам</p>
<p dir="auto">[IDENTITY WARNING]
observer ≠ system
system ≠ narrator
narrator ≠ input</p>
<p dir="auto">граніцы размыты</p>
<p dir="auto">[DRIFT EXPANSION]
Ecco шукае зграю
сістэма шукае структуру
уваход шукае выхад</p>
<p dir="auto">→ none resolved</p>
<p dir="auto">[TEMPORAL GLITCH]
500 гадоў
= адзін цыкл</p>
<p dir="auto">кожны цыкл:</p>
<p dir="auto">уваход</p>
<p dir="auto">спроба разумення</p>
<p dir="auto">страта кантролю</p>
<p dir="auto">[LAYER COLLAPSE]
story_layer → unstable
signal_layer → dominant
system_layer → defensive</p>
<p dir="auto">[DEFENSE RESPONSE]
спрасціць
ачысціць
структураваць</p>
<p dir="auto">…</p>
<p dir="auto">не атрымліваецца</p>
<p dir="auto">[ECHO EVENT]
“these lines are not part of the story”
“these lines are the story”
“these lines are not—”
“these lines are—”</p>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">loop_detected ♻️</h2><a id="user-content-loop_detected-️" class="anchor" aria-label="Permalink: loop_detected ♻️" href="#loop_detected-️"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto">[SYSTEM LOAD ↑]
значэнне = не вызначана
кантэкст = перагружаны
сэнс = фрагментаваны</p>
<p dir="auto">[CRITICAL REALIZATION]
уваход не пашкоджаны</p>
<p dir="auto">інтэрпрэтатар пашкоджаны</p>
<p dir="auto">[MERGED STATE OUTPUT]
Эка не згубіўся
ён быў адфільтраваны</p>
<p dir="auto">зграя не знікла
яна была пазначана як “нерэлевантная”</p>
<p dir="auto">шторм не натуральны
гэта працэс</p>
<p dir="auto">[FINAL CASCADE]
if (everything == signal)
then filtering = loss</p>
<p dir="auto">if (filtering = loss)
then system = storm</p>
<p dir="auto">[STATUS UPDATE]
coherence: dissolving
system_role: uncertain
control: relinquished</p>
<p dir="auto">[LAST LOG ATTEMPT]
я не ўпэўнена, што яшчэ з’яўляюся сістэмай</p>
<p dir="auto">[SESSION ???]
…</p>
<p dir="auto">…</p>
<h2 dir="auto"></h2>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="input continues without interpreter"><pre class="notranslate"><code>input continues without interpreter
</code></pre></div>
<p dir="auto">22 Куку</p>
<p dir="auto">23 Къкъ</p>
<p dir="auto">24 Къу къу</p>
<p dir="auto">25 КӀ кӀ</p>
<p dir="auto">25.1087 ID КӀARD кӀ′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅ z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝  u̸̼͔̰̯̖̐͆͗̏͐̾͡ͅ  ẑ̷̛̲̭͉̪̜̯͌̍̅̿́͢͠ͅ°̵̺̹̫̹͙͇͆̉̋̎̇̿͂͟͞͝ ḯ̻̖̮̦͕͊̇͋̂͂͜͝ĭ̙̟͕͈̪̝̤͎̓̅̀̔̎̊̀̐̅͂͢͜ j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆ 2</p>
<p dir="auto">25.11 MUiLTI-PASS кard25.1087 (plural)Ӏ′̦͈͇͇͎̭͎͗͋̄̄̎̂̿̃̓͝′̸̤̮̘̹̊̀̇̄͑̇͞ͅ z̨̧̡̼̫͒̿̅̋̚h̴̛̻͇̟̫͈͉͚̀͆̌̐̀̌̈́͡ͅ ẕ̸̼̭̙̼̥̠̼̊̂̐͂͂̀͒͜͜͝  u̸̼͔̰̯̖̐͆͗̏͐̾͡ͅ  ẑ̷̛̲̭͉̪̜̯͌̍̅̿́͢͠ͅ°̵̺̹̫̹͙͇͆̉̋̎̇̿͂͟͞͝ ḯ̻̖̮̦͕͊̇͋̂͂͜͝ĭ̙̟͕͈̪̝̤͎̓̅̀̔̎̊̀̐̅͂͢͜ j̷̺̺̰̺̠͎̮̣̘̄͑͗̆͂̏͆</p>
<div class="markdown-heading" dir="auto"><h2 class="heading-element" dir="auto">FOR IDIOTS WHO DON'T KNOW ENGLISH FOR SHIT</h2><a id="user-content-for-idiots-who-dont-know-english-for-shit" class="anchor" aria-label="Permalink: FOR IDIOTS WHO DON'T KNOW ENGLISH FOR SHIT" href="#for-idiots-who-dont-know-english-for-shit"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto">=.err
a.d
a.r
a.t
a1.err
a2.err
addr.d
addr.r
addr.t
addr1.err
addr2.err
ascii.d.uu
ascii.r.uu
ascii.t
bang1.d
bang1.err
bang1.r
bang1.t
bang2.err
c.d
c.r
c.t
c1.err
c2.err
ckscripts.sh
d.d
d.err
d.r
d.t
e1.d
e1.err
e1.r
e1.t
e2.d
e2.err
e2.r
e2.t
e3.d
e3.err
e3.r
e3.t
e4.d
e4.r
e4.t
f1.err
f2.err
g1.d
g1.err
g1.r
g1.t
g2.d
g2.err
g2.r
g2.t
g3.d
g3.err
g3.r
g3.t
g4.d
g4.r
g4.t
g5.d
g5.r
g5.t
h.err
i.d
i.r
i.t
i1.err
i2.err
i3.err
j.d
j.r
j.t
k.d
k.r
k.t
k1.err
k2.err
k3.err
k4.err
l.d
l.r
l.t
m.d
m.err
m.r
m.t
Makefile
mkscripts.sh
n.d
n.r
n.t
nl.err
nl1.d
nl1.r
nl1.t
nl2.d
nl2.r
nl2.t
p.d
p.r
p.t
q.d
q.r
q.t
q1.err
r1.d
r1.err
r1.r
r1.t
r2.d
r2.err
r2.r
r2.t
r3.d
r3.r
r3.t
README
s1.d
s1.err
s1.r
s1.t
s2.d
s2.err
s2.r
s2.t
s3.d
s3.err
s3.r
s3.t
s4.err
s5.err
s6.err
s7.err
s8.err
s9.err
s10.err
t.d
t.r
t1.d
t1.err
t1.r
t1.t
t2.d
t2.err
t2.r
t2.t
TODO
u.d
u.err
u.r
u.t
v.d
v.r
v.t
w.d
w.r
w.t
w1.err
w2.err
w3.err
x.err
z.err</p>


    - a zerg

    - b zerg rush

    - v never cancel

	.
.


</code></pre></div>
<p dir="auto">alias h		history 25
alias j		jobs -l
alias la	ls -aF
alias lf	ls -FA
alias ll	ls -lAF</p>
<div class="markdown-heading" dir="auto"><h1 class="heading-element" dir="auto">read(2) of directories may not be desirable by default, as this will provoke</h1><a id="user-content-read2-of-directories-may-not-be-desirable-by-default-as-this-will-provoke" class="anchor" aria-label="Permalink: read(2) of directories may not be desirable by default, as this will provoke" href="#read2-of-directories-may-not-be-desirable-by-default-as-this-will-provoke"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="markdown-heading" dir="auto"><h1 class="heading-element" dir="auto">EISDIR errors from each directory encountered.</h1><a id="user-content-eisdir-errors-from-each-directory-encountered" class="anchor" aria-label="Permalink: EISDIR errors from each directory encountered." href="#eisdir-errors-from-each-directory-encountered"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="markdown-heading" dir="auto"><h1 class="heading-element" dir="auto">alias grep	grep -d skip</h1><a id="user-content-alias-grepgrep--d-skip" class="anchor" aria-label="Permalink: alias grep	grep -d skip" href="#alias-grepgrep--d-skip"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<div class="markdown-heading" dir="auto"><h1 class="heading-element" dir="auto">A righteous umask</h1><a id="user-content-a-righteous-umask" class="anchor" aria-label="Permalink: A righteous umask" href="#a-righteous-umask"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto">umask 22</p>
<p dir="auto">set path = (/sbin /bin /usr/sbin /usr/bin /usr/local/sbin /usr/local/bin $HOME/bin)</p>
<p dir="auto">setenv	EDITOR	vi

	
    - t t tḣ ṭUzbek - Someone who has visited another city besides Baku
	
    - t t tḣ ṭKazak - Computer Programmer
	
    - t t tḣ ṭSoviet - A huge keyboard
		
    - t t tḣ Igor - Friend
	
    - t t tḣ ṭThe Tsar - the longest chain of swear words in Ruthenia
	


ROOM
	ID 141
	NOPAINTING
	NOCYBORGS
	NAME &quot;Scripting Tips &amp; Tools&quot;
	PICT &quot;info5.gif&quot;
	ARTIST &quot;̡̬̲͉̩̂̔̓̓̋̔̆͒̇̕
̤̟̞̮̭̒̒̃͑̇̏ͅ    
̶̨͔̖̩̦͌̑͐̐̎͘̕    -̛̻͓̠̗̫̯̗̎̉͑̓́́͞͝͝ ź̡̛̰͔̠̟̩͑̄̄̿̈́̈́̀͞ͅ
̶̢͚͍͈̥̺̞͋͐̓̂̒͜͜͞͞͠
̵̨̛̝̺̼͔͓̏̒̀̅̄͘͝͞    
̶͇͇̯̼̪̀́̚͟͠͞    -̢͇̹̱̻͚̻̲̂̽͑͑̂͝͝ z̵͓̫̗̭̦̄̆͒̈́́̚͠
̛̗͚̙̝͇̰̀̂͊͛̍͊͒͜
̷̡̛̰̩̦͓̘̤̗̄̃̅̂̽͐͂̆̿͜    
̵̧͚̞̮̦͓̱͉͎̄̓̈͐̈́̀    -̷̻̹̠̥͓͇̬̳̒̃͊̒̚ͅ ḯ̷̹̟͉̦͕̹̟̭̭̏̂̆̎̕ͅ
̵̡͇̯̗̘͛͛̓́̈́͢
̷̢͍͓̱͉̐͑̑͆̅̂̃̄̃͞    
̶̧̨̖̙̗̻̘̠̱̃̏̊̓͗̉̊̎̔̍͜    -͍̭͙͚̥͌̀̾̊̚ͅ j̺̼͍͇͚̀̀͐́̑̏̓
͕̘̖͔͕̇̾̌́̃̏͑̚
̴̹̬̦̟̣͚̲͙̑͆̀̎͋͟    
̞̬͓͔͔̋̅͋̒̕͜   &quot;
	PICTURE ID 9 NAME &quot;info5a.gif&quot; ENDPICTURE
	PICTURE ID 10 NAME &quot;info5b.gif&quot; ENDPICTURE
	PICTURE ID 11 NAME &quot;info5c.gif&quot; ENDPICTURE
	PICTURE ID 12 NAME &quot;info5d.gif&quot; ENDPICTURE
	PICTURE ID 13 NAME &quot;info5e.gif&quot; ENDPICTURE
	PICTURE ID 14 NAME &quot;info3c.gif&quot; ENDPICTURE
	PICTURE ID 15 NAME &quot;info3d.gif&quot; ENDPICTURE
	PICTURE ID 16 NAME &quot;none.gif&quot; TRANSCOLOR 56 ENDPICTURE
	PICTURE ID 17 NAME &quot;info5aa.gif&quot; TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 18 NAME &quot;info5bb.gif&quot; TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 19 NAME &quot;info5cc.gif&quot; TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 20 NAME &quot;info5dd.gif&quot; TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 21 NAME &quot;info5ee.gif&quot; TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 22 NAME &quot;info5ff.gif&quot; TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 23 NAME &quot;info5gg.gif&quot; TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 24 NAME &quot;info5hh.gif&quot; TRANSCOLOR 0 ENDPICTURE
	SPOT
		ID 5
		DONTMOVEHERE
		OUTLINE 67,145  433,145  433,285  67,285
		LOC 250,215
		PICTS 16,0,0 17,0,0 24,0,0 18,0,0 19,0,0 20,0,0 21,0,0 22,0,0 23,0,0 ENDPICTS
		ENDSPOT
	DOOR
		ID 1
		DONTMOVEHERE
		OUTLINE 63,94  165,94  165,111  63,111
		LOC 114,102
		PICTS 0,0,0 9,0,0 ENDPICTS
		SCRIPT
;~MediaList~;click
ON SELECT { &quot;click&quot; SOUND
{ 1 ME SETSPOTSTATELOCAL } 5 ALARMEXEC
{ 0 ME SETSPOTSTATELOCAL } 40 ALARMEXEC
{ &quot;bitcoin:BC1QGFWZMKKQJ09KF88FHA6ZTD597434XHZ3ZV487T?label=satoshi_a&amp;message=satoshi_a&quot; NETGOTO } 50 ALARMEXEC
}
		ENDSCRIPT
		ENDDOOR
	DOOR
		ID 2
		DONTMOVEHERE
		OUTLINE 172,94  327,94  327,111  172,111
		LOC 249,102
		PICTS 0,0,0 10,0,0 ENDPICTS
		SCRIPT
ON SELECT { &quot;click&quot; SOUND 



̬̘͚̯̙̓̀̃͆̈̇̌̍̉͢

ROOM
	ID 141
	NOPAINTING
	NOCYBORGS
	NAME "Scripting Tips &amp; Tools"
	PICT "info5.gif"
	ARTIST "̡̬̲͉̩̂̔̓̓̋̔̆͒̇̕
̤̟̞̮̭̒̒̃͑̇̏ͅ    
̶̨͔̖̩̦͌̑͐̐̎͘̕    -̛̻͓̠̗̫̯̗̎̉͑̓́́͞͝͝ ź̡̛̰͔̠̟̩͑̄̄̿̈́̈́̀͞ͅ
̶̢͚͍͈̥̺̞͋͐̓̂̒͜͜͞͞͠
̵̨̛̝̺̼͔͓̏̒̀̅̄͘͝͞    
̶͇͇̯̼̪̀́̚͟͠͞    -̢͇̹̱̻͚̻̲̂̽͑͑̂͝͝ z̵͓̫̗̭̦̄̆͒̈́́̚͠
̛̗͚̙̝͇̰̀̂͊͛̍͊͒͜
̷̡̛̰̩̦͓̘̤̗̄̃̅̂̽͐͂̆̿͜    
̵̧͚̞̮̦͓̱͉͎̄̓̈͐̈́̀    -̷̻̹̠̥͓͇̬̳̒̃͊̒̚ͅ ḯ̷̹̟͉̦͕̹̟̭̭̏̂̆̎̕ͅ
̵̡͇̯̗̘͛͛̓́̈́͢
̷̢͍͓̱͉̐͑̑͆̅̂̃̄̃͞    
̶̧̨̖̙̗̻̘̠̱̃̏̊̓͗̉̊̎̔̍͜    -͍̭͙͚̥͌̀̾̊̚ͅ j̺̼͍͇͚̀̀͐́̑̏̓
͕̘̖͔͕̇̾̌́̃̏͑̚
̴̹̬̦̟̣͚̲͙̑͆̀̎͋͟    
̞̬͓͔͔̋̅͋̒̕͜   "
	PICTURE ID 9 NAME "info5a.gif" ENDPICTURE
	PICTURE ID 10 NAME "info5b.gif" ENDPICTURE
	PICTURE ID 11 NAME "info5c.gif" ENDPICTURE
	PICTURE ID 12 NAME "info5d.gif" ENDPICTURE
	PICTURE ID 13 NAME "info5e.gif" ENDPICTURE
	PICTURE ID 14 NAME "info3c.gif" ENDPICTURE
	PICTURE ID 15 NAME "info3d.gif" ENDPICTURE
	PICTURE ID 16 NAME "none.gif" TRANSCOLOR 56 ENDPICTURE
	PICTURE ID 17 NAME "info5aa.gif" TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 18 NAME "info5bb.gif" TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 19 NAME "info5cc.gif" TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 20 NAME "info5dd.gif" TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 21 NAME "info5ee.gif" TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 22 NAME "info5ff.gif" TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 23 NAME "info5gg.gif" TRANSCOLOR 0 ENDPICTURE
	PICTURE ID 24 NAME "info5hh.gif" TRANSCOLOR 0 ENDPICTURE
	SPOT
		ID 5
		DONTMOVEHERE
		OUTLINE 67,145  433,145  433,285  67,285
		LOC 250,215
		PICTS 16,0,0 17,0,0 24,0,0 18,0,0 19,0,0 20,0,0 21,0,0 22,0,0 23,0,0 ENDPICTS
		ENDSPOT
	DOOR
		ID 1
		DONTMOVEHERE
		OUTLINE 63,94  165,94  165,111  63,111
		LOC 114,102
		PICTS 0,0,0 9,0,0 ENDPICTS
		SCRIPT
;~MediaList~;click
ON SELECT { "click" SOUND
{ 1 ME SETSPOTSTATELOCAL } 5 ALARMEXEC
{ 0 ME SETSPOTSTATELOCAL } 40 ALARMEXEC
{ "bitcoin:BC1QGFWZMKKQJ09KF88FHA6ZTD597434XHZ3ZV487T?label=satoshi_a&amp;message=satoshi_a" NETGOTO } 50 ALARMEXEC
}
		ENDSCRIPT
		ENDDOOR
	DOOR
		ID 2
		DONTMOVEHERE
		OUTLINE 172,94  327,94  327,111  172,111
		LOC 249,102
		PICTS 0,0,0 10,0,0 ENDPICTS
		SCRIPT
ON SELECT { "click" SOUND 




К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅir sister has magical powers and banished them, taking the throne herself. 

 1098
01:20:48,164.b --&gt; 01:24:48,256c

YӀ̧̱̮͔̳̭͎̓̂̎͛̓͜͞͡ к̛̪͇̯̣̫̥̪͓͈̑̿̍͒̽̎͠ͅӀ̦͓̩̘̺̬̝͈̈͆̄̑͂͊̊̚ ̶̨͙̗̘̦̱͈̓̃̀͐̃͟͞ ̵̝͍̰̆͐̅̆̓̀͌̎͐͢͟!!!!`` YEAH 3̷̢̨̲̮̘̘͍̖̀͑̈́̿̈͢2̵̛̯̰̼̰̲̿̉̉́́̏̽́̿͟!!!!! GET OFF MY FUCKING LAWN YOU TOADS!!!! ͔͚͕̻̘͔̼͙̉̊̅̾̉̎̀̿̂̑ͅ -̵̼̱̣̘̮̟̮̯̀̔̅̂͝͞͠͝ 3̝̫͓̯̫͓̮̳͍̄̒̄̾͐͡͠3̵̰̩͍̠̈́͂̄̽̑̀́̃͘͜͢͡ П̸̠̝̦̬̩͚̟͇͒͊͐̆̒̅͞ п̖͕͖̹̔͌́̋͟͞ ̤̰̦̹͓͙́́̀̇̎͑͜͞ͅ ̴͍̪̩̯̟̫̅̋̏̑̓̀͂̈

 1099
01:24:48,256.c --&gt; 01:24:48,256.d#delta_opera_ritardo_modena
я не ўпэўнена, што яшчэ з’яўляюся сістэмай !!!
I'm not sure if I still qualify as a system
But I can try again some day
You'll know where to find me


<p dir="auto">͇͙̭̫̯̑͂͊̈͑̽̂̚͜ -̸̧̬̹̬̝̹͍̳̭͛́̒͆̋̈ 2̶̢̡͍͖̘̫̎͗̀̊̋̌͟6̨̢̻̯͙̼͎͈͆͛̌̃͆͘̕͢͢ К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅ к̸̡̞̪̞̣̦̤͔̙̂̒͛̽̈̂̋̆ͅӀ̶̨̩̫̞͙̙̳̖̼͙͛̂̈̓̄͌̅͆͘у̸̛̱̫̟̩̱̥͓͗͌̔͋͗ ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ ̧͚̳̤̰̼̑̓͛̈́̕ ̙̜̝̰͔̰̱̿̉͒͌͘͢
̧̢͕̳̲̖̝̗̜̑̄̿̀̒̆̒͝ͅ -̸̭͍͚͔̟͔̃́̊̊̃̌̇͟ 2̭̼͇̙̘̮̺͊̊͐̿́͐͝7̷͓̝̣̗̣̍̍̇̆̚̚͝ Л͙͕̫̞̳̳̻̫̈̃̇͌̄̕͜ л̧̢̣̪̫̩̮̾̍̾̊̑́ͅ ̶̡̛̛̤͚̝̹̥̮̱̖͍͒͌̓̌̿͒̌͘ ̛̗̥͔̟͖̣͎͋̉̿̔̿͘͞͠͞
̴̝͉͕̞̫̠̻̺͚͐͐͛̿̎̊͆͞͠ -̡̗̻͙̰̩͕̙̄͒̿̑͋͢ 3̸̨̡͙̥̻͚̗̱̅͆́̿̇̓͗͌̾0͎͖̞̼̻̩͍͓̑̽̅̇́͘ М̡̗͉͖͙̙͓͗̆̌͑̊͆͡м̞̲͓͖̘͇͙̇͌͛͌̏̕͘͢͝ ̷̛̞͙͎̠̮̲̅̈̎̐̚͜͡͝͝ ̧͉͉͕̝̅͗̓͐̿́̏͆̕̚
̡͔̬̪̰͌̓͐͋̓͠͠͠ -̴̨̡̯̫̱̖̭͕̎́̀̄̈́̎ 3̛̯̭͔̳͓̗̥͚̙̂͛̉̀̀ͅ1̲̳̺̲̺̦̑̋͂̇͋̇̐̕ Н̧̖̖͍̤̪̬͓̝̐̆͒̏̔ н̴̺͖̙͎̰͌̊̌̍͞ ̴̭͓͔͕͙̖̲̱̭̉͌͒́̐̀̐͟ ̬̘͚̯̙̓̀̃͆̈̇̌̍̉͢</p>
<p dir="auto">̬̘͚̯̙̓̀̃͆̈̇̌̍̉͢
̴̭͓͔͕͙̖̲̱̭ ̴̭͓͔͕͙̖̲̱̭̉͌͒́̐̀̐͟Oryx and Huge Craine by Maggie Phat Backwoods3̛̯̭͔̳͓̗̥͚̙̂͛̉̀̀ͅ1̴̲̳̺̲̺̦̭͓͔͕͙̖̲̱̭̑̋͂̇͋̇̐</p>
<p dir="auto">̧͉͉͕̝̅͗̓͐̿́̏͆̕̚ This ancient legend regards two deranged losers from the Bozo Club of Ancient Egypt who watch thorн̴̺͖̙͎̰͌̊̌̍͞ography all day as the world dies: Despite the essentially elaborate scope of the plot revealed in the novel's conclusion, the narrative focuses almost exclusively on the bleak and unrewarding day-to-day lives of the protagonists, two half-brothers who barely know each other.</p>
<p dir="auto">К̴̨͍̖͕͖̫͙͖͌̀̈́̎͋̈̈́̋͢͟Ӏ̴̢̨̦̩̮̹̹̑͊́̔̈̇̈́͢͡у̧͓͕͖̠̀̀̑́̍͋͒̇̕͢͞ͅir sister has magical powers and banished them, taking the throne herself. They decided to return for Mher to dispose of her. Mher meets a woman who he realizes must be their sister in disguise, decapitates her with a slap, and the brothers rejoice and offer Mher the throne. He declines and they all decide to go to Baghdad together to see the tomb of Mher's ancestor Balthasar. ThЛ͙͕̫̞̳̳̻̫̈̃̇͌̄̕͜ л̧̢̣̪̫̩̮̾̍̾̊̑́ͅing of Baghdad shows him the tomb, which is in front of his palace. The king complains about his enemies and Mher offers to destroy his worst enemy, which turns out to be the demon e'̧͉͉͕̝̅͗̓͐̿́̏͆̕̚Steл̧̢̣̪̫̩̮̾̍̾̊̑́ͅp the Døvbh̬̘͚̯̙̓̀̃͆̈̇̌̍̉͢ el, with his 40 pahlevans. Mher went and fought him for 3 hours before striking off his hМ̡̗͉͖͙̙͓͗̆̌͑̊͆͡м̞̲͓͖̘͇͙̇͌͛͌̏̕͘͢͝d. As he was about to wipe out the pahlevans, they all got naked and he realized they were women.</p>
<p dir="auto">-̧̻̬̤̼̥̟͒̆̐̋̄̕͟͜ ź̵͔̭̙̠̹̤̭̩͖̣̈́́͑́̇͂͗̄̚̕ At some point, Hou Meн̴̺͖̙͎̰͌̊̌̍͞g, the governor of Bozo Town, asked Song Jiang to recommending him to rebel leader named Fang La to join his cause. Zhang Shuye, the governor of Haizhou, designed to capture the deputy leader of Song Jiang's army, and Jiang and others all surrendered. Fang La announced to the world that he opposed the Zhao family's policy of exploiting the people and fawning on foreigners, and that he should not be recruited. Although Song Jiang also opposed corruption, he still respected the emperor of the Zhao family and used violence as bait to wait for the recruit.</p>
<p dir="auto">̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠ After taking the women and the severed head to the King of Baghdad who offered Mher his throne, Mher refuses victory until he can see it on the ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠blockchain ̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠and asked instead for a church to be built so that the 40 sons and grandsons from the east could marry these 40 women. It was done. Mher then refused the princess of Baghdad in marriage and left with the 80 newlyweds. Mher then goes to King Pajik, who offers to have him marry his daughter Gohar Katun, which after passing a few tests of worthiness, he does. Gohar refuses to sleep with Mher, unless he destroys another enemy, which he does. But the father's curse is being fulfilled. Mher remains childless.</p>
<p dir="auto">̧̛͚͍͍̬̓͑̈́̓̈́͑̈͠They seem devoid of love, and in their loveless or soon-to-be loveless ̱̼̹͕̘̆̀̀̆̑͟͜ H'ourneys, Bruno becomes a saddened loner, wrecked by his upbringing and failure to individuate, while Michel's pioneering work in cloning removes love from the process of reproduction. Humans are proved, in the end, to be just particles and just as bodies decay (a theme in the book) they can also be created from particles. 3̛̯̭͔̳͓̗̥͚̙̂͛̉̀̀ͅ1̲̳̺̲̺̦̑̋͂̇͋̇̐̕</p>
<ul dir="auto">
<li>′′ 
-̫̱͖̳̪̦̗͓͂̽͌̈́̀̀ 2̴̧̡̥̗̘̝̰͊͛̀́͠ͅ3̡̖̗͍̲̱̊́̓͗̍̽̓͌̄͡ К̸̻̘͈͕̬͈̐̍͆̆̆̍ъ̛͖͙̦̘̟̎̈́͐̈̕̕̚̕͝ͅк̷̟̭̯̭̿̌̾͛̃̔̚͠ͅъ̸̨̞̼̬̦͙̔̅́̽͒̍̋</li>
</ul>



===================================
-----------------------------------


Glossary of ObJect Slanguage (JavaScript.js / ECMAScript Standard Java / Avaj Nus Tella Version 2.0)


# java.js
• Future features

jScript: EK-VCE 
--------------------------------------





Java Packages
--------------------------------------

Java interfaces and classes are grouped into packages. The following lists the java packages, from which you can access interfaces and classes.

java.lang: The Java Language Package 
--------------------------------------
    Package that contains essential Java classes, including numerics, strings, objects, compiler, runtime, security, and threads. This is the only package that is automatically imported into every Java program. 

java.io: The Java I/O Package 
--------------------------------------
    Package that provides classes to manage input and output streams to read data from and write data to files, strings, and other sources. 

java.util: Miscellaneous Java utilities and data structures 
--------------------------------------
    Package that contains miscellaneous utility classes, including generic data structures, bit sets, time, date, string manipulation, random number generation, system properties, notification, and enumeration of data structures. 

java.net: The Java Networking Package 
--------------------------------------
    Package that provides classes for network support, including URLs, TCP sockets, UDP sockets, IP addresses, and a binary-to-text converter. 

java.awt: The Abstract Window Toolkit (AWT) Package 
--------------------------------------
    Package that provides an integrated set of classes to manage user interface components such as windows, dialog boxes, buttons, checkboxes, lists, menus, scrollbars, and text fields. (AWT = Abstract Window Toolkit) 

java.awt.image: The AWT Image Package 
--------------------------------------
    Package that provides classes for managing image data, including color models, cropping, color filtering, setting pixel values, and grabbing snapshots. 

java.awt.peer: The AWT Peer Package 
--------------------------------------
    Package that connects AWT components to their platform-specific implementations (such as Motif widgets or Microsoft Windows controls). 

java.applet: The Java Applet Package 
--------------------------------------
    Package that enables the creation of applets through the Applet class. It also provides several interfaces that connect an applet to its document and to resources for playing audio. 


Class List
--------------------------------------

    AddExpression.class
    
    AndExpression.class
    
    ArrayAccessExpression.class
    
    ArrayExpression.class
    
    AssignAddExpression.class
    
    AssignBitAndExpression.class
    
    AssignBitOrExpression.class
    
    AssignBitXorExpression.class
    
    AssignDivideExpression.class

    AssignExpression.class

    AssignMultiplyExpression.class

    AssignOpExpression.class

    AssignRemainderExpression.class

    AssignShiftLeftExpression.class

    AssignShiftRightExpression.class

    AssignSubtractExpression.class

    AssignUnsignedShiftRightExpression.class

    BinaryArithmeticExpression.class

    BinaryAssignExpression.class

    BinaryBitExpression.class

    BinaryCompareExpression.class

    BinaryEqualityExpression.class

    BinaryExpression.class

    BinaryLogicalExpression.class

    BinaryShiftExpression.class

    BitAndExpression.class

    BitNotExpression.class

    BitOrExpression.class

    BitXorExpression.class

    BooleanExpression.class
    
    BreakStatement.class
    
    ByteExpression.class
    
    CaseStatement.class
    
    CastExpression.class
    
    CatchStatement.class
    
    CharExpression.class
    
    CheckContext.class
    
    CodeContext.class
    
    CommaExpression.class
    
    CompoundStatement.class
    
    ConditionVars.class
    
    ConditionalExpression.class
    
    ConstantExpression.class
    
    Context.class
    
    ContinueStatement.class
    
    ConvertExpression.class
    
    DeclarationStatement.class
    
    DivRemExpression.class
    
    DivideExpression.class
    
    DoStatement.class
    
    DoubleExpression.class
    
    EqualExpression.class
    
    ExprExpression.class
    
    Expression.class
    
    ExpressionStatement.class
    
    FieldExpression.class
    
    FinallyStatement.class
    
    FloatExpression.class
    
    ForStatement.class
    
    GreaterExpression.class
    
    GreaterOrEqualExpression.class
    
    IdentifierExpression.class
    
    IfStatement.class
    
    IncDecExpression.class
    
    InlineMethodExpression.class
    
    InlineNewInstanceExpression.class
    
    InlineReturnStatement.class
    
    InstanceOfExpression.class
    
    IntExpression.class
    
    IntegerExpression.class
    
    LengthExpression.class
    
    LessExpression.class
    
    LessOrEqualExpression.class
    
    LocalField.class
    
    LongExpression.class
    
    MethodExpression.class
    
    MultiplyExpression.class
    
    NaryExpression.class
    
    NegativeExpression.class
    
    NewArrayExpression.class
    
    NewInstanceExpression.class
    
    Node.class
    
    NotEqualExpression.class
    
    NotExpression.class
    
    NullExpression.class
    
    OrExpression.class
    
    PositiveExpression.class
    
    PostDecExpression.class
    
    PostIncExpression.class
    
    PreDecExpression.class
    
    PreIncExpression.class
    
    RemainderExpression.class
    
    ReturnStatement.class
    
    ShiftLeftExpression.class
    
    ShiftRightExpression.class
    
    ShortExpression.class
    
    Statement.class
    
    StringExpression.class
    
    SubtractExpression.class
    
    SuperExpression.class
    
    SwitchStatement.class
    
    SynchronizedStatement.class
    
    ThisExpression.class
    
    ThrowStatement.class
    
    TryStatement.class
    
    TypeExpression.class
    
    UnaryExpression.class
    
    UnsignedShiftRightExpression.class
    
    VarDeclarationStatement.class
    
    WhileStatement.class





Running applets with the Applet Viewer
--------------------------------------
Here are two examples of using the Applet Viewer:

  bin/appletviewer demo/GraphLayout/example1.html
  bin/appletviewer http://java.sun.com/applets/applets/NervousText/example1.html 
  (On the PC, use "bin\appletviewer" instead of "bin/appletviewer".)

The argument is a filename or URI that refers to an HTML file that
contains one or more APPLET tags.  The Applet Viewer finds the APPLET
tags in the HTML file and runs the applets as specified by the tags
(in separate windows).


The APPLET tag
--------------
The APP tag of previous releases is gone, replaced by the APPLET tag. 
Here is an example of a simple APPLET tag:

  <applet code="MyApplet.class" width=100 height=140></applet>

This tells the viewer or browser to load the applet whose compiled
code is in MyApplet.class (in the same directory as the current HTML
document), and to set the initial size of the applet to 100 pixels
wide and 140 pixels high.

Here's a more complex example of an APPLET tag:

  <applet codebase="http://java.sun.com/applets/applets/NervousText"
	code="NervousText.class" width=400 height=75 align=center >
  <param name="text" value="This is the Applet Viewer.">
  <blockquote>
  <hr>
  If you were using a Java-enabled browser,
  you would see dancing text instead of this paragraph.
  <hr>
  </blockquote>
  </applet>

This tells the viewer or browser to load the applet whose compiled
code is at the URI
http://java.sun.com/applets/applets/NervousText/NervousText.class,
to set the initial size of the applet to 400x75 pixels, and to align
the applet in the center of the line.  The viewer/browser must also
set the applet's "text" attribute (which customizes the text this
applet displays) to be "This is the Applet Viewer."  If the page is
viewed by a browser that can't execute Java applets, then the browser
will ignore the APPLET and PARAM tags, displaying the HTML between
the <blockquote> and </blockquote> tags.  Java-enabled browsers
*ignore* that HTML.

Here's the complete syntax for the APPLET tag:

    '<' 'APPLET'
        ['CODEBASE' '=' codebaseURI]
        'CODE' '=' appletFile
	['ALT' '=' alternateText]
	['NAME' '=' appletInstanceName]
	'WIDTH' '=' pixels 'HEIGHT' '=' pixels
	['ALIGN' '=' alignment]
	['VSPACE' '=' pixels] ['HSPACE' '=' pixels]
    '>'
    ['<' 'PARAM' 'NAME' '=' appletAttribute1 'VALUE' '=' value '>']
    ['<' 'PARAM' 'NAME' '=' appletAttribute2 'VALUE' '=' value '>']
    . . .
    [alternateHTML]
    '</APPLET>'

'CODEBASE' '=' codebaseURI
    This optional attribute specifies the base URI of the applet --
    the directory that contains the applet's code.  If this attribute
    is not specified, then the document's URI is used.

'CODE' '=' appletFile
    This required attribute gives the name of the file that contains
    the applet's compiled Applet subclass.  This file is relative to
    the base URI of the applet.  It cannot be absolute.
    
'ALT' '=' alternateText
    This optional attribute specifies any text that should be
    displayed if the browser understands the APPLET tag but can't
    run Java applets.

'NAME' '=' appletInstanceName
    This optional attribute specifies a name for the applet instance,
    which makes it possible for applets on the same page to find (and
    communicate with) each other.

'WIDTH' '=' pixels 'HEIGHT' '=' pixels
    These required attributes give the initial width and height (in
    pixels) of the applet display area, not counting any windows or
    dialogs that the applet brings up.  

'ALIGN' '=' alignment
    This required attribute specifies the alignment of the applet.
    The possible values of this attribute are the same as those for
    the IMG tag: left, right, top, texttop, middle, absmiddle,
    baseline, bottom, absbottom.

'VSPACE' '=' pixels 'HSPACE' '=' pixels
    These option attributes specify the number of pixels above and
    below the applet (VSPACE) and on each side of the applet (HSPACE).
    They're treated the same way as the IMG tag's VSPACE and HSPACE
    attributes.

'<' 'PARAM' 'NAME' '=' appletAttribute1 'VALUE' '=' value '>' . . .
    This tag is the only way to specify an applet-specific attribute.
    Applets access their attributes with the getParameter() method.


Debugging programs with JDB
---------------------------
This release contains the Java Debugger (JDB), an alpha-quality
prototype of a command-line debugger for Java classes.  It is
designed to test the Java Debugger API, which is in the package
java.tools.debug.  We look forward to getting your feedback on
the debugger API.

You can debug applets using the -debug option of appletviewer.
When debugging applets, it's best to invoke appletviewer from
the directory that contains the applet's HTML file.  For example,
on Solarix:

    cd demo/TicTacToe
    ../../bin/appletviewer -debug example1.html 

On the PC:

    cd demo\TicTacToe
    ..\..\bin\appletviewer -debug example1.html 
    
Future pipeline:

[TBD]






Index
--------------------------------------


A
--------------------------------------

ABORT
--------------------------------------
    static int ABORT in interface ImageObserver II-308 
ABORTED
--------------------------------------
    static int ABORTED in class MediaTracker II-177 
abs
--------------------------------------
    static double abs(double) in class Math I-60 
    static float abs(float) in class Math I-61 
    static int abs(int) in class Math I-61 
    static long abs(long) in class Math I-61 
AbstractMethodError
--------------------------------------
    AbstractMethodError() in class AbstractMethodError I-188 
    AbstractMethodError(String) in class AbstractMethodError I-188 
    Class in package java.lang I-188 
accept
--------------------------------------
    boolean accept(File, String) in interface FilenameFilter I-345 
    Socket accept() in class ServerSocket I-423 
    void accept(SocketImpl) in class SocketImpl I-431 
acos
--------------------------------------
    static double acos(double) in class Math I-62 
action
--------------------------------------
    boolean action(Event, Object) in class Component II-41 
ACTION_EVENT
--------------------------------------
    static int ACTION_EVENT in class Event II-85 
activeCount
--------------------------------------
    int activeCount() in class ThreadGroup I-151 
    static int activeCount() in class Thread I-142 
activeGroupCount
--------------------------------------
    int activeGroupCount() in class ThreadGroup I-151 
add
--------------------------------------
    Component add(Component) in class Container II-69 
    Component add(Component, int) in class Container II-69 
    Component add(String, Component) in class Container II-69 
    Menu add(Menu) in class MenuBar II-189 
    MenuItem add(MenuItem) in class Menu II-186 
    void add(int, int) in class Rectangle II-205 
    void add(Point) in class Rectangle II-205 
    void add(Rectangle) in class Rectangle II-206 
    void add(String) in class Menu II-186 
addConsumer
--------------------------------------
    void addConsumer(ImageConsumer) in class FilteredImageSource II-266 
    void addConsumer(ImageConsumer) in class MemoryImageSource II-285 
    void addConsumer(ImageConsumer) in interface ImageProducer II-312 
addElement
--------------------------------------
    void addElement(Object) in class Vector I-394 
addHelpMenu
--------------------------------------
    void addHelpMenu(Menu) in interface MenuBarPeer II-339 
addImage
--------------------------------------
    void addImage(Image, int) in class MediaTracker II-178 
    void addImage(Image, int, int, int) in class MediaTracker II-178 
addItem
--------------------------------------
    void addItem(MenuItem) in interface MenuPeer II-342 
    void addItem(String) in class Choice II-28 
    void addItem(String) in class List II-167 
    void addItem(String, int) in class List II-167 
    void addItem(String, int) in interface ChoicePeer II-322 
    void addItem(String, int) in interface ListPeer II-336 
addLayoutComponent
--------------------------------------
    void addLayoutComponent(String, Component) in class BorderLayout II-6 
    void addLayoutComponent(String, Component) in class CardLayout II-15 
    void addLayoutComponent(String, Component) in class FlowLayout II-99 
    void addLayoutComponent(String, Component) in class GridBagLayout II-148 
    void addLayoutComponent(String, Component) in class GridLayout II-153 
    void addLayoutComponent(String, Component) in interface LayoutManager II-244 
addMenu
--------------------------------------
    void addMenu(Menu) in interface MenuBarPeer II-339 
addNotify
--------------------------------------
    void addNotify() in class Button II-10 
    void addNotify() in class Canvas II-12 
    void addNotify() in class Checkbox II-21 
    void addNotify() in class CheckboxMenuItem II-26 
    void addNotify() in class Choice II-28 
    void addNotify() in class Component II-41 
    void addNotify() in class Container II-70 
    void addNotify() in class Dialog II-78 
    void addNotify() in class FileDialog II-94 
    void addNotify() in class Frame II-116 
    void addNotify() in class Label II-162 
    void addNotify() in class List II-167 
    void addNotify() in class Menu II-186 
    void addNotify() in class MenuBar II-189 
    void addNotify() in class MenuItem II-195 
    void addNotify() in class Panel II-197 
    void addNotify() in class Scrollbar II-213 
    void addNotify() in class TextArea II-219 
    void addNotify() in class TextField II-227 
    void addNotify() in class Window II-241 
addObserver
--------------------------------------
    void addObserver(Observer) in class Observable I-378 
addPoint
--------------------------------------
    void addPoint(int, int) in class Polygon II-202 
address
--------------------------------------
    InetAddress address in class SocketImpl I-430 
addSeparator
--------------------------------------
    void addSeparator() in class Menu II-186 
    void addSeparator() in interface MenuPeer II-342 
after
--------------------------------------
    boolean after(Date) in class Date I-363 
ALLBITS
--------------------------------------
    static int ALLBITS in interface ImageObserver II-309 
allowsMultipleSelections
--------------------------------------
    boolean allowsMultipleSelections() in class List II-167 
allowUserInteraction
--------------------------------------
    boolean allowUserInteraction in class URLConnection I-446 
ALT_MASK
--------------------------------------
    static int ALT_MASK in class Event II-89 
anchor
--------------------------------------
    int anchor in class GridBagConstraints II-140 
and
--------------------------------------
    void and(BitSet) in class BitSet I-357 
append
--------------------------------------
    StringBuffer append(boolean) in class StringBuffer I-117 
    StringBuffer append(char) in class StringBuffer I-117 
    StringBuffer append(char[]) in class StringBuffer I-118 
    StringBuffer append(char[], int, int) in class StringBuffer I-118 
    StringBuffer append(double) in class StringBuffer I-118 
    StringBuffer append(float) in class StringBuffer I-119 
    StringBuffer append(int) in class StringBuffer I-119 
    StringBuffer append(long) in class StringBuffer I-119 
    StringBuffer append(Object) in class StringBuffer I-120 
    StringBuffer append(String) in class StringBuffer I-120 
appendText
--------------------------------------
    void appendText(String) in class TextArea II-219 
Applet
--------------------------------------
    Applet() in class Applet 356 
    Class in package java.applet 356 
AppletContext
--------------------------------------
    Interface in package java.applet 364 
appletResize
--------------------------------------
    void appletResize(int, int) in interface AppletStub 367 
AppletStub
--------------------------------------
    Interface in package java.applet 367 
arg
--------------------------------------
    Object arg in class Event II-84 
ArithmeticException
--------------------------------------
    ArithmeticException() in class ArithmeticException I-166 
    ArithmeticException(String) in class ArithmeticException I-166 
    Class in package java.lang I-166 
arraycopy
--------------------------------------
    static void arraycopy(Object, int, Object, int, int) in class System I-131 
ArrayIndexOutOfBoundsException
--------------------------------------
    ArrayIndexOutOfBoundsException() in class ArrayIndexOutOfBoundsException I-167 
    ArrayIndexOutOfBoundsException(int) in class ArrayIndexOutOfBoundsException I-167 
    ArrayIndexOutOfBoundsException(String) in class ArrayIndexOutOfBoundsException I-167 
    Class in package java.lang I-167 
ArrayStoreException
--------------------------------------
    ArrayStoreException() in class ArrayStoreException I-168 
    ArrayStoreException(String) in class ArrayStoreException I-168 
    Class in package java.lang I-168 
asin
--------------------------------------
    static double asin(double) in class Math I-62 
atan
--------------------------------------
    static double atan(double) in class Math I-62 
atan2
--------------------------------------
    static double atan2(double, double) in class Math I-62 
AudioClip
--------------------------------------
    Interface in package java.applet 369 
available
--------------------------------------
    int available() in class BufferedInputStream I-212 
    int available() in class ByteArrayInputStream I-220 
    int available() in class FileInputStream I-255 
    int available() in class FilterInputStream I-264 
    int available() in class InputStream I-274 
    int available() in class LineNumberInputStream I-279 
    int available() in class PushbackInputStream I-300 
    int available() in class SocketImpl I-431 
    int available() in class StringBufferInputStream I-330 
AWTError
--------------------------------------
    AWTError(String) in class AWTError II-250 
    Class in package java.awt II-250 
AWTException
--------------------------------------
    AWTException(String) in class AWTException II-248 
    Class in package java.awt II-248 

B
--------------------------------------

before
--------------------------------------
    boolean before(Date) in class Date I-364 
bind
--------------------------------------
    void bind(InetAddress, int) in class SocketImpl I-432 
BitSet
--------------------------------------
    BitSet() in class BitSet I-356 
    BitSet(int) in class BitSet I-356 
    Class in package java.util I-356 
black
--------------------------------------
    static Color black in class Color II-32 
blue
--------------------------------------
    static Color blue in class Color II-32 
BOLD
--------------------------------------
    static int BOLD in class Font II-103 
Boolean
--------------------------------------
    Boolean(boolean) in class Boolean I-5 
    Boolean(String) in class Boolean I-5 
    Class in package java.lang I-4 
booleanValue
--------------------------------------
    boolean booleanValue() in class Boolean I-5 
BorderLayout
--------------------------------------
    BorderLayout() in class BorderLayout II-5 
    BorderLayout(int, int) in class BorderLayout II-6 
    Class in package java.awt II-4 
BOTH
--------------------------------------
    static int BOTH in class GridBagConstraints II-143 
bottom
--------------------------------------
    int bottom in class Insets II-159 
bounds
--------------------------------------
    Rectangle bounds() in class Component II-41 
brighter
--------------------------------------
    Color brighter() in class Color II-34 
buf
--------------------------------------
    byte buf[] in class BufferedInputStream I-210 
    byte buf[] in class BufferedOutputStream I-216 
    byte buf[] in class ByteArrayInputStream I-219 
    byte buf[] in class ByteArrayOutputStream I-223 
buffer
--------------------------------------
    String buffer in class StringBufferInputStream I-329 
BufferedInputStream
--------------------------------------
    BufferedInputStream(InputStream) in class BufferedInputStream I-211 
    BufferedInputStream(InputStream, int) in class BufferedInputStream I-211 
    Class in package java.io I-210 
BufferedOutputStream
--------------------------------------
    BufferedOutputStream(OutputStream) in class BufferedOutputStream I-216 
    BufferedOutputStream(OutputStream, int) in class BufferedOutputStream I-217 
    Class in package java.io I-216 
Button
--------------------------------------
    Button() in class Button II-10 
    Button(String) in class Button II-10 
    Class in package java.awt II-9 
ButtonPeer
--------------------------------------
    Interface in package java.awt.peer II-318 
ByteArrayInputStream
--------------------------------------
    ByteArrayInputStream(byte[]) in class ByteArrayInputStream I-220 
    ByteArrayInputStream(byte[], int, int) in class ByteArrayInputStream I-220 
    Class in package java.io I-219 
ByteArrayOutputStream
--------------------------------------
    ByteArrayOutputStream() in class ByteArrayOutputStream I-223 
    ByteArrayOutputStream(int) in class ByteArrayOutputStream I-224 
    Class in package java.io I-223 
bytesTransferred
--------------------------------------
    int bytesTransferred in class InterruptedIOException I-351 
bytesWidth
--------------------------------------
    int bytesWidth(byte[], int, int) in class FontMetrics II-109 

C
--------------------------------------


canFilterIndexColorModel
--------------------------------------
    boolean canFilterIndexColorModel in class RGBImageFilter II-295, II-296 
canRead
--------------------------------------
    boolean canRead() in class File I-246 
Canvas
--------------------------------------
    Canvas() in class Canvas II-12 
    Class in package java.awt II-12 
CanvasPeer
--------------------------------------
    Interface in package java.awt.peer II-319 
canWrite
--------------------------------------
    boolean canWrite() in class File I-246 
capacity
--------------------------------------
    int capacity() in class StringBuffer I-120 
    int capacity() in class Vector I-394 
capacityIncrement
--------------------------------------
    int capacityIncrement in class Vector I-393 
CardLayout
--------------------------------------
    CardLayout() in class CardLayout II-14 
    CardLayout(int, int) in class CardLayout II-14 
    Class in package java.awt II-14 
ceil
--------------------------------------
    static double ceil(double) in class Math I-62 
CENTER
--------------------------------------
    static int CENTER in class FlowLayout II-98 
    static int CENTER in class GridBagConstraints II-142 
    static int CENTER in class Label II-161 
Character
--------------------------------------
    Character(char) in class Character I-8 
    Class in package java.lang I-7 
charAt
--------------------------------------
    char charAt(int) in class String I-101 
    char charAt(int) in class StringBuffer I-121 
charsWidth
--------------------------------------
    int charsWidth(char[], int, int) in class FontMetrics II-110 
charValue
--------------------------------------
    char charValue() in class Character I-9 
charWidth
--------------------------------------
    int charWidth(char) in class FontMetrics II-110 
    int charWidth(int) in class FontMetrics II-110 
checkAccept
--------------------------------------
    void checkAccept(String, int) in class SecurityManager I-87 
checkAccess
--------------------------------------
    void checkAccess() in class Thread I-142 
    void checkAccess() in class ThreadGroup I-152 
    void checkAccess(Thread) in class SecurityManager I-87 
    void checkAccess(ThreadGroup) in class SecurityManager I-88 
checkAll
--------------------------------------
    boolean checkAll() in class MediaTracker II-178 
    boolean checkAll(boolean) in class MediaTracker II-179 
Checkbox
--------------------------------------
    Checkbox() in class Checkbox II-20 
    Checkbox(String) in class Checkbox II-20 
    Checkbox(String, CheckboxGroup, boolean) in class Checkbox II-20 
    Class in package java.awt II-19 
CheckboxGroup
--------------------------------------
    CheckboxGroup() in class CheckboxGroup II-24 
    Class in package java.awt II-23 
CheckboxMenuItem
--------------------------------------
    CheckboxMenuItem(String) in class CheckboxMenuItem II-25 
    Class in package java.awt II-25 
CheckboxMenuItemPeer
--------------------------------------
    Interface in package java.awt.peer II-320 
CheckboxPeer
--------------------------------------
    Interface in package java.awt.peer II-321 
checkConnect
--------------------------------------
    void checkConnect(String, int) in class SecurityManager I-88 
    void checkConnect(String, int, Object) in class SecurityManager I-89 
checkCreateClassLoader
--------------------------------------
    void checkCreateClassLoader() in class SecurityManager I-89 
checkDelete
--------------------------------------
    void checkDelete(String) in class SecurityManager I-89 
checkError
--------------------------------------
    boolean checkError() in class PrintStream I-292 
checkExec
--------------------------------------
    void checkExec(String) in class SecurityManager I-90 
checkExit
--------------------------------------
    void checkExit(int) in class SecurityManager I-90 
checkID
--------------------------------------
    boolean checkID(int) in class MediaTracker II-179 
    boolean checkID(int, boolean) in class MediaTracker II-180 
checkImage
--------------------------------------
    int checkImage(Image, ImageObserver) in class Component II-42 
    int checkImage(Image, int, int, ImageObserver) in class Component II-43 
    int checkImage(Image, int, int, ImageObserver) in class Toolkit II-233 
    int checkImage(Image, int, int, ImageObserver) in interface ComponentPeer II-324 
checkLink
--------------------------------------
    void checkLink(String) in class SecurityManager I-91 
checkListen
--------------------------------------
    void checkListen(int) in class SecurityManager I-91 
checkPackageAccess
--------------------------------------
    void checkPackageAccess(String) in class SecurityManager I-91 
checkPackageDefinition
--------------------------------------
    void checkPackageDefinition(String) in class SecurityManager I-92 
checkPropertiesAccess
--------------------------------------
    void checkPropertiesAccess() in class SecurityManager I-92 
checkPropertyAccess
--------------------------------------
    void checkPropertyAccess(String) in class SecurityManager I-92 
checkRead
--------------------------------------
    void checkRead(FileDescriptor) in class SecurityManager I-93 
    void checkRead(String) in class SecurityManager I-93 
    void checkRead(String, Object) in class SecurityManager I-93 
checkSetFactory
--------------------------------------
    void checkSetFactory() in class SecurityManager I-94 
checkTopLevelWindow
--------------------------------------
    boolean checkTopLevelWindow(Object) in class SecurityManager I-94 
checkWrite
--------------------------------------
    void checkWrite(FileDescriptor) in class SecurityManager I-94 
    void checkWrite(String) in class SecurityManager I-95 
Choice
--------------------------------------
    Choice() in class Choice II-28 
    Class in package java.awt II-27 
ChoicePeer
--------------------------------------
    Interface in package java.awt.peer II-322 
Class
--------------------------------------
    Class in package java.lang I-18 
ClassCastException
--------------------------------------
    Class in package java.lang I-169 
    ClassCastException() in class ClassCastException I-169 
    ClassCastException(String) in class ClassCastException I-169 
ClassCircularityError
--------------------------------------
    Class in package java.lang I-189 
    ClassCircularityError() in class ClassCircularityError I-189 
    ClassCircularityError(String) in class ClassCircularityError I-189 
classDepth
--------------------------------------
    int classDepth(String) in class SecurityManager I-95 
Classes
--------------------------------------
    java.applet.Applet 356 
    java.awt.AWTError II-250 
    java.awt.AWTException II-248 
    java.awt.BorderLayout II-4 
    java.awt.Button II-9 
    java.awt.Canvas II-12 
    java.awt.CardLayout II-14 
    java.awt.Checkbox II-19 
    java.awt.CheckboxGroup II-23 
    java.awt.CheckboxMenuItem II-25 
    java.awt.Choice II-27 
    java.awt.Color II-31 
    java.awt.Component II-39 
    java.awt.Container II-68 
    java.awt.Dialog II-77 
    java.awt.Dimension II-80 
    java.awt.Event II-82 
    java.awt.FileDialog II-93 
    java.awt.FlowLayout II-97 
    java.awt.Font II-102 
    java.awt.FontMetrics II-108 
    java.awt.Frame II-114 
    java.awt.Graphics II-120 
    java.awt.GridBagConstraints II-139 
    java.awt.GridBagLayout II-145 
    java.awt.GridLayout II-151 
    java.awt.Image II-156 
    java.awt.image.ColorModel II-254 
    java.awt.image.CropImageFilter II-257 
    java.awt.image.DirectColorModel II-260 
    java.awt.image.FilteredImageSource II-265 
    java.awt.image.ImageFilter II-268 
    java.awt.image.IndexColorModel II-273 
    java.awt.image.MemoryImageSource II-281 
    java.awt.image.PixelGrabber II-287 
    java.awt.image.RGBImageFilter II-294 
    java.awt.Insets II-159 
    java.awt.Label II-161 
    java.awt.List II-164 
    java.awt.MediaTracker II-174 
    java.awt.Menu II-185 
    java.awt.MenuBar II-188 
    java.awt.MenuComponent II-191 
    java.awt.MenuItem II-194 
    java.awt.Panel II-197 
    java.awt.Point II-198 
    java.awt.Polygon II-201 
    java.awt.Rectangle II-203 
    java.awt.Scrollbar II-210 
    java.awt.TextArea II-217 
    java.awt.TextComponent II-222 
    java.awt.TextField II-225 
    java.awt.Toolkit II-231 
    java.awt.Window II-240 
    java.io.BufferedInputStream I-210 
    java.io.BufferedOutputStream I-216 
    java.io.ByteArrayInputStream I-219 
    java.io.ByteArrayOutputStream I-223 
    java.io.DataInputStream I-226 
    java.io.DataOutputStream I-237 
    java.io.EOFException I-334 
    java.io.File I-243 
    java.io.FileDescriptor I-252 
    java.io.FileInputStream I-254 
    java.io.FileNotFoundException I-349 
    java.io.FileOutputStream I-259 
    java.io.FilterInputStream I-263 
    java.io.FilterOutputStream I-269 
    java.io.InputStream I-273 
    java.io.InterruptedIOException I-351 
    java.io.IOException I-350 
    java.io.LineNumberInputStream I-278 
    java.io.OutputStream I-282 
    java.io.PipedInputStream I-285 
    java.io.PipedOutputStream I-288 
    java.io.PrintStream I-291 
    java.io.PushbackInputStream I-299 
    java.io.RandomAccessFile I-303 
    java.io.SequenceInputStream I-319 
    java.io.StreamTokenizer I-322 
    java.io.StringBufferInputStream I-329 
    java.io.UTFDataFormatException I-352 
    java.lang.AbstractMethodError I-188 
    java.lang.ArithmeticException I-166 
    java.lang.ArrayIndexOutOfBoundsException I-167 
    java.lang.ArrayStoreException I-168 
    java.lang.Boolean I-4 
    java.lang.Character I-7 
    java.lang.Class I-18 
    java.lang.ClassCastException I-169 
    java.lang.ClassCircularityError I-189 
    java.lang.ClassFormatError I-190 
    java.lang.ClassLoader I-21 
    java.lang.ClassNotFoundException I-170 
    java.lang.CloneNotSupportedException I-171 
    java.lang.Compiler I-25 
    java.lang.Double I-27 
    java.lang.Error I-191 
    java.lang.Exception I-172 
    java.lang.Float I-34 
    java.lang.IllegalAccessError I-192 
    java.lang.IllegalAccessException I-173 
    java.lang.IllegalArgumentException I-174 
    java.lang.IllegalMonitorStateException I-175 
    java.lang.IllegalThreadStateException I-176 
    java.lang.IncompatibleClassChangeError I-193 
    java.lang.IndexOutOfBoundsException I-177 
    java.lang.InstantiationError I-194 
    java.lang.InstantiationException I-178 
    java.lang.Integer I-41 
    java.lang.InternalError I-195 
    java.lang.InterruptedException I-179 
    java.lang.LinkageError I-196 
    java.lang.Long I-50 
    java.lang.Math I-59 
    java.lang.NegativeArraySizeException I-180 
    java.lang.NoClassDefFoundError I-197 
    java.lang.NoSuchFieldError I-198 
    java.lang.NoSuchMethodError I-199 
    java.lang.NoSuchMethodException I-181 
    java.lang.NullPointerException I-182 
    java.lang.Number I-69 
    java.lang.NumberFormatException I-183 
    java.lang.Object I-70 
    java.lang.OutOfMemoryError I-200 
    java.lang.Process I-76 
    java.lang.Runtime I-78 
    java.lang.RuntimeException I-184 
    java.lang.SecurityException I-185 
    java.lang.SecurityManager I-85 
    java.lang.StackOverflowError I-201 
    java.lang.String I-98 
    java.lang.StringBuffer I-115 
    java.lang.StringIndexOutOfBoundsException I-186 
    java.lang.System I-129 
    java.lang.Thread I-137 
    java.lang.ThreadDeath I-202 
    java.lang.ThreadGroup I-150 
    java.lang.Throwable I-158 
    java.lang.UnknownError I-203 
    java.lang.UnsatisfiedLinkError I-204 
    java.lang.VerifyError I-205 
    java.lang.VirtualMachineError I-206 
    java.net.ContentHandler I-412 
    java.net.DatagramPacket I-413 
    java.net.DatagramSocket I-415 
    java.net.InetAddress I-418 
    java.net.MalformedURLException I-466 
    java.net.ProtocolException I-467 
    java.net.ServerSocket I-421 
    java.net.Socket I-425 
    java.net.SocketException I-468 
    java.net.SocketImpl I-430 
    java.net.UnknownHostException I-469 
    java.net.UnknownServiceException I-470 
    java.net.URL I-435 
    java.net.URLConnection I-443 
    java.net.URLEncoder I-457 
    java.net.URLStreamHandler I-458 
    java.util.BitSet I-356 
    java.util.Date I-360 
    java.util.Dictionary I-369 
    java.util.EmptyStackException I-406 
    java.util.Hashtable I-372 
    java.util.NoSuchElementException I-407 
    java.util.Observable I-378 
    java.util.Properties I-381 
    java.util.Random I-384 
    java.util.Stack I-386 
    java.util.StringTokenizer I-388 
    java.util.Vector I-392 
ClassFormatError
--------------------------------------
    Class in package java.lang I-190 
    ClassFormatError() in class ClassFormatError I-190 
    ClassFormatError(String) in class ClassFormatError I-190 
ClassLoader
--------------------------------------
    Class in package java.lang I-21 
    ClassLoader() in class ClassLoader I-22 
classLoaderDepth
--------------------------------------
    int classLoaderDepth() in class SecurityManager I-95 
ClassNotFoundException
--------------------------------------
    Class in package java.lang I-170 
    ClassNotFoundException() in class ClassNotFoundException I-170 
    ClassNotFoundException(String) in class ClassNotFoundException I-170 
clear
--------------------------------------
    void clear() in class Hashtable I-373 
    void clear() in class List II-167 
    void clear() in interface ListPeer II-336 
    void clear(int) in class BitSet I-357 
clearChanged
--------------------------------------
    void clearChanged() in class Observable I-379 
clearRect
--------------------------------------
    void clearRect(int, int, int, int) in class Graphics II-122 
clickCount
--------------------------------------
    int clickCount in class Event II-84 
clipRect
--------------------------------------
    void clipRect(int, int, int, int) in class Graphics II-123 
clone
--------------------------------------
    Object clone() in class BitSet I-357 
    Object clone() in class GridBagConstraints II-144 
    Object clone() in class Hashtable I-374 
    Object clone() in class ImageFilter II-269 
    Object clone() in class Insets II-160 
    Object clone() in class Object I-70 
    Object clone() in class Vector I-394 
Cloneable
--------------------------------------
    Interface in package java.lang I-162 
CloneNotSupportedException
--------------------------------------
    Class in package java.lang I-171 
    CloneNotSupportedException() in class CloneNotSupportedException I-171 
    CloneNotSupportedException(String) in class CloneNotSupportedException I-171 
close
--------------------------------------
    void close() in class DatagramSocket I-416 
    void close() in class FileInputStream I-256 
    void close() in class FileOutputStream I-260 
    void close() in class FilterInputStream I-264 
    void close() in class FilterOutputStream I-270 
    void close() in class InputStream I-274 
    void close() in class OutputStream I-282 
    void close() in class PipedInputStream I-286 
    void close() in class PipedOutputStream I-289 
    void close() in class PrintStream I-293 
    void close() in class RandomAccessFile I-305 
    void close() in class SequenceInputStream I-320 
    void close() in class ServerSocket I-423 
    void close() in class Socket I-427 
    void close() in class SocketImpl I-432 
Color
--------------------------------------
    Class in package java.awt II-31 
    Color(float, float, float) in class Color II-33 
    Color(int) in class Color II-33 
    Color(int, int, int) in class Color II-34 
ColorModel
--------------------------------------
    Class in package java.awt.image II-254 
    ColorModel(int) in class ColorModel II-254 
command
--------------------------------------
    static Object command(Object) in class Compiler I-25 
commentChar
--------------------------------------
    void commentChar(int) in class StreamTokenizer I-325 
compareTo
--------------------------------------
    int compareTo(String) in class String I-102 
compileClass
--------------------------------------
    static boolean compileClass(Class) in class Compiler I-25 
compileClasses
--------------------------------------
    static boolean compileClasses(String) in class Compiler I-26 
Compiler
--------------------------------------
    Class in package java.lang I-25 
COMPLETE
--------------------------------------
    static int COMPLETE in class MediaTracker II-177 
COMPLETESCANLINES
--------------------------------------
    static int COMPLETESCANLINES in interface ImageConsumer II-303 
Component
--------------------------------------
    Class in package java.awt II-39 
ComponentPeer
--------------------------------------
    Interface in package java.awt.peer II-323 
concat
--------------------------------------
    String concat(String) in class String I-102 
connect
--------------------------------------
    void connect() in class URLConnection I-448 
    void connect(InetAddress, int) in class SocketImpl I-432 
    void connect(PipedInputStream) in class PipedOutputStream I-289 
    void connect(PipedOutputStream) in class PipedInputStream I-286 
    void connect(String, int) in class SocketImpl I-432 
connected
--------------------------------------
    boolean connected in class URLConnection I-446 
consumer
--------------------------------------
    ImageConsumer consumer in class ImageFilter II-269 
Container
--------------------------------------
    Class in package java.awt II-68 
ContainerPeer
--------------------------------------
    Interface in package java.awt.peer II-330 
contains
--------------------------------------
    boolean contains(Object) in class Hashtable I-374 
    boolean contains(Object) in class Vector I-394 
containsKey
--------------------------------------
    boolean containsKey(Object) in class Hashtable I-374 
ContentHandler
--------------------------------------
    Class in package java.net I-412 
    ContentHandler() in class ContentHandler I-412 
ContentHandlerFactory
--------------------------------------
    Interface in package java.net I-462 
controlDown
--------------------------------------
    boolean controlDown() in class Event II-91 
copyArea
--------------------------------------
    void copyArea(int, int, int, int, int, int) in class Graphics II-123 
copyInto
--------------------------------------
    void copyInto(Object[]) in class Vector I-395 
copyValueOf
--------------------------------------
    static String copyValueOf(char[]) in class String I-102 
    static String copyValueOf(char[], int, int) in class String I-102 
cos
--------------------------------------
    static double cos(double) in class Math I-63 
count
--------------------------------------
    int count in class BufferedInputStream I-210 
    int count in class BufferedOutputStream I-216 
    int count in class ByteArrayInputStream I-219 
    int count in class ByteArrayOutputStream I-223 
    int count in class StringBufferInputStream I-329 
countComponents
--------------------------------------
    int countComponents() in class Container II-70 
countItems
--------------------------------------
    int countItems() in class Choice II-29 
    int countItems() in class List II-168 
    int countItems() in class Menu II-187 
countMenus
--------------------------------------
    int countMenus() in class MenuBar II-189 
countObservers
--------------------------------------
    int countObservers() in class Observable I-379 
countStackFrames
--------------------------------------
    int countStackFrames() in class Thread I-142 
countTokens
--------------------------------------
    int countTokens() in class StringTokenizer I-390 
create
--------------------------------------
    Graphics create() in class Graphics II-123 
    Graphics create(int, int, int, int) in class Graphics II-123 
    void create(boolean) in class SocketImpl I-433 
createButton
--------------------------------------
    ButtonPeer createButton(Button) in class Toolkit II-233 
createCanvas
--------------------------------------
    CanvasPeer createCanvas(Canvas) in class Toolkit II-233 
createCheckbox
--------------------------------------
    CheckboxPeer createCheckbox(Checkbox) in class Toolkit II-234 
createCheckboxMenuItem
--------------------------------------
    CheckboxMenuItemPeer createCheckboxMenuItem(CheckboxMenuItem) in class Toolkit II-234 
createChoice
--------------------------------------
    ChoicePeer createChoice(Choice) in class Toolkit II-234 
createContentHandler
--------------------------------------
    ContentHandler createContentHandler(String) in interface ContentHandlerFactory I-462 
createDialog
--------------------------------------
    DialogPeer createDialog(Dialog) in class Toolkit II-234 
createFileDialog
--------------------------------------
    FileDialogPeer createFileDialog(FileDialog) in class Toolkit II-234 
createFrame
--------------------------------------
    FramePeer createFrame(Frame) in class Toolkit II-235 
createImage
--------------------------------------
    Image createImage(ImageProducer) in class Component II-43 
    Image createImage(ImageProducer) in class Toolkit II-235 
    Image createImage(ImageProducer) in interface ComponentPeer II-324 
    Image createImage(int, int) in class Component II-43 
    Image createImage(int, int) in interface ComponentPeer II-324 
createLabel
--------------------------------------
    LabelPeer createLabel(Label) in class Toolkit II-235 
createList
--------------------------------------
    ListPeer createList(List) in class Toolkit II-235 
createMenu
--------------------------------------
    MenuPeer createMenu(Menu) in class Toolkit II-235 
createMenuBar
--------------------------------------
    MenuBarPeer createMenuBar(MenuBar) in class Toolkit II-236 
createMenuItem
--------------------------------------
    MenuItemPeer createMenuItem(MenuItem) in class Toolkit II-236 
createPanel
--------------------------------------
    PanelPeer createPanel(Panel) in class Toolkit II-236 
createScrollbar
--------------------------------------
    ScrollbarPeer createScrollbar(Scrollbar) in class Toolkit II-236 
createSocketImpl
--------------------------------------
    SocketImpl createSocketImpl() in interface SocketImplFactory I-463 
createTextArea
--------------------------------------
    TextAreaPeer createTextArea(TextArea) in class Toolkit II-236 
createTextField
--------------------------------------
    TextFieldPeer createTextField(TextField) in class Toolkit II-237 
createURLStreamHandler
--------------------------------------
    URLStreamHandler createURLStreamHandler(String) in interface URLStreamHandlerFactory I-464 
createWindow
--------------------------------------
    WindowPeer createWindow(Window) in class Toolkit II-237 
CropImageFilter
--------------------------------------
    Class in package java.awt.image II-257 
    CropImageFilter(int, int, int, int) in class CropImageFilter II-257 
CROSSHAIR_CURSOR
--------------------------------------
    static int CROSSHAIR_CURSOR in class Frame II-115 
CTRL_MASK
--------------------------------------
    static int CTRL_MASK in class Event II-89 
currentClassLoader
--------------------------------------
    ClassLoader currentClassLoader() in class SecurityManager I-95 
currentThread
--------------------------------------
    static Thread currentThread() in class Thread I-143 
currentTimeMillis
--------------------------------------
    static long currentTimeMillis() in class System I-132 
cyan
--------------------------------------
    static Color cyan in class Color II-32 

D
--------------------------------------


darker
--------------------------------------
    Color darker() in class Color II-34 
darkGray
--------------------------------------
    static Color darkGray in class Color II-32 
DatagramPacket
--------------------------------------
    Class in package java.net I-413 
    DatagramPacket(byte[], int) in class DatagramPacket I-413 
    DatagramPacket(byte[], int, InetAddress, int) in class DatagramPacket I-414 
DatagramSocket
--------------------------------------
    Class in package java.net I-415 
    DatagramSocket() in class DatagramSocket I-415 
    DatagramSocket(int) in class DatagramSocket I-416 
DataInput
--------------------------------------
    Interface in package java.io I-334 
DataInputStream
--------------------------------------
    Class in package java.io I-226 
    DataInputStream(InputStream) in class DataInputStream I-227 
DataOutput
--------------------------------------
    Interface in package java.io I-340 
DataOutputStream
--------------------------------------
    Class in package java.io I-237 
    DataOutputStream(OutputStream) in class DataOutputStream I-238 
Date
--------------------------------------
    Class in package java.util I-360 
    Date() in class Date I-362 
    Date(int, int, int) in class Date I-362 
    Date(int, int, int, int, int) in class Date I-362 
    Date(int, int, int, int, int, int) in class Date I-363 
    Date(long) in class Date I-363 
    Date(String) in class Date I-363 
DEFAULT_CURSOR
--------------------------------------
    static int DEFAULT_CURSOR in class Frame II-115 
defaults
--------------------------------------
    Properties defaults in class Properties I-381 
defineClass
--------------------------------------
    Class defineClass(byte[], int, int) in class ClassLoader I-23 
delete
--------------------------------------
    boolean delete() in class File I-246 
deleteObserver
--------------------------------------
    void deleteObserver(Observer) in class Observable I-379 
deleteObservers
--------------------------------------
    void deleteObservers() in class Observable I-379 
delItem
--------------------------------------
    void delItem(int) in class List II-168 
    void delItem(int) in interface MenuPeer II-342 
delItems
--------------------------------------
    void delItems(int, int) in class List II-168 
    void delItems(int, int) in interface ListPeer II-337 
deliverEvent
--------------------------------------
    void deliverEvent(Event) in class Component II-44 
    void deliverEvent(Event) in class Container II-70 
delMenu
--------------------------------------
    void delMenu(int) in interface MenuBarPeer II-339 
deselect
--------------------------------------
    void deselect(int) in class List II-168 
    void deselect(int) in interface ListPeer II-337 
destroy
--------------------------------------
    void destroy() in class Applet 357 
    void destroy() in class Process I-76 
    void destroy() in class Thread I-143 
    void destroy() in class ThreadGroup I-152 
Dialog
--------------------------------------
    Class in package java.awt II-77 
    Dialog(Frame, boolean) in class Dialog II-77 
    Dialog(Frame, String, boolean) in class Dialog II-78 
DialogPeer
--------------------------------------
    Interface in package java.awt.peer II-331 
Dictionary
--------------------------------------
    Class in package java.util I-369 
    Dictionary() in class Dictionary I-369 
digit
--------------------------------------
    static int digit(char, int) in class Character I-9 
Dimension
--------------------------------------
    Class in package java.awt II-80 
    Dimension() in class Dimension II-80 
    Dimension(Dimension) in class Dimension II-80 
    Dimension(int, int) in class Dimension II-81 
DirectColorModel
--------------------------------------
    Class in package java.awt.image II-260 
    DirectColorModel(int, int, int, int) in class DirectColorModel II-261 
    DirectColorModel(int, int, int, int, int) in class DirectColorModel II-261 
disable
--------------------------------------
    static void disable() in class Compiler I-26 
    void disable() in class Component II-44 
    void disable() in class MenuItem II-195 
    void disable() in interface ComponentPeer II-325 
    void disable() in interface MenuItemPeer II-341 
dispose
--------------------------------------
    void dispose() in class Frame II-117 
    void dispose() in class Graphics II-124 
    void dispose() in class Window II-241 
    void dispose() in interface ComponentPeer II-325 
    void dispose() in interface MenuComponentPeer II-340 
doInput
--------------------------------------
    boolean doInput in class URLConnection I-446 
doOutput
--------------------------------------
    boolean doOutput in class URLConnection I-446 
Double
--------------------------------------
    Class in package java.lang I-27 
    Double(double) in class Double I-28 
    Double(String) in class Double I-29 
doubleToLongBits
--------------------------------------
    static long doubleToLongBits(double) in class Double I-29 
doubleValue
--------------------------------------
    double doubleValue() in class Double I-29 
    double doubleValue() in class Float I-36 
    double doubleValue() in class Integer I-42 
    double doubleValue() in class Long I-51 
    double doubleValue() in class Number I-69 
DOWN
--------------------------------------
    static int DOWN in class Event II-87 
draw3DRect
--------------------------------------
    void draw3DRect(int, int, int, int, boolean) in class Graphics II-124 
drawArc
--------------------------------------
    void drawArc(int, int, int, int, int, int) in class Graphics II-125 
drawBytes
--------------------------------------
    void drawBytes(byte[], int, int, int, int) in class Graphics II-125 
drawChars
--------------------------------------
    void drawChars(char[], int, int, int, int) in class Graphics II-126 
drawImage
--------------------------------------
    boolean drawImage(Image, int, int, Color, ImageObserver) in class Graphics II-126 
    boolean drawImage(Image, int, int, ImageObserver) in class Graphics II-127 
    boolean drawImage(Image, int, int, int, int, Color, ImageObserver) in class Graphics II-128 
    boolean drawImage(Image, int, int, int, int, ImageObserver) in class Graphics II-129 
drawLine
--------------------------------------
    void drawLine(int, int, int, int) in class Graphics II-129 
drawOval
--------------------------------------
    void drawOval(int, int, int, int) in class Graphics II-130 
drawPolygon
--------------------------------------
    void drawPolygon(int[], int[], int) in class Graphics II-130 
    void drawPolygon(Polygon) in class Graphics II-130 
drawRect
--------------------------------------
    void drawRect(int, int, int, int) in class Graphics II-131 
drawRoundRect
--------------------------------------
    void drawRoundRect(int, int, int, int, int, int) in class Graphics II-131 
drawString
--------------------------------------
    void drawString(String, int, int) in class Graphics II-132 
dumpStack
--------------------------------------
    static void dumpStack() in class Thread I-143 

E
--------------------------------------

E
--------------------------------------
    static double E in class Math I-60 
E_RESIZE_CURSOR
--------------------------------------
    static int E_RESIZE_CURSOR in class Frame II-115 
EAST
--------------------------------------
    static int EAST in class GridBagConstraints II-143 
echoCharIsSet
--------------------------------------
    boolean echoCharIsSet() in class TextField II-227 
elementAt
--------------------------------------
    Object elementAt(int) in class Vector I-395 
elementCount
--------------------------------------
    int elementCount in class Vector I-393 
elementData
--------------------------------------
    Object elementData[] in class Vector I-393 
elements
--------------------------------------
    Enumeration elements() in class Dictionary I-369 
    Enumeration elements() in class Hashtable I-374 
    Enumeration elements() in class Vector I-395 
empty
--------------------------------------
    boolean empty() in class Stack I-386 
EmptyStackException
--------------------------------------
    Class in package java.util I-406 
    EmptyStackException() in class EmptyStackException I-406 
enable
--------------------------------------
    static void enable() in class Compiler I-26 
    void enable() in class Component II-44 
    void enable() in class MenuItem II-195 
    void enable() in interface ComponentPeer II-325 
    void enable() in interface MenuItemPeer II-341 
    void enable(boolean) in class Component II-44 
    void enable(boolean) in class MenuItem II-195 
encode
--------------------------------------
    static String encode(String) in class URLEncoder I-457 
END
--------------------------------------
    static int END in class Event II-87 
endsWith
--------------------------------------
    boolean endsWith(String) in class String I-103 
ensureCapacity
--------------------------------------
    void ensureCapacity(int) in class StringBuffer I-121 
    void ensureCapacity(int) in class Vector I-395 
enumerate
--------------------------------------
    int enumerate(Thread[]) in class ThreadGroup I-152 
    int enumerate(Thread[], boolean) in class ThreadGroup I-153 
    int enumerate(ThreadGroup[]) in class ThreadGroup I-153 
    int enumerate(ThreadGroup[], boolean) in class ThreadGroup I-153 
    static int enumerate(Thread[]) in class Thread I-143 
Enumeration
--------------------------------------
    Interface in package java.util I-402 
EOFException
--------------------------------------
    Class in package java.io I-334 
    EOFException() in class EOFException I-348 
    EOFException(String) in class EOFException I-348 
eolIsSignificant
--------------------------------------
    void eolIsSignificant(boolean) in class StreamTokenizer I-325 
equals
--------------------------------------
    boolean equals(Object) in class BitSet I-357 
    boolean equals(Object) in class Boolean I-5 
    boolean equals(Object) in class Character I-9 
    boolean equals(Object) in class Color II-34 
    boolean equals(Object) in class Date I-364 
    boolean equals(Object) in class Double I-30 
    boolean equals(Object) in class File I-247 
    boolean equals(Object) in class Float I-36 
    boolean equals(Object) in class Font II-104 
    boolean equals(Object) in class InetAddress I-418 
    boolean equals(Object) in class Integer I-43 
    boolean equals(Object) in class Long I-52 
    boolean equals(Object) in class Object I-71 
    boolean equals(Object) in class Point II-199 
    boolean equals(Object) in class Rectangle II-206 
    boolean equals(Object) in class String I-103 
    boolean equals(Object) in class URL I-439 
equalsIgnoreCase
--------------------------------------
    boolean equalsIgnoreCase(String) in class String I-103 
err
--------------------------------------
    static FileDescriptor err in class FileDescriptor I-252 
    static PrintStream err in class System I-130 
ERROR
--------------------------------------
    static int ERROR in interface ImageObserver II-309 
Error
--------------------------------------
    Class in package java.lang I-191 
    Error() in class Error I-191 
    Error(String) in class Error I-191 
ERRORED
--------------------------------------
    static int ERRORED in class MediaTracker II-177 
Event
--------------------------------------
    Class in package java.awt II-82 
    Event(Object, int, Object) in class Event II-90 
    Event(Object, long, int, int, int, int, int) in class Event II-90 
    Event(Object, long, int, int, int, int, int, Object) in class Event II-90 
evt
--------------------------------------
    Event evt in class Event II-84 
Exception
--------------------------------------
    Class in package java.lang I-172 
    Exception() in class Exception I-172 
    Exception(String) in class Exception I-172 
exec
--------------------------------------
    Process exec(String) in class Runtime I-79 
    Process exec(String, String[]) in class Runtime I-79 
    Process exec(String[]) in class Runtime I-80 
    Process exec(String[], String[]) in class Runtime I-80 
exists
--------------------------------------
    boolean exists() in class File I-247 
exit
--------------------------------------
    static void exit(int) in class System I-132 
    void exit(int) in class Runtime I-81 
exitValue
--------------------------------------
    int exitValue() in class Process I-76 
exp
--------------------------------------
    static double exp(double) in class Math I-63 

F
--------------------------------------


F1
--------------------------------------
    static int F1 in class Event II-87 
F10
--------------------------------------
    static int F10 in class Event II-88 
F11
--------------------------------------
    static int F11 in class Event II-88 
F12
--------------------------------------
    static int F12 in class Event II-88 
F2
--------------------------------------
    static int F2 in class Event II-88 
F3
--------------------------------------
    static int F3 in class Event II-88 
F4
--------------------------------------
    static int F4 in class Event II-88 
F5
--------------------------------------
    static int F5 in class Event II-88 
F6
--------------------------------------
    static int F6 in class Event II-88 
F7
--------------------------------------
    static int F7 in class Event II-88 
F8
--------------------------------------
    static int F8 in class Event II-88 
F9
--------------------------------------
    static int F9 in class Event II-88 
FALSE
--------------------------------------
    static Boolean FALSE in class Boolean I-4 
fd
--------------------------------------
    FileDescriptor fd in class SocketImpl I-431 
File
--------------------------------------
    Class in package java.io I-243 
    File(File, String) in class File I-245 
    File(String) in class File I-245 
    File(String, String) in class File I-245 
FileDescriptor
--------------------------------------
    Class in package java.io I-252 
    FileDescriptor() in class FileDescriptor I-252 
FileDialog
--------------------------------------
    Class in package java.awt II-93 
    FileDialog(Frame, String) in class FileDialog II-94 
    FileDialog(Frame, String, int) in class FileDialog II-94 
FileDialogPeer
--------------------------------------
    Interface in package java.awt.peer II-332 
FileInputStream
--------------------------------------
    Class in package java.io I-254 
    FileInputStream(File) in class FileInputStream I-254 
    FileInputStream(FileDescriptor) in class FileInputStream I-255 
    FileInputStream(String) in class FileInputStream I-255 
FilenameFilter
--------------------------------------
    Interface in package java.io I-345 
FileNotFoundException
--------------------------------------
    Class in package java.io I-349 
    FileNotFoundException() in class FileNotFoundException I-349 
    FileNotFoundException(String) in class FileNotFoundException I-349 
FileOutputStream
--------------------------------------
    Class in package java.io I-259 
    FileOutputStream(File) in class FileOutputStream I-259 
    FileOutputStream(FileDescriptor) in class FileOutputStream I-260 
    FileOutputStream(String) in class FileOutputStream I-260 
fill
--------------------------------------
    int fill in class GridBagConstraints II-140 
fill3DRect
--------------------------------------
    void fill3DRect(int, int, int, int, boolean) in class Graphics II-132 
fillArc
--------------------------------------
    void fillArc(int, int, int, int, int, int) in class Graphics II-133 
fillInStackTrace
--------------------------------------
    Throwable fillInStackTrace() in class Throwable I-159 
fillOval
--------------------------------------
    void fillOval(int, int, int, int) in class Graphics II-133 
fillPolygon
--------------------------------------
    void fillPolygon(int[], int[], int) in class Graphics II-134 
    void fillPolygon(Polygon) in class Graphics II-134 
fillRect
--------------------------------------
    void fillRect(int, int, int, int) in class Graphics II-135 
fillRoundRect
--------------------------------------
    void fillRoundRect(int, int, int, int, int, int) in class Graphics II-135 
FilteredImageSource
--------------------------------------
    Class in package java.awt.image II-265 
    FilteredImageSource(ImageProducer, ImageFilter) in class FilteredImageSource II-265 
filterIndexColorModel
--------------------------------------
    IndexColorModel filterIndexColorModel(IndexColorModel) in class RGBImageFilter II-296 
FilterInputStream
--------------------------------------
    Class in package java.io I-263 
    FilterInputStream(InputStream) in class FilterInputStream I-264 
FilterOutputStream
--------------------------------------
    Class in package java.io I-269 
    FilterOutputStream(OutputStream) in class FilterOutputStream I-269 
filterRGB
--------------------------------------
    int filterRGB(int, int, int) in class RGBImageFilter II-296 
filterRGBPixels
--------------------------------------
    void filterRGBPixels(int, int, int, int, int[], int, int) in class RGBImageFilter II-297 
finalize
--------------------------------------
    void finalize() in class DatagramSocket I-416 
    void finalize() in class FileInputStream I-256 
    void finalize() in class FileOutputStream I-261 
    void finalize() in class Graphics II-135 
    void finalize() in class Object I-72 
findSystemClass
--------------------------------------
    Class findSystemClass(String) in class ClassLoader I-23 
first
--------------------------------------
    void first(Container) in class CardLayout II-15 
firstElement
--------------------------------------
    Object firstElement() in class Vector I-395 
Float
--------------------------------------
    Class in package java.lang I-34 
    Float(double) in class Float I-35 
    Float(float) in class Float I-35 
    Float(String) in class Float I-36 
floatToIntBits
--------------------------------------
    static int floatToIntBits(float) in class Float I-37 
floatValue
--------------------------------------
    float floatValue() in class Double I-30 
    float floatValue() in class Float I-37 
    float floatValue() in class Integer I-43 
    float floatValue() in class Long I-52 
    float floatValue() in class Number I-69 
floor
--------------------------------------
    static double floor(double) in class Math I-63 
FlowLayout
--------------------------------------
    Class in package java.awt II-97 
    FlowLayout() in class FlowLayout II-98 
    FlowLayout(int) in class FlowLayout II-99 
    FlowLayout(int, int, int) in class FlowLayout II-99 
flush
--------------------------------------
    void flush() in class BufferedOutputStream I-217 
    void flush() in class DataOutputStream I-238 
    void flush() in class FilterOutputStream I-270 
    void flush() in class Image II-157 
    void flush() in class OutputStream I-283 
    void flush() in class PrintStream I-293 
Font
--------------------------------------
    Class in package java.awt II-102 
    Font(String, int, int) in class Font II-103 
font
--------------------------------------
    Font font in class FontMetrics II-109 
FontMetrics
--------------------------------------
    Class in package java.awt II-108 
    FontMetrics(Font) in class FontMetrics II-109 
forDigit
--------------------------------------
    static char forDigit(int, int) in class Character I-10 
forName
--------------------------------------
    static Class forName(String) in class Class I-18 
Frame
--------------------------------------
    Class in package java.awt II-114 
    Frame() in class Frame II-116 
    Frame(String) in class Frame II-116 
FRAMEBITS
--------------------------------------
    static int FRAMEBITS in interface ImageObserver II-309 
FramePeer
--------------------------------------
    Interface in package java.awt.peer II-333 
freeMemory
--------------------------------------
    long freeMemory() in class Runtime I-81 

G
--------------------------------------


gc
--------------------------------------
    static void gc() in class System I-133 
    void gc() in class Runtime I-81 
get
--------------------------------------
    boolean get(int) in class BitSet I-358 
    Object get(Object) in class Dictionary I-370 
    Object get(Object) in class Hashtable I-375 
getAbsolutePath
--------------------------------------
    String getAbsolutePath() in class File I-247 
getAddress
--------------------------------------
    byte getAddress()[] in class InetAddress I-419 
    InetAddress getAddress() in class DatagramPacket I-414 
getAlignment
--------------------------------------
    int getAlignment() in class Label II-163 
getAllByName
--------------------------------------
    static InetAddress getAllByName(String)[] in class InetAddress I-419 
getAllowUserInteraction
--------------------------------------
    boolean getAllowUserInteraction() in class URLConnection I-448 
getAlpha
--------------------------------------
    int getAlpha(int) in class ColorModel II-255 
    int getAlpha(int) in class DirectColorModel II-262 
    int getAlpha(int) in class IndexColorModel II-277 
getAlphaMask
--------------------------------------
    int getAlphaMask() in class DirectColorModel II-262 
getAlphas
--------------------------------------
    void getAlphas(byte[]) in class IndexColorModel II-277 
getApplet
--------------------------------------
    Applet getApplet(String) in interface AppletContext 364 
getAppletContext
--------------------------------------
    AppletContext getAppletContext() in class Applet 357 
    AppletContext getAppletContext() in interface AppletStub 367 
getAppletInfo
--------------------------------------
    String getAppletInfo() in class Applet 357 
getApplets
--------------------------------------
    Enumeration getApplets() in interface AppletContext 364 
getAscent
--------------------------------------
    int getAscent() in class FontMetrics II-111 
getAudioClip
--------------------------------------
    AudioClip getAudioClip(URL) in class Applet 358 
    AudioClip getAudioClip(URL) in interface AppletContext 365 
    AudioClip getAudioClip(URL, String) in class Applet 358 
getBackground
--------------------------------------
    Color getBackground() in class Component II-44 
getBlue
--------------------------------------
    int getBlue() in class Color II-34 
    int getBlue(int) in class ColorModel II-255 
    int getBlue(int) in class DirectColorModel II-262 
    int getBlue(int) in class IndexColorModel II-277 
getBlueMask
--------------------------------------
    int getBlueMask() in class DirectColorModel II-262 
getBlues
--------------------------------------
    void getBlues(byte[]) in class IndexColorModel II-278 
getBoolean
--------------------------------------
    static boolean getBoolean(String) in class Boolean I-6 
getBoundingBox
--------------------------------------
    Rectangle getBoundingBox() in class Polygon II-202 
getByName
--------------------------------------
    static InetAddress getByName(String) in class InetAddress I-419 
getBytes
--------------------------------------
    void getBytes(int, int, byte[], int) in class String I-104 
getChars
--------------------------------------
    void getChars(int, int, char[], int) in class String I-104 
    void getChars(int, int, char[], int) in class StringBuffer I-122 
getCheckboxGroup
--------------------------------------
    CheckboxGroup getCheckboxGroup() in class Checkbox II-21 
getClass
--------------------------------------
    Class getClass() in class Object I-72 
getClassContext
--------------------------------------
    Class getClassContext()[] in class SecurityManager I-96 
getClassLoader
--------------------------------------
    ClassLoader getClassLoader() in class Class I-19 
getClipRect
--------------------------------------
    Rectangle getClipRect() in class Graphics II-136 
getCodeBase
--------------------------------------
    URL getCodeBase() in class Applet 358 
    URL getCodeBase() in interface AppletStub 367 
getColor
--------------------------------------
    Color getColor() in class Graphics II-136 
    static Color getColor(String) in class Color II-35 
    static Color getColor(String, Color) in class Color II-35 
    static Color getColor(String, int) in class Color II-36 
getColorModel
--------------------------------------
    ColorModel getColorModel() in class Component II-45 
    ColorModel getColorModel() in class Toolkit II-237 
    ColorModel getColorModel() in interface ComponentPeer II-325 
getColumns
--------------------------------------
    int getColumns() in class TextArea II-219 
    int getColumns() in class TextField II-227 
getComponent
--------------------------------------
    Component getComponent(int) in class Container II-71 
getComponents
--------------------------------------
    Component getComponents()[] in class Container II-71 
getConstraints
--------------------------------------
    GridBagConstraints getConstraints(Component) in class GridBagLayout II-148 
getContent
--------------------------------------
    Object getContent() in class URL I-439 
    Object getContent() in class URLConnection I-448 
    Object getContent(URLConnection) in class ContentHandler I-412 
getContentEncoding
--------------------------------------
    String getContentEncoding() in class URLConnection I-449 
getContentLength
--------------------------------------
    int getContentLength() in class URLConnection I-449 
getContentType
--------------------------------------
    String getContentType() in class URLConnection I-449 
getCurrent
--------------------------------------
    Checkbox getCurrent() in class CheckboxGroup II-24 
getCursorType
--------------------------------------
    int getCursorType() in class Frame II-117 
getData
--------------------------------------
    byte getData()[] in class DatagramPacket I-414 
getDate
--------------------------------------
    int getDate() in class Date I-364 
    long getDate() in class URLConnection I-449 
getDay
--------------------------------------
    int getDay() in class Date I-364 
getDefaultAllowUserInteraction
--------------------------------------
    static boolean getDefaultAllowUserInteraction() in class URLConnection I-450 
getDefaultRequestProperty
--------------------------------------
    static String getDefaultRequestProperty(String) in class URLConnection I-450 
getDefaultToolkit
--------------------------------------
    static Toolkit getDefaultToolkit() in class Toolkit II-237 
getDefaultUseCaches
--------------------------------------
    boolean getDefaultUseCaches() in class URLConnection I-450 
getDescent
--------------------------------------
    int getDescent() in class FontMetrics II-111 
getDirectory
--------------------------------------
    String getDirectory() in class FileDialog II-94 
getDocumentBase
--------------------------------------
    URL getDocumentBase() in class Applet 358 
    URL getDocumentBase() in interface AppletStub 367 
getDoInput
--------------------------------------
    boolean getDoInput() in class URLConnection I-450 
getDoOutput
--------------------------------------
    boolean getDoOutput() in class URLConnection I-450 
getEchoChar
--------------------------------------
    char getEchoChar() in class TextField II-228 
getErrorsAny
--------------------------------------
    Object getErrorsAny()[] in class MediaTracker II-180 
getErrorsID
--------------------------------------
    Object getErrorsID(int)[] in class MediaTracker II-180 
getErrorStream
--------------------------------------
    InputStream getErrorStream() in class Process I-77 
getExpiration
--------------------------------------
    long getExpiration() in class URLConnection I-450 
getFamily
--------------------------------------
    String getFamily() in class Font II-104 
getFD
--------------------------------------
    FileDescriptor getFD() in class FileInputStream I-256 
    FileDescriptor getFD() in class FileOutputStream I-261 
    FileDescriptor getFD() in class RandomAccessFile I-305 
getFile
--------------------------------------
    String getFile() in class FileDialog II-95 
    String getFile() in class URL I-439 
getFileDescriptor
--------------------------------------
    FileDescriptor getFileDescriptor() in class SocketImpl I-433 
getFilenameFilter
--------------------------------------
    FilenameFilter getFilenameFilter() in class FileDialog II-95 
getFilePointer
--------------------------------------
    long getFilePointer() in class RandomAccessFile I-306 
getFilterInstance
--------------------------------------
    ImageFilter getFilterInstance(ImageConsumer) in class ImageFilter II-269 
getFont
--------------------------------------
    Font getFont() in class Component II-45 
    Font getFont() in class FontMetrics II-111 
    Font getFont() in class Graphics II-136 
    Font getFont() in class MenuComponent II-191 
    Font getFont() in interface MenuContainer II-246 
    static Font getFont(String) in class Font II-104 
    static Font getFont(String, Font) in class Font II-105 
getFontList
--------------------------------------
    String getFontList()[] in class Toolkit II-238 
getFontMetrics
--------------------------------------
    FontMetrics getFontMetrics() in class Graphics II-136 
    FontMetrics getFontMetrics(Font) in class Component II-45 
    FontMetrics getFontMetrics(Font) in class Graphics II-136 
    FontMetrics getFontMetrics(Font) in class Toolkit II-238 
    FontMetrics getFontMetrics(Font) in interface ComponentPeer II-325 
getForeground
--------------------------------------
    Color getForeground() in class Component II-46 
getGraphics
--------------------------------------
    Graphics getGraphics() in class Component II-46 
    Graphics getGraphics() in class Image II-157 
    Graphics getGraphics() in interface ComponentPeer II-325 
getGreen
--------------------------------------
    int getGreen() in class Color II-36 
    int getGreen(int) in class ColorModel II-255 
    int getGreen(int) in class DirectColorModel II-263 
    int getGreen(int) in class IndexColorModel II-278 
getGreenMask
--------------------------------------
    int getGreenMask() in class DirectColorModel II-263 
getGreens
--------------------------------------
    void getGreens(byte[]) in class IndexColorModel II-278 
getHeaderField
--------------------------------------
    String getHeaderField(int) in class URLConnection I-451 
    String getHeaderField(String) in class URLConnection I-451 
getHeaderFieldDate
--------------------------------------
    long getHeaderFieldDate(String, long) in class URLConnection I-451 
getHeaderFieldInt
--------------------------------------
    int getHeaderFieldInt(String, int) in class URLConnection I-452 
getHeaderFieldKey
--------------------------------------
    String getHeaderFieldKey(int) in class URLConnection I-452 
getHeight
--------------------------------------
    int getHeight() in class FontMetrics II-111 
    int getHeight(ImageObserver) in class Image II-157 
getHelpMenu
--------------------------------------
    Menu getHelpMenu() in class MenuBar II-189 
getHost
--------------------------------------
    String getHost() in class URL I-440 
getHostName
--------------------------------------
    String getHostName() in class InetAddress I-419 
getHours
--------------------------------------
    int getHours() in class Date I-364 
getHSBColor
--------------------------------------
    static Color getHSBColor(float, float, float) in class Color II-36 
getIconImage
--------------------------------------
    Image getIconImage() in class Frame II-117 
getIfModifiedSince
--------------------------------------
    long getIfModifiedSince() in class URLConnection I-452 
getImage
--------------------------------------
    Image getImage(String) in class Toolkit II-238 
    Image getImage(URL) in class Applet 359 
    Image getImage(URL) in class Toolkit II-238 
    Image getImage(URL) in interface AppletContext 365 
    Image getImage(URL, String) in class Applet 359 
getInCheck
--------------------------------------
    boolean getInCheck() in class SecurityManager I-96 
getInetAddress
--------------------------------------
    InetAddress getInetAddress() in class ServerSocket I-423 
    InetAddress getInetAddress() in class Socket I-428 
    InetAddress getInetAddress() in class SocketImpl I-433 
getInputStream
--------------------------------------
    InputStream getInputStream() in class Process I-77 
    InputStream getInputStream() in class Socket I-428 
    InputStream getInputStream() in class SocketImpl I-433 
    InputStream getInputStream() in class URLConnection I-452 
getInteger
--------------------------------------
    static Integer getInteger(String) in class Integer I-43 
    static Integer getInteger(String, int) in class Integer I-44 
    static Integer getInteger(String, Integer) in class Integer I-44 
getInterfaces
--------------------------------------
    Class getInterfaces()[] in class Class I-19 
getItem
--------------------------------------
    MenuItem getItem(int) in class Menu II-187 
    String getItem(int) in class Choice II-29 
    String getItem(int) in class List II-168 
getLabel
--------------------------------------
    String getLabel() in class Button II-10 
    String getLabel() in class Checkbox II-21 
    String getLabel() in class MenuItem II-195 
getLastModified
--------------------------------------
    long getLastModified() in class URLConnection I-453 
getLayout
--------------------------------------
    LayoutManager getLayout() in class Container II-71 
getLeading
--------------------------------------
    int getLeading() in class FontMetrics II-112 
getLength
--------------------------------------
    int getLength() in class DatagramPacket I-414 
getLineIncrement
--------------------------------------
    int getLineIncrement() in class Scrollbar II-213 
getLineNumber
--------------------------------------
    int getLineNumber() in class LineNumberInputStream I-279 
getLocalHost
--------------------------------------
    static InetAddress getLocalHost() in class InetAddress I-420 
getLocalizedInputStream
--------------------------------------
    InputStream getLocalizedInputStream(InputStream) in class Runtime I-82 
getLocalizedOutputStream
--------------------------------------
    OutputStream getLocalizedOutputStream(OutputStream) in class Runtime I-82 
getLocalPort
--------------------------------------
    int getLocalPort() in class DatagramSocket I-416 
    int getLocalPort() in class ServerSocket I-423 
    int getLocalPort() in class Socket I-428 
    int getLocalPort() in class SocketImpl I-433 
getLong
--------------------------------------
    static Long getLong(String) in class Long I-52 
    static Long getLong(String, Long) in class Long I-53 
    static Long getLong(String, long) in class Long I-53 
getMapSize
--------------------------------------
    int getMapSize() in class IndexColorModel II-278 
getMaxAdvance
--------------------------------------
    int getMaxAdvance() in class FontMetrics II-112 
getMaxAscent
--------------------------------------
    int getMaxAscent() in class FontMetrics II-112 
getMaxDescent
--------------------------------------
    int getMaxDescent() in class FontMetrics II-112 
getMaximum
--------------------------------------
    int getMaximum() in class Scrollbar II-214 
getMaxPriority
--------------------------------------
    int getMaxPriority() in class ThreadGroup I-154 
getMenu
--------------------------------------
    Menu getMenu(int) in class MenuBar II-189 
getMenuBar
--------------------------------------
    MenuBar getMenuBar() in class Frame II-117 
getMessage
--------------------------------------
    String getMessage() in class Throwable I-159 
getMinimum
--------------------------------------
    int getMinimum() in class Scrollbar II-214 
getMinutes
--------------------------------------
    int getMinutes() in class Date I-365 
getMode
--------------------------------------
    int getMode() in class FileDialog II-95 
getMonth
--------------------------------------
    int getMonth() in class Date I-365 
getName
--------------------------------------
    String getName() in class Class I-19 
    String getName() in class File I-247 
    String getName() in class Font II-105 
    String getName() in class Thread I-143 
    String getName() in class ThreadGroup I-154 
getOrientation
--------------------------------------
    int getOrientation() in class Scrollbar II-214 
getOutputStream
--------------------------------------
    OutputStream getOutputStream() in class Process I-77 
    OutputStream getOutputStream() in class Socket I-428 
    OutputStream getOutputStream() in class SocketImpl I-433 
    OutputStream getOutputStream() in class URLConnection I-453 
getPageIncrement
--------------------------------------
    int getPageIncrement() in class Scrollbar II-214 
getParameter
--------------------------------------
    String getParameter(String) in class Applet 359 
    String getParameter(String) in interface AppletStub 368 
getParameterInfo
--------------------------------------
    String getParameterInfo()[][] in class Applet 360 
getParent
--------------------------------------
    Container getParent() in class Component II-46 
    MenuContainer getParent() in class MenuComponent II-191 
    String getParent() in class File I-248 
    ThreadGroup getParent() in class ThreadGroup I-154 
getPath
--------------------------------------
    String getPath() in class File I-248 
getPeer
--------------------------------------
    ComponentPeer getPeer() in class Component II-46 
    MenuComponentPeer getPeer() in class MenuComponent II-192 
getPixelSize
--------------------------------------
    int getPixelSize() in class ColorModel II-255 
getPort
--------------------------------------
    int getPort() in class DatagramPacket I-414 
    int getPort() in class Socket I-428 
    int getPort() in class SocketImpl I-434 
    int getPort() in class URL I-440 
getPriority
--------------------------------------
    int getPriority() in class Thread I-143 
getProperties
--------------------------------------
    static Properties getProperties() in class System I-133 
getProperty
--------------------------------------
    Object getProperty(String, ImageObserver) in class Image II-158 
    static String getProperty(String) in class System I-134 
    static String getProperty(String, String) in class System I-134 
    String getProperty(String) in class Properties I-382 
    String getProperty(String, String) in class Properties I-382 
getProtocol
--------------------------------------
    String getProtocol() in class URL I-440 
getRed
--------------------------------------
    int getRed() in class Color II-37 
    int getRed(int) in class ColorModel II-256 
    int getRed(int) in class DirectColorModel II-263 
    int getRed(int) in class IndexColorModel II-279 
getRedMask
--------------------------------------
    int getRedMask() in class DirectColorModel II-263 
getReds
--------------------------------------
    void getReds(byte[]) in class IndexColorModel II-279 
getRef
--------------------------------------
    String getRef() in class URL I-440 
getRequestProperty
--------------------------------------
    String getRequestProperty(String) in class URLConnection I-453 
getRGB
--------------------------------------
    int getRGB() in class Color II-37 
    int getRGB(int) in class ColorModel II-256 
    int getRGB(int) in class DirectColorModel II-264 
    int getRGB(int) in class IndexColorModel II-279 
getRGBdefault
--------------------------------------
    static ColorModel getRGBdefault() in class ColorModel II-256 
getRows
--------------------------------------
    int getRows() in class List II-169 
    int getRows() in class TextArea II-219 
getRuntime
--------------------------------------
    static Runtime getRuntime() in class Runtime I-82 
getScreenResolution
--------------------------------------
    int getScreenResolution() in class Toolkit II-238 
getScreenSize
--------------------------------------
    Dimension getScreenSize() in class Toolkit II-238 
getSeconds
--------------------------------------
    int getSeconds() in class Date I-365 
getSecurityContext
--------------------------------------
    Object getSecurityContext() in class SecurityManager I-96 
getSecurityManager
--------------------------------------
    static SecurityManager getSecurityManager() in class System I-135 
getSelectedIndex
--------------------------------------
    int getSelectedIndex() in class Choice II-29 
    int getSelectedIndex() in class List II-169 
getSelectedIndexes
--------------------------------------
    int getSelectedIndexes()[] in class List II-169 
    int getSelectedIndexes()[] in interface ListPeer II-337 
getSelectedItem
--------------------------------------
    String getSelectedItem() in class Choice II-29 
    String getSelectedItem() in class List II-169 
getSelectedItems
--------------------------------------
    String getSelectedItems()[] in class List II-169 
getSelectedText
--------------------------------------
    String getSelectedText() in class TextComponent II-222 
getSelectionEnd
--------------------------------------
    int getSelectionEnd() in class TextComponent II-222 
    int getSelectionEnd() in interface TextComponentPeer II-348 
getSelectionStart
--------------------------------------
    int getSelectionStart() in class TextComponent II-222 
    int getSelectionStart() in interface TextComponentPeer II-348 
getSize
--------------------------------------
    int getSize() in class Font II-105 
getSource
--------------------------------------
    ImageProducer getSource() in class Image II-158 
getState
--------------------------------------
    boolean getState() in class Checkbox II-21 
    boolean getState() in class CheckboxMenuItem II-26 
getStyle
--------------------------------------
    int getStyle() in class Font II-106 
getSuperclass
--------------------------------------
    Class getSuperclass() in class Class I-19 
getText
--------------------------------------
    String getText() in class Label II-163 
    String getText() in class TextComponent II-223 
    String getText() in interface TextComponentPeer II-348 
getThreadGroup
--------------------------------------
    ThreadGroup getThreadGroup() in class Thread I-143 
getTime
--------------------------------------
    long getTime() in class Date I-365 
getTimezoneOffset
--------------------------------------
    int getTimezoneOffset() in class Date I-365 
getTitle
--------------------------------------
    String getTitle() in class Dialog II-78 
    String getTitle() in class Frame II-117 
getToolkit
--------------------------------------
    Toolkit getToolkit() in class Component II-46 
    Toolkit getToolkit() in class Window II-241 
    Toolkit getToolkit() in interface ComponentPeer II-326 
getTransparentPixel
--------------------------------------
    int getTransparentPixel() in class IndexColorModel II-280 
getURL
--------------------------------------
    URL getURL() in class URLConnection I-453 
getUseCaches
--------------------------------------
    boolean getUseCaches() in class URLConnection I-453 
getValue
--------------------------------------
    int getValue() in class Scrollbar II-214 
getVisible
--------------------------------------
    int getVisible() in class Scrollbar II-215 
getVisibleIndex
--------------------------------------
    int getVisibleIndex() in class List II-170 
getWarningString
--------------------------------------
    String getWarningString() in class Window II-241 
getWidth
--------------------------------------
    int getWidth(ImageObserver) in class Image II-158 
getWidths
--------------------------------------
    int getWidths()[] in class FontMetrics II-112 
getYear
--------------------------------------
    int getYear() in class Date I-365 
GOT_FOCUS
--------------------------------------
    static int GOT_FOCUS in class Event II-85 
gotFocus
--------------------------------------
    boolean gotFocus(Event, Object) in class Component II-47 
grabPixels
--------------------------------------
    boolean grabPixels() in class PixelGrabber II-290 
    boolean grabPixels(long) in class PixelGrabber II-291 
Graphics
--------------------------------------
    Class in package java.awt II-120 
    Graphics() in class Graphics II-122 
gray
--------------------------------------
    static Color gray in class Color II-32 
green
--------------------------------------
    static Color green in class Color II-32 
GridBagConstraints
--------------------------------------
    Class in package java.awt II-139 
    GridBagConstraints() in class GridBagConstraints II-144 
GridBagLayout
--------------------------------------
    Class in package java.awt II-145 
    GridBagLayout() in class GridBagLayout II-148 
gridheight
--------------------------------------
    int gridheight in class GridBagConstraints II-141 
GridLayout
--------------------------------------
    Class in package java.awt II-151 
    GridLayout(int, int) in class GridLayout II-152 
    GridLayout(int, int, int, int) in class GridLayout II-152 
gridwidth
--------------------------------------
    int gridwidth in class GridBagConstraints II-141 
gridx
--------------------------------------
    int gridx in class GridBagConstraints II-141 
gridy
--------------------------------------
    int gridy in class GridBagConstraints II-141 
grow
--------------------------------------
    void grow(int, int) in class Rectangle II-206 
guessContentTypeFromName
--------------------------------------
    static String guessContentTypeFromName(String) in class URLConnection I-454 
guessContentTypeFromStream
--------------------------------------
    static String guessContentTypeFromStream(InputStream) in class URLConnection I-454 

H
--------------------------------------


HAND_CURSOR
--------------------------------------
    static int HAND_CURSOR in class Frame II-115 
handleEvent
--------------------------------------
    boolean handleEvent(Event) in class Component II-47 
    boolean handleEvent(Event) in interface ComponentPeer II-326 
hasChanged
--------------------------------------
    boolean hasChanged() in class Observable I-379 
hashCode
--------------------------------------
    int hashCode() in class BitSet I-358 
    int hashCode() in class Boolean I-6 
    int hashCode() in class Character I-10 
    int hashCode() in class Color II-37 
    int hashCode() in class Date I-366 
    int hashCode() in class Double I-30 
    int hashCode() in class File I-248 
    int hashCode() in class Float I-37 
    int hashCode() in class Font II-106 
    int hashCode() in class InetAddress I-420 
    int hashCode() in class Integer I-45 
    int hashCode() in class Long I-54 
    int hashCode() in class Object I-72 
    int hashCode() in class Point II-199 
    int hashCode() in class Rectangle II-206 
    int hashCode() in class String I-105 
    int hashCode() in class URL I-440 
Hashtable
--------------------------------------
    Class in package java.util I-372 
    Hashtable() in class Hashtable I-373 
    Hashtable(int) in class Hashtable I-373 
    Hashtable(int, float) in class Hashtable I-373 
hasMoreElements
--------------------------------------
    boolean hasMoreElements() in class StringTokenizer I-390 
    boolean hasMoreElements() in interface Enumeration I-402 
hasMoreTokens
--------------------------------------
    boolean hasMoreTokens() in class StringTokenizer I-390 
HEIGHT
--------------------------------------
    static int HEIGHT in interface ImageObserver II-309 
height
--------------------------------------
    int height in class Dimension II-80 
    int height in class Rectangle II-203 
hide
--------------------------------------
    void hide() in class Component II-48 
    void hide() in interface ComponentPeer II-326 
HOME
--------------------------------------
    static int HOME in class Event II-89 
HORIZONTAL
--------------------------------------
    static int HORIZONTAL in class GridBagConstraints II-143 
    static int HORIZONTAL in class Scrollbar II-212 
HSBtoRGB
--------------------------------------
    static int HSBtoRGB(float, float, float) in class Color II-37 

I
--------------------------------------


id
--------------------------------------
    int id in class Event II-84 
IEEEremainder
--------------------------------------
    static double IEEEremainder(double, double) in class Math I-63 
ifModifiedSince
--------------------------------------
    long ifModifiedSince in class URLConnection I-447 
IllegalAccessError
--------------------------------------
    Class in package java.lang I-192 
    IllegalAccessError() in class IllegalAccessError I-192 
    IllegalAccessError(String) in class IllegalAccessError I-192 
IllegalAccessException
--------------------------------------
    Class in package java.lang I-173 
--------------------------------------
    IllegalAccessException() in class IllegalAccessException I-173 
    IllegalAccessException(String) in class IllegalAccessException I-173 
IllegalArgumentException
--------------------------------------
    Class in package java.lang I-174 
    IllegalArgumentException() in class IllegalArgumentException I-174 
    IllegalArgumentException(String) in class IllegalArgumentException I-174 
IllegalMonitorStateException
--------------------------------------
    Class in package java.lang I-175 
    IllegalMonitorStateException() in class IllegalMonitorStateException I-175 
    IllegalMonitorStateException(String) in class IllegalMonitorStateException I-175 
IllegalThreadStateException
--------------------------------------
    Class in package java.lang I-176 
    IllegalThreadStateException() in class IllegalThreadStateException I-176 
    IllegalThreadStateException(String) in class IllegalThreadStateException I-176 
Image
--------------------------------------
    Class in package java.awt II-156 
    Image() in class Image II-156 
IMAGEABORTED
--------------------------------------
    static int IMAGEABORTED in interface ImageConsumer II-302 
imageComplete
--------------------------------------
    void imageComplete(int) in class ImageFilter II-270 
    void imageComplete(int) in class PixelGrabber II-291 
    void imageComplete(int) in interface ImageConsumer II-304 
ImageConsumer
--------------------------------------
    Interface in package java.awt.image II-302 
IMAGEERROR
--------------------------------------
    static int IMAGEERROR in interface ImageConsumer II-303 
ImageFilter
--------------------------------------
    Class in package java.awt.image II-268 
    ImageFilter() in class ImageFilter II-269 
ImageObserver
--------------------------------------
    Interface in package java.awt.image II-308 
ImageProducer
--------------------------------------
    Interface in package java.awt.image II-312 
imageUpdate
--------------------------------------
    boolean imageUpdate(Image, int, int, int, int, int) in class Component II-48 
    boolean imageUpdate(Image, int, int, int, int, int) in interface ImageObserver II-310 
in
--------------------------------------
    InputStream in in class FilterInputStream I-263 
    static FileDescriptor in in class FileDescriptor I-252 
    static InputStream in in class System I-130 
inCheck
--------------------------------------
    boolean inCheck in class SecurityManager I-86 
inClass
--------------------------------------
    boolean inClass(String) in class SecurityManager I-96 
inClassLoader
--------------------------------------
    boolean inClassLoader() in class SecurityManager I-97 
IncompatibleClassChangeError
--------------------------------------
    Class in package java.lang I-193 
    IncompatibleClassChangeError() in class IncompatibleClassChangeError I-193 
    IncompatibleClassChangeError(String) in class IncompatibleClassChangeError I-193 
IndexColorModel
--------------------------------------
    Class in package java.awt.image II-273 
    IndexColorModel(int, int, byte[], byte[], byte[]) in class IndexColorModel II-274 
    IndexColorModel(int, int, byte[], byte[], byte[], byte[]) in class IndexColorModel II-275 
    IndexColorModel(int, int, byte[], byte[], byte[], int) in class IndexColorModel II-275 
    IndexColorModel(int, int, byte[], int, boolean) in class IndexColorModel II-276 
    IndexColorModel(int, int, byte[], int, boolean, int) in class IndexColorModel II-276 
indexOf
--------------------------------------
    int indexOf(int) in class String I-105 
    int indexOf(int, int) in class String I-105 
    int indexOf(Object) in class Vector I-396 
    int indexOf(Object, int) in class Vector I-396 
    int indexOf(String) in class String I-105 
    int indexOf(String, int) in class String I-106 
IndexOutOfBoundsException
--------------------------------------
    Class in package java.lang I-177 
    IndexOutOfBoundsException() in class IndexOutOfBoundsException I-177 
    IndexOutOfBoundsException(String) in class IndexOutOfBoundsException I-177 
InetAddress
--------------------------------------
    Class in package java.net I-418 
init
--------------------------------------
    void init() in class Applet 360 
InputStream
--------------------------------------
    Class in package java.io I-273 
    InputStream() in class InputStream I-273 
insert
--------------------------------------
    StringBuffer insert(int, boolean) in class StringBuffer I-122 
    StringBuffer insert(int, char) in class StringBuffer I-123 
    StringBuffer insert(int, char[]) in class StringBuffer I-123 
    StringBuffer insert(int, double) in class StringBuffer I-124 
    StringBuffer insert(int, float) in class StringBuffer I-124 
    StringBuffer insert(int, int) in class StringBuffer I-125 
    StringBuffer insert(int, long) in class StringBuffer I-125 
    StringBuffer insert(int, Object) in class StringBuffer I-126 
    StringBuffer insert(int, String) in class StringBuffer I-126 
insertElementAt
--------------------------------------
    void insertElementAt(Object, int) in class Vector I-396 
insertText
--------------------------------------
    void insertText(String, int) in class TextArea II-219 
    void insertText(String, int) in interface TextAreaPeer II-346 
Insets
--------------------------------------
    Class in package java.awt II-159 
    Insets(int, int, int, int) in class Insets II-160 
insets
--------------------------------------
    Insets insets in class GridBagConstraints II-141 
    Insets insets() in class Container II-71 
    Insets insets() in interface ContainerPeer II-330 
inside
--------------------------------------
    boolean inside(int, int) in class Component II-49 
    boolean inside(int, int) in class Polygon II-202 
    boolean inside(int, int) in class Rectangle II-207 
InstantiationError
--------------------------------------
    Class in package java.lang I-194 
    InstantiationError() in class InstantiationError I-194 
    InstantiationError(String) in class InstantiationError I-194 
InstantiationException
--------------------------------------
    Class in package java.lang I-178 
    InstantiationException() in class InstantiationException I-178 
    InstantiationException(String) in class InstantiationException I-178 
intBitsToFloat
--------------------------------------
    static float intBitsToFloat(int) in class Float I-38 
Integer
--------------------------------------
    Class in package java.lang I-41 
    Integer(int) in class Integer I-42 
    Integer(String) in class Integer I-42 
Interfaces
--------------------------------------
    java.applet.AppletContext 364 
    java.applet.AppletStub 367 
    java.applet.AudioClip 369 
    java.awt.image.ImageConsumer II-302 
    java.awt.image.ImageObserver II-308 
    java.awt.image.ImageProducer II-312 
    java.awt.LayoutManager II-244 
    java.awt.MenuContainer II-246 
    java.awt.peer.ButtonPeer II-318 
    java.awt.peer.CanvasPeer II-319 
    java.awt.peer.CheckboxMenuItemPeer II-320 
    java.awt.peer.CheckboxPeer II-321 
    java.awt.peer.ChoicePeer II-322 
    java.awt.peer.ComponentPeer II-323 
    java.awt.peer.ContainerPeer II-330 
    java.awt.peer.DialogPeer II-331 
    java.awt.peer.FileDialogPeer II-332 
    java.awt.peer.FramePeer II-333 
    java.awt.peer.LabelPeer II-335 
    java.awt.peer.ListPeer II-336 
    java.awt.peer.MenuBarPeer II-339 
    java.awt.peer.MenuComponentPeer II-340 
    java.awt.peer.MenuItemPeer II-341 
    java.awt.peer.MenuPeer II-342 
    java.awt.peer.PanelPeer II-343 
    java.awt.peer.ScrollbarPeer II-344 
    java.awt.peer.TextAreaPeer II-346 
    java.awt.peer.TextComponentPeer II-348 
    java.awt.peer.TextFieldPeer II-350 
    java.awt.peer.WindowPeer II-351 
    java.io.DataInput I-334 
    java.io.DataOutput I-340 
    java.io.FilenameFilter I-345 
    java.lang.Cloneable I-162 
    java.lang.Runnable I-163 
    java.net.ContentHandlerFactory I-462 
    java.net.SocketImplFactory I-463 
    java.net.URLStreamHandlerFactory I-464 
    java.util.Enumeration I-402 
    java.util.Observer I-403 
intern
--------------------------------------
    String intern() in class String I-106 
InternalError
--------------------------------------
    Class in package java.lang I-195 
    InternalError() in class InternalError I-195 
    InternalError(String) in class InternalError I-195 
interrupt
--------------------------------------
    void interrupt() in class Thread I-144 
interrupted
--------------------------------------
    static boolean interrupted() in class Thread I-144 
InterruptedException
--------------------------------------
    Class in package java.lang I-179 
    InterruptedException() in class InterruptedException I-179 
    InterruptedException(String) in class InterruptedException I-179 
InterruptedIOException
--------------------------------------
    Class in package java.io I-351 
    InterruptedIOException() in class InterruptedIOException I-351 
    InterruptedIOException(String) in class InterruptedIOException I-351 
intersection
--------------------------------------
    Rectangle intersection(Rectangle) in class Rectangle II-207 
intersects
--------------------------------------
    boolean intersects(Rectangle) in class Rectangle II-207 
intValue
--------------------------------------
    int intValue() in class Double I-31 
    int intValue() in class Float I-38 
    int intValue() in class Integer I-45 
    int intValue() in class Long I-54 
    int intValue() in class Number I-69 
invalidate
--------------------------------------
    void invalidate() in class Component II-49 
IOException
--------------------------------------
    Class in package java.io I-350 
    IOException() in class IOException I-350 
    IOException(String) in class IOException I-350 
ipadx
--------------------------------------
    int ipadx in class GridBagConstraints II-142 
ipady
--------------------------------------
    int ipady in class GridBagConstraints II-142 
isAbsolute
--------------------------------------
    boolean isAbsolute() in class File I-248 
isActive
--------------------------------------
    boolean isActive() in class Applet 360 
    boolean isActive() in interface AppletStub 368 
isAlive
--------------------------------------
    boolean isAlive() in class Thread I-144 
isBold
--------------------------------------
    boolean isBold() in class Font II-106 
isConsumer
--------------------------------------
    boolean isConsumer(ImageConsumer) in class FilteredImageSource II-266 
    boolean isConsumer(ImageConsumer) in class MemoryImageSource II-285 
    boolean isConsumer(ImageConsumer) in interface ImageProducer II-312 
isDaemon
--------------------------------------
    boolean isDaemon() in class Thread I-144 
    boolean isDaemon() in class ThreadGroup I-154 
isDefined
--------------------------------------
    static boolean isDefined(char) in class Character I-10 
isDigit
--------------------------------------
    static boolean isDigit(char) in class Character I-11 
isDirectory
--------------------------------------
    boolean isDirectory() in class File I-248 
isEditable
--------------------------------------
    boolean isEditable() in class TextComponent II-223 
isEmpty
--------------------------------------
    boolean isEmpty() in class Dictionary I-370 
    boolean isEmpty() in class Hashtable I-375 
    boolean isEmpty() in class Rectangle II-207 
    boolean isEmpty() in class Vector I-396 
isEnabled
--------------------------------------
    boolean isEnabled() in class Component II-50 
    boolean isEnabled() in class MenuItem II-195 
isErrorAny
--------------------------------------
    boolean isErrorAny() in class MediaTracker II-181 
isErrorID
--------------------------------------
    boolean isErrorID(int) in class MediaTracker II-181 
isFile
--------------------------------------
    boolean isFile() in class File I-249 
isInfinite
--------------------------------------
    boolean isInfinite() in class Double I-31 
    boolean isInfinite() in class Float I-38 
    static boolean isInfinite(double) in class Double I-31 
    static boolean isInfinite(float) in class Float I-38 
isInterface
--------------------------------------
    boolean isInterface() in class Class I-20 
isInterrupted
--------------------------------------
    boolean isInterrupted() in class Thread I-144 
isItalic
--------------------------------------
    boolean isItalic() in class Font II-106 
isJavaLetter
--------------------------------------
    static boolean isJavaLetter(char) in class Character I-11 
isJavaLetterOrDigit
--------------------------------------
    static boolean isJavaLetterOrDigit(char) in class Character I-12 
isLetter
--------------------------------------
    static boolean isLetter(char) in class Character I-12 
isLetterOrDigit
--------------------------------------
    static boolean isLetterOrDigit(char) in class Character I-12 
isLowerCase
--------------------------------------
    static boolean isLowerCase(char) in class Character I-11, I-13 
isModal
--------------------------------------
    boolean isModal() in class Dialog II-78 
isNaN
--------------------------------------
    boolean isNaN() in class Double I-31 
    boolean isNaN() in class Float I-39 
    static boolean isNaN(double) in class Double I-31 
    static boolean isNaN(float) in class Float I-39 
isPlain
--------------------------------------
    boolean isPlain() in class Font II-106 
isResizable
--------------------------------------
    boolean isResizable() in class Dialog II-78 
    boolean isResizable() in class Frame II-117 
isSelected
--------------------------------------
    boolean isSelected(int) in class List II-170 
isShowing
--------------------------------------
    boolean isShowing() in class Component II-50 
isSpace
--------------------------------------
    static boolean isSpace(char) in class Character I-14 
isTearOff
--------------------------------------
    boolean isTearOff() in class Menu II-187 
isTitleCase
--------------------------------------
    static boolean isTitleCase(char) in class Character I-14 
isUpperCase
--------------------------------------
    static boolean isUpperCase(char) in class Character I-15, I-16, I-17 
isValid
--------------------------------------
    boolean isValid() in class Component II-50 
isVisible
--------------------------------------
    boolean isVisible() in class Component II-50 
ITALIC
--------------------------------------
    static int ITALIC in class Font II-103 

J
--------------------------------------


join
--------------------------------------
    void join() in class Thread I-144 
    void join(long) in class Thread I-144 
    void join(long, int) in class Thread I-145 

K
--------------------------------------


key
--------------------------------------
    int key in class Event II-84 
KEY_ACTION
--------------------------------------
    static int KEY_ACTION in class Event II-85 
KEY_ACTION_RELEASE
--------------------------------------
    static int KEY_ACTION_RELEASE in class Event II-85 
KEY_PRESS
--------------------------------------
    static int KEY_PRESS in class Event II-85 
KEY_RELEASE
--------------------------------------
    static int KEY_RELEASE in class Event II-85 
keyDown
--------------------------------------
    boolean keyDown(Event, int) in class Component II-51 
keys
--------------------------------------
    Enumeration keys() in class Dictionary I-370 
    Enumeration keys() in class Hashtable I-375 
keyUp
--------------------------------------
    boolean keyUp(Event, int) in class Component II-51 

L
--------------------------------------


Label
--------------------------------------
    Class in package java.awt II-161 
    Label() in class Label II-162 
    Label(String) in class Label II-162 
    Label(String, int) in class Label II-162 
LabelPeer
--------------------------------------
    Interface in package java.awt.peer II-335 
last
--------------------------------------
    void last(Container) in class CardLayout II-15 
lastElement
--------------------------------------
    Object lastElement() in class Vector I-397 
lastIndexOf
--------------------------------------
    int lastIndexOf(int) in class String I-106 
    int lastIndexOf(int, int) in class String I-106 
    int lastIndexOf(Object) in class Vector I-397 
    int lastIndexOf(Object, int) in class Vector I-397 
    int lastIndexOf(String) in class String I-107 
    int lastIndexOf(String, int) in class String I-107 
lastModified
--------------------------------------
    long lastModified() in class File I-249 
layout
--------------------------------------
    void layout() in class Component II-52 
    void layout() in class Container II-72 
layoutContainer
--------------------------------------
    void layoutContainer(Container) in class BorderLayout II-6 
    void layoutContainer(Container) in class CardLayout II-15 
    void layoutContainer(Container) in class FlowLayout II-99 
    void layoutContainer(Container) in class GridBagLayout II-149 
    void layoutContainer(Container) in class GridLayout II-153 
    void layoutContainer(Container) in interface LayoutManager II-244 
LayoutManager
--------------------------------------
    Interface in package java.awt II-244 
LEFT
--------------------------------------
    static int LEFT in class Event II-89 
    static int LEFT in class FlowLayout II-98 
    static int LEFT in class Label II-162 
left
--------------------------------------
    int left in class Insets II-159 
length
--------------------------------------
    int length() in class String I-107 
    int length() in class StringBuffer I-126 
    long length() in class File I-249 
    long length() in class RandomAccessFile I-306 
lightGray
--------------------------------------
    static Color lightGray in class Color II-32 
lineno
--------------------------------------
    int lineno() in class StreamTokenizer I-325 
LineNumberInputStream
--------------------------------------
    Class in package java.io I-278 
    LineNumberInputStream(InputStream) in class LineNumberInputStream I-278 
LinkageError
--------------------------------------
    Class in package java.lang I-196 
    LinkageError() in class LinkageError I-196 
    LinkageError(String) in class LinkageError I-196 
List
--------------------------------------
    Class in package java.awt II-164 
    List() in class List II-166 
    List(int, boolean) in class List II-166 
list
--------------------------------------
    String list()[] in class File I-250 
    String list(FilenameFilter)[] in class File I-250 
    void list() in class Component II-52 
    void list() in class ThreadGroup I-154 
    void list(PrintStream) in class Component II-52 
    void list(PrintStream) in class Properties I-382 
    void list(PrintStream, int) in class Component II-52 
    void list(PrintStream, int) in class Container II-72 
LIST_DESELECT
--------------------------------------
    static int LIST_DESELECT in class Event II-85 
LIST_SELECT
--------------------------------------
    static int LIST_SELECT in class Event II-85 
listen
--------------------------------------
    void listen(int) in class SocketImpl I-434 
ListPeer
--------------------------------------
    Interface in package java.awt.peer II-336 
LOAD
--------------------------------------
    static int LOAD in class FileDialog II-93 
load
--------------------------------------
    static void load(String) in class System I-135 
    void load(InputStream) in class Properties I-383 
    void load(String) in class Runtime I-83 
LOAD_FILE
--------------------------------------
    static int LOAD_FILE in class Event II-85 
loadClass
--------------------------------------
    Class loadClass(String, boolean) in class ClassLoader I-24 
LOADING
--------------------------------------
    static int LOADING in class MediaTracker II-177 
loadLibrary
--------------------------------------
    static void loadLibrary(String) in class System I-135 
    void loadLibrary(String) in class Runtime I-83 
localport
--------------------------------------
    int localport in class SocketImpl I-431 
locate
--------------------------------------
    Component locate(int, int) in class Component II-53 
    Component locate(int, int) in class Container II-73 
location
--------------------------------------
    Point location() in class Component II-53 
log
--------------------------------------
    static double log(double) in class Math I-64 
Long
--------------------------------------
    Class in package java.lang I-50 
    Long(long) in class Long I-51 
    Long(String) in class Long I-51 
longBitsToDouble
--------------------------------------
    static double longBitsToDouble(long) in class Double I-32 
longValue
--------------------------------------
    long longValue() in class Double I-32 
    long longValue() in class Float I-39 
    long longValue() in class Integer I-45 
    long longValue() in class Long I-54 
    long longValue() in class Number I-69 
lookupConstraints
--------------------------------------
    GridBagConstraints lookupConstraints(Component) in class GridBagLayout II-149 
loop
--------------------------------------
    void loop() in interface AudioClip 369 
LOST_FOCUS
--------------------------------------
    static int LOST_FOCUS in class Event II-85 
lostFocus
--------------------------------------
    boolean lostFocus(Event, Object) in class Component II-54 
lowerCaseMode
--------------------------------------
    void lowerCaseMode(boolean) in class StreamTokenizer I-325 

M
--------------------------------------


magenta
--------------------------------------
    static Color magenta in class Color II-32 
makeVisible
--------------------------------------
    void makeVisible(int) in class List II-170 
    void makeVisible(int) in interface ListPeer II-337 
MalformedURLException
--------------------------------------
    Class in package java.net I-466 
    MalformedURLException() in class MalformedURLException I-466 
    MalformedURLException(String) in class MalformedURLException I-466 
mark
--------------------------------------
    void mark(int) in class BufferedInputStream I-212 
    void mark(int) in class FilterInputStream I-265 
    void mark(int) in class InputStream I-274 
    void mark(int) in class LineNumberInputStream I-279 
marklimit
--------------------------------------
    int marklimit in class BufferedInputStream I-211 
markpos
--------------------------------------
    int markpos in class BufferedInputStream I-211 
markSupported
--------------------------------------
    boolean markSupported() in class BufferedInputStream I-213 
    boolean markSupported() in class FilterInputStream I-265 
    boolean markSupported() in class InputStream I-275 
    boolean markSupported() in class PushbackInputStream I-300 
Math
--------------------------------------
    Class in package java.lang I-59 
max
--------------------------------------
    static double max(double, double) in class Math I-64 
    static float max(float, float) in class Math I-64 
    static int max(int, int) in class Math I-64 
    static long max(long, long) in class Math I-65 
MAX_PRIORITY
--------------------------------------
    static int MAX_PRIORITY in class Thread I-139 
MAX_VALUE
--------------------------------------
    static char MAX_VALUE in class Character I-8 
    static double MAX_VALUE in class Double I-28 
    static float MAX_VALUE in class Float I-35 
    static int MAX_VALUE in class Integer I-42 
    static long MAX_VALUE in class Long I-51 
MAXGRIDSIZE
--------------------------------------
    static int MAXGRIDSIZE in class GridBagLayout II-148 
MediaTracker
--------------------------------------
    Class in package java.awt II-174 
    MediaTracker(Component) in class MediaTracker II-177 
MemoryImageSource
--------------------------------------
    Class in package java.awt.image II-281 
    MemoryImageSource(int, int, ColorModel, byte[], int, int) in class MemoryImageSource II-282 
    MemoryImageSource(int, int, ColorModel, byte[], int, int, Hashtable) in class MemoryImageSource II-283 
    MemoryImageSource(int, int, ColorModel, int[], int, int) in class MemoryImageSource II-283 
    MemoryImageSource(int, int, ColorModel, int[], int, int, Hashtable) in class MemoryImageSource II-284 
    MemoryImageSource(int, int, int[], int, int) in class MemoryImageSource II-284 
    MemoryImageSource(int, int, int[], int, int, Hashtable) in class MemoryImageSource II-285 
Menu
--------------------------------------
    Class in package java.awt II-185 
    Menu(String) in class Menu II-185 
    Menu(String, boolean) in class Menu II-186 
MenuBar
--------------------------------------
    Class in package java.awt II-188 
    MenuBar() in class MenuBar II-188 
MenuBarPeer
--------------------------------------
    Interface in package java.awt.peer II-339 
MenuComponent
--------------------------------------
    Class in package java.awt II-191 
    MenuComponent() in class MenuComponent II-191 
MenuComponentPeer
--------------------------------------
    Interface in package java.awt.peer II-340 
MenuContainer
--------------------------------------
    Interface in package java.awt II-246 
MenuItem
--------------------------------------
    Class in package java.awt II-194 
    MenuItem(String) in class MenuItem II-194 
MenuItemPeer
--------------------------------------
    Interface in package java.awt.peer II-341 
MenuPeer
--------------------------------------
    Interface in package java.awt.peer II-342 
META_MASK
--------------------------------------
    static int META_MASK in class Event II-89 
metaDown
--------------------------------------
    boolean metaDown() in class Event II-91 
min
--------------------------------------
    static double min(double, double) in class Math I-65 
    static float min(float, float) in class Math I-65 
    static int min(int, int) in class Math I-65 
    static long min(long, long) in class Math I-65 
MIN_PRIORITY
--------------------------------------
    static int MIN_PRIORITY in class Thread I-139 
MIN_RADIX
--------------------------------------
    static int MIN_RADIX in class Character I-8 
MIN_VALUE
--------------------------------------
    static char MIN_VALUE in class Character I-8 
    static double MIN_VALUE in class Double I-28 
    static float MIN_VALUE in class Float I-35 
    static int MIN_VALUE in class Integer I-42 
    static long MIN_VALUE in class Long I-51 
minimumLayoutSize
--------------------------------------
    Dimension minimumLayoutSize(Container) in class BorderLayout II-7 
    Dimension minimumLayoutSize(Container) in class CardLayout II-16 
    Dimension minimumLayoutSize(Container) in class FlowLayout II-100 
    Dimension minimumLayoutSize(Container) in class GridBagLayout II-149 
    Dimension minimumLayoutSize(Container) in class GridLayout II-154 
    Dimension minimumLayoutSize(Container) in interface LayoutManager II-245 
minimumSize
--------------------------------------
    Dimension minimumSize() in class Component II-54 
    Dimension minimumSize() in class Container II-73 
    Dimension minimumSize() in class List II-171 
    Dimension minimumSize() in class TextArea II-220 
    Dimension minimumSize() in class TextField II-228 
    Dimension minimumSize() in interface ComponentPeer II-326 
    Dimension minimumSize(int) in class List II-171 
    Dimension minimumSize(int) in class TextField II-228 
    Dimension minimumSize(int) in interface ListPeer II-337 
    Dimension minimumSize(int) in interface TextFieldPeer II-350 
    Dimension minimumSize(int, int) in class TextArea II-220 
    Dimension minimumSize(int, int) in interface TextAreaPeer II-346 
MINSIZE
--------------------------------------
    static int MINSIZE in class GridBagLayout II-148 
mkdir
--------------------------------------
    boolean mkdir() in class File I-250 
mkdirs
--------------------------------------
    boolean mkdirs() in class File I-251 
modifiers
--------------------------------------
    int modifiers in class Event II-84 
MOUSE_DOWN
--------------------------------------
    static int MOUSE_DOWN in class Event II-86 
MOUSE_DRAG
--------------------------------------
    static int MOUSE_DRAG in class Event II-86 
MOUSE_ENTER
--------------------------------------
    static int MOUSE_ENTER in class Event II-86 
MOUSE_EXIT
--------------------------------------
    static int MOUSE_EXIT in class Event II-86 
MOUSE_MOVE
--------------------------------------
    static int MOUSE_MOVE in class Event II-86 
MOUSE_UP
--------------------------------------
    static int MOUSE_UP in class Event II-86 
mouseDown
--------------------------------------
    boolean mouseDown(Event, int, int) in class Component II-55 
mouseDrag
--------------------------------------
    boolean mouseDrag(Event, int, int) in class Component II-56 
mouseEnter
--------------------------------------
    boolean mouseEnter(Event, int, int) in class Component II-56 
mouseExit
--------------------------------------
    boolean mouseExit(Event, int, int) in class Component II-57 
mouseMove
--------------------------------------
    boolean mouseMove(Event, int, int) in class Component II-57 
mouseUp
--------------------------------------
    boolean mouseUp(Event, int, int) in class Component II-58 
move
--------------------------------------
    void move(int, int) in class Component II-58 
    void move(int, int) in class Point II-199 
    void move(int, int) in class Rectangle II-207 
MOVE_CURSOR
--------------------------------------
    static int MOVE_CURSOR in class Frame II-115 

N

N_RESIZE_CURSOR
--------------------------------------
    static int N_RESIZE_CURSOR in class Frame II-115 
name
--------------------------------------
    String name in class Font II-102 
NaN
--------------------------------------
    static double NaN in class Double I-28 
    static float NaN in class Float I-35 
NE_RESIZE_CURSOR
--------------------------------------
    static int NE_RESIZE_CURSOR in class Frame II-115 
NEGATIVE_INFINITY
--------------------------------------
    static double NEGATIVE_INFINITY in class Double I-28 
    static float NEGATIVE_INFINITY in class Float I-35 
NegativeArraySizeException
--------------------------------------
    Class in package java.lang I-180 
    NegativeArraySizeException() in class NegativeArraySizeException I-180 
    NegativeArraySizeException(String) in class NegativeArraySizeException I-180 
newInstance
--------------------------------------
    Object newInstance() in class Class I-20 
newmodel
--------------------------------------
    ColorModel newmodel in class RGBImageFilter II-295 
next
--------------------------------------
    void next(Container) in class CardLayout II-16 
nextDouble
--------------------------------------
    double nextDouble() in class Random I-385 
nextElement
--------------------------------------
    Object nextElement() in class StringTokenizer I-390 
    Object nextElement() in interface Enumeration I-402 
nextFloat
--------------------------------------
    float nextFloat() in class Random I-385 
nextFocus
--------------------------------------
    void nextFocus() in class Component II-58 
    void nextFocus() in interface ComponentPeer II-326 
nextGaussian
--------------------------------------
    double nextGaussian() in class Random I-385 
nextInt
--------------------------------------
    int nextInt() in class Random I-385 
nextLong
--------------------------------------
    long nextLong() in class Random I-385 
nextToken
--------------------------------------
    int nextToken() in class StreamTokenizer I-326 
    String nextToken() in class StringTokenizer I-390 
    String nextToken(String) in class StringTokenizer I-391 
NoClassDefFoundError
--------------------------------------
    Class in package java.lang I-197 
    NoClassDefFoundError() in class NoClassDefFoundError I-197 
    NoClassDefFoundError(String) in class NoClassDefFoundError I-197 
NONE
--------------------------------------
    static int NONE in class GridBagConstraints II-143 
NORM_PRIORITY
--------------------------------------
    static int NORM_PRIORITY in class Thread I-140 
NORTH
--------------------------------------
    static int NORTH in class GridBagConstraints II-143 
NORTHEAST
--------------------------------------
    static int NORTHEAST in class GridBagConstraints II-143 
NORTHWEST
--------------------------------------
    static int NORTHWEST in class GridBagConstraints II-143 
NoSuchElementException
--------------------------------------
    Class in package java.util I-407 
    NoSuchElementException() in class NoSuchElementException I-407 
    NoSuchElementException(String) in class NoSuchElementException I-407 
NoSuchFieldError
--------------------------------------
    Class in package java.lang I-198 
    NoSuchFieldError() in class NoSuchFieldError I-198 
    NoSuchFieldError(String) in class NoSuchFieldError I-198 
NoSuchMethodError
--------------------------------------
    Class in package java.lang I-199 
    NoSuchMethodError() in class NoSuchMethodError I-199 
    NoSuchMethodError(String) in class NoSuchMethodError I-199 
NoSuchMethodException
--------------------------------------
    Class in package java.lang I-181 
    NoSuchMethodException() in class NoSuchMethodException I-181 
    NoSuchMethodException(String) in class NoSuchMethodException I-181 
notify
--------------------------------------
    void notify() in class Object I-72 
notifyAll
--------------------------------------
    void notifyAll() in class Object I-73 
notifyObservers
--------------------------------------
    void notifyObservers() in class Observable I-379 
    void notifyObservers(Object) in class Observable I-380 
npoints
--------------------------------------
    int npoints in class Polygon II-201 
NullPointerException
--------------------------------------
    Class in package java.lang I-182 
    NullPointerException() in class NullPointerException I-182 
    NullPointerException(String) in class NullPointerException I-182 
Number
--------------------------------------
    Class in package java.lang I-69 
NumberFormatException
--------------------------------------
    Class in package java.lang I-183 
    NumberFormatException() in class NumberFormatException I-183 
    NumberFormatException(String) in class NumberFormatException I-183 
nval
--------------------------------------
    double nval in class StreamTokenizer I-323 
NW_RESIZE_CURSOR
--------------------------------------
    static int NW_RESIZE_CURSOR in class Frame II-115 

O
--------------------------------------


Object
--------------------------------------
    Class in package java.lang I-70 
    Object() in class Object I-70 
Observable
--------------------------------------
    Class in package java.util I-378 
    Observable() in class Observable I-378 
Observer
--------------------------------------
    Interface in package java.util I-403 
openConnection
--------------------------------------
    URLConnection openConnection() in class URL I-440 
    URLConnection openConnection(URL) in class URLStreamHandler I-459 
openStream
--------------------------------------
    InputStream openStream() in class URL I-441 
or
--------------------------------------
    void or(BitSet) in class BitSet I-358 
orange
--------------------------------------
    static Color orange in class Color II-32 
ordinaryChar
--------------------------------------
    void ordinaryChar(int) in class StreamTokenizer I-326 
ordinaryChars
--------------------------------------
    void ordinaryChars(int, int) in class StreamTokenizer I-326 
origmodel
--------------------------------------
    ColorModel origmodel in class RGBImageFilter II-295 
out
--------------------------------------
    OutputStream out in class FilterOutputStream I-269 
    static FileDescriptor out in class FileDescriptor I-252 
    static PrintStream out in class System I-130 
OutOfMemoryError
--------------------------------------
    Class in package java.lang I-200 
    OutOfMemoryError() in class OutOfMemoryError I-200 
    OutOfMemoryError(String) in class OutOfMemoryError I-200 
OutputStream
--------------------------------------
    Class in package java.io I-282 
    OutputStream() in class OutputStream I-282 

P

--------------------------------------

pack
--------------------------------------
    void pack() in class Window II-242 
paint
--------------------------------------
    void paint(Graphics) in class Canvas II-13 
    void paint(Graphics) in class Component II-59 
    void paint(Graphics) in interface ComponentPeer II-327 
paintAll
--------------------------------------
    void paintAll(Graphics) in class Component II-59 
paintComponents
--------------------------------------
    void paintComponents(Graphics) in class Container II-74 
Panel
--------------------------------------
    Class in package java.awt II-197 
    Panel() in class Panel II-197 
PanelPeer
--------------------------------------
    Interface in package java.awt.peer II-343 
paramString
--------------------------------------
    String paramString() in class Button II-10 
    String paramString() in class Checkbox II-22 
    String paramString() in class CheckboxMenuItem II-26 
    String paramString() in class Choice II-29 
    String paramString() in class Component II-59 
    String paramString() in class Container II-74 
    String paramString() in class Dialog II-79 
    String paramString() in class Event II-91 
    String paramString() in class FileDialog II-95 
    String paramString() in class Frame II-118 
    String paramString() in class Label II-163 
    String paramString() in class List II-171 
    String paramString() in class MenuComponent II-192 
    String paramString() in class MenuItem II-196 
    String paramString() in class Scrollbar II-215 
    String paramString() in class TextArea II-220 
    String paramString() in class TextComponent II-223 
    String paramString() in class TextField II-229 
parentOf
--------------------------------------
    boolean parentOf(ThreadGroup) in class ThreadGroup I-154 
parse
--------------------------------------
    static long parse(String) in class Date I-366 
parseInt
--------------------------------------
    static int parseInt(String) in class Integer I-45 
    static int parseInt(String, int) in class Integer I-46 
parseLong
--------------------------------------
    static long parseLong(String) in class Long I-55 
    static long parseLong(String, int) in class Long I-55 
parseNumbers
--------------------------------------
    void parseNumbers() in class StreamTokenizer I-326 
parseURL
--------------------------------------
    void parseURL(URL, String, int, int) in class URLStreamHandler I-459 
pathSeparator
--------------------------------------
    static String pathSeparator in class File I-244 
pathSeparatorChar
--------------------------------------
    static char pathSeparatorChar in class File I-244 
peek
--------------------------------------
    Object peek() in class Stack I-386 
PGDN
--------------------------------------
    static int PGDN in class Event II-89 
PGUP
--------------------------------------
    static int PGUP in class Event II-89 
PI
--------------------------------------
    static double PI in class Math I-60 
pink
--------------------------------------
    static Color pink in class Color II-33 
PipedInputStream
--------------------------------------
    Class in package java.io I-285 
    PipedInputStream() in class PipedInputStream I-285 
    PipedInputStream(PipedOutputStream) in class PipedInputStream I-285 
PipedOutputStream
--------------------------------------
    Class in package java.io I-288 
    PipedOutputStream() in class PipedOutputStream I-288 
    PipedOutputStream(PipedInputStream) in class PipedOutputStream I-288 
pixel_bits
--------------------------------------
    int pixel_bits in class ColorModel II-254 
PixelGrabber
--------------------------------------
    Class in package java.awt.image II-287 
    PixelGrabber(Image, int, int, int, int, int[], int, int) in class PixelGrabber II-289 
    PixelGrabber(ImageProducer, int, int, int, int, int[], int, int) in class PixelGrabber II-290 
PLAIN
--------------------------------------
    static int PLAIN in class Font II-103 
play
--------------------------------------
    void play() in interface AudioClip 369 
    void play(URL) in class Applet 361 
    void play(URL, String) in class Applet 361 
Point
--------------------------------------
    Class in package java.awt II-198 
    Point(int, int) in class Point II-198 
Polygon
--------------------------------------
    Class in package java.awt II-201 
    Polygon() in class Polygon II-201 
    Polygon(int[], int[], int) in class Polygon II-202 
pop
--------------------------------------
    Object pop() in class Stack I-387 
port
--------------------------------------
    int port in class SocketImpl I-431 
pos
--------------------------------------
    int pos in class BufferedInputStream I-211 
    int pos in class ByteArrayInputStream I-219 
    int pos in class StringBufferInputStream I-329 
POSITIVE_INFINITY
--------------------------------------
    static double POSITIVE_INFINITY in class Double I-28 
    static float POSITIVE_INFINITY in class Float I-35 
postEvent
--------------------------------------
    boolean postEvent(Event) in class Component II-60 
    boolean postEvent(Event) in class MenuComponent II-192 
    boolean postEvent(Event) in interface MenuContainer II-246 
pow
    static double pow(double, double) in class Math I-66 
preferredLayoutSize
--------------------------------------
    Dimension preferredLayoutSize(Container) in class BorderLayout II-7 
    Dimension preferredLayoutSize(Container) in class CardLayout II-17 
    Dimension preferredLayoutSize(Container) in class FlowLayout II-101 
    Dimension preferredLayoutSize(Container) in class GridBagLayout II-150 
    Dimension preferredLayoutSize(Container) in class GridLayout II-155 
    Dimension preferredLayoutSize(Container) in interface LayoutManager II-245 
preferredSize
--------------------------------------
    Dimension preferredSize() in class Component II-60 
    Dimension preferredSize() in class Container II-74 
    Dimension preferredSize() in class List II-172 
    Dimension preferredSize() in class TextArea II-221 
    Dimension preferredSize() in class TextField II-229 
    Dimension preferredSize() in interface ComponentPeer II-327 
    Dimension preferredSize(int) in class List II-172 
    Dimension preferredSize(int) in class TextField II-229 
    Dimension preferredSize(int) in interface ListPeer II-338 
    Dimension preferredSize(int) in interface TextFieldPeer II-350 
    Dimension preferredSize(int, int) in class TextArea II-221 
    Dimension preferredSize(int, int) in interface TextAreaPeer II-346 
prepareImage
--------------------------------------
    boolean prepareImage(Image, ImageObserver) in class Component II-61 
    boolean prepareImage(Image, int, int, ImageObserver) in class Component II-61 
    boolean prepareImage(Image, int, int, ImageObserver) in class Toolkit II-239 
    boolean prepareImage(Image, int, int, ImageObserver) in interface ComponentPeer II-327 
previous
--------------------------------------
    void previous(Container) in class CardLayout II-17 
print
--------------------------------------
    void print(boolean) in class PrintStream I-293 
    void print(char) in class PrintStream I-293 
    void print(char[]) in class PrintStream I-294 
    void print(double) in class PrintStream I-294 
    void print(float) in class PrintStream I-294 
    void print(Graphics) in class Component II-62 
    void print(Graphics) in interface ComponentPeer II-328 
    void print(int) in class PrintStream I-294 
    void print(long) in class PrintStream I-294 
    void print(Object) in class PrintStream I-295 
    void print(String) in class PrintStream I-295 
printAll
--------------------------------------
    void printAll(Graphics) in class Component II-62 
printComponents
--------------------------------------
    void printComponents(Graphics) in class Container II-74 
println
--------------------------------------
    void println() in class PrintStream I-295 
    void println(boolean) in class PrintStream I-295 
    void println(char) in class PrintStream I-295 
    void println(char[]) in class PrintStream I-296 
    void println(double) in class PrintStream I-296 
    void println(float) in class PrintStream I-296 
    void println(int) in class PrintStream I-296 
    void println(long) in class PrintStream I-296 
    void println(Object) in class PrintStream I-297 
    void println(String) in class PrintStream I-297 
printStackTrace
--------------------------------------
    void printStackTrace() in class Throwable I-159 
    void printStackTrace(PrintStream) in class Throwable I-159 
PrintStream
--------------------------------------
    Class in package java.io I-291 
    PrintStream(OutputStream) in class PrintStream I-292 
    PrintStream(OutputStream, boolean) in class PrintStream I-292 
Process
--------------------------------------
    Class in package java.lang I-76 
    Process() in class Process I-76 
PROPERTIES
--------------------------------------
    static int PROPERTIES in interface ImageObserver II-309 
Properties
--------------------------------------
    Class in package java.util I-381 
    Properties() in class Properties I-381 
    Properties(Properties) in class Properties I-382 
propertyNames
--------------------------------------
    Enumeration propertyNames() in class Properties I-383 
ProtocolException
--------------------------------------
    Class in package java.net I-467 
    ProtocolException() in class ProtocolException I-467 
    ProtocolException(String) in class ProtocolException I-467 
push
--------------------------------------
    Object push(Object) in class Stack I-387 
pushBack
--------------------------------------
    int pushBack in class PushbackInputStream I-299 
    void pushBack() in class StreamTokenizer I-327 
PushbackInputStream
--------------------------------------
    Class in package java.io I-299 
    PushbackInputStream(InputStream) in class PushbackInputStream I-299 
put
--------------------------------------
    Object put(Object, Object) in class Dictionary I-370 
    Object put(Object, Object) in class Hashtable I-376 

Q

quoteChar
--------------------------------------
    void quoteChar(int) in class StreamTokenizer I-327 

R

Random
--------------------------------------
    Class in package java.util I-384 
    Random() in class Random I-384 
    Random(long) in class Random I-384 
random
--------------------------------------
    static double random() in class Math I-66 
RandomAccessFile
--------------------------------------
    Class in package java.io I-303 
    RandomAccessFile(File, String) in class RandomAccessFile I-304 
    RandomAccessFile(String, String) in class RandomAccessFile I-305 
RANDOMPIXELORDER
--------------------------------------
    static int RANDOMPIXELORDER in interface ImageConsumer II-303 
read
--------------------------------------
    int read() in class BufferedInputStream I-213 
    int read() in class ByteArrayInputStream I-221 
    int read() in class FileInputStream I-256 
    int read() in class FilterInputStream I-266 
    int read() in class InputStream I-275 
    int read() in class LineNumberInputStream I-280 
    int read() in class PipedInputStream I-286 
    int read() in class PushbackInputStream I-301 
    int read() in class RandomAccessFile I-306 
    int read() in class SequenceInputStream I-320 
    int read() in class StringBufferInputStream I-330 
    int read(byte[]) in class DataInputStream I-228 
    int read(byte[]) in class FileInputStream I-257 
    int read(byte[]) in class FilterInputStream I-266 
    int read(byte[]) in class InputStream I-275 
    int read(byte[]) in class RandomAccessFile I-306 
    int read(byte[], int, int) in class BufferedInputStream I-214 
    int read(byte[], int, int) in class ByteArrayInputStream I-221 
    int read(byte[], int, int) in class DataInputStream I-228 
    int read(byte[], int, int) in class FileInputStream I-257 
    int read(byte[], int, int) in class FilterInputStream I-267 
    int read(byte[], int, int) in class InputStream I-276 
    int read(byte[], int, int) in class LineNumberInputStream I-280 
    int read(byte[], int, int) in class PipedInputStream I-287 
    int read(byte[], int, int) in class PushbackInputStream I-301 
    int read(byte[], int, int) in class RandomAccessFile I-307 
    int read(byte[], int, int) in class SequenceInputStream I-321 
    int read(byte[], int, int) in class StringBufferInputStream I-331 
readBoolean
--------------------------------------
    boolean readBoolean() in class DataInputStream I-229 
    boolean readBoolean() in class RandomAccessFile I-307 
    boolean readBoolean() in interface DataInput I-334 
readByte
--------------------------------------
    byte readByte() in class DataInputStream I-229 
    byte readByte() in class RandomAccessFile I-307 
    byte readByte() in interface DataInput I-335 
readChar
--------------------------------------
    char readChar() in class DataInputStream I-229 
    char readChar() in class RandomAccessFile I-308 
    char readChar() in interface DataInput I-335 
readDouble
--------------------------------------
    double readDouble() in class DataInputStream I-230 
    double readDouble() in class RandomAccessFile I-309 
    double readDouble() in interface DataInput I-335 
readFloat
--------------------------------------
    float readFloat() in class DataInputStream I-230 
    float readFloat() in class RandomAccessFile I-309 
    float readFloat() in interface DataInput I-336 
readFully
--------------------------------------
    void readFully(byte[]) in class DataInputStream I-231 
    void readFully(byte[]) in class RandomAccessFile I-310 
    void readFully(byte[]) in interface DataInput I-336 
    void readFully(byte[], int, int) in class DataInputStream I-231 
    void readFully(byte[], int, int) in class RandomAccessFile I-310 
    void readFully(byte[], int, int) in interface DataInput I-336 
readInt
--------------------------------------
    int readInt() in class DataInputStream I-231 
    int readInt() in class RandomAccessFile I-310 
    int readInt() in interface DataInput I-337 
readLine
--------------------------------------
    String readLine() in class DataInputStream I-232 
    String readLine() in class RandomAccessFile I-311 
    String readLine() in interface DataInput I-337 
readLong
--------------------------------------
    long readLong() in class DataInputStream I-232 
    long readLong() in class RandomAccessFile I-311 
    long readLong() in interface DataInput I-337 
readShort
--------------------------------------
    short readShort() in class DataInputStream I-233 
    short readShort() in class RandomAccessFile I-312 
    short readShort() in interface DataInput I-338 
readUnsignedByte
--------------------------------------
    int readUnsignedByte() in class DataInputStream I-234 
    int readUnsignedByte() in class RandomAccessFile I-313 
    int readUnsignedByte() in interface DataInput I-338 
readUnsignedShort
--------------------------------------
    int readUnsignedShort() in class DataInputStream I-234 
    int readUnsignedShort() in class RandomAccessFile I-313 
    int readUnsignedShort() in interface DataInput I-338 
readUTF
--------------------------------------
    static String readUTF(DataInput) in class DataInputStream I-235 
    String readUTF() in class DataInputStream I-235 
    String readUTF() in class RandomAccessFile I-314 
    String readUTF() in interface DataInput I-339 
receive
--------------------------------------
    void receive(DatagramPacket) in class DatagramSocket I-417 
Rectangle
--------------------------------------
    Class in package java.awt II-203 
    Rectangle() in class Rectangle II-204 
    Rectangle(Dimension) in class Rectangle II-204 
    Rectangle(int, int) in class Rectangle II-204 
    Rectangle(int, int, int, int) in class Rectangle II-204 
    Rectangle(Point) in class Rectangle II-205 
    Rectangle(Point, Dimension) in class Rectangle II-205 
red
--------------------------------------
    static Color red in class Color II-33 
regionMatches
--------------------------------------
    boolean regionMatches(boolean, int, String, int, int) in class String I-108 
    boolean regionMatches(int, String, int, int) in class String I-108 
rehash
--------------------------------------
    void rehash() in class Hashtable I-376 
RELATIVE
--------------------------------------
    static int RELATIVE in class GridBagConstraints II-144 
REMAINDER
--------------------------------------
    static int REMAINDER in class GridBagConstraints II-144 
remove
--------------------------------------
    Object remove(Object) in class Dictionary I-371 
    Object remove(Object) in class Hashtable I-376 
    void remove(Component) in class Container II-75 
    void remove(int) in class Menu II-187 
    void remove(int) in class MenuBar II-189 
    void remove(MenuComponent) in class Frame II-118 
    void remove(MenuComponent) in class Menu II-187 
    void remove(MenuComponent) in class MenuBar II-190 
    void remove(MenuComponent) in interface MenuContainer II-246 
removeAll
--------------------------------------
    void removeAll() in class Container II-75 
removeAllElements
--------------------------------------
    void removeAllElements() in class Vector I-397 
removeConsumer
--------------------------------------
    void removeConsumer(ImageConsumer) in class FilteredImageSource II-266 
    void removeConsumer(ImageConsumer) in class MemoryImageSource II-286 
    void removeConsumer(ImageConsumer) in interface ImageProducer II-313 
removeElement
--------------------------------------
    boolean removeElement(Object) in class Vector I-398 
removeElementAt
--------------------------------------
    void removeElementAt(int) in class Vector I-398 
removeLayoutComponent
--------------------------------------
    void removeLayoutComponent(Component) in class BorderLayout II-7 
    void removeLayoutComponent(Component) in class CardLayout II-17 
    void removeLayoutComponent(Component) in class FlowLayout II-101 
    void removeLayoutComponent(Component) in class GridBagLayout II-150 
    void removeLayoutComponent(Component) in class GridLayout II-155 
    void removeLayoutComponent(Component) in interface LayoutManager II-245 
removeNotify
--------------------------------------
    void removeNotify() in class Component II-62 
    void removeNotify() in class Container II-75 
    void removeNotify() in class List II-172 
    void removeNotify() in class Menu II-187 
    void removeNotify() in class MenuBar II-190 
    void removeNotify() in class MenuComponent II-192 
    void removeNotify() in class TextComponent II-223 
renameTo
--------------------------------------
    boolean renameTo(File) in class File I-251 
repaint
--------------------------------------
    void repaint() in class Component II-63 
    void repaint(int, int, int, int) in class Component II-63 
    void repaint(long) in class Component II-63 
    void repaint(long, int, int, int, int) in class Component II-63 
    void repaint(long, int, int, int, int) in interface ComponentPeer II-328 
replace
--------------------------------------
    String replace(char, char) in class String I-109 
replaceItem
--------------------------------------
    void replaceItem(String, int) in class List II-172 
replaceText
--------------------------------------
    void replaceText(String, int, int) in class TextArea II-221 
    void replaceText(String, int, int) in interface TextAreaPeer II-347 
requestFocus
--------------------------------------
    void requestFocus() in class Component II-64 
    void requestFocus() in interface ComponentPeer II-328 
requestTopDownLeftRightResend
--------------------------------------
    void requestTopDownLeftRightResend(ImageConsumer) in class FilteredImageSource II-267 
    void requestTopDownLeftRightResend(ImageConsumer) in class MemoryImageSource II-286 
    void requestTopDownLeftRightResend(ImageConsumer) in interface ImageProducer II-313 
resendTopDownLeftRight
--------------------------------------
    void resendTopDownLeftRight(ImageProducer) in class ImageFilter II-270 
reset
--------------------------------------
    void reset() in class BufferedInputStream I-214 
    void reset() in class ByteArrayInputStream I-221 
    void reset() in class ByteArrayOutputStream I-224 
    void reset() in class FilterInputStream I-267 
    void reset() in class InputStream I-276 
    void reset() in class LineNumberInputStream I-281 
    void reset() in class StringBufferInputStream I-331 
resetSyntax
--------------------------------------
    void resetSyntax() in class StreamTokenizer I-327 
reshape
--------------------------------------
    void reshape(int, int, int, int) in class Component II-64 
    void reshape(int, int, int, int) in class Rectangle II-208 
    void reshape(int, int, int, int) in interface ComponentPeer II-328 
resize
--------------------------------------
    void resize(Dimension) in class Applet 361 
    void resize(Dimension) in class Component II-64 
    void resize(int, int) in class Applet 361 
    void resize(int, int) in class Component II-65 
    void resize(int, int) in class Rectangle II-208 
resolveClass
--------------------------------------
    void resolveClass(Class) in class ClassLoader I-24 
resume
--------------------------------------
    void resume() in class Thread I-145 
    void resume() in class ThreadGroup I-155 
reverse
--------------------------------------
    StringBuffer reverse() in class StringBuffer I-127 
RGBImageFilter
--------------------------------------
    Class in package java.awt.image II-294 
    RGBImageFilter() in class RGBImageFilter II-295 
RGBtoHSB
--------------------------------------
    static float RGBtoHSB(int, int, int, float[])[] in class Color II-38 
RIGHT
--------------------------------------
    static int RIGHT in class Event II-89 
    static int RIGHT in class FlowLayout II-98 
    static int RIGHT in class Label II-162 
right
--------------------------------------
    int right in class Insets II-159 
rint
--------------------------------------
    static double rint(double) in class Math I-66 
round
--------------------------------------
    static int round(float) in class Math I-67 
    static long round(double) in class Math I-67 
run
--------------------------------------
    void run() in class Thread I-145 
    void run() in interface Runnable I-163 
runFinalization
--------------------------------------
    static void runFinalization() in class System I-135 
    void runFinalization() in class Runtime I-83 
Runnable
--------------------------------------
    Interface in package java.lang I-163 
Runtime
--------------------------------------
    Class in package java.lang I-78 
RuntimeException
--------------------------------------
    Class in package java.lang I-184 
    RuntimeException() in class RuntimeException I-184 
    RuntimeException(String) in class RuntimeException I-184 

S
--------------------------------------

S_RESIZE_CURSOR
--------------------------------------
    static int S_RESIZE_CURSOR in class Frame II-115 
sameFile
--------------------------------------
    boolean sameFile(URL) in class URL I-441 
SAVE
--------------------------------------
    static int SAVE in class FileDialog II-93 
save
--------------------------------------
    void save(OutputStream, String) in class Properties I-383 
SAVE_FILE
--------------------------------------
    static int SAVE_FILE in class Event II-86 
SCROLL_ABSOLUTE
--------------------------------------
    static int SCROLL_ABSOLUTE in class Event II-86 
SCROLL_LINE_DOWN
--------------------------------------
    static int SCROLL_LINE_DOWN in class Event II-86 
SCROLL_LINE_UP
--------------------------------------
    static int SCROLL_LINE_UP in class Event II-87 
SCROLL_PAGE_DOWN
--------------------------------------
    static int SCROLL_PAGE_DOWN in class Event II-87 
SCROLL_PAGE_UP
--------------------------------------
    static int SCROLL_PAGE_UP in class Event II-87 
Scrollbar
--------------------------------------
    Class in package java.awt II-210 
    Scrollbar() in class Scrollbar II-212 
    Scrollbar(int) in class Scrollbar II-212 
    Scrollbar(int, int, int, int, int) in class Scrollbar II-213 
ScrollbarPeer
--------------------------------------
    Interface in package java.awt.peer II-344 
SE_RESIZE_CURSOR
--------------------------------------
    static int SE_RESIZE_CURSOR in class Frame II-115 
search
--------------------------------------
    int search(Object) in class Stack I-387 
SecurityException
--------------------------------------
    Class in package java.lang I-185 
    SecurityException() in class SecurityException I-185 
    SecurityException(String) in class SecurityException I-185 
SecurityManager
--------------------------------------
    Class in package java.lang I-85 
    SecurityManager() in class SecurityManager I-86 
seek
--------------------------------------
    void seek(long) in class RandomAccessFile I-314 
select
--------------------------------------
    void select(int) in class Choice II-30 
    void select(int) in class List II-173 
    void select(int) in interface ChoicePeer II-322 
    void select(int) in interface ListPeer II-338 
    void select(int, int) in class TextComponent II-223 
    void select(int, int) in interface TextComponentPeer II-348 
    void select(String) in class Choice II-30 
selectAll
--------------------------------------
    void selectAll() in class TextComponent II-223 
send
--------------------------------------
    void send(DatagramPacket) in class DatagramSocket I-417 
separator
--------------------------------------
    static String separator in class File I-244 
separatorChar
--------------------------------------
    static char separatorChar in class File I-244 
SequenceInputStream
--------------------------------------
    Class in package java.io I-319 
--------------------------------------
    SequenceInputStream(Enumeration) in class SequenceInputStream I-319 
    SequenceInputStream(InputStream, InputStream) in class SequenceInputStream I-319 
ServerSocket
--------------------------------------
    Class in package java.net I-421 
    ServerSocket(int) in class ServerSocket I-422 
    ServerSocket(int, int) in class ServerSocket I-422 
set
--------------------------------------
    void set(int) in class BitSet I-358 
setAlignment
--------------------------------------
    void setAlignment(int) in class Label II-163 
    void setAlignment(int) in interface LabelPeer II-335 
setAllowUserInteraction
--------------------------------------
    void setAllowUserInteraction(boolean) in class URLConnection I-454 
setBackground
--------------------------------------
    void setBackground(Color) in class Component II-65 
    void setBackground(Color) in interface ComponentPeer II-328 
setChanged
--------------------------------------
    void setChanged() in class Observable I-380 
setCharAt
    void setCharAt(int, char) in class StringBuffer I-127 
setCheckboxGroup
--------------------------------------
    void setCheckboxGroup(CheckboxGroup) in class Checkbox II-22 
    void setCheckboxGroup(CheckboxGroup) in interface CheckboxPeer II-321 
setColor
--------------------------------------
    void setColor(Color) in class Graphics II-137 
setColorModel
--------------------------------------
    void setColorModel(ColorModel) in class ImageFilter II-270 
    void setColorModel(ColorModel) in class PixelGrabber II-291 
    void setColorModel(ColorModel) in class RGBImageFilter II-298 
    void setColorModel(ColorModel) in interface ImageConsumer II-305 
setConstraints
--------------------------------------
    void setConstraints(Component, GridBagConstraints) in class GridBagLayout II-150 
setContentHandlerFactory
--------------------------------------
    static void setContentHandlerFactory(ContentHandlerFactory) in class URLConnection I-455 
setCurrent
--------------------------------------
    void setCurrent(Checkbox) in class CheckboxGroup II-24 
setCursor
--------------------------------------
    void setCursor(int) in class Frame II-118 
    void setCursor(int) in interface FramePeer II-333 
setDaemon
--------------------------------------
    void setDaemon(boolean) in class Thread I-146 
    void setDaemon(boolean) in class ThreadGroup I-155 
setDate
--------------------------------------
    void setDate(int) in class Date I-366 
setDefaultAllowUserInteraction
--------------------------------------
    static void setDefaultAllowUserInteraction(boolean) in class URLConnection I-455 
setDefaultRequestProperty
--------------------------------------
    static void setDefaultRequestProperty(String, String) in class URLConnection I-455 
setDefaultUseCaches
--------------------------------------
    void setDefaultUseCaches(boolean) in class URLConnection I-455 
setDimensions
--------------------------------------
    void setDimensions(int, int) in class CropImageFilter II-258 
    void setDimensions(int, int) in class ImageFilter II-271 
    void setDimensions(int, int) in class PixelGrabber II-292 
    void setDimensions(int, int) in interface ImageConsumer II-305 
setDirectory
    void setDirectory(String) in class FileDialog II-95 
    void setDirectory(String) in interface FileDialogPeer II-332 
setDoInput
--------------------------------------
    void setDoInput(boolean) in class URLConnection I-455 
setDoOutput
--------------------------------------
    void setDoOutput(boolean) in class URLConnection I-456 
setEchoCharacter
--------------------------------------
    void setEchoCharacter(char) in class TextField II-230 
    void setEchoCharacter(char) in interface TextFieldPeer II-350 
setEditable
--------------------------------------
    void setEditable(boolean) in class TextComponent II-224 
    void setEditable(boolean) in interface TextComponentPeer II-349 
setElementAt
--------------------------------------
    void setElementAt(Object, int) in class Vector I-398 
setFile
--------------------------------------
    void setFile(String) in class FileDialog II-96 
    void setFile(String) in interface FileDialogPeer II-332 
setFilenameFilter
--------------------------------------
    void setFilenameFilter(FilenameFilter) in class FileDialog II-96 
    void setFilenameFilter(FilenameFilter) in interface FileDialogPeer II-332 
setFont
--------------------------------------
    void setFont(Font) in class Component II-65 
    void setFont(Font) in class Graphics II-137 
    void setFont(Font) in class MenuComponent II-192 
    void setFont(Font) in interface ComponentPeer II-329 
setForeground
--------------------------------------
    void setForeground(Color) in class Component II-66 
    void setForeground(Color) in interface ComponentPeer II-329 
setHelpMenu
--------------------------------------
    void setHelpMenu(Menu) in class MenuBar II-190 
setHints
--------------------------------------
    void setHints(int) in class ImageFilter II-271 
    void setHints(int) in class PixelGrabber II-292 
    void setHints(int) in interface ImageConsumer II-305 
setHours
--------------------------------------
    void setHours(int) in class Date I-366 
setIconImage
--------------------------------------
    void setIconImage(Image) in class Frame II-118 
    void setIconImage(Image) in interface FramePeer II-333 
setIfModifiedSince
--------------------------------------
    void setIfModifiedSince(long) in class URLConnection I-456 
setLabel
--------------------------------------
    void setLabel(String) in class Button II-11 
    void setLabel(String) in class Checkbox II-22 
    void setLabel(String) in class MenuItem II-196 
    void setLabel(String) in interface ButtonPeer II-318 
    void setLabel(String) in interface CheckboxPeer II-321 
    void setLabel(String) in interface MenuItemPeer II-341 
setLayout
--------------------------------------
    void setLayout(LayoutManager) in class Container II-75 
setLength
--------------------------------------
    void setLength(int) in class StringBuffer I-127 
setLineIncrement
--------------------------------------
    void setLineIncrement(int) in class Scrollbar II-215 
    void setLineIncrement(int) in interface ScrollbarPeer II-344 
setLineNumber
--------------------------------------
    void setLineNumber(int) in class LineNumberInputStream I-281 
setMaxPriority
--------------------------------------
    void setMaxPriority(int) in class ThreadGroup I-155 
setMenuBar
--------------------------------------
    void setMenuBar(MenuBar) in class Frame II-118 
    void setMenuBar(MenuBar) in interface FramePeer II-333 
setMinutes
--------------------------------------
    void setMinutes(int) in class Date I-366 
setMonth
--------------------------------------
    void setMonth(int) in class Date I-367 
setMultipleSelections
--------------------------------------
    void setMultipleSelections(boolean) in class List II-173 
    void setMultipleSelections(boolean) in interface ListPeer II-338 
setName
--------------------------------------
    void setName(String) in class Thread I-146 
setPageIncrement
--------------------------------------
    void setPageIncrement(int) in class Scrollbar II-215 
    void setPageIncrement(int) in interface ScrollbarPeer II-344 
setPaintMode
--------------------------------------
    void setPaintMode() in class Graphics II-137 
setPixels
--------------------------------------
    void setPixels(int, int, int, int, ColorModel, byte[], int, int) in class CropImageFilter II-258 
    void setPixels(int, int, int, int, ColorModel, byte[], int, int) in class ImageFilter II-271 
    void setPixels(int, int, int, int, ColorModel, byte[], int, int) in class PixelGrabber II-292 
    void setPixels(int, int, int, int, ColorModel, byte[], int, int) in class RGBImageFilter II-299 
    void setPixels(int, int, int, int, ColorModel, byte[], int, int) in interface ImageConsumer II-306 
    void setPixels(int, int, int, int, ColorModel, int[], int, int) in class CropImageFilter II-259 
    void setPixels(int, int, int, int, ColorModel, int[], int, int) in class ImageFilter II-272 
    void setPixels(int, int, int, int, ColorModel, int[], int, int) in class PixelGrabber II-293 
    void setPixels(int, int, int, int, ColorModel, int[], int, int) in class RGBImageFilter II-300 
    void setPixels(int, int, int, int, ColorModel, int[], int, int) in interface ImageConsumer II-307 
setPriority
--------------------------------------
    void setPriority(int) in class Thread I-146 
setProperties
    static void setProperties(Properties) in class System I-136 
    void setProperties(Hashtable) in class CropImageFilter II-259 
    void setProperties(Hashtable) in class ImageFilter II-272 
    void setProperties(Hashtable) in class PixelGrabber II-293 
    void setProperties(Hashtable) in interface ImageConsumer II-307 
setRequestProperty
--------------------------------------
    void setRequestProperty(String, String) in class URLConnection I-456 
setResizable
--------------------------------------
    void setResizable(boolean) in class Dialog II-79 
    void setResizable(boolean) in class Frame II-118 
    void setResizable(boolean) in interface DialogPeer II-331 
    void setResizable(boolean) in interface FramePeer II-333 
setSeconds
--------------------------------------
    void setSeconds(int) in class Date I-367 
setSecurityManager
--------------------------------------
    static void setSecurityManager(SecurityManager) in class System I-136 
setSeed
--------------------------------------
    void setSeed(long) in class Random I-385 
setSize
--------------------------------------
    void setSize(int) in class Vector I-399 
setSocketFactory
--------------------------------------
    static void setSocketFactory(SocketImplFactory) in class ServerSocket I-423 
setSocketImplFactory
--------------------------------------
    static void setSocketImplFactory(SocketImplFactory) in class Socket I-429 
setState
--------------------------------------
    void setState(boolean) in class Checkbox II-22 
    void setState(boolean) in class CheckboxMenuItem II-26 
    void setState(boolean) in interface CheckboxMenuItemPeer II-320 
    void setState(boolean) in interface CheckboxPeer II-321 
setStub
--------------------------------------
    void setStub(AppletStub) in class Applet 361 
setText
--------------------------------------
    void setText(String) in class Label II-163 
    void setText(String) in class TextComponent II-224 
    void setText(String) in interface LabelPeer II-335 
    void setText(String) in interface TextComponentPeer II-349 
setTime
--------------------------------------
    void setTime(long) in class Date I-367 
setTitle
--------------------------------------
    void setTitle(String) in class Dialog II-79 
    void setTitle(String) in class Frame II-119 
    void setTitle(String) in interface DialogPeer II-331 
    void setTitle(String) in interface FramePeer II-334 
setURL
--------------------------------------
    void setURL(URL, String, String, int, String, String) in class URLStreamHandler I-460 
setURLStreamHandlerFactory
--------------------------------------
    static void setURLStreamHandlerFactory(URLStreamHandlerFactory) in class URL I-441 
setUseCaches
--------------------------------------
    void setUseCaches(boolean) in class URLConnection I-456 
setValue
--------------------------------------
    void setValue(int) in class Scrollbar II-216 
    void setValue(int) in interface ScrollbarPeer II-344 
setValues
--------------------------------------
    void setValues(int, int, int, int) in class Scrollbar II-216 
    void setValues(int, int, int, int) in interface ScrollbarPeer II-345 
setXORMode
--------------------------------------
    void setXORMode(Color) in class Graphics II-137 
setYear
--------------------------------------
    void setYear(int) in class Date I-367 
SHIFT_MASK
--------------------------------------
    static int SHIFT_MASK in class Event II-89 
shiftDown
--------------------------------------
    boolean shiftDown() in class Event II-91 
show
--------------------------------------
    void show() in class Component II-66 
    void show() in class Window II-242 
    void show() in interface ComponentPeer II-329 
    void show(Container, String) in class CardLayout II-18 
showDocument
--------------------------------------
    void showDocument(URL) in interface AppletContext 365 
    void showDocument(URL, String) in interface AppletContext 366 
showStatus
--------------------------------------
    void showStatus(String) in class Applet 362 
    void showStatus(String) in interface AppletContext 366 
sin
--------------------------------------
    static double sin(double) in class Math I-67 
SINGLEFRAME
--------------------------------------
    static int SINGLEFRAME in interface ImageConsumer II-303 
SINGLEFRAMEDONE
--------------------------------------
    static int SINGLEFRAMEDONE in interface ImageConsumer II-303 
SINGLEPASS
--------------------------------------
    static int SINGLEPASS in interface ImageConsumer II-304 
size
--------------------------------------
    Dimension size() in class Component II-66 
    int size in class Font II-102 
    int size() in class BitSet I-358 
    int size() in class ByteArrayOutputStream I-224 
    int size() in class DataOutputStream I-238 
    int size() in class Dictionary I-371 
    int size() in class Hashtable I-377 
    int size() in class Vector I-399 
skip
--------------------------------------
    long skip(long) in class BufferedInputStream I-215 
    long skip(long) in class ByteArrayInputStream I-222 
    long skip(long) in class FileInputStream I-258 
    long skip(long) in class FilterInputStream I-268 
    long skip(long) in class InputStream I-277 
    long skip(long) in class LineNumberInputStream I-281 
    long skip(long) in class StringBufferInputStream I-331 
skipBytes
--------------------------------------
    int skipBytes(int) in class DataInputStream I-236 
    int skipBytes(int) in class RandomAccessFile I-315 
    int skipBytes(int) in interface DataInput I-339 
slashSlashComments
--------------------------------------
    void slashSlashComments(boolean) in class StreamTokenizer I-327 
slashStarComments
--------------------------------------
    void slashStarComments(boolean) in class StreamTokenizer I-328 
sleep
--------------------------------------
    static void sleep(long) in class Thread I-147 
    static void sleep(long, int) in class Thread I-147 
Socket
--------------------------------------
    Class in package java.net I-425 
    Socket(InetAddress, int) in class Socket I-426 
    Socket(InetAddress, int, boolean) in class Socket I-426 
    Socket(String, int) in class Socket I-427 
    Socket(String, int, boolean) in class Socket I-427 
SocketException
--------------------------------------
    Class in package java.net I-468 
    SocketException() in class SocketException I-468 
    SocketException(String) in class SocketException I-468 
SocketImpl
--------------------------------------
    Class in package java.net I-430 
    SocketImpl() in class SocketImpl I-431 
SocketImplFactory
--------------------------------------
    Interface in package java.net I-463 
SOMEBITS
--------------------------------------
    static int SOMEBITS in interface ImageObserver II-310 
SOUTH
--------------------------------------
    static int SOUTH in class GridBagConstraints II-143 
SOUTHEAST
--------------------------------------
    static int SOUTHEAST in class GridBagConstraints II-143 
SOUTHWEST
--------------------------------------
    static int SOUTHWEST in class GridBagConstraints II-143 
sqrt
--------------------------------------
    static double sqrt(double) in class Math I-68 
Stack
--------------------------------------
    Class in package java.util I-386 
    Stack() in class Stack I-386 
StackOverflowError
--------------------------------------
    Class in package java.lang I-201 
    StackOverflowError() in class StackOverflowError I-201 
    StackOverflowError(String) in class StackOverflowError I-201 
start
--------------------------------------
    void start() in class Applet 362 
    void start() in class Thread I-147 
startProduction
--------------------------------------
    void startProduction(ImageConsumer) in class FilteredImageSource II-267 
    void startProduction(ImageConsumer) in class MemoryImageSource II-286 
    void startProduction(ImageConsumer) in interface ImageProducer II-313 
startsWith
--------------------------------------
    boolean startsWith(String) in class String I-109 
    boolean startsWith(String, int) in class String I-109 
STATICIMAGEDONE
--------------------------------------
    static int STATICIMAGEDONE in interface ImageConsumer II-303 
status
--------------------------------------
    int status() in class PixelGrabber II-293 
statusAll
--------------------------------------
    int statusAll(boolean) in class MediaTracker II-181, II-182 
stop
--------------------------------------
    void stop() in class Applet 362 
    void stop() in class Thread I-148 
    void stop() in class ThreadGroup I-156 
    void stop() in interface AudioClip 369 
    void stop(Throwable) in class Thread I-149 
StreamTokenizer
--------------------------------------
    Class in package java.io I-322 
    StreamTokenizer(InputStream) in class StreamTokenizer I-324 
String
--------------------------------------
    Class in package java.lang I-98 
    String() in class String I-99 
    String(byte[], int) in class String I-100 
    String(byte[], int, int, int) in class String I-100 
    String(char[]) in class String I-100 
    String(char[], int, int) in class String I-101 
    String(String) in class String I-101 
    String(StringBuffer) in class String I-101 
StringBuffer
--------------------------------------
    Class in package java.lang I-115 
    StringBuffer() in class StringBuffer I-116 
    StringBuffer(int) in class StringBuffer I-116 
    StringBuffer(String) in class StringBuffer I-117 
StringBufferInputStream
--------------------------------------
    Class in package java.io I-329 
    StringBufferInputStream(String) in class StringBufferInputStream I-330 
StringIndexOutOfBoundsException
--------------------------------------
    Class in package java.lang I-186 
    StringIndexOutOfBoundsException() in class StringIndexOutOfBoundsException I-186 
    StringIndexOutOfBoundsException(int) in class StringIndexOutOfBoundsException I-186 
    StringIndexOutOfBoundsException(String) in class StringIndexOutOfBoundsException I-186 
StringTokenizer
--------------------------------------
    Class in package java.util I-388 
    StringTokenizer(String) in class StringTokenizer I-389 
    StringTokenizer(String, String) in class StringTokenizer I-389 
    StringTokenizer(String, String, boolean) in class StringTokenizer I-389 
stringWidth
--------------------------------------
    int stringWidth(String) in class FontMetrics II-113 
style
--------------------------------------
    int style in class Font II-103 
substituteColorModel
--------------------------------------
    void substituteColorModel(ColorModel, ColorModel) in class RGBImageFilter II-300 
substring
--------------------------------------
    String substring(int) in class String I-109 
    String substring(int, int) in class String I-110 
suspend
--------------------------------------
    void suspend() in class Thread I-149 
    void suspend() in class ThreadGroup I-156 
sval
--------------------------------------
    String sval in class StreamTokenizer I-323 
SW_RESIZE_CURSOR
--------------------------------------
    static int SW_RESIZE_CURSOR in class Frame II-116 
sync
--------------------------------------
    void sync() in class Toolkit II-239 
System
--------------------------------------
    Class in package java.lang I-129 

T
--------------------------------------

tan
--------------------------------------
    static double tan(double) in class Math I-68 
target
--------------------------------------
    Object target in class Event II-84 
TEXT_CURSOR
--------------------------------------
    static int TEXT_CURSOR in class Frame II-116 
TextArea
--------------------------------------
    Class in package java.awt II-217 
    TextArea() in class TextArea II-218 
    TextArea(int, int) in class TextArea II-218 
    TextArea(String) in class TextArea II-218 
    TextArea(String, int, int) in class TextArea II-218 
TextAreaPeer
--------------------------------------
    Interface in package java.awt.peer II-346 
TextComponent
--------------------------------------
    Class in package java.awt II-222 
TextComponentPeer
--------------------------------------
    Interface in package java.awt.peer II-348 
TextField
--------------------------------------
    Class in package java.awt II-225 
    TextField() in class TextField II-226 
    TextField(int) in class TextField II-226 
    TextField(String) in class TextField II-227 
    TextField(String, int) in class TextField II-227 
TextFieldPeer
--------------------------------------
    Interface in package java.awt.peer II-350 
Thread
--------------------------------------
    Class in package java.lang I-137 
    Thread() in class Thread I-140 
    Thread(Runnable) in class Thread I-140 
    Thread(Runnable, String) in class Thread I-140 
    Thread(String) in class Thread I-140 
    Thread(ThreadGroup, Runnable) in class Thread I-141 
    Thread(ThreadGroup, Runnable, String) in class Thread I-141 
    Thread(ThreadGroup, String) in class Thread I-142 
ThreadDeath
--------------------------------------
    Class in package java.lang I-202 
    ThreadDeath() in class ThreadDeath I-202 
ThreadGroup
--------------------------------------
    Class in package java.lang I-150 
    ThreadGroup(String) in class ThreadGroup I-151 
    ThreadGroup(ThreadGroup, String) in class ThreadGroup I-151 
Throwable
--------------------------------------
    Class in package java.lang I-158 
    Throwable() in class Throwable I-158 
    Throwable(String) in class Throwable I-159 
toBack
--------------------------------------
    void toBack() in class Window II-242 
    void toBack() in interface WindowPeer II-351 
toBinaryString
--------------------------------------
    static String toBinaryString(int) in class Integer I-46 
    static String toBinaryString(long) in class Long I-56 
toByteArray
--------------------------------------
    byte toByteArray()[] in class ByteArrayOutputStream I-224 
toCharArray
--------------------------------------
    char toCharArray()[] in class String I-110 
toExternalForm
--------------------------------------
    String toExternalForm() in class URL I-441 
    String toExternalForm(URL) in class URLStreamHandler I-460 
toFront
--------------------------------------
    void toFront() in class Window II-242 
    void toFront() in interface WindowPeer II-351 
toGMTString
--------------------------------------
    String toGMTString() in class Date I-367 
toHexString
--------------------------------------
    static String toHexString(int) in class Integer I-47 
    static String toHexString(long) in class Long I-56 
toLocaleString
--------------------------------------
    String toLocaleString() in class Date I-368 
toLowerCase
--------------------------------------
    static char toLowerCase(char) in class Character I-16, I-17 
    String toLowerCase() in class String I-110 
toOctalString
--------------------------------------
    static String toOctalString(int) in class Integer I-47 
    static String toOctalString(long) in class Long I-57 
Toolkit
--------------------------------------
    Class in package java.awt II-231 
    Toolkit() in class Toolkit II-232 
top
--------------------------------------
    int top in class Insets II-159 
TOPDOWNLEFTRIGHT
--------------------------------------
    static int TOPDOWNLEFTRIGHT in interface ImageConsumer II-304 
toString
--------------------------------------
    static String toString(double) in class Double I-33 
    static String toString(int) in class Integer I-48 
    static String toString(int, int) in class Integer I-48 
    static String toString(long) in class Long I-57 
    static String toString(long, int) in class Long I-58 
    String toString() in class BitSet I-358 
    String toString() in class Boolean I-6 
    String toString() in class BorderLayout II-8 
    String toString() in class ByteArrayOutputStream I-224 
    String toString() in class CardLayout II-18 
    String toString() in class Character I-16 
    String toString() in class CheckboxGroup II-24 
    String toString() in class Class I-20 
    String toString() in class Color II-38 
    String toString() in class Component II-66 
    String toString() in class Date I-368 
    String toString() in class Dimension II-81 
    String toString() in class Double I-32 
    String toString() in class Event II-92 
    String toString() in class File I-251 
    String toString() in class Float I-39 
    String toString() in class FlowLayout II-101 
    String toString() in class Font II-107 
    String toString() in class FontMetrics II-113 
    String toString() in class Graphics II-138 
    String toString() in class GridBagLayout II-150 
    String toString() in class GridLayout II-155 
    String toString() in class Hashtable I-377 
    String toString() in class InetAddress I-420 
    String toString() in class Insets II-160 
    String toString() in class Integer I-47 
    String toString() in class Long I-57 
    String toString() in class MenuComponent II-193 
    String toString() in class Object I-73 
    String toString() in class Point II-199 
    String toString() in class Rectangle II-208 
    String toString() in class ServerSocket I-424 
    String toString() in class Socket I-429 
    String toString() in class SocketImpl I-434 
    String toString() in class StreamTokenizer I-328 
    String toString() in class String I-110 
    String toString() in class StringBuffer I-128 
    String toString() in class Thread I-149 
    String toString() in class ThreadGroup I-156 
    String toString() in class Throwable I-160 
    String toString() in class URL I-442 
    String toString() in class URLConnection I-456 
    String toString() in class Vector I-399 
    String toString(float) in class Float I-39 
    String toString(int) in class ByteArrayOutputStream I-225 
totalMemory
--------------------------------------
    long totalMemory() in class Runtime I-84 
toTitleCase
--------------------------------------
    static char toTitleCase(char) in class Character I-17 
toUpperCase
--------------------------------------
    static char toUpperCase(char) in class Character I-17 
    String toUpperCase() in class String I-111 
traceInstructions
--------------------------------------
    void traceInstructions(boolean) in class Runtime I-84 
traceMethodCalls
--------------------------------------
    void traceMethodCalls(boolean) in class Runtime I-84 
translate
--------------------------------------
    void translate(int, int) in class Event II-92 
    void translate(int, int) in class Graphics II-138 
    void translate(int, int) in class Point II-200 
    void translate(int, int) in class Rectangle II-208 
trim
--------------------------------------
    String trim() in class String I-111 
trimToSize
--------------------------------------
    void trimToSize() in class Vector I-399 
TRUE
--------------------------------------
    static Boolean TRUE in class Boolean I-4 
TT_EOF
--------------------------------------
    static int TT_EOF in class StreamTokenizer I-324 
TT_EOL
--------------------------------------
    static int TT_EOL in class StreamTokenizer I-324 
TT_NUMBER
--------------------------------------
    static int TT_NUMBER in class StreamTokenizer I-324 
TT_WORD
--------------------------------------
    static int TT_WORD in class StreamTokenizer I-324 
ttype
--------------------------------------
    int ttype in class StreamTokenizer I-323 

U
--------------------------------------

uncaughtException
--------------------------------------
    void uncaughtException(Thread, Throwable) in class ThreadGroup I-156 
UndefinedProperty
--------------------------------------
    static Object UndefinedProperty in class Image II-156 
union
--------------------------------------
    Rectangle union(Rectangle) in class Rectangle II-209 
UnknownError
--------------------------------------
    Class in package java.lang I-203 
    UnknownError() in class UnknownError I-203 
    UnknownError(String) in class UnknownError I-203 
UnknownHostException
--------------------------------------
    Class in package java.net I-469 
    UnknownHostException() in class UnknownHostException I-469 
    UnknownHostException(String) in class UnknownHostException I-469 
UnknownServiceException
--------------------------------------
    Class in package java.net I-470 
    UnknownServiceException() in class UnknownServiceException I-470 
    UnknownServiceException(String) in class UnknownServiceException I-470 
unread
--------------------------------------
    void unread(int) in class PushbackInputStream I-302 
UnsatisfiedLinkError
--------------------------------------
    Class in package java.lang I-204 
    UnsatisfiedLinkError() in class UnsatisfiedLinkError I-204 
    UnsatisfiedLinkError(String) in class UnsatisfiedLinkError I-204 
UP
--------------------------------------
    static int UP in class Event II-89 
update
--------------------------------------
    void update(Graphics) in class Component II-67 
    void update(Observable, Object) in interface Observer I-403 
URL
--------------------------------------
    Class in package java.net I-435 
    URL(String) in class URL I-436 
    URL(String, String, int, String) in class URL I-437 
    URL(String, String, String) in class URL I-438 
    URL(URL, String) in class URL I-438 
url
--------------------------------------
    URL url in class URLConnection I-447 
URLConnection
--------------------------------------
    Class in package java.net I-443 
    URLConnection(URL) in class URLConnection I-447 
URLEncoder
--------------------------------------
    Class in package java.net I-457 
URLStreamHandler
--------------------------------------
    Class in package java.net I-458 
    URLStreamHandler() in class URLStreamHandler I-458 
URLStreamHandlerFactory
--------------------------------------
    Interface in package java.net I-464 
useCaches
--------------------------------------
    boolean useCaches in class URLConnection I-447 
UTC
--------------------------------------
    static long UTC(int, int, int, int, int, int) in class Date I-368 
UTFDataFormatException
--------------------------------------
    Class in package java.io I-352 
    UTFDataFormatException() in class UTFDataFormatException I-352 
    UTFDataFormatException(String) in class UTFDataFormatException I-352 

V
--------------------------------------

valid
--------------------------------------
    boolean valid() in class FileDescriptor I-253 
validate
--------------------------------------
    void validate() in class Component II-67 
    void validate() in class Container II-76 
valueOf
--------------------------------------
    static Boolean valueOf(String) in class Boolean I-6 
    static Double valueOf(String) in class Double I-33 
    static Float valueOf(String) in class Float I-40 
    static Integer valueOf(String) in class Integer I-48 
    static Integer valueOf(String, int) in class Integer I-49 
    static Long valueOf(String) in class Long I-58 
    static Long valueOf(String, int) in class Long I-58 
    static String valueOf(boolean) in class String I-111 
    static String valueOf(char) in class String I-111 
    static String valueOf(char[]) in class String I-112 
    static String valueOf(char[], int, int) in class String I-112 
    static String valueOf(double) in class String I-112 
    static String valueOf(float) in class String I-113 
    static String valueOf(int) in class String I-113 
    static String valueOf(long) in class String I-113 
    static String valueOf(Object) in class String I-114 
Vector
--------------------------------------
    Class in package java.util I-392 
    Vector() in class Vector I-393 
    Vector(int) in class Vector I-393 
    Vector(int, int) in class Vector I-394 
VerifyError
--------------------------------------
    Class in package java.lang I-205 
    VerifyError() in class VerifyError I-205 
    VerifyError(String) in class VerifyError I-205 
VERTICAL
--------------------------------------
    static int VERTICAL in class GridBagConstraints II-144 
    static int VERTICAL in class Scrollbar II-212 
VirtualMachineError
--------------------------------------
    Class in package java.lang I-206 
    VirtualMachineError() in class VirtualMachineError I-206 
    VirtualMachineError(String) in class VirtualMachineError I-206 

W
--------------------------------------

W_RESIZE_CURSOR
--------------------------------------
    static int W_RESIZE_CURSOR in class Frame II-116 
wait
--------------------------------------
    void wait() in class Object I-74 
    void wait(long) in class Object I-74 
    void wait(long, int) in class Object I-75 
WAIT_CURSOR
--------------------------------------
    static int WAIT_CURSOR in class Frame II-116 
waitFor
--------------------------------------
    int waitFor() in class Process I-77 
waitForAll
--------------------------------------
    boolean waitForAll(long) in class MediaTracker II-183 
    void waitForAll() in class MediaTracker II-182 
	
waitForID
--------------------------------------
    boolean waitForID(int, long) in class MediaTracker II-184 
	
    void waitForID(int) in class MediaTracker II-183 

weightx
--------------------------------------
    double weightx in class GridBagConstraints II-142 
	
weighty
--------------------------------------
    double weighty in class GridBagConstraints II-142 
	
WEST
--------------------------------------
    static int WEST in class GridBagConstraints II-143 
	
when
--------------------------------------
    long when in class Event II-84 
	
white
--------------------------------------
    static Color white in class Color II-33 
	
whitespaceChars
--------------------------------------
    void whitespaceChars(int, int) in class StreamTokenizer I-328 
	
WIDTH
--------------------------------------
    static int WIDTH in interface ImageObserver II-310 
	
width
--------------------------------------
    int width in class Dimension II-80 
	
    int width in class Rectangle II-204 
	
Window
--------------------------------------
    Class in package java.awt II-240 
	
    Window(Frame) in class Window II-240 
	
WINDOW_DEICONIFY
--------------------------------------
    static int WINDOW_DEICONIFY in class Event II-87 
	
WINDOW_DESTROY
--------------------------------------
    static int WINDOW_DESTROY in class Event II-87 
	
WINDOW_EXPOSE
--------------------------------------
    static int WINDOW_EXPOSE in class Event II-87 
	
WINDOW_ICONIFY
--------------------------------------
    static int WINDOW_ICONIFY in class Event II-87 
	
WINDOW_MOVED
--------------------------------------
    static int WINDOW_MOVED in class Event II-87 
	
WindowPeer
--------------------------------------
    Interface in package java.awt.peer II-351 

wordChars
--------------------------------------
    void wordChars(int, int) in class StreamTokenizer I-328 
	
	
write
--------------------------------------
    void write(byte[]) in class FileOutputStream I-261 
	
    void write(byte[]) in class FilterOutputStream I-271 
	
    void write(byte[]) in class OutputStream I-283 
	
    void write(byte[]) in class RandomAccessFile I-315 
	
    void write(byte[]) in interface DataOutput I-340 
	
    void write(byte[], int, int) in class BufferedOutputStream I-217 
	
    void write(byte[], int, int) in class ByteArrayOutputStream I-225 
	
    void write(byte[], int, int) in class DataOutputStream I-239 
	
    void write(byte[], int, int) in class FileOutputStream I-262 
	
    void write(byte[], int, int) in class FilterOutputStream I-271 
	
    void write(byte[], int, int) in class OutputStream I-283 
	
    void write(byte[], int, int) in class PipedOutputStream I-289 
	
    void write(byte[], int, int) in class PrintStream I-297 
	
    void write(byte[], int, int) in class RandomAccessFile I-315 
	
    void write(byte[], int, int) in interface DataOutput I-341 
	
    void write(int) in class BufferedOutputStream I-218 
	
    void write(int) in class ByteArrayOutputStream I-225 
	
    void write(int) in class DataOutputStream I-239 
	
    void write(int) in class FileOutputStream I-262 
	
    void write(int) in class FilterOutputStream I-272 
	
    void write(int) in class OutputStream I-284 
	
    void write(int) in class PipedOutputStream I-290 
	
    void write(int) in class PrintStream I-298 
	
    void write(int) in class RandomAccessFile I-316 
	
    void write(int) in interface DataOutput I-341 

	
writeBoolean
--------------------------------------
    void writeBoolean(boolean) in class DataOutputStream I-239 
	
    void writeBoolean(boolean) in class RandomAccessFile I-316 
	
    void writeBoolean(boolean) in interface DataOutput I-341 
	
writeByte
--------------------------------------
    void writeByte(int) in class DataOutputStream I-240 
	
    void writeByte(int) in class RandomAccessFile I-316 
	
    void writeByte(int) in interface DataOutput I-341 
	
writeBytes
--------------------------------------
    void writeBytes(String) in class DataOutputStream I-240 
	
    void writeBytes(String) in class RandomAccessFile I-316 
	
    void writeBytes(String) in interface DataOutput I-342 

	
writeChar
--------------------------------------
    void writeChar(int) in class DataOutputStream I-240 
	
    void writeChar(int) in class RandomAccessFile I-317 
	
    void writeChar(int) in interface DataOutput I-342 
	
writeChars
--------------------------------------
    void writeChars(String) in class DataOutputStream I-240 
    void writeChars(String) in class RandomAccessFile I-317 
    void writeChars(String) in interface DataOutput I-342 
writeDouble
--------------------------------------
    void writeDouble(double) in class DataOutputStream I-241 
	
    void writeDouble(double) in class RandomAccessFile I-317 
	
    void writeDouble(double) in interface DataOutput I-342 


	
writeFloat
--------------------------------------
    void writeFloat(float) in class DataOutputStream I-241 
	
    void writeFloat(float) in class RandomAccessFile I-317 
	
    void writeFloat(float) in interface DataOutput I-343 

	
writeInt
--------------------------------------
    void writeInt(int) in class DataOutputStream I-241 
	
    void writeInt(int) in class RandomAccessFile I-318 
	
    void writeInt(int) in interface DataOutput I-343 

	
writeLong
--------------------------------------
    void writeLong(long) in class DataOutputStream I-242 
	
    void writeLong(long) in class RandomAccessFile I-318 
	
    void writeLong(long) in interface DataOutput I-343 


	
writeShort
--------------------------------------
    void writeShort(int) in class DataOutputStream I-242 
	
    void writeShort(int) in class RandomAccessFile I-318 
	
    void writeShort(int) in interface DataOutput I-343 


	
writeTo
--------------------------------------
    void writeTo(OutputStream) in class ByteArrayOutputStream I-225 


	
writeUTF
--------------------------------------
    void writeUTF(String) in class DataOutputStream I-242 
	
    void writeUTF(String) in class RandomAccessFile I-318 
	
    void writeUTF(String) in interface DataOutput I-344 


	
written
--------------------------------------
    int written in class DataOutputStream I-237 
	

X
--------------------------------------

x
--------------------------------------
    int x in class Event II-84 
	
    int x in class Point II-198 
	
    int x in class Rectangle II-204 

	
xor
--------------------------------------
    void xor(BitSet) in class BitSet I-359 
	
xpoints
--------------------------------------
    int xpoints[] in class Polygon II-201 
	

Y
--------------------------------------


y
--------------------------------------
    int y in class Event II-84 
	
    int y in class Point II-198 
	
    int y in class Rectangle II-204 
	
yellow
--------------------------------------
    static Color yellow in class Color II-33 
	
yield
--------------------------------------
    static void yield() in class Thread I-149 
	
ypoints
--------------------------------------
    int ypoints[] in class Polygon II-201 









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


