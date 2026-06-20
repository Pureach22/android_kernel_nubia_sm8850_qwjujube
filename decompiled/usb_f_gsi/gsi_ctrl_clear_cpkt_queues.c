__int64 __fastcall gsi_ctrl_clear_cpkt_queues(__int64 a1, char a2)
{
  __int64 v4; // x20
  _QWORD *v5; // x9
  _QWORD *v6; // x8
  _QWORD *v7; // x24
  _QWORD *v8; // x21
  _QWORD *v9; // x9
  _QWORD *v10; // x8
  _QWORD *v11; // x24
  _QWORD *v12; // x21

  v4 = raw_spin_lock_irqsave(a1 + 1304);
  if ( (a2 & 1) == 0 )
  {
    v5 = *(_QWORD **)(a1 + 1264);
    if ( v5 != (_QWORD *)(a1 + 1264) )
    {
      do
      {
        v7 = (_QWORD *)*v5;
        v6 = (_QWORD *)v5[1];
        if ( (_QWORD *)*v6 == v5 && (_QWORD *)v7[1] == v5 )
        {
          v7[1] = v6;
          *v6 = v7;
        }
        else
        {
          _list_del_entry_valid_or_report(v5);
        }
        v8 = v5 - 2;
        *v5 = 0xDEAD000000000100LL;
        v5[1] = 0xDEAD000000000122LL;
        if ( v5 != &qword_10 )
        {
          kfree(*v8);
          kfree(v8);
        }
        v5 = v7;
      }
      while ( v7 != (_QWORD *)(a1 + 1264) );
    }
  }
  v9 = *(_QWORD **)(a1 + 1280);
  if ( v9 != (_QWORD *)(a1 + 1280) )
  {
    do
    {
      v11 = (_QWORD *)*v9;
      v10 = (_QWORD *)v9[1];
      if ( (_QWORD *)*v10 == v9 && (_QWORD *)v11[1] == v9 )
      {
        v11[1] = v10;
        *v10 = v11;
      }
      else
      {
        _list_del_entry_valid_or_report(v9);
      }
      v12 = v9 - 2;
      *v9 = 0xDEAD000000000100LL;
      v9[1] = 0xDEAD000000000122LL;
      if ( v9 != &qword_10 )
      {
        kfree(*v12);
        kfree(v12);
      }
      v9 = v11;
    }
    while ( v11 != (_QWORD *)(a1 + 1280) );
  }
  return raw_spin_unlock_irqrestore(a1 + 1304, v4);
}
