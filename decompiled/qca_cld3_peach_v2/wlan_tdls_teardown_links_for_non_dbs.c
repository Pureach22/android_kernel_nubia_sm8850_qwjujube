__int64 __fastcall wlan_tdls_teardown_links_for_non_dbs(__int64 a1, unsigned int a2)
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
  __int64 v13; // x8
  __int64 v14; // x19
  __int64 comp_private_obj; // x0

  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
    return 0;
  v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 17);
  if ( !v4 )
    return 16;
  v13 = *(_QWORD *)(v4 + 216);
  if ( v13 )
  {
    v13 = *(_QWORD *)(v13 + 80);
    if ( v13 )
    {
      v14 = v4;
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 0xAu);
      if ( !comp_private_obj )
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: Failed to get tdls psoc component",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "wlan_tdls_delete_all_peers");
LABEL_12:
        v4 = v14;
        goto LABEL_13;
      }
      v13 = *(_QWORD *)(comp_private_obj + 640);
      v4 = v14;
      if ( v13 )
      {
        if ( *(_DWORD *)(v13 - 4) != 349571447 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64))v13)(v14, 3);
        goto LABEL_12;
      }
    }
  }
LABEL_13:
  wlan_objmgr_vdev_release_ref(v4, 0x11u, (unsigned int *)v13, v5, v6, v7, v8, v9, v10, v11, v12);
  return 0;
}
