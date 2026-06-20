__int64 __fastcall cfg80211_unlink_bss(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x19
  _QWORD *v5; // x1
  _QWORD *v6; // x21
  _QWORD *v7; // t1
  _QWORD *v8; // x25

  if ( result )
  {
    if ( a2 )
    {
      v3 = result - 808;
      v4 = result;
      raw_spin_lock_bh(result - 808);
      if ( *(_QWORD *)(a2 - 112) != a2 - 112 )
      {
        v7 = *(_QWORD **)(a2 + 48);
        v6 = (_QWORD *)(a2 + 48);
        v5 = v7;
        if ( v7 != v6 )
        {
          do
          {
            v8 = (_QWORD *)*v5;
            if ( (_cfg80211_unlink_bss(v4 - 992) & 1) != 0 )
              ++*(_DWORD *)(v4 - 776);
            v5 = v8;
          }
          while ( v8 != v6 );
        }
        if ( (_cfg80211_unlink_bss(v4 - 992) & 1) != 0 )
          ++*(_DWORD *)(v4 - 776);
      }
      return raw_spin_unlock_bh(v3);
    }
    else
    {
      __break(0x800u);
    }
  }
  else
  {
    __break(0x800u);
    return _cfg80211_unlink_bss(0);
  }
  return result;
}
