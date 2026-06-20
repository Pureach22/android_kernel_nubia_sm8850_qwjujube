__int64 __fastcall send_link_status_req_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x19
  int v7; // w3
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x18u, "send_link_status_req_cmd_tlv", 0x1EEDu);
  if ( v4 )
  {
    v5 = *(_QWORD *)(v4 + 224);
    v6 = v4;
    *(_QWORD *)v5 = 0x20008F0014LL;
    v7 = *a2;
    *(_DWORD *)(v5 + 8) = v7;
    qdf_mtrace(49, 100, 0xB01u, v7, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v6,
               0x18u,
               0x16001u,
               "send_link_status_req_cmd_tlv",
               0x1EFAu,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI link  status request to fw",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "send_link_status_req_cmd_tlv");
    wmi_buf_free();
  }
  return 16;
}
