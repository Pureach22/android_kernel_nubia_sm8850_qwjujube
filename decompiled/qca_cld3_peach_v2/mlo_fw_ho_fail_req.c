__int64 __fastcall mlo_fw_ho_fail_req(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int8 v4; // w19
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x23
  __int64 v16; // x21
  __int64 v17; // x8
  __int64 v18; // x22
  __int64 v19; // x8
  unsigned int *v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  v4 = a2;
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
  if ( !v6 )
    return qdf_trace_msg(0x8Fu, 2u, "%s: vdev is null", v7, v8, v9, v10, v11, v12, v13, v14, "mlo_fw_ho_fail_req");
  v15 = *(_QWORD *)(v6 + 1360);
  v16 = v6;
  if ( v15 )
  {
    v17 = *(_QWORD *)(v15 + 24);
    v18 = a3 & 0xFFFFFFFFFFFFLL;
    if ( v17 && v17 != v6 )
      cm_fw_ho_fail_req(a1, *(_BYTE *)(v17 + 168), v18);
    v19 = *(_QWORD *)(v15 + 32);
    if ( v19 )
    {
      if ( v19 != v16 )
        cm_fw_ho_fail_req(a1, *(_BYTE *)(v19 + 168), v18);
    }
  }
  else
  {
    v18 = a3 & 0xFFFFFFFFFFFFLL;
  }
  cm_fw_ho_fail_req(a1, v4, v18);
  return wlan_objmgr_vdev_release_ref(v16, 1u, v21, v22, v23, v24, v25, v26, v27, v28, v29);
}
