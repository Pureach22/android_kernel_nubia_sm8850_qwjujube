__int64 __fastcall sme_deregister_ssr_on_pagefault_cb(
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

  qdf_trace_msg(0x34u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "sme_deregister_ssr_on_pagefault_cb");
  if ( !(unsigned int)qdf_mutex_acquire(a1 + 12848) )
  {
    *(_QWORD *)(a1 + 14656) = 0;
    qdf_mutex_release(a1 + 12848);
  }
  return qdf_trace_msg(
           0x34u,
           8u,
           "%s: exit",
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           "sme_deregister_ssr_on_pagefault_cb");
}
