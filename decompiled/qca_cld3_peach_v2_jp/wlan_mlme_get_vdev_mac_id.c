__int64 __fastcall wlan_mlme_get_vdev_mac_id(__int64 a1, unsigned __int8 a2)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 ext_hdl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int *v22; // x8
  unsigned int v23; // w20

  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 7u);
  if ( vdev_by_id_from_pdev )
  {
    v12 = (__int64)vdev_by_id_from_pdev;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl((__int64)vdev_by_id_from_pdev, v4, v5, v6, v7, v8, v9, v10, v11);
    if ( ext_hdl )
    {
      v22 = (_DWORD *)&unk_60F4;
      v23 = *(_DWORD *)(ext_hdl + 24820);
    }
    else
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: vdev %d private object is NULL",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_mlme_get_vdev_mac_id",
        a2);
      v23 = 0;
    }
    wlan_objmgr_vdev_release_ref(v12, 7u, v22, v14, v15, v16, v17, v18, v19, v20, v21);
  }
  else
  {
    return 0;
  }
  return v23;
}
