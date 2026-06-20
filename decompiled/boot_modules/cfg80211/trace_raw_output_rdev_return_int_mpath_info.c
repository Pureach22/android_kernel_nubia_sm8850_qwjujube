__int64 __fastcall trace_raw_output_rdev_return_int_mpath_info(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s, returned %d. mpath info - generation: %d, filled: %u, frame qlen: %u, sn: %u, metric: %u, exptime: %u, discove"
      "ry timeout: %u, discovery retries: %u, flags: 0x%x\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44),
      *(_DWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 52),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 68),
      *(unsigned __int8 *)(v1 + 72),
      *(unsigned __int8 *)(v1 + 73));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
