__int64 *__fastcall list_add(__int64 *result)
{
  __int64 v1; // x2

  v1 = qword_394030;
  if ( (__int64 *)qword_394030 == result
    || result == &qword_394030
    || *(_QWORD *)(qword_394030 + 8) != (_QWORD)&qword_394030 )
  {
    return (__int64 *)_list_add_valid_or_report(result);
  }
  *(_QWORD *)(qword_394030 + 8) = result;
  *result = v1;
  result[1] = (__int64)&qword_394030;
  qword_394030 = (__int64)result;
  return result;
}
