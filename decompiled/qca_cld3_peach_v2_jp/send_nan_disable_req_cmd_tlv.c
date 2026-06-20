__int64 __fastcall send_nan_disable_req_cmd_tlv(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w23
  const char *v12; // x2
  unsigned int v13; // w25
  unsigned int v14; // w21
  __int64 result; // x0
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _DWORD *v26; // x26
  __int64 v27; // x20
  _DWORD *v28; // x24
  unsigned int v29; // w8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w19

  if ( !a2 )
  {
    v12 = "%s: nan req is not valid";
    goto LABEL_9;
  }
  v10 = *(unsigned __int16 *)(a2 + 12);
  if ( *(_WORD *)(a2 + 12) )
  {
    if ( ((v10 + 3) & 0xFFFC) < v10 )
    {
      v12 = "%s: Int overflow while rounding up data_len";
LABEL_9:
      qdf_trace_msg(0x31u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "send_nan_disable_req_cmd_tlv");
      return 16;
    }
    v13 = ((_WORD)v10 + 3) & 0xFFFC;
    if ( v13 >= 0x5FD )
    {
      v12 = "%s: nan_data_len exceeding wmi_max_msg_size";
      goto LABEL_9;
    }
    v14 = (unsigned __int16)(((v10 + 3) & 0xFFFC) + 28);
  }
  else
  {
    v13 = 0;
    v14 = 28;
  }
  v17 = wmi_buf_alloc_fl(a1, v14, "send_nan_disable_req_cmd_tlv", 0x10Cu);
  if ( !v17 )
    return 2;
  v26 = *(_DWORD **)(v17 + 224);
  v27 = v17;
  *v26 = 16842756;
  v26[1] = v10;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: nan data len value is %u",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "send_nan_disable_req_cmd_tlv",
    v10);
  v28 = v26 + 3;
  v26[2] = v13 | 0x110000;
  if ( v10 )
  {
    qdf_mem_copy(v26 + 3, (const void *)(a2 + 21), (unsigned int)v26[1]);
    v28 = (_DWORD *)((char *)v28 + v13);
  }
  *(_QWORD *)v28 = 0x2F100080012000CLL;
  v29 = v28[2] & 0xFFFFFFFE | *(unsigned __int8 *)(a2 + 8);
  v28[2] = v29;
  v28[2] = v29 & 0xFFFFFFFD | (2 * (*(_BYTE *)(a2 + 9) & 1));
  wmi_mtrace(0x28001u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v27,
             v14,
             0x28001u,
             "send_nan_disable_req_cmd_tlv",
             0x130u,
             v30,
             v31,
             v32,
             v33,
             v34,
             v35,
             v36,
             v37);
  if ( (_DWORD)result )
  {
    v46 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send set param command ret = %d",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "send_nan_disable_req_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return v46;
  }
  return result;
}
