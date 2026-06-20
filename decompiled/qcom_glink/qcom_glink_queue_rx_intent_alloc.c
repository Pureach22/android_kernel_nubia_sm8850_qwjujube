__int64 __fastcall qcom_glink_queue_rx_intent_alloc(__int64 a1, __int64 a2, char a3, char a4)
{
  __int64 v8; // x22
  __int64 v9; // x0
  _QWORD *v10; // x8
  __int64 v11; // x2
  _QWORD *v12; // x1
  __int64 v13; // x9

  v8 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 56);
  if ( !v8 )
    return 4294967284LL;
  *(_QWORD *)(v8 + 16) = a2;
  *(_BYTE *)(v8 + 24) = a3 & 1;
  *(_BYTE *)(v8 + 27) = a4 & 1;
  v9 = raw_spin_lock_irqsave(a1 + 124);
  v10 = (_QWORD *)(v8 + 40);
  v11 = a1 + 224;
  v12 = *(_QWORD **)(a1 + 232);
  v13 = v9;
  if ( v8 + 40 == a1 + 224 || v12 == v10 || *v12 != v11 )
  {
    _list_add_valid_or_report(v8 + 40);
  }
  else
  {
    *(_QWORD *)(a1 + 232) = v10;
    *(_QWORD *)(v8 + 40) = v11;
    *(_QWORD *)(v8 + 48) = v12;
    *v12 = v10;
  }
  raw_spin_unlock_irqrestore(a1 + 124, v13);
  _wake_up(a1 + 240, 1, 1, 0);
  return 0;
}
