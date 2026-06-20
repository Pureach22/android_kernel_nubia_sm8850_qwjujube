_QWORD *__fastcall list_add_tail_2(_QWORD *result, _QWORD *a2)
{
  _QWORD *v3; // x1

  v3 = (_QWORD *)a2[1];
  if ( result == a2 || v3 == result || (_QWORD *)*v3 != a2 )
    return (_QWORD *)_list_add_valid_or_report(result);
  a2[1] = result;
  *result = a2;
  result[1] = v3;
  *v3 = result;
  return result;
}
