__int64 __fastcall sde_dbg_rsc_read_test_point(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4, char a5)
{
  writel_relaxed_6((2 * (a5 & 0xF)) | 1u, a1 + a2);
  __dsb(0xEu);
  return readl_relaxed_6(a1 + a3);
}
