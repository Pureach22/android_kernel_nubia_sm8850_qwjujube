__int64 __fastcall ieee80211_color_collision_detection_work(__int64 a1)
{
  return cfg80211_bss_color_notify(
           *(_QWORD *)(*(_QWORD *)(a1 - 256) + 1608LL),
           141,
           0,
           *(_QWORD *)(a1 + 104),
           *(unsigned int *)(a1 - 248));
}
