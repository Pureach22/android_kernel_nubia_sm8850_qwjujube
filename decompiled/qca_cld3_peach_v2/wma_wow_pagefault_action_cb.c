__int64 __fastcall wma_wow_pagefault_action_cb(
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
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 (__fastcall *v19)(__int64, __int64); // x8

  context = _cds_get_context(53, (__int64)"wma_wow_pagefault_action_cb", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: NULL mac ptr",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "wma_wow_pagefault_action_cb");
  v19 = (__int64 (__fastcall *)(__int64, __int64))context[1832];
  if ( *((_DWORD *)v19 - 1) != -297509796 )
    __break(0x8228u);
  return v19(a1, 390);
}
