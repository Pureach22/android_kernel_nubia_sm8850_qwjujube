_QWORD *__fastcall wlan_mlme_set_vdev_mac_id(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  _QWORD *result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  __int64 ext_hdl; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w1
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  result = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 7u);
  if ( result )
  {
    v14 = (__int64)result;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl((__int64)result, v6, v7, v8, v9, v10, v11, v12, v13);
    if ( ext_hdl )
    {
      v24 = *(unsigned __int8 *)(ext_hdl + 24924);
      *(_DWORD *)(ext_hdl + 24924) = a3;
      wlan_dp_notify_vdev_mac_id_migration(v14, v24, a3);
    }
    else
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: vdev %d private object is NULL",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_mlme_set_vdev_mac_id",
        a2);
    }
    return (_QWORD *)wlan_objmgr_vdev_release_ref(v14, 7u, v25, v26, v27, v28, v29, v30, v31, v32, v33);
  }
  return result;
}
