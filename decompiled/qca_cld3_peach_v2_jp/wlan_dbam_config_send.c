__int64 wlan_dbam_config_send()
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

  result = tgt_send_dbam_config();
  if ( (_DWORD)result )
  {
    v9 = result;
    qdf_trace_msg(0x70u, 2u, "%s: failed to send dbam config", v1, v2, v3, v4, v5, v6, v7, v8, "wlan_dbam_config_send");
    return v9;
  }
  return result;
}
