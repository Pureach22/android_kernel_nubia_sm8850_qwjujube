__int64 __fastcall policy_mgr_is_sap_restart_required_after_sta_disconnect(
        __int64 a1,
        int a2,
        unsigned int *a3,
        char a4)
{
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int mode_specific_conn_info; // w23
  unsigned int v16; // w21
  int v17; // w19
  int v18; // w22
  char v19; // w23
  char v20; // w0
  unsigned __int64 v21; // x27
  unsigned int v22; // w23
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x22
  double sap_user_config_freq; // d0
  unsigned int v34; // w0
  unsigned int v35; // w19
  unsigned int *v36; // x8
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w22
  bool is_24ghz_ch_freq; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w22
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  char is_sap_go_interface_allowed_on_indoor; // w0
  unsigned int v80; // w22
  unsigned int v81; // w0
  char v82; // w8
  unsigned int v83; // w28
  const char *v84; // x2
  __int64 v85; // x4
  const char *v86; // x2
  unsigned int v87; // w1
  unsigned int v88; // w24
  int v89; // w8
  __int64 v90; // x0
  unsigned int *v91; // x8
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 v100; // x19
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x21
  unsigned int v110; // w1
  int opmode_from_vdev_id; // w0
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  __int64 result; // x0
  unsigned int v121; // w19
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  bool v130; // zf
  int v131; // w8
  int v132; // [xsp+Ch] [xbp-2C4h]
  unsigned int *v133; // [xsp+10h] [xbp-2C0h]
  unsigned int v134; // [xsp+1Ch] [xbp-2B4h]
  int ll_lt_sap_freq; // [xsp+20h] [xbp-2B0h]
  char v136; // [xsp+24h] [xbp-2ACh]
  unsigned __int8 is_sta_sap_scc_allowed_on_dfs_chan; // [xsp+2Ch] [xbp-2A4h]
  int v139; // [xsp+30h] [xbp-2A0h]
  bool v140; // [xsp+34h] [xbp-29Ch]
  __int64 context; // [xsp+38h] [xbp-298h]
  _BYTE v142[4]; // [xsp+4Ch] [xbp-284h] BYREF
  _QWORD v143[4]; // [xsp+50h] [xbp-280h] BYREF
  int v144; // [xsp+70h] [xbp-260h]
  unsigned int v145; // [xsp+78h] [xbp-258h] BYREF
  _BYTE v146[112]; // [xsp+7Ch] [xbp-254h] BYREF
  _DWORD s[103]; // [xsp+ECh] [xbp-1E4h] BYREF
  __int64 v148; // [xsp+288h] [xbp-48h] BYREF
  __int16 v149; // [xsp+290h] [xbp-40h]
  _QWORD v150[7]; // [xsp+298h] [xbp-38h] BYREF

  v150[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  is_sta_sap_scc_allowed_on_dfs_chan = policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(a1);
  v136 = policy_mgr_sta_sap_scc_on_lte_coex_chan(a1);
  v146[0] = 0;
  v145 = 0;
  v144 = 0;
  memset(v143, 0, sizeof(v143));
  v142[0] = 0;
  if ( a3 )
    *a3 = 0;
  memset(v150, 0, 40);
  v148 = 0;
  v149 = 0;
  memset(s, 0, sizeof(s));
  memset(&v146[4], 0, 103);
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v86 = "%s: Invalid pm context";
    v87 = 2;
LABEL_70:
    qdf_trace_msg(
      0x4Fu,
      v87,
      v86,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_is_sap_restart_required_after_sta_disconnect");
LABEL_71:
    result = 0;
    goto LABEL_72;
  }
  ll_lt_sap_freq = policy_mgr_get_ll_lt_sap_freq(a1);
  policy_mgr_get_sta_sap_scc_on_dfs_chnl(a1, v146);
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 && (unsigned int)policy_mgr_get_connection_count(a1) > 1 )
    goto LABEL_71;
  v133 = a3;
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(a1, v150, &v148, 1);
  v16 = mode_specific_conn_info;
  if ( mode_specific_conn_info < 5 )
    v16 = policy_mgr_get_mode_specific_conn_info(
            a1,
            (char *)v150 + 4 * mode_specific_conn_info,
            (char *)&v148 + mode_specific_conn_info,
            3)
        + mode_specific_conn_info;
  v134 = mode_specific_conn_info;
  v17 = policy_mgr_mode_specific_connection_count(a1, 0, 0);
  v18 = policy_mgr_mode_specific_connection_count(a1, 2, 0);
  v19 = policy_mgr_mode_specific_connection_count(a1, 5, 0);
  v20 = policy_mgr_mode_specific_connection_count(a1, 4, 0);
  if ( !v16 )
    goto LABEL_69;
  v21 = 0;
  v132 = v18 + v17;
  v139 = (unsigned __int8)(v20 + v19);
  v140 = (ll_lt_sap_freq | (v18 + v17)) != 0;
  while ( 1 )
  {
    if ( a2 == 255 )
    {
      if ( v21 > 9 )
        goto LABEL_88;
      v22 = *((unsigned __int8 *)&v148 + v21);
    }
    else
    {
      if ( v21 > 9 )
      {
LABEL_88:
        __break(0x5512u);
        __break(1u);
      }
      v22 = *((unsigned __int8 *)&v148 + v21);
      if ( v22 != a2 )
        goto LABEL_10;
    }
    v23 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v22, 24);
    if ( v23 )
    {
      v32 = v23;
      sap_user_config_freq = wlan_get_sap_user_config_freq();
      v35 = v34;
      wlan_objmgr_vdev_release_ref(v32, 0x18u, v36, sap_user_config_freq, v37, v38, v39, v40, v41, v42, v43);
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: vdev is NULL",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "policy_mgr_get_user_config_sap_freq");
      v35 = 0;
    }
    v44 = *((unsigned __int8 *)&v148 + v21);
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v150 + v21));
    if ( (policy_mgr_is_any_mode_active_on_band_along_with_session(a1, v44, !is_24ghz_ch_freq) & 1) == 0 )
      break;
    v54 = *((_DWORD *)v150 + v21);
