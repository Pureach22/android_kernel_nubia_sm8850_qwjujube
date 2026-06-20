__int64 __fastcall ttlm_req_timeout_cb(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  qdf_trace_msg(
    0x99u,
    2u,
    "%s: Failed to get the TTLM req response",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "ttlm_req_timeout_cb");
  qdf_mutex_acquire(a1 + 656);
  wlan_sm_dispatch(*(_QWORD *)(a1 + 720), 0xBu, 0, 0, v10, v11, v12, v13, v14, v15, v16, v17);
  return qdf_mutex_release(a1 + 656);
}
