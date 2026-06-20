__int64 __fastcall a619_holi_sptprac_enable(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x21
  __int64 v6; // x0
  __int64 v7; // x21
  unsigned __int64 v15; // x9

  v2 = kgsl_regmap_virt(a1 + 1650, 129232);
  if ( (a1[1780] & 0x100) == 0 )
  {
    v3 = v2;
    v4 = kgsl_regmap_write(a1 + 1650, 7831552);
    v5 = ktime_get(v4);
    v6 = readl(v3);
    if ( (v6 & 8) == 0 )
    {
      v7 = v5 + 10000000;
      while ( ktime_get(v6) <= v7 )
      {
        usleep_range_state(3, 10, 2);
        __yield();
        v6 = readl(v3);
        if ( (v6 & 8) != 0 )
          goto LABEL_8;
      }
      LOBYTE(v6) = readl(v3);
    }
LABEL_8:
    if ( (v6 & 8) == 0 )
    {
      dev_err(*a1, "power on SPTPRAC fail\n");
      return 4294967274LL;
    }
    _X8 = a1 + 1780;
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 | 0x100, _X8) );
  }
  return 0;
}
