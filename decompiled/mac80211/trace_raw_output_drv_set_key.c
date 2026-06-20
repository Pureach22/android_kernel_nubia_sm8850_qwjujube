__int64 __fastcall trace_raw_output_drv_set_key(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(a1, "%s vif:%s(%d%s) sta:%pM cmd: %d cipher:0x%x, flags=%#x, keyidx=%d, hw_key_idx=%d\n", v1 + 8);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
