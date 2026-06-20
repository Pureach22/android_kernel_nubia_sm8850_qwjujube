__int64 __fastcall ucfg_mlme_set_vdev_traffic_high_throughput(__int64 a1, __int64 a2, char a3)
{
  unsigned __int8 v4; // w19
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  char v14; // w1
  __int64 v15; // x20
  unsigned int v16; // w19
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( v5 )
  {
    v14 = a3 & 1;
    v15 = v5;
    v16 = ucfg_mlme_set_vdev_traffic_type(v5, v14, 2u, v6, v7, v8, v9, v10, v11, v12, v13);
    wlan_objmgr_vdev_release_ref(v15, 0x43u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev %d: vdev not found",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "ucfg_mlme_set_vdev_traffic_high_throughput",
      v4);
    return 16;
  }
  return v16;
}
