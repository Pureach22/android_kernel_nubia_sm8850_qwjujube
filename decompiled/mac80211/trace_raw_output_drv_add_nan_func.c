__int64 __fastcall trace_raw_output_drv_add_nan_func(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x5

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 56) )
      v4 = "/p2p";
    else
      v4 = (const char *)&unk_B8EF0;
    trace_event_printf(
      a1,
      "%s vif:%s(%d%s), type: %u, inst_id: %u\n",
      v1 + 8,
      v1 + *(unsigned __int16 *)(v1 + 60),
      *(unsigned int *)(v1 + 40),
      v4,
      *(unsigned __int8 *)(v1 + 64),
      *(unsigned __int8 *)(v1 + 65));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
