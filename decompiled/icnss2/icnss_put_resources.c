__int64 __fastcall icnss_put_resources(__int64 result)
{
  __int64 v1; // x9
  unsigned __int64 v2; // x11
  unsigned __int64 *i; // x10
  unsigned __int64 **v4; // x12
  unsigned __int64 **v5; // x8
  unsigned __int64 v6; // x13
  unsigned __int64 **v7; // x9
  unsigned __int64 *j; // x10
  unsigned __int64 *v9; // t1
  unsigned __int64 **v10; // x8
  unsigned __int64 v11; // x12

  v1 = result;
  v2 = 0xDEAD000000000100LL;
  if ( result )
  {
    v4 = (unsigned __int64 **)(result + 232);
    for ( i = *(unsigned __int64 **)(result + 232); i != (unsigned __int64 *)v4; i = *v4 )
    {
      v5 = (unsigned __int64 **)i[1];
      if ( *v5 == i && (v6 = *i, *(unsigned __int64 **)(*i + 8) == i) )
      {
        *(_QWORD *)(v6 + 8) = v5;
        *v5 = (unsigned __int64 *)v6;
      }
      else
      {
        result = _list_del_entry_valid_or_report(i);
      }
      *i = v2;
      i[1] = v2 + 34;
    }
  }
  v9 = *(unsigned __int64 **)(v1 + 216);
  v7 = (unsigned __int64 **)(v1 + 216);
  for ( j = v9; j != (unsigned __int64 *)v7; j = *v7 )
  {
    v10 = (unsigned __int64 **)j[1];
    if ( *v10 == j && (v11 = *j, *(unsigned __int64 **)(*j + 8) == j) )
    {
      *(_QWORD *)(v11 + 8) = v10;
      *v10 = (unsigned __int64 *)v11;
    }
    else
    {
      result = _list_del_entry_valid_or_report(j);
    }
    *j = v2;
    j[1] = v2 + 34;
  }
  return result;
}
