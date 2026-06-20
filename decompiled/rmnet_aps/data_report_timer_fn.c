__int64 data_report_timer_fn()
{
  __int64 v0; // x21
  __int64 v1; // x1
  _QWORD *v2; // x0
  _QWORD *v3; // x9
  _QWORD *v4; // x24
  _QWORD *v5; // x8
  _UNKNOWN **v6; // x21
  __int64 result; // x0

  v0 = jiffies;
  raw_spin_lock_bh(&data_report_lock);
  v2 = data_report_req_list;
  if ( data_report_req_list != (_UNKNOWN *)&data_report_req_list )
  {
    do
    {
      v4 = (_QWORD *)*v2;
      if ( v0 - v2[12] >= 0 )
      {
        v5 = (_QWORD *)v2[1];
        if ( (_QWORD *)*v5 == v2 && (_QWORD *)v4[1] == v2 )
        {
          v4[1] = v5;
          *v5 = v4;
        }
        else
        {
          _list_del_entry_valid_or_report(v2, v1);
          v2 = v3;
        }
        *v2 = 0xDEAD000000000100LL;
        v2[1] = 0xDEAD000000000122LL;
        kfree(v2);
        --data_report_count;
      }
      v2 = v4;
    }
    while ( v4 != &data_report_req_list );
  }
  v6 = (_UNKNOWN **)data_report_req_list;
  result = raw_spin_unlock_bh(&data_report_lock);
  if ( v6 != &data_report_req_list )
    return mod_timer(&data_report_timer);
  return result;
}
