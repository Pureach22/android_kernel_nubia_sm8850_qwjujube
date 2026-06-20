__int64 __fastcall clk_prepare_regmap(__int64 a1)
{
  __int64 rate; // x0
  __int64 result; // x0
  __int64 v4; // x1
  int v5; // w20
  const char *name; // x0

  rate = clk_hw_get_rate(a1);
  if ( !*(_QWORD *)(a1 + 64) )
    return 0;
  result = clk_find_vdd_level(a1, a1 + 48, rate);
  if ( (result & 0x80000000) == 0 )
  {
    v4 = *(unsigned int *)(a1 + 76);
    if ( (_DWORD)v4 )
    {
      if ( (int)result > (int)v4 )
      {
        v5 = result;
        name = (const char *)clk_hw_get_name(a1);
        _warn_printk("%s level:%d > vdd_level:%d\n", name, v5, *(_DWORD *)(a1 + 76));
        __break(0x800u);
        v4 = *(unsigned int *)(a1 + 76);
      }
    }
    else
    {
      *(_DWORD *)(a1 + 76) = result;
      v4 = (unsigned int)result;
    }
    return clk_vote_vdd_level(a1 + 48, v4);
  }
  return result;
}
