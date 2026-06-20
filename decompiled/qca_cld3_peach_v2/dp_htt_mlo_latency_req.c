__int64 __fastcall dp_htt_mlo_latency_req(
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
  unsigned int v11; // w19
  unsigned int v12; // w20
  unsigned int v13; // w21

  v11 = HIWORD(*a2);
  v12 = (*a2 >> 8) & 0x7F;
  v13 = (*a2 >> 15) & 1;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: vdev id: %d enable: %d interval: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_htt_mlo_latency_req",
    v12,
    v13,
    v11);
  return dp_mlo_latency_req(*(_QWORD *)(a1 + 8), v12, v11, v13);
}
