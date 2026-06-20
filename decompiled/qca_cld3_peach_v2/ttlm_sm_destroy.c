__int64 __fastcall ttlm_sm_destroy(__int64 a1)
{
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 736) == 21 )
    qdf_mc_timer_stop(a1 + 736);
  qdf_mc_timer_destroy(a1 + 736);
  qdf_mutex_destroy(a1 + 656);
  wlan_sm_delete(*(_QWORD *)(a1 + 720));
  return 0;
}
