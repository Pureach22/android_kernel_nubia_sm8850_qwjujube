__int64 __fastcall cm_fw_roam_sync_req(__int64 a1, __int64 a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned int v6; // w20
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  _QWORD *context; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int *v69; // x8
  unsigned int v70; // w21
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  _BYTE v79[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v80; // [xsp+18h] [xbp-8h]

  v6 = a2;
  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
  if ( v8 )
  {
    v17 = v8;
    if ( cm_is_vdev_disconnecting(v8, v9, v10, v11, v12, v13, v14, v15, v16)
      || (mlo_is_any_link_disconnecting(v17) & 1) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Roam sync for vdev %d is not handled, since vdev is disconnecting",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "cm_fw_roam_sync_req",
        (unsigned __int8)v6);
LABEL_9:
      wlan_objmgr_vdev_release_ref(v17, 1u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
      result = 4;
      goto LABEL_10;
    }
    if ( (mlo_is_mld_connecting(v17) & 1) != 0 || cm_is_vdev_connecting(v17, v36, v37, v38, v39, v40, v41, v42, v43) )
    {
LABEL_8:
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d Roam sync not handled in connecting state",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "cm_fw_roam_sync_req",
        (unsigned __int8)v6);
      wlan_cm_roam_state_change(*(_QWORD *)(v17 + 216), v6, 3u, 0x24u);
      goto LABEL_9;
    }
    context = _cds_get_context(54, (__int64)"cm_is_peer_preset_on_other_sta", v36, v37, v38, v39, v40, v41, v42, v43);
    v79[0] = 0;
    if ( context )
    {
      if ( ((unsigned __int8)wma_objmgr_peer_exist((__int64)context, (__int64)(a3 + 14), v79) & 1) != 0
        && v79[0] != (unsigned __int8)v6
        && (mlo_check_is_given_vdevs_on_same_mld(a1, v6, v79[0]) & 1) == 0 )
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Peer %02x:%02x:%02x:**:**:%02x already exists on vdev %d, current vdev %d",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "cm_is_peer_preset_on_other_sta",
          a3[14],
          a3[15],
          a3[16],
          a3[19],
          v79[0],
          (unsigned __int8)v6);
        goto LABEL_8;
      }
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: wma_handle is NULL",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "cm_is_peer_preset_on_other_sta");
    }
    ((void (__fastcall *)(__int64))mlo_sta_stop_reconfig_timer)(v17);
    wlan_clear_mlo_sta_link_removed_flag(v17);
    v70 = cm_sm_deliver_event(v17, 0x12u, a4, (__int64)a3, v61, v62, v63, v64, v65, v66, v67, v68);
    if ( v70 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Roam sync was not handled",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "cm_fw_roam_sync_req");
      wlan_cm_roam_state_change(*(_QWORD *)(v17 + 216), v6, 3u, 0x24u);
    }
    wlan_objmgr_vdev_release_ref(v17, 1u, v69, v71, v72, v73, v74, v75, v76, v77, v78);
    result = v70;
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev object is NULL", v9, v10, v11, v12, v13, v14, v15, v16, "cm_fw_roam_sync_req");
    result = 29;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
