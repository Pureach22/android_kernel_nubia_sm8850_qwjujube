__int64 __fastcall ieee80211_ocb_setup_sdata(__int64 a1)
{
  __int64 result; // x0

  result = init_timer_key(a1 + 2264, ieee80211_ocb_housekeeping_timer, 0, 0, 0);
  *(_QWORD *)(a1 + 2320) = a1 + 2320;
  *(_QWORD *)(a1 + 2328) = a1 + 2320;
  *(_DWORD *)(a1 + 2312) = 0;
  return result;
}
