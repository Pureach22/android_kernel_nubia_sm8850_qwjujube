__int64 __fastcall pld_del_dev(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  _QWORD *v5; // x9
  _QWORD *v6; // x10
  _QWORD *v7; // x0
  _QWORD *v8; // x24
  _QWORD *v9; // x8

  v4 = raw_spin_lock_irqsave(a1 + 8);
  v5 = *(_QWORD **)(a1 + 16);
  if ( v5 != (_QWORD *)(a1 + 16) )
  {
    do
    {
      v8 = (_QWORD *)*v5;
      v7 = v5 - 2;
      if ( *(v5 - 2) == a2 )
      {
        v9 = (_QWORD *)v5[1];
        if ( (_QWORD *)*v9 == v5 && (_QWORD *)v8[1] == v5 )
        {
          v8[1] = v9;
          *v9 = v8;
        }
        else
        {
          _list_del_entry_valid_or_report(v5);
          v7 = v6;
        }
        *v5 = 0xDEAD000000000100LL;
        v5[1] = 0xDEAD000000000122LL;
        kfree(v7);
      }
      v5 = v8;
    }
    while ( v8 != (_QWORD *)(a1 + 16) );
  }
  return raw_spin_unlock_irqrestore(a1 + 8, v4);
}
