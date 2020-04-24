# CometLakeFspBinPkg
These FSP binaries are intended to be used with 10th Generation Intel® Core™ processors and chipsets formerly known as Comet Lake. They are ***not*** intended to be used with 10th Generation Intel® Core™ processors and chipsets formerly known as Ice Lake.

## Comet Lake Binary Differences
There are different variants of the Comet Lake FSP intended for different 10th Generation Intel® Core™ (formerly Comet Lake) SKUs. Please consult the table below:

Directory Name | 10th Generation Intel® Core™ (formerly Comet Lake) SKU Description
:------------- | :-------------------------
CometLake1 | U-Series & H-Series processors with support for LPDDR3 & DDR4 memory
CometLake2 | U-Series processors with support for LPDDR4 & DDR4 memory
CometLakeS | Desktop processors with a 14nm Platform Controller Hub (PCH)
CometLakeV | Desktop processors with a 22nm Platform Controller Hub (PCH)

## Differentiating CometLake1 and CometLake2

CometLake1 and CometLake2 can be differentiated by checking the CPU Family, Model, and Stepping data. This can be done by setting the value of EAX=1, executing a CPUID instruction, and storing the value of EAX. CometLake2 has a value of EAX=0x000A0661, CometLake1 has a value of EAX=0x000A0660 or 0x000806EC.

Processor numbers cannot be used to determine the difference between CometLake1 and CometLake2. For example, some Intel® Core™ i7-10710U processors are CometLake1 and some Intel® Core™ i7-10710U processors are CometLake2. An indirect method of differentiation is checking if the system's RAM is LPDDR3 or LPDDR4; this method fails if the system RAM is DDR4 however. CPUID checks are the only reliable mechanism to differentiate them.

## Differentiating CometLakeS and CometLakeV

The desktop processors work in any LGA1120 socket; therefore the difference between CometLakeS and CometLakeV is the Platform Controller Hub (PCH). Motherboards with a 14nm Platform Controller Hub (PCH) use CometLakeS. Motherboards with a 22nm Platform Controller Hub (PCH) use CometLakeV. At time of writing, the following Intel® 400 Series Chipsets use 22nm fabrication:

* Intel® B460C Chipset
* Intel® H410 Chipset

For all other Intel® 400 Series Chipsets, use CometLakeS. For the Intel® B460 Chipset use CometLakeS.

## Comet Lake Y-Series

Comet Lake Y-Series processors use AmberLakeFspBinPkg. Amber Lake FSP version 3.7.6 or later is required for Comet Lake Y-Series support. For all other Comet Lake processors, please use CometLakeFspBinPkg.
