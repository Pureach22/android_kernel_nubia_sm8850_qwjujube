__int64 __fastcall send_roam_bss_load_config_tlv(__int64 a1, _DWORD *a2)
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
  int v16; // w9
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
  int v36; // [xsp+8h] [xbp-18h]
  int v37; // [xsp+10h] [xbp-10h]

  v4 = wmi_buf_alloc_fl(a1, 0x24u, "send_roam_bss_load_config_tlv", 0x1855u);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 51052576;
  v13[1] = *a2;
  v13[4] = a2[1];
  v13[8] = a2[3];
  v13[3] = a2[2];
  v15 = a2[6];
  v13[5] = v15;
  v16 = a2[5];
  v13[6] = v16;
  v17 = a2[4];
  v13[7] = v17;
  v37 = v17;
  v36 = v16;
  v35 = v15;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: RSO_CFG: vdev:%d bss_load_thres:%d bss_alpha:%d monitor_time:%d rssi_2g:%d rssi_5g:%d, rssi_6g:%d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_roam_bss_load_config_tlv",
    v35,
    v36,
    v37);
  wmi_mtrace(0xB013u, v13[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x24u,
             0xB013u,
             "send_roam_bss_load_config_tlv",
             0x186Fu,
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
      "%s: Failed to send WMI_ROAM_BSS_LOAD_CONFIG_CMDID",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "send_roam_bss_load_config_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
