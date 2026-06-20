__int64 __fastcall rate_control_rate_init(_QWORD *a1)
{
  __int64 v1; // x20
  _QWORD *v2; // x23
  __int64 v4; // x22
  __int64 result; // x0
  __int64 v6; // x1
  unsigned int **v7; // x21
  __int64 v8; // x8
  __int64 v9; // x22
  __int64 v10; // x0
  __int64 v11; // x0
  _DWORD *v12; // x8
  __int64 v13; // x0
  unsigned __int64 v20; // x9

  v2 = (_QWORD *)a1[16];
  v1 = a1[17];
  v4 = *(_QWORD *)(a1[10] + 1616LL);
  result = ieee80211_sta_init_nss(a1 + 205);
  if ( v2 )
  {
    result = _rcu_read_lock(result, v6);
    v7 = *(unsigned int ***)(a1[10] + 5640LL);
    if ( v7 )
    {
      v8 = **v7;
      if ( (unsigned int)v8 >= 6 )
      {
        __break(0x5512u);
      }
      else
      {
        v9 = *(_QWORD *)(*(_QWORD *)(v4 + 72) + 8 * v8 + 328);
        if ( *(_DWORD *)(v9 + 16) == 4 )
        {
          v10 = ieee80211_s1g_sta_rate_init(a1);
          return _rcu_read_unlock(v10);
        }
        raw_spin_lock_bh(a1 + 18);
        v11 = v2[1];
        v12 = *(_DWORD **)(*v2 + 48LL);
        if ( *(v12 - 1) != -1475551757 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, unsigned int **, _QWORD *, __int64))v12)(v11, v9, v7, a1 + 336, v1);
        v13 = raw_spin_unlock_bh(a1 + 18);
        result = _rcu_read_unlock(v13);
      }
      _X8 = a1 + 27;
      __asm { PRFM            #0x11, [X8] }
      do
        v20 = __ldxr(_X8);
      while ( __stxr(v20 | 0x200000, _X8) );
    }
    else
    {
      __break(0x800u);
      return _rcu_read_unlock(result);
    }
  }
  return result;
}
