__int64 __fastcall writeq_relaxed(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x30
  __int64 v4; // x20

  v4 = v2;
  log_write_mmio(0x80000000LL, 64, a2, writeq_relaxed, v2);
  *a2 = 0x80000000LL;
  return log_post_write_mmio(0x80000000LL, 64, a2, &loc_7218, v4);
}
