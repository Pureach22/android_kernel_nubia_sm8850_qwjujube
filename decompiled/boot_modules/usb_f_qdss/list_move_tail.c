_QWORD *__fastcall list_move_tail(_QWORD *result, _QWORD *a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x9
  _QWORD *v4; // x8
  _QWORD *v5; // x10
  _QWORD *v6; // x9

  v2 = (_QWORD *)result[1];
  if ( (_QWORD *)*v2 == result && (v3 = *result, *(_QWORD **)(*result + 8LL) == result) )
  {
    *(_QWORD *)(v3 + 8) = v2;
    *v2 = v3;
  }
  else
  {
    _list_del_entry_valid_or_report(result);
    a2 = v5;
    result = v6;
  }
  v4 = (_QWORD *)a2[1];
  if ( result == a2 || v4 == result || (_QWORD *)*v4 != a2 )
    return (_QWORD *)_list_add_valid_or_report(result, a2[1], a2);
  a2[1] = result;
  *result = a2;
  result[1] = v4;
  *v4 = result;
  return result;
}
