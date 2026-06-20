__int64 __fastcall send_pdev_get_pn_cmd_tlv(__int64 a1, __int64 a2)
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
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x18u, "send_pdev_get_pn_cmd_tlv", 0x421Cu);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    *v13 = 50724884;
    v13[1] = *(_DWORD *)a2;
    v13[2] = *(_DWORD *)(a2 + 5);
    v13[3] = *(unsigned __int16 *)(a2 + 9);
    v13[4] = *(_DWORD *)(a2 + 12);
    v13[5] = *(unsigned __int8 *)(a2 + 4);
    result = wmi_unified_cmd_send_fl(
               a1,
               v4,
               0x18u,
               0x601Cu,
               "send_pdev_get_pn_cmd_tlv",
               0x422Eu,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI command",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "send_pdev_get_pn_cmd_tlv");
    wmi_buf_free();
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: wmi_buf_alloc failed", v5, v6, v7, v8, v9, v10, v11, v12, "send_pdev_get_pn_cmd_tlv");
  }
  return 16;
}
