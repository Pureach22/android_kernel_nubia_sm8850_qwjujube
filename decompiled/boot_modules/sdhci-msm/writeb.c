__int64 __fastcall writeb(__int64 a1, _BYTE *a2)
{
  __int64 v2; // x30
  __int64 v4; // x20

  v4 = v2;
  log_write_mmio(0, 8, a2, writeb, v2);
  __dmb(2u);
  *a2 = 0;
  return log_post_write_mmio(0, 8, a2, &loc_AE58, v4);
}
