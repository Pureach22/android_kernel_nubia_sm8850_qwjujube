__int64 __fastcall wlan_hdd_get_snr(
        __int64 a1,
        _BYTE *a2,
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
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  const char *v41; // x2
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  v12 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_get_snr");
  if ( (unsigned int)_wlan_hdd_validate_context(
                       v12,
                       (__int64)"wlan_hdd_get_snr",
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20) )
    return 5;
  v22 = osif_request_alloc(wlan_hdd_get_snr_params);
  if ( !v22 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Request allocation failure",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wlan_hdd_get_snr");
    return 5;
  }
  v31 = v22;
  v32 = osif_request_cookie(v22);
  if ( (unsigned int)sme_get_snr(
                       *(_QWORD *)(v12 + 16),
                       hdd_get_snr_cb,
                       *(unsigned int *)(a1 + 308) | ((unsigned __int64)*(unsigned __int16 *)(a1 + 312) << 32),
                       v32) )
  {
    v41 = "%s: Unable to retrieve RSSI";
  }
  else
  {
    if ( !(unsigned int)osif_request_wait_for_response(v31) )
    {
      *(_BYTE *)(a1 + 2689) = *(_BYTE *)osif_request_priv(v31);
      goto LABEL_10;
    }
    v41 = "%s: SME timed out while retrieving SNR";
  }
  qdf_trace_msg(0x33u, 2u, v41, v33, v34, v35, v36, v37, v38, v39, v40, "wlan_hdd_get_snr");
LABEL_10:
  osif_request_put(v31);
  *a2 = *(_BYTE *)(a1 + 2689);
  qdf_trace_msg(0x33u, 8u, "%s: exit", v42, v43, v44, v45, v46, v47, v48, v49, "wlan_hdd_get_snr");
  return 0;
}
