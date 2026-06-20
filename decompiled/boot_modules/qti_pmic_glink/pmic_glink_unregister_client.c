__int64 __fastcall pmic_glink_unregister_client(const char **a1)
{
  const char *v2; // x8
  const char *v3; // x12
  const char **v4; // x9
  unsigned __int64 v5; // x10
  const char *v7; // x11
  char *v8; // x8
  const char *v9; // x12

  if ( !a1 )
    return 4294967277LL;
  if ( !*a1 )
    return 4294967277LL;
  mutex_lock(*a1 + 64);
  v2 = *a1;
  v3 = *((const char **)*a1 + 39);
  if ( v3 != *a1 + 312 )
  {
    v4 = a1 + 11;
    v5 = 0xDEAD000000000100LL;
    do
    {
      v7 = *(const char **)v3;
      if ( v3 - 88 == (const char *)a1 )
      {
        v8 = (char *)a1[12];
        if ( *(const char ***)v8 == v4 && (v9 = *v4, *((const char ***)*v4 + 1) == v4) )
        {
          *((_QWORD *)v9 + 1) = v8;
          *(_QWORD *)v8 = v9;
        }
        else
        {
          _list_del_entry_valid_or_report(v4);
        }
        v2 = *a1;
        a1[11] = (const char *)v5;
        a1[12] = (const char *)(v5 + 34);
      }
      v3 = v7;
    }
    while ( v7 != v2 + 312 );
  }
  idr_remove(v2 + 40, *((unsigned int *)a1 + 4));
  mutex_unlock(*a1 + 64);
  ipc_log_string(*((_QWORD *)*a1 + 4), "Unregistered client %s\n", a1[1]);
  kfree(a1[1]);
  kfree(a1);
  return 0;
}
