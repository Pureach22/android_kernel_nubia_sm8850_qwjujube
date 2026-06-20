__int64 __fastcall wma_send_coex_config_cmd(__int64 *a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( !(unsigned int)_wma_validate_handle(a1, "wma_send_coex_config_cmd") )
  {
    v12 = *a1;
    if ( !(unsigned int)_wmi_validate_handle(v12, (__int64)"wma_send_coex_config_cmd", v4, v5, v6, v7, v8, v9, v10, v11) )
    {
      if ( a2 )
        return wmi_unified_send_coex_config_cmd(v12);
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: coex cfg params ptr NULL",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wma_send_coex_config_cmd");
    }
  }
  return 4;
}
