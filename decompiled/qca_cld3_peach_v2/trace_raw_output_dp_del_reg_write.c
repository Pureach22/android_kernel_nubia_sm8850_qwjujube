__int64 __fastcall trace_raw_output_dp_del_reg_write(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "srng_id=%u enq_val=%u deq_val=%u sched_time=0x%llx enq_time=0x%llx deq_time=0x%llx\n",
      *(unsigned __int8 *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
