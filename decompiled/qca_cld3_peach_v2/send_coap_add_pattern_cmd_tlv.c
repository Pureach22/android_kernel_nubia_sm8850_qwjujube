__int64 __fastcall send_coap_add_pattern_cmd_tlv(
        __int64 a1,
        const void **a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const void *v10; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w8
  unsigned int v30; // w9
  __int16 v31; // w25
  __int16 v32; // w28
  __int64 v33; // x26
  unsigned int v34; // w24
  __int64 v35; // x0
  _DWORD *v36; // x27
  __int64 v37; // x22
  unsigned int v38; // w9
  unsigned int v39; // w8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 result; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w19
  __int64 v58; // [xsp+0h] [xbp-10h]

  v10 = (char *)a2 + 12;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev id %d pattern id %d timeout %d src ip 0x%x:%d coap msg len %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "send_coap_add_pattern_cmd_tlv",
    *(unsigned int *)a2,
    *((unsigned int *)a2 + 1),
    *((unsigned int *)a2 + 2),
    *((unsigned int *)a2 + 3),
    *((unsigned __int16 *)a2 + 8),
    *((_DWORD *)a2 + 12));
  LODWORD(v58) = *((_DWORD *)a2 + 8);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: filter: dest ip 0x%x:%d is bc %d verify offset %d len %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "send_coap_add_pattern_cmd_tlv",
    *((unsigned int *)a2 + 5),
    *((unsigned __int16 *)a2 + 13),
    *((unsigned __int8 *)a2 + 24),
    *((unsigned int *)a2 + 7),
    v58);
  if ( a2[5] && (v29 = *((_DWORD *)a2 + 8)) != 0 && a2[7] && (v30 = *((_DWORD *)a2 + 12)) != 0 )
  {
    v31 = v30 + 3;
    v32 = v29 + 3;
    v33 = (v29 + 3) & 0xFFFFFFFC;
    v34 = ((v29 + 3) & 0xFFFFFFFC) + ((v30 + 3) & 0xFFFFFFFC);
    v35 = wmi_buf_alloc_fl(a1, v34 + 80, "send_coap_add_pattern_cmd_tlv", 0x3Eu);
    if ( v35 )
    {
      v36 = *(_DWORD **)(v35 + 224);
      v37 = v35;
      *v36 = 71630916;
      v36[1] = *(_DWORD *)a2;
      v36[2] = *((_DWORD *)a2 + 1);
      v38 = *((_DWORD *)a2 + 2);
      v39 = v36[3] & 0xFFFFFFFC;
      v36[3] = v39;
      v36[4] = v38;
      v36[3] = v39 | (2 * *((unsigned __int8 *)a2 + 24));
      qdf_mem_copy(v36 + 5, (char *)a2 + 20, 4u);
      v36[9] = *((unsigned __int16 *)a2 + 13);
      qdf_mem_copy(v36 + 10, v10, 4u);
      v36[14] = *((unsigned __int16 *)a2 + 8);
      v36[15] = *((_DWORD *)a2 + 7);
      v36[16] = *((_DWORD *)a2 + 8);
      v36[17] = *((_DWORD *)a2 + 12);
      v36[18] = v32 & 0xFFFC | 0x110000;
      qdf_mem_copy(v36 + 19, a2[5], *((unsigned int *)a2 + 8));
      *(_DWORD *)((char *)v36 + v33 + 76) = v31 & 0xFFFC | 0x110000;
      qdf_mem_copy((char *)v36 + v33 + 80, a2[7], *((unsigned int *)a2 + 12));
      wmi_mtrace(0x13012u, v36[1], v36[2]);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v37,
                 v34 + 80,
                 0x13012u,
                 "send_coap_add_pattern_cmd_tlv",
                 0x68u,
                 v40,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 v47);
      if ( (_DWORD)result )
      {
        v57 = result;
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send wow coap add pattern command %d",
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          "send_coap_add_pattern_cmd_tlv",
          (unsigned int)result);
        wmi_buf_free();
        return v57;
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
      "%s: invalid param",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "send_coap_add_pattern_cmd_tlv");
    return 4;
  }
  return result;
}
