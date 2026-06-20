__int64 __fastcall trace_raw_output_msm_vidc_driver(__int64 a1)
{
  unsigned __int16 *v1; // x20
  __int64 result; // x0

  v1 = *(unsigned __int16 **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s: %s: state changed to %s from %s\n\n",
      (const char *)v1 + v1[4],
      (const char *)v1 + v1[6],
      (const char *)v1 + v1[8],
      (const char *)v1 + v1[10]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
