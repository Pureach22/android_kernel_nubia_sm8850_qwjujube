__int64 __fastcall cm_disconnect_start_req(__int64 a1, __int64 *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 result; // x0
  unsigned int v17; // w19

  if ( !cm_get_cm_ctx_fl(a1, "cm_disconnect_start_req", 829) )
    return 4;
  v4 = _qdf_mem_malloc(0x9F0u, "cm_disconnect_start_req", 837);
  if ( !v4 )
    return 2;
  v13 = v4;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v5, v6, v7, v8, v9, v10, v11, v12) & 1) != 0 && (*(_BYTE *)(a1 + 60) & 2) == 0 )
    *((_BYTE *)a2 + 18) = 1;
  v15 = *a2;
  v14 = a2[1];
  *(_DWORD *)(v13 + 44) = *((_DWORD *)a2 + 4);
  *(_QWORD *)(v13 + 36) = v14;
  *(_QWORD *)(v13 + 28) = v15;
  result = cm_sm_deliver_event(a1, 13, 24, v13 + 24);
  if ( (_DWORD)result )
  {
    v17 = result;
    _qdf_mem_free(v13);
    return v17;
  }
  return result;
}
