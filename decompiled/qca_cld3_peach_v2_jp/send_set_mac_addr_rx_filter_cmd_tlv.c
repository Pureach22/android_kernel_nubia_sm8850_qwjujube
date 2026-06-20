__int64 __fastcall send_set_mac_addr_rx_filter_cmd_tlv(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _DWORD *v21; // x8
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 result; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // [xsp+0h] [xbp-20h]
  int v41; // [xsp+8h] [xbp-18h]
  int v42; // [xsp+10h] [xbp-10h]

  if ( a1 )
  {
    v12 = wmi_buf_alloc_fl(a1, 0x18u, "send_set_mac_addr_rx_filter_cmd_tlv", 0x59BFu);
    if ( v12 )
    {
      v21 = *(_DWORD **)(v12 + 224);
      v22 = v12;
      *v21 = 40435732;
      v21[1] = *a2;
      v21[5] = a2[3];
      v21[3] = a2[1];
      v21[4] = *((unsigned __int16 *)a2 + 4);
      v21[2] = *((unsigned __int8 *)a2 + 16);
      v41 = *((unsigned __int8 *)a2 + 6);
      v42 = *((unsigned __int8 *)a2 + 9);
      v40 = *((unsigned __int8 *)a2 + 5);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: set random mac rx vdev:%d freq:%d set:%d %02x:%02x:%02x:**:**:%02x",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "send_set_mac_addr_rx_filter_cmd_tlv",
        *a2,
        a2[3],
        *((unsigned __int8 *)a2 + 16),
        *((unsigned __int8 *)a2 + 4),
        v40,
        v41,
        v42);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v22,
                 0x18u,
                 0x501Bu,
                 "send_set_mac_addr_rx_filter_cmd_tlv",
                 0x59D9u,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30);
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send action frame random mac cmd",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "send_set_mac_addr_rx_filter_cmd_tlv");
        wmi_buf_free();
        return 16;
      }
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed allocate wmi buffer",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "send_set_mac_addr_rx_filter_cmd_tlv");
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: WMA context is invalid!",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "send_set_mac_addr_rx_filter_cmd_tlv");
    return 4;
  }
  return result;
}
