__int64 __fastcall hdd_psoc_idle_timeout_callback(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w20
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7

  result = _wlan_hdd_validate_context(a1, (__int64)"hdd_psoc_idle_timeout_callback", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !(_DWORD)result )
  {
    if ( _cds_get_context(61, (__int64)"hdd_psoc_idle_timeout_callback", v11, v12, v13, v14, v15, v16, v17, v18) )
      qdf_rtpm_sync_resume();
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Psoc idle timeout elapsed; starting psoc shutdown",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "hdd_psoc_idle_timeout_callback");
    v27 = pld_idle_shutdown(*(_QWORD *)(a1 + 96), hdd_psoc_idle_shutdown);
    if ( v27 == -11 || *(_BYTE *)(a1 + 488) == 1 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: System suspend in progress. Restart idle shutdown timer",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_psoc_idle_timeout_callback");
      hdd_psoc_idle_timer_start(a1, v36, v37, v38, v39, v40, v41, v42, v43);
    }
    result = pld_get_bus_type(*(_QWORD *)(a1 + 96));
    if ( v27 != -16 && !(_DWORD)result )
      return cds_clear_driver_state(8, v44, v45, v46, v47, v48, v49, v50, v51);
  }
  return result;
}
