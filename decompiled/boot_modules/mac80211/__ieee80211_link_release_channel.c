__int64 *__fastcall _ieee80211_link_release_channel(__int64 *result, char a2)
{
  __int64 v2; // x23
  __int64 v3; // x8
  __int64 *v4; // x19
  __int64 *v6; // x21
  __int64 v7; // x20
  _QWORD *v8; // x9
  int v9; // w8
  _QWORD *v10; // x10
  _BOOL4 v11; // w24
  _QWORD *v12; // x8
  int v13; // w10
  _QWORD *v14; // x9
  _QWORD *v15; // x9
  _QWORD *v16; // x11
  int v17; // w10
  _QWORD *v18; // x11
  _QWORD *v19; // x8
  __int64 **v20; // x8
  __int64 *v21; // x9

  v2 = *(_QWORD *)(result[118] + 832);
  if ( v2 )
  {
    v3 = result[46];
    v4 = result;
    v6 = (__int64 *)(v2 - 152);
    v7 = *(_QWORD *)(*result + 1616);
    if ( v3 )
    {
      if ( *(_DWORD *)(v3 + 64) == 2 )
      {
        v8 = (_QWORD *)(v3 + 48);
        v9 = -1;
        v10 = v8;
        do
        {
          v10 = (_QWORD *)*v10;
          ++v9;
        }
        while ( v10 != v8 );
        v11 = v9 > 1;
      }
      else
      {
        v11 = 0;
      }
      ieee80211_link_unreserve_chanctx(result);
    }
    else
    {
      v11 = 0;
    }
    result = (__int64 *)ieee80211_assign_link_chanctx(v4, 0, 0);
    v12 = (_QWORD *)(v2 - 120);
    v13 = 2;
    v14 = (_QWORD *)(v2 - 120);
    do
    {
      v14 = (_QWORD *)*v14;
      --v13;
    }
    while ( v14 != v12 );
    v15 = (_QWORD *)(v2 - 104);
    v16 = (_QWORD *)(v2 - 104);
    do
    {
      v16 = (_QWORD *)*v16;
      --v13;
    }
    while ( v16 != v15 );
    if ( !v13 )
    {
      v17 = 2;
      v18 = (_QWORD *)(v2 - 120);
      do
      {
        v18 = (_QWORD *)*v18;
        --v17;
      }
      while ( v18 != v12 );
      v19 = (_QWORD *)(v2 - 104);
      do
      {
        v19 = (_QWORD *)*v19;
        --v17;
      }
      while ( v19 != v15 );
      if ( v17 )
        __break(0x800u);
      v20 = *(__int64 ***)(v2 - 144);
      if ( *v20 == v6 && (v21 = (__int64 *)*v6, *(__int64 **)(*v6 + 8) == v6) )
      {
        v21[1] = (__int64)v20;
        *v20 = v21;
      }
      else
      {
        _list_del_entry_valid_or_report(v2 - 152);
      }
      *(_QWORD *)(v2 - 144) = 0xDEAD000000000122LL;
      result = (__int64 *)ieee80211_del_chanctx(v7, v2 - 152, a2 & 1);
      if ( v2 != 152 )
        result = (__int64 *)kvfree_call_rcu(v2 - 136, v2 - 152);
    }
    *((_BYTE *)v4 + 456) = 0;
    if ( v11 )
      return (__int64 *)ieee80211_vif_use_reserved_switch(v7);
  }
  return result;
}
