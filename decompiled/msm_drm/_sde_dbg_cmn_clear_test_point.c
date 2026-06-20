__int64 __fastcall sde_dbg_cmn_clear_test_point(__int64 a1, unsigned int a2)
{
  return writel_relaxed_6(0, a1 + a2);
}
