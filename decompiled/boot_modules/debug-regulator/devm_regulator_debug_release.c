__int64 __fastcall devm_regulator_debug_release(__int64 a1, _QWORD **a2)
{
  _QWORD *v3; // x19
  _UNKNOWN **v4; // x9
  _QWORD *v5; // x8
  __int64 v6; // x9

  mutex_lock(&debug_reg_list_lock);
  v3 = *a2;
  v4 = &debug_reg_list;
  while ( 1 )
  {
    v4 = (_UNKNOWN **)*v4;
    if ( v4 == &debug_reg_list )
      break;
    if ( v4 == v3 )
    {
      regulator_put(v3[2]);
      v5 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v5 == v3 && (v6 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
      {
        *(_QWORD *)(v6 + 8) = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      kfree(v3);
      return mutex_unlock(&debug_reg_list_lock);
    }
  }
  return mutex_unlock(&debug_reg_list_lock);
}
