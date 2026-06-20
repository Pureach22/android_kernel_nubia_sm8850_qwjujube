bool __fastcall wlansap_is_channel_leaking_in_nol(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int16 a10,
        unsigned __int8 a11)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x1
  _BOOL4 v22; // w19
  int v23; // w0
  __int16 v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = a10;
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    v21 = a11;
    v22 = 1;
    utils_dfs_mark_leaking_chan_for_freq(context[2695], v21, 1, &v25);
    if ( !v23 )
      v22 = v25 == 0;
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid MAC context",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlansap_is_channel_leaking_in_nol");
    v22 = 1;
  }
  _ReadStatusReg(SP_EL0);
  return v22;
}
