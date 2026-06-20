__int64 __fastcall devm_regulator_debug_release(__int64 a1, _QWORD **a2)
{
  _QWORD *v2; // x19
  _UNKNOWN **v3; // x9
  _QWORD *v4; // x8
  __int64 v5; // x9
  __int64 result; // x0

  v2 = *a2;
  v3 = &debug_reg_list;
  while ( 1 )
  {
    v3 = (_UNKNOWN **)*v3;
    if ( v3 == &debug_reg_list )
      break;
    if ( v3 == v2 )
    {
      regulator_put(v2[2]);
      v4 = (_QWORD *)v2[1];
      if ( (_QWORD *)*v4 == v2 && (v5 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
      {
        *(_QWORD *)(v5 + 8) = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
      }
      *v2 = 0xDEAD000000000100LL;
      v2[1] = 0xDEAD000000000122LL;
      return kfree(v2);
    }
  }
  return result;
}
