__int64 __fastcall trace_raw_output_adreno_gpu_fault(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "ctx=%d ts=%d rb_id=%d status=%X RB=%X/%X IB1=%llX/%X IB2=%llX/%X\n",
      *(_DWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 20),
      *(_QWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 56));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
