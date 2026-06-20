__int64 __fastcall send_get_rcpi_cmd_tlv(__int64 a1, __int64 a2)
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
  _DWORD *v13; // x22
  __int64 v14; // x19
  int v15; // w8
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

  v4 = wmi_buf_alloc_fl(a1, 0x14u, "send_get_rcpi_cmd_tlv", 0x4A09u);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 39321616;
  v13[1] = *(_DWORD *)a2;
  v13[2] = *(_DWORD *)(a2 + 8);
  v13[3] = *(unsigned __int16 *)(a2 + 12);
  v15 = *(_DWORD *)(a2 + 4);
  if ( (unsigned int)(v15 - 2) >= 3 )
    v15 = 1;
  v13[4] = v15;
  qdf_trace_msg(0x31u, 8u, "%s: RCPI REQ VDEV_ID:%d-->", v5, v6, v7, v8, v9, v10, v11, v12, "send_get_rcpi_cmd_tlv");
  qdf_mtrace(49, 100, 0xB0Bu, v13[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x14u,
             0x1600Bu,
             "send_get_rcpi_cmd_tlv",
             0x4A34u,
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
      "%s: Failed to send WMI_REQUEST_RCPI_CMDID",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "send_get_rcpi_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
