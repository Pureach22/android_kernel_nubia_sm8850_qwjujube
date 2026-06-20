__int64 __fastcall regulator_debug_unregister(unsigned __int64 a1)
{
  _QWORD *v2; // x20
  _UNKNOWN **v3; // x23
  _QWORD *v4; // x8
  _UNKNOWN **v5; // x9

  if ( !a1 || a1 >= 0xFFFFFFFFFFFFF001LL )
    return printk(&unk_8162, "regulator_debug_unregister");
  mutex_lock(&debug_reg_list_lock);
  v2 = debug_reg_list;
  if ( debug_reg_list != (_UNKNOWN *)&debug_reg_list )
  {
    do
    {
      v3 = (_UNKNOWN **)*v2;
      if ( v2[4] == a1 )
      {
        regulator_put(v2[2]);
        v4 = (_QWORD *)v2[1];
        if ( (_QWORD *)*v4 == v2 && (v5 = (_UNKNOWN **)*v2, *(_QWORD **)(*v2 + 8LL) == v2) )
        {
          v5[1] = v4;
          *v4 = v5;
        }
        else
        {
          _list_del_entry_valid_or_report(v2);
        }
        *v2 = 0xDEAD000000000100LL;
        v2[1] = 0xDEAD000000000122LL;
        kfree(v2);
      }
      v2 = v3;
    }
    while ( v3 != &debug_reg_list );
  }
  return mutex_unlock(&debug_reg_list_lock);
}
