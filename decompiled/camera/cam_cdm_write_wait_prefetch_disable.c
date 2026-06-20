int *__fastcall cam_cdm_write_wait_prefetch_disable(int *a1, unsigned __int8 a2, int a3, int a4)
{
  int v4; // w9

  v4 = *a1;
  a1[1] = a3;
  a1[2] = a4;
  *a1 = v4 & 0xFF00FF | (a2 << 8) | 0xE000000;
  return a1 + 3;
}
