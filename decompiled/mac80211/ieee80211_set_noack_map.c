__int64 __fastcall ieee80211_set_noack_map(__int64 a1, __int64 a2, __int16 a3)
{
  *(_WORD *)(a2 + 4576) = a3;
  ieee80211_check_fast_xmit_iface(a2 + 2688);
  return 0;
}
