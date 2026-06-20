__int64 __fastcall send_probe_rsp_tmpl_send_cmd_tlv(
        __int64 a1,
        unsigned __int8 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w24
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w23
  unsigned int v23; // w26
  unsigned int v24; // w20
  __int64 result; // x0
  __int64 v26; // x0
  __int64 v27; // x27
  __int64 v28; // x21
  int v29; // w9
  int v30; // w3
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w19

  v11 = a2;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Send probe response template for vdev %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "send_probe_rsp_tmpl_send_cmd_tlv",
    a2);
  v22 = *(_DWORD *)(a3 + 8);
  v23 = v22 + 3;
  v24 = ((v22 + 3) & 0xFFFFFFFC) + 36;
  if ( v24 < 0x2DD )
  {
    v26 = wmi_buf_alloc_fl(a1, v24, "send_probe_rsp_tmpl_send_cmd_tlv", 0x1920u);
    if ( v26 )
    {
      v27 = *(_QWORD *)(v26 + 224);
      v28 = v26;
      *(_DWORD *)v27 = 6815756;
      *(_DWORD *)(v27 + 4) = v11;
      v29 = *(unsigned __int8 *)(a3 + 12);
      *(_QWORD *)(v27 + 16) = 6881288;
      *(_DWORD *)(v27 + 8) = v22;
      *(_DWORD *)(v27 + 12) = v29;
      *(_DWORD *)(v27 + 24) = 0;
      *(_DWORD *)(v27 + 28) = v23 & 0xFFFC | 0x110000;
      qdf_mem_copy((void *)(v27 + 32), *(const void **)a3, v22);
      v30 = *(_DWORD *)(v27 + 4);
      *(_DWORD *)(v27 + 32 + (v23 & 0xFFFFFFFC)) = 1179648;
      qdf_mtrace(49, 100, 0x387u, v30, 0);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v28,
                 v24,
                 0x7007u,
                 "send_probe_rsp_tmpl_send_cmd_tlv",
                 0x1940u,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 v38);
      if ( (_DWORD)result )
      {
        v47 = result;
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send PRB RSP tmpl: %d",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "send_probe_rsp_tmpl_send_cmd_tlv",
          (unsigned int)result);
        wmi_buf_free();
        return v47;
      }
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi_buf_len: %d > %d. Can't send wmi cmd",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "send_probe_rsp_tmpl_send_cmd_tlv",
      v24,
      732);
    return 4;
  }
  return result;
}
