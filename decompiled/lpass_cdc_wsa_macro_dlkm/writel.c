__int64 __fastcall writel(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x30
  __int64 v4; // x20

  v4 = v2;
  log_write_mmio(0, 32, a2, writel, v2);
  __dmb(2u);
  *a2 = 0;
  return log_post_write_mmio(0, 32, a2, &loc_E7DC, v4);
}
