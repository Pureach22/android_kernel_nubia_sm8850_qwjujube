__int64 __fastcall qcom_glink_mem_entry_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  __int64 v10; // x0
  __int64 v11; // x19
  _UNKNOWN **v12; // x20
  __int64 v13; // x9
  _QWORD *v14; // x1

  v10 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 56);
  v11 = v10;
  if ( v10 )
  {
    *(_QWORD *)(v10 + 16) = a3;
    *(_QWORD *)(v10 + 24) = a4;
    v12 = (_UNKNOWN **)(v10 + 40);
    *(_QWORD *)v10 = a1;
    *(_QWORD *)(v10 + 8) = a2;
    *(_DWORD *)(v10 + 32) = a5;
    *(_QWORD *)(v10 + 40) = v10 + 40;
    *(_QWORD *)(v10 + 48) = v10 + 40;
    v13 = raw_spin_lock_irqsave(&qcom_glink_mem_entry_lock);
    v14 = off_360;
    if ( off_360 == v12 || *off_360 != (_UNKNOWN *)&qcom_glink_mem_entries )
    {
      _list_add_valid_or_report(v11 + 40);
    }
    else
    {
      off_360 = (_UNKNOWN **)(v11 + 40);
      *(_QWORD *)(v11 + 40) = &qcom_glink_mem_entries;
      *(_QWORD *)(v11 + 48) = v14;
      *v14 = v12;
    }
    raw_spin_unlock_irqrestore(&qcom_glink_mem_entry_lock, v13);
  }
  return v11;
}
