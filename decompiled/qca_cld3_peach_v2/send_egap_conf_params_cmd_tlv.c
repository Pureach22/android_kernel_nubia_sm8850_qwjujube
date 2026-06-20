__int64 __fastcall send_egap_conf_params_cmd_tlv(__int64 a1, __int64 a2)
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
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x18u, "send_egap_conf_params_cmd_tlv", 0x1F12u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 28573716;
  v5[1] = *(unsigned __int8 *)(a2 + 1);
  v5[2] = *(_DWORD *)(a2 + 4);
  v5[3] = *(_DWORD *)(a2 + 8);
  v5[4] = *(_DWORD *)(a2 + 12);
  qdf_mtrace(49, 100, 0x703u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             0x18u,
             0xE003u,
             "send_egap_conf_params_cmd_tlv",
             0x1F22u,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send ap_ps_egap cmd",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "send_egap_conf_params_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
