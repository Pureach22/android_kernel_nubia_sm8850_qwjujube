__int64 __fastcall send_add_clear_mcbc_filter_cmd_tlv(__int64 a1, unsigned __int8 a2, __int64 a3, char a4)
{
  __int64 v8; // x0
  _DWORD *v9; // x22
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w4
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

  v8 = wmi_buf_alloc_fl(a1, 0x18u, "send_add_clear_mcbc_filter_cmd_tlv", 0x248u);
  if ( !v8 )
    return 2;
  v9 = *(_DWORD **)(v8 + 224);
  v10 = v8;
  qdf_mem_set(v9, 0x18u, 0);
  if ( (a4 & 1) != 0 )
    v19 = 2;
  else
    v19 = 1;
  *v9 = 13959188;
  v9[1] = a2;
  v9[5] = BYTE4(a3) | (BYTE5(a3) << 8);
  v9[3] = v19;
  v9[4] = (BYTE2(a3) << 16) | (BYTE1(a3) << 8) | a3 & 0xFF000000 | (unsigned __int8)a3;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Action:%d; vdev_id:%d; clearList:%d; MCBC MAC Addr: %02x:%02x:%02x:**:**:%02x",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "send_add_clear_mcbc_filter_cmd_tlv",
    BYTE1(a3),
    BYTE2(a3),
    BYTE5(a3));
  wmi_mtrace(0x1D009u, v9[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v10,
             0x18u,
             0x1D009u,
             "send_add_clear_mcbc_filter_cmd_tlv",
             0x260u,
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
      "%s: Failed to send set_param cmd %d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "send_add_clear_mcbc_filter_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return 16;
  }
  return result;
}
