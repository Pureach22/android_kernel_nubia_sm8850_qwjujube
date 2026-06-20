__int64 __fastcall send_injector_config_cmd_tlv(__int64 a1, __int64 a2)
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
  unsigned int v14; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x28u, "send_injector_config_cmd_tlv", 0x3481u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    *v13 = 57344036;
    v13[1] = *(_DWORD *)a2;
    v13[2] = *(_DWORD *)(a2 + 4);
    v13[3] = *(_DWORD *)(a2 + 8);
    v13[4] = *(_DWORD *)(a2 + 12);
    v13[7] = *(_DWORD *)(a2 + 16);
    v13[5] = *(_DWORD *)(a2 + 24);
    v13[6] = *(unsigned __int16 *)(a2 + 28);
    v13[9] = *(_DWORD *)(a2 + 20);
    v14 = wmi_unified_cmd_send_fl(
            a1,
            v4,
            0x28u,
            0x4039u,
            "send_injector_config_cmd_tlv",
            0x3495u,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12);
    if ( v14 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: WMI_PDEV_FRAME_INJECT_CMDID send returned Error %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "send_injector_config_cmd_tlv",
        v14);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v14;
}
