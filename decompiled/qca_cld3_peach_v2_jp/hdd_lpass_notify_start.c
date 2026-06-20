__int64 __fastcall hdd_lpass_notify_start(
        _BYTE *a1,
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
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  result = qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_lpass_notify_start");
  if ( !*(_DWORD *)(*(_QWORD *)a1 + 40LL) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Sending Start Lpass notification",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "hdd_lpass_notify_start");
    wlan_hdd_send_status_pkg(a1, 0, 1, 0, v19, v20, v21, v22, v23, v24, v25, v26);
    return qdf_trace_msg(0x33u, 8u, "%s: exit", v27, v28, v29, v30, v31, v32, v33, v34, "hdd_lpass_notify_start");
  }
  return result;
}
