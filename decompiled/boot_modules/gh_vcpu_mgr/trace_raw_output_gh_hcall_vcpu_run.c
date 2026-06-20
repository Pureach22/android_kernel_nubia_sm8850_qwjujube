__int64 __fastcall trace_raw_output_gh_hcall_vcpu_run(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "ret=%d vm=%u vcpu=%u yield_time=%llu vcpu_state=%llu vcpu_suspend_state=%llu\n",
      1,
      *(unsigned __int16 *)(v1 + 12),
      *(_DWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
