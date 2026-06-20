__int64 __fastcall cfg80211_rehash_bss(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x21
  __int64 *v3; // x22
  __int64 v6; // x8
  __int64 *v7; // x23
  __int64 v8; // x24
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x9
  _QWORD *v12; // x8
  __int64 v13; // x9
  _QWORD *v14; // x8
  _QWORD *v15; // x9
  _QWORD *v16; // x10
  _QWORD *v17; // x8
  _QWORD *v18; // x9
  _QWORD *v19; // x10

  v2 = a2 + 4;
  v3 = (__int64 *)(a1 + 208);
  rb_erase(a2 + 4, a1 + 208);
  v6 = *(_QWORD *)(a1 + 208);
  if ( v6 )
  {
    v7 = v3;
    while ( 1 )
    {
      v8 = v6;
      result = cmp_bss((__int64)(a2 + 14), v6 + 80, 0);
      if ( !(_DWORD)result )
        break;
      v10 = *v7;
      if ( (int)result >= 0 )
        v11 = 8;
      else
        v11 = 16;
      v7 = (__int64 *)(v10 + v11);
      v6 = *(_QWORD *)(v10 + v11);
      if ( !v6 )
        goto LABEL_10;
    }
    __break(0x800u);
    v12 = (_QWORD *)a2[1];
    if ( (_QWORD *)*v12 == a2 && (v13 = *a2, *(_QWORD **)(*a2 + 8LL) == a2) )
    {
      *(_QWORD *)(v13 + 8) = v12;
      *v12 = v13;
    }
    else
    {
      result = _list_del_entry_valid_or_report(a2);
    }
    *a2 = 0xDEAD000000000100LL;
    a2[1] = 0xDEAD000000000122LL;
    v15 = a2 + 2;
    v14 = (_QWORD *)a2[2];
    if ( v14 != a2 + 2 )
    {
      v16 = (_QWORD *)a2[3];
      if ( (_QWORD *)*v16 == v15 && (_QWORD *)v14[1] == v15 )
      {
        v14[1] = v16;
        *v16 = v14;
      }
      else
      {
        result = _list_del_entry_valid_or_report(a2 + 2);
      }
      a2[2] = a2 + 2;
      a2[3] = v15;
    }
    v18 = a2 + 20;
    v17 = (_QWORD *)a2[20];
    if ( v17 != a2 + 20 )
    {
      v19 = (_QWORD *)a2[21];
      if ( (_QWORD *)*v19 == v18 && (_QWORD *)v17[1] == v18 )
      {
        v17[1] = v19;
        *v19 = v17;
      }
      else
      {
        result = _list_del_entry_valid_or_report(a2 + 20);
      }
      a2[20] = a2 + 20;
      a2[21] = v18;
    }
    --*(_DWORD *)(a1 + 220);
  }
  else
  {
    v8 = 0;
    v7 = v3;
LABEL_10:
    a2[4] = v8;
    a2[5] = 0;
    a2[6] = 0;
    *v7 = (__int64)v2;
    result = rb_insert_color(v2, v3);
  }
  ++*(_DWORD *)(a1 + 216);
  return result;
}
