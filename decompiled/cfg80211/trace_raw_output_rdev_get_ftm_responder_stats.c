__int64 __fastcall trace_raw_output_rdev_get_ftm_responder_stats(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%sFtm responder stats: success %u, partial %u, failed %u, asap %u, non asap %u, total duration %llu, unknown trigg"
      "ers %u, rescheduled %u, out of window %u\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 76),
      *(_DWORD *)(v1 + 80),
      *(_DWORD *)(v1 + 84),
      *(_DWORD *)(v1 + 88),
      *(_QWORD *)(v1 + 96),
      *(_DWORD *)(v1 + 104),
      *(_DWORD *)(v1 + 108),
      *(_DWORD *)(v1 + 112));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
