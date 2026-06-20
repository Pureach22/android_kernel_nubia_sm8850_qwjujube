__int64 __fastcall wlan_hdd_is_ap_ap_force_scc_override(
        __int64 *a1,
        unsigned int *a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 *v12; // x20
  unsigned int v15; // w19
  __int64 vdev_by_user; // x0
  __int64 v17; // x21
  __int64 v18; // x23
  __int64 *v19; // x24
  unsigned int v20; // w0
  const char *v21; // x2
  const char *v22; // x3
  __int64 result; // x0
  int v24; // w22
  __int64 v25; // x21
  int mode_specific_conn_info; // w22
  unsigned int v27; // w24
  unsigned __int8 v28; // w23
  unsigned int alternate_channel_for_sap; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w22
  unsigned int v39; // w3
  const char *v40; // x2
  __int64 *link_info_by_vdev; // x0
  unsigned int v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 channel_khz; // x0
  __int64 v52; // x21
  unsigned int v53; // w22
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x2
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  int v71; // w8
  __int64 v72; // x9
  unsigned int v73; // [xsp+10h] [xbp-60h] BYREF
  unsigned __int8 v74[4]; // [xsp+14h] [xbp-5Ch] BYREF
  __int64 v75; // [xsp+18h] [xbp-58h] BYREF
  __int64 v76; // [xsp+20h] [xbp-50h]
  int v77; // [xsp+28h] [xbp-48h] BYREF
  char v78; // [xsp+2Ch] [xbp-44h]
  int v79; // [xsp+30h] [xbp-40h] BYREF
  char v80; // [xsp+34h] [xbp-3Ch]
  __int64 v81; // [xsp+38h] [xbp-38h] BYREF
  __int64 v82; // [xsp+40h] [xbp-30h]
  unsigned int v83; // [xsp+48h] [xbp-28h]
  _QWORD v84[2]; // [xsp+50h] [xbp-20h] BYREF
  int v85; // [xsp+60h] [xbp-10h]
  __int64 v86; // [xsp+68h] [xbp-8h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *a1;
  v75 = 0;
  v76 = 0;
  v74[0] = -1;
  v12 = *(__int64 **)(v11 + 24);
  v73 = 0;
  if ( !a2 || !v12 )
  {
    v21 = "%s: hdd context or chandef is NULL";
LABEL_8:
    v22 = "wlan_hdd_is_ap_ap_force_scc_override";
LABEL_9:
    qdf_trace_msg(0x33u, 2u, v21, a4, a5, a6, a7, a8, a9, a10, a11, v22);
    goto LABEL_10;
  }
  v15 = *(_DWORD *)(*(_QWORD *)a2 + 4LL);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "wlan_hdd_is_ap_ap_force_scc_override");
  if ( !vdev_by_user )
  {
    v21 = "%s: failed to get vdev";
    goto LABEL_8;
  }
  v17 = vdev_by_user;
  v18 = *v12;
  v19 = (__int64 *)v12[1];
  v20 = hdd_map_nl_chan_width(a2[2]);
  if ( !policy_mgr_is_ap_ap_mcc_allow(v18, (__int64)v19, v17, v15, v20, v74, &v73) )
  {
    v24 = *(_DWORD *)(v17 + 16);
    _hdd_objmgr_put_vdev_by_user(v17, 6, "wlan_hdd_is_ap_ap_force_scc_override");
    if ( v24 != 1 )
      goto LABEL_47;
    v25 = *v12;
    v80 = 0;
    v79 = 0;
    v85 = 0;
    v84[0] = 0;
    v84[1] = 0;
    v78 = 0;
    v77 = 0;
    v83 = 0;
    v81 = 0;
    v82 = 0;
    if ( (policy_mgr_is_hw_dbs_capable(v25) & 1) == 0 )
      goto LABEL_47;
    if ( (unsigned __int8)policy_mgr_get_mode_specific_conn_info(v25, (unsigned __int64)v84, (unsigned __int64)&v79, 3u) != 1 )
      goto LABEL_47;
    if ( (policy_mgr_2_freq_always_on_same_mac(v25, LODWORD(v84[0]), v15) & 1) == 0 )
      goto LABEL_47;
    mode_specific_conn_info = (unsigned __int8)policy_mgr_get_mode_specific_conn_info(
                                                 v25,
                                                 (unsigned __int64)&v81,
                                                 (unsigned __int64)&v77,
                                                 0);
    if ( !mode_specific_conn_info )
      goto LABEL_47;
    if ( LODWORD(v84[0]) == (_DWORD)v81
      || (policy_mgr_2_freq_always_on_same_mac(v25, LODWORD(v84[0]), (unsigned int)v81) & 1) == 0 )
    {
      if ( mode_specific_conn_info == 1 )
        goto LABEL_47;
      if ( LODWORD(v84[0]) == HIDWORD(v81)
        || (policy_mgr_2_freq_always_on_same_mac(v25, LODWORD(v84[0]), HIDWORD(v81)) & 1) == 0 )
      {
        if ( mode_specific_conn_info == 2 )
          goto LABEL_47;
        if ( LODWORD(v84[0]) == (_DWORD)v82
          || (policy_mgr_2_freq_always_on_same_mac(v25, LODWORD(v84[0]), (unsigned int)v82) & 1) == 0 )
        {
          if ( mode_specific_conn_info == 3 )
            goto LABEL_47;
          if ( LODWORD(v84[0]) == HIDWORD(v82)
            || (policy_mgr_2_freq_always_on_same_mac(v25, LODWORD(v84[0]), HIDWORD(v82)) & 1) == 0 )
          {
            if ( mode_specific_conn_info == 4 )
              goto LABEL_47;
            if ( LODWORD(v84[0]) == v83 || (policy_mgr_2_freq_always_on_same_mac(v25, LODWORD(v84[0]), v83) & 1) == 0 )
            {
              if ( mode_specific_conn_info == 5 )
                goto LABEL_47;
              __break(0x5512u);
              goto LABEL_72;
            }
            v27 = 4;
          }
          else
          {
            v27 = 3;
          }
        }
        else
        {
          v27 = 2;
        }
      }
      else
      {
        v27 = 1;
      }
    }
    else
    {
      v27 = 0;
    }
    if ( v27 != mode_specific_conn_info )
    {
      v28 = v79;
      alternate_channel_for_sap = policy_mgr_get_alternate_channel_for_sap(v25, (unsigned __int8)v79, v84[0], 3);
      if ( !alternate_channel_for_sap )
      {
        v40 = "%s: no alternate GO channel";
        goto LABEL_46;
      }
      v38 = alternate_channel_for_sap;
      v39 = *((_DWORD *)&v81 + v27);
      if ( alternate_channel_for_sap != v39
        && (policy_mgr_3_freq_always_on_same_mac(v25, v15, alternate_channel_for_sap, v39) & 1) != 0 )
      {
        v40 = "%s: no alternate GO channel to avoid 3vif MCC";
LABEL_46:
        qdf_trace_msg(0x33u, 8u, v40, v30, v31, v32, v33, v34, v35, v36, v37, "hdd_handle_p2p_go_for_3rd_ap_conc");
        goto LABEL_47;
      }
      link_info_by_vdev = (__int64 *)hdd_get_link_info_by_vdev(v12);
      if ( !link_info_by_vdev )
        goto LABEL_47;
      v19 = link_info_by_vdev;
      if ( (unsigned int)_hdd_validate_adapter(*link_info_by_vdev, "hdd_handle_p2p_go_for_3rd_ap_conc") )
        goto LABEL_47;
      wlan_hdd_set_sap_csa_reason(v25, v28, 0xFu);
      qdf_event_reset((__int64)(v19 + 11));
      v42 = hdd_softap_set_channel_change(v19, v38, 0, 2u, 0, 0);
      if ( v42 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: CSA failed to %d, ret %d",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "hdd_handle_p2p_go_for_3rd_ap_conc",
          v38,
          v42);
        goto LABEL_47;
      }
LABEL_72:
      if ( !(unsigned int)qdf_wait_for_event_completion((__int64)(v19 + 11), 0x32C8u) )
        goto LABEL_10;
      v21 = "%s: wait for qdf_event failed!!";
      v22 = "hdd_handle_p2p_go_for_3rd_ap_conc";
      goto LABEL_9;
    }
