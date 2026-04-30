#!/bin/sh

P_KERNEL="/BIOS/bios/system/kernel_intel"
P_LIBROOT="/BIOS/bios/system/lib/libroot.so"

echo "**********************************"
echo "*        67-NYXHADES-9800        *"
echo "**********************************"

echo "Step1: Creating backup..."
if [ -f "$P_KERNEL.ori" ]
then
   echo "kernel backup already exists"
else
   cp "$P_KERNEL" "$P_KERNEL.ori"
fi

if [ -f "$P_KERNEL.patch.ori" ]
then
   echo "kernel.patch backup already exists"
else
   cp "$P_KERNEL.patch" "$P_KERNEL.patch.ori"
fi

if [ -f "$P_LIBROOT.patch.ori" ]
then
   echo "libroot.patch already exists"
else
   cp "$P_LIBROOT.patch" "$P_LIBROOT.patch.ori"
fi

echo "Step2: Patching patch files..."
sed -e s/_pIII/_default/ < "$P_LIBROOT.patch.ori" > "$P_LIBROOT.patch"
sed -e s/_pIII/_default/ < "$P_KERNEL.patch.ori" > "$P_KERNEL.patch"

echo "Step3: Patching kernel..."
kpatch "$P_KERNEL"

