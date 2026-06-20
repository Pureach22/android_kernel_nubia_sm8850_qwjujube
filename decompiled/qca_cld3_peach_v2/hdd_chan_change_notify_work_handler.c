__int64 __fastcall hdd_chan_change_notify_work_handler(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v9; // w8
  __int64 v10; // x22
  unsigned int v11; // w24
  __int64 v12; // x8
  __int64 v13; // x26
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x25
  __int64 vdev_by_user; // x19
  __int64 v24; // x23
  __int64 v25; // x20
  unsigned int v26; // w21
  _QWORD *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x22
  __int64 v37; // x8
  __int64 v38; // x20
  unsigned __int16 *v39; // x24
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w21
  _QWORD *v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  const char *v58; // x3
  __int64 v59; // x0
  const char *v60; // x2
  _QWORD *v61; // x8
  __int64 v62; // x0
  unsigned int v63; // w23
  __int64 ap_link_by_link_id; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x1
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int16 v82; // w10
  __int64 v83; // x8
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  const char *v92; // x2
  const char *v93; // x2
  int v94; // w22
  unsigned int v95; // w22
  _QWORD *v96; // x8
  unsigned __int16 reg_punc_bitmap; // w0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned __int16 v106; // w23
  _QWORD *v107; // x8
  unsigned int v108; // [xsp+2Ch] [xbp-54h] BYREF
  __int64 v109; // [xsp+30h] [xbp-50h] BYREF
  __int64 v110; // [xsp+38h] [xbp-48h]
  __int64 v111; // [xsp+40h] [xbp-40h]
  __int64 v112; // [xsp+48h] [xbp-38h]
  __int64 v113; // [xsp+50h] [xbp-30h] BYREF
  __int64 v114; // [xsp+58h] [xbp-28h]
  __int64 v115; // [xsp+60h] [xbp-20h]
  __int64 v116; // [xsp+68h] [xbp-18h]
  __int64 v117; // [xsp+70h] [xbp-10h]
  __int64 v118; // [xsp+78h] [xbp-8h]

  v118 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_67;
  v9 = *(_DWORD *)(result + 6004);
  if ( v9 != 1 )
  {
    if ( v9 )
      goto LABEL_67;
    v10 = *(_QWORD *)result;
    v11 = *(unsigned __int16 *)(result + 5976);
    v109 = 0;
    v110 = 0;
    v108 = 0;
    v12 = *(_QWORD *)(*(_QWORD *)(v10 + 24) + 16LL);
    v111 = 0;
    v112 = 0;
    if ( v12 )
    {
      v13 = result;
      result = _hdd_objmgr_get_vdev_by_user(result, 6, "hdd_chan_change_started_notify");
      if ( result )
      {
        v22 = *(_QWORD *)(result + 216);
        vdev_by_user = result;
        if ( !v22 || (v24 = *(_QWORD *)(v22 + 80)) == 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: psoc is NULL",
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            "hdd_chan_change_started_notify");
          v59 = vdev_by_user;
          v60 = "hdd_chan_change_started_notify";
LABEL_66:
          result = _hdd_objmgr_put_vdev_by_user(v59, 6, v60);
          goto LABEL_67;
        }
        v25 = *(_QWORD *)(v10 + 32);
        v26 = *(unsigned __int8 *)(result + 168);
        v27 = *(_QWORD **)(v25 + 992);
        if ( v27 )
          mutex_lock(*v27);
        if ( (unsigned int)wlan_vdev_mlme_is_active(vdev_by_user)
          && (unsigned int)wlan_vdev_is_restart_progress(vdev_by_user) )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Vdev %d mode %d not UP",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "hdd_chan_change_started_notify",
            v26,
            *(unsigned int *)(v10 + 40));
        }
        else
        {
          v116 = 0;
          v117 = 0;
          v114 = 0;
          v115 = 0;
          v113 = (unsigned __int16)v11;
          BYTE2(v113) = wlan_reg_freq_to_chan(v22, v11, v28, v29, v30, v31, v32, v33, v34, v35);
          HIWORD(v113) = 0;
          if ( (wlan_reg_is_dfs_for_freq(v22, v11, v74, v75, v76, v77, v78, v79, v80, v81) & 1) != 0 )
            HIWORD(v113) = 2;
          v82 = *(_WORD *)(v13 + 5985);
          v83 = *(_QWORD *)(v13 + 5988);
          LODWORD(v116) = *(_DWORD *)(v13 + 5980);
          *(_WORD *)((char *)&v113 + 3) = v82;
          v115 = v83;
          if ( (unsigned int)hdd_create_chandef(v10, &v113, &v109) )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Vdev %d failed to create channel def",
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              "hdd_chan_change_started_notify",
              v26);
          }
          else
          {
            if ( (wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, v84, v85, v86, v87, v88, v89, v90, v91) & 1) != 0 )
              v95 = *(unsigned __int8 *)(vdev_by_user + 93);
            else
              v95 = 0;
            wlan_mlme_get_sap_chn_switch_bcn_count(v24, &v108);
            reg_punc_bitmap = wlan_reg_get_reg_punc_bitmap(v13 + 5980);
            if ( !reg_punc_bitmap )
              reg_punc_bitmap = wlan_reg_get_input_punc_bitmap(v13 + 5980);
            v106 = reg_punc_bitmap;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: channel switch started notify: link_id %d, vdev_id %d chan:%d width:%d freq1:%d freq2:%d punct 0x%x ch"
              "_switch_count %d",
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              v104,
              v105,
              "hdd_chan_change_started_notify",
              v95,
              v26,
              *(unsigned int *)(v109 + 4),
              (unsigned int)v110,
              HIDWORD(v110),
              v111,
              reg_punc_bitmap,
              v108);
            HIWORD(v112) = v106;
            cfg80211_ch_switch_started_notify(v25, &v109, v95, v108, 0);
          }
        }
        v107 = *(_QWORD **)(v25 + 992);
        if ( v107 )
          mutex_unlock(*v107);
        v60 = "hdd_chan_change_started_notify";
