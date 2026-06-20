__int64 __fastcall send_snr_request_cmd_tlv(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x19
  int v5; // w3
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v2 = wmi_buf_alloc_fl(a1, 0x18u, "send_snr_request_cmd_tlv", 0x1EA6u);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 224);
    v4 = v2;
    v5 = *(_DWORD *)(v3 + 8);
    *(_QWORD *)v3 = 0x8008F0014LL;
    qdf_mtrace(49, 100, 0xB01u, v5, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v4,
               0x18u,
               0x16001u,
               "send_snr_request_cmd_tlv",
               0x1EB2u,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send host stats request to fw",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "send_snr_request_cmd_tlv");
    wmi_buf_free();
  }
  return 16;
}
