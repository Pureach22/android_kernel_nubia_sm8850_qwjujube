__int64 __fastcall readq(__int64 *a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  __int64 v4; // x21

  v3 = v1;
  log_read_mmio(64, a1, readq, v1);
  v4 = *a1;
  __dmb(1u);
  log_post_read_mmio(v4, 64, a1, &loc_13FEC, v3);
  return v4;
}
