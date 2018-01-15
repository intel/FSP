# Intel(R) Firmware Support Package (Intel(R) FSP) Binaries
Repository of Intel FSP binaries posted by Intel

# Intel FSP Home Page 
www.intel.com/FSP

## Wiki
https://github.com/IntelFsp/FSP/wiki

## Support and Issue Submission Link
http://www.intel.com/content/www/xr/ar/design/support/ips/training/access-and-login.html

# FSP Project Information
Each FSP project will be hosted in a separate branch.


FSP Project Name | Branch Name | Git command
:--------------- | :---------: | :----------
Intel® Atom™ processor E3900 product family (formerly Apollo Lake, Compliant with FSP v2.0 Specification) | ApolloLake | git clone -b ApolloLake https://github.com/IntelFsp/FSP.git
Intel® Pentium® and Celeron® Processor N3000 Product Families and Intel® Atom™ x5-E8000 Processor (formerly Braswell, Compliant with FSP v1.1 Specification) | Braswell | git clone -b Braswell https://github.com/IntelFsp/FSP.git
Intel® Atom™ processor E3800 product family (formerly Bay Trail, Compliant with FSP v1.0 Specification) | BayTrail | git clone -b BayTrail https://github.com/IntelFsp/FSP.git
Intel® Atom™ processor E6xx series with Intel® Platform Controller Hub EG20T (formerly Queens Bay: Tunnel Creek and Topcliff, Compliant with FSP v1.0 Specification) | QueensBay | git clone -b QueensBay https://github.com/IntelFsp/FSP.git
Intel® Atom™ processor C2000 product family (formerly Rangeley, Compliant with FSP v1.0 Specification) | Rangeley  | git clone -b Rangeley https://github.com/IntelFsp/FSP.git
7th Generation Intel® Core™ processors and chipsets (formerly Kaby Lake, Compliant with FSP v2.0 Specification) | Kabylake  | git clone -b Kabylake https://github.com/IntelFsp/FSP.git
6th Generation Intel® Core™ processors and chipsets (formerly SkyLake, Compliant with FSP v1.1 Specification) | Skylake  | git clone -b Skylake https://github.com/IntelFsp/FSP.git
5th Generation Intel® Core™ processors and chipsets (formerly Broadwell, Compliant with FSP v1.0 Specification) | Broadwell  | git clone -b Broadwell https://github.com/IntelFsp/FSP.git
4th Generation Intel® Core™ processors with mobile Intel® QM87 and HM86 chipsets (formerly Shark Bay mobile: Haswell and Lynx Point, Compliant with FSP v1.0 Specification) | SharkBay | git clone -b SharkBay https://github.com/IntelFsp/FSP.git
3rd Generation Intel® Core™ processors with mobile Intel® HM76 and QM77 chipsets  (formerly Chief River Platform: Ivy Bridge and Panther Point, Compliant with FSP v1.0 Specification) | ChiefRiver | git clone -b ChiefRiver https://github.com/IntelFsp/FSP.git
Intel® Xeon® E3-1125C v2, E3-1105C v2, Intel® Pentium® B925C, Intel® Core™ i3-3115C for communication infrastructure with Intel® Communication Chipset 89xx Series Platform Controller Hub (formerly Crystal Forest Refresh: Ivy Bridge Gladden and Cave Creek, Compliant with FSP v1.0 Specification) | CrystalForestIvyBridge | git clone -b CrystalForestIvyBridge https://github.com/IntelFsp/FSP.git
Intel® Xeon® Processor D Product Family (formerly Broadwell-DE, Compliant with FSP v1.0 Specification) | Broadwell-DE | git clone -b Broadwell-DE https://github.com/IntelFsp/FSP.git
Intel® Atom™ processor C3XXX product family (formerly Denverton, Compliant with FSP v2.0 Specification) | DenvertonNS | git clone -b DenvertonNS https://github.com/IntelFsp/FSP.git

# FSP Issue Communication
## Intel® Atom™ processor E3900 product family (formerly Apollo Lake)
Issue: Some write-one clear bits in GEN_PMCON1 will be cleared unexpectedly in FSP which results in unable to obtain reset type in OS layer
Expected fix: To be fixed in MR4 release in Q4'2017 timeframe
