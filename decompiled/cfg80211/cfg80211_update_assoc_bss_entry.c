__int64 __fastcall cfg80211_update_assoc_bss_entry(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x26
  _QWORD *v6; // x21
  __int64 v7; // x8
  __int64 *v8; // x27
  __int64 i; // x23
  unsigned int v10; // w9
  _BOOL4 v11; // w8
  _QWORD *v12; // x1
  _QWORD *v13; // x27
  _QWORD *v14; // x8
  _QWORD *v15; // x21
  _QWORD *v16; // t1
  _QWORD *v17; // x23

  v3 = *a1;
  if ( !*a1 )
    goto LABEL_39;
  if ( (unsigned int)a2 >= 0xF )
  {
    __break(0x5512u);
LABEL_39:
    __break(0x800u);
    return cmp_bss(a1, a2, a3);
  }
  v6 = (_QWORD *)a1[9 * (unsigned int)a2 + 50];
  raw_spin_lock_bh(v3 - 808);
  if ( v6[14] != a3 )
  {
    v7 = v6[19];
    v8 = (__int64 *)(v3 - 800);
    if ( v7 )
      v6 = (_QWORD *)(v7 - 112);
    v6[14] = a3;
    for ( i = *v8; (__int64 *)i != v8; i = *(_QWORD *)i )
    {
      v10 = *((_DWORD *)a1 + 24);
      if ( v10 == 4 )
      {
        v11 = 1;
        if ( (_QWORD *)i == v6 )
          continue;
      }
      else
      {
        if ( **(_DWORD **)(i + 112) == 2 )
        {
          if ( v10 >= 3 )
            continue;
          v10 = 3 - v10;
        }
        else if ( v10 )
        {
          if ( v10 == 3 )
          {
            v10 = 0;
          }
          else if ( v10 != 2 )
          {
            continue;
          }
        }
        else
        {
          v10 = 1;
        }
        v11 = v10 == (*(_WORD *)(i + 182) & 3);
        if ( (_QWORD *)i == v6 )
          continue;
      }
      if ( v11 && !(unsigned int)cmp_bss(i + 112, v6 + 14, 0) )
      {
        if ( i )
        {
          cfg80211_update_known_bss(v6, i, 0);
          v12 = *(_QWORD **)(i + 160);
          *(_QWORD *)(i + 128) = 0;
          *(_QWORD *)(i + 136) = 0;
          if ( v12 != (_QWORD *)(i + 160) )
          {
            do
            {
              v13 = (_QWORD *)*v12;
              if ( (_cfg80211_unlink_bss(v3 - 992, v12 - 20) & 1) != 0 )
                ++*(_DWORD *)(v3 - 776);
              v12 = v13;
            }
            while ( v13 != (_QWORD *)(i + 160) );
          }
          if ( *(_DWORD *)(i + 80) )
            __break(0x800u);
          if ( (_cfg80211_unlink_bss(v3 - 992, (__int64 *)i) & 1) != 0 )
            ++*(_DWORD *)(v3 - 776);
          else
            __break(0x800u);
        }
        break;
      }
    }
    cfg80211_rehash_bss(v3 - 992, v6);
    v16 = (_QWORD *)v6[20];
    v15 = v6 + 20;
    v14 = v16;
    if ( v16 != v15 )
    {
      do
      {
        v17 = (_QWORD *)*v14;
        *(v14 - 6) = a3;
        cfg80211_rehash_bss(v3 - 992, v14 - 20);
        v14 = v17;
      }
      while ( v17 != v15 );
    }
  }
  return raw_spin_unlock_bh(v3 - 808);
}
