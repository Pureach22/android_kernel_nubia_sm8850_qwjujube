__int64 __fastcall pmic_glink_register_client(__int64 a1, __int64 a2)
{
  void *v2; // x19
  _UNKNOWN **v4; // x21
  int v5; // w20
  __int64 v6; // x2
  __int64 v7; // x0
  __int64 v8; // x24
  __int64 v9; // x0
  int v10; // w8
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x8
  int v14; // w0
  int v16; // w20

  if ( !a1 )
    return -19;
  v2 = *(void **)(a1 + 96);
  if ( !v2 )
    return -19;
  if ( !*(_DWORD *)(a2 + 8) || !*(_QWORD *)(a2 + 24) || !*(_QWORD *)a2 )
    return -22;
  mutex_lock(&pmic_glink_dev_lock);
  v4 = &pmic_glink_dev_list;
  do
  {
    v4 = (_UNKNOWN **)*v4;
    if ( v4 == &pmic_glink_dev_list )
    {
      mutex_unlock(&pmic_glink_dev_lock);
      goto LABEL_23;
    }
  }
  while ( *(v4 - 33) != v2 );
  mutex_unlock(&pmic_glink_dev_lock);
  if ( v4 == (_UNKNOWN **)&unk_110 )
  {
LABEL_23:
    printk(&unk_784C, "pmic_glink_register_client", *(_QWORD *)a2);
    return -19;
  }
  down_read(v4 - 20);
  v5 = *((_DWORD *)v4 + 4);
  up_read(v4 - 20);
  if ( !v5 )
  {
    printk(&unk_7A59, "pmic_glink_register_client", v6);
    return -517;
  }
  v7 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 112);
  if ( !v7 )
    return -12;
  v8 = v7;
  v9 = kstrdup(*(_QWORD *)a2, 3264);
  *(_QWORD *)(v8 + 8) = v9;
  if ( !v9 )
  {
    kfree(v8);
    return -12;
  }
  _mutex_init(v8 + 24, "&client->lock", &pmic_glink_register_client___key);
  v10 = *(_DWORD *)(a2 + 8);
  v12 = *(_QWORD *)(a2 + 16);
  v11 = *(_QWORD *)(a2 + 24);
  *(_QWORD *)v8 = v4 - 34;
  *(_DWORD *)(v8 + 16) = v10;
  v13 = *(_QWORD *)(a2 + 32);
  *(_QWORD *)(v8 + 72) = v12;
  *(_QWORD *)(v8 + 80) = v11;
  *(_QWORD *)(v8 + 104) = v13;
  mutex_lock(v4 - 26);
  v14 = idr_alloc(v4 - 29, v8, *(unsigned int *)(v8 + 16), (unsigned int)(*(_DWORD *)(v8 + 16) + 1), 3264);
  if ( v14 < 0 )
  {
    v16 = v14;
    printk(&unk_7AAA, "pmic_glink_register_client", *(_QWORD *)(v8 + 8));
    mutex_unlock(v4 - 26);
    kfree(*(_QWORD *)(v8 + 8));
    kfree(v8);
    return v16;
  }
  else
  {
    if ( *(_QWORD *)(v8 + 104) )
    {
      *(_QWORD *)(v8 + 88) = v8 + 88;
      *(_QWORD *)(v8 + 96) = v8 + 88;
      _list_add();
    }
    mutex_unlock(v4 - 26);
    ipc_log_string(*(v4 - 30), "Registered client %s\n", *(const char **)(v8 + 8));
    return v8;
  }
}
