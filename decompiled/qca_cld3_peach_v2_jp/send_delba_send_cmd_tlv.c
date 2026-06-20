__int64 __fastcall send_delba_send_cmd_tlv(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  __int64 v6; // x0
  _DWORD *v7; // x8
  __int64 v8; // x19
  int v9; // w3
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  v6 = wmi_buf_alloc_fl(a1, 0x1Cu, "send_delba_send_cmd_tlv", 0x3289u);
  if ( !v6 )
    return 2;
  v7 = *(_DWORD **)(v6 + 224);
  v8 = v6;
  *v7 = 10616856;
  v9 = *a3;
  v7[1] = v9;
  v7[2] = *(_DWORD *)a2;
  v7[3] = *(unsigned __int16 *)(a2 + 4);
  v7[4] = a3[1];
  v7[5] = a3[2];
  v7[6] = *((unsigned __int16 *)a3 + 2);
  qdf_mtrace(49, 100, 0x404u, v9, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v8,
             0x1Cu,
             0x8004u,
             "send_delba_send_cmd_tlv",
             0x329Au,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send cmd to fw, ret=%d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "send_delba_send_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return 16;
  }
  return result;
}
