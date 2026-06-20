__int64 qmi_ts_cleanup()
{
  __int64 v0; // x20
  __int64 result; // x0
  __int64 v2; // x24
  _QWORD *v3; // x9
  __int64 v4; // x10
  _QWORD *v5; // x11
  _QWORD *v6; // x8

  if ( ts_inst_cnt >= 1 )
  {
    v0 = 0;
    do
    {
      v2 = ts_instances + 416 * v0;
      mutex_lock(v2 + 312);
      v3 = *(_QWORD **)(v2 + 368);
      v4 = v2 + 368;
      if ( v3 != (_QWORD *)(v2 + 368) )
      {
        do
        {
          v5 = (_QWORD *)*v3;
          v6 = (_QWORD *)v3[1];
          *((_BYTE *)v3 - 8) = 0;
          if ( (_QWORD *)*v6 == v3 && (_QWORD *)v5[1] == v3 )
          {
            v5[1] = v6;
            *v6 = v5;
          }
          else
          {
            _list_del_entry_valid_or_report(v3);
          }
          *v3 = 0xDEAD000000000100LL;
          v3[1] = 0xDEAD000000000122LL;
          v3 = v5;
        }
        while ( v5 != (_QWORD *)v4 );
      }
      qmi_handle_release(v2 + 8);
      result = mutex_unlock(v2 + 312);
      ++v0;
    }
    while ( v0 < ts_inst_cnt );
  }
  ts_inst_cnt = 0;
  return result;
}
