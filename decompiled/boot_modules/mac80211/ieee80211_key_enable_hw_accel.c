__int64 __fastcall ieee80211_key_enable_hw_accel(char *a1, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x19
  __int64 v4; // x21
  int v5; // w20
  char *v6; // x20
  __int64 lock; // x0
  _QWORD *i; // x8
  int v9; // w8
  char *v10; // x19
  unsigned int v11; // w8
  unsigned int v12; // w9
  __int64 v14; // x9
  char *v15; // x22
  __int64 v16; // x3
  int v17; // w8
  void *v18; // x3

  v2 = *((_DWORD *)a1 + 10);
  v3 = *((_QWORD *)a1 + 1);
  if ( (v2 & 2) != 0 )
  {
    if ( (v2 & 1) != 0 && (*((_WORD *)a1 + 276) & 0x184) == 0 )
    {
      if ( *(_DWORD *)(v3 + 4720) == 3 )
      {
        v6 = a1;
        lock = _rcu_read_lock(a1, a2);
        for ( i = *(_QWORD **)(v3 + 2264); i != (_QWORD *)(v3 + 2264); i = (_QWORD *)*i )
          ++*((_DWORD *)i - 184);
        _rcu_read_unlock(lock);
        a1 = v6;
      }
      v9 = *(_DWORD *)(v3 + 1528);
      *(_DWORD *)(v3 + 1528) = v9 + 1;
      if ( !v9 )
      {
        v10 = a1;
        synchronize_net(a1);
        a1 = v10;
      }
    }
    *((_DWORD *)a1 + 10) &= ~1u;
    return (unsigned int)-22;
  }
  if ( !*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 464LL) + 152LL)
    || (v4 = *((_QWORD *)a1 + 2)) != 0
    && ((*((_WORD *)a1 + 276) & 8) == 0 && (*(_QWORD *)(*(_QWORD *)a1 + 96LL) & 0x80000) == 0
     || *(_BYTE *)(v4 + 204) != 1) )
  {
    v5 = -95;
    goto LABEL_20;
  }
  if ( *(_DWORD *)(v3 + 4720) != 4 || (*((_WORD *)a1 + 276) & 8) != 0 )
  {
    v14 = a1[554];
    if ( (v14 & 0x8000000000000000LL) == 0
      && *(_WORD *)(v3 + 5802)
      && (((unsigned __int64)*(unsigned __int16 *)(v3 + 5802) >> v14) & 1) == 0 )
    {
      return 0;
    }
    v15 = a1;
    if ( v4 )
      v16 = v4 + 2688;
    else
      v16 = 0;
    v5 = drv_set_key(*(_QWORD *)a1, 0, v3, v16, (__int64)(a1 + 536));
    if ( v5 < 0 )
    {
      if ( v5 != -95 )
      {
        a1 = v15;
        if ( v5 == -28 )
          goto LABEL_20;
        goto LABEL_46;
      }
    }
    else if ( v5 != 1 )
    {
      a1 = v15;
      if ( !v5 )
      {
        v17 = *((unsigned __int16 *)v15 + 276);
        *((_DWORD *)v15 + 10) |= 1u;
        if ( (v17 & 0x184) == 0 )
        {
          decrease_tailroom_need_count(v3, 1);
          v17 = *((unsigned __int16 *)v15 + 276);
          a1 = v15;
        }
        if ( (~v17 & 0x22) == 0 )
        {
          __break(0x800u);
          v17 = *((unsigned __int16 *)a1 + 276);
        }
        if ( (~v17 & 0x104) == 0 )
        {
          v11 = 0;
          __break(0x800u);
          return v11;
        }
        return 0;
      }
LABEL_46:
      if ( v4 )
        v18 = (void *)(v4 + 2688);
      else
        v18 = &bcast_addr;
      printk(&unk_BB49B, v3 + 1640, (unsigned int)a1[551], v18);
    }
    a1 = v15;
    goto LABEL_20;
  }
  v5 = 1;
LABEL_20:
  v12 = *((_DWORD *)a1 + 136) - 1027073;
  v11 = -22;
  if ( v12 <= 0xC && ((1 << v12) & 0x1FBB) != 0 )
  {
    if ( v5 == 1 )
      return 0;
    if ( (*(_QWORD *)(*(_QWORD *)a1 + 96LL) & 0x4000LL) != 0 )
      return (unsigned int)-22;
    else
      return 0;
  }
  return v11;
}
