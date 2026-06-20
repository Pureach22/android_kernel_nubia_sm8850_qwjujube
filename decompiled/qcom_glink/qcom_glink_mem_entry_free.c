__int64 __fastcall qcom_glink_mem_entry_free(__int64 a1)
{
  __int64 v2; // x9
  _UNKNOWN **v3; // x10
  _QWORD *v4; // x8
  __int64 *v5; // x0
  __int64 v6; // x10

  v2 = raw_spin_lock_irqsave(&qcom_glink_mem_entry_lock);
  v3 = &qcom_glink_mem_entries;
  while ( 1 )
  {
    v3 = (_UNKNOWN **)*v3;
    if ( v3 == &qcom_glink_mem_entries )
      break;
    if ( v3 - 5 == (_UNKNOWN **)a1 )
    {
      v4 = *(_QWORD **)(a1 + 48);
      v5 = (__int64 *)(a1 + 40);
      if ( *v4 == a1 + 40 && (v6 = *v5, *(__int64 **)(*v5 + 8) == v5) )
      {
        *(_QWORD *)(v6 + 8) = v4;
        *v4 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report();
      }
      *(_QWORD *)(a1 + 40) = 0xDEAD000000000100LL;
      *(_QWORD *)(a1 + 48) = 0xDEAD000000000122LL;
      break;
    }
  }
  raw_spin_unlock_irqrestore(&qcom_glink_mem_entry_lock, v2);
  return kfree(a1);
}
