__int64 __fastcall sde_dbg_vbif_clear_test_point(__int64 a1, unsigned int a2)
{
  __int64 v2; // x19
  __int64 result; // x0

  v2 = a1 + a2;
  writel_relaxed_6(0, v2);
  result = writel_relaxed_6(0, v2 + 4);
  __dsb(0xEu);
  return result;
}
