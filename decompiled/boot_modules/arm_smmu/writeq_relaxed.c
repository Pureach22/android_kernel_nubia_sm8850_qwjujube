__int64 __fastcall writeq_relaxed(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x30
  __int64 v5; // x20

  v5 = v2;
  log_write_mmio(a1, 64, a2, writeq_relaxed, v2);
  *a2 = a1;
  return log_post_write_mmio(a1, 64, a2, &loc_B5B8, v5);
}
