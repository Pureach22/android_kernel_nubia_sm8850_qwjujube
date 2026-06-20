__int64 __fastcall trace_raw_output_sched_load_to_gov(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cpu=%d policy=%d ed_task_pid=%d aggr_grp_load=%llu freq_aggr=%d tt_load=%llu rq_ps=%llu grp_rq_ps=%llu nt_ps=%llu "
      "grp_nt_ps=%llu pl=%llu nbl=%llu load=%llu big_task_rotation=%d user_hint=%u reasons=0x%x util=%llu\n",
      *(_DWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48),
      *(_QWORD *)(v1 + 56),
      *(_QWORD *)(v1 + 64),
      *(_QWORD *)(v1 + 72),
      *(_QWORD *)(v1 + 80),
      *(_QWORD *)(v1 + 96),
      *(_QWORD *)(v1 + 88),
      *(unsigned __int8 *)(v1 + 104),
      *(_DWORD *)(v1 + 108),
      *(_DWORD *)(v1 + 112),
      *(_QWORD *)(v1 + 120));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
