__int64 __fastcall smmu_aspace_unregister_cb(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w22
  _QWORD *i; // x9
  _QWORD *v8; // x8
  _QWORD *v9; // x0
  _QWORD *v10; // x10
  _QWORD *v12; // x10

  v3 = -22;
  if ( a1 && a2 )
  {
    mutex_lock(a1 + 320);
    for ( i = *(_QWORD **)(a1 + 304); ; i = (_QWORD *)*i )
    {
      if ( i == (_QWORD *)(a1 + 304) )
      {
        v3 = -2;
        goto LABEL_13;
      }
      if ( *(i - 2) == a2 && *(i - 1) == a3 )
        break;
    }
    v8 = (_QWORD *)i[1];
    v9 = i - 2;
    if ( (_QWORD *)*v8 == i && (v10 = (_QWORD *)*i, *(_QWORD **)(*i + 8LL) == i) )
    {
      v10[1] = v8;
      *v8 = v10;
    }
    else
    {
      _list_del_entry_valid_or_report(i);
      v9 = v12;
    }
    *i = 0xDEAD000000000100LL;
    i[1] = 0xDEAD000000000122LL;
    kfree(v9);
    v3 = 0;
LABEL_13:
    mutex_unlock(a1 + 320);
  }
  return v3;
}
