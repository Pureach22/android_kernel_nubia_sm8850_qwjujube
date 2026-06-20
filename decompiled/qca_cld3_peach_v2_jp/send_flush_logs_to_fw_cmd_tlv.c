__int64 __fastcall send_flush_logs_to_fw_cmd_tlv(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v2 = wmi_buf_alloc_fl(a1, 8u, "send_flush_logs_to_fw_cmd_tlv", 0x2CD6u);
  if ( !v2 )
    return 2;
  v3 = v2;
  **(_QWORD **)(v2 + 224) = 26148868;
  qdf_mtrace(49, 100, 0xB08u, 0xFFu, 0);
  if ( (unsigned int)wmi_unified_cmd_send_fl(
                       a1,
                       v3,
                       8u,
                       0x16008u,
                       "send_flush_logs_to_fw_cmd_tlv",
                       0x2CE5u,
                       v4,
                       v5,
                       v6,
                       v7,
                       v8,
                       v9,
                       v10,
                       v11) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_DEBUG_MESG_FLUSH_CMDID",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "send_flush_logs_to_fw_cmd_tlv");
    wmi_buf_free();
    return 4;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Sent WMI_DEBUG_MESG_FLUSH_CMDID to FW",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "send_flush_logs_to_fw_cmd_tlv");
    return 0;
  }
}
