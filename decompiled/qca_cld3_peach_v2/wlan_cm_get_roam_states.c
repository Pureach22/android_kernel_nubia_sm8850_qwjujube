__int64 __fastcall wlan_cm_get_roam_states(__int64 a1, __int64 a2, int a3)
{
  unsigned __int8 v4; // w20
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int *ext_hdl_fl; // x8
  __int64 v16; // x20
  unsigned int v17; // w19

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( v5 )
  {
    ext_hdl_fl = (unsigned int *)*(unsigned int *)(v5 + 16);
    if ( ((unsigned int)ext_hdl_fl & 0xFFFFFFFD) != 0
      || (v16 = v5,
          ext_hdl_fl = (unsigned int *)cm_get_ext_hdl_fl(
                                         v5,
                                         (__int64)"wlan_cm_get_roam_states",
                                         0xB5Eu,
                                         v6,
                                         v7,
                                         v8,
                                         v9,
                                         v10,
                                         v11,
                                         v12,
                                         v13),
          v5 = v16,
          !ext_hdl_fl) )
    {
      wlan_objmgr_vdev_release_ref(v5, 2u, ext_hdl_fl, v6, v7, v8, v9, v10, v11, v12, v13);
      return 0;
    }
    else
    {
      if ( a3 == 2 )
      {
        v17 = ext_hdl_fl[214];
      }
      else if ( a3 == 1 )
      {
        v17 = ext_hdl_fl[216];
      }
      else if ( a3 )
      {
        v17 = 0;
      }
      else
      {
        v17 = ext_hdl_fl[215];
      }
      wlan_objmgr_vdev_release_ref(v16, 2u, ext_hdl_fl, v6, v7, v8, v9, v10, v11, v12, v13);
      return v17;
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev%d: vdev object is NULL",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_cm_get_roam_states",
      v4);
    return 0;
  }
}
