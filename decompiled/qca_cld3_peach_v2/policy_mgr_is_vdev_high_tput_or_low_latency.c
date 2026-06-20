__int64 __fastcall policy_mgr_is_vdev_high_tput_or_low_latency(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w19
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  double v13; // d0
  char v14; // w0
  char v15; // w19
  unsigned int *v16; // x8
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v2 = a2;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( v3 )
  {
    v12 = v3;
    v13 = wlan_is_vdev_traffic_ll_ht();
    v15 = v14;
    wlan_objmgr_vdev_release_ref(v12, 0x18u, v16, v13, v17, v18, v19, v20, v21, v22, v23);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: invalid vdev for id %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "policy_mgr_is_vdev_high_tput_or_low_latency",
      v2);
    v15 = 0;
  }
  return v15 & 1;
}
