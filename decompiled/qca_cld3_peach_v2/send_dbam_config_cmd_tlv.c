__int64 __fastcall send_dbam_config_cmd_tlv(__int64 a1, int *a2)
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
  __int64 v14; // x19
  int v15; // w3
  int v16; // w9
  int v17; // w9
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x20

  v4 = wmi_buf_alloc_fl(a1, 0xCu, "send_dbam_config_cmd_tlv", 0x274Au);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 72286216;
    v15 = *a2;
    v13[1] = *a2;
    v16 = a2[1];
    if ( v16 == 1 )
      v17 = 1;
    else
      v17 = 2 * (v16 == 2);
    v13[2] = v17;
    qdf_mtrace(49, 100, 0x1488u, v15, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v14,
               0xCu,
               0x29008u,
               "send_dbam_config_cmd_tlv",
               0x275Cu,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Sending DBAM CONFIG CMD failed",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "send_dbam_config_cmd_tlv");
      wmi_buf_free();
      return 16;
    }
  }
  else
  {
    v35 = jiffies;
    if ( send_dbam_config_cmd_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to allocate wmi buffer",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "send_dbam_config_cmd_tlv");
      send_dbam_config_cmd_tlv___last_ticks = v35;
    }
    return 2;
  }
  return result;
}
