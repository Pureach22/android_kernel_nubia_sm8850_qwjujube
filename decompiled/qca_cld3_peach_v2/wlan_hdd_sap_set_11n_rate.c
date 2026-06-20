__int64 __fastcall wlan_hdd_sap_set_11n_rate(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x22
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v22; // x5
  int v23; // w8
  const char *v24; // x2
  unsigned int v25; // w8
  __int64 v26; // x7
  __int64 v27; // x6

  v12 = *(_QWORD *)(a1 + 52832);
  qdf_trace_msg(0x33u, 8u, "%s: SET_HT_RATE val %d", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_sap_set_11n_rate", a2);
  if ( a2 == 255 )
    return 4294967274LL;
  v22 = a2 & 7;
  if ( (a2 & 0x80) != 0 )
  {
    v25 = *(_DWORD *)(v12 + 320);
    if ( v25 <= 0x20 && ((1LL << v25) & 0x100000116LL) != 0 || v25 == 128 )
    {
      v24 = "%s: Not valid mode for HT";
      goto LABEL_13;
    }
    v26 = (a2 >> 3) & 0xF;
    v27 = 2;
  }
  else
  {
    v23 = *(_DWORD *)(v12 + 320);
    if ( (a2 & 0x10) != 0 )
    {
      if ( v23 == 2 )
      {
        v24 = "%s: Not valid for cck";
        goto LABEL_13;
      }
      v26 = 0;
      if ( (a2 & 7) != 3 )
        v22 = a2 & 3 | 4;
      v27 = 1;
    }
    else
    {
      if ( v23 == 128 || v23 == 4 )
      {
        v24 = "%s: Not valid for OFDM";
LABEL_13:
        qdf_trace_msg(0x33u, 2u, v24, v13, v14, v15, v16, v17, v18, v19, v20, "wlan_hdd_sap_set_11n_rate");
        return 4294967291LL;
      }
      v27 = 0;
      v26 = 0;
    }
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: SET_HT_RATE val %d rix %d preamble %x nss %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "wlan_hdd_sap_set_11n_rate",
    a2,
    v22,
    v27,
    v26);
  return wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), 27, a2, 1);
}
