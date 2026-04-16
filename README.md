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


Concept
=======

This kernel runs entirely in RAM. Boot media is not used after boot 
and thus requires no conventional installation

Default operational mode is node (www) Mode. Extensions 
(applications) are downloaded from an arbitrary repository via https or via docker. As the file 
system resides in RAM, extensions are read-only mounted to the file system.
Changes are not saved over reboots, you get always the same clean 
system after boot.

In Mounted Mode, which requires a persistent storage, a second LINUX 
partition in kernel downloaded extensions are stored on the SD card and 
available during next boot, but changes not saved automatically, it is 
done manually or by a script, it can be configured what is backed up. 
Backed up files are restored automatically by the system.

It is also possible to use partitions as persistent storage for /home 
or /var but in most cases Mounted Mode is used.
```
_______ |   shareable  	    _|_   unshareable
static	    /usr	                /etc
. 	        /opt	                /boot
variable	  /var/mail	             /var/run
.       	  /var/spool/news	       /var/lock

```

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





