void *__fastcall lim_update_last_processed_frame(
        _WORD *a1,
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
  __int64 v10; // x8
  int v12; // w20
  void *result; // x0

  if ( !a2 )
    return (void *)qdf_trace_msg(
                     0x35u,
                     2u,
                     "%s: Invalid RX frame",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "lim_update_last_processed_frame");
  v10 = *(_QWORD *)(a2 + 16);
  v12 = *(unsigned __int16 *)(v10 + 22) >> 4;
  result = qdf_mem_copy(a1, (const void *)(v10 + 10), 6u);
  a1[3] = v12;
  return result;
}
