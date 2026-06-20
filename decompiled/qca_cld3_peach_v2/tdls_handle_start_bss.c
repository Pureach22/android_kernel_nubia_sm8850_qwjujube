__int64 __fastcall tdls_handle_start_bss(__int64 a1)
{
  unsigned int v2; // w20
  unsigned int v3; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x0
  __int64 v13; // x19
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v2 = policy_mgr_mode_specific_vdev_id(a1, 0);
  if ( v2 == 255
    && ((v3 = policy_mgr_mode_specific_vdev_id(a1, 2), v3 == 255)
     || (v2 = v3, (unsigned int)policy_mgr_get_connection_count_with_mlo(a1) != 1))
    || (v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v2, 17)) == 0 )
  {
    qdf_trace_msg(0, 2u, "%s: Unable get the tdls vdev", v4, v5, v6, v7, v8, v9, v10, v11, "tdls_handle_start_bss");
    return 16;
  }
  else
  {
    v13 = v12;
    tdls_set_tdls_offchannelmode(v12, 3u);
    wlan_objmgr_vdev_release_ref(v13, 0x11u, v14, v15, v16, v17, v18, v19, v20, v21, v22);
    return 0;
  }
}
