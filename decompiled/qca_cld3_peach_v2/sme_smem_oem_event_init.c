__int64 __fastcall sme_smem_oem_event_init(
        __int64 a1,
        __int64 a2,
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

  qdf_trace_msg(0x34u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "sme_smem_oem_event_init");
  if ( !(unsigned int)qdf_mutex_acquire(a1 + 12848) )
  {
    *(_QWORD *)(a1 + 14648) = a2;
    qdf_mutex_release(a1 + 12848);
  }
  return qdf_trace_msg(0x34u, 8u, "%s: exit", v12, v13, v14, v15, v16, v17, v18, v19, "sme_smem_oem_event_init");
}
