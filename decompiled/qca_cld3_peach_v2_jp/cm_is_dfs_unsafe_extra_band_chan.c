__int64 __fastcall cm_is_dfs_unsafe_extra_band_chan(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  __int64 v18; // x22
  char is_dfs_for_freq; // w8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  const char *v29; // x2
  __int64 result; // x0
  unsigned __int16 v31; // [xsp+4h] [xbp-DCh] BYREF
  _QWORD v32[25]; // [xsp+8h] [xbp-D8h] BYREF
  int v33; // [xsp+D0h] [xbp-10h]
  __int64 v34; // [xsp+D8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  memset(v32, 0, sizeof(v32));
  v31 = 0;
  context = _cds_get_context(64, "cm_is_dfs_unsafe_extra_band_chan");
  if ( !context )
    goto LABEL_22;
  v17 = *(_QWORD *)(a1 + 152);
  if ( !v17 )
    goto LABEL_22;
  if ( !*(_DWORD *)(a2 + 1752) || *(_DWORD *)(a2 + 2512) == 2 )
  {
    v18 = context;
    is_dfs_for_freq = wlan_reg_is_dfs_for_freq(v17, a3, v9, v10, v11, v12, v13, v14, v15, v16);
    context = v18;
    if ( (is_dfs_for_freq & 1) != 0 )
      goto LABEL_22;
  }
  cnss_utils_get_wlan_unsafe_channel(*(_QWORD *)(context + 40), v32, &v31, 204);
  if ( *(_BYTE *)(a2 + 2516) == 1 && v31 )
  {
    v28 = 0;
    v29 = "%s: ignoring unsafe channel freq %d";
    do
    {
      if ( v28 == 204 )
        __break(0x5512u);
      if ( *(unsigned __int16 *)((char *)v32 + v28) == a3 )
        goto LABEL_21;
      v28 += 2;
    }
    while ( 2LL * v31 != v28 );
  }
  if ( a4 )
  {
    if ( a4 == 2 )
    {
      if ( wlan_reg_is_5ghz_ch_freq(a3) )
        goto LABEL_19;
    }
    else if ( a4 == 1 && wlan_reg_is_24ghz_ch_freq(a3) )
    {
      goto LABEL_19;
    }
    if ( !wlan_reg_is_6ghz_chan_freq(a3) )
    {
      v29 = "%s: ignoring non-intra band freq %d";
LABEL_21:
      qdf_trace_msg(0x68u, 8u, v29, v20, v21, v22, v23, v24, v25, v26, v27, "cm_is_dfs_unsafe_extra_band_chan", a3);
LABEL_22:
      result = 1;
      goto LABEL_23;
    }
  }
LABEL_19:
  result = 0;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
