__int64 __fastcall wlan_cm_get_roam_scan_scheme_bitmap(__int64 a1, __int64 a2)
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
  unsigned int *ext_hdl_fl; // x8
  __int64 v14; // x19
  unsigned int v15; // w19

  v2 = a2;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( v3 )
  {
    ext_hdl_fl = (unsigned int *)*(unsigned int *)(v3 + 16);
    if ( ((unsigned int)ext_hdl_fl & 0xFFFFFFFD) != 0
      || (v14 = v3,
          ext_hdl_fl = (unsigned int *)cm_get_ext_hdl_fl(
                                         v3,
                                         (__int64)"wlan_cm_get_roam_scan_scheme_bitmap",
                                         0xB1Au,
                                         v4,
                                         v5,
                                         v6,
                                         v7,
                                         v8,
                                         v9,
                                         v10,
                                         v11),
          v3 = v14,
          !ext_hdl_fl) )
    {
      wlan_objmgr_vdev_release_ref(v3, 2u, ext_hdl_fl, v4, v5, v6, v7, v8, v9, v10, v11);
      return 0;
    }
    else
    {
      v15 = ext_hdl_fl[25];
      wlan_objmgr_vdev_release_ref(v3, 2u, ext_hdl_fl, v4, v5, v6, v7, v8, v9, v10, v11);
      return v15;
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev%d: vdev object is NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_cm_get_roam_scan_scheme_bitmap",
      v2);
    return 0;
  }
}
