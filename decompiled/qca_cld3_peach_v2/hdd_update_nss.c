__int64 __fastcall hdd_update_nss(
        __int64 *a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w23
  unsigned int v14; // w24
  __int64 v15; // x26
  __int64 v16; // x22
  const char *v18; // x2
  __int64 result; // x0
  const char *v20; // x2
  __int64 v21; // x21
  __int64 v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _BOOL4 v31; // w8
  int v33; // w23
  const char *v34; // x2
  unsigned int v35; // w1
  const char *v36; // x2
  int v37; // w1
  int v39; // w23
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w24
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  const char *v65; // x2
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int16 v74; // w8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  const char *v91; // x2
  int updated; // w19
  _BYTE v93[4]; // [xsp+8h] [xbp-48h] BYREF
  __int16 v94; // [xsp+Ch] [xbp-44h] BYREF
  size_t v95; // [xsp+10h] [xbp-40h] BYREF
  _BYTE v96[4]; // [xsp+1Ch] [xbp-34h] BYREF
  _BYTE v97[4]; // [xsp+20h] [xbp-30h] BYREF
  _BYTE v98[4]; // [xsp+24h] [xbp-2Ch] BYREF
  _QWORD v99[2]; // [xsp+28h] [xbp-28h] BYREF
  _QWORD s[3]; // [xsp+38h] [xbp-18h] BYREF

  v11 = (unsigned __int8)a2;
  v14 = (unsigned __int8)a3;
  s[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *a1;
  v96[0] = 0;
  v94 = 0;
  v16 = *(_QWORD *)(v15 + 24);
  s[0] = 0;
  s[1] = 0;
  v99[0] = 0;
  v99[1] = 0;
  v93[0] = 0;
  if ( ((unsigned __int8)a2 == 2 || (unsigned __int8)a3 == 2) && *(_DWORD *)(v16 + 1248) != 2 )
  {
    v20 = "%s: No support for 2 spatial streams";
LABEL_11:
    qdf_trace_msg(0x33u, 2u, v20, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_update_nss");
    goto LABEL_12;
  }
  if ( (unsigned __int8)a2 > 2u || (unsigned __int8)a3 >= 3u )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Cannot support tx_nss: %d rx_nss: %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hdd_update_nss",
      (unsigned __int8)a2,
      (unsigned __int8)a3);
LABEL_12:
    result = 4;
    goto LABEL_13;
  }
  if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(*(_QWORD *)v16, v93) )
  {
    v18 = "%s: unable to get vht_enable2x2";
LABEL_8:
    qdf_trace_msg(0x33u, 2u, v18, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_update_nss");
    result = 16;
    goto LABEL_13;
  }
  v21 = *(_QWORD *)(v16 + 16);
  if ( !v21 )
  {
    v20 = "%s: NULL MAC handle";
    goto LABEL_11;
  }
  if ( *(_BYTE *)(v16 + 3752) == 1 )
  {
    v22 = *a1;
    v97[0] = 0;
    wlan_mlme_get_restart_sap_on_dynamic_nss_chains_cfg(**(_QWORD **)(v22 + 24), v97);
    v31 = 0;
    if ( v97[0] == 1 )
    {
      LOBYTE(v95) = 0;
      v98[0] = 0;
      hdd_get_sap_rx_nss(a1, &v95);
      hdd_get_sap_tx_nss(a1, v98);
      v31 = (unsigned __int8)v95 != (unsigned __int8)a3 && v98[0] != (unsigned __int8)a2;
    }
    if ( (*(_DWORD *)(v15 + 40) | 2) == 3 && v31 )
    {
      if ( (unsigned __int8)a2 == 2 && (unsigned __int8)a3 == 2 || (unsigned __int8)a2 == 1 && (unsigned __int8)a3 == 1 )
      {
        hdd_update_nss_in_vdev(a1, v21, a2, a3);
        hdd_restart_sap(a1);
        result = 0;
        goto LABEL_13;
      }
      v36 = "%s: tx_nss %d rx_nss %d not supported ";
LABEL_56:
      qdf_trace_msg(0x33u, 2u, v36, v23, v24, v25, v26, v27, v28, v29, v30, "hdd_update_nss", v11, v14);
      result = 16;
      goto LABEL_13;
    }
    if ( (hdd_is_vdev_in_conn_state(a1) & 1) != 0 )
    {
      result = hdd_set_nss_params(a1, a2, a3);
      goto LABEL_13;
    }
    if ( (unsigned __int8)a2 != (unsigned __int8)a3 )
    {
      v36 = "%s: TX NSS = %d, RX NSS  = %d value mismatch, doesn't support asymmetric config in disconnected state";
      goto LABEL_56;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Vdev %d in disconnect state, changing ini nss params",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hdd_update_nss",
      *((unsigned __int8 *)a1 + 8));
    if ( v93[0] )
    {
      hdd_update_nss_in_vdev(a1, v21, a2, a2);
      sme_set_nss_capability(v21, *((unsigned __int8 *)a1 + 8), a2, *(unsigned int *)(v15 + 40));
      result = 0;
      goto LABEL_13;
    }
    v34 = "%s: Nss in 1x1, no change required, 2x2 mode disabled";
    v35 = 2;
LABEL_33:
    qdf_trace_msg(0x33u, v35, v34, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_update_nss");
    result = 0;
    goto LABEL_13;
  }
  v33 = (unsigned __int8)a3 > 1u;
  if ( v93[0] == v33 )
  {
    v34 = "%s: NSS same as requested";
    v35 = 8;
    goto LABEL_33;
  }
  if ( (sme_is_any_session_in_connected_state(*(_QWORD *)(v16 + 16)) & 1) != 0 )
  {
    v20 = "%s: Connected sessions present, Do not change NSS";
    goto LABEL_11;
  }
  if ( (unsigned int)wlan_mlme_set_vht_mimo_cap(*(_QWORD *)v16, v33) )
  {
    v18 = "%s: Failed to set vht_enable2x2";
    goto LABEL_8;
  }
  if ( (a3 & 0xFE) != 0 )
    v37 = 780;
  else
    v37 = 390;
  if ( (unsigned __int8)a3 == 2 && (unsigned __int8)a2 == 1 )
    v39 = 390;
  else
    v39 = v37;
  if ( (unsigned int)wlan_mlme_cfg_set_vht_rx_supp_data_rate(*(_QWORD *)v16, v37) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set rx_supp_data_rate",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "hdd_update_nss");
    v48 = 0;
  }
  else
  {
    v48 = 16;
  }
  if ( (unsigned int)wlan_mlme_cfg_set_vht_tx_supp_data_rate(*(_QWORD *)v16, v39) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set tx_supp_data_rate",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "hdd_update_nss");
    v48 = 0;
  }
  if ( (unsigned int)wlan_mlme_get_ht_cap_info(*(_QWORD *)v16, &v94) )
  {
    v65 = "%s: Failed to get HT Cap info";
    goto LABEL_71;
  }
  if ( (unsigned __int8)a3 >= 2u && *(_BYTE *)(v16 + 1252) )
  {
    if ( !(unsigned int)wlan_mlme_cfg_get_vht_tx_stbc(*(_QWORD *)v16, v96) )
    {
      v74 = v94;
      goto LABEL_69;
    }
    qdf_trace_msg(0x33u, 2u, "%s: Failed to get vht_tx_stbc", v66, v67, v68, v69, v70, v71, v72, v73, "hdd_update_nss");
    v74 = v94 & 0xFF7F | ((v96[0] & 1) << 7);
  }
  else
  {
    v74 = v94 & 0xFF7F;
  }
  v94 = v74;
LABEL_69:
  if ( !(unsigned int)wlan_mlme_set_ht_cap_info(*(_QWORD *)v16, v74) )
    goto LABEL_72;
  v65 = "%s: Could not set the HT_CAP_INFO";
LABEL_71:
  qdf_trace_msg(0x33u, 2u, v65, v57, v58, v59, v60, v61, v62, v63, v64, "hdd_update_nss");
LABEL_72:
  if ( (unsigned int)mlme_update_nss_vht_cap(*(_QWORD *)v16) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set update_nss_vht_cap",
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      "hdd_update_nss");
    v48 = 0;
  }
  v95 = 16;
  if ( (unsigned int)ucfg_mlme_get_supported_mcs_set(*(_QWORD *)v16, v99, &v95) )
  {
    v91 = "%s: Could not get MCS SET from CFG";
  }
  else
  {
    LOBYTE(s[0]) = v99[0];
    if ( (unsigned __int8)a3 >= 2u )
    {
      memset(s, 255, (unsigned __int8)a3);
      v95 = (unsigned __int8)a3;
    }
    if ( (unsigned int)ucfg_mlme_set_supported_mcs_set(*(_QWORD *)v16, s, 0x10u) != 16 )
      goto LABEL_81;
    v91 = "%s: Could not pass on MCS SET to CFG";
  }
  qdf_trace_msg(0x33u, 2u, v91, v83, v84, v85, v86, v87, v88, v89, v90, "hdd_update_nss");
  v48 = 0;
LABEL_81:
  sme_set_nss_capability(v21, *((unsigned __int8 *)a1 + 8), a3, *(unsigned int *)(v15 + 40));
  updated = sme_update_nss(v21, a3);
  hdd_set_policy_mgr_user_cfg((__int64 *)v16);
  if ( updated )
    result = 16;
  else
    result = ~v48 & 0x10;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
