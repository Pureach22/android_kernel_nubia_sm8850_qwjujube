__int64 __fastcall qptm_release_zone(_QWORD *a1, __int64 a2)
{
  _QWORD *v3; // x9
  _QWORD *v4; // x8
  __int64 v5; // x10
  __int64 v6; // x8
  _DWORD *v7; // x8
  _QWORD *v8; // x20
  _QWORD *v9; // x9
  _QWORD *v10; // x0
  __int64 v11; // x10
  _QWORD *v12; // x8
  _QWORD *v13; // x19
  _QWORD *v14; // x9

  if ( (_QWORD *)a1[137] != a1 + 137 )
    return 4294967280LL;
  if ( a1[156] )
  {
    v3 = (_QWORD *)a1[136];
    v4 = a1 + 135;
    if ( (_QWORD *)*v3 == a1 + 135 && (v5 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
    {
      *(_QWORD *)(v5 + 8) = v3;
      *v3 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report(a1 + 135);
      a1 = v14;
    }
    a1[135] = 0xDEAD000000000100LL;
    a1[136] = 0xDEAD000000000122LL;
  }
  v6 = a1[139];
  if ( v6 )
  {
    v7 = *(_DWORD **)(v6 + 32);
    if ( *(v7 - 1) != -1437097284 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64))v7)(a1, a2);
  }
  else
  {
    v8 = a1;
    mutex_lock(&qptm_list_lock);
    v9 = (_QWORD *)v8[149];
    v10 = v8 + 148;
    if ( (_QWORD *)*v9 == v8 + 148 && (v11 = *v10, *(_QWORD **)(*v10 + 8LL) == v10) )
    {
      v12 = v8;
      *(_QWORD *)(v11 + 8) = v9;
      *v9 = v11;
    }
    else
    {
      _list_del_entry_valid_or_report(v10);
      v12 = v8;
    }
    v12[148] = 0xDEAD000000000100LL;
    v13 = v12;
    v12[149] = 0xDEAD000000000122LL;
    mutex_unlock(&qptm_list_lock);
    kfree(v13);
  }
  return 0;
}
