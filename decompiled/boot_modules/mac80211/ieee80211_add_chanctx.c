__int64 __fastcall ieee80211_add_chanctx(__int64 a1, __int64 a2)
{
  unsigned int v4; // w0
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  unsigned int v6; // w21

  ieee80211_add_wbrf(a1, a2 + 152);
  v4 = ieee80211_idle_off(a1);
  if ( v4 )
    ieee80211_hw_config(a1, v4);
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 464) + 592LL);
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != -739578247 )
      __break(0x8228u);
    v6 = v5(a1, a2 + 152);
  }
  else
  {
    v6 = -95;
  }
  if ( v6 )
    ieee80211_recalc_idle(a1);
  else
    *(_BYTE *)(a2 + 84) = 1;
  return v6;
}
