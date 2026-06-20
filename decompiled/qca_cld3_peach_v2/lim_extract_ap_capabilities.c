__int64 __fastcall lim_extract_ap_capabilities(int a1, int a2, unsigned __int16 a3, void *a4)
{
  int v5; // w21
  int v6; // w19
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  v5 = a3;
  v6 = (int)a4;
  qdf_mem_set(a4, 0x1A08u, 0);
  if ( !v5 )
    return 0;
  result = sir_parse_beacon_ie(a1, v6);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: APCapExtract: Beacon parsing error!",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "lim_extract_ap_capabilities");
    return 16;
  }
  return result;
}
