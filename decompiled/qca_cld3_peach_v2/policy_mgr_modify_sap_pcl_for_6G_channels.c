__int64 __fastcall policy_mgr_modify_sap_pcl_for_6G_channels(__int64 a1, void *a2, void *a3, unsigned int *a4)
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
  const char *v17; // x2
  __int64 result; // x0
  __int64 v19; // x22
  __int64 *v20; // x24
  int v21; // w26
  unsigned int v22; // w25
  __int64 v23; // x0
  __int64 v24; // x24
  unsigned int curr_6g_power_type; // w25
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
  char keep_6ghz_sta_cli_connection; // w0
  char v43; // w26
  __int64 v44; // x27
  unsigned int v45; // w23
  unsigned __int64 v46; // x8
  __int64 is_6ghz_chan_freq; // x0
  __int64 v48; // x1
  __int64 v49; // x2
  __int64 v50; // x3
  __int64 v51; // x4
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  size_t v60; // x1
  unsigned int *v61; // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  _BYTE v70[4]; // [xsp+Ch] [xbp-214h] BYREF
  _QWORD v71[13]; // [xsp+10h] [xbp-210h] BYREF
  _DWORD s[102]; // [xsp+78h] [xbp-1A8h] BYREF
  __int64 v73; // [xsp+210h] [xbp-10h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  memset(v71, 0, 102);
  v70[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "policy_mgr_modify_sap_pcl_for_6G_channels");
    result = 16;
    goto LABEL_41;
  }
  if ( *a4 >= 0x67 )
  {
    v17 = "%s: Invalid PCL List Length %d";
LABEL_4:
    qdf_trace_msg(0x4Fu, 2u, v17, v9, v10, v11, v12, v13, v14, v15, v16, "policy_mgr_modify_sap_pcl_for_6G_channels");
    result = 16;
LABEL_41:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v19 = context;
  qdf_mutex_acquire(context + 56);
  if ( ((unsigned int)pm_conc_connection_list | 2) != 2
    || BYTE4(qword_8D4F00) != 1
    || (v20 = &pm_conc_connection_list, !wlan_reg_is_6ghz_chan_freq(WORD2(pm_conc_connection_list))) )
  {
    if ( ((unsigned int)qword_8D4F0C | 2) != 2
      || BYTE4(qword_8D4F24) != 1
      || (v20 = &qword_8D4F0C, !wlan_reg_is_6ghz_chan_freq(WORD2(qword_8D4F0C))) )
    {
      if ( ((unsigned int)qword_8D4F30 | 2) != 2
        || BYTE4(qword_8D4F48) != 1
        || (v20 = &qword_8D4F30, !wlan_reg_is_6ghz_chan_freq(WORD2(qword_8D4F30))) )
      {
        if ( ((unsigned int)qword_8D4F54 | 2) != 2
          || BYTE4(qword_8D4F6C) != 1
          || (v20 = &qword_8D4F54, !wlan_reg_is_6ghz_chan_freq(WORD2(qword_8D4F54))) )
        {
          if ( ((unsigned int)qword_8D4F78 | 2) != 2
            || BYTE4(qword_8D4F90) != 1
            || (v20 = &qword_8D4F78, !wlan_reg_is_6ghz_chan_freq(WORD2(qword_8D4F78))) )
          {
            qdf_mutex_release(v19 + 56);
            goto LABEL_40;
          }
        }
      }
    }
  }
  v21 = *((_DWORD *)v20 + 1);
  v22 = *((_DWORD *)v20 + 6);
  qdf_mutex_release(v19 + 56);
  if ( !v21 )
  {
LABEL_40:
    result = 0;
    goto LABEL_41;
  }
  v23 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v22, 24);
  if ( !v23 )
  {
    v17 = "%s: vdev %d is not present";
    goto LABEL_4;
  }
  v24 = v23;
  curr_6g_power_type = wlan_mlme_get_curr_6g_power_type();
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: STA power type : %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "policy_mgr_modify_sap_pcl_for_6G_channels",
    curr_6g_power_type);
  ucfg_mlme_get_indoor_channel_support(a1, v70);
  keep_6ghz_sta_cli_connection = wlan_reg_get_keep_6ghz_sta_cli_connection(
                                   *(_QWORD *)(v19 + 8),
                                   v34,
                                   v35,
                                   v36,
                                   v37,
                                   v38,
                                   v39,
                                   v40,
                                   v41);
  if ( !*a4 )
  {
    v45 = 0;
    v60 = 0;
LABEL_39:
    qdf_mem_set(a2, v60, 0);
    qdf_mem_set(a3, *a4, 0);
    qdf_mem_copy(a2, s, 4 * v45);
    qdf_mem_copy(a3, v71, v45);
    *a4 = v45;
    wlan_objmgr_vdev_release_ref(v24, 0x18u, v61, v62, v63, v64, v65, v66, v67, v68, v69);
    goto LABEL_40;
  }
  v43 = keep_6ghz_sta_cli_connection;
  v44 = 0;
  v45 = 0;
  while ( 1 )
  {
    is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(*((_DWORD *)a2 + v44));
    if ( (is_6ghz_chan_freq & 1) != 0 )
    {
      is_6ghz_chan_freq = wlan_reg_is_6ghz_psc_chan_freq(*((_DWORD *)a2 + v44), v52, v53, v54, v55, v56, v57, v58, v59);
      if ( v43 & 1 | ((is_6ghz_chan_freq & 1) == 0) )
        goto LABEL_26;
      if ( (curr_6g_power_type & 0xFFFFFFFE) != 2 )
      {
        if ( curr_6g_power_type )
          goto LABEL_26;
        is_6ghz_chan_freq = wlan_reg_is_freq_indoor();
        if ( (is_6ghz_chan_freq & 1) != 0 && v70[0] != 1 )
          goto LABEL_26;
      }
    }
    if ( v45 > 0x65 )
      break;
    s[v45] = *((_DWORD *)a2 + v44);
    *((_BYTE *)v71 + v45++) = *((_BYTE *)a3 + v44);
LABEL_26:
    v46 = *a4;
    if ( ++v44 >= v46 )
    {
      v60 = (unsigned int)(4 * v46);
      goto LABEL_39;
    }
  }
  __break(0x5512u);
  return policy_mgr_modify_sap_go_4th_conc_disallow(is_6ghz_chan_freq, v48, v49, v50, v51);
}
