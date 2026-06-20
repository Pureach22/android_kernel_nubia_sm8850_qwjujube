__int64 __fastcall readl_relaxed(unsigned int *a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  unsigned int v4; // w21

  v3 = v1;
  log_read_mmio(32, a1, readl_relaxed, v1);
  v4 = *a1;
  log_post_read_mmio(*a1, 32, a1, &loc_6F84, v3);
  return v4;
}
