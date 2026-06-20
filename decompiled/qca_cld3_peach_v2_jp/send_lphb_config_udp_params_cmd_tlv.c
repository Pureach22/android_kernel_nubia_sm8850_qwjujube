__int64 __fastcall send_lphb_config_udp_params_cmd_tlv(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x8
  __int64 v6; // x19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x2Cu, "send_lphb_config_udp_params_cmd_tlv", 0x58Fu);
  if ( v4 )
  {
    v5 = *(_DWORD **)(v4 + 224);
    v6 = v4;
    *v5 = 14876712;
    v5[1] = a2[1];
    v5[2] = a2[2];
    v5[3] = a2[3];
    v5[4] = a2[4];
    v5[5] = a2[5];
    v5[6] = a2[6];
    v5[7] = a2[7];
    v5[8] = a2[8];
    qdf_mem_copy(v5 + 9, a2 + 9, 8u);
    wmi_mtrace(0x23004u, 0xFFu, 0);
    v15 = wmi_unified_cmd_send_fl(
            a1,
            v6,
            0x2Cu,
            0x23004u,
            "send_lphb_config_udp_params_cmd_tlv",
            0x5AAu,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14);
    if ( v15 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: cmd_send WMI_HB_SET_UDP_PARAMS returned Error %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "send_lphb_config_udp_params_cmd_tlv",
        v15);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v15;
}
