double __fastcall wlan_twt_sap_set_command_in_progress(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned __int8 v14; // w19
  double result; // d0
  unsigned __int8 v17; // w22
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x21
  _QWORD *v28; // x0
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x22
  __int64 next_active_peer_of_vdev; // x23
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 comp_private_obj; // x0
  int v49; // w25
  __int64 v50; // x23
  __int64 v51; // x0
  __int64 v52; // x1
  __int64 v53; // x2
  __int64 v54; // x3

  v14 = a4;
  if ( *(_DWORD *)a3 != -1 || *(__int16 *)(a3 + 4) != -1 )
  {
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))wlan_twt_set_command_in_progress)(a1, a3, a4, a5);
    return result;
  }
  if ( !a1 )
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: psoc is NULL, dialog_id: %d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wlan_twt_sap_set_all_peers_cmd_in_progress",
      (unsigned __int8)a4);
    return result;
  }
  v17 = a2;
  v18 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 94);
  if ( !v18 )
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: vdev is NULL, vdev_id: %d dialog_id: %d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_twt_sap_set_all_peers_cmd_in_progress",
      v17,
      v14);
    return result;
  }
  v27 = v18;
  v28 = wlan_vdev_peer_list_peek_active_head(v18, (_QWORD *)(v18 + 192), 0x5Eu);
  if ( !v28 )
  {
LABEL_19:
    wlan_objmgr_vdev_release_ref(v27, 0x5Eu, v29, v30, v31, v32, v33, v34, v35, v36, v37);
    return result;
  }
  v38 = (__int64)v28;
  while ( 1 )
  {
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(v38, 0x2Cu);
    if ( !comp_private_obj )
      goto LABEL_12;
    v49 = *(unsigned __int8 *)(comp_private_obj + 65);
    v50 = comp_private_obj;
    v51 = qdf_mutex_acquire(comp_private_obj);
    if ( v49 )
    {
      if ( v14 != 0xFF && *(unsigned __int8 *)(v50 + 72) != v14 || (*(_DWORD *)(v50 + 76) = a5, v14 == 0xFF) )
      {
        if ( v49 != 1 )
          break;
      }
    }
    qdf_mutex_release(v50);
LABEL_12:
    next_active_peer_of_vdev = wlan_peer_get_next_active_peer_of_vdev(v27, (_QWORD *)(v27 + 192), v38, 0x5Eu);
    wlan_objmgr_peer_release_ref(v38, 0x5Eu, v40, v41, v42, v43, v44, v45, v46, v47);
    v38 = next_active_peer_of_vdev;
    if ( !next_active_peer_of_vdev )
      goto LABEL_19;
  }
  __break(0x5512u);
  return wlan_twt_sap_init_context(v51, v52, v53, v54);
}
