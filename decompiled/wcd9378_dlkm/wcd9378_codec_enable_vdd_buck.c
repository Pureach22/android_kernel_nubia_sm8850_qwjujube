__int64 __fastcall wcd9378_codec_enable_vdd_buck(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x21
  unsigned __int64 *v4; // x20
  __int64 v5; // x22
  unsigned __int64 v10; // x9
  unsigned __int64 v13; // x10
  unsigned __int64 v20; // x10

  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(unsigned __int64 **)(*(_QWORD *)(v3 - 184) + 152LL);
  v5 = *(_QWORD *)(*v4 + 144);
  if ( !v5 )
  {
    dev_err(*(_QWORD *)(v3 - 184), "%s: pdata is NULL\n", "wcd9378_codec_enable_vdd_buck");
    return 4294967274LL;
  }
  if ( (msm_cdc_is_ondemand_supply() & 1) != 0 )
  {
    if ( a3 == 8 )
    {
      _X8 = v4 + 57;
      __asm { PRFM            #0x11, [X8] }
      do
        v10 = __ldxr(_X8);
      while ( __stxr(v10 | 8, _X8) );
      return 0;
    }
    if ( a3 == 1 )
    {
      if ( (v4[57] & 8) != 0 )
      {
        _X8 = v4 + 57;
        __asm { PRFM            #0x11, [X8] }
        do
          v13 = __ldxr(_X8);
        while ( __stxr(v13 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
        return 0;
      }
      if ( (unsigned int)msm_cdc_enable_ondemand_supply(
                           *v4,
                           v4[399],
                           *(_QWORD *)(v5 + 64),
                           *(unsigned int *)(v5 + 72),
                           "cdc-vdd-buck") != -22 )
      {
        _X8 = v4 + 57;
        __asm { PRFM            #0x11, [X8] }
        do
          v20 = __ldxr(_X8);
        while ( __stxr(v20 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
        usleep_range_state(200, 250, 2);
        return 0;
      }
      dev_err(*(_QWORD *)(v3 - 184), "%s: vdd buck is not enabled\n", "wcd9378_codec_enable_vdd_buck");
      return 4294967274LL;
    }
  }
  return 0;
}
