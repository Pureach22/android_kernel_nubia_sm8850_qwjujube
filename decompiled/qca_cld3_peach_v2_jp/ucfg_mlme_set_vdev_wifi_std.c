__int64 __fastcall ucfg_mlme_set_vdev_wifi_std(__int64 a1, __int64 a2, int a3)
{
  unsigned __int8 v4; // w19
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  __int64 ext_hdl; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( v5 )
  {
    v14 = v5;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v5, v6, v7, v8, v9, v10, v11, v12, v13);
    if ( ext_hdl )
    {
      *(_DWORD *)(ext_hdl + 24460) = a3;
      *(_BYTE *)(ext_hdl + 24459) = 1;
      wlan_objmgr_vdev_release_ref(
        v14,
        0x43u,
        (unsigned int *)(ext_hdl + 20480),
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23);
      return 0;
    }
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev %d: vmlme_priv is null",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "ucfg_mlme_set_vdev_wifi_std",
      v4);
    wlan_objmgr_vdev_release_ref(v14, 0x43u, v25, v26, v27, v28, v29, v30, v31, v32, v33);
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev %d: vdev not found",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "ucfg_mlme_set_vdev_wifi_std",
      v4);
  }
  return 16;
}
