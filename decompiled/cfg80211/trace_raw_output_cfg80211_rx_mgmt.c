__int64 __fastcall trace_raw_output_cfg80211_rx_mgmt(__int64 a1)
{
  _DWORD *v1; // x20
  __int64 result; // x0

  v1 = *(_DWORD **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(a1, "wdev(%u), freq: %d.%03d, sig dbm: %d\n", v1[2], v1[3] / 1000, v1[3] % 1000, v1[4]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
