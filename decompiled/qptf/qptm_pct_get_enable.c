__int64 __fastcall qptm_pct_get_enable(__int64 a1)
{
  __int64 result; // x0
  _UNKNOWN **v2; // x8
  __int64 v3; // x10
  __int64 (__fastcall *v4)(_QWORD); // x10
  __int64 v5; // x2
  __int64 v6; // x3
  unsigned int v7; // w19

  if ( *(_QWORD *)(qh + 8) != a1 )
    return 4294967274LL;
  v2 = (_UNKNOWN **)qptm_list;
  if ( qptm_list == (_UNKNOWN *)&qptm_list )
    return 0;
  while ( 1 )
  {
    v3 = (__int64)*(v2 - 9);
    if ( v3 )
    {
      v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 8);
      if ( v4 )
        break;
    }
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &qptm_list )
      return 0;
  }
  if ( *((_DWORD *)v4 - 1) != -1292534236 )
    __break(0x822Au);
  result = v4(v2 - 148);
  if ( (_DWORD)result )
  {
    v7 = result;
    printk(&unk_8339, "qptm_pct_get_enable", v5, v6);
    return v7;
  }
  return result;
}