LABEL_35:
    v80 = wlan_reg_freq_to_band(v54);
    v81 = wlan_reg_freq_to_band(v35);
    if ( v35 )
      v82 = v140;
    else
      v82 = 1;
    if ( (v82 & 1) == 0 && !v139 )
    {
      v83 = v81;
      if ( wlan_reg_is_enable_in_secondary_list_for_freq(
             *(_QWORD *)(context + 8),
             v35,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14)
        && v80 < v83 )
      {
        v84 = "%s: Move sap to user configured freq: %d";
        v54 = *((_DWORD *)v150 + v21);
        v85 = v35;
LABEL_45:
        qdf_trace_msg(
          0x4Fu,
          8u,
          v84,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "policy_mgr_is_sap_restart_required_after_sta_disconnect",
          v85);
        goto LABEL_46;
      }
    }
LABEL_10:
    if ( v16 == ++v21 )
      goto LABEL_69;
  }
  if ( (is_sta_sap_scc_allowed_on_dfs_chan & (v146[0] != 2)) != 1
    || (wlan_reg_is_dfs_for_freq(
          *(_QWORD *)(context + 8),
          *((_DWORD *)v150 + v21),
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53)
      & 1) == 0
    || (v54 = *(_DWORD *)(context + 964), v54 != *((_DWORD *)v150 + v21)) )
  {
    if ( (a4 & 1) != 0 )
    {
      if ( (v136 & 1) == 0 )
        goto LABEL_33;
    }
    else
    {
      if ( !policy_mgr_get_context(a1) )
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: Invalid context",
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          "policy_mgr_restrict_sap_on_unsafe_chan");
        goto LABEL_33;
      }
      if ( (((unsigned int)policy_mgr_get_freq_restriction_mask() >> 1) & 1 & *(_DWORD *)&v136) == 0 )
      {
LABEL_33:
        v54 = *((_DWORD *)v150 + v21);
        if ( *(_DWORD *)(context + 964) == v54 )
        {
          is_sap_go_interface_allowed_on_indoor = policy_mgr_is_sap_go_interface_allowed_on_indoor(
                                                    *(_QWORD *)(context + 8),
                                                    v22);
          v54 = *((_DWORD *)v150 + v21);
          if ( (is_sap_go_interface_allowed_on_indoor & 1) == 0 )
          {
            v84 = "%s: indoor sap_ch_freq %u";
            v85 = v54;
            goto LABEL_45;
          }
        }
        goto LABEL_35;
      }
    }
    if ( (((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(a1, *((unsigned int *)v150 + v21)) & 1) == 0 )
    {
      v54 = *(_DWORD *)(context + 964);
      if ( v54 == *((_DWORD *)v150 + v21) )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: sta_sap_scc_on_lte_coex_chan %u unsafe sap_ch_freq %u",
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          "policy_mgr_is_sap_restart_required_after_sta_disconnect",
          1,
          v54);
        goto LABEL_46;
      }
    }
    goto LABEL_33;
  }
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: sta_sap_scc_on_dfs_chan %u, sta_sap_scc_on_dfs_chnl_config_value %u, dfs sap_ch_freq %u",
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    "policy_mgr_is_sap_restart_required_after_sta_disconnect",
    1,
    v146[0],
    v54);
