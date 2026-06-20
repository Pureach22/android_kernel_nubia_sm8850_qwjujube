__int64 __fastcall readq_relaxed(_QWORD *a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  __int64 v4; // x21

  v3 = v1;
  log_read_mmio(64, a1, readq_relaxed, v1);
  v4 = *a1;
  log_post_read_mmio(*a1, 64, a1, &loc_B45C, v3);
  return v4;
}
