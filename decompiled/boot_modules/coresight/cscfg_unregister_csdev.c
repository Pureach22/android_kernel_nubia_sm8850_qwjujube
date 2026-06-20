__int64 __fastcall cscfg_unregister_csdev(__int64 a1)
{
  _QWORD *v2; // x8
  __int64 v3; // x11
  _QWORD *v4; // x9
  _QWORD *v5; // x10
  _QWORD *v6; // x0
  _QWORD *v8; // x10

  mutex_lock(&cscfg_mutex);
  v2 = *(_QWORD **)(cscfg_mgr + 912);
  while ( v2 != (_QWORD *)(cscfg_mgr + 912) )
  {
    v3 = *(v2 - 3);
    v4 = v2;
    v2 = (_QWORD *)*v2;
    if ( v3 == a1 )
    {
      v5 = (_QWORD *)v4[1];
      v6 = v4 - 3;
      if ( (_QWORD *)*v5 == v4 && (_QWORD *)v2[1] == v4 )
      {
        v2[1] = v5;
        *v5 = v2;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
        v6 = v8;
      }
      *v4 = 0xDEAD000000000100LL;
      v4[1] = 0xDEAD000000000122LL;
      kfree(v6);
      return mutex_unlock(&cscfg_mutex);
    }
  }
  return mutex_unlock(&cscfg_mutex);
}
