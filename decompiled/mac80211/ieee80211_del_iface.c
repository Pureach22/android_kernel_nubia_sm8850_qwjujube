__int64 __fastcall ieee80211_del_iface(__int64 a1, __int64 a2)
{
  ieee80211_if_remove(a2 - 16);
  return 0;
}
