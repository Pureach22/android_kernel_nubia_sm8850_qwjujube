__int64 __fastcall reg_regdb_apply(__int64 a1)
{
  __int64 *i; // x19
  __int64 **v2; // x8
  __int64 *v3; // x9
  unsigned __int64 v4; // x0
  __int64 v5; // x0

  rtnl_lock(a1);
  mutex_lock(&reg_regdb_apply_mutex);
  for ( i = (__int64 *)reg_regdb_apply_list;
        reg_regdb_apply_list != (_UNKNOWN *)&reg_regdb_apply_list;
        i = (__int64 *)reg_regdb_apply_list )
  {
    v2 = *(__int64 ***)((char *)&unk_8 + (_QWORD)i);
    if ( *v2 == i && (v3 = (__int64 *)*i, *(__int64 **)((char *)&unk_8 + *i) == i) )
    {
      *(_QWORD *)((char *)&unk_8 + (_QWORD)v3) = v2;
      *v2 = v3;
    }
    else
    {
      _list_del_entry_valid_or_report(i);
    }
    v4 = *(_QWORD *)((char *)&qword_10 + (_QWORD)i);
    *i = 0xDEAD000000000100LL;
    i[1] = 0xDEAD000000000122LL;
    set_regdom(v4);
    kfree(i);
  }
  v5 = mutex_unlock(&reg_regdb_apply_mutex);
  return rtnl_unlock(v5);
}