LABEL_47:
    if ( !v73 )
      goto LABEL_10;
    channel_khz = ieee80211_get_channel_khz(v12[3], 1000 * v73);
    if ( channel_khz )
    {
      v52 = channel_khz;
      v53 = v73;
      result = hdd_get_link_info_by_vdev(v12);
      if ( !result )
        goto LABEL_11;
      if ( (wlan_sap_get_ch_params(*(_QWORD *)(result + 272), &v75) & 1) == 0 )
        wlan_reg_set_channel_params_for_pwrmode(
          v12[1],
          v53,
          0,
          (__int64)&v75,
          0,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61);
      if ( BYTE4(v75) > 3uLL )
        v62 = 0;
      else
        v62 = dword_A2F978[BYTE4(v75)];
      cfg80211_chandef_create(a3, v52, v62);
      switch ( (_DWORD)v75 )
      {
        case 2:
          v71 = 3;
          break;
        case 3:
          v71 = 5;
          break;
        case 4:
          v71 = HIDWORD(v76);
          a3[2] = 4;
          if ( !v71 )
            goto LABEL_65;
          v72 = 4;
LABEL_64:
          a3[v72] = v71;
          goto LABEL_65;
        default:
          if ( (unsigned int)(v75 - 2) >= 3 )
          {
LABEL_67:
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: override AP freq %d to first AP(vdev_id %d) center_freq:%d width:%d freq1:%d freq2:%d ",
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              v70,
              "wlan_hdd_is_ap_ap_force_scc_override",
              v15,
              v74[0],
              *(unsigned int *)(*(_QWORD *)a3 + 4LL),
              (unsigned int)a3[2],
              a3[3],
              a3[4]);
            result = 1;
            goto LABEL_11;
          }
LABEL_65:
          if ( (_DWORD)v76 )
            a3[3] = v76;
          goto LABEL_67;
      }
      v72 = 2;
      goto LABEL_64;
    }
    v21 = "%s: channel conversion failed";
    goto LABEL_8;
  }
  _hdd_objmgr_put_vdev_by_user(v17, 6, "wlan_hdd_is_ap_ap_force_scc_override");
LABEL_10:
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
