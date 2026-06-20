__int64 __fastcall devm_regulator_debug_unregister(unsigned __int64 a1)
{
  _QWORD *v2; // x3
  _UNKNOWN **v3; // x23

  if ( !a1 || a1 >= 0xFFFFFFFFFFFFF001LL )
    return printk(&unk_8162, "devm_regulator_debug_unregister");
  mutex_lock(&debug_reg_list_lock);
  v2 = debug_reg_list;
  if ( debug_reg_list != (_UNKNOWN *)&debug_reg_list )
  {
    do
    {
      v3 = (_UNKNOWN **)*v2;
      if ( v2[4] == a1 )
        devres_release(v2[3], devm_regulator_debug_release, devm_regulator_debug_match);
      v2 = v3;
    }
    while ( v3 != &debug_reg_list );
  }
  return mutex_unlock(&debug_reg_list_lock);
}
