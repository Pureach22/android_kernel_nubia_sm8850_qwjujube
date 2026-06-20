__int64 __fastcall trace_raw_output_sde_hw_fence_status(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "crtc:%d %s hw-fence start timestamp:%u end timestamp:%u\n",
      *(_DWORD *)(v1 + 8),
      *(const char **)(v1 + 16),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 28));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
