# WhitleyFspBinPkg
This FSP binary is intended to be used with 3rd Generation Intel® Xeon® Scalable Processors formerly known as Ice Lake-SP.

## Differentiating Ice Lake and Cooper Lake
3rd Generation Intel® Xeon® Scalable Processors may require different FSP
binaries depending on the processor number. Processor numbers ending in an "H"
or "HL" are formerly known as Cooper Lake (supported by the Cedar Island platform).
All other 3rd Generation Intel® Xeon® Scalable Processors are formerly known as
Ice Lake (supported by the Whitley platform). For example the Intel® Xeon®
Platinum 8380 Processor is Ice Lake and the Intel® Xeon® Platinum 8380H Processor
is Cooper Lake.

These FSP binaries can only be used with Ice Lake. **They will not work with Cooper Lake.**

## FSP API Mode
FSP API Mode has not been tested on WhitleyFspBinPkg. There are known issues that
prevent a platform from booting in API Mode. FSP Dispatch Mode is supported.
At time of writing FSP Dispatch Mode is only implemented by EDK II based boot
loaders, which Intel recommends for WhitleyFspBinPkg. Intel has provided an open
source EDK II MinPlatform reference implementation at
[edk2-platforms/Platform/Intel/WhitleyOpenBoardPkg](https://github.com/tianocore/edk2-platforms/tree/master/Platform/Intel/WhitleyOpenBoardPkg)
which supports WhitleyFspBinPkg in FSP Dispatch Mode. There are also commercially
supported implementations available from several IFVs and IBVs.
