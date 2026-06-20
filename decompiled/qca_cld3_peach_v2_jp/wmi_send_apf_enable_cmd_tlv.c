__int64 __fastcall wmi_send_apf_enable_cmd_tlv(__int64 a1, int a2, char a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _DWORD *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19

  v6 = wmi_buf_alloc_fl(a1, 0xCu, "wmi_send_apf_enable_cmd_tlv", 0x4Fu);
  if ( v6 )
  {
    v15 = *(_DWORD **)(v6 + 224);
    *v15 = 46923784;
    v15[1] = a2;
    v15[2] = a3 & 1;
    if ( (unsigned int)wmi_unified_cmd_send_fl(
                         a1,
                         v6,
                         0xCu,
                         0x36006u,
                         "wmi_send_apf_enable_cmd_tlv",
                         0x5Eu,
                         v7,
                         v8,
                         v9,
                         v10,
                         v11,
                         v12,
                         v13,
                         v14) )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to enable/disable APF interpreter",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wmi_send_apf_enable_cmd_tlv");
      wmi_buf_free();
      return 16;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v24 = 2;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi_buf_alloc failed",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wmi_send_apf_enable_cmd_tlv");
  }
  return v24;
}
