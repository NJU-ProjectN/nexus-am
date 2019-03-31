#include <am.h>
#include <amdev.h>

void vga_init();
void timer_init();

int _ioe_init() {
  vga_init();
  timer_init();
  return 0;
}

size_t timer_read(uintptr_t reg, void *buf, size_t size);
size_t video_read(uintptr_t reg, void *buf, size_t size);
size_t video_write(uintptr_t reg, void *buf, size_t size);
size_t input_read(uintptr_t reg, void *buf, size_t size);

size_t _io_read(uint32_t dev, uintptr_t reg, void *buf, size_t size) {
  switch (dev) {
    case _DEV_INPUT: return input_read(reg, buf, size);
    case _DEV_TIMER: return timer_read(reg, buf, size);
    case _DEV_VIDEO: return video_read(reg, buf, size);
  }
  return 0;
}

size_t _io_write(uint32_t dev, uintptr_t reg, void *buf, size_t size) {
  switch (dev) {
    case _DEV_VIDEO: return video_write(reg, buf, size);
  }
  return 0;
}
