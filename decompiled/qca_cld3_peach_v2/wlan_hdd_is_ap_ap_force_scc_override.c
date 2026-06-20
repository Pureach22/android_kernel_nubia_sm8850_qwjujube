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
  __int64 *v11; // x26
  __int64 v12; // x8
  __int64 *v13; // x20
  unsigned int v16; // w19
  __int64 vdev_by_user; // x0
  __int64 v18; // x22
  __int64 v19; // x23
  __int64 v20; // x24
  unsigned int v21; // w0
  const char *v22; // x2
  const char *v23; // x3
  __int64 result; // x0
  int v25; // w23
  __int64 v26; // x23
  int mode_specific_conn_info; // w24
  unsigned int v28; // w26
  unsigned __int8 v29; // w25
  unsigned int alternate_channel_for_sap; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w24
  unsigned int v40; // w3
  const char *v41; // x2
  __int64 *link_info_by_vdev; // x0
  unsigned int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 channel_khz; // x0
  __int64 v53; // x23
  int v54; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x8
  unsigned int v64; // w1
  __int64 v65; // x0
  unsigned int v66; // w21
  __int64 v67; // x2
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  int v76; // w8
  __int64 v77; // x9
  int v78; // w8
  unsigned int v79; // [xsp+18h] [xbp-68h] BYREF
  unsigned __int8 v80[4]; // [xsp+1Ch] [xbp-64h] BYREF
  __int64 v81; // [xsp+20h] [xbp-60h] BYREF
  __int64 v82; // [xsp+28h] [xbp-58h]
  __int64 v83; // [xsp+30h] [xbp-50h]
  int v84; // [xsp+38h] [xbp-48h] BYREF
  char v85; // [xsp+3Ch] [xbp-44h]
  int v86; // [xsp+40h] [xbp-40h] BYREF
  char v87; // [xsp+44h] [xbp-3Ch]
  __int64 v88; // [xsp+48h] [xbp-38h] BYREF
  __int64 v89; // [xsp+50h] [xbp-30h]
  unsigned int v90; // [xsp+58h] [xbp-28h]
  _QWORD v91[2]; // [xsp+60h] [xbp-20h] BYREF
  int v92; // [xsp+70h] [xbp-10h]
  __int64 v93; // [xsp+78h] [xbp-8h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a1;
  v82 = 0;
  v83 = 0;
  v81 = 0;
  v13 = *(__int64 **)(v12 + 24);
  v80[0] = -1;
  v79 = 0;
  if ( !a2 || !v13 )
  {
    v22 = "%s: hdd context or chandef is NULL";
LABEL_8:
    v23 = "wlan_hdd_is_ap_ap_force_scc_override";
LABEL_9:
    qdf_trace_msg(0x33u, 2u, v22, a4, a5, a6, a7, a8, a9, a10, a11, v23);
    goto LABEL_10;
  }
  v16 = *(_DWORD *)(*(_QWORD *)a2 + 4LL);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "wlan_hdd_is_ap_ap_force_scc_override");
  if ( !vdev_by_user )
  {
    v22 = "%s: failed to get vdev";
    goto LABEL_8;
  }
  v18 = vdev_by_user;
  v19 = *v13;
  v20 = v13[1];
  v21 = hdd_map_nl_chan_width(a2[2]);
  if ( !policy_mgr_is_ap_ap_mcc_allow(v19, v20, v18, v16, v21, v80, &v79) )
  {
    v25 = *(_DWORD *)(v18 + 16);
    _hdd_objmgr_put_vdev_by_user(v18, 6, "wlan_hdd_is_ap_ap_force_scc_override");
    if ( v25 != 1 )
      goto LABEL_47;
    v26 = *v13;
    v87 = 0;
    v86 = 0;
    v92 = 0;
    v91[0] = 0;
    v91[1] = 0;
    v85 = 0;
    v84 = 0;
    v90 = 0;
    v88 = 0;
    v89 = 0;
    if ( (policy_mgr_is_hw_dbs_capable(v26) & 1) == 0 )
      goto LABEL_47;
    if ( (unsigned __int8)policy_mgr_get_mode_specific_conn_info(v26, (unsigned __int64)v91, (unsigned __int64)&v86, 3u) != 1 )
      goto LABEL_47;
    if ( (policy_mgr_2_freq_always_on_same_mac(v26, LODWORD(v91[0]), v16) & 1) == 0 )
      goto LABEL_47;
    mode_specific_conn_info = (unsigned __int8)policy_mgr_get_mode_specific_conn_info(
                                                 v26,
                                                 (unsigned __int64)&v88,
                                                 (unsigned __int64)&v84,
                                                 0);
    if ( !mode_specific_conn_info )
      goto LABEL_47;
    if ( LODWORD(v91[0]) == (_DWORD)v88
      || (policy_mgr_2_freq_always_on_same_mac(v26, LODWORD(v91[0]), (unsigned int)v88) & 1) == 0 )
    {
      if ( mode_specific_conn_info == 1 )
        goto LABEL_47;
      if ( LODWORD(v91[0]) == HIDWORD(v88)
        || (policy_mgr_2_freq_always_on_same_mac(v26, LODWORD(v91[0]), HIDWORD(v88)) & 1) == 0 )
      {
        if ( mode_specific_conn_info == 2 )
          goto LABEL_47;
        if ( LODWORD(v91[0]) == (_DWORD)v89
          || (policy_mgr_2_freq_always_on_same_mac(v26, LODWORD(v91[0]), (unsigned int)v89) & 1) == 0 )
        {
          if ( mode_specific_conn_info == 3 )
            goto LABEL_47;
          if ( LODWORD(v91[0]) == HIDWORD(v89)
            || (policy_mgr_2_freq_always_on_same_mac(v26, LODWORD(v91[0]), HIDWORD(v89)) & 1) == 0 )
          {
            if ( mode_specific_conn_info == 4 )
              goto LABEL_47;
            if ( LODWORD(v91[0]) == v90 || (policy_mgr_2_freq_always_on_same_mac(v26, LODWORD(v91[0]), v90) & 1) == 0 )
            {
              if ( mode_specific_conn_info == 5 )
                goto LABEL_47;
              __break(0x5512u);
              goto LABEL_79;
            }
            v28 = 4;
          }
          else
          {
            v28 = 3;
          }
        }
        else
        {
          v28 = 2;
        }
      }
      else
      {
        v28 = 1;
      }
    }
    else
    {
      v28 = 0;
    }
    if ( v28 != mode_specific_conn_info )
    {
      v29 = v86;
      alternate_channel_for_sap = policy_mgr_get_alternate_channel_for_sap(v26, (unsigned __int8)v86, v91[0], 3);
      if ( !alternate_channel_for_sap )
      {
        v41 = "%s: no alternate GO channel";
        goto LABEL_46;
      }
      v39 = alternate_channel_for_sap;
      v40 = *((_DWORD *)&v88 + v28);
      if ( alternate_channel_for_sap != v40
        && (policy_mgr_3_freq_always_on_same_mac(v26, v16, alternate_channel_for_sap, v40) & 1) != 0 )
      {
        v41 = "%s: no alternate GO channel to avoid 3vif MCC";
LABEL_46:
        qdf_trace_msg(0x33u, 8u, v41, v31, v32, v33, v34, v35, v36, v37, v38, "hdd_handle_p2p_go_for_3rd_ap_conc");
        goto LABEL_47;
      }
      link_info_by_vdev = (__int64 *)hdd_get_link_info_by_vdev(v13);
      if ( !link_info_by_vdev )
        goto LABEL_47;
      v11 = link_info_by_vdev;
      if ( (unsigned int)_hdd_validate_adapter(*link_info_by_vdev, "hdd_handle_p2p_go_for_3rd_ap_conc") )
        goto LABEL_47;
      wlan_hdd_set_sap_csa_reason(v26, v29, 0xFu);
      qdf_event_reset((__int64)(v11 + 11));
      v43 = hdd_softap_set_channel_change(v11, v39, 0, 2u, 0, 0, 1);
      if ( v43 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: CSA failed to %d, ret %d",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "hdd_handle_p2p_go_for_3rd_ap_conc",
          v39,
          v43);
        goto LABEL_47;
      }
LABEL_79:
      if ( !(unsigned int)qdf_wait_for_event_completion((__int64)(v11 + 11), 0x32C8u) )
        goto LABEL_10;
      v22 = "%s: wait for qdf_event failed!!";
      v23 = "hdd_handle_p2p_go_for_3rd_ap_conc";
      goto LABEL_9;
    }
