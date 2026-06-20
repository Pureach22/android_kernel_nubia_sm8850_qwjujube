__int64 __fastcall send_process_dhcpserver_offload_cmd_tlv(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x20
  unsigned int v7; // w3
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x18u, "send_process_dhcpserver_offload_cmd_tlv", 0x218Fu);
  if ( !v4 )
    return 2;
  v5 = *(_QWORD *)(v4 + 224);
  v6 = v4;
  *(_DWORD *)v5 = 22544404;
  v7 = *a2;
  *(_DWORD *)(v5 + 4) = *a2;
  *(_DWORD *)(v5 + 8) = *((unsigned __int8 *)a2 + 4);
  *(_DWORD *)(v5 + 20) = a2[2];
  *(_QWORD *)(v5 + 12) = a2[3];
  qdf_mtrace(49, 100, 0x1681u, v7, 0);
  if ( (unsigned int)wmi_unified_cmd_send_fl(
                       a1,
                       v6,
                       0x18u,
                       0x2D001u,
                       "send_process_dhcpserver_offload_cmd_tlv",
                       0x21A1u,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send set_dhcp_server_offload cmd",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "send_process_dhcpserver_offload_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Set dhcp server offload to vdevId %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "send_process_dhcpserver_offload_cmd_tlv",
      *a2);
    return 0;
  }
}
