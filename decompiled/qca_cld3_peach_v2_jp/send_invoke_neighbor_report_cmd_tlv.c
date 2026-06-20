__int64 __fastcall send_invoke_neighbor_report_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
  size_t v7; // x2
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x30u, "send_invoke_neighbor_report_cmd_tlv", 0x19A2u);
  if ( v4 )
  {
    v5 = *(_DWORD **)(v4 + 224);
    v6 = v4;
    *v5 = 46661676;
    v5[1] = *(_DWORD *)a2;
    v5[2] = *(_DWORD *)(a2 + 4);
    v7 = *(unsigned __int8 *)(a2 + 8);
    v5[3] = v7;
    qdf_mem_copy(v5 + 4, (const void *)(a2 + 9), v7);
    wmi_mtrace(0x3D002u, v5[1], 0);
    v16 = wmi_unified_cmd_send_fl(
            a1,
            v6,
            0x30u,
            0x3D002u,
            "send_invoke_neighbor_report_cmd_tlv",
            0x19B6u,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15);
    if ( v16 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send invoke neighbor report command %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "send_invoke_neighbor_report_cmd_tlv",
        v16);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v16;
}
