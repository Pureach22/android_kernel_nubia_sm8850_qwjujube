__int64 __fastcall wlan_mlo_t2lm_timer_deinit(__int64 a1)
{
  __int64 v1; // x20

  if ( !a1 )
    return 16;
  v1 = *(_QWORD *)(a1 + 1360);
  if ( !v1 )
    return 16;
  qdf_mutex_acquire(v1 + 2528);
  *(_BYTE *)(v1 + 2448) = 0;
  *(_DWORD *)(v1 + 2440) = 0;
  qdf_mutex_release(*(_QWORD *)(a1 + 1360) + 2528LL);
  hrtimer_cancel(v1 + 2352);
  qdf_mutex_destroy(*(_QWORD *)(a1 + 1360) + 2528LL);
  return 0;
}
