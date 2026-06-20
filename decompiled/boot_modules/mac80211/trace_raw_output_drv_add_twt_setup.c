__int64 __fastcall trace_raw_output_drv_add_twt_setup(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s sta:%pM token:%d control:0x%02x req_type:0x%04x twt:%llu duration:%d mantissa:%d channel:%d\n",
      (const char *)(v1 + 8),
      (const void *)(v1 + 40),
      *(unsigned __int8 *)(v1 + 46),
      *(unsigned __int8 *)(v1 + 47),
      *(unsigned __int16 *)(v1 + 48),
      *(_QWORD *)(v1 + 56),
      *(unsigned __int8 *)(v1 + 64),
      *(unsigned __int16 *)(v1 + 66),
      *(unsigned __int8 *)(v1 + 68));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
