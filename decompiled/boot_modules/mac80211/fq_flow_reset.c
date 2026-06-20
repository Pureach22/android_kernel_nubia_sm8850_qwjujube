__int64 __fastcall fq_flow_reset(__int64 result, __int64 a2)
{
  _QWORD *v2; // x23
  __int64 *v4; // x21
  __int64 *v5; // x24
  __int64 v6; // x20
  __int64 v7; // x22
  __int64 v8; // x8
  _QWORD *v9; // x9
  __int64 v10; // x8
  __int64 v11; // x9
  _QWORD *v12; // x10
  _QWORD *v13; // x8
  _QWORD *v14; // x9
  __int64 v15; // x10
  int v16; // w8

  v2 = *(_QWORD **)a2;
  v5 = (__int64 *)(a2 + 24);
  v4 = *(__int64 **)(a2 + 24);
  if ( v4 != (__int64 *)(a2 + 24) && v4 )
  {
    v6 = result;
    v7 = result - 208;
    do
    {
      --*(_DWORD *)(a2 + 40);
      v8 = *v4;
      v9 = (_QWORD *)v4[1];
      *v4 = 0;
      v4[1] = 0;
      *(_QWORD *)(v8 + 8) = v9;
      *v9 = v8;
      fq_adjust_removal(v6, (_DWORD *)a2, (__int64)v4);
      result = ieee80211_free_txskb(v7, (__int64)v4);
      v4 = *(__int64 **)(a2 + 24);
    }
    while ( v4 != v5 && v4 );
  }
  v11 = a2 + 8;
  v10 = *(_QWORD *)(a2 + 8);
  if ( v10 != a2 + 8 )
  {
    v12 = *(_QWORD **)(a2 + 16);
    if ( *v12 == v11 && *(_QWORD *)(v10 + 8) == v11 )
    {
      *(_QWORD *)(v10 + 8) = v12;
      *v12 = v10;
    }
    else
    {
      result = _list_del_entry_valid_or_report(a2 + 8);
    }
    *(_QWORD *)(a2 + 8) = a2 + 8;
    *(_QWORD *)(a2 + 16) = v11;
    if ( (_QWORD *)*v2 == v2 && (_QWORD *)v2[2] == v2 + 2 )
    {
      v13 = (_QWORD *)v2[5];
      v14 = v2 + 4;
      if ( (_QWORD *)*v13 == v2 + 4 && (v15 = *v14, *(_QWORD **)(*v14 + 8LL) == v14) )
      {
        *(_QWORD *)(v15 + 8) = v13;
        *v13 = v15;
      }
      else
      {
        result = _list_del_entry_valid_or_report(v2 + 4);
      }
      v2[4] = v2 + 4;
      v2[5] = v14;
    }
  }
  v16 = *(_DWORD *)(a2 + 48);
  *(_QWORD *)a2 = 0;
  if ( v16 )
    __break(0x800u);
  return result;
}
