_QWORD *__fastcall _list_del_entry_1(_QWORD *result)
{
  _QWORD *v1; // x8
  __int64 v2; // x9

  v1 = (_QWORD *)result[1];
  if ( (_QWORD *)*v1 != result )
    return (_QWORD *)_list_del_entry_valid_or_report(result);
  v2 = *result;
  if ( *(_QWORD **)(*result + 8LL) != result )
    return (_QWORD *)_list_del_entry_valid_or_report(result);
  *(_QWORD *)(v2 + 8) = v1;
  *v1 = v2;
  return result;
}
