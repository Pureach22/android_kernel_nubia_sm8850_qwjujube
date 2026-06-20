__int64 __fastcall ieee80211_destroy_auth_data(__int64 a1, char a2)
{
  _QWORD *v2; // x20
  __int64 result; // x0

  v2 = *(_QWORD **)(a1 + 2480);
  if ( (a2 & 1) == 0 )
  {
    timer_delete_sync(a1 + 2264);
    sta_info_destroy_addr(a1, v2 + 6);
    *(_DWORD *)(a1 + 4152) = 0;
    *(_WORD *)(a1 + 4156) = 0;
    ieee80211_link_info_change_notify(a1, a1 + 3616, 128);
    *(_DWORD *)(a1 + 2500) = 0;
    ieee80211_link_release_channel((__int64 *)(a1 + 3616));
    ieee80211_vif_set_links((unsigned __int16 *)a1, 0, 0);
  }
  cfg80211_put_bss(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), *v2);
  result = kfree(v2);
  *(_QWORD *)(a1 + 2480) = 0;
  return result;
}
