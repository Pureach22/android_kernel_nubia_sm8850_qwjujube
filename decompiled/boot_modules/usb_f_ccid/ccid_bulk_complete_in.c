__int64 __fastcall ccid_bulk_complete_in(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v4; // x20
  __int64 v5; // x0
  _QWORD *v6; // x8
  _QWORD *v7; // x1
  __int64 v8; // x9

  v2 = *(_QWORD *)(a2 + 56);
  if ( *(_DWORD *)(a2 + 84) )
    *(_DWORD *)(v2 + 464) = 1;
  v4 = v2 + 544;
  v5 = raw_spin_lock_irqsave(v2 + 228);
  v6 = (_QWORD *)(a2 + 64);
  v7 = *(_QWORD **)(v2 + 552);
  v8 = v5;
  if ( a2 + 64 == v2 + 544 || v7 == v6 || *v7 != v4 )
  {
    _list_add_valid_or_report(a2 + 64, v7, v2 + 544);
  }
  else
  {
    *(_QWORD *)(v2 + 552) = v6;
    *(_QWORD *)(a2 + 64) = v4;
    *(_QWORD *)(a2 + 72) = v7;
    *v7 = v6;
  }
  raw_spin_unlock_irqrestore(v2 + 228, v8);
  return _wake_up(v2 + 504, 3, 1, 0);
}
