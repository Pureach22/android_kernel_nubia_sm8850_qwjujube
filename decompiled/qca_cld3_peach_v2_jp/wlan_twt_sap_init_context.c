__int64 __fastcall wlan_twt_sap_init_context(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int8 v15; // w21
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x20
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
  __int64 v36; // x21
  __int64 next_active_peer_of_vdev; // x22
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 comp_private_obj; // x0
  __int64 v47; // x22
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7

  if ( *(_DWORD *)a3 != -1 || *(__int16 *)(a3 + 4) != -1 )
    return wlan_twt_init_context(a1, (unsigned __int8 *)a3, a4);
  if ( !a1 )
    return qdf_trace_msg(
             0x96u,
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
             "wlan_twt_init_all_peers_context",
             a4);
  v15 = a2;
  v16 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 94);
  if ( !v16 )
    return qdf_trace_msg(
             0x96u,
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
             "wlan_twt_init_all_peers_context",
             v15,
             a4);
  v25 = v16;
  v26 = wlan_vdev_peer_list_peek_active_head(v16, (_QWORD *)(v16 + 128), 0x5Eu);
  if ( v26 )
  {
    v36 = (__int64)v26;
    do
    {
      comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(v36, 0x2Cu);
      if ( comp_private_obj )
      {
        v47 = comp_private_obj;
        *(_BYTE *)(comp_private_obj + 65) = 1;
        qdf_mutex_acquire(comp_private_obj);
        if ( a4 == 0xFF || *(unsigned __int8 *)(v47 + 72) == a4 )
        {
          *(_BYTE *)(v47 + 74) = 0;
          *(_BYTE *)(v47 + 72) = -1;
        }
        qdf_mutex_release(v47);
      }
      next_active_peer_of_vdev = wlan_peer_get_next_active_peer_of_vdev(v25, (_QWORD *)(v25 + 128), v36, 0x5Eu);
      wlan_objmgr_peer_release_ref(v36, 0x5Eu, v38, v39, v40, v41, v42, v43, v44, v45);
      v36 = next_active_peer_of_vdev;
    }
    while ( next_active_peer_of_vdev );
  }
  wlan_objmgr_vdev_release_ref(v25, 0x5Eu, v27, v28, v29, v30, v31, v32, v33, v34, v35);
  return qdf_trace_msg(
           0x96u,
           8u,
           "%s: init done",
           v48,
           v49,
           v50,
           v51,
           v52,
           v53,
           v54,
           v55,
           "wlan_twt_init_all_peers_context");
}
