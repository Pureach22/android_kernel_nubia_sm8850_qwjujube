__int64 __fastcall lim_send_peer_create_resp(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  result = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
             *(_QWORD *)(a1 + 21552),
             a2,
             7);
  if ( result )
  {
    v13 = result;
    wlan_cm_bss_peer_create_rsp(result, a3, v5, v6, v7, v8, v9, v10, v11, v12);
    return wlan_objmgr_vdev_release_ref(v13, 7u, v14, v15, v16, v17, v18, v19, v20, v21, v22);
  }
  return result;
}
