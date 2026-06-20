__int64 __fastcall policy_mgr_modify_sap_pcl_based_on_mandatory_channel(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        _DWORD *a4,
        unsigned int a5)
{
  char sta_sap_scc_allowed_on_indoor_chnl; // w23
  __int64 context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned __int64 v19; // x20
  __int64 v20; // x24
  __int64 v21; // x8
  __int64 v22; // x28
  bool is_24ghz_ch_freq; // w0
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x27
  __int64 *v34; // x8
  const char *v35; // x2
  __int64 result; // x0
  char is_connected_sta_5g; // w27
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  bool v46; // w28
  int v47; // w20
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x26
  unsigned __int64 v57; // x25
  __int64 v58; // x4
  const char *v59; // x2
  __int64 v60; // x9
  __int64 v61; // x9
  __int64 v62; // x10
  unsigned int v63; // [xsp+4h] [xbp-4Ch]
  unsigned int v65; // [xsp+10h] [xbp-40h] BYREF
  _BYTE v66[4]; // [xsp+14h] [xbp-3Ch] BYREF
  _BYTE v67[4]; // [xsp+18h] [xbp-38h] BYREF
  int v68; // [xsp+1Ch] [xbp-34h] BYREF
  __int64 v69; // [xsp+20h] [xbp-30h] BYREF
  int v70; // [xsp+28h] [xbp-28h] BYREF
  char v71; // [xsp+2Ch] [xbp-24h]
  _QWORD v72[2]; // [xsp+30h] [xbp-20h] BYREF
  int v73; // [xsp+40h] [xbp-10h]
  __int64 v74; // [xsp+48h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v69 = 0;
  v68 = 0;
  v67[0] = 0;
  v66[0] = 0;
  sta_sap_scc_allowed_on_indoor_chnl = policy_mgr_get_sta_sap_scc_allowed_on_indoor_chnl(a1);
  v73 = 0;
  v72[0] = 0;
  v72[1] = 0;
  v71 = 0;
  v70 = 0;
  v65 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v35 = "%s: Invalid Context";
LABEL_29:
    qdf_trace_msg(
      0x4Fu,
      2u,
      v35,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "policy_mgr_modify_sap_pcl_based_on_mandatory_channel");
    result = 16;
    goto LABEL_73;
  }
  v19 = *(unsigned int *)(context + 960);
  v20 = context;
  if ( !(_DWORD)v19 )
  {
    result = 0;
    goto LABEL_73;
  }
  if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(context + 552)) )
  {
    v21 = 0;
    do
    {
      v22 = v21;
      if ( v19 - 1 == v21 )
        break;
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v20 + 556 + 4 * v21));
      v21 = v22 + 1;
    }
    while ( !is_24ghz_ch_freq );
    if ( v22 + 1 >= v19 )
    {
      v35 = "%s: fav channel list is missing 2.4GHz channels";
      goto LABEL_29;
    }
  }
  policy_mgr_dump_sap_mandatory(v20);
  if ( (sta_sap_scc_allowed_on_indoor_chnl & 1) != 0 )
  {
    v24 = policy_mgr_get_context(a1);
    if ( v24 )
    {
      v33 = v24;
      qdf_mutex_acquire(v24 + 56);
      if ( !(_DWORD)pm_conc_connection_list
        && (wlan_reg_is_freq_indoor() & 1) != 0
        && (v34 = &pm_conc_connection_list, BYTE4(qword_8D4F00) == 1)
        || !(_DWORD)qword_8D4F0C
        && (wlan_reg_is_freq_indoor() & 1) != 0
        && (v34 = &qword_8D4F0C, (qword_8D4F24 & 0x100000000LL) != 0)
        || !(_DWORD)qword_8D4F30
        && (wlan_reg_is_freq_indoor() & 1) != 0
        && (v34 = &qword_8D4F30, (qword_8D4F48 & 0x100000000LL) != 0)
        || !(_DWORD)qword_8D4F54
        && (wlan_reg_is_freq_indoor() & 1) != 0
        && (v34 = &qword_8D4F54, (qword_8D4F6C & 0x100000000LL) != 0)
        || !(_DWORD)qword_8D4F78
        && (wlan_reg_is_freq_indoor() & 1) != 0
        && (v34 = &qword_8D4F78, (qword_8D4F90 & 0x100000000LL) != 0) )
      {
        v63 = *((_DWORD *)v34 + 1);
      }
      else
      {
        v63 = 0;
      }
      qdf_mutex_release(v33 + 56);
      goto LABEL_34;
    }
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "policy_mgr_is_sta_on_indoor_channel");
  }
  v63 = 0;
