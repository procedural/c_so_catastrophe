I have a real library `/usr/lib/x86_64-linux-gnu/libmylib.so.1` and its symlink `/usr/lib/x86_64-linux-gnu/libmylib.so`, I symlink `/usr/lib/x86_64-linux-gnu/libmylib.so` to `~/Desktop/libmylib.so`, I'm telling CMake to link `~/Desktop/libmylib.so` and I get:
```
$ make
[ 50%] Linking C executable main
/usr/bin/ld: cannot find -lmylib
collect2: error: ld returned 1 exit status
```
"The problem" is that `/usr/lib/x86_64-linux-gnu/libmylib.so` symlink points to just `libmylib.so.1`, not `/usr/lib/x86_64-linux-gnu/libmylib.so.1`:
```
$ file /usr/lib/x86_64-linux-gnu/libmylib.so
/usr/lib/x86_64-linux-gnu/libmylib.so: symbolic link to libmylib.so.1
```
All these symlinks chain point to a single real library I told CMake to link to, there's no problem here other than that CMake doesn't get the full path of that library.
