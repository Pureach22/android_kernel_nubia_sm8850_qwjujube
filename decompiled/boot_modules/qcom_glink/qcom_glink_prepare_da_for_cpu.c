__int64 __fastcall qcom_glink_prepare_da_for_cpu(int a1, __int64 a2)
{
  __int64 v4; // x19
  _UNKNOWN **v5; // x8
  __int64 v6; // x22
  __int64 v8; // x10
  __int64 v9; // x11

  v4 = raw_spin_lock_irqsave(&qcom_glink_mem_entry_lock);
  v5 = (_UNKNOWN **)qcom_glink_mem_entries;
  if ( qcom_glink_mem_entries == (_UNKNOWN *)&qcom_glink_mem_entries )
  {
LABEL_2:
    v6 = 0;
  }
  else
  {
    while ( 1 )
    {
      v8 = (__int64)*(v5 - 4);
      if ( v8 )
      {
        v9 = (unsigned int)(a1 - *((_DWORD *)v5 - 2));
        if ( (v9 & 0x80000000) == 0 && v9 + a2 <= (unsigned __int64)*(v5 - 2) )
          break;
      }
      v5 = (_UNKNOWN **)*v5;
      if ( v5 == &qcom_glink_mem_entries )
        goto LABEL_2;
    }
    v6 = v8 + v9;
    if ( (*((_BYTE *)*(v5 - 5) + 844) & 0x40) == 0 )
      _dma_sync_single_for_cpu();
  }
  raw_spin_unlock_irqrestore(&qcom_glink_mem_entry_lock, v4);
  return v6;
}
