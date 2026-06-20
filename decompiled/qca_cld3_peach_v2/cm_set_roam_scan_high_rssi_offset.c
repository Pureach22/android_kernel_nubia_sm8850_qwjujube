__int64 __fastcall cm_set_roam_scan_high_rssi_offset(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v4; // w20
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 rso_config_fl; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x24
  __int64 v27; // x0
  unsigned int *v28; // x21
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w20
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7

  v4 = a2;
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( v6 )
  {
    v15 = v6;
    rso_config_fl = wlan_cm_get_rso_config_fl(v6, "cm_set_roam_scan_high_rssi_offset", 4221);
    if ( rso_config_fl
      && (v26 = rso_config_fl, (v27 = _qdf_mem_malloc(0x6Cu, "cm_set_roam_scan_high_rssi_offset", 4225)) != 0) )
    {
      v28 = (unsigned int *)v27;
      wlan_cm_set_roam_scan_high_rssi_offset(a1, a3);
      qdf_mem_set(v28, 0x6Cu, 0);
      cm_roam_scan_offload_rssi_thresh(a1, v4, v28, v26);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev:%d Configured high RSSI delta=%d, 5 GHZ roam flag=%d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "cm_set_roam_scan_high_rssi_offset",
        (unsigned __int8)v4,
        v28[2],
        v28[26] & 1);
      v37 = wlan_cm_tgt_send_roam_scan_offload_rssi_params(v15, v28);
      if ( v37 )
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: fail to set roam scan high RSSI offset",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "cm_set_roam_scan_high_rssi_offset");
      _qdf_mem_free((__int64)v28);
    }
    else
    {
      v37 = 4;
    }
    wlan_objmgr_vdev_release_ref(v15, 0x4Du, v17, v18, v19, v20, v21, v22, v23, v24, v25);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL for vdev %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "cm_set_roam_scan_high_rssi_offset",
      (unsigned __int8)v4);
    return 16;
  }
  return v37;
}
