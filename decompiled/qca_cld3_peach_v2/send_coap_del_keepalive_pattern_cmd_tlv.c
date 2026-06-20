__int64 __fastcall send_coap_del_keepalive_pattern_cmd_tlv(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v12; // w22
  __int64 v14; // x0
  __int64 v15; // x19
  _DWORD *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v12 = a2;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev id %d pattern id %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "send_coap_del_keepalive_pattern_cmd_tlv",
    a2,
    a3);
  v14 = wmi_buf_alloc_fl(a1, 0xCu, "send_coap_del_keepalive_pattern_cmd_tlv", 0x101u);
  if ( v14 )
  {
    v15 = v14;
    v16 = *(_DWORD **)(v14 + 224);
    *v16 = 71827464;
    v16[1] = v12;
    v16[2] = a3;
    wmi_mtrace(0x13015u, v12, a3);
    v25 = wmi_unified_cmd_send_fl(
            a1,
            v15,
            0xCu,
            0x13015u,
            "send_coap_del_keepalive_pattern_cmd_tlv",
            0x112u,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24);
    if ( v25 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send wow coap del keepalive pattern command %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "send_coap_del_keepalive_pattern_cmd_tlv",
        v25);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v25;
}
