__int64 __fastcall ieee80211_beacon_update_cntdwn(_DWORD *a1, __int64 a2)
{
  int v2; // w20
  __int64 lock; // x0
  __int64 v5; // x8
  __int64 v6; // x8
  int v7; // w9
  unsigned int v8; // w19

  if ( (unsigned int)a2 >= 0xF )
  {
    v8 = 0;
    __break(0x800u);
    return v8;
  }
  v2 = a2;
  lock = _rcu_read_lock(a1, a2);
  v5 = *(_QWORD *)&a1[2 * v2 - 38];
  if ( v5 )
  {
    if ( *a1 == 1 )
    {
      v6 = *((_QWORD *)a1 - 285);
      if ( v6 )
        goto LABEL_6;
    }
    else if ( *a1 == 3 )
    {
      v6 = *(_QWORD *)(v5 + 536);
      if ( v6 )
      {
LABEL_6:
        v7 = *(unsigned __int8 *)(v6 + 36);
        v8 = v7 - 1;
        *(_BYTE *)(v6 + 36) = v7 - 1;
        if ( (_BYTE)v7 == 1 )
        {
          __break(0x800u);
          v8 = *(unsigned __int8 *)(v6 + 36);
        }
        goto LABEL_10;
      }
    }
  }
  v8 = 0;
LABEL_10:
  _rcu_read_unlock(lock);
  return v8;
}
