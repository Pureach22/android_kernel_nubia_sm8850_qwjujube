__int64 __fastcall hdd_config_tx_rx_nss(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x9
  unsigned int v12; // w20
  unsigned int v13; // w19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  bool v24; // w8
  bool v25; // zf
  const char *v26; // x2
  unsigned int v27; // w1
  __int64 result; // x0
  const char *v29; // x4

  v10 = *(_QWORD *)(a2 + 616);
  v11 = *(_QWORD *)(a2 + 624);
  if ( *(_OWORD *)(a2 + 616) == 0 )
    return 0;
  if ( v10 && v11 )
  {
    v12 = *(unsigned __int8 *)(v10 + 4);
    v13 = *(unsigned __int8 *)(v11 + 4);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: tx_nss %d rx_nss %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_config_tx_rx_nss",
      *(unsigned __int8 *)(v10 + 4),
      *(unsigned __int8 *)(v11 + 4));
    v24 = v12 == 1 && v13 - 1 < 2;
    v25 = v13 == 2 && v12 == 2;
    if ( v25 || v24 )
    {
      result = hdd_update_nss(a1, v12, v13);
      if ( !(_DWORD)result )
        return result;
      v26 = "%s: Can't set tx_nss %d rx_nss %d";
      v27 = 8;
    }
    else
    {
      v26 = "%s: Setting tx_nss %d rx_nss %d not allowed";
      v27 = 2;
    }
    qdf_trace_msg(0x33u, v27, v26, v15, v16, v17, v18, v19, v20, v21, v22, "hdd_config_tx_rx_nss", v12, v13);
  }
  else
  {
    if ( v10 )
      v29 = (const char *)&unk_956283;
    else
      v29 = "TX";
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Missing attribute for %s",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_config_tx_rx_nss",
      v29);
  }
  return 4294967274LL;
}