LABEL_47:
    if ( !v79 )
      goto LABEL_10;
    channel_khz = ieee80211_get_channel_khz(v13[3], 1000 * v79);
    if ( channel_khz )
    {
      v53 = channel_khz;
      if ( (wlan_vdev_mlme_is_mlo_vdev(v18, a4, a5, a6, a7, a8, a9, a10, a11) & 1) != 0 )
      {
        v54 = hdd_map_nl_chan_width(a2[2]);
        v63 = v13[1];
        v64 = v79;
        LODWORD(v81) = v54;
        v65 = v63;
      }
      else
      {
        v66 = v79;
        result = hdd_get_link_info_by_vdev(v13);
        if ( !result )
          goto LABEL_11;
        if ( (wlan_sap_get_ch_params(*(_QWORD *)(result + 272), &v81) & 1) != 0 )
        {
LABEL_56:
          if ( BYTE4(v81) > 3uLL )
            v67 = 0;
          else
            v67 = dword_B357D8[BYTE4(v81)];
          cfg80211_chandef_create(a3, v53, v67);
          if ( (int)v81 > 3 )
          {
            if ( (_DWORD)v81 == 7 )
            {
              v78 = v82;
              a3[2] = 13;
              if ( !v78 )
                goto LABEL_74;
              goto LABEL_73;
            }
            if ( (_DWORD)v81 == 4 )
            {
              v76 = HIDWORD(v82);
              a3[2] = 4;
              if ( !v76 )
                goto LABEL_72;
              v77 = 4;
              goto LABEL_71;
            }
          }
          else
          {
            if ( (_DWORD)v81 == 2 )
            {
              v76 = 3;
              goto LABEL_70;
            }
            if ( (_DWORD)v81 == 3 )
            {
              v76 = 5;
LABEL_70:
              v77 = 2;
LABEL_71:
              a3[v77] = v76;
              goto LABEL_72;
            }
          }
          if ( (unsigned int)(v81 - 5) < 0xFFFFFFFD )
            goto LABEL_74;
LABEL_72:
          v78 = v82;
          if ( !(_DWORD)v82 )
          {
LABEL_74:
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: override AP freq %d to first AP(vdev_id %d) center_freq:%d width:%d freq1:%d freq2:%d ",
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              "wlan_hdd_is_ap_ap_force_scc_override",
              v16,
              v80[0],
              *(unsigned int *)(*(_QWORD *)a3 + 4LL),
              (unsigned int)a3[2],
              a3[3],
              a3[4]);
            result = 1;
            goto LABEL_11;
          }
LABEL_73:
          a3[3] = v78;
          goto LABEL_74;
        }
        v65 = v13[1];
        v64 = v66;
      }
      wlan_reg_set_channel_params_for_pwrmode(v65, v64, 0, (__int64)&v81, 0, v55, v56, v57, v58, v59, v60, v61, v62);
      goto LABEL_56;
    }
    v22 = "%s: channel conversion failed";
    goto LABEL_8;
  }
  _hdd_objmgr_put_vdev_by_user(v18, 6, "wlan_hdd_is_ap_ap_force_scc_override");
LABEL_10:
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
