__int64 __fastcall adreno_ioctl_perfcounter_put(__int64 *a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x19
  _QWORD *v6; // x9
  _QWORD *v7; // x21
  _QWORD *v8; // t1
  _QWORD *v9; // x8
  _QWORD *v10; // x0
  __int64 v11; // x10
  __int64 v12; // x20
  _QWORD *v14; // x10

  v3 = *a1;
  rt_mutex_lock(*a1 + 11088);
  v8 = (_QWORD *)a1[2];
  v7 = a1 + 2;
  v6 = v8;
  if ( v8 == v7 )
  {
LABEL_10:
    v12 = -19;
  }
  else
  {
    while ( *((_DWORD *)v6 - 2) != *a3 || *((_DWORD *)v6 - 1) != a3[1] )
    {
      v6 = (_QWORD *)*v6;
      if ( v6 == v7 )
        goto LABEL_10;
    }
    v9 = (_QWORD *)v6[1];
    v10 = v6 - 1;
    if ( (_QWORD *)*v9 == v6 && (v11 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
    {
      *(_QWORD *)(v11 + 8) = v9;
      *v9 = v11;
    }
    else
    {
      _list_del_entry_valid_or_report(v6);
      v10 = v14;
    }
    *v6 = 0xDEAD000000000100LL;
    v6[1] = 0xDEAD000000000122LL;
    kfree(v10);
    adreno_perfcounter_put(v3, *a3, a3[1], 0);
    v12 = 0;
  }
  rt_mutex_unlock(v3 + 11088);
  return v12;
}
