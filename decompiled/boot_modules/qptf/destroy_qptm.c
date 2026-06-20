__int64 __fastcall destroy_qptm(_QWORD *a1)
{
  _QWORD *v2; // x8
  _QWORD *v3; // x0
  __int64 v4; // x9
  _QWORD *v5; // x9
  _QWORD *v6; // x10
  _QWORD *v7; // x8
  _QWORD *v8; // x11

  powercap_unregister_zone(*(_QWORD *)(qh + 8), a1);
  mutex_lock(&qptm_list_lock);
  v2 = (_QWORD *)a1[149];
  v3 = a1 + 148;
  if ( (_QWORD *)*v2 == a1 + 148 && (v4 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
  {
    *(_QWORD *)(v4 + 8) = v2;
    *v2 = v4;
  }
  else
  {
    ((void (*)(void))_list_del_entry_valid_or_report)();
  }
  a1[148] = 0xDEAD000000000100LL;
  a1[149] = 0xDEAD000000000122LL;
  mutex_unlock(&qptm_list_lock);
  mutex_lock(a1 + 150);
  v5 = (_QWORD *)a1[146];
  v6 = a1 + 146;
  if ( v5 != a1 + 146 )
  {
    do
    {
      v8 = (_QWORD *)*v5;
      v7 = (_QWORD *)v5[1];
      if ( (_QWORD *)*v7 == v5 && (_QWORD *)v8[1] == v5 )
      {
        v8[1] = v7;
        *v7 = v8;
      }
      else
      {
        _list_del_entry_valid_or_report(v5);
      }
      *((_BYTE *)v5 - 8) = 0;
      *v5 = 0xDEAD000000000100LL;
      v5[1] = 0xDEAD000000000122LL;
      v5 = v8;
    }
    while ( v8 != v6 );
  }
  return mutex_unlock(a1 + 150);
}
