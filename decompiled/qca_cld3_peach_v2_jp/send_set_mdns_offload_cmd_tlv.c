__int64 __fastcall send_set_mdns_offload_cmd_tlv(__int64 a1, __int64 a2)
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
  unsigned int v24; // w20
  __int64 v25; // x20

  v4 = wmi_buf_alloc_fl(a1, 0xCu, "send_set_mdns_offload_cmd_tlv", 0x164u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 23134216;
    v13[1] = *(_DWORD *)a2;
    v13[2] = *(unsigned __int8 *)(a2 + 4);
    wmi_mtrace(0x2F001u, *(_DWORD *)a2, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v14,
               0xCu,
               0x2F001u,
               "send_set_mdns_offload_cmd_tlv",
               0x175u,
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
      v24 = result;
      wmi_buf_free();
      return v24;
    }
  }
  else
  {
    v25 = jiffies;
    if ( send_set_mdns_offload_cmd_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to allocate wmi buffer",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "send_set_mdns_offload_cmd_tlv");
      send_set_mdns_offload_cmd_tlv___last_ticks = v25;
    }
    return 2;
  }
  return result;
}
