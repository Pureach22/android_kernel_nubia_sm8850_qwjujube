__int64 __fastcall trace_raw_output_cache_alloc_bw_ratio(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cpu_m_bw=%llu, cpu_l_bw=%llu, cpu_bw=%llu, gpu_bw=%llu, bw_ratio=%llu\n",
      v1[1],
      v1[2],
      v1[3],
      v1[4],
      v1[5]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
