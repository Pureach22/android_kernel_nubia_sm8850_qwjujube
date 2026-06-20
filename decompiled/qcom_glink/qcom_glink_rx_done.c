__int64 __fastcall qcom_glink_rx_done(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v5; // x21
  _QWORD *v6; // x8
  __int64 v7; // x11
  _QWORD *v8; // x9
  _QWORD *v9; // x10
  _QWORD *v10; // x22
  char v11; // w11

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 112);
    if ( (*(_BYTE *)(v2 + 208) & 8) != 0 )
    {
      v5 = raw_spin_lock_irqsave(a1 + 144);
      v6 = *(_QWORD **)(a1 + 200);
      do
      {
        if ( v6 == (_QWORD *)(a1 + 200) )
        {
          raw_spin_unlock_irqrestore(a1 + 144, v5);
          return 4294967274LL;
        }
        v7 = *(v6 - 5);
        v8 = v6;
        v6 = (_QWORD *)*v6;
      }
      while ( v7 != a2 );
      v9 = (_QWORD *)v8[1];
      v10 = v8 - 5;
      if ( (_QWORD *)*v9 == v8 && (_QWORD *)v6[1] == v8 )
      {
        v6[1] = v9;
        *v9 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v8);
      }
      v11 = *((_BYTE *)v8 - 16);
      *v8 = 0xDEAD000000000100LL;
      v8[1] = 0xDEAD000000000122LL;
      if ( (v11 & 1) == 0 )
        idr_remove(a1 + 152, *((unsigned int *)v8 - 8));
      raw_spin_unlock_irqrestore(a1 + 144, v5);
      qcom_glink_send_rx_done(v2, a1, v10, 1);
      return 0;
    }
    else
    {
      return 4294967274LL;
    }
  }
  else
  {
    __break(0x800u);
    return 4294967274LL;
  }
}
