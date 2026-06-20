__int64 __fastcall send_update_fw_tdls_state_cmd_tlv(__int64 a1, unsigned int *a2, unsigned int a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _DWORD *v15; // x23
  __int64 v16; // x19
  unsigned int v17; // w8
  unsigned int v18; // w9
  unsigned int v19; // w10
  unsigned int v20; // w11
  unsigned int v21; // w12
  unsigned int v22; // w13
  unsigned int v23; // w14
  unsigned int v24; // w15
  unsigned int v25; // w16
  unsigned int v26; // w17
  unsigned int v27; // w0
  unsigned int v28; // w1
  unsigned int v29; // w2
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 result; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // [xsp+0h] [xbp-70h]
  unsigned int v48; // [xsp+8h] [xbp-68h]
  unsigned int v49; // [xsp+10h] [xbp-60h]
  unsigned int v50; // [xsp+18h] [xbp-58h]
  unsigned int v51; // [xsp+20h] [xbp-50h]
  unsigned int v52; // [xsp+28h] [xbp-48h]
  unsigned int v53; // [xsp+30h] [xbp-40h]
  unsigned int v54; // [xsp+38h] [xbp-38h]
  unsigned int v55; // [xsp+40h] [xbp-30h]
  unsigned int v56; // [xsp+48h] [xbp-28h]
  unsigned int v57; // [xsp+50h] [xbp-20h]
  unsigned int v58; // [xsp+58h] [xbp-18h]
  unsigned int v59; // [xsp+60h] [xbp-10h]

  v6 = wmi_buf_alloc_fl(a1, 0x44u, "send_update_fw_tdls_state_cmd_tlv", 0x2CCu);
  if ( v6 )
  {
    v15 = *(_DWORD **)(v6 + 224);
    v16 = v6;
    *v15 = 13107264;
    v15[1] = *a2;
    v15[2] = a3;
    v15[3] = a2[2];
    v17 = a2[3];
    v15[4] = v17;
    v18 = a2[4];
    v15[5] = v18;
    v19 = a2[5];
    v15[6] = v19;
    v20 = a2[6];
    v15[7] = v20;
    v21 = a2[7];
    v15[8] = v21;
    v22 = a2[8];
    v15[9] = v22;
    v23 = a2[9];
    v15[10] = v23;
    v24 = a2[10];
    v15[11] = v24;
    v25 = a2[11];
    v15[12] = v25;
    v26 = a2[12];
    v15[13] = v26;
    v27 = a2[13];
    v15[14] = v27;
    v28 = a2[14];
    v15[15] = v28;
    v29 = a2[15];
    v15[16] = v29;
    v59 = v29;
    v58 = v28;
    v57 = v27;
    v56 = v26;
    v55 = v25;
    v54 = v24;
    v53 = v23;
    v52 = v22;
    v51 = v21;
    v50 = v20;
    v49 = v19;
    v48 = v18;
    v47 = v17;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev %d tdls_state: %d, state: %d, notification_interval_ms: %d, tx_discovery_threshold: %d, tx_teardown_thres"
      "hold: %d, rssi_teardown_threshold: %d, rssi_delta: %d, tdls_options: 0x%x, tdls_peer_traffic_ind_window: %d, tdls_"
      "peer_traffic_response_timeout: %d, tdls_puapsd_mask: 0x%x, tdls_puapsd_inactivity_time: %d, tdls_puapsd_rx_frame_t"
      "hreshold: %d, teardown_notification_ms: %d, tdls_peer_kickout_threshold: %d, tdls_discovery_wake_timeout: %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "send_update_fw_tdls_state_cmd_tlv",
      *a2,
      a3,
      a3,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59);
    wmi_mtrace(0x20001u, v15[1], 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v16,
               0x44u,
               0x20001u,
               "send_update_fw_tdls_state_cmd_tlv",
               0x30Du,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send tdls set state command",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "send_update_fw_tdls_state_cmd_tlv");
    wmi_buf_free();
  }
  return 16;
}
