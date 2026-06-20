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
  int channel; // w26
  int mode_specific_conn_info; // w24
  __int64 is_ml_vdev_id; // x0
  __int64 v34; // x1
  __int64 v35; // x2
  __int64 v36; // x3
  __int64 v37; // x4
  __int64 v38; // x5
  __int64 v39; // x6
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x26
  unsigned int v50; // w24
  unsigned int v51; // w27
  unsigned int v52; // w27
  unsigned int v53; // w27
  unsigned int v54; // w27
  unsigned int v55; // w27
  unsigned int v56; // w26
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 context; // x0
  __int64 v66; // x27
  char v67; // [xsp+Ch] [xbp-34h]
  char ll_lt_sap_vdev_id; // [xsp+10h] [xbp-30h]
  _BYTE v69[4]; // [xsp+14h] [xbp-2Ch] BYREF
  int v70; // [xsp+18h] [xbp-28h] BYREF
  unsigned __int8 v71; // [xsp+1Ch] [xbp-24h]
  _QWORD v72[2]; // [xsp+20h] [xbp-20h] BYREF
  int v73; // [xsp+30h] [xbp-10h]
  __int64 v74; // [xsp+38h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a5 == 6 )
  {
    result = 0;
LABEL_100:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v69[0] = 0;
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
    goto LABEL_100;
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
    goto LABEL_100;
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
    goto LABEL_100;
  }
  ll_lt_sap_vdev_id = wlan_policy_mgr_get_ll_lt_sap_vdev_id(a1);
  policy_mgr_get_mcc_scc_switch(a1, v69);
  is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(a1);
  if ( !*a4 )
  {
    v29 = 0;
LABEL_99:
    result = 0;
    *a4 = v29;
    goto LABEL_100;
  }
  v27 = is_hw_dbs_capable;
  v28 = 0;
  v29 = 0;
  v67 = is_hw_dbs_capable;
  while ( !(v27 & 1 | (v69[0] != 6)) )
  {
LABEL_89:
    if ( ll_lt_sap_vdev_id != -1 )
    {
      v56 = *(_DWORD *)(a2 + 4 * v28);
      if ( policy_mgr_get_context(a1) )
      {
        context = policy_mgr_get_context(a1);
        if ( !context
          || (v66 = context, (policy_mgr_is_hw_sbs_capable(a1) & 1) == 0)
          || !policy_mgr_can_2ghz_share_low_high_5ghz_sbs(v66) )
        {
          if ( wlan_reg_is_5ghz_ch_freq(v56) || wlan_reg_is_6ghz_chan_freq(v56) )
            goto LABEL_12;
        }
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: Invalid Context",
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          "policy_mgr_channel_mcc_with_ll_lt_sap_in_static_sbs");
      }
    }
    *(_DWORD *)(a2 + 4LL * v29) = *(_DWORD *)(a2 + 4 * v28);
    *(_BYTE *)(a3 + v29++) = *(_BYTE *)(a3 + v28);
