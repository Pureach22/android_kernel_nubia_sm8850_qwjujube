__int64 __fastcall wlan_cm_update_roam_states(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  unsigned __int8 v6; // w21
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int *ext_hdl_fl; // x8
  __int64 v18; // x21

  v6 = a2;
  v7 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( v7 )
  {
    ext_hdl_fl = (unsigned int *)*(unsigned int *)(v7 + 16);
    if ( ((unsigned int)ext_hdl_fl & 0xFFFFFFFD) != 0
      || (v18 = v7,
          ext_hdl_fl = (unsigned int *)cm_get_ext_hdl_fl(
                                         v7,
                                         (__int64)"wlan_cm_update_roam_states",
                                         0xB36u,
                                         v8,
                                         v9,
                                         v10,
                                         v11,
                                         v12,
                                         v13,
                                         v14,
                                         v15),
          v7 = v18,
          !ext_hdl_fl) )
    {
      wlan_objmgr_vdev_release_ref(v7, 2u, ext_hdl_fl, v8, v9, v10, v11, v12, v13, v14, v15);
      return 16;
    }
    else
    {
      switch ( a4 )
      {
        case 2:
          ext_hdl_fl[214] = a3;
          break;
        case 1:
          ext_hdl_fl[216] = a3;
          break;
        case 0:
          ext_hdl_fl[215] = a3;
          break;
      }
      wlan_objmgr_vdev_release_ref(v18, 2u, ext_hdl_fl, v8, v9, v10, v11, v12, v13, v14, v15);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev%d: vdev object is NULL",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wlan_cm_update_roam_states",
      v6);
    return 16;
  }
}
