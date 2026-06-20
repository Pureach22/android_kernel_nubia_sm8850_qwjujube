__int64 __fastcall sde_dbg_sde_clear_test_point(__int64 a1, unsigned int a2)
{
  __int64 result; // x0

  result = writel_relaxed_6(0, a1 + a2);
  if ( a2 != 840 )
    return writel_relaxed_6(0, a1 + 840);
  return result;
}
