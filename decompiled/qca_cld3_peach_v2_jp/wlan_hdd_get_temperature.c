__int64 __fastcall wlan_hdd_get_temperature(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x21
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  const char *v40; // x2
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w8

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_get_temperature");
  if ( !a1 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: adapter is NULL", v12, v13, v14, v15, v16, v17, v18, v19, "wlan_hdd_get_temperature");
    return 0xFFFFFFFFLL;
  }
  if ( (*(_BYTE *)(**(_QWORD **)(a1 + 24) + 21LL) & 4) == 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: WMI_SERVICE_THERM_THROT service from FW is disable",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_hdd_get_temperature");
    return 4294967274LL;
  }
  v21 = osif_request_alloc(wlan_hdd_get_temperature_params);
  if ( !v21 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Request allocation failure",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wlan_hdd_get_temperature");
    return 4294967284LL;
  }
  v30 = v21;
  v31 = osif_request_cookie(v21);
  if ( (unsigned int)sme_get_temperature(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 16LL), v31, hdd_get_temperature_cb) )
  {
    v40 = "%s: Unable to retrieve temperature";
  }
  else
  {
    if ( !(unsigned int)osif_request_wait_for_response(v30) )
    {
      v49 = *(_DWORD *)osif_request_priv(v30);
      if ( v49 )
        *(_DWORD *)(a1 + 42088) = v49;
      goto LABEL_12;
    }
    v40 = "%s: SME timed out while retrieving temperature";
  }
  qdf_trace_msg(0x33u, 2u, v40, v32, v33, v34, v35, v36, v37, v38, v39, "wlan_hdd_get_temperature");
LABEL_12:
  osif_request_put(v30);
  *a2 = *(_DWORD *)(a1 + 42088);
  qdf_trace_msg(0x33u, 8u, "%s: exit", v41, v42, v43, v44, v45, v46, v47, v48, "wlan_hdd_get_temperature");
  return 0;
}
