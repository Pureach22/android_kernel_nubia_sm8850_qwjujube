__int64 __fastcall send_pdev_set_dual_mac_config_cmd_tlv(__int64 a1, unsigned int *a2)
{
  unsigned int v4; // w22
  __int64 v5; // x0
  _DWORD *v6; // x22
  __int64 v7; // x19
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v4 = 16;
  v5 = wmi_buf_alloc_fl(a1, 0x10u, "send_pdev_set_dual_mac_config_cmd_tlv", 0x89Cu);
  if ( v5 )
  {
    v6 = *(_DWORD **)(v5 + 224);
    v7 = v5;
    *v6 = 33816588;
    v8 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3664LL);
    if ( *((_DWORD *)v8 - 1) != -2112860426 )
      __break(0x8228u);
    v6[1] = v8(a1, 255);
    v6[2] = *a2;
    v6[3] = a2[1];
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: scan_config:%x fw_mode_config:%x",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "send_pdev_set_dual_mac_config_cmd_tlv",
      *a2);
    wmi_mtrace(0x401Fu, 0xFFu, 0);
    if ( (unsigned int)wmi_unified_cmd_send_fl(
                         a1,
                         v7,
                         0x10u,
                         0x401Fu,
                         "send_pdev_set_dual_mac_config_cmd_tlv",
                         0x8B1u,
                         v17,
                         v18,
                         v19,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24) )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_PDEV_SET_MAC_CONFIG_CMDID",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "send_pdev_set_dual_mac_config_cmd_tlv");
      wmi_buf_free();
      return 16;
    }
    else
    {
      return 0;
    }
  }
  return v4;
}
