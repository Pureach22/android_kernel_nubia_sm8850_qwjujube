__int64 __fastcall trace_raw_output_sched_update_task_ravg_mini(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "wc %llu ws %llu delta %llu event %s cpu %d task %d (%s) ms %llu delta %llu demand %u rq_cs %llu rq_ps %llu cur_win"
      "dow %u prev_window %u grp_cs %lld grp_ps %lld global_ws %llu\n",
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 56),
      *(_QWORD *)(v1 + 64),
      task_event_names[*(unsigned int *)(v1 + 72)],
      *(_DWORD *)(v1 + 80),
      *(_DWORD *)(v1 + 24),
      (const char *)(v1 + 8),
      *(_QWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 76),
      *(_QWORD *)(v1 + 88),
      *(_QWORD *)(v1 + 96),
      *(_DWORD *)(v1 + 120),
      *(_DWORD *)(v1 + 124),
      *(_QWORD *)(v1 + 104),
      *(_QWORD *)(v1 + 112),
      *(_QWORD *)(v1 + 128));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
