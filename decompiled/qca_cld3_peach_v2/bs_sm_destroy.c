__int64 __fastcall bs_sm_destroy(__int64 a1, __int64 a2)
{
  qdf_event_destroy(a1 + 792, a2);
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 456) == 21 )
    qdf_mc_timer_stop(a1 + 456);
  qdf_mc_timer_destroy(a1 + 456);
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 624) == 21 )
    qdf_mc_timer_stop(a1 + 624);
  qdf_mc_timer_destroy(a1 + 624);
  qdf_mutex_destroy(a1 + 16);
  wlan_sm_delete(*(_QWORD *)(a1 + 80));
  return 0;
}
