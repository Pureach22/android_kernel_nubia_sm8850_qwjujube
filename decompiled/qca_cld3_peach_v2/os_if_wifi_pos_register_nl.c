__int64 os_if_wifi_pos_register_nl()
{
  __int64 result; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  unsigned int v9; // w19

  result = register_cld_cmd_cb(25, os_if_wifi_pos_callback, 0);
  if ( (_DWORD)result )
  {
    v9 = result;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: register_cld_cmd_cb failed",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "os_if_wifi_pos_register_nl");
    return v9;
  }
  return result;
}
