__int64 __fastcall hdd_wmm_adapter_clear(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_wmm_adapter_clear");
  a1[235] = 0;
  a1[270] = 0;
  a1[305] = 0;
  a1[340] = 0;
  return 0;
}
