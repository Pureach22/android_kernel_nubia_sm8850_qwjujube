__int64 __fastcall scheduler_qdf_mc_timer_callback_t_wrapper(
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
  _QWORD *v9; // x19
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0

  v9 = *(_QWORD **)(a1 + 8);
  if ( !v9 )
  {
    qdf_trace_msg(
      0x4Au,
      2u,
      "%s: NULL mc_timer_wrapper from msg body",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "scheduler_qdf_mc_timer_callback_t_wrapper");
    return 16;
  }
  v10 = (void (__fastcall *)(_QWORD))*v9;
  if ( !*v9 )
  {
    qdf_trace_msg(
      0x4Au,
      2u,
      "%s: failed to get timer cb is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "scheduler_qdf_mc_timer_callback_t_wrapper");
    _qdf_mem_free((__int64)v9);
    return 16;
  }
  v11 = v9[1];
  if ( *((_DWORD *)v10 - 1) != 251140989 )
    __break(0x8228u);
  v10(v11);
  _qdf_mem_free((__int64)v9);
  return 0;
}
