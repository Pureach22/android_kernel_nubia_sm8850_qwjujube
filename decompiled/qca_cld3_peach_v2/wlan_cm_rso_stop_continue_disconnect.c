__int64 __fastcall wlan_cm_rso_stop_continue_disconnect(__int64 a1, __int64 a2, char a3)
{
  unsigned int v4; // w20
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x1
  __int64 *v26; // x8
  __int64 is_vdev_connecting; // x0
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x21
  unsigned int *v38; // x8
  unsigned int *v39; // x22
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x4
  __int64 v57; // x5
  unsigned int v58; // w19
  unsigned __int16 v60; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v61; // [xsp+8h] [xbp-18h] BYREF
  __int64 v62[2]; // [xsp+10h] [xbp-10h] BYREF

  v4 = a2;
  v62[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = 0;
  v62[0] = 0;
  v60 = 0;
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
  if ( v6 )
  {
    v15 = v6;
    if ( (wlan_vdev_mlme_is_mlo_vdev(v6, v7, v8, v9, v10, v11, v12, v13, v14) & 1) != 0 )
    {
      mlo_get_ml_vdev_list(v15, &v60, &v61);
      if ( v60 )
      {
        if ( v60 <= 2u )
        {
          if ( (*(_BYTE *)(v61 + 60) & 2) != 0
            && (wlan_cm_is_vdev_disconnecting(v61, v17, v18, v19, v20, v21, v22, v23, v24)
             || wlan_cm_is_vdev_connecting(v61, v17, v18, v19, v20, v21, v22, v23, v24))
            && (unsigned int)wlan_cm_get_active_req_type(v61, v17, v18, v19, v20, v21, v22, v23, v24) == 2 )
          {
            v26 = &v61;
          }
          else
          {
            v16 = (unsigned int *)v60;
            if ( v60 < 2u )
            {
LABEL_22:
              if ( !(_DWORD)v16 )
                goto LABEL_25;
              mlo_release_vdev_ref(v61);
              v16 = (unsigned int *)v60;
              if ( v60 < 2u )
                goto LABEL_25;
              is_vdev_connecting = mlo_release_vdev_ref(v62[0]);
              v16 = (unsigned int *)v60;
              if ( v60 <= 2u )
                goto LABEL_25;
LABEL_37:
              __break(0x5512u);
              _ReadStatusReg(CNTVCTSS_EL0);
              _ReadStatusReg(CNTVCTSS_EL0);
              return wlan_cm_enable_roaming_on_connected_sta(is_vdev_connecting, v25);
            }
            is_vdev_connecting = v62[0];
            if ( (*(_BYTE *)(v62[0] + 60) & 2) == 0
              || !wlan_cm_is_vdev_disconnecting(v62[0], v17, v18, v19, v20, v21, v22, v23, v24)
              && (is_vdev_connecting = wlan_cm_is_vdev_connecting(v62[0], v17, v18, v19, v20, v21, v22, v23, v24),
                  (is_vdev_connecting & 1) == 0)
              || (is_vdev_connecting = wlan_cm_get_active_req_type(v62[0], v17, v18, v19, v20, v21, v22, v23, v24),
                  (_DWORD)is_vdev_connecting != 2) )
            {
              v16 = (unsigned int *)v60;
              if ( v60 > 2u )
                goto LABEL_37;
              goto LABEL_22;
            }
            v26 = v62;
          }
          v4 = *(unsigned __int8 *)(*v26 + 168);
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: Invalid number of VDEVs num_links:%u",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "wlan_cm_mlo_update_disconnecting_vdev_id");
        }
        v16 = (unsigned int *)v60;
        goto LABEL_22;
      }
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: No VDEVs under vdev id: %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlan_cm_mlo_update_disconnecting_vdev_id",
        (unsigned __int8)v4);
    }
LABEL_25:
    wlan_objmgr_vdev_release_ref(v15, 1u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
    goto LABEL_26;
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev_id: %d vdev not found",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "wlan_cm_mlo_update_disconnecting_vdev_id",
    (unsigned __int8)v4);
LABEL_26:
  v28 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v4, 1);
  if ( v28 )
  {
    v37 = v28;
    v39 = (unsigned int *)_qdf_mem_malloc(0x18u, "wlan_cm_rso_stop_continue_disconnect", 604);
    if ( v39 )
    {
      if ( (cm_get_active_disconnect_req(v37, (__int64)v39, v40, v41, v42, v43, v44, v45, v46, v47) & 1) != 0 )
      {
        if ( (a3 & 1) != 0 )
        {
          v56 = *((unsigned __int8 *)v39 + 4);
          v57 = *v39;
          *((_QWORD *)v39 + 1) = 0xFFF000000008LL;
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: vdev %d cm_id 0x%x: Updating source(%d) and reason code (%d) to RSO reason and source as ho fail is rece"
            "ived in RSO stop",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "wlan_cm_rso_stop_continue_disconnect",
            v56,
            v57,
            8,
            65520);
        }
        wlan_cm_disc_cont_after_rso_stop(v37, v39);
        v58 = 0;
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev: %d: Active disconnect not found",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "wlan_cm_rso_stop_continue_disconnect",
          (unsigned __int8)v4);
        v58 = 14;
      }
    }
    else
    {
      v58 = 2;
    }
    wlan_objmgr_vdev_release_ref(v37, 1u, v38, v40, v41, v42, v43, v44, v45, v46, v47);
    _qdf_mem_free((__int64)v39);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev_id: %d vdev not found",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wlan_cm_rso_stop_continue_disconnect",
      (unsigned __int8)v4);
    v58 = 29;
  }
  _ReadStatusReg(SP_EL0);
  return v58;
}
