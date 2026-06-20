__int64 __fastcall sap_is_chan_change_needed_for_radar(unsigned int *a1, unsigned int *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  char v13; // w0
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x22
  __int64 sap_ch_sw_info; // x0
  int v25; // w8
  __int64 v26; // x21
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  char v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  int v52; // w1
  __int64 result; // x0
  const char *v54; // x2
  unsigned int v55; // w1
  int v56; // w8
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned __int16 v65; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v66; // [xsp+18h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[371];
  v65 = 0;
  v5 = sap_phymode_is_eht(v4);
  if ( (v13 & 1) == 0 )
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: phy mode: 0x%x",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "sap_is_chan_change_needed_for_radar",
      a1[371]);
LABEL_18:
    result = 1;
    goto LABEL_19;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", v5, v6, v7, v8, v9, v10, v11, v12);
  if ( !context )
  {
    v54 = "%s: Invalid MAC context";
LABEL_16:
    v55 = 2;
    goto LABEL_17;
  }
  v23 = context;
  if ( (wlan_mlme_get_sap_dfs_puncture(context[2703]) & 1) == 0 )
  {
    v54 = "%s: dfs punct disabled";
    v55 = 8;
LABEL_17:
    qdf_trace_msg(0x39u, v55, v54, v15, v16, v17, v18, v19, v20, v21, v22, "sap_is_chan_change_needed_for_radar");
    goto LABEL_18;
  }
  sap_ch_sw_info = wlan_get_sap_ch_sw_info(*((_QWORD *)a1 + 2), v15, v16, v17, v18, v19, v20, v21, v22);
  if ( !sap_ch_sw_info )
  {
    v54 = "%s: Invalid channel info";
    goto LABEL_16;
  }
  v25 = *(_DWORD *)(sap_ch_sw_info + 12);
  v26 = sap_ch_sw_info;
  if ( !v25 )
  {
    LOWORD(v25) = *((_WORD *)a1 + 749);
    *(_DWORD *)(sap_ch_sw_info + 12) = (unsigned __int8)v25;
  }
  *(_DWORD *)(sap_ch_sw_info + 20) = (unsigned __int8)v25;
  v27 = sap_phymode_is_eht(a1[371]);
  if ( (v35 & 1) != 0 )
    wlan_reg_set_create_punc_bitmap(v26 + 20, 1);
  wlan_reg_set_channel_params_for_pwrmode(v23[2704], *a1, 0, v26 + 20, 0, v27, v28, v29, v30, v31, v32, v33, v34);
  if ( *(_DWORD *)(v26 + 20) != a1[375] )
    goto LABEL_18;
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: punct, new 0x%x, old 0x%x",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "sap_is_same_punc",
    *(unsigned __int16 *)(v26 + 38),
    *((unsigned __int16 *)a1 + 759));
  v52 = *(unsigned __int16 *)(v26 + 38);
  if ( v52 == *((unsigned __int16 *)a1 + 759) )
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: No CSA needed, same freq %d, bw %d and puncture",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "sap_is_chan_change_needed_for_radar",
      *a1,
      *(unsigned int *)(v26 + 20));
    result = 0;
    *(_DWORD *)(v26 + 16) = *(_DWORD *)(v26 + 20);
    *a2 = 0;
  }
  else
  {
    v56 = wlan_reg_extract_puncture_by_bw(
            *(_DWORD *)(v26 + 20),
            v52,
            *a1,
            *(_DWORD *)(v26 + 32),
            0,
            &v65,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51);
    result = 1;
    if ( !v56 && !v65 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Eht valid puncture : 0x%x, keep freq %d bw %d ccfs0 %d ccfs1 %d",
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        "sap_is_chan_change_needed_for_radar",
        *(unsigned __int16 *)(v26 + 38),
        *a1,
        *(unsigned int *)(v26 + 20),
        *(unsigned int *)(v26 + 28),
        *(_DWORD *)(v26 + 32));
      result = 0;
      *(_DWORD *)(v26 + 16) = *(_DWORD *)(v26 + 20);
      *a2 = *a1;
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
