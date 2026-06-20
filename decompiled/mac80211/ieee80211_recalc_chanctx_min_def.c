__int64 __fastcall ieee80211_recalc_chanctx_min_def(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v5; // w21
  _DWORD *v6; // x8

  result = ieee80211_recalc_chanctx_min_def();
  if ( (_DWORD)result )
  {
    v5 = result;
    ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))ieee80211_chan_bw_change)(a1, a2, 0, 1);
    v6 = *(_DWORD **)(*(_QWORD *)(a1 + 464) + 608LL);
    if ( v6 )
    {
      if ( (*(_BYTE *)(a2 + 84) & 1) == 0 )
      {
        __break(0x800u);
        v6 = *(_DWORD **)(*(_QWORD *)(a1 + 464) + 608LL);
      }
      if ( *(v6 - 1) != 1043050079 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v6)(a1, a2 + 152, v5);
    }
    return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))ieee80211_chan_bw_change)(a1, a2, 0, 0);
  }
  return result;
}
