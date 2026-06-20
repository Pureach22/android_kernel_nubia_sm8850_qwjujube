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
  unsigned __int16 _2g_first_safe_chan_freq; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w22
  __int64 v54; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  char v63; // w0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  int v72; // w8
  __int64 v73; // [xsp+8h] [xbp-28h] BYREF
  __int64 v74; // [xsp+10h] [xbp-20h]
  __int64 v75; // [xsp+18h] [xbp-18h]
  int v76; // [xsp+20h] [xbp-10h] BYREF
  unsigned __int16 v77; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v78; // [xsp+28h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v77 = 0;
  v76 = 0;
  v74 = 0;
  v75 = 0;
  v73 = 0;
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v34 = "%s: Invalid MAC context";
LABEL_22:
    qdf_trace_msg(0x39u, 2u, v34, v11, v12, v13, v14, v15, v16, v17, v18, "sap_random_channel_sel");
    result = 0;
    goto LABEL_34;
  }
  v19 = context[2704];
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
  v24 = *(_QWORD *)(a1 + 1544);
  if ( v24 )
  {
    v25 = *(_QWORD *)(v24 + 32);
    v26 = *(_BYTE *)(v24 + 40);
    LOBYTE(v24) = *(_BYTE *)v24;
    v74 = v25;
    LOBYTE(v75) = v26;
  }
  v27 = v20[1];
  LOBYTE(v73) = v24;
  v28 = *((unsigned __int8 *)v20 + 14882);
  v29 = *(unsigned __int8 *)(v27 + 3373);
  v30 = *(unsigned __int8 *)(v27 + 3374);
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
    v33 = *(unsigned int *)(a1 + 1768);
    if ( !(_DWORD)v33 )
      goto LABEL_26;
LABEL_24:
    if ( *(_DWORD *)a1 != (_DWORD)v33 && (utils_dfs_is_freq_in_nol(v19, v33) & 1) == 0 )
    {
      v53 = *(_DWORD *)(a1 + 1768);
      v54 = *(unsigned int *)(a1 + 1484);
      v77 = v53;
      v55 = sap_phymode_is_eht(v54);
      if ( (v63 & 1) != 0 )
        wlan_reg_set_create_punc_bitmap(v23 + 20, 1);
      wlan_reg_set_channel_params_for_pwrmode(
        v19,
        (unsigned __int16)v53,
        0,
        v23 + 20,
        0,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62);
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: random chan select candidate freq=%d",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "sap_random_channel_sel",
        (unsigned __int16)v53);
      *(_DWORD *)(a1 + 1768) = 0;
      goto LABEL_33;
    }
    goto LABEL_26;
  }
  v32 |= 4u;
  v33 = *(unsigned int *)(a1 + 1768);
  if ( (_DWORD)v33 )
    goto LABEL_24;
LABEL_26:
  if ( !(unsigned int)utils_dfs_get_vdev_random_channel_for_freq(
                        v19,
                        *(_QWORD *)(a1 + 16),
                        v32 | 0x400u,
                        v23 + 20,
                        &v76,
                        &v77,
                        &v73) )
  {
LABEL_33:
    v72 = *(_DWORD *)(v23 + 20);
    result = v77;
    *(_DWORD *)(v23 + 16) = v72;
    *(_DWORD *)(a1 + 1500) = v72;
    *(_BYTE *)(a1 + 1504) = *(_BYTE *)(v23 + 24);
    *(_BYTE *)(a1 + 1505) = *(_BYTE *)(v23 + 25);
    *(_BYTE *)(a1 + 1506) = *(_BYTE *)(v23 + 26);
    goto LABEL_34;
  }
  _2g_first_safe_chan_freq = wlansap_get_2g_first_safe_chan_freq(a1);
  v77 = _2g_first_safe_chan_freq;
  if ( _2g_first_safe_chan_freq )
  {
    wlan_reg_set_channel_params_for_pwrmode(
      v19,
      _2g_first_safe_chan_freq,
      0,
      v23 + 20,
      0,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44);
    goto LABEL_33;
  }
  qdf_trace_msg(
    0x39u,
    2u,
    "%s: No available channel found!!!",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "sap_random_channel_sel");
  sap_signal_hdd_event(a1, 0, 0x12u, nullptr, v45, v46, v47, v48, v49, v50, v51, v52);
  result = 0;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
