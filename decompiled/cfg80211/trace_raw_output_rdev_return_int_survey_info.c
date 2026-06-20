__int64 __fastcall trace_raw_output_rdev_return_int_survey_info(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s, returned: %d, band: %d, freq: %u.%03u, channel time: %llu, channel time busy: %llu, channel time extension bus"
      "y: %llu, channel time rx: %llu, channel time tx: %llu, scan time: %llu, filled: %u, noise: %d\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 52),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44),
      *(unsigned __int16 *)(v1 + 48),
      *(_QWORD *)(v1 + 56),
      *(_QWORD *)(v1 + 64),
      *(_QWORD *)(v1 + 72),
      *(_QWORD *)(v1 + 80),
      *(_QWORD *)(v1 + 88),
      *(_QWORD *)(v1 + 96),
      *(_DWORD *)(v1 + 104),
      *(char *)(v1 + 108));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
