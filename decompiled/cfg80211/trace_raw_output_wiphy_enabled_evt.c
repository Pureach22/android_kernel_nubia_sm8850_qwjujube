__int64 __fastcall trace_raw_output_wiphy_enabled_evt(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x3

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 40) )
      v4 = (const char *)&unk_B6F9E;
    else
      v4 = "not ";
    trace_event_printf(a1, "%s, %senabled \n", v1 + 8, v4);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
