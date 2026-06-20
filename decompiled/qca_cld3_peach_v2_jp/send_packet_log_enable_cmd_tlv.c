__int64 __fastcall send_packet_log_enable_cmd_tlv(__int64 a1, unsigned int a2, unsigned __int8 a3)
{
  __int64 v6; // x0
  _DWORD *v7; // x11
  __int64 v8; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v6 = wmi_buf_alloc_fl(a1, 0x10u, "send_packet_log_enable_cmd_tlv", 0xE80u);
  if ( v6 )
  {
    v7 = *(_DWORD **)(v6 + 224);
    v8 = v6;
    v7[2] = a2 & 0x2F | (a2 >> 2) & 0x80 | (a2 >> 2) & 0x100;
    *v7 = 10813452;
    v7[1] = a3;
    qdf_mtrace(49, 100, 0x204u, a3, 0);
    v17 = wmi_unified_cmd_send_fl(
            a1,
            v8,
            0x10u,
            0x4004u,
            "send_packet_log_enable_cmd_tlv",
            0xE92u,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16);
    if ( v17 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send pktlog enable cmd to FW =%d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "send_packet_log_enable_cmd_tlv",
        v17);
      wmi_buf_free();
    }
  }
  else
  {
    return (unsigned int)-2;
  }
  return v17;
}
