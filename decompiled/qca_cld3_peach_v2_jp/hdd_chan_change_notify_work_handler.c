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
  __int64 v23; // x19
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
  unsigned int v39; // w21
  _QWORD *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v49; // x3
  __int64 v50; // x0
  const char *v51; // x2
  _QWORD *v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  const char *v61; // x2
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int16 v70; // w10
  __int64 v71; // x8
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned __int16 reg_punc_bitmap; // w0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  unsigned __int16 v89; // w22
  _QWORD *v90; // x8
  _QWORD *v91; // x8
  unsigned int v92; // [xsp+24h] [xbp-4Ch] BYREF
  __int64 v93; // [xsp+28h] [xbp-48h] BYREF
  __int64 v94; // [xsp+30h] [xbp-40h]
  __int64 v95; // [xsp+38h] [xbp-38h]
  __int64 v96; // [xsp+40h] [xbp-30h]
  __int64 v97; // [xsp+48h] [xbp-28h] BYREF
  __int64 v98; // [xsp+50h] [xbp-20h]
  __int64 v99; // [xsp+58h] [xbp-18h]
  __int64 v100; // [xsp+60h] [xbp-10h]
  __int64 v101; // [xsp+68h] [xbp-8h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_49;
  v9 = *(_DWORD *)(result + 4444);
  if ( v9 != 1 )
  {
    if ( v9 )
      goto LABEL_49;
    v10 = *(_QWORD *)result;
    v11 = *(unsigned __int16 *)(result + 4424);
    v93 = 0;
    v94 = 0;
    v92 = 0;
    v12 = *(_QWORD *)(*(_QWORD *)(v10 + 24) + 16LL);
    v95 = 0;
    v96 = 0;
    if ( v12 )
    {
      v13 = result;
      result = _hdd_objmgr_get_vdev_by_user(result, 6, "hdd_chan_change_started_notify");
      if ( result )
      {
        v22 = *(_QWORD *)(result + 152);
        v23 = result;
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
          v50 = v23;
          v51 = "hdd_chan_change_started_notify";
LABEL_48:
          result = _hdd_objmgr_put_vdev_by_user(v50, 6, v51);
          goto LABEL_49;
        }
        v25 = *(_QWORD *)(v10 + 32);
        v26 = *(unsigned __int8 *)(result + 104);
        v27 = *(_QWORD **)(v25 + 992);
        if ( v27 )
          mutex_lock(*v27);
        if ( (unsigned int)wlan_vdev_mlme_is_active(v23) && (unsigned int)wlan_vdev_is_restart_progress(v23) )
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
          v99 = 0;
          v100 = 0;
          v98 = 0;
          v97 = (unsigned __int16)v11;
          BYTE2(v97) = wlan_reg_freq_to_chan(v22, v11, v28, v29, v30, v31, v32, v33, v34, v35);
          HIWORD(v97) = 0;
          if ( (wlan_reg_is_dfs_for_freq(v22, v11, v62, v63, v64, v65, v66, v67, v68, v69) & 1) != 0 )
            HIWORD(v97) = 2;
          v70 = *(_WORD *)(v13 + 4433);
          v71 = *(_QWORD *)(v13 + 4436);
          LODWORD(v100) = *(_DWORD *)(v13 + 4428);
          *(_WORD *)((char *)&v97 + 3) = v70;
          v99 = v71;
          if ( (unsigned int)hdd_create_chandef(v10, &v97, &v93) )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Vdev %d failed to create channel def",
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              "hdd_chan_change_started_notify",
              v26);
          }
          else
          {
            wlan_mlme_get_sap_chn_switch_bcn_count(v24, &v92);
            reg_punc_bitmap = wlan_reg_get_reg_punc_bitmap();
            if ( !reg_punc_bitmap )
              reg_punc_bitmap = wlan_reg_get_input_punc_bitmap();
            v89 = reg_punc_bitmap;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: channel switch started notify: link_id %d, vdev_id %d chan:%d width:%d freq1:%d freq2:%d punct 0x%x ch"
              "_switch_count %d",
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              v88,
              "hdd_chan_change_started_notify",
              0,
              v26,
              *(unsigned int *)(v93 + 4),
              (unsigned int)v94,
              HIDWORD(v94),
              v95,
              reg_punc_bitmap,
              v92);
            HIWORD(v96) = v89;
            cfg80211_ch_switch_started_notify(v25, &v93, 0, v92, 0);
          }
        }
        v90 = *(_QWORD **)(v25 + 992);
        if ( v90 )
          mutex_unlock(*v90);
        v51 = "hdd_chan_change_started_notify";
LABEL_47:
        v50 = v23;
        goto LABEL_48;
      }
      goto LABEL_49;
    }
    v49 = "hdd_chan_change_started_notify";
LABEL_21:
    result = qdf_trace_msg(0x33u, 2u, "%s: mac_handle is NULL", a2, a3, a4, a5, a6, a7, a8, a9, v49);
    goto LABEL_49;
  }
  v36 = *(_QWORD *)result;
  v97 = 0;
  v98 = 0;
  v37 = *(_QWORD *)(*(_QWORD *)(v36 + 24) + 16LL);
  v99 = 0;
  v100 = 0;
  if ( !v37 )
  {
    v49 = "hdd_chan_change_notify_update";
    goto LABEL_21;
  }
  v38 = *(_QWORD *)(v36 + 32);
  result = _hdd_objmgr_get_vdev_by_user(result, 6, "hdd_chan_change_notify_update");
  v23 = result;
  if ( result )
  {
    v39 = *(unsigned __int8 *)(result + 104);
    wlan_twt_concurrency_update(*(_QWORD *)(v36 + 24));
    v40 = *(_QWORD **)(v38 + 992);
    if ( v40 )
      mutex_lock(*v40);
    if ( (unsigned int)wlan_vdev_mlme_is_active(v23) )
    {
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: Vdev %d mode %d not UP",
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 v47,
                 v48,
                 "hdd_chan_change_notify_update",
                 v39,
                 *(unsigned int *)(v36 + 40));
      goto LABEL_43;
    }
    if ( (*(_DWORD *)(v36 + 40) | 2) == 2 && !ucfg_cm_is_vdev_active(v23, v41, v42, v43, v44, v45, v46, v47, v48) )
    {
      v61 = "%s: Vdev %d is not connected";
      goto LABEL_35;
    }
    result = wlan_vdev_get_active_channel(v23);
    if ( !result )
      goto LABEL_43;
    if ( (unsigned int)hdd_create_chandef(v36, result, &v97) )
    {
      v61 = "%s: Vdev %d failed to create channel def";
LABEL_35:
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 v61,
                 v53,
                 v54,
                 v55,
                 v56,
                 v57,
                 v58,
                 v59,
                 v60,
                 "hdd_chan_change_notify_update",
                 v39);
      goto LABEL_43;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: notify: link_id %d vdev_id %d chan:%d width:%d freq1:%d freq2:%d punct 0x%x",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "hdd_chan_change_notify_update",
      0,
      v39,
      *(unsigned int *)(v97 + 4),
      (unsigned int)v98,
      HIDWORD(v98),
      v99,
      0);
    HIWORD(v100) = 0;
    result = cfg80211_ch_switch_notify(v38, &v97, 0);
  }
  else
  {
    v52 = *(_QWORD **)(v38 + 992);
    if ( v52 )
      result = mutex_lock(*v52);
  }
LABEL_43:
  v91 = *(_QWORD **)(v38 + 992);
  if ( v91 )
    result = mutex_unlock(*v91);
  if ( v23 )
  {
    v51 = "hdd_chan_change_notify_update";
    goto LABEL_47;
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
