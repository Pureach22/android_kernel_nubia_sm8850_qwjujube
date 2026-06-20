__int64 __fastcall writew_relaxed(unsigned __int16 a1, unsigned __int16 *a2)
{
  __int64 v2; // x30
  __int64 v5; // x21

  v5 = v2;
  log_write_mmio(a1, 16, a2, writew_relaxed, v2);
  *a2 = a1;
  return log_post_write_mmio(a1, 16, a2, &loc_AA60, v5);
}
