__int64 __fastcall send_set_gateway_params_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
  int v7; // w8
  _BOOL4 v8; // w8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x34u, "send_set_gateway_params_cmd_tlv", 0x3Au);
  if ( v4 )
  {
    v5 = *(_DWORD **)(v4 + 224);
    v6 = v4;
    *v5 = 26345520;
    v5[1] = *(_DWORD *)(a2 + 4);
    qdf_mem_copy(v5 + 5, (const void *)(a2 + 30), 4u);
    qdf_mem_copy(v5 + 6, (const void *)(a2 + 34), 0x10u);
    v5[3] = *(_DWORD *)(a2 + 24);
    v5[4] = *(unsigned __int16 *)(a2 + 28);
    v5[10] = *(_DWORD *)(a2 + 8);
    v7 = *(_DWORD *)(a2 + 12);
    v5[2] = 0;
    v5[11] = v7;
    v5[12] = 0;
    v8 = *(_DWORD *)(a2 + 16) != 0;
    v5[2] = v8;
    if ( *(_DWORD *)(a2 + 20) )
      v5[2] = v8 | 2;
    wmi_mtrace(0xB00Cu, v5[1], 0);
    v17 = wmi_unified_cmd_send_fl(
            a1,
            v6,
            0x34u,
            0xB00Cu,
            "send_set_gateway_params_cmd_tlv",
            0x57u,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16);
    if ( v17 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send gw config parameter to fw, ret: %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "send_set_gateway_params_cmd_tlv",
        v17);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v17;
}
