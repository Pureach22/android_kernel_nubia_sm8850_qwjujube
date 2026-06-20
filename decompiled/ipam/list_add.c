_QWORD *__fastcall list_add(_QWORD *result, _QWORD *a2)
{
  _QWORD *v2; // x2

  v2 = (_QWORD *)*a2;
  if ( *(_QWORD **)(*a2 + 8LL) != a2 || result == a2 || v2 == result )
    return (_QWORD *)_list_add_valid_or_report(result, a2);
  v2[1] = result;
  *result = v2;
  result[1] = a2;
  *a2 = result;
  return result;
}
