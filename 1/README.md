To compile, just run `main.c`. You'll see `instance` is `0x0` or some garbage value, even if you have a working Vulkan setup. Comment [line 27](https://github.com/procedural/c_so_catastrophe/blob/master/1/main.c#L27), rerun and it will work fine.

`amdvlk64.so` and `libvulkan.so.1` are x64 libraries compiled on Ubuntu 18.04.

<img width="500px" src="https://i.imgur.com/w2YMxrE.png" />
