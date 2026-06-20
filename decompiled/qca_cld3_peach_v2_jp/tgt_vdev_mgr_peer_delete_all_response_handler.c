__int64 __fastcall tgt_vdev_mgr_peer_delete_all_response_handler(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  __int64 cmpt_obj; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  unsigned int v32; // w20

  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Invalid input",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tgt_vdev_mgr_peer_delete_all_response_handler");
    return 4;
  }
  v12 = ((__int64 (*)(void))wlan_objmgr_get_vdev_by_id_from_psoc)();
  if ( !v12 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV is NULL for vdev_id %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "tgt_vdev_mgr_peer_delete_all_response_handler",
      *a2);
    return 16;
  }
  v21 = v12;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v12);
  if ( cmpt_obj )
  {
    v31 = *(_QWORD *)(cmpt_obj + 512);
    if ( v31 )
    {
      v31 = *(_QWORD *)(v31 + 176);
      if ( v31 )
      {
        if ( *(_DWORD *)(v31 - 4) != 896848590 )
          __break(0x8228u);
        v32 = ((__int64 (*)(void))v31)();
        goto LABEL_14;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: PSOC_%d VDEV_MLME is NULL",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "tgt_vdev_mgr_peer_delete_all_response_handler",
      *a2,
      *(unsigned __int8 *)(a1 + 48));
  }
  v32 = 16;
LABEL_14:
  wlan_objmgr_vdev_release_ref(v21, 0x31u, (unsigned int *)v31, v23, v24, v25, v26, v27, v28, v29, v30);
  return v32;
}
