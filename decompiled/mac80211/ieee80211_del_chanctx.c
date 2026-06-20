__int64 __fastcall ieee80211_del_chanctx(__int64 a1, __int64 a2, char a3)
{
  void (*v6)(void); // x8

  if ( (*(_BYTE *)(a2 + 84) & 1) == 0 )
  {
    __break(0x800u);
    if ( (a3 & 1) != 0 )
      return ieee80211_remove_wbrf(a1, a2 + 152);
    goto LABEL_7;
  }
  v6 = *(void (**)(void))(*(_QWORD *)(a1 + 464) + 600LL);
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != -1888841998 )
      __break(0x8228u);
    v6();
  }
  *(_BYTE *)(a2 + 84) = 0;
  if ( (a3 & 1) == 0 )
LABEL_7:
    ieee80211_recalc_idle(a1);
  return ieee80211_remove_wbrf(a1, a2 + 152);
}
