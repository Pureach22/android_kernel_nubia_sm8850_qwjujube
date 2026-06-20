__int64 __fastcall ieee80211_del_intf_link(__int64 a1, __int64 a2)
{
  return ieee80211_vif_set_links(a2 - 16, *(unsigned __int16 *)(a2 + 1472), 0);
}
