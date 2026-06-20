__int64 __fastcall hdd_restart_tsf_sync_post_wlan_resume(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 result; // x0
  const char *v12; // x2
  unsigned int v13; // w1

  v9 = a1 + 36864;
  if ( *(_DWORD *)(a1 + 39384) )
  {
    result = qdf_mc_timer_get_current_state(a1 + 39176);
    if ( (_DWORD)result != 21 )
      return result;
    if ( !(unsigned int)qdf_mc_timer_stop_sync(a1 + 39176) )
    {
      *(_BYTE *)(v9 + 2481) = 1;
      if ( (unsigned int)qdf_mc_timer_start(a1 + 39176, 0xAu) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Host TSF sync timer restart failed",
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          "hdd_restart_tsf_sync_post_wlan_resume");
      v12 = "%s: Host TSF sync timer restarted post wlan resume";
      v13 = 8;
      return qdf_trace_msg(0x33u, v13, v12, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_restart_tsf_sync_post_wlan_resume");
    }
    v12 = "%s: Couldn't stop Host TSF sync running timer!!";
  }
  else
  {
    v12 = "%s: Host TSF sync is not initialized!!";
  }
  v13 = 2;
  return qdf_trace_msg(0x33u, v13, v12, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_restart_tsf_sync_post_wlan_resume");
}
