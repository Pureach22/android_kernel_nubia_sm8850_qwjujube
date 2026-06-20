void __fastcall ieee80211_csa_finalize_work(__int64 a1, __int64 a2)
{
  if ( *(_BYTE *)(*(_QWORD *)(a2 + 800) + 830LL) == 1 && (*(_QWORD *)(*(_QWORD *)(a2 - 144) + 1632LL) & 1) != 0 )
    ieee80211_csa_finalize(a2 - 144, a2);
}
