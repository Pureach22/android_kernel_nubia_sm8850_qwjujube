__int64 __fastcall hdd_deregister_data_stall_detect_cb(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  _DWORD *v26; // x8
  unsigned int v27; // w0

  context = _cds_get_context(71, (__int64)"hdd_deregister_data_stall_detect_cb", a1, a2, a3, a4, a5, a6, a7, a8);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: De-Register data stall detect callback",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "hdd_deregister_data_stall_detect_cb");
  if ( context && *context && (v25 = *(_QWORD *)(*context + 64LL)) != 0 )
  {
    v26 = *(_DWORD **)(v25 + 80);
    if ( v26 )
    {
      if ( *(v26 - 1) != 1559598277 )
        __break(0x8228u);
      v27 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, _DWORD *(__fastcall *)(_DWORD *)))v26)(
              context,
              0,
              hdd_data_stall_process_cb);
    }
    else
    {
      v27 = 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "cdp_data_stall_cb_deregister");
    v27 = 4;
  }
  return qdf_status_to_os_return(v27);
}
