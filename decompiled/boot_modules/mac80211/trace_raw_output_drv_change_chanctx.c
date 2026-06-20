__int64 __fastcall trace_raw_output_drv_change_chanctx(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s chandef(%d.%03d MHz,width:%d,center: %d.%03d/%d MHz) mindef(%d.%03d MHz,width:%d,center: %d.%03d/%d MHz) ap(%d."
      "%03d MHz,width:%d,center: %d.%03d/%d MHz) chains:%d/%d changed:%#x\n",
      v1 + 8);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
