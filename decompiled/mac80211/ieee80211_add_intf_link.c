__int64 __fastcall ieee80211_add_intf_link(__int64 a1, __int64 a2)
{
  if ( (*(_BYTE *)(a2 + 65) & 1) != 0 )
    return 4294967201LL;
  else
    return ieee80211_vif_set_links(a2 - 16, *(unsigned __int16 *)(a2 + 1472), 0);
}
