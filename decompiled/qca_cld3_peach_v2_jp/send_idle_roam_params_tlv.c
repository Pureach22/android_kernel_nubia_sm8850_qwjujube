__int64 __fastcall send_idle_roam_params_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x22
  __int64 v14; // x19
  int v15; // w8
  unsigned int v16; // w9
  int v17; // w10
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // [xsp+0h] [xbp-20h]
  unsigned int v36; // [xsp+8h] [xbp-18h]
  int v37; // [xsp+10h] [xbp-10h]

  v4 = wmi_buf_alloc_fl(a1, 0x20u, "send_idle_roam_params_tlv", 0x18BCu);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 52297756;
  v13[1] = *(_DWORD *)a2;
  v13[2] = *(unsigned __int8 *)(a2 + 4);
  v13[3] = *(_DWORD *)(a2 + 8);
  v13[4] = *(_DWORD *)(a2 + 12);
  v15 = *(_DWORD *)(a2 + 16);
  v13[5] = v15;
  v16 = *(_DWORD *)(a2 + 20) / 0x3E8u;
  v13[6] = v16;
  v17 = *(_DWORD *)(a2 + 24);
  v13[7] = v17;
  v37 = v17;
  v36 = v16;
  v35 = v15;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: RSO_CFG: vdev_id:%d enable:%d band:%d rssi_delta:%d min_rssi:%d idle_time:%d data_pkt:%d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_idle_roam_params_tlv",
    v35,
    v36,
    v37);
  wmi_mtrace(0xB015u, v13[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x20u,
             0xB015u,
             "send_idle_roam_params_tlv",
             0x18D4u,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_ROAM_IDLE_CONFIG_CMDID",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "send_idle_roam_params_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
