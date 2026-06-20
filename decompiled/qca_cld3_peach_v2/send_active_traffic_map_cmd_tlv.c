__int64 __fastcall send_active_traffic_map_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x8
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // [xsp+0h] [xbp-10h]

  v4 = wmi_buf_alloc_fl(a1, 0x14u, "send_active_traffic_map_cmd_tlv", 0x5A1Du);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 81133584;
  v13[1] = *(_DWORD *)a2;
  v13[2] = *(_DWORD *)(a2 + 4);
  v13[3] = *(unsigned __int16 *)(a2 + 8);
  v13[4] = *(_DWORD *)(a2 + 12);
  v32 = *(unsigned __int8 *)(a2 + 9);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: set traffic map 0x%x for peer %02x:%02x:%02x:**:**:%02x",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_active_traffic_map_cmd_tlv",
    v32);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x14u,
             0x1D025u,
             "send_active_traffic_map_cmd_tlv",
             0x5A31u,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send active traffic map, peer: %02x:%02x:%02x:**:**:%02x",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "send_active_traffic_map_cmd_tlv",
      *(unsigned __int8 *)(a2 + 4),
      *(unsigned __int8 *)(a2 + 5),
      *(unsigned __int8 *)(a2 + 6),
      *(unsigned __int8 *)(a2 + 9));
    wmi_buf_free();
    return 16;
  }
  return result;
}
