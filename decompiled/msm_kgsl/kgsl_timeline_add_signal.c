__int64 __fastcall kgsl_timeline_add_signal(_QWORD *a1)
{
  _QWORD *v1; // x20
  __int64 v3; // x0
  unsigned __int64 v4; // x8
  __int64 v5; // x9
  _QWORD *i; // x1
  _QWORD *v7; // x2
  _QWORD *v8; // x0

  v1 = (_QWORD *)*a1;
  v3 = raw_spin_lock_irqsave(*a1 + 28LL);
  v4 = a1[1];
  v5 = v3;
  if ( v1[2] < v4 )
  {
    for ( i = (_QWORD *)v1[8]; i != v1 + 7; i = (_QWORD *)i[1] )
    {
      if ( *(i - 3) <= v4 )
        break;
    }
    v7 = (_QWORD *)*i;
    v8 = a1 + 4;
    if ( *(_QWORD **)(*i + 8LL) != i || v8 == i || v7 == v8 )
    {
      _list_add_valid_or_report(v8, i);
    }
    else
    {
      v7[1] = v8;
      a1[4] = v7;
      a1[5] = i;
      *i = v8;
    }
  }
  return raw_spin_unlock_irqrestore((char *)v1 + 28, v5);
}
