__int64 __fastcall synx_dma_add_cb_no_enable_sig(_QWORD *a1, _QWORD *a2, __int64 a3)
{
  __int64 v6; // x9
  _QWORD *v7; // x2
  _QWORD *v8; // x1
  unsigned int v9; // w21

  if ( a1 && a3 )
  {
    v6 = raw_spin_lock_irqsave(*a1);
    if ( (a1[6] & 1) != 0 )
    {
      *a2 = a2;
      v9 = -2;
      a2[1] = a2;
    }
    else
    {
      a2[2] = a3;
      v7 = a1 + 2;
      v8 = (_QWORD *)a1[3];
      if ( a1 + 2 == a2 || v8 == a2 || (_QWORD *)*v8 != v7 )
      {
        _list_add_valid_or_report(a2, v8);
        v9 = 0;
      }
      else
      {
        v9 = 0;
        a1[3] = a2;
        *a2 = v7;
        a2[1] = v8;
        *v8 = a2;
      }
    }
    raw_spin_unlock_irqrestore(*a1, v6);
  }
  else
  {
    __break(0x800u);
    return (unsigned int)-22;
  }
  return v9;
}
