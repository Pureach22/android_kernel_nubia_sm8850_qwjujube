__int64 __fastcall readl_relaxed_8(unsigned int *a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  unsigned int v4; // w21

  v3 = v1;
  log_read_mmio(32, a1, readl_relaxed_8, v1);
  v4 = *a1;
  log_post_read_mmio(*a1, 32, a1, &loc_1735EC, v3);
  return v4;
}
