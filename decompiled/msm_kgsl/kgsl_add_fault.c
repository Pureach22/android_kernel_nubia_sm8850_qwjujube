__int64 __fastcall kgsl_add_fault(_QWORD *a1, int a2, __int64 a3)
{
  __int64 v6; // x0
  _QWORD *v7; // x20
  __int64 v8; // x0
  __int64 v9; // x23
  _QWORD *v10; // x22
  _QWORD *v11; // x21
  int v12; // w24
  _QWORD *v13; // x26
  _QWORD *v14; // x8
  __int64 v15; // x0
  _QWORD *v17; // x22
  _QWORD *v18; // x8
  __int64 v19; // x9
  __int64 v20; // x0
  _QWORD *v21; // x1

  if ( !a1 || (a1[4] & 2) != 0 || (a1[4] & 4) != 0 )
    return 4294967274LL;
  v6 = _kmalloc_cache_noprof(raw_read_unlock, 3264, 40);
  v7 = (_QWORD *)v6;
  if ( !v6 )
    return 4294967284LL;
  *(_DWORD *)(v6 + 16) = a2;
  *(_QWORD *)(v6 + 24) = a3;
  v8 = ktime_get(v6);
  v7[4] = v8;
  v9 = ktime_get(v8);
  mutex_lock(a1 + 39);
  v10 = (_QWORD *)a1[37];
  v11 = a1 + 37;
  if ( v10 != a1 + 37 )
  {
    v12 = 0;
    do
    {
      v13 = (_QWORD *)*v10;
      if ( v10[4] > v9 - 5000000000LL )
      {
        ++v12;
      }
      else
      {
        v14 = (_QWORD *)v10[1];
        if ( (_QWORD *)*v14 == v10 && (_QWORD *)v13[1] == v10 )
        {
          v13[1] = v14;
          *v14 = v13;
        }
        else
        {
          _list_del_entry_valid_or_report(v10);
        }
        v15 = v10[3];
        *v10 = 0xDEAD000000000100LL;
        v10[1] = 0xDEAD000000000122LL;
        kfree(v15);
        kfree(v10);
      }
      v10 = v13;
    }
    while ( v13 != v11 );
    if ( v12 == 40 )
    {
      v17 = (_QWORD *)*v11;
      v18 = *(_QWORD **)(*v11 + 8LL);
      if ( *v18 == *v11 && (v19 = *v17, *(_QWORD **)(*v17 + 8LL) == v17) )
      {
        *(_QWORD *)(v19 + 8) = v18;
        *v18 = v19;
      }
      else
      {
        _list_del_entry_valid_or_report(*v11);
      }
      v20 = v17[3];
      *v17 = 0xDEAD000000000100LL;
      v17[1] = 0xDEAD000000000122LL;
      kfree(v20);
      kfree(v17);
    }
  }
  v21 = (_QWORD *)a1[38];
  if ( v7 == v11 || v21 == v7 || (_QWORD *)*v21 != v11 )
  {
    _list_add_valid_or_report(v7, v21);
  }
  else
  {
    a1[38] = v7;
    *v7 = v11;
    v7[1] = v21;
    *v21 = v7;
  }
  mutex_unlock(a1 + 39);
  return 0;
}
