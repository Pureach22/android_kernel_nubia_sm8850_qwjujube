__int64 __fastcall trace_raw_output_sde_evtlog(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%d|%s:%d|0x%x|0x%x|0x%x|0x%x|0x%x|0x%x|0x%x|0x%x|0x%x|0x%x|0x%x|0x%x|0x%x|0x%x|0x%x\n",
      *(_DWORD *)(v1 + 8),
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 12)),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 80),
      *(_DWORD *)(v1 + 84),
      *(_DWORD *)(v1 + 88),
      *(_DWORD *)(v1 + 92),
      *(_DWORD *)(v1 + 96),
      *(_DWORD *)(v1 + 100),
      *(_DWORD *)(v1 + 104),
      *(_DWORD *)(v1 + 108),
      *(_DWORD *)(v1 + 112),
      *(_DWORD *)(v1 + 116),
      *(_DWORD *)(v1 + 120),
      *(_DWORD *)(v1 + 124),
      *(_DWORD *)(v1 + 128),
      *(_DWORD *)(v1 + 132),
      *(_DWORD *)(v1 + 136));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
