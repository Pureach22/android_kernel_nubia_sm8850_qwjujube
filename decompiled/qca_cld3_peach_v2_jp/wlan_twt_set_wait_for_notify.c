__int64 __fastcall wlan_twt_set_wait_for_notify(__int64 a1, __int64 a2, char a3)
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
  _BYTE *comp_private_obj; // x0
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v34; // x2

  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 94);
  if ( v4 )
  {
    v13 = v4;
    comp_private_obj = (_BYTE *)wlan_objmgr_vdev_get_comp_private_obj(v4, 0x2Cu);
    if ( comp_private_obj )
    {
      *comp_private_obj = a3 & 1;
      qdf_trace_msg(
        0x96u,
        8u,
        "%s: twt_wait_for_notify: %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_twt_set_wait_for_notify",
        a3 & 1);
      wlan_objmgr_vdev_release_ref(v13, 0x5Eu, v24, v25, v26, v27, v28, v29, v30, v31, v32);
      return 0;
    }
    wlan_objmgr_vdev_release_ref(v13, 0x5Eu, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    v34 = "%s: twt vdev private object is NULL";
  }
  else
  {
    v34 = "%s: vdev object not found";
  }
  qdf_trace_msg(0x96u, 2u, v34, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_twt_set_wait_for_notify");
  return 4;
}
