__int64 __fastcall send_coex_config_cmd_tlv(__int64 a1, int *a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x8
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
  unsigned int v25; // w20

  v4 = wmi_buf_alloc_fl(a1, 0x24u, "send_coex_config_cmd_tlv", 0x26C6u);
  if ( !v4 )
    return 16;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 34209824;
  v7 = *a2;
  v5[1] = *a2;
  v5[2] = a2[1];
  v5[3] = a2[2];
  v5[4] = a2[3];
  v5[5] = a2[4];
  v5[6] = a2[5];
  v5[7] = a2[6];
  v5[8] = a2[7];
  qdf_mtrace(49, 100, 0x1483u, v7, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             0x24u,
             0x29003u,
             "send_coex_config_cmd_tlv",
             0x26DBu,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15);
  if ( (_DWORD)result )
  {
    v25 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Sending COEX CONFIG CMD failed",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "send_coex_config_cmd_tlv");
    wmi_buf_free();
    return v25;
  }
  return result;
}
