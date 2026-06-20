__int64 __fastcall mlme_init_all_peers_twt_context(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w19
  unsigned __int8 v13; // w22
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  _QWORD *v24; // x0
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x21
  __int64 next_active_peer_of_vdev; // x22
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  _BYTE *comp_private_obj; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7

  v11 = a3;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: psoc is NULL, dialog_id: %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "mlme_init_all_peers_twt_context",
      a3);
    return 29;
  }
  v13 = a2;
  v14 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v14 )
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev is NULL, vdev_id: %d dialog_id: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "mlme_init_all_peers_twt_context",
      v13,
      a3);
    return 29;
  }
  v23 = v14;
  v24 = wlan_vdev_peer_list_peek_active_head(v14, (_QWORD *)(v14 + 128), 2u);
  if ( v24 )
  {
    v34 = (__int64)v24;
    do
    {
      comp_private_obj = (_BYTE *)wlan_objmgr_peer_get_comp_private_obj(v34, 0);
      if ( comp_private_obj )
      {
        comp_private_obj[41] = 1;
        if ( v11 == 255 || (unsigned __int8)comp_private_obj[44] == v11 )
        {
          comp_private_obj[46] = 0;
          comp_private_obj[44] = -1;
        }
      }
      next_active_peer_of_vdev = wlan_peer_get_next_active_peer_of_vdev(v23, (_QWORD *)(v23 + 128), v34, 2u);
      wlan_objmgr_peer_release_ref(v34, 2u, v36, v37, v38, v39, v40, v41, v42, v43);
      v34 = next_active_peer_of_vdev;
    }
    while ( next_active_peer_of_vdev );
  }
  wlan_objmgr_vdev_release_ref(v23, 2u, v25, v26, v27, v28, v29, v30, v31, v32, v33);
  qdf_trace_msg(0x1Fu, 8u, "%s: init done", v45, v46, v47, v48, v49, v50, v51, v52, "mlme_init_all_peers_twt_context");
  return 0;
}
