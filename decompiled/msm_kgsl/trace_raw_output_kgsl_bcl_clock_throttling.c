__int64 __fastcall trace_raw_output_kgsl_bcl_clock_throttling(__int64 a1)
{
  _DWORD *v1; // x20
  __int64 result; // x0

  v1 = *(_DWORD **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(a1, "crc_25=%d crc_58=%d crc_75=%d\n", v1[2], v1[3], v1[4]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
