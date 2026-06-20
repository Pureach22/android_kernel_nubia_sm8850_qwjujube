__int64 __fastcall wma_process_set_miracast(
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
  if ( !a2 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Invalid input to store miracast value",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wma_process_set_miracast");
  *(_DWORD *)(a1 + 2736) = *a2;
  return qdf_trace_msg(
           0x36u,
           8u,
           "%s: Miracast value is %d",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "wma_process_set_miracast");
}
