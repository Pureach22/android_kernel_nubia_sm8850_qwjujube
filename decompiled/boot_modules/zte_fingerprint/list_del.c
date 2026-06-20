__int64 list_del()
{
  __int64 *v0; // x9
  __int64 *v1; // x8
  __int64 v2; // x10
  __int64 result; // x0

  v0 = &qword_8378;
  v1 = (__int64 *)qword_8380;
  if ( *(__int64 **)qword_8380 == &qword_8378 && (v2 = qword_8378, *(__int64 **)(qword_8378 + 8) == &qword_8378) )
  {
    *(_QWORD *)(qword_8378 + 8) = qword_8380;
    *v1 = v2;
  }
  else
  {
    result = _list_del_entry_valid_or_report(&qword_8378);
  }
  *v0 = 0xDEAD000000000100LL;
  v0[1] = 0xDEAD000000000122LL;
  return result;
}