LABEL_65:
        v59 = vdev_by_user;
        goto LABEL_66;
      }
      goto LABEL_67;
    }
    v58 = "hdd_chan_change_started_notify";
LABEL_21:
    result = qdf_trace_msg(0x33u, 2u, "%s: mac_handle is NULL", a2, a3, a4, a5, a6, a7, a8, a9, v58);
    goto LABEL_67;
  }
  v36 = *(_QWORD *)result;
  v113 = 0;
  v114 = 0;
  v37 = *(_QWORD *)(*(_QWORD *)(v36 + 24) + 16LL);
  v115 = 0;
  v116 = 0;
  if ( !v37 )
  {
    v58 = "hdd_chan_change_notify_update";
    goto LABEL_21;
  }
  v38 = *(_QWORD *)(v36 + 32);
  v39 = (unsigned __int16 *)result;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(result, 6, "hdd_chan_change_notify_update");
  if ( !vdev_by_user )
  {
    v61 = *(_QWORD **)(v38 + 992);
    if ( v61 )
      mutex_lock(*v61);
    v62 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v39 + 52832LL) + 32LL) + 1360LL);
    if ( !v62 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: Invalid mlo dev context",
                 v40,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 v47,
                 "wlan_hdd_get_standby_channel");
      goto LABEL_54;
    }
    v63 = v39[488];
    ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(v62, (unsigned __int8)v39[488]);
    if ( ap_link_by_link_id )
    {
      v73 = *(_QWORD *)(ap_link_by_link_id + 32);
      if ( v73 )
      {
        v48 = 255;
LABEL_42:
        if ( (unsigned int)hdd_create_chandef(v36, v73, &v113) )
        {
          v93 = "%s: Vdev %d failed to create channel def";
LABEL_45:
          result = qdf_trace_msg(
                     0x33u,
                     8u,
                     v93,
                     v50,
                     v51,
                     v52,
                     v53,
                     v54,
                     v55,
                     v56,
                     v57,
                     "hdd_chan_change_notify_update",
                     v48);
          goto LABEL_54;
        }
        if ( (unsigned int)(*(_DWORD *)(*(_QWORD *)v39 + 40LL) - 1) > 1 )
          v94 = 0;
        else
          v94 = v39[1320];
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: notify: link_id %d vdev_id %d chan:%d width:%d freq1:%d freq2:%d punct 0x%x",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "hdd_chan_change_notify_update",
          v63,
          v48,
          *(unsigned int *)(v113 + 4),
          (unsigned int)v114,
          HIDWORD(v114),
          v115,
          v94);
        HIWORD(v116) = v94;
        result = cfg80211_ch_switch_notify(v38, &v113, v63);
        goto LABEL_54;
      }
      v92 = "%s: link chan info for standby link id: %d is NULL";
    }
    else
    {
      v92 = "%s: mlo link info is NULL for standby link id: %d";
    }
    result = qdf_trace_msg(
               0x33u,
               8u,
               v92,
               v65,
               v66,
               v67,
               v68,
               v69,
               v70,
               v71,
               v72,
               "wlan_hdd_get_standby_channel",
               (unsigned __int8)v63);
    goto LABEL_54;
  }
  v48 = *(unsigned __int8 *)(vdev_by_user + 168);
  wlan_twt_concurrency_update(*(_QWORD *)(v36 + 24));
  v49 = *(_QWORD **)(v38 + 992);
  if ( v49 )
    mutex_lock(*v49);
  if ( (unsigned int)wlan_vdev_mlme_is_active(vdev_by_user) )
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: Vdev %d mode %d not UP",
               v50,
               v51,
               v52,
               v53,
               v54,
               v55,
               v56,
               v57,
               "hdd_chan_change_notify_update",
               v48,
               *(unsigned int *)(v36 + 40));
    goto LABEL_54;
  }
  if ( (*(_DWORD *)(v36 + 40) | 2) == 2 && !ucfg_cm_is_vdev_active(vdev_by_user, v50, v51, v52, v53, v54, v55, v56, v57) )
  {
    v93 = "%s: Vdev %d is not connected";
    goto LABEL_45;
  }
  if ( (wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, v50, v51, v52, v53, v54, v55, v56, v57) & 1) != 0 )
    v63 = *(unsigned __int8 *)(vdev_by_user + 93);
  else
    v63 = 0;
  result = wlan_vdev_get_active_channel(vdev_by_user);
  if ( result )
  {
    v73 = result;
    goto LABEL_42;
  }
LABEL_54:
  v96 = *(_QWORD **)(v38 + 992);
  if ( v96 )
    result = mutex_unlock(*v96);
  if ( vdev_by_user )
  {
    v60 = "hdd_chan_change_notify_update";
    goto LABEL_65;
  }
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}
