__int64 __fastcall hdd_update_dynamic_mac(
        __int64 a1,
        const void *a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  void *v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_update_dynamic_mac");
  v14 = (void *)(a1 + 3696);
  if ( !(unsigned int)qdf_mem_cmp(a2, (const void *)(a1 + 3696), 6u)
    || (v14 = (void *)(a1 + 3704), !(unsigned int)qdf_mem_cmp(a2, (const void *)(a1 + 3704), 6u))
    || (v14 = (void *)(a1 + 3712), !(unsigned int)qdf_mem_cmp(a2, (const void *)(a1 + 3712), 6u))
    || (v14 = (void *)(a1 + 3720), !(unsigned int)qdf_mem_cmp(a2, (const void *)(a1 + 3720), 6u))
    || (v14 = (void *)(a1 + 3728), !(unsigned int)qdf_mem_cmp(a2, (const void *)(a1 + 3728), 6u))
    || (v14 = (void *)(a1 + 3736), !(unsigned int)qdf_mem_cmp(a2, (const void *)(a1 + 3736), 6u))
    || (v14 = (void *)(a1 + 3744), !(unsigned int)qdf_mem_cmp(a2, (const void *)(a1 + 3744), 6u)) )
  {
    qdf_mem_copy(v14, a3, 6u);
  }
  return qdf_trace_msg(0x33u, 8u, "%s: exit", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_update_dynamic_mac");
}
