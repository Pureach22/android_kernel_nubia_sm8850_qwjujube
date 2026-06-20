__int64 __fastcall rndis_free_response(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x0
  _QWORD *v5; // x9
  _QWORD *v6; // x23
  _QWORD *v7; // x8

  raw_spin_lock(a1 + 96);
  v4 = *(_QWORD **)(a1 + 80);
  if ( v4 != (_QWORD *)(a1 + 80) )
  {
    do
    {
      v6 = (_QWORD *)*v4;
      if ( v4[2] == a2 )
      {
        v7 = (_QWORD *)v4[1];
        if ( (_QWORD *)*v7 == v4 && (_QWORD *)v6[1] == v4 )
        {
          v6[1] = v7;
          *v7 = v6;
        }
        else
        {
          _list_del_entry_valid_or_report(v4);
          v4 = v5;
        }
        *v4 = 0xDEAD000000000100LL;
        v4[1] = 0xDEAD000000000122LL;
        kfree(v4);
      }
      v4 = v6;
    }
    while ( v6 != (_QWORD *)(a1 + 80) );
  }
  return raw_spin_unlock(a1 + 96);
}
