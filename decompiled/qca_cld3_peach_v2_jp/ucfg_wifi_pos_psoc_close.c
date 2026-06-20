__int64 ucfg_wifi_pos_psoc_close()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w19

  if ( (unsigned int)wifi_pos_deregister_legacy_ops() )
    qdf_trace_msg(0x25u, 2u, "%s: Set legacy ops failed", v0, v1, v2, v3, v4, v5, v6, v7, "ucfg_wifi_pos_psoc_close");
  result = osif_wifi_pos_deregister_ops();
  if ( (_DWORD)result )
  {
    v17 = result;
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Register OSIF ops failed",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "ucfg_wifi_pos_psoc_close");
    return v17;
  }
  return result;
}
