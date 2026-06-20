__int64 __fastcall readw_relaxed(unsigned __int16 *a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  unsigned int v4; // w21

  v3 = v1;
  log_read_mmio(16, a1, readw_relaxed, v1);
  v4 = *a1;
  log_post_read_mmio(*a1, 16, a1, &loc_D0A0, v3);
  return v4;
}
