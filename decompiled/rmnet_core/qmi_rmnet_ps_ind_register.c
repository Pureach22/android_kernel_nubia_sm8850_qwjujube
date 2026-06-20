__int64 __fastcall qmi_rmnet_ps_ind_register(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  void *v4; // x2
  _UNKNOWN **v5; // x8

  result = 4294967274LL;
  if ( a1 && a2 && *a2 && a2[1] )
  {
    v4 = ps_list;
    v5 = (_UNKNOWN **)(a2 + 2);
    if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)ps_list) != &ps_list || v5 == &ps_list || ps_list == (_UNKNOWN *)v5 )
    {
      _list_add_valid_or_report(v5, &ps_list, ps_list);
      return 0;
    }
    else
    {
      a2[2] = ps_list;
      a2[3] = &ps_list;
      result = 0;
      atomic_store((unsigned __int64)v5, (unsigned __int64 *)&ps_list);
      *(_QWORD *)((char *)&unk_8 + (_QWORD)v4) = v5;
    }
  }
  return result;
}
