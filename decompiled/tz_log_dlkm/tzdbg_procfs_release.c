__int64 __fastcall tzdbg_procfs_release(__int64 a1, void *a2)
{
  _UNKNOWN **v4; // x9
  _QWORD *v5; // x8
  _UNKNOWN **v6; // x0
  _QWORD *v7; // x10
  _UNKNOWN **v9; // x10

  mutex_lock(&tzdbg_mutex);
  v4 = &clients_list;
  while ( 1 )
  {
    v4 = (_UNKNOWN **)*v4;
    if ( v4 == &clients_list )
      break;
    if ( *(v4 - 1) == a2 )
    {
      v5 = v4[1];
      v6 = v4 - 3;
      if ( (_UNKNOWN **)*v5 == v4 && (v7 = *v4, *((_UNKNOWN ***)*v4 + 1) == v4) )
      {
        v7[1] = v5;
        *v5 = v7;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
        v6 = v9;
      }
      *v4 = (_UNKNOWN *)0xDEAD000000000100LL;
      v4[1] = (_UNKNOWN *)0xDEAD000000000122LL;
      kfree(v6);
      break;
    }
  }
  mutex_unlock(&tzdbg_mutex);
  return single_release(a1, a2);
}
