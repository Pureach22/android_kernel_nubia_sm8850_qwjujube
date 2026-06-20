__int64 __fastcall rmnet_aps_remove_flow(_QWORD *a1, __int64 a2)
{
  _QWORD *v2; // x8
  _QWORD *v4; // x0
  __int64 v5; // x9
  _QWORD *v6; // x8
  __int64 result; // x0
  unsigned __int64 v8; // x9
  __int64 v9; // x10
  int v10; // w10

  v2 = (_QWORD *)a1[3];
  v4 = a1 + 2;
  if ( (_QWORD *)*v2 == v4 && (v5 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
  {
    *(_QWORD *)(v5 + 8) = v2;
    *v2 = v5;
  }
  else
  {
    _list_del_entry_valid_or_report(v4, a2);
  }
  v6 = (_QWORD *)a1[5];
  result = (__int64)(a1 + 4);
  v8 = 0xDEAD000000000122LL;
  a1[3] = 0xDEAD000000000122LL;
  if ( (_QWORD *)*v6 == a1 + 4 && (v9 = *(_QWORD *)result, *(_QWORD *)(*(_QWORD *)result + 8LL) == result) )
  {
    *(_QWORD *)(v9 + 8) = v6;
    *v6 = v9;
  }
  else
  {
    result = _list_del_entry_valid_or_report(result, a2);
  }
  v10 = rmnet_aps_flow_cnt;
  a1[4] = v8 - 34;
  a1[5] = v8;
  if ( !v10 || (rmnet_aps_flow_cnt = v10 - 1, v10 == 1) )
    result = timer_delete(&rmnet_aps_timer);
  if ( a1[9] )
    a1[9] = 0;
  if ( a1 )
    return kvfree_call_rcu(a1, a1);
  return result;
}
