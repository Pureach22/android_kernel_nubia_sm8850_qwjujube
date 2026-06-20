__int64 __fastcall sde_dbg_sde_read_test_point_ver_c00(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        unsigned int a5)
{
  __int64 v6; // x1
  int v9; // w8

  v6 = a1 + a2;
  v9 = (16 * a4) | (a5 >> 3 << 24) | (2 * (a5 & 7));
  if ( a5 < 8 )
    v9 = (2 * a5) | (16 * a4);
  writel_relaxed_6(v9 | 1u, v6);
  if ( a2 != 900 )
    writel_relaxed_6(28673, a1 + 900);
  __dsb(0xEu);
  return readl_relaxed_6(a1 + a3);
}
