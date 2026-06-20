__int64 __fastcall hdd_config_tx_rx_nss_per_band(
        __int64 a1,
        _QWORD *a2,
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
  __int64 v11; // x10
  __int64 v12; // x11
  __int64 v13; // x25
  __int64 v14; // x9
  unsigned int v16; // w21
  unsigned int v17; // w19
  unsigned int v19; // w22
  unsigned int v20; // w20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  bool v38; // w8
  bool v39; // zf
  const char *v40; // x2
  __int64 v41; // x4
  __int64 v42; // x5
  const char *v43; // x4
  bool v45; // w8
  bool v46; // zf

  v10 = a2[110];
  v11 = a2[111];
  v12 = a2[113];
  v13 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  v14 = a2[112];
  if ( !v10 && !v11 && !v14 && !v12 )
    return 0;
  if ( !v10 || !v11 )
  {
    if ( v10 )
      v43 = "RX_NSS_2G";
    else
      v43 = "TX_NSS_2G";
    goto LABEL_28;
  }
  if ( !v14 || !v12 )
  {
    if ( v14 )
      v43 = "RX_NSS_5G";
    else
      v43 = "TX_NSS_5G";
LABEL_28:
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
      "hdd_config_tx_rx_nss_per_band",
      v43);
    return 4294967274LL;
  }
  v16 = *(unsigned __int8 *)(v10 + 4);
  v17 = *(unsigned __int8 *)(v11 + 4);
  v19 = *(unsigned __int8 *)(v14 + 4);
  v20 = *(unsigned __int8 *)(v12 + 4);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: 2.4GHz Band: tx_nss %d rx_nss %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_config_tx_rx_nss_per_band",
    *(unsigned __int8 *)(v10 + 4),
    *(unsigned __int8 *)(v11 + 4));
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: 5/6GHz Band: tx_nss %d rx_nss %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "hdd_config_tx_rx_nss_per_band",
    v19,
    v20);
  v38 = v16 == 1 && v17 - 1 < 2;
  v39 = v17 == 2 && v16 == 2;
  if ( !v39 && !v38 )
  {
    v40 = "%s: Invalid Tx_Rx_Nss for 2.4GHz band (%d, %d)";
    v41 = v16;
    v42 = v17;
LABEL_43:
    qdf_trace_msg(0x33u, 2u, v40, v29, v30, v31, v32, v33, v34, v35, v36, "hdd_config_tx_rx_nss_per_band", v41, v42);
    return 4294967274LL;
  }
  v45 = v19 == 2 && v20 == 2;
  v46 = (unsigned __int8)(v20 - 1) < 2u && v19 == 1;
  if ( !v46 && !v45 )
  {
    v40 = "%s: Invalid Tx_Rx_Nss for 5/6GHz band (%d, %d)";
    v41 = v19;
    v42 = v20;
    goto LABEL_43;
  }
  if ( *(_DWORD *)(v13 + 1248) == 2 )
    return hdd_set_tx_rx_nss_per_band(a1, v16, v17, v19, v20);
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: No support for 2 spatial streams",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "hdd_config_tx_rx_nss_per_band");
  return 4294967274LL;
}
