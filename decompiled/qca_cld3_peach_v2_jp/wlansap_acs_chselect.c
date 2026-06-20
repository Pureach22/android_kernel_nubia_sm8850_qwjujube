__int64 __fastcall wlansap_acs_chselect(
        unsigned int *a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v14; // w8
  _QWORD *context; // x0
  _QWORD *v16; // x21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  char v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  const char *v74; // x2
  __int64 result; // x0
  const char *v76; // x2
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  _BYTE v101[4]; // [xsp+Ch] [xbp-24h] BYREF
  _WORD v102[2]; // [xsp+10h] [xbp-20h] BYREF
  _BYTE v103[4]; // [xsp+14h] [xbp-1Ch] BYREF
  _BYTE v104[4]; // [xsp+18h] [xbp-18h] BYREF
  _BYTE v105[4]; // [xsp+1Ch] [xbp-14h] BYREF
  _BYTE v106[4]; // [xsp+20h] [xbp-10h] BYREF
  unsigned int v107; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v108; // [xsp+28h] [xbp-8h]

  v108 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v74 = "%s: Invalid SAP pointer";
LABEL_24:
    qdf_trace_msg(0x39u, 2u, v74, a4, a5, a6, a7, a8, a9, a10, a11, "wlansap_acs_chselect");
    result = 5;
    goto LABEL_25;
  }
  if ( !_cds_get_context(53, (__int64)"sap_get_mac_context", a4, a5, a6, a7, a8, a9, a10, a11) )
  {
    v74 = "%s: Invalid MAC context";
    goto LABEL_24;
  }
  v14 = a1[182];
  *((_QWORD *)a1 + 192) = a3 + 1136;
  *((_WORD *)a1 + 749) = *(_WORD *)(a3 + 1178);
  if ( v14 != 2 )
    a1[371] = *(_DWORD *)(a3 + 1140);
  v107 = 0;
  v106[0] = 0;
  v105[0] = 0;
  v104[0] = 0;
  v103[0] = 0;
  v102[0] = 0;
  v101[0] = 0;
  if ( a3 )
  {
    context = _cds_get_context(53, (__int64)"sap_get_mac_context", a4, a5, a6, a7, a8, a9, a10, a11);
    if ( context )
    {
      v16 = context;
      wlansap_set_acs_ch_freq(context, a1, *(unsigned int *)(a3 + 440));
      a1[405] = *(_DWORD *)(a3 + 1836);
      *((_BYTE *)a1 + 1552) = *(_BYTE *)(a3 + 1133);
      if ( (unsigned int)wlan_mlme_get_auto_channel_weight(v16[2694], (int *)&v107) )
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: get_auto_channel_weight failed",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "wlansap_set_scan_acs_channel_params");
      a1[381] = v107;
      v25 = *(_BYTE *)(a3 + 1132);
      *((_QWORD *)a1 + 192) = a3 + 1136;
      *((_BYTE *)a1 + 1528) = v25;
      *((_WORD *)a1 + 749) = *(_WORD *)(a3 + 1178);
      a1[1] = *(_DWORD *)(a3 + 444);
      qdf_mem_copy(a1 + 6, (const void *)(a3 + 432), 6u);
      if ( (unsigned int)wlan_mlme_get_acs_linear_bss_status(v16[2694], v106) )
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: get_acs_linear_bss_status failed",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "wlansap_set_scan_acs_channel_params");
      if ( (unsigned int)wlan_mlme_get_acs_linear_rssi_status(v16[2694], v105) )
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: get_acs_linear_rssi_status failed",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "wlansap_set_scan_acs_channel_params");
      if ( (unsigned int)wlan_mlme_get_acs_rssi_threshold_score(v16[2694], v102) )
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: get_acs_rssi_threshold_score failed",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "wlansap_set_scan_acs_channel_params");
      if ( (unsigned int)wlan_mlme_get_acs_same_chan_weight_rand_status(v16[2694], v104) )
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: get_acs_same_chan_weight_rand_status failed",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "wlansap_set_scan_acs_channel_params");
      if ( (unsigned int)wlan_mlme_get_acs_wifi_non_wifi_load_status(v16[2694], v103) )
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: get_acs_wifi_non_wifi_load_status failed",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "wlansap_set_scan_acs_channel_params");
      if ( (unsigned int)wlan_mlme_get_acs_early_terminate_status(v16[2694], v101) )
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: get_acs_early_terminate_status failed",
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          "wlansap_set_scan_acs_channel_params");
      *(_BYTE *)(*((_QWORD *)a1 + 192) + 600LL) = v106[0];
      *(_BYTE *)(*((_QWORD *)a1 + 192) + 601LL) = v105[0];
      *(_WORD *)(*((_QWORD *)a1 + 192) + 602LL) = v102[0];
      *(_BYTE *)(*((_QWORD *)a1 + 192) + 604LL) = v104[0];
      *(_BYTE *)(*((_QWORD *)a1 + 192) + 605LL) = v103[0];
      *(_BYTE *)(*((_QWORD *)a1 + 192) + 606LL) = v101[0];
      goto LABEL_29;
    }
    v76 = "%s: Invalid MAC context";
  }
  else
  {
    v76 = "%s: Invalid config passed ";
  }
  qdf_trace_msg(0x39u, 2u, v76, a4, a5, a6, a7, a8, a9, a10, a11, "wlansap_set_scan_acs_channel_params");
LABEL_29:
  *((_QWORD *)a1 + 90) = a2;
  result = sap_channel_sel(a1, v66, v67, v68, v69, v70, v71, v72, v73);
  if ( (_DWORD)result == 9 )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Scan Req Failed/ACS Overridden",
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      "wlansap_acs_chselect");
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Selected channel frequency = %d",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "wlansap_acs_chselect",
      *a1);
    result = sap_signal_hdd_event((__int64)a1, 0, 0x15u, nullptr, v93, v94, v95, v96, v97, v98, v99, v100);
  }
  else if ( (_DWORD)result == 10 )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: DFS not supported in the current operating mode",
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      "wlansap_acs_chselect");
    result = 16;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
