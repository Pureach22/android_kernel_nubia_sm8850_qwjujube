__int64 __fastcall ieee80211_get_station(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 bss; // x0

  bss = sta_info_get_bss(a2 + 2688, a3);
  if ( !bss )
    return 4294967294LL;
  sta_set_sinfo(bss, a4, 1);
  return 0;
}
