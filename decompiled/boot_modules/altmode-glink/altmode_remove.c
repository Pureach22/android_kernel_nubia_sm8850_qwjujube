__int64 __fastcall altmode_remove(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *v2; // x0
  _QWORD *v3; // x8
  _QWORD *v4; // x22
  _QWORD *v5; // x9
  _QWORD *v6; // x9
  _QWORD *v7; // x10
  _QWORD *v8; // x8
  _QWORD *v9; // x11
  __int64 v10; // x0
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 168);
  debugfs_remove(*(_QWORD *)(v1 + 336));
  cancel_delayed_work_sync(v1 + 128);
  cancel_delayed_work_sync(v1 + 232);
  idr_destroy(v1 + 16);
  *(_DWORD *)(v1 + 120) = 0;
  mutex_lock(&notify_lock);
  v2 = probe_notify_list;
  if ( probe_notify_list != (_UNKNOWN *)&probe_notify_list )
  {
    do
    {
      v4 = (_QWORD *)*v2;
      v3 = (_QWORD *)v2[1];
      if ( (_QWORD *)*v3 == v2 && (_QWORD *)v4[1] == v2 )
      {
        v4[1] = v3;
        *v3 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
        v2 = v5;
      }
      *v2 = 0xDEAD000000000100LL;
      v2[1] = 0xDEAD000000000122LL;
      kfree(v2);
      v2 = v4;
    }
    while ( v4 != &probe_notify_list );
  }
  mutex_unlock(&notify_lock);
  mutex_lock(v1 + 40);
  v7 = (_QWORD *)(v1 + 104);
  v6 = *(_QWORD **)(v1 + 104);
  if ( v6 != (_QWORD *)(v1 + 104) )
  {
    do
    {
      v9 = (_QWORD *)*v6;
      v8 = (_QWORD *)v6[1];
      if ( (_QWORD *)*v8 == v6 && (_QWORD *)v9[1] == v6 )
      {
        v9[1] = v8;
        *v8 = v9;
      }
      else
      {
        _list_del_entry_valid_or_report(v6);
      }
      *v6 = 0xDEAD000000000100LL;
      v6[1] = 0xDEAD000000000122LL;
      v6 = v9;
    }
    while ( v9 != v7 );
  }
  mutex_unlock(v1 + 40);
  ipc_log_context_destroy(altmode_ipc_log);
  v10 = *(_QWORD *)(v1 + 8);
  altmode_ipc_log = 0;
  result = pmic_glink_unregister_client(v10);
  if ( (result & 0x80000000) != 0 )
    return dev_err(*(_QWORD *)v1, "Error in pmic_glink de-registration: %d\n", result);
  return result;
}
