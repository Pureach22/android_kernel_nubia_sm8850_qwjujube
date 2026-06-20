__int64 __fastcall trace_raw_output_fastrpc_perf_counters(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "for: handle 0x%x, sc 0x%x, count %lld, flush %lld ns, map %lld ns, copy %lld ns, link %lld ns, getargs %lld ns, pu"
      "targs %lld ns, invargs %lld ns, invoke %lld ns, tid %lld\n",
      *(_DWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(_QWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48),
      *(_QWORD *)(v1 + 56),
      *(_QWORD *)(v1 + 64),
      *(_QWORD *)(v1 + 72),
      *(_QWORD *)(v1 + 80),
      *(_QWORD *)(v1 + 88));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
