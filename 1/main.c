#if 0
rm -f a.out
clang -nostdlib main.s main.c libvulkan.so.1 -O0 -g
if [ -e a.out ]
then
  LD_LIBRARY_PATH=. gdb -q -ex 'break main.c:24' -ex 'r' -ex 'tui e' -ex 'foc n' -ex 'p instance' ./a.out
fi
exit
#endif

void * memset(void * s, int c, unsigned long n) {
  unsigned char * cs = s;
  for (int i = 0; i < n; i += 1)
    cs[i] = c;
  return s;
}

#include <vulkan/vulkan.h>

int main() {
  VkInstanceCreateInfo create_instance_info = {VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO};
  VkInstance instance = VK_NULL_HANDLE;
  vkCreateInstance(&create_instance_info, NULL, &instance);
  vkDestroyInstance(instance, NULL); // Will segmentation fault if instance is garbage.
}

int snprintf(char * s, size_t n, const char * fmt, ...) { return 0; }
