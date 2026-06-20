__int64 __fastcall send_coap_add_keepalive_pattern_cmd_tlv(
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
  const void *v10; // x22
  const void *v11; // x23
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w8
  __int16 v23; // w25
  unsigned int v24; // w24
  __int64 v25; // x0
  _DWORD *v26; // x26
  __int64 v27; // x21
  unsigned int v28; // w8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 result; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w19

  v10 = a2 + 1;
  v11 = a2 + 2;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev id %d pattern id %d ip src 0x%x:%d dest 0x%x:%d bc %d timeout %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "send_coap_add_keepalive_pattern_cmd_tlv",
    *(unsigned int *)a2,
    *((unsigned int *)a2 + 1),
    *((unsigned int *)a2 + 2),
    *((unsigned __int16 *)a2 + 6),
    *((_DWORD *)a2 + 4),
    *((unsigned __int16 *)a2 + 11),
    *((unsigned __int8 *)a2 + 20),
    *((_DWORD *)a2 + 6));
  if ( a2[4] && (v22 = *((_DWORD *)a2 + 7)) != 0 )
  {
    v23 = v22 + 3;
    v24 = (v22 + 3) & 0xFFFFFFFC;
    v25 = wmi_buf_alloc_fl(a1, v24 + 68, "send_coap_add_keepalive_pattern_cmd_tlv", 0xBEu);
    if ( v25 )
    {
      v26 = *(_DWORD **)(v25 + 224);
      v27 = v25;
      *v26 = 71761980;
      v26[1] = *(_DWORD *)a2;
      v28 = v26[3] & 0xFFFFFFFC;
      v26[2] = *((_DWORD *)a2 + 1);
      v26[3] = v28;
      v26[3] = v28 | (2 * *((unsigned __int8 *)a2 + 20));
      qdf_mem_copy(v26 + 9, v11, 4u);
      v26[13] = *((unsigned __int16 *)a2 + 11);
      qdf_mem_copy(v26 + 4, v10, 4u);
      v26[8] = *((unsigned __int16 *)a2 + 6);
      v26[14] = *((_DWORD *)a2 + 6);
      v26[15] = *((_DWORD *)a2 + 7);
      v26[16] = v23 & 0xFFFC | 0x110000;
      qdf_mem_copy(v26 + 17, a2[4], *((unsigned int *)a2 + 7));
      wmi_mtrace(0x13014u, v26[1], v26[2]);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v27,
                 v24 + 68,
                 0x13014u,
                 "send_coap_add_keepalive_pattern_cmd_tlv",
                 0xE3u,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36);
      if ( (_DWORD)result )
      {
        v46 = result;
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send wow coap add keepalive pattern command %d",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "send_coap_add_keepalive_pattern_cmd_tlv",
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
      "%s: invalid CoAP message",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "send_coap_add_keepalive_pattern_cmd_tlv");
    return 4;
  }
  return result;
}
