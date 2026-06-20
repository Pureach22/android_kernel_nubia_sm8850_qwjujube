__int64 __fastcall trace_raw_output_dfc_set_powersave_mode(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x2

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_DWORD *)(v1 + 8) )
      v4 = "enable";
    else
      v4 = "disable";
    trace_event_printf(a1, "set powersave mode to %s\n", v4);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
