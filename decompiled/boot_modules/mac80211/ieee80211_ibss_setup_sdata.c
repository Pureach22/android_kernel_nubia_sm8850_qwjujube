__int64 __fastcall ieee80211_ibss_setup_sdata(__int64 a1)
{
  __int64 result; // x0

  result = init_timer_key(a1 + 2264, ieee80211_ibss_timer, 0, 0, 0);
  *(_QWORD *)(a1 + 2504) = a1 + 2504;
  *(_QWORD *)(a1 + 2512) = a1 + 2504;
  *(_DWORD *)(a1 + 2500) = 0;
  *(_QWORD *)(a1 + 2304) = a1 + 2304;
  *(_QWORD *)(a1 + 2312) = a1 + 2304;
  *(_QWORD *)(a1 + 2320) = ieee80211_csa_connection_drop_work;
  return result;
}
