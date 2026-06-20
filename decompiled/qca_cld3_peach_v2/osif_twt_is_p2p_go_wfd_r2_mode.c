bool __fastcall osif_twt_is_p2p_go_wfd_r2_mode(__int64 a1)
{
  __int64 v2; // x0
  unsigned int *v3; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(a1, 3, 94);
  if ( v2 )
  {
    v12 = *(unsigned __int8 *)(v2 + 168);
    wlan_objmgr_vdev_release_ref(v2, 0x5Eu, v3, v4, v5, v6, v7, v8, v9, v10, v11);
    return wlan_vdev_p2p_is_wfd_r2_mode(a1, v12, v13, v14, v15, v16, v17, v18, v19, v20);
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: vdev is null for P2P Go opmode",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "osif_twt_is_p2p_go_wfd_r2_mode");
    return 0;
  }
}
