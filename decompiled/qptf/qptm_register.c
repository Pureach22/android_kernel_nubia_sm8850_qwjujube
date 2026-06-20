unsigned __int64 __fastcall qptm_register(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  _QWORD *v3; // x9
  _QWORD *v6; // x3
  unsigned __int64 result; // x0
  _QWORD *v8; // x0
  _QWORD *v9; // x2
  _QWORD *v10; // x1
  _QWORD *v11; // x8
  _QWORD *v12; // x9
  __int64 v14; // x9
  _QWORD *v15; // x0
  __int64 v16; // x10
  __int64 v17; // x2
  _QWORD *v18; // x1

  if ( !*(_QWORD *)(qh + 8) )
    return 4294967285LL;
  if ( a3 && a3[139] )
    return 4294967274LL;
  v3 = (_QWORD *)a2[139];
  if ( v3 )
  {
    if ( !v3[2] || !v3[3] || !v3[4] )
      return 4294967274LL;
  }
  if ( !a3 )
  {
    result = powercap_register_zone(a2, *(_QWORD *)(qh + 8), a1, 0, &zone_ops, 1, constraint_ops);
    if ( result > 0xFFFFFFFFFFFFF000LL )
      return result;
    v14 = qh;
    v15 = a2 + 135;
    v16 = *(_QWORD *)(qh + 24);
    v17 = v16 + 1096;
    v18 = *(_QWORD **)(v16 + 1104);
    if ( a2 + 135 == (_QWORD *)(v16 + 1096) || v18 == v15 || *v18 != v17 )
    {
      _list_add_valid_or_report(v15, v18);
      v14 = qh;
      v11 = a2;
    }
    else
    {
      v11 = a2;
      *(_QWORD *)(v16 + 1104) = v15;
      a2[135] = v17;
      a2[136] = v18;
      *v18 = v15;
    }
    v12 = *(_QWORD **)(v14 + 24);
    goto LABEL_25;
  }
  if ( *(_QWORD **)(qh + 24) == a3 )
    v6 = nullptr;
  else
    v6 = a3;
  result = powercap_register_zone(a2, *(_QWORD *)(qh + 8), a1, v6, &zone_ops, 1, constraint_ops);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v8 = a2 + 135;
    v9 = a3 + 137;
    v10 = (_QWORD *)a3[138];
    if ( a2 + 135 == a3 + 137 || v10 == v8 || (_QWORD *)*v10 != v9 )
    {
      _list_add_valid_or_report(v8, v10);
      v12 = a3;
      v11 = a2;
    }
    else
    {
      v11 = a2;
      v12 = a3;
      a3[138] = v8;
      a2[135] = v9;
      a2[136] = v10;
      *v10 = v8;
    }
LABEL_25:
    result = 0;
    v11[156] = v12;
    *((_BYTE *)v11 + 1164) = 1;
  }
  return result;
}
