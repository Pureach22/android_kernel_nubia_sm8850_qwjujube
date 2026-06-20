__int64 __fastcall qmi_handle_release(__int64 *a1)
{
  __int64 v2; // x20
  __int64 *v3; // x21
  void (__fastcall *v4)(__int64 *, __int64 *); // x8
  __int64 *v5; // x25
  __int64 **v6; // x8
  __int64 *v7; // x9
  __int64 next; // x0
  __int64 v9; // x20
  __int64 result; // x0
  __int64 **v11; // x9
  __int64 **v12; // x8
  __int64 *v13; // x21
  _QWORD *v14; // x9
  _QWORD *v15; // x19
  _QWORD *v16; // t1
  _QWORD *v17; // x8
  _QWORD *v18; // x20
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v19 = 0;
  *(_QWORD *)(*(_QWORD *)(v2 + 24) + 648LL) = 0;
  cancel_work_sync(a1 + 9);
  v3 = (__int64 *)a1[18];
  if ( v3 != a1 + 18 )
  {
    do
    {
      v4 = (void (__fastcall *)(__int64 *, __int64 *))a1[23];
      v5 = (__int64 *)*v3;
      if ( v4 )
      {
        if ( *((_DWORD *)v4 - 1) != 190001868 )
          __break(0x8228u);
        v4(a1, v3 - 4);
      }
      v6 = (__int64 **)v3[1];
      if ( *v6 == v3 && (v7 = (__int64 *)*v3, *(__int64 **)(*v3 + 8) == v3) )
      {
        v7[1] = (__int64)v6;
        *v6 = v7;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      kfree(v3 - 4);
      v3 = v5;
    }
    while ( v5 != a1 + 18 );
  }
  mutex_lock(a1 + 1);
  sock_release(v2);
  *a1 = 0;
  mutex_unlock(a1 + 1);
  destroy_workqueue(a1[13]);
  mutex_lock(a1 + 31);
  v19 = 0;
  next = idr_get_next(a1 + 28, &v19);
  if ( next )
  {
    v9 = next;
    do
    {
      idr_remove(a1 + 28, *(unsigned __int16 *)(v9 + 8));
      *(_DWORD *)(v9 + 48) = -102;
      complete(v9 + 16);
      ++v19;
      v9 = idr_get_next(a1 + 28, &v19);
    }
    while ( v9 );
  }
  mutex_unlock(a1 + 31);
  idr_destroy(a1 + 28);
  result = kfree(a1[14]);
  v11 = (__int64 **)a1[16];
  if ( v11 != (__int64 **)(a1 + 16) )
  {
    do
    {
      v13 = *v11;
      v12 = (__int64 **)v11[1];
      if ( *v12 == (__int64 *)v11 && (__int64 **)v13[1] == v11 )
      {
        v13[1] = (__int64)v12;
        *v12 = v13;
      }
      else
      {
        _list_del_entry_valid_or_report(v11);
      }
      *v11 = (__int64 *)0xDEAD000000000100LL;
      v11[1] = (__int64 *)0xDEAD000000000122LL;
      result = kfree(v11 - 4);
      v11 = (__int64 **)v13;
    }
    while ( v13 != a1 + 16 );
  }
  v16 = (_QWORD *)a1[20];
  v15 = a1 + 20;
  v14 = v16;
  if ( v16 != v15 )
  {
    do
    {
      v18 = (_QWORD *)*v14;
      v17 = (_QWORD *)v14[1];
      if ( (_QWORD *)*v17 == v14 && (_QWORD *)v18[1] == v14 )
      {
        v18[1] = v17;
        *v17 = v18;
      }
      else
      {
        _list_del_entry_valid_or_report(v14);
      }
      *v14 = 0xDEAD000000000100LL;
      v14[1] = 0xDEAD000000000122LL;
      result = kfree(v14 - 4);
      v14 = v18;
    }
    while ( v18 != v15 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
