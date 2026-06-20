_QWORD *__fastcall list_del(_QWORD *result, __int64 a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x9
  _QWORD *v4; // x9

  v2 = (_QWORD *)result[1];
  if ( (_QWORD *)*v2 == result && (v3 = *result, *(_QWORD **)(*result + 8LL) == result) )
  {
    *(_QWORD *)(v3 + 8) = v2;
    *v2 = v3;
  }
  else
  {
    _list_del_entry_valid_or_report(result, a2);
    result = v4;
  }
  *result = 0xDEAD000000000100LL;
  result[1] = 0xDEAD000000000122LL;
  return result;
}
