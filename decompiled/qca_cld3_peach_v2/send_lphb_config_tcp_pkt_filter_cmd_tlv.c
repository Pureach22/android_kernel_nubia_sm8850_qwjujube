__int64 __fastcall send_lphb_config_tcp_pkt_filter_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x19
  __int64 v7; // x10
  __int64 v8; // x11
  __int64 v9; // x12
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x34u, "send_lphb_config_tcp_pkt_filter_cmd_tlv", 0x55Du);
  if ( v4 )
  {
    v5 = *(_QWORD *)(v4 + 224);
    v6 = v4;
    *(_DWORD *)v5 = 14811184;
    *(_DWORD *)(v5 + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v5 + 8) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v5 + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(v5 + 16) = *(_DWORD *)(a2 + 16);
    v7 = *(_QWORD *)(a2 + 36);
    v8 = *(_QWORD *)(a2 + 20);
    v9 = *(_QWORD *)(a2 + 28);
    *(_QWORD *)(v5 + 44) = *(_QWORD *)(a2 + 44);
    *(_QWORD *)(v5 + 36) = v7;
    *(_QWORD *)(v5 + 28) = v9;
    *(_QWORD *)(v5 + 20) = v8;
    wmi_mtrace(0x23003u, 0xFFu, 0);
    v18 = wmi_unified_cmd_send_fl(
            a1,
            v6,
            0x34u,
            0x23003u,
            "send_lphb_config_tcp_pkt_filter_cmd_tlv",
            0x575u,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17);
    if ( v18 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: cmd_send WMI_HB_SET_TCP_PKT_FILTER returned Error %d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "send_lphb_config_tcp_pkt_filter_cmd_tlv",
        v18);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v18;
}
