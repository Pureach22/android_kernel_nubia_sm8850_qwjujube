__int64 __fastcall mlme_sap_set_twt_all_peers_cmd_in_progress(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v12; // w19
  unsigned __int8 v15; // w23
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  _QWORD *v26; // x0
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x22
  __int64 next_active_peer_of_vdev; // x23
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 comp_private_obj; // x0

  v12 = a3;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: psoc is NULL, dialog_id: %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "mlme_sap_set_twt_all_peers_cmd_in_progress",
      a3);
    return 29;
  }
  v15 = a2;
  v16 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v16 )
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev is NULL, vdev_id: %d dialog_id: %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "mlme_sap_set_twt_all_peers_cmd_in_progress",
      v15,
      a3);
    return 29;
  }
  v25 = v16;
  v26 = wlan_vdev_peer_list_peek_active_head(v16, (_QWORD *)(v16 + 128), 2u);
  if ( !v26 )
    goto LABEL_14;
  v36 = (__int64)v26;
  while ( 1 )
  {
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(v36, 0);
    if ( !comp_private_obj )
      goto LABEL_6;
    v27 = (unsigned int *)*(unsigned __int8 *)(comp_private_obj + 41);
    if ( !*(_BYTE *)(comp_private_obj + 41) )
      goto LABEL_6;
    if ( v12 == 255 || *(unsigned __int8 *)(comp_private_obj + 44) == v12 )
      break;
    if ( (_DWORD)v27 != 1 )
      goto LABEL_13;
LABEL_6:
    next_active_peer_of_vdev = wlan_peer_get_next_active_peer_of_vdev(v25, (_QWORD *)(v25 + 128), v36, 2u);
    wlan_objmgr_peer_release_ref(v36, 2u, v38, v39, v40, v41, v42, v43, v44, v45);
    v36 = next_active_peer_of_vdev;
    if ( !next_active_peer_of_vdev )
      goto LABEL_14;
  }
  *(_DWORD *)(comp_private_obj + 48) = a4;
  if ( (_DWORD)v27 == 1 || v12 != 255 )
    goto LABEL_6;
LABEL_13:
  __break(0x5512u);
LABEL_14:
  wlan_objmgr_vdev_release_ref(v25, 2u, v27, v28, v29, v30, v31, v32, v33, v34, v35);
  return 0;
}
