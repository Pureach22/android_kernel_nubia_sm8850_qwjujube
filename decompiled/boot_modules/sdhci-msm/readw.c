__int64 __fastcall readw(unsigned __int16 *a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  unsigned __int16 v4; // w8
  unsigned int v5; // w21

  v3 = v1;
  log_read_mmio(16, a1, readw, v1);
  v4 = *a1;
  __dmb(1u);
  v5 = v4;
  log_post_read_mmio(v4, 16, a1, &loc_B32C, v3);
  return v5;
}
