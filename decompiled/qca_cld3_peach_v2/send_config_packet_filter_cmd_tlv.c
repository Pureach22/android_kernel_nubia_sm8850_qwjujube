__int64 __fastcall send_config_packet_filter_cmd_tlv(
        __int64 a1,
        unsigned __int8 a2,
        __int64 a3,
        unsigned __int8 a4,
        char a5)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x25
  __int64 v20; // x19
  unsigned int v21; // w8
  int v22; // w6
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  v10 = wmi_buf_alloc_fl(a1, 0x15Cu, "send_config_packet_filter_cmd_tlv", 0x63Eu);
  if ( !v10 )
    return 2;
  v19 = *(_QWORD *)(v10 + 224);
  v20 = v10;
  *(_DWORD *)v19 = 27459928;
  *(_DWORD *)(v19 + 4) = a2;
  *(_DWORD *)(v19 + 8) = a4;
  if ( (a5 & 1) != 0 )
  {
    *(_DWORD *)(v19 + 12) = 1;
    v21 = *(_DWORD *)(a3 + 8);
    if ( v21 >= 5 )
      v22 = 5;
    else
      v22 = *(_DWORD *)(a3 + 8);
    *(_DWORD *)(v19 + 20) = v22;
    *(_DWORD *)(v19 + 16) = *(_DWORD *)(a3 + 4);
    *(_DWORD *)(v19 + 24) = *(_DWORD *)(a3 + 12);
    if ( v21 )
    {
      *(_DWORD *)(v19 + 28) = *(_DWORD *)(a3 + 28);
      *(_DWORD *)(v19 + 32) = *(_DWORD *)(a3 + 32);
      *(_DWORD *)(v19 + 36) = *(unsigned __int16 *)(a3 + 36);
      *(_DWORD *)(v19 + 40) = *(unsigned __int8 *)(a3 + 38);
      *(_QWORD *)(v19 + 44) = *(_QWORD *)(a3 + 40);
      *(_QWORD *)(v19 + 52) = *(_QWORD *)(a3 + 48);
      if ( v21 != 1 )
      {
        *(_DWORD *)(v19 + 60) = *(_DWORD *)(a3 + 56);
        *(_DWORD *)(v19 + 64) = *(_DWORD *)(a3 + 60);
        *(_DWORD *)(v19 + 68) = *(unsigned __int16 *)(a3 + 64);
        *(_DWORD *)(v19 + 72) = *(unsigned __int8 *)(a3 + 66);
        *(_QWORD *)(v19 + 76) = *(_QWORD *)(a3 + 68);
        *(_QWORD *)(v19 + 84) = *(_QWORD *)(a3 + 76);
        if ( v21 >= 3 )
        {
          *(_DWORD *)(v19 + 92) = *(_DWORD *)(a3 + 84);
          *(_DWORD *)(v19 + 96) = *(_DWORD *)(a3 + 88);
          *(_DWORD *)(v19 + 100) = *(unsigned __int16 *)(a3 + 92);
          *(_DWORD *)(v19 + 104) = *(unsigned __int8 *)(a3 + 94);
          *(_QWORD *)(v19 + 108) = *(_QWORD *)(a3 + 96);
          *(_QWORD *)(v19 + 116) = *(_QWORD *)(a3 + 104);
          if ( v21 != 3 )
          {
            *(_DWORD *)(v19 + 124) = *(_DWORD *)(a3 + 112);
            *(_DWORD *)(v19 + 128) = *(_DWORD *)(a3 + 116);
            *(_DWORD *)(v19 + 132) = *(unsigned __int16 *)(a3 + 120);
            *(_DWORD *)(v19 + 136) = *(unsigned __int8 *)(a3 + 122);
            *(_QWORD *)(v19 + 140) = *(_QWORD *)(a3 + 124);
            *(_QWORD *)(v19 + 148) = *(_QWORD *)(a3 + 132);
            if ( v21 >= 5 )
            {
              *(_DWORD *)(v19 + 156) = *(_DWORD *)(a3 + 140);
              *(_DWORD *)(v19 + 160) = *(_DWORD *)(a3 + 144);
              *(_DWORD *)(v19 + 164) = *(unsigned __int16 *)(a3 + 148);
              *(_DWORD *)(v19 + 168) = *(unsigned __int8 *)(a3 + 150);
              *(_QWORD *)(v19 + 172) = *(_QWORD *)(a3 + 152);
              *(_QWORD *)(v19 + 180) = *(_QWORD *)(a3 + 160);
            }
          }
        }
      }
    }
  }
  else
  {
    *(_DWORD *)(v19 + 12) = 0;
  }
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: Packet filter action %d filter with id: %d, num_params=%d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "send_config_packet_filter_cmd_tlv");
  wmi_mtrace(0x33001u, *(_DWORD *)(v19 + 4), 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v20,
             0x15Cu,
             0x33001u,
             "send_config_packet_filter_cmd_tlv",
             0x66Eu,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send pkt_filter cmd %d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "send_config_packet_filter_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return 16;
  }
  return result;
}
