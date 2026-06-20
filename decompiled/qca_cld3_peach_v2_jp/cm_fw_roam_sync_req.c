__int64 __fastcall cm_fw_roam_sync_req(__int64 a1, __int64 a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned int v6; // w20
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x4
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
  unsigned int *v61; // x8
  unsigned int v62; // w21
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  _BYTE v71[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v72; // [xsp+18h] [xbp-8h]

  v6 = a2;
  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
  if ( v7 )
  {
    v16 = v7;
    if ( cm_is_vdev_disconnecting(v7, v8, v9, v10, v11, v12, v13, v14, v15) )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Roam sync for vdev %d is not handled, since vdev is disconnecting",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "cm_fw_roam_sync_req",
        (unsigned __int8)v6);
LABEL_8:
      wlan_objmgr_vdev_release_ref(v16, 1u, v25, v26, v27, v28, v29, v30, v31, v32, v33);
      result = 4;
      goto LABEL_17;
    }
    if ( cm_is_vdev_connecting(v16, v17, v18, v19, v20, v21, v22, v23, v24) )
    {
      v43 = (unsigned __int8)v6;
LABEL_7:
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d Roam sync not handled in connecting state",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "cm_fw_roam_sync_req",
        v43);
      wlan_cm_roam_state_change(*(_QWORD *)(v16 + 152), v6, 3, 0x24u);
      goto LABEL_8;
    }
    context = _cds_get_context(54, (__int64)"cm_is_peer_preset_on_other_sta", v35, v36, v37, v38, v39, v40, v41, v42);
    v71[0] = 0;
    if ( context )
    {
      if ( ((unsigned __int8)wma_objmgr_peer_exist((__int64)context, (__int64)(a3 + 14), v71) & 1) != 0
        && v71[0] != (unsigned __int8)v6 )
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
          v71[0],
          (unsigned __int8)v6);
        v43 = (unsigned __int8)v6;
        goto LABEL_7;
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
    v62 = cm_sm_deliver_event(v16, 0x12u, a4, (__int64)a3, v53, v54, v55, v56, v57, v58, v59, v60);
    if ( v62 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Roam sync was not handled",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "cm_fw_roam_sync_req");
      wlan_cm_roam_state_change(*(_QWORD *)(v16 + 152), v6, 3, 0x24u);
    }
    wlan_objmgr_vdev_release_ref(v16, 1u, v61, v63, v64, v65, v66, v67, v68, v69, v70);
    result = v62;
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev object is NULL", v8, v9, v10, v11, v12, v13, v14, v15, "cm_fw_roam_sync_req");
    result = 29;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
