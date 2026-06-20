__int64 __fastcall wlan_acquire_peer_key_wakelock(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7
  unsigned int v32; // w9

  result = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v21 = result;
    _X8 = (unsigned int *)(result + 25040);
    __asm { PRFM            #0x11, [X8] }
    do
      v32 = __ldxr(_X8);
    while ( __stxr(v32 + 1, _X8) );
    if ( a2 )
    {
      v23 = *a2;
      v24 = a2[1];
      v25 = a2[2];
      v26 = a2[5];
    }
    else
    {
      v25 = 0;
      v23 = 0;
      v24 = 0;
      v26 = 0;
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x VDEV-%d Acquire set key wake lock cnt %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_acquire_peer_key_wakelock",
      v23,
      v24,
      v25,
      v26,
      *(unsigned __int8 *)(a1 + 104),
      *_X8);
    qdf_wake_lock_timeout_acquire(v21 + 24832, 1000);
    return qdf_runtime_pm_prevent_suspend((__int64 *)(v21 + 25032));
  }
  return result;
}
