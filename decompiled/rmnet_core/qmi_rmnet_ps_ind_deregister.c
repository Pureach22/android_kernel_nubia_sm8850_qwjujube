__int64 __fastcall qmi_rmnet_ps_ind_deregister(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _UNKNOWN **v4; // x9
  _QWORD *v5; // x8
  __int64 *v6; // x0
  __int64 v7; // x9
  __int64 v8; // x9

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v4 = &ps_list;
    do
    {
      v4 = (_UNKNOWN **)*v4;
      if ( v4 == &ps_list )
        return 0;
    }
    while ( v4 - 2 != (_UNKNOWN **)a2 );
    v5 = *(_QWORD **)(a2 + 24);
    v6 = (__int64 *)(a2 + 16);
    if ( *v5 == a2 + 16 && (v7 = *v6, *(__int64 **)(*v6 + 8) == v6) )
    {
      *(_QWORD *)(v7 + 8) = v5;
      *v5 = v7;
    }
    else
    {
      _list_del_entry_valid_or_report(v6);
      a2 = v8;
    }
    *(_QWORD *)(a2 + 24) = 0xDEAD000000000122LL;
    return 0;
  }
  return result;
}
