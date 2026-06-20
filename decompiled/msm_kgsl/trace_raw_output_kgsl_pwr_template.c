__int64 __fastcall trace_raw_output_kgsl_pwr_template(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x3

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 12) )
      v4 = "on";
    else
      v4 = "off";
    trace_event_printf(a1, "d_name=%s flag=%s\n", v1 + *(unsigned __int16 *)(v1 + 8), v4);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
