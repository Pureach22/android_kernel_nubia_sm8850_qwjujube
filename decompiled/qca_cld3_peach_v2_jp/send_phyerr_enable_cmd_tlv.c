__int64 __fastcall send_phyerr_enable_cmd_tlv(__int64 a1)
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
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20

  v2 = wmi_buf_alloc_fl(a1, 8u, "send_phyerr_enable_cmd_tlv", 0x2334u);
  if ( !v2 )
    return 16;
  v3 = v2;
  **(_QWORD **)(v2 + 224) = 11599876;
  qdf_mtrace(49, 100, 0x501u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v3,
             8u,
             0xA001u,
             "send_phyerr_enable_cmd_tlv",
             0x2342u,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11);
  if ( (_DWORD)result )
  {
    v21 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Sending PDEV DFS enable cmd failed",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "send_phyerr_enable_cmd_tlv");
    wmi_buf_free();
    return v21;
  }
  return result;
}
