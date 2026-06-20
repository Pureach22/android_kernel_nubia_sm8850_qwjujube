__int64 __fastcall wlan_cm_get_psk_pmk(__int64 result, char a2, void *a3, _BYTE *a4)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 ext_hdl_fl; // x8
  _QWORD *v16; // x20

  if ( a3 && a4 )
  {
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(result, a2, 0x4Du);
    if ( vdev_by_id_from_pdev )
    {
      if ( (vdev_by_id_from_pdev[2] & 0xFFFFFFFD) != 0 )
      {
        ext_hdl_fl = (__int64)&policy_mgr_2_freq_always_on_same_mac___last_ticks;
        wlan_cm_get_psk_pmk_rso_cfg = 0;
      }
      else
      {
        v16 = vdev_by_id_from_pdev;
        ext_hdl_fl = cm_get_ext_hdl_fl(
                       (__int64)vdev_by_id_from_pdev,
                       (__int64)"wlan_cm_get_psk_pmk",
                       0x33Bu,
                       v7,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14);
        vdev_by_id_from_pdev = v16;
        wlan_cm_get_psk_pmk_rso_cfg = ext_hdl_fl;
        if ( ext_hdl_fl )
        {
          qdf_mem_copy(a3, (const void *)(ext_hdl_fl + 727), *(unsigned __int8 *)(ext_hdl_fl + 791));
          vdev_by_id_from_pdev = v16;
          ext_hdl_fl = *(unsigned __int8 *)(wlan_cm_get_psk_pmk_rso_cfg + 791);
          *a4 = ext_hdl_fl;
        }
      }
      return wlan_objmgr_vdev_release_ref(
               (__int64)vdev_by_id_from_pdev,
               0x4Du,
               (unsigned int *)ext_hdl_fl,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14);
    }
    else
    {
      return qdf_trace_msg(
               0x68u,
               2u,
               "%s: vdev object is NULL",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "wlan_cm_get_psk_pmk");
    }
  }
  return result;
}
