__int64 __fastcall send_nan_req_cmd_tlv(
        __int64 a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w8
  __int64 v11; // x23
  const char *v12; // x2
  __int64 result; // x0
  __int64 v16; // x0
  _DWORD *v17; // x8
  unsigned __int16 *v18; // x24
  __int64 v19; // x19
  const void *v20; // x1
  size_t v21; // x2
  _DWORD *v22; // x21
  char *v23; // x8
  int v24; // w9
  unsigned int v25; // w9
  unsigned int v26; // w9
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w20

  if ( !a2 )
  {
    v12 = "%s: nan req is not valid";
    goto LABEL_7;
  }
  v10 = *a2;
  v11 = (unsigned __int16)(v10 + 3) & 0xFFFC;
  if ( (((_WORD)v10 + 3) & 0xFFFCu) < v10 )
  {
    v12 = "%s: integer overflow while rounding up data_len";
LABEL_7:
    qdf_trace_msg(0x31u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "send_nan_req_cmd_tlv");
    return 16;
  }
  if ( (unsigned int)v11 >= 0x5FD )
  {
    v12 = "%s: wmi_max_msg_size overflow for given datalen";
    goto LABEL_7;
  }
  v16 = wmi_buf_alloc_fl(a1, (unsigned __int16)(v11 + 28), "send_nan_req_cmd_tlv", 0x168u);
  if ( !v16 )
    return 2;
  v17 = *(_DWORD **)(v16 + 224);
  v18 = a2;
  v19 = v16;
  v20 = (char *)a2 + 9;
  *v17 = 16842756;
  v21 = *a2;
  v22 = v17 + 3;
  v17[1] = v21;
  v17[2] = v11 | 0x110000;
  qdf_mem_copy(v17 + 3, v20, v21);
  v23 = (char *)v22 + v11;
  v24 = *(_DWORD *)((char *)v22 + v11 + 12);
  *(_QWORD *)v23 = 0x2F100080012000CLL;
  *((_DWORD *)v23 + 3) = v24 & 0xFFFFFFFE;
  v25 = v24 & 0xFFFFFFFC | (*((_DWORD *)v18 + 1) >> 8) & 1;
  *((_DWORD *)v23 + 3) = v25;
  v26 = v25 & 0xFFFFFFF9 | (*((_DWORD *)v18 + 1) >> 8) & 2;
  *((_DWORD *)v23 + 3) = v26;
  *((_DWORD *)v23 + 3) = v26 | (4 * *((unsigned __int8 *)v18 + 8));
  wmi_mtrace(0x28001u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v19,
             (unsigned __int16)(v11 + 28),
             0x28001u,
             "send_nan_req_cmd_tlv",
             0x188u,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34);
  if ( (_DWORD)result )
  {
    v43 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send NAN req command ret = %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "send_nan_req_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return v43;
  }
  return result;
}
