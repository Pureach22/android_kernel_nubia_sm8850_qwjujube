__int64 __fastcall send_limit_off_chan_cmd_tlv(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x22
  __int64 v14; // x19
  int v15; // w5
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x14u, "send_limit_off_chan_cmd_tlv", 0x17B0u);
  if ( !v4 )
    return 2;
  v13 = *(_QWORD *)(v4 + 224);
  v14 = v4;
  *(_DWORD *)v13 = 43581456;
  *(_QWORD *)(v13 + 4) = *a2;
  v15 = *((unsigned __int8 *)a2 + 4);
  *(_DWORD *)(v13 + 8) = v15;
  if ( *((_BYTE *)a2 + 16) == 1 )
    *(_DWORD *)(v13 + 8) = v15 | 2;
  *(_DWORD *)(v13 + 12) = a2[2];
  *(_DWORD *)(v13 + 16) = a2[3];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id=%d, flags =%x, max_offchan_time=%d, rest_time=%d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_limit_off_chan_cmd_tlv");
  wmi_mtrace(0x501Fu, *(_DWORD *)(v13 + 4), 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x14u,
             0x501Fu,
             "send_limit_off_chan_cmd_tlv",
             0x17CCu,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send limit off chan cmd err=%d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "send_limit_off_chan_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return 16;
  }
  return result;
}
