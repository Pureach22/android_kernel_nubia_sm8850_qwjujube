__int64 __fastcall wlan_hdd_set_mcc_low_latency_quota(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  __int64 v22; // x8
  _BOOL4 v23; // w19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v11 = *(_QWORD *)(a2 + 32);
  if ( (unsigned int)_wlan_hdd_validate_context(
                       a1,
                       (__int64)"wlan_hdd_set_mcc_low_latency_quota",
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       a11) )
    return 4294967274LL;
  v22 = *(_QWORD *)(a3 + 48);
  if ( !v22 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: No MCC LL mode attr id %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_hdd_set_mcc_low_latency_quota",
      6);
    return 4294967274LL;
  }
  v23 = *(unsigned __int8 *)(v22 + 4) != 0;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: set conc ll mode 0x%08x",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "wlan_hdd_set_mcc_low_latency_quota",
    *(unsigned __int8 *)(v22 + 4) != 0);
  result = wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(v11 + 55512) + 8LL), 226, v23, 2);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set conc low latency mode, %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_hdd_set_mcc_low_latency_quota",
      (unsigned int)result);
    return 0;
  }
  return result;
}
