__int64 __fastcall policy_mgr_modify_sap_pcl_filter_mcc(__int64 a1, __int64 a2, __int64 a3, unsigned int *a4, int a5)
{
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  char is_hw_dbs_capable; // w0
  char v27; // w24
  __int64 v28; // x23
  unsigned int v29; // w25
  unsigned int v30; // w28
  int mode_specific_conn_info; // w24
  __int64 v32; // x0
  __int64 v33; // x1
  __int64 v34; // x2
  __int64 v35; // x3
  __int64 v36; // x4
  __int64 v37; // x5
  __int64 v38; // x6
  __int64 context; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x26
  unsigned int v49; // w24
  unsigned int v50; // w27
  unsigned int v51; // w27
  unsigned int v52; // w27
  unsigned int v53; // w27
  unsigned int v54; // w27
  unsigned int v55; // w26
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x0
  __int64 v65; // x27
  char v66; // [xsp+Ch] [xbp-34h]
  char ll_lt_sap_vdev_id; // [xsp+10h] [xbp-30h]
  _BYTE v68[4]; // [xsp+14h] [xbp-2Ch] BYREF
  int v69; // [xsp+18h] [xbp-28h] BYREF
  char v70; // [xsp+1Ch] [xbp-24h]
  _QWORD v71[2]; // [xsp+20h] [xbp-20h] BYREF
  int v72; // [xsp+30h] [xbp-10h]
  __int64 v73; // [xsp+38h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a5 == 6 )
  {
    result = 0;
LABEL_78:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v68[0] = 0;
  if ( !policy_mgr_get_context(a1) )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "policy_mgr_modify_sap_pcl_filter_mcc");
    result = 16;
    goto LABEL_78;
  }
  if ( *a4 >= 0x67 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid PCL List Length %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "policy_mgr_modify_sap_pcl_filter_mcc");
    result = 16;
    goto LABEL_78;
  }
  if ( !policy_mgr_is_force_scc(a1) )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: force SCC is not prefer, skip!",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "policy_mgr_modify_sap_pcl_filter_mcc");
    result = 0;
    goto LABEL_78;
  }
  ll_lt_sap_vdev_id = wlan_policy_mgr_get_ll_lt_sap_vdev_id(a1);
  policy_mgr_get_mcc_scc_switch(a1, v68);
  is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(a1);
  if ( !*a4 )
  {
    v29 = 0;
LABEL_77:
    result = 0;
    *a4 = v29;
    goto LABEL_78;
  }
  v27 = is_hw_dbs_capable;
  v28 = 0;
  v29 = 0;
  v66 = is_hw_dbs_capable;
  while ( 1 )
  {
    if ( !(v27 & 1 | (v68[0] != 6)) )
      goto LABEL_67;
    v30 = *(_DWORD *)(a2 + 4 * v28);
    v70 = 0;
    v69 = 0;
    v72 = 0;
    v71[0] = 0;
    v71[1] = 0;
    policy_mgr_mode_specific_get_channel(a1, 5);
    mode_specific_conn_info = (unsigned __int8)policy_mgr_get_mode_specific_conn_info(
                                                 a1,
                                                 (unsigned __int64)v71,
                                                 (unsigned __int64)&v69,
                                                 0);
    if ( mode_specific_conn_info )
    {
      v32 = policy_mgr_is_hw_dbs_capable(a1);
      if ( (unsigned int)(mode_specific_conn_info - 6) < 0xFFFFFFFB )
        break;
    }
    context = policy_mgr_get_context(a1);
    if ( context )
    {
      v48 = context;
      qdf_mutex_acquire(context + 56);
      v49 = BYTE4(qword_81C458) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list));
      if ( BYTE4(qword_81C47C) == 1 )
        v49 += wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464));
      if ( BYTE4(qword_81C4A0) == 1 )
        v49 += wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488));
      if ( BYTE4(qword_81C4C4) == 1 )
        v49 += wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC));
      if ( BYTE4(qword_81C4E8) == 1 )
        v49 += wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0));
      qdf_mutex_release(v48 + 56);
      qdf_mutex_acquire(v48 + 56);
      if ( BYTE4(qword_81C458) == 1
        && (unsigned int)pm_conc_connection_list <= 3
        && (_DWORD)pm_conc_connection_list != 1
        && (v50 = HIDWORD(pm_conc_connection_list), HIDWORD(pm_conc_connection_list) != v30)
        && (v49 >= 2 && (policy_mgr_2_freq_same_mac_in_dbs(a1, v30, HIDWORD(pm_conc_connection_list)) & 1) != 0
         || (policy_mgr_2_freq_always_on_same_mac(a1, v30, v50) & 1) != 0)
        || BYTE4(qword_81C47C) == 1
        && (unsigned int)qword_81C464 <= 3
        && (_DWORD)qword_81C464 != 1
        && (v51 = HIDWORD(qword_81C464), HIDWORD(qword_81C464) != v30)
        && (v49 >= 2 && (policy_mgr_2_freq_same_mac_in_dbs(a1, v30, HIDWORD(qword_81C464)) & 1) != 0
         || (policy_mgr_2_freq_always_on_same_mac(a1, v30, v51) & 1) != 0)
        || BYTE4(qword_81C4A0) == 1
        && (unsigned int)qword_81C488 <= 3
        && (_DWORD)qword_81C488 != 1
        && (v52 = HIDWORD(qword_81C488), HIDWORD(qword_81C488) != v30)
        && (v49 >= 2 && (policy_mgr_2_freq_same_mac_in_dbs(a1, v30, HIDWORD(qword_81C488)) & 1) != 0
         || (policy_mgr_2_freq_always_on_same_mac(a1, v30, v52) & 1) != 0)
        || BYTE4(qword_81C4C4) == 1
        && (unsigned int)qword_81C4AC <= 3
        && (_DWORD)qword_81C4AC != 1
        && (v53 = HIDWORD(qword_81C4AC), HIDWORD(qword_81C4AC) != v30)
        && (v49 >= 2 && (policy_mgr_2_freq_same_mac_in_dbs(a1, v30, HIDWORD(qword_81C4AC)) & 1) != 0
         || (policy_mgr_2_freq_always_on_same_mac(a1, v30, v53) & 1) != 0)
        || BYTE4(qword_81C4E8) == 1
        && (unsigned int)qword_81C4D0 <= 3
        && (_DWORD)qword_81C4D0 != 1
        && (v54 = HIDWORD(qword_81C4D0), HIDWORD(qword_81C4D0) != v30)
        && (v49 >= 2 && (policy_mgr_2_freq_same_mac_in_dbs(a1, v30, HIDWORD(qword_81C4D0)) & 1) != 0
         || (policy_mgr_2_freq_always_on_same_mac(a1, v30, v54) & 1) != 0) )
      {
        qdf_mutex_release(v48 + 56);
        v27 = v66;
        goto LABEL_12;
      }
      qdf_mutex_release(v48 + 56);
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "policy_mgr_channel_mcc_with_non_sap");
    }
    v27 = v66;
LABEL_67:
    if ( ll_lt_sap_vdev_id != -1 )
    {
      v55 = *(_DWORD *)(a2 + 4 * v28);
      if ( policy_mgr_get_context(a1) )
      {
        v64 = policy_mgr_get_context(a1);
        if ( !v64
          || (v65 = v64, (policy_mgr_is_hw_sbs_capable(a1) & 1) == 0)
          || !policy_mgr_can_2ghz_share_low_high_5ghz_sbs(v65) )
        {
          if ( wlan_reg_is_5ghz_ch_freq(v55) || wlan_reg_is_6ghz_chan_freq(v55) )
            goto LABEL_12;
        }
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: Invalid Context",
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          "policy_mgr_channel_mcc_with_ll_lt_sap_in_static_sbs");
      }
    }
    *(_DWORD *)(a2 + 4LL * v29) = *(_DWORD *)(a2 + 4 * v28);
    *(_BYTE *)(a3 + v29++) = *(_BYTE *)(a3 + v28);
LABEL_12:
    if ( ++v28 >= (unsigned __int64)*a4 )
      goto LABEL_77;
  }
  __break(0x5512u);
  return policy_mgr_modify_dual_sap_band_pcl_filter(v32, v33, v34, v35, v36, v37, v38);
}
