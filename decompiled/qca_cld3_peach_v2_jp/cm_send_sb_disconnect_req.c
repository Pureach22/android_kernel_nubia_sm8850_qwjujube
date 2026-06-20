__int64 __fastcall cm_send_sb_disconnect_req(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  unsigned int v12; // w21
  unsigned int *v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( !a1 )
    return 16;
  v1 = *(_QWORD *)(a1 + 8);
  if ( !v1 )
    return 16;
  v2 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *(_QWORD *)v1,
         *(unsigned __int8 *)(v1 + 8),
         77);
  if ( v2 )
  {
    v11 = v2;
    v12 = wlan_cm_disconnect(v2, *(_DWORD *)(v1 + 12), *(_DWORD *)(v1 + 16), (int *)(v1 + 20));
    _qdf_mem_free(v1);
    wlan_objmgr_vdev_release_ref(v11, 0x4Du, v13, v14, v15, v16, v17, v18, v19, v20, v21);
    return v12;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev_id: %d: vdev not found",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "cm_send_sb_disconnect_req",
      *(unsigned __int8 *)(v1 + 8));
    return 4;
  }
}
