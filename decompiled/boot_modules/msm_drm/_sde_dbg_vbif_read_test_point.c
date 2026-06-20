__int64 __fastcall sde_dbg_vbif_read_test_point(__int64 a1, unsigned int a2, unsigned int a3, char a4, unsigned int a5)
{
  __int64 v7; // x21

  v7 = a1 + a2;
  writel_relaxed_6((unsigned int)(1 << a4), v7);
  writel_relaxed_6(a5, v7 + 4);
  __dsb(0xEu);
  return readl_relaxed_6(a1 + a3);
}
