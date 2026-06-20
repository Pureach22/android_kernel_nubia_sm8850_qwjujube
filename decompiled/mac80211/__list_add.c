_QWORD *__fastcall _list_add(_QWORD *result, _QWORD *a2, __int64 a3)
{
  if ( *(_QWORD **)(a3 + 8) != a2 || result == (_QWORD *)a3 || result == a2 || *a2 != a3 )
    return (_QWORD *)_list_add_valid_or_report(result, a2);
  *(_QWORD *)(a3 + 8) = result;
  *result = a3;
  result[1] = a2;
  *a2 = result;
  return result;
}
