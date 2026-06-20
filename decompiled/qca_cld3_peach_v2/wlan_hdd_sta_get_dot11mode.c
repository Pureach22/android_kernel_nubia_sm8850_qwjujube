bool __fastcall wlan_hdd_sta_get_dot11mode(__int64 a1, __int64 a2, _DWORD *a3)
{
  if ( a1 )
    *a3 = hdd_convert_cfgdot11mode_to_80211mode(*(_DWORD *)(*(_QWORD *)(a2 + 55520) + 688LL));
  return a1 != 0;
}