LABEL_34:
  policy_mgr_get_sta_sap_scc_on_dfs_chnl(a1, v66);
  if ( v66[0] )
    policy_mgr_is_sta_present_on_dfs_channel(a1, v67, (_DWORD *)&v69 + 1, &v68);
  is_connected_sta_5g = policy_mgr_is_connected_sta_5g(a1, &v69);
  if ( (unsigned __int8)policy_mgr_get_mode_specific_conn_info(a1, (unsigned __int64)v72, (unsigned __int64)&v70, 3u)
    && !wlan_reg_is_24ghz_ch_freq(v72[0]) )
  {
    v47 = v72[0];
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: go 5/6G present, SAP exclude 5/6G channels",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "policy_mgr_modify_sap_pcl_based_on_mandatory_channel");
    v46 = v47 == 0;
  }
  else
  {
    v46 = 1;
  }
  policy_mgr_get_ap_6ghz_capable(a1, a5, &v65);
  if ( !*a4 )
  {
    LODWORD(v57) = 0;
    goto LABEL_72;
  }
  v56 = 0;
  v57 = 0;
  while ( v56 != 102 )
  {
    if ( v46 || wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 4 * v56)) )
    {
      if ( (sta_sap_scc_allowed_on_indoor_chnl & 1) != 0
        && policy_mgr_is_force_scc(a1)
        && *(_DWORD *)(a2 + 4 * v56) == v63
        && (wlan_reg_is_5ghz_ch_freq(v63) || wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 4 * v56)) && (v65 & 2) != 0) )
      {
        v58 = *(unsigned int *)(a2 + 4 * v56);
        v59 = "%s: indoor chan:%d";
        goto LABEL_61;
      }
      if ( v66[0] )
      {
        if ( policy_mgr_is_force_scc(a1) )
        {
          v58 = *(unsigned int *)(a2 + 4 * v56);
          if ( (_DWORD)v58 == HIDWORD(v69) )
          {
            v59 = "%s: dfs chan:%d";
            goto LABEL_61;
          }
        }
      }
      if ( (is_connected_sta_5g & 1) != 0 && policy_mgr_is_force_scc(a1) )
      {
        v58 = *(unsigned int *)(a2 + 4 * v56);
        if ( (_DWORD)v58 == (_DWORD)v69 )
        {
          v59 = "%s: scc chan:%d";
LABEL_61:
          qdf_trace_msg(
            0x4Fu,
            8u,
            v59,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "policy_mgr_modify_sap_pcl_based_on_mandatory_channel",
            v58);
LABEL_62:
          if ( v57 <= 0x65 )
          {
            *(_DWORD *)(a2 + 4 * v57) = *(_DWORD *)(a2 + 4 * v56);
            *(_BYTE *)(a3 + v57++) = *(_BYTE *)(a3 + v56);
          }
          goto LABEL_42;
        }
      }
      v60 = *(unsigned int *)(v20 + 960);
      if ( (_DWORD)v60 )
      {
        v61 = 4 * v60;
        v62 = 0;
        do
        {
          if ( v62 == 408 )
            __break(0x5512u);
          if ( *(_DWORD *)(a2 + 4 * v56) == *(_DWORD *)(v20 + 552 + v62) )
            goto LABEL_62;
          v62 += 4;
        }
        while ( v61 != v62 );
      }
    }
LABEL_42:
    if ( ++v56 >= (unsigned __int64)(unsigned int)*a4 )
      goto LABEL_72;
  }
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: index is exceeding NUM_CHANNELS",
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    "policy_mgr_modify_sap_pcl_based_on_mandatory_channel");
LABEL_72:
  result = 0;
  *a4 = v57;
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return result;
}
