__int64 __fastcall writel_relaxed(unsigned int a1, unsigned int *a2)
{
  __int64 v2; // x30
  __int64 v3; // x20
  __int64 v6; // x21

  v3 = a1;
  v6 = v2;
  log_write_mmio(a1, 32, a2, &loc_2BB53C, v2);
  *a2 = a1;
  return log_post_write_mmio(v3, 32, a2, &loc_2BB56C, v6);
}
