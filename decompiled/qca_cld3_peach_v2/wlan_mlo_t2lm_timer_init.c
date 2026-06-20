__int64 __fastcall wlan_mlo_t2lm_timer_init(__int64 a1)
{
  __int64 v1; // x21

  if ( !a1 )
    return 16;
  v1 = *(_QWORD *)(a1 + 1360);
  if ( !v1 )
    return 16;
  qdf_mutex_create(v1 + 2528);
  qdf_mutex_acquire(*(_QWORD *)(a1 + 1360) + 2528LL);
  *(_QWORD *)(v1 + 2432) = wlan_mlo_t2lm_timer_expiry_handler;
  *(_DWORD *)(v1 + 2416) = 1;
  *(_QWORD *)(v1 + 2424) = v1 + 2352;
  hrtimer_init(v1 + 2352, 1, 5);
  *(_QWORD *)(v1 + 2440) = 0;
  *(_QWORD *)(v1 + 2392) = _qdf_hrtimer_cb_1;
  *(_BYTE *)(v1 + 2448) = 0;
  qdf_mutex_release(*(_QWORD *)(a1 + 1360) + 2528LL);
  return 0;
}
