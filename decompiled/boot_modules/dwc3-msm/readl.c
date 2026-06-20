__int64 __fastcall readl(unsigned int *a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  unsigned int v4; // w8
  unsigned int v5; // w21

  v3 = v1;
  log_read_mmio(32, a1, readl, v1);
  v4 = *a1;
  __dmb(1u);
  v5 = v4;
  log_post_read_mmio(v4, 32, a1, &loc_C954, v3);
  return v5;
}
