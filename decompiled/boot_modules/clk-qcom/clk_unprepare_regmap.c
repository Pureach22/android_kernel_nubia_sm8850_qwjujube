__int64 __fastcall clk_unprepare_regmap(__int64 result)
{
  if ( *(_QWORD *)(result + 64) )
    return clk_unvote_vdd_level(result + 48, *(unsigned int *)(result + 76));
  return result;
}
