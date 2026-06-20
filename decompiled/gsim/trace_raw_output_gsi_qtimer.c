__int64 __fastcall trace_raw_output_gsi_qtimer(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x3

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 16) )
      v4 = "true";
    else
      v4 = "false";
    trace_event_printf(
      a1,
      "qtimer=%llu is_ll=%s, evt=%u, ch=0x%x, msk=0x%x\n",
      *(_QWORD *)(v1 + 8),
      v4,
      *(unsigned __int8 *)(v1 + 17),
      *(unsigned int *)(v1 + 20),
      *(unsigned int *)(v1 + 24));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
