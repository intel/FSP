If you are integrating this FSP bin into an older coreboot code base, you might encounter crossgcc build error where the download link of “LIBELF” is broken.

In this case, you need to manually edit the <buildgcc> script, under: ~/coreboot/util/crossgcc/
By replacing the download link

From:
http://www.mr511.de/software/libelf-0.8.13.tar.gz

To:
https://fossies.org/linux/misc/old/libelf-0.8.13.tar.gz
