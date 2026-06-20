__int64 __fastcall trace_raw_output_rdev_tdls_channel_switch(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s, netdev:%s(%d), %pM oper class %d, band: %d, control freq: %u.%03u, width: %d, cf1: %u.%03u, cf2: %u, punct: 0x%x\n",
      (const char *)(v1 + 8),
      (const char *)(v1 + 40),
      *(_DWORD *)(v1 + 56),
      (const void *)(v1 + 60),
      *(unsigned __int8 *)(v1 + 66),
      *(_DWORD *)(v1 + 68),
      *(_DWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 76),
      *(_DWORD *)(v1 + 80),
      *(_DWORD *)(v1 + 84),
      *(_DWORD *)(v1 + 88),
      *(_DWORD *)(v1 + 92),
      *(unsigned __int16 *)(v1 + 96));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
