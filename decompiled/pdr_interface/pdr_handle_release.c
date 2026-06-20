unsigned __int64 __fastcall pdr_handle_release(unsigned __int64 result)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x9
  _QWORD *v3; // x8
  _QWORD *v4; // x22

  if ( result )
  {
    v1 = (_QWORD *)result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      mutex_lock(result + 656);
      v2 = (_QWORD *)v1[78];
      if ( v2 != v1 + 78 )
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
          }
          *v2 = 0xDEAD000000000100LL;
          v2[1] = 0xDEAD000000000122LL;
          kfree(v2 - 21);
          v2 = v4;
        }
        while ( v4 != v1 + 78 );
      }
      mutex_unlock(v1 + 82);
      cancel_work_sync(v1 + 101);
      cancel_work_sync(v1 + 105);
      cancel_work_sync(v1 + 109);
      destroy_workqueue(v1[113]);
      destroy_workqueue(v1[114]);
      qmi_handle_release(v1);
      qmi_handle_release(v1 + 38);
      return kfree(v1);
    }
  }
  return result;
}
