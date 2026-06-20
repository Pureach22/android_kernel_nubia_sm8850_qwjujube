__int64 __fastcall ieee80211_uninit(__int64 a1)
{
  ieee80211_free_keys(a1 + 2688, 0);
  ieee80211_destroy_frag_cache(a1 + 4344);
  ieee80211_vif_set_links(a1 + 2688, 0, 0);
  return ((__int64 (__fastcall *)(__int64))ieee80211_link_stop)(a1 + 6304);
}
