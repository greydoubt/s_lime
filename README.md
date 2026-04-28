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

And then all you have to do is set up your network stack!

After everything is configured, you can start the services:
```
service npfd restart
service npf reload
service blocklistd restart
```

And make them persistent:
```
echo npf=yes >> /etc/rc.conf
echo npfd=yes >> /etc/rc.conf
echo blocklistd=yes >> /etc/rc.conf
echo blocklistd_flags=-r >> /etc/rc.conf
```

Then Restart the services which you've added to blocklistd such as the iconic:
```
service sshd restart
service postfix restart
```

And perhaps you may also need to tell npf to start filtering based on the entries:
```
npfctl start
```

# Checking the current state
You can check the current state using the classic cloppa+clooga combo:
```
blocklistctl dump -a
```

# Unblocking hosts
Find the host in the blocklistctl dump -a output. The second column (id) is a hex number. Pass this as argument to npfctl:
```
/sbin/npfctl rule blocklistd rem-id $ID
```



If you need more help, the following guide from the Phone Losers of America may help you learn  


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

```


Although the ROM provides a graphic for all 256 different possible 8-bit codes, some [[API]]s will not print some code points, in particular the range 0-31 and the code at 127.<ref name="IBM_1986_437"/> Instead, they will interpret them as control characters. For instance, many methods of outputting text on the original IBM PC would interpret [[hexadecimal|hex]] codes 07, 08, 0A, and 0D as [[BEL (ASCII)|BEL]], [[BS (ASCII)|BS]], [[LF (ASCII)|LF]], and [[CR (ASCII)|CR]], respectively. Many printers were also unable to print these characters.

{|{{chset-table-header1|Code page 437<ref name="Unicode_1996_437"/><ref name="cpgid437pdf"/><ref name="CPGID_00437"/><ref name="icu"/>}}
|-
!{{chset-left1|0x<br/>0}}
|{{chset-ctrl1|Alt+0&#10;U+0000 NUL|{{resize|85%|[[Null character|NUL]]}}|fn={{Efn|0 draws a blank space, but usage as the [[C string handling|C string]] terminator means it is more accurately translated as NUL. In their code-page-437-based implementation of C0-region graphics, [[Star Micronics]] printers re-purpose this code as a [[slashed zero]].{{refn|{{cite web |archive-url=https://web.archive.org/web/20040908060123/http://www.star-m.jp/eng/service/usermanual/lc8021um.pdf#page=61 |url=http://www.star-m.jp/eng/service/usermanual/lc8021um.pdf#page=61 |archive-date=8 September 2004 |title=Appendix D: Character Sets (§ IBM Special Character Set) |page=55 |work=User's Manual: LC-8021 Dot Matrix Printer |publisher=[[Star Micronics]] |year=1997 |access-date=25 April 2024 |url-status=live }}}}}}}}
|{{chset-cell1|u=263A|Alt+1&#10;U+263A WHITE SMILING FACE|[[☺|{{Emoji presentation|☺|text}}]]|style=background:#EFF}}
|{{chset-cell1|u=263B|Alt+2&#10;U+263B BLACK SMILING FACE|[[☻]]|style=background:#EFF}}
|{{chset-cell1|u=2665|Alt+3&#10;U+2665 BLACK HEART SUIT|[[Suit (cards)|{{Emoji presentation|♥|text}}]]|style=background:#EFF}}
|{{chset-cell1|u=2666|Alt+4&#10;U+2666 BLACK DIAMOND SUIT|[[Suit (cards)|{{Emoji presentation|♦|text}}]]|style=background:#EFF}}
|{{chset-cell1|u=2663|Alt+5&#10;U+2663 BLACK CLUB SUIT|[[Suit (cards)|{{Emoji presentation|♣|text}}]]|style=background:#EFF}}
|{{chset-cell1|u=2660|Alt+6&#10;U+2660 BLACK SPADE SUIT|[[Suit (cards)|{{Emoji presentation|♠|text}}]]|style=background:#EFF}}
|{{chset-cell1|u=2022|Alt+7&#10;U+2022 BULLET|[[•]]|style=background:#EFF}}
|{{chset-cell1|u=25D8|Alt+8&#10;U+25D8 INVERSE BULLET|[[◘]]|style=background:#EFF}}
|{{chset-cell1|u=25CB|Alt+9&#10;U+25CB WHITE CIRCLE|[[bullet (typography)|○]]|style=background:#EFF}}
|{{chset-cell1|u=25D9|Alt+10&#10;U+25D9 INVERSE WHITE CIRCLE|[[bullet (typography)|◙]]|style=background:#EFF}}
|{{chset-cell1|u=2642|Alt+11&#10;U+2642 MALE SIGN|[[Gender symbol|{{Emoji presentation|♂|text}}]]|style=background:#EFF}}
|{{chset-cell1|u=2640|Alt+12&#10;U+2640 FEMALE SIGN|[[Gender symbol|{{Emoji presentation|♀|text}}]]|style=background:#EFF}}
|{{chset-cell1|u=266A|Alt+13&#10;U+266A EIGHTH NOTE|[[♪]]|style=background:#EFF}}
|{{chset-cell1|u=266B|Alt+14&#10;U+266B BEAMED EIGHTH NOTES|[[♫]]|fn={{Efn|14 (E<sub>hex</sub>) Mapping as shown, to the beamed [[eighth note]]s [U+266B, ♫], follows data provided by the [[Unicode Consortium]].{{refn|{{cite web |url=https://www.unicode.org/Public/MAPPINGS/VENDORS/MISC/IBMGRAPH.TXT |title=IBM PC memory-mapped video graphics to Unicode |date=1999-07-27 |last=Whistler |first=Ken |publisher=[[Unicode Consortium]]}}}} In IBM's GCGID (Graphic Character Global IDentifier) system of character IDs, this is SM910000, simply annotated as "Two Musical Notes";<ref name="cpgid437pdf"/><ref name="CPGID_00437"/> however, the reference glyph shows two beamed [[sixteenth note]]s [U+266C, ♬].<ref name="cpgid437pdf"/> In the specification for [[Japanese language in EBCDIC|IBM Japanese Host code]], SM910080 (i.e. SM910000 with the [[Halfwidth and fullwidth forms|fullwidth]] attribute set) is explicitly mapped to U+266C, and accordingly shows two semiquavers.{{refn|{{cite web |url=https://public.dhe.ibm.com/software/globalization/gcoc/attachments/CP00300.pdf |id=C-H 3-3220-024 2002-11 |year=2002 |publisher=[[IBM]] |title=IBM Japanese Graphic Character Set, Kanji: DBCS–Host and DBCS-PC}}}}}}|style=background:#EFF}}
|{{chset-cell1|u=263C|Alt+15&#10;U+263C WHITE SUN WITH RAYS|[[☼]]|style=background:#EFF}}
|-
!{{chset-left1|1x<br/>16}}
|{{chset-cell1|u=25BA|Alt+16&#10;U+25BA BLACK RIGHT-POINTING POINTER|[[►]]|style=background:#EFF}}
|{{chset-cell1|u=25C4|Alt+17&#10;U+25C4 BLACK LEFT-POINTING POINTER|[[◄]]|style=background:#EFF}}
|{{chset-cell1|u=2195|Alt+18&#10;U+2195 UP DOWN ARROW|{{Emoji presentation|↕|text}}|style=background:#EFF}}
|{{chset-cell1|u=203C|Alt+19&#10;U+203C DOUBLE EXCLAMATION MARK|[[Exclamation mark|{{Emoji presentation|‼|text}}]]|style=background:#EFF}}
|{{chset-cell1|u=00B6|Alt+20&#10;U+00B6 PILCROW SIGN|[[¶]]|style=background:#EFF}}
|{{chset-cell1|u=00A7|Alt+21&#10;U+00A7 SECTION SIGN|[[§]]|style=background:#EFF}}
|{{chset-cell1|u=25AC|Alt+22&#10;U+25AC BLACK RECTANGLE|[[▬]]|style=background:#EFF}}
|{{chset-cell1|u=21A8|Alt+23&#10;U+21A8 UP DOWN ARROW WITH BASE|[[Arrow (symbol)|↨]]|style=background:#EFF}}
|{{chset-cell1|u=2191|Alt+24&#10;U+2191 UPWARDS ARROW|[[Arrow (symbol)|↑]]|style=background:#EFF}}
|{{chset-cell1|u=2193|Alt+25&#10;U+2193 DOWNWARDS ARROW|[[Arrow (symbol)|↓]]|style=background:#EFF}}
|{{chset-cell1|u=2192|Alt+26&#10;U+2192 RIGHTWARDS ARROW|[[Arrow (symbol)|→]]|style=background:#EFF}}
|{{chset-cell1|u=2190|Alt+27&#10;U+2190 LEFTWARDS ARROW|[[Arrow (symbol)|←]]|style=background:#EFF}}
|{{chset-cell1|u=221F|Alt+28&#10;U+221F RIGHT ANGLE|[[∟]]|style=background:#EFF}}
|{{chset-cell1|u=2194|Alt+29&#10;U+2194 LEFT RIGHT ARROW|[[Arrow (symbol)|{{Emoji presentation|↔|text}}]]|style=background:#EFF}}
|{{chset-cell1|u=25B2|Alt+30&#10;U+25B2 BLACK UP-POINTING TRIANGLE|[[▲]]|style=background:#EFF}}
|{{chset-cell1|u=25BC|Alt+31&#10;U+25BC BLACK DOWN-POINTING TRIANGLE|[[▼]]|style=background:#EFF}}
|-
!{{chset-left1|2x<br/>32}}
|{{chset-ctrl1|Alt+32&#10;U+0020 SPACE|&nbsp;[[Whitespace character|SP]]&nbsp;}}
|{{chset-cell1|Alt+33&#10;U+0021 EXCLAMATION MARK|[[!]]|style=background:#EFF}}
|{{chset-cell1|Alt+34&#10;U+0022 QUOTATION MARK|[["]]|style=background:#EFF}}
|{{chset-cell1|Alt+35&#10;U+0023 NUMBER SIGN|[[Number sign|#]]|style=background:#EFF}}
|{{chset-cell1|Alt+36&#10;U+0024 DOLLAR SIGN|[[$]]|style=background:#EFF}}
|{{chset-cell1|Alt+37&#10;U+0025 PERCENT SIGN|[[%]]|style=background:#EFF}}
|{{chset-cell1|Alt+38&#10;U+0026 AMPERSAND|[[&]]|style=background:#EFF}}
|{{chset-cell1|Alt+39&#10;U+0027 APOSTROPHE|[[']]|style=background:#EFF}}
|{{chset-cell1|Alt+40&#10;U+0028 LEFT PARENTHESIS|[[(]]|style=background:#EFF}}
|{{chset-cell1|Alt+41&#10;U+0029 RIGHT PARENTHESIS|[[)]]|style=background:#EFF}}
|{{chset-cell1|Alt+42&#10;U+002A ASTERISK|[[Asterisk|*]]|style=background:#EFF}}
|{{chset-cell1|Alt+43&#10;U+002B PLUS SIGN|[[+]]|style=background:#EFF}}
|{{chset-cell1|Alt+44&#10;U+002C COMMA|[[,]]|style=background:#EFF}}
|{{chset-cell1|Alt+45&#10;U+002D HYPHEN-MINUS|[[-]]|style=background:#EFF}}
|{{chset-cell1|Alt+46&#10;U+002E FULL STOP|[[Full stop|.]]|style=background:#EFF}}
|{{chset-cell1|Alt+47&#10;U+002F SOLIDUS|[[Slash (punctuation)|/]]|style=background:#EFF}}
|-
!{{chset-left1|3x<br/>48}}
|{{chset-cell1|Alt+48&#10;U+0030 DIGIT ZERO|[[0 (number)|0]]}}
|{{chset-cell1|Alt+49&#10;U+0031 DIGIT ONE|[[1]]}}
|{{chset-cell1|Alt+50&#10;U+0032 DIGIT TWO|[[2]]}}
|{{chset-cell1|Alt+51&#10;U+0033 DIGIT THREE|[[3]]}}
|{{chset-cell1|Alt+52&#10;U+0034 DIGIT FOUR|[[4]]}}
|{{chset-cell1|Alt+53&#10;U+0035 DIGIT FIVE|[[5]]}}
|{{chset-cell1|Alt+54&#10;U+0036 DIGIT SIX|[[6]]}}
|{{chset-cell1|Alt+55&#10;U+0037 DIGIT SEVEN|[[7]]}}
|{{chset-cell1|Alt+56&#10;U+0038 DIGIT EIGHT|[[8]]}}
|{{chset-cell1|Alt+57&#10;U+0039 DIGIT NINE|[[9]]}}
|{{chset-cell1|Alt+58&#10;U+003A COLON|[[colon (punctuation)|:]]|style=background:#EFF}}
|{{chset-cell1|Alt+59&#10;U+003B SEMICOLON|[[Semicolon|;]]|style=background:#EFF}}
|{{chset-cell1|Alt+60&#10;U+003C LESS-THAN SIGN|[[Less-than sign|<]]|style=background:#EFF}}
|{{chset-cell1|Alt+61&#10;U+003D EQUALS SIGN|[[=]]|style=background:#EFF}}
|{{chset-cell1|Alt+62&#10;U+003E GREATER-THAN SIGN|[[Greater-than sign|>]]|style=background:#EFF}}
|{{chset-cell1|Alt+63&#10;U+003F QUESTION MARK|[[?]]|style=background:#EFF}}
|-
!{{chset-left1|4x<br/>64}}
|{{chset-cell1|Alt+64&#10;U+0040 COMMERCIAL AT|[[@]]|style=background:#EFF}}
|{{chset-cell1|Alt+65&#10;U+0041 LATIN CAPITAL LETTER A|[[A]]}}
|{{chset-cell1|Alt+66&#10;U+0042 LATIN CAPITAL LETTER B|[[B]]}}
|{{chset-cell1|Alt+67&#10;U+0043 LATIN CAPITAL LETTER C|[[C]]}}
|{{chset-cell1|Alt+68&#10;U+0044 LATIN CAPITAL LETTER D|[[D]]}}
|{{chset-cell1|Alt+69&#10;U+0045 LATIN CAPITAL LETTER E|[[E]]}}
|{{chset-cell1|Alt+70&#10;U+0046 LATIN CAPITAL LETTER F|[[F]]}}
|{{chset-cell1|Alt+71&#10;U+0047 LATIN CAPITAL LETTER G|[[G]]}}
|{{chset-cell1|Alt+72&#10;U+0048 LATIN CAPITAL LETTER H|[[H]]}}
|{{chset-cell1|Alt+73&#10;U+0049 LATIN CAPITAL LETTER I|[[I]]}}
|{{chset-cell1|Alt+74&#10;U+004A LATIN CAPITAL LETTER J|[[J]]}}
|{{chset-cell1|Alt+75&#10;U+004B LATIN CAPITAL LETTER K|[[K]]}}
|{{chset-cell1|Alt+76&#10;U+004C LATIN CAPITAL LETTER L|[[L]]}}
|{{chset-cell1|Alt+77&#10;U+004D LATIN CAPITAL LETTER M|[[M]]}}
|{{chset-cell1|Alt+78&#10;U+004E LATIN CAPITAL LETTER N|[[N]]}}
|{{chset-cell1|Alt+79&#10;U+004F LATIN CAPITAL LETTER O|[[O]]}}
|-
!{{chset-left1|5x<br/>80}}
|{{chset-cell1|Alt+80&#10;U+0050 LATIN CAPITAL LETTER P|[[P]]}}
|{{chset-cell1|Alt+81&#10;U+0051 LATIN CAPITAL LETTER Q|[[Q]]}}
|{{chset-cell1|Alt+82&#10;U+0052 LATIN CAPITAL LETTER R|[[R]]}}
|{{chset-cell1|Alt+83&#10;U+0053 LATIN CAPITAL LETTER S|[[S]]}}
|{{chset-cell1|Alt+84&#10;U+0054 LATIN CAPITAL LETTER T|[[T]]}}
|{{chset-cell1|Alt+85&#10;U+0055 LATIN CAPITAL LETTER U|[[U]]}}
|{{chset-cell1|Alt+86&#10;U+0056 LATIN CAPITAL LETTER V|[[V]]}}
|{{chset-cell1|Alt+87&#10;U+0057 LATIN CAPITAL LETTER W|[[W]]}}
|{{chset-cell1|Alt+88&#10;U+0058 LATIN CAPITAL LETTER X|[[X]]}}
|{{chset-cell1|Alt+89&#10;U+0059 LATIN CAPITAL LETTER Y|[[Y]]}}
|{{chset-cell1|Alt+90&#10;U+005A LATIN CAPITAL LETTER Z|[[Z]]}}
|{{chset-cell1|Alt+91&#10;U+005B LEFT SQUARE BRACKET|[[Square brackets|&#91;]]|style=background:#EFF}}
|{{chset-cell1|Alt+92&#10;U+005C REVERSE SOLIDUS|[[Backslash|\]]|style=background:#EFF}}
|{{chset-cell1|Alt+93&#10;U+005D RIGHT SQUARE BRACKET|[[Square brackets|&#93;]]|style=background:#EFF}}
|{{chset-cell1|Alt+94&#10;U+005E CIRCUMFLEX ACCENT|[[^]]|style=background:#EFF}}
|{{chset-cell1|Alt+95&#10;U+005F LOW LINE|[[Underscore|_]]|style=background:#EFF}}
|-
!{{chset-left1|6x<br/>96}}
|{{chset-cell1|Alt+96&#10;U+0060 GRAVE ACCENT|[[`]]|style=background:#EFF}}
|{{chset-cell1|Alt+97&#10;U+0061 LATIN SMALL LETTER A|[[a]]}}
|{{chset-cell1|Alt+98&#10;U+0062 LATIN SMALL LETTER B|[[b]]}}
|{{chset-cell1|Alt+99&#10;U+0063 LATIN SMALL LETTER C|[[c]]}}
|{{chset-cell1|Alt+100&#10;U+0064 LATIN SMALL LETTER D|[[d]]}}
|{{chset-cell1|Alt+101&#10;U+0065 LATIN SMALL LETTER E|[[e]]}}
|{{chset-cell1|Alt+102&#10;U+0066 LATIN SMALL LETTER F|[[f]]}}
|{{chset-cell1|Alt+103&#10;U+0067 LATIN SMALL LETTER G|[[g]]}}
|{{chset-cell1|Alt+104&#10;U+0068 LATIN SMALL LETTER H|[[h]]}}
|{{chset-cell1|Alt+105&#10;U+0069 LATIN SMALL LETTER I|[[i]]}}
|{{chset-cell1|Alt+106&#10;U+006A LATIN SMALL LETTER J|[[j]]}}
|{{chset-cell1|Alt+107&#10;U+006B LATIN SMALL LETTER K|[[k]]}}
|{{chset-cell1|Alt+108&#10;U+006C LATIN SMALL LETTER L|[[l]]}}
|{{chset-cell1|Alt+109&#10;U+006D LATIN SMALL LETTER M|[[m]]}}
|{{chset-cell1|Alt+110&#10;U+006E LATIN SMALL LETTER N|[[n]]}}
|{{chset-cell1|Alt+111&#10;U+006F LATIN SMALL LETTER O|[[o]]}}
|-
!{{chset-left1|7x<br/>112}}
|{{chset-cell1|Alt+112&#10;U+0070 LATIN SMALL LETTER P|[[p]]}}
|{{chset-cell1|Alt+113&#10;U+0071 LATIN SMALL LETTER Q|[[q]]}}
|{{chset-cell1|Alt+114&#10;U+0072 LATIN SMALL LETTER R|[[r]]}}
|{{chset-cell1|Alt+115&#10;U+0073 LATIN SMALL LETTER S|[[s]]}}
|{{chset-cell1|Alt+116&#10;U+0074 LATIN SMALL LETTER T|[[t]]}}
|{{chset-cell1|Alt+117&#10;U+0075 LATIN SMALL LETTER U|[[u]]}}
|{{chset-cell1|Alt+118&#10;U+0076 LATIN SMALL LETTER V|[[v]]}}
|{{chset-cell1|Alt+119&#10;U+0077 LATIN SMALL LETTER W|[[w]]}}
|{{chset-cell1|Alt+120&#10;U+0078 LATIN SMALL LETTER X|[[x]]}}
|{{chset-cell1|Alt+121&#10;U+0079 LATIN SMALL LETTER Y|[[y]]}}
|{{chset-cell1|Alt+122&#10;U+007A LATIN SMALL LETTER Z|[[z]]}}
|{{chset-cell1|Alt+123&#10;U+007B LEFT CURLY BRACKET|[[Braces (punctuation)|{]]|style=background:#EFF}}
|{{chset-cell1|Alt+124&#10;U+007C VERTICAL LINE|[[Vertical bar|{{pipe}}]]|fn={{Efn|124 (7C<sub>hex</sub>) The actual glyph at this position is a [[broken bar]] [U+00A6, ¦] in the original [[IBM Personal Computer|IBM PC]] and [[IBM PC compatible|compatibles]] font, as rendered by the original [[IBM Monochrome Display Adapter|MDA]]. This rendering was later adopted for [[Color Graphics Adapter|CGA]], [[Enhanced Graphics Adapter|EGA]] and [[Video Graphics Array|VGA]] (see image at the beginning of the article). However, almost all software assumes this code is the ASCII character [U+007C, <nowiki>|</nowiki>]; for example, programming languages use it as "or". In the early 1990s, it was clarified{{By whom|date=July 2023}} that there is vertical bar in [[ASCII]] at this position and that the broken bar symbol is not part of ASCII.}}|style=background:#EFF}}
|{{chset-cell1|Alt+125&#10;U+007D RIGHT CURLY BRACKET|[[Braces (punctuation)|}]]|style=background:#EFF}}
|{{chset-cell1|Alt+126&#10;U+007E TILDE|[[~]]|style=background:#EFF}}
|{{chset-cell1|u=2302|Alt+127&#10;U+2302 HOUSE|[[Miscellaneous Technical|⌂]]|fn={{Efn|127 (7F<sub>hex</sub>) is a "house" but was also sometimes used as Greek capital [[delta (letter)|delta]] [U+0394, Δ].}}|style=background:#EFF}}
|-
!{{chset-left1|8x<br/>128}}
|{{chset-cell1|u=00C7|Alt+128&#10;U+00C7 LATIN CAPITAL LETTER C WITH CEDILLA|[[Ç]]}}
|{{chset-cell1|u=00FC|Alt+129&#10;U+00FC LATIN SMALL LETTER U WITH DIAERESIS|[[ü]]}}
|{{chset-cell1|u=00E9|Alt+130&#10;U+00E9 LATIN SMALL LETTER E WITH ACUTE|[[é]]}}
|{{chset-cell1|u=00E2|Alt+131&#10;U+00E2 LATIN SMALL LETTER A WITH CIRCUMFLEX|[[â]]}}
|{{chset-cell1|u=00E4|Alt+132&#10;U+00E4 LATIN SMALL LETTER A WITH DIAERESIS|[[ä]]}}
|{{chset-cell1|u=00E0|Alt+133&#10;U+00E0 LATIN SMALL LETTER A WITH GRAVE|[[à]]}}
|{{chset-cell1|u=00E5|Alt+134&#10;U+00E5 LATIN SMALL LETTER A WITH RING ABOVE|[[å]]}}
|{{chset-cell1|u=00E7|Alt+135&#10;U+00E7 LATIN SMALL LETTER C WITH CEDILLA|[[ç]]}}
|{{chset-cell1|u=00EA|Alt+136&#10;U+00EA LATIN SMALL LETTER E WITH CIRCUMFLEX|[[ê]]}}
|{{chset-cell1|u=00EB|Alt+137&#10;U+00EB LATIN SMALL LETTER E WITH DIAERESIS|[[ë]]}}
|{{chset-cell1|u=00E8|Alt+138&#10;U+00E8 LATIN SMALL LETTER E WITH GRAVE|[[è]]}}
|{{chset-cell1|u=00EF|Alt+139&#10;U+00EF LATIN SMALL LETTER I WITH DIAERESIS|[[ï]]}}
|{{chset-cell1|u=00EE|Alt+140&#10;U+00EE LATIN SMALL LETTER I WITH CIRCUMFLEX|[[î]]}}
|{{chset-cell1|u=00EC|Alt+141&#10;U+00EC LATIN SMALL LETTER I WITH GRAVE|[[ì]]}}
|{{chset-cell1|u=00C4|Alt+142&#10;U+00C4 LATIN CAPITAL LETTER A WITH DIAERESIS|[[Ä]]}}
|{{chset-cell1|u=00C5|Alt+143&#10;U+00C5 LATIN CAPITAL LETTER A WITH RING ABOVE|[[Å]]}}
|-
!{{chset-left1|9x<br/>144}}
|{{chset-cell1|u=00C9|Alt+144&#10;U+00C9 LATIN CAPITAL LETTER E WITH ACUTE|[[É]]}}
|{{chset-cell1|u=00E6|Alt+145&#10;U+00E6 LATIN SMALL LETTER AE|[[æ]]}}
|{{chset-cell1|u=00C6|Alt+146&#10;U+00C6 LATIN CAPITAL LETTER AE|[[Æ]]}}
|{{chset-cell1|u=00F4|Alt+147&#10;U+00F4 LATIN SMALL LETTER O WITH CIRCUMFLEX|[[ô]]}}
|{{chset-cell1|u=00F6|Alt+148&#10;U+00F6 LATIN SMALL LETTER O WITH DIAERESIS|[[ö]]}}
|{{chset-cell1|u=00F2|Alt+149&#10;U+00F2 LATIN SMALL LETTER O WITH GRAVE|[[ò]]}}
|{{chset-cell1|u=00FB|Alt+150&#10;U+00FB LATIN SMALL LETTER U WITH CIRCUMFLEX|[[û]]}}
|{{chset-cell1|u=00F9|Alt+151&#10;U+00F9 LATIN SMALL LETTER U WITH GRAVE|[[ù]]}}
|{{chset-cell1|u=00FF|Alt+152&#10;U+00FF LATIN SMALL LETTER Y WITH DIAERESIS|[[ÿ]]}}
|{{chset-cell1|u=00D6|Alt+153&#10;U+00D6 LATIN CAPITAL LETTER O WITH DIAERESIS|[[Ö]]}}
|{{chset-cell1|u=00DC|Alt+154&#10;U+00DC LATIN CAPITAL LETTER U WITH DIAERESIS|[[Ü]]}}
|{{chset-cell1|u=00A2|Alt+155&#10;U+00A2 CENT SIGN|[[¢]]|style=background:#EFF}}
|{{chset-cell1|u=00A3|Alt+156&#10;U+00A3 POUND SIGN|[[£]]|style=background:#EFF}}
|{{chset-cell1|u=00A5|Alt+157&#10;U+00A5 YEN SIGN|[[¥]]|style=background:#EFF}}
|{{chset-cell1|u=20A7|Alt+158&#10;U+20A7 PESETA SIGN|[[Spanish peseta|₧]]|style=background:#EFF}}
|{{chset-cell1|u=0192|Alt+159&#10;U+0192 LATIN SMALL LETTER F WITH HOOK|[[ƒ]]|style=background:#EFF}}
|-
!{{chset-left1|Ax<br/>160}}
|{{chset-cell1|u=00E1|Alt+160&#10;U+00E1 LATIN SMALL LETTER A WITH ACUTE|[[á]]}}
|{{chset-cell1|u=00ED|Alt+161&#10;U+00ED LATIN SMALL LETTER I WITH ACUTE|[[í]]}}
|{{chset-cell1|u=00F3|Alt+162&#10;U+00F3 LATIN SMALL LETTER O WITH ACUTE|[[ó]]}}
|{{chset-cell1|u=00FA|Alt+163&#10;U+00FA LATIN SMALL LETTER U WITH ACUTE|[[ú]]}}
|{{chset-cell1|u=00F1|Alt+164&#10;U+00F1 LATIN SMALL LETTER N WITH TILDE|[[ñ]]}}
|{{chset-cell1|u=00D1|Alt+165&#10;U+00D1 LATIN CAPITAL LETTER N WITH TILDE|[[Ñ]]}}
|{{chset-cell1|u=00AA|Alt+166&#10;U+00AA FEMININE ORDINAL INDICATOR|[[ª]]}}
|{{chset-cell1|u=00BA|Alt+167&#10;U+00BA MASCULINE ORDINAL INDICATOR|[[º]]}}
|{{chset-cell1|u=00BF|Alt+168&#10;U+00BF INVERTED QUESTION MARK|[[¿]]|style=background:#EFF}}
|{{chset-cell1|u=2310|Alt+169&#10;U+2310 REVERSED NOT SIGN|[[⌐]]|style=background:#EFF}}
|{{chset-cell1|u=00AC|Alt+170&#10;U+00AC NOT SIGN|[[¬]]|style=background:#EFF}}
|{{chset-cell1|u=00BD|Alt+171&#10;U+00BD VULGAR FRACTION ONE HALF|[[½]]}}
|{{chset-cell1|u=00BC|Alt+172&#10;U+00BC VULGAR FRACTION ONE QUARTER|[[Fraction|¼]]}}
|{{chset-cell1|u=00A1|Alt+173&#10;U+00A1 INVERTED EXCLAMATION MARK|[[¡]]|style=background:#EFF}}
|{{chset-cell1|u=00AB|Alt+174&#10;U+00AB LEFT-POINTING DOUBLE ANGLE QUOTATION MARK|[[«]]|style=background:#EFF}}
|{{chset-cell1|u=00BB|Alt+175&#10;U+00BB RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK|[[»]]|style=background:#EFF}}
|-
!{{chset-left1|Bx<br/>176}}
|{{chset-cell1|u=2591|Alt+176&#10;U+2591 LIGHT SHADE|[[░]]|style=background:#EFF}}
|{{chset-cell1|u=2592|Alt+177&#10;U+2592 MEDIUM SHADE|[[▒]]|style=background:#EFF}}
|{{chset-cell1|u=2593|Alt+178&#10;U+2593 DARK SHADE|[[▓]]|style=background:#EFF}}
|{{chset-cell1|u=2502|Alt+179&#10;U+2502 BOX DRAWINGS LIGHT VERTICAL|[[│]]|fn={{Efn|179 (B3<sub>hex</sub>) Could also serve as an integral extension [U+23AE, ⎮] in IBM's font.}}|style=background:#EFF}}
|{{chset-cell1|u=2524|Alt+180&#10;U+2524 BOX DRAWINGS LIGHT VERTICAL AND LEFT|[[┤]]|style=background:#EFF}}
|{{chset-cell1|u=2561|Alt+181&#10;U+2561 BOX DRAWINGS VERTICAL SINGLE AND LEFT DOUBLE|[[╡]]|style=background:#EFF}}
|{{chset-cell1|u=2562|Alt+182&#10;U+2562 BOX DRAWINGS VERTICAL DOUBLE AND LEFT SINGLE|[[╢]]|style=background:#EFF}}
|{{chset-cell1|u=2556|Alt+183&#10;U+2556 BOX DRAWINGS DOWN DOUBLE AND LEFT SINGLE|[[╖]]|style=background:#EFF}}
|{{chset-cell1|u=2555|Alt+184&#10;U+2555 BOX DRAWINGS DOWN SINGLE AND LEFT DOUBLE|[[╕]]|style=background:#EFF}}
|{{chset-cell1|u=2563|Alt+185&#10;U+2563 BOX DRAWINGS DOUBLE VERTICAL AND LEFT|[[╣]]|style=background:#EFF}}
|{{chset-cell1|u=2551|Alt+186&#10;U+2551 BOX DRAWINGS DOUBLE VERTICAL|[[║]]|style=background:#EFF}}
|{{chset-cell1|u=2557|Alt+187&#10;U+2557 BOX DRAWINGS DOUBLE DOWN AND LEFT|[[╗]]|style=background:#EFF}}
|{{chset-cell1|u=255D|Alt+188&#10;U+255D BOX DRAWINGS DOUBLE UP AND LEFT|[[╝]]|style=background:#EFF}}
|{{chset-cell1|u=255C|Alt+189&#10;U+255C BOX DRAWINGS UP DOUBLE AND LEFT SINGLE|[[╜]]|style=background:#EFF}}
|{{chset-cell1|u=255B|Alt+190&#10;U+255B BOX DRAWINGS UP SINGLE AND LEFT DOUBLE|[[╛]]|style=background:#EFF}}
|{{chset-cell1|u=2510|Alt+191&#10;U+2510 BOX DRAWINGS LIGHT DOWN AND LEFT|[[┐]]|style=background:#EFF}}
|-
!{{chset-left1|Cx<br/>192}}
|{{chset-cell1|u=2514|Alt+192&#10;U+2514 BOX DRAWINGS LIGHT UP AND RIGHT|[[└]]|style=background:#EFF}}
|{{chset-cell1|u=2534|Alt+193&#10;U+2534 BOX DRAWINGS LIGHT UP AND HORIZONTAL|[[┴]]|style=background:#EFF}}
|{{chset-cell1|u=252C|Alt+194&#10;U+252C BOX DRAWINGS LIGHT DOWN AND HORIZONTAL|[[┬]]|style=background:#EFF}}
|{{chset-cell1|u=251C|Alt+195&#10;U+251C BOX DRAWINGS LIGHT VERTICAL AND RIGHT|[[├]]|style=background:#EFF}}
|{{chset-cell1|u=2500|Alt+196&#10;U+2500 BOX DRAWINGS LIGHT HORIZONTAL|[[─]]|style=background:#EFF}}
|{{chset-cell1|u=253C|Alt+197&#10;U+253C BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL|[[┼]]|style=background:#EFF}}
|{{chset-cell1|u=255E|Alt+198&#10;U+255E BOX DRAWINGS VERTICAL SINGLE AND RIGHT DOUBLE|[[╞]]|style=background:#EFF}}
|{{chset-cell1|u=255F|Alt+199&#10;U+255F BOX DRAWINGS VERTICAL DOUBLE AND RIGHT SINGLE|[[╟]]|style=background:#EFF}}
|{{chset-cell1|u=255A|Alt+200&#10;U+255A BOX DRAWINGS DOUBLE UP AND RIGHT|[[╚]]|style=background:#EFF}}
|{{chset-cell1|u=2554|Alt+201&#10;U+2554 BOX DRAWINGS DOUBLE DOWN AND RIGHT|[[╔]]|style=background:#EFF}}
|{{chset-cell1|u=2569|Alt+202&#10;U+2569 BOX DRAWINGS DOUBLE UP AND HORIZONTAL|[[╩]]|style=background:#EFF}}
|{{chset-cell1|u=2566|Alt+203&#10;U+2566 BOX DRAWINGS DOUBLE DOWN AND HORIZONTAL|[[╦]]|style=background:#EFF}}
|{{chset-cell1|u=2560|Alt+204&#10;U+2560 BOX DRAWINGS DOUBLE VERTICAL AND RIGHT|[[╠]]|style=background:#EFF}}
|{{chset-cell1|u=2550|Alt+205&#10;U+2550 BOX DRAWINGS DOUBLE HORIZONTAL|[[═]]|style=background:#EFF}}
|{{chset-cell1|u=256C|Alt+206&#10;U+256C BOX DRAWINGS DOUBLE VERTICAL AND HORIZONTAL|[[╬]]|style=background:#EFF}}
|{{chset-cell1|u=2567|Alt+207&#10;U+2567 BOX DRAWINGS UP SINGLE AND HORIZONTAL DOUBLE|[[╧]]|style=background:#EFF}}
|-
!{{chset-left1|Dx<br/>208}}
|{{chset-cell1|u=2568|Alt+208&#10;U+2568 BOX DRAWINGS UP DOUBLE AND HORIZONTAL SINGLE|[[╨]]|style=background:#EFF}}
|{{chset-cell1|u=2564|Alt+209&#10;U+2564 BOX DRAWINGS DOWN SINGLE AND HORIZONTAL DOUBLE|[[╤]]|style=background:#EFF}}
|{{chset-cell1|u=2565|Alt+210&#10;U+2565 BOX DRAWINGS DOWN DOUBLE AND HORIZONTAL SINGLE|[[╥]]|style=background:#EFF}}
|{{chset-cell1|u=2559|Alt+211&#10;U+2559 BOX DRAWINGS UP DOUBLE AND RIGHT SINGLE|[[╙]]|style=background:#EFF}}
|{{chset-cell1|u=2558|Alt+212&#10;U+2558 BOX DRAWINGS UP SINGLE AND RIGHT DOUBLE|[[╘]]|style=background:#EFF}}
|{{chset-cell1|u=2552|Alt+213&#10;U+2552 BOX DRAWINGS DOWN SINGLE AND RIGHT DOUBLE|[[╒]]|style=background:#EFF}}
|{{chset-cell1|u=2553|Alt+214&#10;U+2553 BOX DRAWINGS DOWN DOUBLE AND RIGHT SINGLE|[[╓]]|style=background:#EFF}}
|{{chset-cell1|u=256B|Alt+215&#10;U+256B BOX DRAWINGS VERTICAL DOUBLE AND HORIZONTAL SINGLE|[[╫]]|style=background:#EFF}}
|{{chset-cell1|u=256A|Alt+216&#10;U+256A BOX DRAWINGS VERTICAL SINGLE AND HORIZONTAL DOUBLE|[[╪]]|style=background:#EFF}}
|{{chset-cell1|u=2518|Alt+217&#10;U+2518 BOX DRAWINGS LIGHT UP AND LEFT|[[┘]]|style=background:#EFF}}
|{{chset-cell1|u=250C|Alt+218&#10;U+250C BOX DRAWINGS LIGHT DOWN AND RIGHT|[[┌]]|style=background:#EFF}}
|{{chset-cell1|u=2588|Alt+219&#10;U+2588 FULL BLOCK|[[█]]|style=background:#EFF}}
|{{chset-cell1|u=2584|Alt+220&#10;U+2584 LOWER HALF BLOCK|[[▄]]|style=background:#EFF}}
|{{chset-cell1|u=258C|Alt+221&#10;U+258C LEFT HALF BLOCK|[[▌]]|style=background:#EFF}}
|{{chset-cell1|u=2590|Alt+222&#10;U+2590 RIGHT HALF BLOCK|[[▐]]|style=background:#EFF}}
|{{chset-cell1|u=2580|Alt+223&#10;U+2580 UPPER HALF BLOCK|[[▀]]|style=background:#EFF}}
|-
!{{chset-left1|Ex<br/>224}}
|{{chset-cell1|u=03B1|Alt+224&#10;U+03B1 GREEK SMALL LETTER ALPHA|[[α]]}}
|{{chset-cell1|u=00DF|Alt+225&#10;U+00DF LATIN SMALL LETTER SHARP S|[[ß]]|fn={{Efn|[[File:Code Page 437 E0-EF Comparison.svg|thumb|Comparison of characters in the E0 to EF range across various IBM products.]]225 (E1<sub>hex</sub>) is identified by IBM as Latin "[[ß|Sharp s]] Small"<ref name="CPGID_00437"/> [U+00DF, ß] but is sometimes rendered in [[OEM font]]s as Greek small [[beta (letter)|beta]] [U+03B2, β].  The placement of this Latin character among Greek characters suggests intended multi-use.}}}}
|{{chset-cell1|u=0393|Alt+226&#10;U+0393 GREEK CAPITAL LETTER GAMMA|[[Γ]]}}
|{{chset-cell1|u=03C0|Alt+227&#10;U+03C0 GREEK SMALL LETTER PI|[[Pi (letter)|π]]|fn={{Efn|227 (E3<sub>hex</sub>) is identified by IBM as Greek "[[pi (letter)|Pi]] Small" [U+03C0, π] but is sometimes rendered in OEM fonts as Greek capital pi [U+03A0, Π] or the [[variadic function|n-ary]] [[product (mathematics)|product]] sign [U+220F, ∏].}}}}
|{{chset-cell1|u=03A3|Alt+228&#10;U+03A3 GREEK CAPITAL LETTER SIGMA|[[Sigma|Σ]]|fn={{Efn|228 (E4<sub>hex</sub>) is identified by IBM as Greek "[[Sigma]] Capital" [U+03A3, Σ] but is also used as the [[variadic function|n-ary]] [[summation]] sign [U+2211, ∑].}}}}
|{{chset-cell1|u=03C3|Alt+229&#10;U+03C3 GREEK SMALL LETTER SIGMA|[[Sigma|σ]]}}
|{{chset-cell1|u=00B5|Alt+230&#10;U+00B5 MICRO SIGN|[[µ]]|fn={{Efn|230 (E6<sub>hex</sub>) is identified by IBM as Greek "[[mu (letter)|Mu]] Small" [U+03BC, μ] but is also used as the [[micro sign]] [U+00B5, µ].  IBM's Greek GCGID table<ref name="GCGID_Greek"/> maps the character in this code page to the Greek letter, but the cp437_DOSLatinUS to Unicode table<ref name="Unicode_1996_437"/> maps it to the micro sign.}}}}
|{{chset-cell1|u=03C4|Alt+231&#10;U+03C4 GREEK SMALL LETTER TAU|[[τ]]}}
|{{chset-cell1|u=03A6|Alt+232&#10;U+03A6 GREEK CAPITAL LETTER PHI|[[Φ]]}}
|{{chset-cell1|u=0398|Alt+233&#10;U+0398 GREEK CAPITAL LETTER THETA|[[Θ]]|fn={{Efn|233 (E9<sub>hex</sub>) is identified by IBM as Greek "[[Theta]] Capital" [U+0398, Θ].<ref name="cpgid437pdf"/><ref name="CPGID_00437"/> However, these symbols are for mathematics and physics, in which lowercase theta is much more commonly used (e.g. for polar coordinates).}}}}
|{{chset-cell1|u=03A9|Alt+234&#10;U+03A9 GREEK CAPITAL LETTER OMEGA|[[Ω]]|fn={{Efn|234 (EA<sub>hex</sub>) is identified by IBM as Greek "[[Omega]] Capital" [U+03A9, Ω] but is also used as the [[Ohm (unit)|ohm]] sign [U+2126, Ω]. Unicode considers the characters to be equivalent and suggests that U+03A9 be used in both contexts.<ref name="Unicode_2003_40"/>}}}}
|{{chset-cell1|u=03B4|Alt+235&#10;U+03B4 GREEK SMALL LETTER DELTA|[[δ]]|fn={{Efn|235 (EB<sub>hex</sub>) is identified by IBM as Greek "[[Delta (letter)|Delta]] Small" [U+03B4, δ]. It was also unofficially used for the small [[eth]] [U+00F0, ð] and the [[partial derivative]] sign [U+2202, ∂]}}}}
|{{chset-cell1|u=221E|Alt+236&#10;U+221E INFINITY|[[∞]]|style=background:#EFF}}
|{{chset-cell1|u=03C6|Alt+237&#10;U+03C6 GREEK SMALL LETTER PHI|[[φ]]|fn={{Efn|237 (ED<sub>hex</sub>) is identified by IBM as Greek "[[Phi (letter)|Phi]] Small (Closed Form)" [U+03D5, ϕ; or, from the italicized math set, U+1D719, 𝜙] but, Unicode maps it to the open (or "loopy") form [U+03C6, φ] in its cp437_DOSLatinUS table.<ref name="Unicode_1996_437"/> Comparison of IBM's Greek GCGID table<ref name="GCGID_Greek"/> with Unicode's Greek code chart<ref name="Unicode_Greek"/> shows where IBM, for example, reversed the open and closed forms when mapping to Unicode. This character is also used as the [[empty set]] sign [U+2205, ∅], the [[diameter]] sign [U+2300, ⌀], and the [[Ø|Latin letter O with stroke]] [U+00D8, Ø; and U+00F8, ø].}}}}
|{{chset-cell1|u=03B5|Alt+238&#10;U+03B5 GREEK SMALL LETTER EPSILON|[[ε]]|fn={{Efn|238 (EE<sub>hex</sub>) is identified by IBM as Greek "[[Epsilon]] Small" [U+03B5, ε] but is sometimes rendered in OEM fonts as the [[element (mathematics)|element-of]] sign [U+2208, ∈]. It was often used as the [[euro sign]] [U+20AC, €]}}}}
|{{chset-cell1|u=2229|Alt+239&#10;U+2229 INTERSECTION|[[Intersection#Notation|∩]]|style=background:#EFF}}
|-
!{{chset-left1|Fx<br/>240}}
|{{chset-cell1|u=2261|Alt+240&#10;U+2261 IDENTICAL TO|[[Triple bar|≡]]|style=background:#EFF}}
|{{chset-cell1|u=00B1|Alt+241&#10;U+00B1 PLUS-MINUS SIGN|[[±]]|style=background:#EFF}}
|{{chset-cell1|u=2265|Alt+242&#10;U+2265 GREATER-THAN OR EQUAL TO|[[≥]]|style=background:#EFF}}
|{{chset-cell1|u=2264|Alt+243&#10;U+2264 LESS-THAN OR EQUAL TO|[[Inequality (mathematics)|≤]]|style=background:#EFF}}
|{{chset-cell1|u=2320|Alt+244&#10;U+2320 TOP HALF INTEGRAL|[[⌠]]|fn={{efn|244 (F4<sub>hex</sub>) and 245 (F5<sub>hex</sub>) are the upper and lower portion of the [[integral symbol]] (∫), and they can be extended with the character 179 (B3<sub>hex</sub>), the vertical line of the box drawing block. 244 could also be used for the [[long s]] character [U+017F, ſ].}}|style=background:#EFF}}
|{{chset-cell1|u=2321|Alt+245&#10;U+2321 BOTTOM HALF INTEGRAL|[[⌡]]|style=background:#EFF}}
|{{chset-cell1|u=00F7|Alt+246&#10;U+00F7 DIVISION SIGN|[[÷]]|style=background:#EFF}}
|{{chset-cell1|u=2248|Alt+247&#10;U+2248 ALMOST EQUAL TO|[[≈]]|style=background:#EFF}}
|{{chset-cell1|u=00B0|Alt+248&#10;U+00B0 DEGREE SIGN|[[°]]|style=background:#EFF}}
|{{chset-cell1|u=2219|Alt+249&#10;U+2219 BULLET OPERATOR|[[∙]]|fn={{efn|249 (F9<sub>hex</sub>) and 250 (FA<sub>hex</sub>) are almost indistinguishable: the first is a slightly larger dot than the second, both were used as [[bullet (punctuation)|bullets]], [[interpunct|middle dot]], and [[multiplication dot]] [U+2219, ∙]}}|style=background:#EFF}}
|{{chset-cell1|u=00B7|Alt+250&#10;U+00B7 MIDDLE DOT|[[interpunct|·]]|style=background:#EFF}}
|{{chset-cell1|u=221A|Alt+251&#10;U+221A SQUARE ROOT|[[Square root|√]]|fn={{Efn|251 (FB<sub>hex</sub>) was also sometimes used as a [[check mark]] [U+2713, ✓].}}|style=background:#EFF}}
|{{chset-cell1|u=207F|Alt+252&#10;U+207F SUPERSCRIPT LATIN SMALL LETTER N|[[ⁿ]]}}
|{{chset-cell1|u=00B2|Alt+253&#10;U+00B2 SUPERSCRIPT TWO|[[²]]}}
|{{chset-cell1|u=25A0|Alt+254&#10;U+25A0 BLACK SQUARE|[[■]]|style=background:#EFF}}
|{{chset-ctrl1|u=00A0|Alt+255&#10;U+00A0 NO-BREAK SPACE|{{resize|60%|[[Non-breaking space|NBSP]]}}|fn={{Efn|255 (FF<sub>hex</sub>) draws a blank space; the use as non-breaking space (NBSP) has precedent in [[word processor]]s designed for the IBM PC.}}}}
|}
{{legend|#EFF|Symbols and punctuation}}
When translating to Unicode some codes do not have a unique, single Unicode equivalent; the correct choice may depend upon context.

```

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
```
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


AES-GCM encryption computed using two plaintext blocks and one block of additional authenticated data 
<img width="1168" height="562" alt="Screenshot 2026-04-24 at 23 01 55" src="https://github.com/user-attachments/assets/c95357cc-ebe7-46ba-8146-c453864df3f2" />


https://csrc.nist.gov/csrc/media/Events/2023/third-workshop-on-block-cipher-modes-of-operation/documents/accepted-papers/Practical%20Challenges%20with%20AES-GCM.pdf

AES-GCM Pain-Points AWS has been using AES-GCM in many encryption use-cases. AES-GCM has good performance, is highly optimized, FIPS-approved, and well-trusted. In spite of its proven value, GCM sucks for Key Management Systems so again, the Blockchain beats the NIST published standards. Consider the case where a customer managed key (CMK) is only accessible within a FIPS 140-2 Level 3 HSM. The CMK is used to both encrypt/decrypt small plaintext values and request encrypted data keys. GCM is a convenient mode for both operations. Constraints on the system, limit the number of CMKs any system can manage in or even export out of the HSM because that system requires another, larger system, aka someone else's shit


<img width="657" height="181" alt="expectation" src="https://github.com/user-attachments/assets/015c7d4c-56a6-4913-8b2c-1a61444fac3e" />




-----------------------------------
106.7: More Math to Make that Fucker go to 11


<img width="986" height="594" alt="Screenshot 2026-04-27 at 22 20 47" src="https://github.com/user-attachments/assets/ff716db9-047b-4048-a9a0-c5c4448c2e16" />


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


