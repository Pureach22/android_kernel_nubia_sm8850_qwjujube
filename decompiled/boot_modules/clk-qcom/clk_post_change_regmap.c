__int64 __fastcall clk_post_change_regmap(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w20
  unsigned int vdd_level; // w21
  __int64 result; // x0

  if ( !*(_QWORD *)(a1 + 64) )
    return 0;
  v3 = *(_DWORD *)(a1 + 76);
  vdd_level = clk_find_vdd_level(a1, a1 + 48, a3);
  if ( (vdd_level & 0x80000000) != 0 )
    return vdd_level;
  if ( (int)vdd_level >= (int)v3 )
    return 0;
  if ( (clk_hw_is_prepared(a1) & 1) != 0 )
  {
    result = clk_vote_vdd_level(a1 + 48, vdd_level);
    if ( (_DWORD)result )
      return result;
    clk_unvote_vdd_level(a1 + 48, v3);
  }
  *(_DWORD *)(a1 + 76) = vdd_level;
  return 0;
}
