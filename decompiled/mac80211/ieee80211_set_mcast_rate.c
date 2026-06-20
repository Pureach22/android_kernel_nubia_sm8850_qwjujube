__int64 __fastcall ieee80211_set_mcast_rate(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 v3; // x8
  __int64 v4; // x9

  v4 = a3[1];
  v3 = a3[2];
  a2[948] = *a3;
  a2[950] = v3;
  a2[949] = v4;
  if ( (a2[540] & 1) != 0 )
    ieee80211_link_info_change_notify(a2 + 336, a2 + 788, 0x2000000);
  return 0;
}
