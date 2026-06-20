__int64 __fastcall send_set_rssi_monitoring_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x19
  int v7; // w1
  int v8; // w9
  unsigned int v9; // w20
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x38u, "send_set_rssi_monitoring_cmd_tlv", 0x7Cu);
  if ( v4 )
  {
    v5 = *(_QWORD *)(v4 + 224);
    v6 = v4;
    *(_DWORD *)v5 = 26476596;
    v7 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v5 + 4) = v7;
    *(_DWORD *)(v5 + 8) = *(_DWORD *)a2;
    *(_QWORD *)(v5 + 40) = 0;
    *(_QWORD *)(v5 + 48) = 0x100000000LL;
    if ( *(_BYTE *)(a2 + 10) == 1 )
    {
      *(_DWORD *)(v5 + 12) = 9;
      *(_DWORD *)(v5 + 16) = *(char *)(a2 + 8);
      v8 = *(char *)(a2 + 9);
    }
    else
    {
      v8 = 0;
      *(_QWORD *)(v5 + 12) = 0;
    }
    *(_DWORD *)(v5 + 28) = v8;
    wmi_mtrace(0x1D00Fu, v7, 0);
    v9 = wmi_unified_cmd_send_fl(
           a1,
           v6,
           0x38u,
           0x1D00Fu,
           "send_set_rssi_monitoring_cmd_tlv",
           0x99u,
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17);
    if ( v9 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_RSSI_BREACH_MONITOR_CONFIG_CMDID",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "send_set_rssi_monitoring_cmd_tlv");
      wmi_buf_free();
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Sent WMI_RSSI_BREACH_MONITOR_CONFIG_CMDID to FW",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "send_set_rssi_monitoring_cmd_tlv");
  }
  else
  {
    return 2;
  }
  return v9;
}
