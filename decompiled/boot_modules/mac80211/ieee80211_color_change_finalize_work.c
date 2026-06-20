void __fastcall ieee80211_color_change_finalize_work(__int64 a1, __int64 a2)
{
  if ( *(_BYTE *)(*(_QWORD *)(a2 + 712) + 840LL) == 1 && (*(_QWORD *)(*(_QWORD *)(a2 - 232) + 1632LL) & 1) != 0 )
    ieee80211_color_change_finalize(a2 - 232, a2);
}
