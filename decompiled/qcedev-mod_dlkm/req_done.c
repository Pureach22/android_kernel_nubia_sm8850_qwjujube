__int64 __fastcall req_done(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x20
  char v5; // w9
  __int64 *v6; // x9
  __int64 **v7; // x8
  __int64 *v8; // x10

  v2 = raw_spin_lock_irqsave(a1 + 272);
  v3 = *(_QWORD *)(a1 + 264);
  v4 = v2;
  *(_QWORD *)(a1 + 264) = 0;
  if ( v3 )
  {
    v5 = *(_BYTE *)(v3 + 946);
    *(_WORD *)(v3 + 944) = 3;
    if ( (v5 & 1) == 0 && (*(_BYTE *)(v3 + 947) & 1) == 0 )
      complete(v3 + 16);
  }
  v6 = *(__int64 **)(a1 + 248);
  if ( v6 != (__int64 *)(a1 + 248) )
  {
    v7 = (__int64 **)v6[1];
    if ( *v7 == v6 && (v8 = (__int64 *)*v6, *(__int64 **)(*v6 + 8) == v6) )
    {
      v8[1] = (__int64)v7;
      *v7 = v8;
    }
    else
    {
      _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 248));
    }
    *((_WORD *)v6 + 472) = 0;
    *v6 = 0xDEAD000000000100LL;
    v6[1] = 0xDEAD000000000122LL;
    _wake_up(v6 + 115, 1, 1, 0);
  }
  return raw_spin_unlock_irqrestore(a1 + 272, v4);
}
