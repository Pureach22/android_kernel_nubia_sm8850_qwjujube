__int64 __fastcall ieee80211_color_change_abort(__int64 a1)
{
  __int64 v2; // x8

  *(_BYTE *)(*(_QWORD *)(a1 + 944) + 840LL) = 0;
  v2 = *(_QWORD *)(a1 + 568);
  if ( v2 )
  {
    kfree(*(_QWORD *)(v2 + 72));
    kfree(*(_QWORD *)(*(_QWORD *)(a1 + 568) + 80LL));
    kfree(*(_QWORD *)(a1 + 568));
    *(_QWORD *)(a1 + 568) = 0;
  }
  return cfg80211_bss_color_notify(*(_QWORD *)(*(_QWORD *)a1 + 1608LL), 144, 0, 0, *(unsigned int *)(a1 + 8));
}
