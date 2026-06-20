__int64 __fastcall cm_roam_restart_req(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  unsigned int v4; // w20
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int hb_ap_rssi; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v5 )
    return 4;
  v14 = v5;
  v15 = (unsigned int *)((unsigned int)a3 - 11);
  if ( (unsigned int)v15 <= 1 && (mlme_get_roam_reason_better_ap(v5, v6, v7, v8, v9, v10, v11, v12, v13) & 1) != 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Sending heartbeat failure, reason %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "cm_roam_restart_req",
      a3);
    hb_ap_rssi = mlme_get_hb_ap_rssi(v14, v16, v17, v18, v19, v20, v21, v22, v23);
    v25 = wlan_cm_send_beacon_miss(v4, hb_ap_rssi);
    mlme_set_roam_reason_better_ap(v14, 0, v25, v26, v27, v28, v29, v30, v31, v32);
  }
  wlan_objmgr_vdev_release_ref(v14, 2u, v15, v6, v7, v8, v9, v10, v11, v12, v13);
  return 0;
}
