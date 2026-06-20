__int64 __fastcall hdd_process_vendor_acs_response(__int64 result)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(result + 52832);
  if ( (*(_QWORD *)(v1 + 5968) & 8) != 0 )
  {
    result = qdf_mc_timer_get_current_state(v1 + 2440);
    if ( (_DWORD)result == 21 )
      return qdf_mc_timer_stop(v1 + 2440);
  }
  return result;
}
