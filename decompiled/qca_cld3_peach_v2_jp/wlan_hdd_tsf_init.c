__int64 __fastcall wlan_hdd_tsf_init(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v15; // w8
  signed int v16; // w8
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x0
  int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    _X9 = (unsigned int *)(result + 3232);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v15 = __ldxr(_X9);
      v16 = v15 + 1;
    }
    while ( __stlxr(v16, _X9) );
    __dmb(0xBu);
    if ( v16 >= 2 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: TSF ready flag already set",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "wlan_hdd_tsf_init");
    }
    else
    {
      v17 = result;
      *(_DWORD *)(result + 3236) = 0;
      if ( (unsigned int)qdf_event_create(tsf_sync_get_completion_evt) )
      {
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: failed to create tsf_sync_get_completion_evt",
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   v25,
                   "wlan_hdd_tsf_init");
        *(_DWORD *)(v17 + 3232) = 0;
      }
      else
      {
        v26 = *(_QWORD *)v17;
        v27 = 0;
        result = ucfg_fwol_get_tsf_ptp_options(v26, &v27);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
