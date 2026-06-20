__int64 __fastcall cm_disconnect(__int64 a1, __int64 a2, int a3, int a4, int *a5)
{
  unsigned __int8 v8; // w20
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  unsigned int v19; // w19
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  v8 = a2;
  v9 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( v9 )
  {
    v18 = v9;
    v19 = wlan_cm_disconnect(v9, a3, a4, a5);
    wlan_objmgr_vdev_release_ref(v18, 0x4Du, v20, v21, v22, v23, v24, v25, v26, v27, v28);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev_id: %d: vdev not found",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "cm_disconnect",
      v8);
    return 4;
  }
  return v19;
}
