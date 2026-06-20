__int64 __fastcall sap_random_channel_sel(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x21
  _QWORD *v20; // x22
  __int64 sap_ch_sw_info; // x0
  int v22; // w8
  __int64 v23; // x20
  __int64 v24; // x9
  __int64 v25; // x10
  char v26; // w11
  __int64 v27; // x10
  int v28; // w8
  int v29; // w11
  int v30; // w10
  int v31; // w11
  int v32; // w22
  __int64 v33; // x1
  const char *v34; // x2
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned __int16 _2g_first_safe_chan_freq; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  int v61; // w22
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  int v70; // w8
  __int64 v71; // [xsp+8h] [xbp-28h] BYREF
  __int64 v72; // [xsp+10h] [xbp-20h]
  __int64 v73; // [xsp+18h] [xbp-18h]
  int v74; // [xsp+20h] [xbp-10h] BYREF
  unsigned __int16 v75; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v76; // [xsp+28h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v75 = 0;
  v74 = 0;
  v72 = 0;
  v73 = 0;
  v71 = 0;
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v34 = "%s: Invalid MAC context";
LABEL_22:
    qdf_trace_msg(0x39u, 2u, v34, v11, v12, v13, v14, v15, v16, v17, v18, "sap_random_channel_sel");
    result = 0;
    goto LABEL_32;
  }
  v19 = context[2695];
  if ( !v19 )
  {
    v34 = "%s: null pdev";
    goto LABEL_22;
  }
  v20 = context;
  sap_ch_sw_info = wlan_get_sap_ch_sw_info(*(_QWORD *)(a1 + 16), v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !sap_ch_sw_info )
  {
    v34 = "%s: Invalid channel info";
    goto LABEL_22;
  }
  v22 = *(_DWORD *)(sap_ch_sw_info + 12);
  v23 = sap_ch_sw_info;
  if ( !v22 )
  {
    LOWORD(v22) = *(_WORD *)(a1 + 1498);
    *(_DWORD *)(sap_ch_sw_info + 12) = (unsigned __int8)v22;
  }
  *(_DWORD *)(sap_ch_sw_info + 20) = (unsigned __int8)v22;
  v24 = *(_QWORD *)(a1 + 1536);
  if ( v24 )
  {
    v25 = *(_QWORD *)(v24 + 32);
    v26 = *(_BYTE *)(v24 + 40);
    LOBYTE(v24) = *(_BYTE *)v24;
    v72 = v25;
    LOBYTE(v73) = v26;
  }
  v27 = v20[1];
  LOBYTE(v71) = v24;
  v28 = *((unsigned __int8 *)v20 + 14810);
  v29 = *(unsigned __int8 *)(v27 + 3173);
  v30 = *(unsigned __int8 *)(v27 + 3174);
  if ( v29 )
    v31 = 16;
  else
    v31 = 0;
  if ( v30 )
    v32 = v31 | 0x100;
  else
    v32 = v31;
  if ( v28 != 2 )
  {
    if ( v28 == 1 )
      v32 |= 8u;
    v33 = *(unsigned int *)(a1 + 1744);
    if ( !(_DWORD)v33 )
      goto LABEL_26;
LABEL_24:
    if ( *(_DWORD *)a1 != (_DWORD)v33 && (utils_dfs_is_freq_in_nol(v19, v33) & 1) == 0 )
    {
      v61 = *(_DWORD *)(a1 + 1744);
      v75 = v61;
      wlan_reg_set_channel_params_for_pwrmode(
        v19,
        (unsigned __int16)v61,
        0,
        v23 + 20,
        0,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43);
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: random chan select candidate freq=%d",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        "sap_random_channel_sel",
        (unsigned __int16)v61);
      *(_DWORD *)(a1 + 1744) = 0;
      goto LABEL_31;
    }
    goto LABEL_26;
  }
  v32 |= 4u;
  v33 = *(unsigned int *)(a1 + 1744);
  if ( (_DWORD)v33 )
    goto LABEL_24;
LABEL_26:
  if ( !(unsigned int)utils_dfs_get_vdev_random_channel_for_freq(
                        v19,
                        *(_QWORD *)(a1 + 16),
                        v32 | 0x400u,
                        v23 + 20,
                        &v74,
                        &v75,
                        &v71) )
  {
LABEL_31:
    v70 = *(_DWORD *)(v23 + 20);
    result = v75;
    *(_DWORD *)(v23 + 16) = v70;
    *(_DWORD *)(a1 + 1500) = v70;
    *(_BYTE *)(a1 + 1504) = *(_BYTE *)(v23 + 24);
    *(_BYTE *)(a1 + 1505) = *(_BYTE *)(v23 + 25);
    *(_BYTE *)(a1 + 1506) = *(_BYTE *)(v23 + 26);
    goto LABEL_32;
  }
  _2g_first_safe_chan_freq = wlansap_get_2g_first_safe_chan_freq(a1);
  v75 = _2g_first_safe_chan_freq;
  if ( _2g_first_safe_chan_freq )
  {
    wlan_reg_set_channel_params_for_pwrmode(
      v19,
      _2g_first_safe_chan_freq,
      0,
      v23 + 20,
      0,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52);
    goto LABEL_31;
  }
  qdf_trace_msg(
    0x39u,
    2u,
    "%s: No available channel found!!!",
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    "sap_random_channel_sel");
  sap_signal_hdd_event(a1, 0, 0x12u, nullptr, v53, v54, v55, v56, v57, v58, v59, v60);
  result = 0;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
