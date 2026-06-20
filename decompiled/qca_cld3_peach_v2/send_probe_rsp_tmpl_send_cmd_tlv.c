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
  unsigned int v14; // w23
  __int64 v15; // x25
  unsigned int v16; // w20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  __int64 v26; // x0
  __int64 v27; // x27
  __int64 v28; // x22
  int v29; // w9
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
  v14 = *(_DWORD *)(a3 + 8);
  v15 = (v14 + 3) & 0xFFFFFFFC;
  v16 = prb_resp_tmpl_ml_info_size(a3) + v15 + 32;
  if ( v16 < 0x2DD )
  {
    v26 = wmi_buf_alloc_fl(a1, v16, "send_probe_rsp_tmpl_send_cmd_tlv", 0x1920u);
    if ( v26 )
    {
      v27 = *(_QWORD *)(v26 + 224);
      v28 = v26;
      *(_DWORD *)v27 = 6815756;
      *(_DWORD *)(v27 + 4) = v11;
      v29 = *(unsigned __int8 *)(a3 + 12);
      *(_QWORD *)(v27 + 16) = 6881288;
      *(_DWORD *)(v27 + 8) = v14;
      *(_DWORD *)(v27 + 12) = v29;
      *(_DWORD *)(v27 + 24) = 0;
      *(_DWORD *)(v27 + 28) = ((_WORD)v14 + 3) & 0xFFFC | 0x110000;
      qdf_mem_copy((void *)(v27 + 32), *(const void **)a3, v14);
      prb_resp_tmpl_add_ml_info(v27 + 32 + v15, a3);
      qdf_mtrace(49, 100, 0x387u, *(_DWORD *)(v27 + 4), 0);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v28,
                 v16,
                 0x7007u,
                 "send_probe_rsp_tmpl_send_cmd_tlv",
                 0x1940u,
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
          "%s: Failed to send PRB RSP tmpl: %d",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "send_probe_rsp_tmpl_send_cmd_tlv",
          (unsigned int)result);
        wmi_buf_free();
        return v46;
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
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "send_probe_rsp_tmpl_send_cmd_tlv",
      v16,
      732);
    return 4;
  }
  return result;
}
