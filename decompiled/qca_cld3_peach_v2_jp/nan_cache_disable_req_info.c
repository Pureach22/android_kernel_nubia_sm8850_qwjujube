__int64 __fastcall nan_cache_disable_req_info(__int64 a1, char a2)
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
  __int64 v13; // x19
  __int64 comp_private_obj; // x0
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w21

  if ( (ucfg_nan_is_vdev_creation_allowed(a1) & 1) == 0 )
    return 0;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(a1, 16, 20);
  if ( v4 )
  {
    v13 = v4;
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v4, 0xFu);
    if ( comp_private_obj )
    {
      v24 = 0;
      *(_BYTE *)(comp_private_obj + 138) = a2;
    }
    else
    {
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: nan vdev priv obj is null",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "nan_cache_disable_req_info");
      v24 = 29;
    }
    wlan_objmgr_vdev_release_ref(v13, 0x14u, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    return v24;
  }
  else
  {
    qdf_trace_msg(0x53u, 2u, "%s: vdev is null", v5, v6, v7, v8, v9, v10, v11, v12, "nan_cache_disable_req_info");
    return 29;
  }
}
