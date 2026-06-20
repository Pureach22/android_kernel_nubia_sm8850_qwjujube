__int64 __fastcall send_pdev_get_rxpn_cmd_tlv(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _DWORD *v29; // x8
  __int64 result; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  if ( (is_service_enabled_tlv(a1, 0x149u, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    v20 = wmi_buf_alloc_fl(a1, 0x18u, "send_pdev_get_rxpn_cmd_tlv", 0x4268u);
    if ( v20 )
    {
      v29 = *(_DWORD **)(v20 + 224);
      *v29 = 69992468;
      v29[1] = *(_DWORD *)a2;
      v29[2] = *(_DWORD *)(a2 + 4);
      v29[3] = *(unsigned __int16 *)(a2 + 8);
      v29[5] = *(unsigned __int16 *)(a2 + 10);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v20,
                 0x18u,
                 0x6021u,
                 "send_pdev_get_rxpn_cmd_tlv",
                 0x4279u,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28);
      if ( !(_DWORD)result )
        return result;
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI command",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "send_pdev_get_rxpn_cmd_tlv");
      wmi_buf_free();
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: wmi_buf_alloc failed",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "send_pdev_get_rxpn_cmd_tlv");
    }
    return 16;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Rx PN Replay Check not supported by target",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "send_pdev_get_rxpn_cmd_tlv");
    return 11;
  }
}
