__int64 __fastcall send_set_ric_req_cmd_tlv(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x25
  __int64 v16; // x9
  __int64 v17; // x20
  int v18; // w8
  __int64 v19; // x24
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 result; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  v6 = wmi_buf_alloc_fl(a1, 0x58u, "send_set_ric_req_cmd_tlv", 0x492u);
  if ( !v6 )
    return 2;
  v15 = *(_QWORD *)(v6 + 224);
  *(_DWORD *)v15 = 22347788;
  v16 = 4;
  if ( !a3 )
    v16 = 14;
  v17 = v6;
  v18 = *(unsigned __int8 *)(a2 + 8LL * (a3 == 0));
  v19 = a2 + v16;
  *(_DWORD *)(v15 + 8) = 1;
  *(_DWORD *)(v15 + 12) = a3;
  *(_DWORD *)(v15 + 4) = v18;
  *(_QWORD *)(v15 + 16) = 0x15A004000120044LL;
  if ( a2 + v16 )
  {
    qdf_mem_copy((void *)(v15 + 24), (const void *)(v19 + 3), 2u);
    *(_DWORD *)(v15 + 28) = *(unsigned __int16 *)(v19 + 6);
    *(_DWORD *)(v15 + 32) = *(unsigned __int16 *)(v19 + 8);
    *(_DWORD *)(v15 + 36) = *(_DWORD *)(v19 + 10);
    *(_DWORD *)(v15 + 40) = *(_DWORD *)(v19 + 14);
    *(_DWORD *)(v15 + 44) = *(_DWORD *)(v19 + 18);
    *(_DWORD *)(v15 + 48) = *(_DWORD *)(v19 + 22);
    *(_DWORD *)(v15 + 52) = *(_DWORD *)(v19 + 26);
    *(_DWORD *)(v15 + 56) = *(_DWORD *)(v19 + 30);
    *(_DWORD *)(v15 + 60) = *(_DWORD *)(v19 + 34);
    *(_DWORD *)(v15 + 64) = *(_DWORD *)(v19 + 38);
    *(_DWORD *)(v15 + 68) = *(_DWORD *)(v19 + 42);
    *(_DWORD *)(v15 + 72) = *(_DWORD *)(v19 + 46);
    *(_DWORD *)(v15 + 76) = *(_DWORD *)(v19 + 50);
    *(_QWORD *)(v15 + 80) = *(unsigned __int16 *)(v19 + 54);
  }
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Set RIC Req is_add_ts: %d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "send_set_ric_req_cmd_tlv",
    a3);
  wmi_mtrace(0xB009u, *(_DWORD *)(v15 + 4), 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v17,
             0x58u,
             0xB009u,
             "send_set_ric_req_cmd_tlv",
             0x4CEu,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send vdev Set RIC Req command",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "send_set_ric_req_cmd_tlv");
    if ( a3 )
      *(_DWORD *)(a2 + 64) = 16;
    wmi_buf_free();
    return 16;
  }
  return result;
}
