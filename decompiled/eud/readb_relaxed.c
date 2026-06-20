__int64 __fastcall readb_relaxed(unsigned __int8 *a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  unsigned int v4; // w21

  v3 = v1;
  log_read_mmio(8, a1, readb_relaxed, v1);
  v4 = *a1;
  log_post_read_mmio(*a1, 8, a1, &loc_6F70, v3);
  return v4;
}
