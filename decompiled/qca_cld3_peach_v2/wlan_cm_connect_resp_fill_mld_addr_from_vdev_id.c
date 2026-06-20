__int64 __fastcall wlan_cm_connect_resp_fill_mld_addr_from_vdev_id(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  result = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( result )
  {
    v15 = result;
    cm_connect_resp_fill_mld_addr_from_candidate(result, a3, a4, v7, v8, v9, v10, v11, v12, v13, v14);
    return wlan_objmgr_vdev_release_ref(v15, 0x4Du, v16, v17, v18, v19, v20, v21, v22, v23, v24);
  }
  return result;
}
