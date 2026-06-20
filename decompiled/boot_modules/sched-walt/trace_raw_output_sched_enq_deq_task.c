__int64 __fastcall trace_raw_output_sched_enq_deq_task(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x3

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 36) )
      v4 = "enqueue";
    else
      v4 = "dequeue";
    trace_event_printf(
      a1,
      "cpu=%d %s comm=%s pid=%d prio=%d nr_running=%u rt_nr_running=%u affine=%x demand=%u pred_demand_scaled=%u is_compa"
      "t_t=%d mvp=%d misfit=%d big_task_pid=%d\n",
      *(_DWORD *)(v1 + 32),
      v4,
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44),
      *(_DWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 52),
      *(_DWORD *)(v1 + 56),
      *(unsigned __int8 *)(v1 + 60),
      *(unsigned __int8 *)(v1 + 61),
      *(unsigned __int8 *)(v1 + 62),
      *(_DWORD *)(v1 + 64));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
