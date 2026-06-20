__int64 __fastcall msm_unregister_vm_event(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  _QWORD *v4; // x8
  __int64 v5; // x11
  _QWORD *v6; // x9
  _QWORD *v7; // x10
  _QWORD *v8; // x0
  _QWORD *v10; // x10

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 56LL);
  mutex_lock(v3 + 5704);
  v4 = *(_QWORD **)(v3 + 5752);
  while ( v4 != (_QWORD *)(v3 + 5752) )
  {
    v5 = *(v4 - 2);
    v6 = v4;
    v4 = (_QWORD *)*v4;
    if ( v5 == a2 )
    {
      v7 = (_QWORD *)v6[1];
      v8 = v6 - 6;
      if ( (_QWORD *)*v7 == v6 && (_QWORD *)v4[1] == v6 )
      {
        v4[1] = v7;
        *v7 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v6);
        v8 = v10;
      }
      *v6 = 0xDEAD000000000100LL;
      v6[1] = 0xDEAD000000000122LL;
      kfree(v8);
      return mutex_unlock(v3 + 5704);
    }
  }
  return mutex_unlock(v3 + 5704);
}
