bool __fastcall p2p_is_random_mac(__int64 a1, __int64 a2, const void *a3)
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
  __int64 v13; // x20
  _BOOL4 v14; // w19
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 15);
  if ( v4 )
  {
    v13 = v4;
    v14 = qdf_mem_cmp((const void *)(v4 + 74), a3, 6u) != 0;
    wlan_objmgr_vdev_release_ref(v13, 0xFu, v15, v16, v17, v18, v19, v20, v21, v22, v23);
  }
  else
  {
    qdf_trace_msg(0x4Eu, 8u, "%s: random_mac:vdev is null", v5, v6, v7, v8, v9, v10, v11, v12, "p2p_is_random_mac");
    return 0;
  }
  return v14;
}
