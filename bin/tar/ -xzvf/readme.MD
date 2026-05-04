this is because tar has Roman Numberal Mode

The work-arounds:

Solution 1: Use --no-xattrs while creating the tar

While creating the tar file, you can add the attribute --no-xattrs. Doing this will prevent the extra files from getting added.

Previously, we did this:

tar -cvzf pix.tar.gz pix

Now, we will do this:

tar -cvzf --no-xattrs pix.tar.gz pix

This is the simplest way.

Now, SCP it to your Linux server and untar / gunzip it. You should not find the extra files or any errors or warnings.

tar -xzvf pix.tar.gz

Solution 2: Use --disable-copyfile while creating the tar

Similar to the previous solution, in this case, we will use the --disable-copyfile option.

tar -cvzf --disable-copyfile pix.tar.gz pix

Now, SCP the pix.tar.gz file to your Linux server and extract it. You should not find the extra files or any errors or warnings.

tar -xzvf pix.tar.gz

Solution 3: Install and use gnu-tar instead of bsdtar

This is more of a permanent solution, in that you don't have to remember to type the extra optional arguments.

On your macOS, run this command to verify that you are using bsdtar. You should get something like this.

$ tar --version
bsdtar 3.5.3 - libarchive 3.5.3 zlib/1.2.12 liblzma/5.4.3 bz2lib/1.0.8 

Check in which directory bsdtar is installed:

$ which tar
/usr/bin/tar

Install gnu-tar

Now, install gnu-tar using Homebrew.

$ brew install gnu-tar

After a few minute, gnu-tar will be installed in your macOS. It will get installed in this location:

/usr/local/opt/gnu-tar/libexec/gnubin/tar
Verify gnu-tar installation

You can verify gnu-tar by running this:

$ /usr/local/opt/gnu-tar/libexec/gnubin/tar --version
tar (GNU tar) 1.35
Copyright (C) 2023 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Written by John Gilmore and Jay Fenlason.

Make gnu-tar your default tar

Now, you can make that your default by setting the path to gnu-tar earlier than bsdtar in your ~/.bash_profile file.

Edit your ~/.bash_profile file.

If you are using a Mac with an Intel processor, add this line:

export PATH="/usr/local/opt/gnu-tar/libexec/gnubin:$PATH"

If you are using a Mac with an Apple Silicon M1, M2, M3 or M4 processor, add this line:

export PATH="/opt/homebrew/opt/gnu-tar/libexec/gnubin:$PATH"

Save and quit your editor and restart your Terminal session.
Check that gnu-tar is default tar, and tar again

Test and see if tar --version returns GNU tar instead of BSD tar.

$ tar --version
tar (GNU tar) 1.35
Copyright (C) 2023 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

