__int64 __fastcall wlan_cm_set_country_code(__int64 a1, unsigned __int8 a2, unsigned __int8 *a3)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int *ext_hdl_fl; // x8
  _QWORD *v15; // x20

  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du);
  if ( !vdev_by_id_from_pdev )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev object is NULL",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "wlan_cm_set_country_code");
  if ( (vdev_by_id_from_pdev[2] & 0xFFFFFFFD) != 0 )
  {
    ext_hdl_fl = (unsigned int *)&unk_81C000;
    wlan_cm_set_country_code_rso_cfg = 0;
  }
  else
  {
    v15 = vdev_by_id_from_pdev;
    ext_hdl_fl = (unsigned int *)cm_get_ext_hdl_fl(
                                   (__int64)vdev_by_id_from_pdev,
                                   (__int64)"wlan_cm_set_country_code",
                                   0x43Bu,
                                   v5,
                                   v6,
                                   v7,
                                   v8,
                                   v9,
                                   v10,
                                   v11,
                                   v12);
    vdev_by_id_from_pdev = v15;
    wlan_cm_set_country_code_rso_cfg = (__int64)ext_hdl_fl;
    if ( a3 )
    {
      if ( ext_hdl_fl )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: Country info from bcn IE:%c%c 0x%x",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "wlan_cm_set_country_code",
          *a3,
          a3[1],
          a3[2]);
        qdf_mem_copy((void *)(wlan_cm_set_country_code_rso_cfg + 88), a3, 3u);
        vdev_by_id_from_pdev = v15;
      }
    }
  }
  return wlan_objmgr_vdev_release_ref(
           (__int64)vdev_by_id_from_pdev,
           0x4Du,
           ext_hdl_fl,
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           v12);
}
