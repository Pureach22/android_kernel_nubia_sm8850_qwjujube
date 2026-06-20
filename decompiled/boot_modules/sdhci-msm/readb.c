__int64 __fastcall readb(unsigned __int8 *a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  unsigned __int8 v4; // w8
  unsigned int v5; // w21

  v3 = v1;
  log_read_mmio(8, a1, readb, v1);
  v4 = *a1;
  __dmb(1u);
  v5 = v4;
  log_post_read_mmio(v4, 8, a1, &loc_B3AC, v3);
  return v5;
}
