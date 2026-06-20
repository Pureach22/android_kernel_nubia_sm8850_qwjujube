_QWORD *__fastcall list_del_0(_QWORD *result)
{
  _QWORD *v1; // x8
  __int64 v2; // x9
  _QWORD *v3; // x9

  v1 = (_QWORD *)result[1];
  if ( (_QWORD *)*v1 == result && (v2 = *result, *(_QWORD **)(*result + 8LL) == result) )
  {
    *(_QWORD *)(v2 + 8) = v1;
    *v1 = v2;
  }
  else
  {
    _list_del_entry_valid_or_report(result);
    result = v3;
  }
  *result = 0xDEAD000000000100LL;
  result[1] = 0xDEAD000000000122LL;
  return result;
}
