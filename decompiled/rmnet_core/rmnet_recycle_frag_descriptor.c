__int64 __fastcall rmnet_recycle_frag_descriptor(_QWORD *a1, __int64 a2)
{
  _QWORD *v2; // x8
  _QWORD *v3; // x21
  __int64 v6; // x9
  _QWORD *v7; // x0
  _QWORD *v8; // x22
  __int64 v9; // x8
  _QWORD *v10; // x26
  __int64 v11; // x9
  _QWORD *v12; // x27
  _QWORD *v13; // x8
  __int64 v14; // x9
  _QWORD *v15; // x9
  unsigned int v22; // w9
  unsigned int v23; // w9
  __int64 v24; // x0
  _QWORD *v25; // x1
  __int64 v26; // x9

  v2 = (_QWORD *)a1[1];
  v3 = *(_QWORD **)(a2 + 2808);
  if ( (_QWORD *)*v2 == a1 && (v6 = *a1, *(_QWORD **)(*a1 + 8LL) == a1) )
  {
    *(_QWORD *)(v6 + 8) = v2;
    *v2 = v6;
  }
  else
  {
    _list_del_entry_valid_or_report(a1);
  }
  v8 = a1 + 2;
  v7 = (_QWORD *)a1[2];
  *a1 = 0xDEAD000000000100LL;
  a1[1] = 0xDEAD000000000122LL;
  if ( v7 != a1 + 2 )
  {
    do
    {
      v9 = v7[2];
      v10 = (_QWORD *)*v7;
      if ( v9 && (v9 & 1) == 0 )
      {
        v11 = *(_QWORD *)(v9 + 8);
        if ( (v11 & 1) != 0 )
          v9 = v11 - 1;
        _X10 = (unsigned int *)(v9 + 52);
        __asm { PRFM            #0x11, [X10] }
        do
        {
          v22 = __ldxr(_X10);
          v23 = v22 - 1;
        }
        while ( __stlxr(v23, _X10) );
        __dmb(0xBu);
        if ( !v23 )
        {
          v12 = v7;
          _folio_put(v9);
          v7 = v12;
        }
      }
      v13 = (_QWORD *)v7[1];
      if ( (_QWORD *)*v13 == v7 && (v14 = *v7, *(_QWORD **)(*v7 + 8LL) == v7) )
      {
        *(_QWORD *)(v14 + 8) = v13;
        *v13 = v14;
      }
      else
      {
        _list_del_entry_valid_or_report(v7);
        v7 = v15;
      }
      *v7 = 0xDEAD000000000100LL;
      v7[1] = 0xDEAD000000000122LL;
      kfree(v7);
      v7 = v10;
    }
    while ( v10 != v8 );
  }
  a1[9] = 0;
  a1[10] = 0;
  a1[7] = 0;
  a1[8] = 0;
  a1[5] = 0;
  a1[6] = 0;
  a1[4] = 0;
  *a1 = a1;
  a1[1] = a1;
  a1[2] = a1 + 2;
  a1[3] = v8;
  v24 = raw_spin_lock_irqsave(a2 + 2800);
  v25 = (_QWORD *)v3[1];
  v26 = v24;
  if ( v3 == a1 || v25 == a1 || (_QWORD *)*v25 != v3 )
  {
    _list_add_valid_or_report(a1, v25, v3);
  }
  else
  {
    v3[1] = a1;
    *a1 = v3;
    a1[1] = v25;
    *v25 = a1;
  }
  return raw_spin_unlock_irqrestore(a2 + 2800, v26);
}
