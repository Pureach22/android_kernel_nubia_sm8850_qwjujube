__int64 __fastcall _qcom_glink_rx_done(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 v9; // x23
  __int64 v10; // x0
  _QWORD *v11; // x10
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x11

  if ( *(_BYTE *)(a1 + 216) == 1 )
  {
    kfree(*(_QWORD *)a3);
    kfree(a3);
    return 0;
  }
  else
  {
    if ( (*(_BYTE *)(a3 + 24) & 1) == 0 )
    {
      v9 = raw_spin_lock_irqsave(a2 + 144);
      idr_remove(a2 + 152, *(unsigned int *)(a3 + 8));
      raw_spin_unlock_irqrestore(a2 + 144, v9);
    }
    v10 = raw_spin_lock_irqsave(a2 + 144);
    v11 = *(_QWORD **)(a3 + 48);
    v12 = a3 + 40;
    v13 = v10;
    if ( *v11 == a3 + 40 && (v14 = *(_QWORD *)v12, *(_QWORD *)(*(_QWORD *)v12 + 8LL) == v12) )
    {
      *(_QWORD *)(v14 + 8) = v11;
      *v11 = v14;
    }
    else
    {
      _list_del_entry_valid_or_report(a3 + 40);
    }
    *(_QWORD *)(a3 + 40) = 0xDEAD000000000100LL;
    *(_QWORD *)(a3 + 48) = 0xDEAD000000000122LL;
    raw_spin_unlock_irqrestore(a2 + 144, v13);
    return qcom_glink_send_rx_done(a1, a2, a3, a4 & 1);
  }
}
