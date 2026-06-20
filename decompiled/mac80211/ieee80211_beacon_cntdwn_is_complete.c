bool __fastcall ieee80211_beacon_cntdwn_is_complete(_DWORD *a1, __int64 a2)
{
  _BOOL4 v2; // w19
  int v3; // w20
  __int64 lock; // x0
  __int64 v6; // x8
  int v7; // w9
  __int64 v8; // x8
  __int64 v9; // x9
  int *v10; // x10
  unsigned __int64 v11; // x8
  __int64 *v12; // x8

  if ( (*((_QWORD *)a1 - 386) & 1) != 0 )
  {
    v3 = a2;
    if ( (unsigned int)a2 >= 0xF )
    {
      v2 = 0;
      __break(0x800u);
      return v2;
    }
    lock = _rcu_read_lock(a1, a2);
    v6 = *(_QWORD *)&a1[2 * v3 - 38];
    if ( !v6 )
      goto LABEL_18;
    v7 = *a1;
    if ( *a1 == 1 )
    {
      v12 = *((__int64 **)a1 - 285);
      if ( !v12 )
        goto LABEL_18;
    }
    else
    {
      if ( v7 != 7 )
      {
        if ( v7 != 3 )
          goto LABEL_19;
        v8 = *(_QWORD *)(v6 + 536);
        if ( !v8 )
          goto LABEL_19;
        v9 = *(_QWORD *)(v8 + 8);
        if ( !v9 )
          goto LABEL_19;
        v10 = (int *)(v8 + 20);
        v11 = *(unsigned __int16 *)(v8 + 32);
        if ( !v11 )
          goto LABEL_18;
LABEL_16:
        if ( *v10 >= v11 )
        {
          v2 = *(unsigned __int8 *)(v9 + v11) == 1;
LABEL_20:
          _rcu_read_unlock(lock);
          return v2;
        }
LABEL_19:
        v2 = 0;
        __break(0x800u);
        goto LABEL_20;
      }
      v12 = *((__int64 **)a1 - 257);
      if ( !v12 )
        goto LABEL_18;
    }
    v10 = (int *)(v12 + 2);
    v9 = *v12;
    v11 = *((unsigned __int16 *)v12 + 16);
    if ( v11 )
      goto LABEL_16;
LABEL_18:
    v2 = 0;
    goto LABEL_20;
  }
  return 0;
}
