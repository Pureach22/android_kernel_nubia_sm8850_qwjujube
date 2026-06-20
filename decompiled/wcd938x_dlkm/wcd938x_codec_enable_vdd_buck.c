__int64 __fastcall wcd938x_codec_enable_vdd_buck(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x20
  unsigned __int64 *v4; // x21
  __int64 v5; // x22
  unsigned __int64 v14; // x9
  unsigned __int64 v17; // x10
  unsigned __int64 v20; // x10

  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(unsigned __int64 **)(*(_QWORD *)(v3 - 184) + 152LL);
  v5 = *(_QWORD *)(*v4 + 144);
  if ( !v5 )
  {
    if ( (unsigned int)__ratelimit(&wcd938x_codec_enable_vdd_buck__rs, "wcd938x_codec_enable_vdd_buck") )
    {
      dev_err(*(_QWORD *)(v3 - 184), "%s: pdata is NULL\n", "wcd938x_codec_enable_vdd_buck");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( (msm_cdc_is_ondemand_supply() & 1) != 0 )
  {
    if ( a3 == 8 )
    {
      _X8 = v4 + 44;
      __asm { PRFM            #0x11, [X8] }
      do
        v14 = __ldxr(_X8);
      while ( __stxr(v14 | 0x10, _X8) );
    }
    else if ( a3 == 1 )
    {
      if ( (v4[44] & 0x10) != 0 )
      {
        _X8 = v4 + 44;
        __asm { PRFM            #0x11, [X8] }
        do
          v17 = __ldxr(_X8);
        while ( __stxr(v17 & 0xFFFFFFFFFFFFFFEFLL, _X8) );
      }
      else
      {
        if ( (unsigned int)msm_cdc_enable_ondemand_supply(
                             *v4,
                             v4[386],
                             *(_QWORD *)(v5 + 56),
                             *(unsigned int *)(v5 + 64),
                             "cdc-vdd-buck") == -22 )
        {
          if ( (unsigned int)__ratelimit(&wcd938x_codec_enable_vdd_buck__rs_339, "wcd938x_codec_enable_vdd_buck") )
          {
            dev_err(*(_QWORD *)(v3 - 184), "%s: vdd buck is not enabled\n", "wcd938x_codec_enable_vdd_buck");
            return 4294967274LL;
          }
          return 4294967274LL;
        }
        _X8 = v4 + 44;
        __asm { PRFM            #0x11, [X8] }
        do
          v20 = __ldxr(_X8);
        while ( __stxr(v20 & 0xFFFFFFFFFFFFFFEFLL, _X8) );
        usleep_range_state(200, 250, 2);
      }
    }
  }
  return 0;
}
