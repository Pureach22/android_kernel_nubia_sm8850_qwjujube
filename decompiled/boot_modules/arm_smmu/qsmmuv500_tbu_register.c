__int64 __fastcall qsmmuv500_tbu_register(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x0
  _QWORD *v4; // x2
  _QWORD *v5; // x1
  unsigned int v6; // w8

  v3 = *(_QWORD **)(a1 + 152);
  if ( v3 )
  {
    *v3 = v3;
    v3[1] = v3;
    v3[3] = a2;
    v4 = *(_QWORD **)(a2 + 328);
    v5 = (_QWORD *)(a2 + 328);
    if ( (_QWORD *)v4[1] != v5 || v3 == v5 || v4 == v3 )
    {
      _list_add_valid_or_report();
      return 0;
    }
    else
    {
      v6 = 0;
      v4[1] = v3;
      *v3 = v4;
      v3[1] = v5;
      *v5 = v3;
    }
  }
  else
  {
    dev_err(a1, "TBU failed probe, QSMMUV500 cannot continue!\n");
    return (unsigned int)-22;
  }
  return v6;
}
