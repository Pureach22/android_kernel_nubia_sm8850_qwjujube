__int64 __fastcall ieee80211_link_unreserve_chanctx(__int64 *a1)
{
  __int64 *v1; // x19
  __int64 **v2; // x9
  __int64 **v3; // x8
  __int64 v4; // x10
  __int64 *v5; // x11
  int v6; // w12
  unsigned __int64 v7; // x9
  _QWORD *v8; // x8
  _QWORD *v9; // x11
  _QWORD *v10; // x11
  _QWORD *v11; // x13
  __int64 v12; // x8
  __int64 **v13; // x8
  __int64 *v14; // x10
  __int64 v15; // x0
  int v16; // w10
  _QWORD *v17; // x12
  _QWORD *v18; // x8
  __int64 **v19; // x8
  __int64 *v20; // x10
  __int64 *v22; // x9
  __int64 v23; // x10
  __int64 v24; // x9

  v1 = (__int64 *)a1[46];
  if ( v1 )
  {
    v2 = (__int64 **)a1[5];
    v3 = (__int64 **)(a1 + 4);
    v4 = *a1;
    if ( *v2 == a1 + 4 && (v5 = *v3, (__int64 **)(*v3)[1] == v3) )
    {
      v5[1] = (__int64)v2;
      *v2 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report(a1 + 4);
      a1 = v22;
    }
    v6 = 2;
    a1[46] = 0;
    v7 = 0xDEAD000000000122LL;
    a1[4] = 0xDEAD000000000100LL;
    a1[5] = 0xDEAD000000000122LL;
    v8 = v1 + 4;
    v9 = v1 + 4;
    do
    {
      v9 = (_QWORD *)*v9;
      --v6;
    }
    while ( v9 != v8 );
    v10 = v1 + 6;
    v11 = v1 + 6;
    do
    {
      v11 = (_QWORD *)*v11;
      --v6;
    }
    while ( v11 != v10 );
    if ( v6 )
      return 0;
    if ( *((_DWORD *)v1 + 16) != 2 )
    {
      v15 = *(_QWORD *)(v4 + 1616);
      v16 = 2;
      v17 = v1 + 4;
      do
      {
        v17 = (_QWORD *)*v17;
        --v16;
      }
      while ( v17 != v8 );
      v18 = v1 + 6;
      do
      {
        v18 = (_QWORD *)*v18;
        --v16;
      }
      while ( v18 != v10 );
      if ( v16 )
        __break(0x800u);
      v19 = (__int64 **)v1[1];
      if ( *v19 == v1 && (v20 = (__int64 *)*v1, *(__int64 **)(*v1 + 8) == v1) )
      {
        v20[1] = (__int64)v19;
        *v19 = v20;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
        v15 = v23;
      }
      v1[1] = v7;
      ieee80211_del_chanctx(v15, v1, 0);
      goto LABEL_29;
    }
    v12 = v1[9];
    if ( v12 )
    {
      if ( *(_DWORD *)(v12 + 64) != 1 )
      {
        __break(0x800u);
        v12 = v1[9];
      }
      if ( *(__int64 **)(v12 + 72) != v1 )
      {
        __break(0x800u);
        v12 = v1[9];
      }
      *(_QWORD *)(v12 + 72) = 0;
      *(_DWORD *)(v1[9] + 64) = 0;
      v13 = (__int64 **)v1[1];
      if ( *v13 == v1 && (v14 = (__int64 *)*v1, *(__int64 **)(*v1 + 8) == v1) )
      {
        v14[1] = (__int64)v13;
        *v13 = v14;
        v1[1] = 0xDEAD000000000122LL;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
        v1[1] = v24;
      }
LABEL_29:
      kvfree_call_rcu(v1 + 2, v1);
      return 0;
    }
  }
  __break(0x800u);
  return 4294967274LL;
}
