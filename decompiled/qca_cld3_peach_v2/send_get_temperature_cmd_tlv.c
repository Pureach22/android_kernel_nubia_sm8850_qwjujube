__int64 __fastcall send_get_temperature_cmd_tlv(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  if ( a1 )
  {
    v10 = wmi_buf_alloc_fl(a1, 0xCu, "send_get_temperature_cmd_tlv", 0x1640u);
    if ( v10 )
    {
      v11 = v10;
      **(_DWORD **)(v10 + 224) = 22413320;
      qdf_mtrace(49, 100, 0x210u, 0xFFu, 0);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v11,
                 0xCu,
                 0x4010u,
                 "send_get_temperature_cmd_tlv",
                 0x164Eu,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19);
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send get temperature command",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "send_get_temperature_cmd_tlv");
        wmi_buf_free();
        return 16;
      }
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: WMI is closed, can not issue cmd",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "send_get_temperature_cmd_tlv");
    return 4;
  }
  return result;
}
