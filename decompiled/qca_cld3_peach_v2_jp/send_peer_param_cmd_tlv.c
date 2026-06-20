__int64 __fastcall send_peer_param_cmd_tlv(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w25
  int v12; // w23
  unsigned int v15; // w8
  unsigned int v16; // w8
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _DWORD *v27; // x24
  __int64 v28; // x19
  int v29; // w8
  int v30; // w8
  __int64 result; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  v11 = *a3;
  if ( *a3 )
  {
    v12 = a3[1];
    if ( v11 == 39 )
    {
      v15 = (unsigned __int8)(v12 - 1);
      if ( v15 < 9 )
        v16 = v15 + 1;
      else
        v16 = 0;
      v12 = (v16 | v12 & 0xFFFF00) ^ 0xFFFF00;
    }
    v18 = wmi_buf_alloc_fl(a1, 0x18u, "send_peer_param_cmd_tlv", 0x887u);
    if ( v18 )
    {
      v27 = *(_DWORD **)(v18 + 224);
      v28 = v18;
      *v27 = 6553620;
      v27[1] = a3[2];
      v27[2] = *(_DWORD *)a2;
      v29 = *(unsigned __int16 *)(a2 + 4);
      v27[5] = v12;
      v27[3] = v29;
      v27[4] = v11;
      if ( a2 )
        v30 = *(unsigned __int8 *)(a2 + 5);
      else
        v30 = 0;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: vdev_id %d peer_mac: %02x:%02x:%02x:**:**:%02x param_id: %u param_value: %x",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "send_peer_param_cmd_tlv",
        v30,
        *a3,
        v12);
      qdf_mtrace(49, 100, 0x304u, v27[1], 0);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v28,
                 0x18u,
                 0x6004u,
                 "send_peer_param_cmd_tlv",
                 0x89Du,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 v38,
                 v39);
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send set_param cmd",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "send_peer_param_cmd_tlv");
        wmi_buf_free();
        return 16;
      }
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: Unavailable param %d", a4, a5, a6, a7, a8, a9, a10, a11, "send_peer_param_cmd_tlv", 0);
    return 11;
  }
  return result;
}
