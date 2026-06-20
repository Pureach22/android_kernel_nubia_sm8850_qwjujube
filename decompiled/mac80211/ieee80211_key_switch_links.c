__int64 __fastcall ieee80211_key_switch_links(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  char *v3; // x22
  char *v4; // x21
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 result; // x0

  v3 = *(char **)(a1 + 1512);
  v4 = (char *)(a1 + 1512);
  if ( v3 != (char *)(a1 + 1512) )
  {
    do
    {
      v7 = v3[530];
      if ( (v7 & 0x8000000000000000LL) == 0 && ((a2 >> v7) & 1) != 0 )
      {
        if ( *((_QWORD *)v3 - 1) )
          __break(0x800u);
        ieee80211_key_disable_hw_accel(v3 - 24);
      }
      v3 = *(char **)v3;
    }
    while ( v3 != v4 );
    v3 = *(char **)v4;
  }
  while ( v3 != v4 )
  {
    v8 = v3[530];
    if ( (v8 & 0x8000000000000000LL) == 0 && ((a3 >> v8) & 1) != 0 )
    {
      if ( *((_QWORD *)v3 - 1) )
        __break(0x800u);
      result = ieee80211_key_enable_hw_accel(v3 - 24, a2);
      if ( (_DWORD)result )
        return result;
    }
    v3 = *(char **)v3;
  }
  return 0;
}
