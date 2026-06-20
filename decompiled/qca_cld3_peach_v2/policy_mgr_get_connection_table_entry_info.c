__int64 __fastcall policy_mgr_get_connection_table_entry_info(__int64 a1, unsigned int a2, __int64 a3)
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
  __int64 v15; // x19
  __int64 active_channel; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned __int16 *v26; // x23
  __int64 cmpt_obj; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w8
  int vdev_mac_id; // w0
  unsigned int v38; // w20

  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x18u);
  if ( vdev_by_id_from_pdev )
  {
    v15 = (__int64)vdev_by_id_from_pdev;
    active_channel = wlan_vdev_get_active_channel((__int64)vdev_by_id_from_pdev);
    if ( active_channel )
    {
      v26 = (unsigned __int16 *)active_channel;
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v15, v18, v19, v20, v21, v22, v23, v24, v25);
      if ( cmpt_obj )
      {
        *(_DWORD *)a3 = *(unsigned __int8 *)(cmpt_obj + 179);
        v36 = *(unsigned __int8 *)(cmpt_obj + 180);
        *(_BYTE *)(a3 + 8) = a2;
        *(_DWORD *)(a3 + 4) = v36;
        *(_DWORD *)(a3 + 12) = *v26;
        *(_DWORD *)(a3 + 16) = *((_DWORD *)v26 + 6);
        *(_WORD *)(a3 + 24) = v26[3];
        vdev_mac_id = wlan_mlme_get_vdev_mac_id(a1, a2);
        v38 = 0;
        *(_DWORD *)(a3 + 20) = vdev_mac_id;
LABEL_8:
        wlan_objmgr_vdev_release_ref(v15, 0x18u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
        return v38;
      }
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: vdev %d component object is NULL",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "policy_mgr_get_connection_table_entry_info",
        (unsigned __int8)a2);
    }
    v38 = 4;
    goto LABEL_8;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: vdev is NULL",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "policy_mgr_get_connection_table_entry_info");
  return 4;
}
