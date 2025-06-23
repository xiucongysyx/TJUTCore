#include <am.h>
#include <npc.h>
#include <riscv.h>
#include <stdio.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

static int width;
static int height;

void __am_gpu_init() {
  int width_height = inl(VGACTL_ADDR);
  height = (int)(0x0000ffff & width_height);
  width = (int)(width_height >> 16);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = width,  .height = height,
    .vmemsz = width * height * sizeof(uint32_t)
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  uint32_t *pixels = (uint32_t *)(ctl->pixels);
  printf("drawing picture\n");
  int n = 0;
  for(int j = 0; j < ctl->h; j++) {
    for(int i = 0; i < ctl->w; i++) {
      fb[(ctl->y + j) * width + (ctl->x + i)] = pixels[n++];
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}