LABEL_46:
  if ( !v54 )
  {
LABEL_69:
    v86 = "%s: SAP restart is not required";
    v87 = 8;
    goto LABEL_70;
  }
  if ( v134 > (unsigned int)v21 )
    v88 = 1;
  else
    v88 = 3;
  qdf_mutex_acquire(context + 56);
  ((void (__fastcall *)(__int64, _QWORD, _QWORD *, _BYTE *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
    a1,
    v22,
    v143,
    v142);
  s[0] = v35;
  v146[4] = 0;
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _DWORD *, unsigned int *, _BYTE *, __int64, _QWORD))policy_mgr_get_pcl)(
                       a1,
                       v88,
                       &s[1],
                       &v145,
                       &v146[5],
                       102,
                       v22) )
    v89 = 1;
  else
    v89 = v145 + 1;
  v145 = v89;
  v90 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v22, 24);
  if ( !v90 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: vdev is NULL",
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      "policy_mgr_is_sap_restart_required_after_sta_disconnect");
    goto LABEL_74;
  }
  v100 = *(_QWORD *)(v90 + 216);
  wlan_objmgr_vdev_release_ref(v90, 0x18u, v91, v92, v93, v94, v95, v96, v97, v98, v99);
  if ( !v145 )
  {
LABEL_74:
    v121 = 0;
    goto LABEL_75;
  }
  v109 = 0;
  while ( 1 )
  {
    if ( v109 == 103 )
      goto LABEL_88;
    v110 = s[v109];
    if ( v110 != v54 )
    {
      if ( !ll_lt_sap_freq )
        goto LABEL_63;
      opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(context + 8), v22);
      v110 = s[v109];
      if ( opmode_from_vdev_id != 1 )
        goto LABEL_63;
      if ( (policy_mgr_are_2_freq_on_same_mac(a1) & 1) == 0 )
        break;
    }
LABEL_56:
    if ( ++v109 >= (unsigned __int64)v145 )
      goto LABEL_74;
  }
  v110 = s[v109];
LABEL_63:
  if ( (wlan_reg_is_freq_enabled(v100, v110, v101, v102, v103, v104, v105, v106, v107, v108) & 1) == 0
    || (((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(a1, (unsigned int)s[v109]) & 1) == 0
    || (wlan_reg_is_dfs_for_freq(*(_QWORD *)(context + 8), s[v109], v101, v102, v103, v104, v105, v106, v107, v108) & 1) != 0 )
  {
    goto LABEL_56;
  }
  if ( !v132 && (policy_mgr_is_sap_go_interface_allowed_on_indoor(*(_QWORD *)(context + 8), v22) & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Do not allow SAP on indoor frequency, STA is absent",
      v112,
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      v119,
      "policy_mgr_is_sap_restart_required_after_sta_disconnect");
    goto LABEL_56;
  }
  v121 = s[v109];
LABEL_75:
  if ( v142[0] )
    policy_mgr_restore_deleted_conn_info(a1, v143);
  qdf_mutex_release(context + 56);
  if ( v121 )
    v130 = v54 == v121;
  else
    v130 = 1;
  v131 = v130;
  result = v131 ^ 1u;
  if ( v133 && (v131 & 1) == 0 )
  {
    *v133 = v121;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Standalone SAP(vdev_id %d) will be moved to channel %u",
      v122,
      v123,
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      "policy_mgr_is_sap_restart_required_after_sta_disconnect",
      v22,
      v121);
    result = 1;
  }
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return result;
}
