# AmberLakeFspBinPkg
This FSP binary is intended to be used with 10th, 8th and 7th Generation Intel® Core™ processors and chipsets formerly known as Comet Lake Y-Series, Amber Lake, Kaby Lake Refresh, and Kaby Lake. It is generally not intended to be used with 8th Generation Intel® Core™ processors and chipsets formerly known as Coffee Lake or Whiskey Lake.

In rare circumstances, this FSP binary is also used with 9th and 8th Generation Intel® Core™ processors and chipsets formerly known as Coffee Lake Refresh and Coffee Lake. Specifically, this FSP binary is only used with Coffee Lake Refresh and Coffee Lake desktop processors when installed in a motherboard that utilizes a 22nm Platform Controller Hub (PCH). The following Intel® 300 Series Chipsets use 22nm fabrication:

* Intel® Z370 Chipset
* Intel® B365 Chipset
* Intel® H310C Chipset

For all other Intel® 300 Series Chipsets, please use CoffeeLakeFspBinPkg. This FSP binary is never used with mobile Coffee Lake Refresh, Coffee Lake, or Whiskey Lake processors.

Comet Lake Y-Series support has been added starting with FSP release 3.7.6, previous versions of AmberLakeFspBinPkg do not support Comet Lake Y-Series. For all other Comet Lake processors, please use CometLakeFspBinPkg.

AmberLakeFspBinPkg is the initial Intel® FSP to implement Intel® FSP External Architecture Specification v2.1. KabyLakeFspBinPkg supports similar Intel® Core™ processors and chipsets, however it implements Intel® FSP External Architecture Specification v2.0 instead of v2.1.