LABEL_12:
    if ( ++v28 >= (unsigned __int64)*a4 )
      goto LABEL_99;
  }
  v30 = *(_DWORD *)(a2 + 4 * v28);
  v71 = 0;
  v70 = 0;
  v73 = 0;
  v72[0] = 0;
  v72[1] = 0;
  channel = policy_mgr_mode_specific_get_channel(a1, 5);
  mode_specific_conn_info = (unsigned __int8)policy_mgr_get_mode_specific_conn_info(
                                               a1,
                                               (unsigned __int64)v72,
                                               (unsigned __int64)&v70,
                                               0);
  if ( !mode_specific_conn_info )
    goto LABEL_38;
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0
    && (policy_mgr_is_mlo_sta_present(a1) & 1) != 0
    && (policy_mgr_if_freq_n_inactive_links_freq_same(a1, v30) & 1) != 0
    || (policy_mgr_is_ml_vdev_id(a1, (unsigned __int8)v70) & 1) != 0
    && (wlan_nan_is_disc_active(a1) & 1) != 0
    && channel == v30 )
  {
    goto LABEL_88;
  }
  if ( mode_specific_conn_info == 1 )
    goto LABEL_38;
  if ( (policy_mgr_is_ml_vdev_id(a1, BYTE1(v70)) & 1) != 0 && (wlan_nan_is_disc_active(a1) & 1) != 0 && channel == v30 )
    goto LABEL_88;
  if ( mode_specific_conn_info == 2 )
    goto LABEL_38;
  if ( (policy_mgr_is_ml_vdev_id(a1, BYTE2(v70)) & 1) != 0 && (wlan_nan_is_disc_active(a1) & 1) != 0 && channel == v30 )
    goto LABEL_88;
  if ( mode_specific_conn_info == 3 )
    goto LABEL_38;
  if ( (policy_mgr_is_ml_vdev_id(a1, HIBYTE(v70)) & 1) != 0 && (wlan_nan_is_disc_active(a1) & 1) != 0 && channel == v30 )
    goto LABEL_88;
  if ( mode_specific_conn_info == 4 )
    goto LABEL_38;
  is_ml_vdev_id = policy_mgr_is_ml_vdev_id(a1, v71);
  if ( (is_ml_vdev_id & 1) != 0 )
  {
    is_ml_vdev_id = wlan_nan_is_disc_active(a1);
    if ( (is_ml_vdev_id & 1) != 0 && channel == v30 )
    {
LABEL_88:
      v27 = v67;
      goto LABEL_89;
    }
  }
  if ( mode_specific_conn_info == 5 )
  {
LABEL_38:
    v40 = policy_mgr_get_context(a1);
    if ( v40 )
    {
      v49 = v40;
      qdf_mutex_acquire(v40 + 56);
      v50 = BYTE4(qword_8D4F00) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list));
      if ( BYTE4(qword_8D4F24) == 1 )
        v50 += wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C));
      if ( BYTE4(qword_8D4F48) == 1 )
        v50 += wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F30));
      if ( BYTE4(qword_8D4F6C) == 1 )
        v50 += wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F54));
      if ( BYTE4(qword_8D4F90) == 1 )
        v50 += wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F78));
      qdf_mutex_release(v49 + 56);
      qdf_mutex_acquire(v49 + 56);
      if ( BYTE4(qword_8D4F00) == 1
        && (unsigned int)pm_conc_connection_list <= 3
        && (_DWORD)pm_conc_connection_list != 1
        && (v51 = HIDWORD(pm_conc_connection_list), HIDWORD(pm_conc_connection_list) != v30)
        && (v50 >= 2 && (policy_mgr_2_freq_same_mac_in_dbs(a1, v30, HIDWORD(pm_conc_connection_list)) & 1) != 0
         || (policy_mgr_2_freq_always_on_same_mac(a1, v30, v51) & 1) != 0)
        || BYTE4(qword_8D4F24) == 1
        && (unsigned int)qword_8D4F0C <= 3
        && (_DWORD)qword_8D4F0C != 1
        && (v52 = HIDWORD(qword_8D4F0C), HIDWORD(qword_8D4F0C) != v30)
        && (v50 >= 2 && (policy_mgr_2_freq_same_mac_in_dbs(a1, v30, HIDWORD(qword_8D4F0C)) & 1) != 0
         || (policy_mgr_2_freq_always_on_same_mac(a1, v30, v52) & 1) != 0)
        || BYTE4(qword_8D4F48) == 1
        && (unsigned int)qword_8D4F30 <= 3
        && (_DWORD)qword_8D4F30 != 1
        && (v53 = HIDWORD(qword_8D4F30), HIDWORD(qword_8D4F30) != v30)
        && (v50 >= 2 && (policy_mgr_2_freq_same_mac_in_dbs(a1, v30, HIDWORD(qword_8D4F30)) & 1) != 0
         || (policy_mgr_2_freq_always_on_same_mac(a1, v30, v53) & 1) != 0)
        || BYTE4(qword_8D4F6C) == 1
        && (unsigned int)qword_8D4F54 <= 3
        && (_DWORD)qword_8D4F54 != 1
        && (v54 = HIDWORD(qword_8D4F54), HIDWORD(qword_8D4F54) != v30)
        && (v50 >= 2 && (policy_mgr_2_freq_same_mac_in_dbs(a1, v30, HIDWORD(qword_8D4F54)) & 1) != 0
         || (policy_mgr_2_freq_always_on_same_mac(a1, v30, v54) & 1) != 0)
        || BYTE4(qword_8D4F90) == 1
        && (unsigned int)qword_8D4F78 <= 3
        && (_DWORD)qword_8D4F78 != 1
        && (v55 = HIDWORD(qword_8D4F78), HIDWORD(qword_8D4F78) != v30)
        && (v50 >= 2 && (policy_mgr_2_freq_same_mac_in_dbs(a1, v30, HIDWORD(qword_8D4F78)) & 1) != 0
         || (policy_mgr_2_freq_always_on_same_mac(a1, v30, v55) & 1) != 0) )
      {
        qdf_mutex_release(v49 + 56);
        v27 = v67;
        goto LABEL_12;
      }
      qdf_mutex_release(v49 + 56);
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "policy_mgr_channel_mcc_with_non_sap");
    }
    goto LABEL_88;
  }
  __break(0x5512u);
  return policy_mgr_modify_dual_sap_band_pcl_filter(is_ml_vdev_id, v34, v35, v36, v37, v38, v39);
}
