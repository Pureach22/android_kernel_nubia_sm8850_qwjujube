__int64 __fastcall ucfg_wifi_pos_psoc_open(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19

  if ( (unsigned int)osif_wifi_pos_register_ops() )
    qdf_trace_msg(0x25u, 2u, "%s: Register OSIF ops failed", v2, v3, v4, v5, v6, v7, v8, v9, "ucfg_wifi_pos_psoc_open");
  result = wifi_pos_register_legacy_ops(a1);
  if ( (_DWORD)result )
  {
    v19 = result;
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Set legacy ops failed",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "ucfg_wifi_pos_psoc_open");
    return v19;
  }
  return result;
}
