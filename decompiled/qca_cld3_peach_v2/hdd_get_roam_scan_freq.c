__int64 __fastcall hdd_get_roam_scan_freq(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        _BYTE *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x20
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x19
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned int roam_scan_ch; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w20
  int v38; // w20
  __int64 result; // x0
  const char *v40; // x2
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x0
  bool v50; // zf
  unsigned __int64 v51; // x8

  if ( !a1 || !a2 || !a3 || !a4 )
  {
    v40 = "%s: failed to get roam scan channel, invalid input";
LABEL_17:
    qdf_trace_msg(0x33u, 2u, v40, a5, a6, a7, a8, a9, a10, a11, a12, "hdd_get_roam_scan_freq");
    return 4294967282LL;
  }
  v12 = *(_QWORD *)(a1 + 24);
  if ( *(_BYTE *)(v12 + 6800) != 1 )
  {
    result = sme_get_roam_scan_channel_list(a2, a3, a4, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL));
    if ( !(_DWORD)result )
      return result;
    v40 = "%s: failed to get roam scan channel list";
    goto LABEL_17;
  }
  v16 = osif_request_alloc(hdd_get_roam_chan_from_fw_params);
  if ( !v16 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Request allocation failure",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "hdd_get_roam_chan_from_fw");
LABEL_16:
    v40 = "%s: failed to get roam scan channel list from FW";
    goto LABEL_17;
  }
  v25 = v16;
  v26 = osif_request_priv(v16);
  *(_QWORD *)(v26 + 8) = v26 + 16;
  v27 = osif_request_cookie(v25);
  roam_scan_ch = sme_get_roam_scan_ch(*(_QWORD *)(v12 + 16), *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), v27);
  if ( roam_scan_ch )
  {
    v37 = roam_scan_ch;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Unable to retrieve roam channels",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "hdd_get_roam_chan_from_fw");
    v38 = qdf_status_to_os_return(v37);
    osif_request_put(v25);
    if ( !v38 )
      return 0;
    goto LABEL_16;
  }
  if ( (unsigned int)osif_request_wait_for_response(v25) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: SME timed out while retrieving raom channels",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "hdd_get_roam_chan_from_fw");
    osif_request_put(v25);
    goto LABEL_16;
  }
  v49 = osif_request_priv(v25);
  v50 = (unsigned __int8)*(_WORD *)(v49 + 2) == 0;
  *a4 = *(_WORD *)(v49 + 2);
  if ( !v50 )
  {
    v51 = 0;
    do
    {
      *(_DWORD *)(a3 + 4 * v51) = *(_DWORD *)(*(_QWORD *)(v49 + 8) + 4 * v51);
      ++v51;
    }
    while ( v51 < (unsigned __int8)*a4 );
  }
  osif_request_put(v25);
  return 0;
}
