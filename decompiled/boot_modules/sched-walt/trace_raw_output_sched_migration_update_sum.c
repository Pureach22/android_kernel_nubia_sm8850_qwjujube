__int64 __fastcall trace_raw_output_sched_migration_update_sum(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "pid %d task_cpu %d migrate_type %s src_cs %llu src_ps %llu dst_cs %lld dst_ps %lld src_nt_cs %llu src_nt_ps %llu d"
      "st_nt_cs %lld dst_nt_ps %lld\n",
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 8),
      migrate_type_names[*(unsigned int *)(v1 + 16)],
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48),
      *(_QWORD *)(v1 + 56),
      *(_QWORD *)(v1 + 64),
      *(_QWORD *)(v1 + 72),
      *(_QWORD *)(v1 + 80));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
