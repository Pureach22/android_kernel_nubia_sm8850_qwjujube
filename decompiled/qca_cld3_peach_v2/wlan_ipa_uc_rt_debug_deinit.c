__int64 __fastcall wlan_ipa_uc_rt_debug_deinit(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  qdf_mutex_destroy(a1 + 7160);
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 1464) + 1LL) & 1) == 0 )
    return qdf_trace_msg(
             0x61u,
             8u,
             "%s: IPA RT debug is not enabled",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "wlan_ipa_uc_rt_debug_deinit");
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 6992) != 19 )
    qdf_mc_timer_stop(a1 + 6992);
  qdf_mc_timer_destroy(a1 + 6992);
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 4168) != 19 )
    qdf_mc_timer_stop(a1 + 4168);
  return qdf_mc_timer_destroy(a1 + 4168);
}
