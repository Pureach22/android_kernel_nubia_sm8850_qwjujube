__int64 __fastcall _sta_info_flush(__int64 a1, char a2, int a3)
{
  __int64 v5; // x19
  __int64 v6; // x8
  __int64 v7; // x23
  __int64 v8; // x24
  unsigned int v9; // w20
  _QWORD *v10; // x8
  char v11; // w22
  _QWORD *v12; // x24
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x23
  int v16; // w22
  __int64 lock; // x0
  __int64 *i; // x8
  __int64 v20; // x8
  __int64 v21; // x27
  __int64 v22; // x2
  _QWORD v23[3]; // [xsp+8h] [xbp-18h] BYREF

  v5 = a1;
  v23[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 1616);
  v23[0] = v23;
  v23[1] = v23;
  if ( (a2 & 1) != 0 )
  {
    if ( *(_DWORD *)(a1 + 4720) == 3 )
    {
      if ( *(_QWORD *)(a1 + 2032) )
        goto LABEL_4;
    }
    else
    {
      __break(0x800u);
      if ( *(_QWORD *)(a1 + 2032) )
        goto LABEL_4;
    }
    __break(0x800u);
  }
LABEL_4:
  v7 = *(_QWORD *)(v6 + 1616);
  v8 = v6 + 1616;
  if ( v7 == v6 + 1616 )
  {
    v9 = 0;
  }
  else
  {
    v9 = 0;
    do
    {
      v20 = *(_QWORD *)(v7 + 80);
      v21 = *(_QWORD *)v7;
      if ( (v20 == v5 || (a2 & 1) != 0 && *(_QWORD *)(v5 + 2032) == *(_QWORD *)(v20 + 2032))
        && (a3 < 0 || !*(_WORD *)(v7 + 2872) || ((1LL << a3) & *(unsigned __int16 *)(v7 + 2872)) != 0) )
      {
        a1 = _sta_info_destroy_part1((__int64 *)v7);
        if ( (_DWORD)a1 )
        {
          __break(0x800u);
        }
        else
        {
          v22 = v23[0];
          a1 = v7 + 16;
          if ( *(_QWORD **)(v23[0] + 8LL) != v23 || (_QWORD *)a1 == v23 || v23[0] == a1 )
          {
            a1 = _list_add_valid_or_report(a1, v23);
          }
          else
          {
            *(_QWORD *)(v23[0] + 8LL) = a1;
            *(_QWORD *)(v7 + 16) = v22;
            *(_QWORD *)(v7 + 24) = v23;
            v23[0] = v7 + 16;
          }
        }
        ++v9;
      }
      v7 = v21;
    }
    while ( v21 != v8 );
  }
  if ( (_QWORD *)v23[0] != v23 )
  {
    synchronize_net(a1);
    v10 = (_QWORD *)v23[0];
    if ( (_QWORD *)v23[0] == v23 )
    {
      ieee80211_recalc_min_chandef(v5, 0xFFFFFFFFLL);
    }
    else
    {
      v11 = 1;
      do
      {
        v12 = (_QWORD *)*v10;
        v11 &= *((_BYTE *)v10 + 2712);
        _sta_info_destroy_part2((__int64)(v10 - 2), 0);
        v10 = v12;
      }
      while ( v12 != v23 );
      v13 = ieee80211_recalc_min_chandef(v5, 0xFFFFFFFFLL);
      if ( (v11 & 1) == 0 )
      {
        v15 = *(_QWORD *)(v5 + 1616);
        v16 = *(unsigned __int8 *)(v5 + 5848);
        lock = _rcu_read_lock(v13, v14);
        for ( i = *(__int64 **)(v15 + 1616); i != (__int64 *)(v15 + 1616); i = (__int64 *)*i )
        {
          if ( i[10] == v5 && (i[27] & 2) != 0 && *((_BYTE *)i + 2728) != 1 )
          {
            v16 = 0;
            break;
          }
        }
        _rcu_read_unlock(lock);
        if ( *(unsigned __int8 *)(v5 + 5098) != v16 )
        {
          *(_BYTE *)(v5 + 5098) = v16;
          ieee80211_link_info_change_notify(v5, v5 + 3616, 0x80000);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
