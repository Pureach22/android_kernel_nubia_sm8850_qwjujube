__int64 __fastcall ieee80211_hw_config(__int64 a1, __int64 a2)
{
  if ( (a2 & 0x62) != 0 )
  {
    __break(0x800u);
    if ( *(_DWORD *)(a1 + 1316) )
      return drv_config(a1, a2);
  }
  else if ( (_DWORD)a2 && *(_DWORD *)(a1 + 1316) )
  {
    return drv_config(a1, a2);
  }
  return 0;
}
