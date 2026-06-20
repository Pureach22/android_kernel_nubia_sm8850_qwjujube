__int64 __fastcall sub_310550(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int128 v4; // q24
  __int128 v5; // q25

  *(_OWORD *)(a3 + 736) = v5;
  *(_OWORD *)(a3 + 752) = v4;
  return wlan_hdd_trim_acs_channel_list(a1, a2, a3, a4);
}
