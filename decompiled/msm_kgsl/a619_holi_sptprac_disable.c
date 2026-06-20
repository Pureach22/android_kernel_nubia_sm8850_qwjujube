__int64 __fastcall a619_holi_sptprac_disable(_QWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x21
  __int64 v6; // x21
  unsigned __int64 v13; // x8

  result = kgsl_regmap_virt(a1 + 1650, 129232);
  v3 = result;
  _X9 = a1 + 1780;
  __asm { PRFM            #0x11, [X9] }
  do
    v13 = __ldxr(_X9);
  while ( __stlxr(v13 & 0xFFFFFFFFFFFFFEFFLL, _X9) );
  __dmb(0xBu);
  if ( (v13 & 0x100) != 0 )
  {
    kgsl_regmap_rmw(a1 + 1650, 148483, 0, 2048);
    v4 = kgsl_regmap_write(a1 + 1650, 7831553);
    v5 = ktime_get(v4);
    result = readl(v3);
    if ( (result & 4) == 0 )
    {
      v6 = v5 + 10000000;
      while ( ktime_get(result) <= v6 )
      {
        usleep_range_state(3, 10, 2);
        __yield();
        result = readl(v3);
        if ( (result & 4) != 0 )
          goto LABEL_8;
      }
      result = readl(v3);
    }
LABEL_8:
    if ( (result & 4) == 0 )
      return dev_err(*a1, "power off SPTPRAC fail\n");
  }
  return result;
}
