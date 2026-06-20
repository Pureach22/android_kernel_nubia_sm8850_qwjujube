__int64 __fastcall qtee_shmbridge_deregister(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x5
  __int64 v6; // x6
  __int64 v7; // x7
  __int64 *v8; // x22
  __int64 v9; // x4
  unsigned int v10; // w0
  __int64 *v11; // x0
  __int64 *v12; // x8
  __int64 v13; // x9
  unsigned int v14; // w20
  __int64 *v16; // x9

  if ( qtee_shmbridge_enabled != 1 )
    return 0;
  mutex_lock(&unk_13920);
  v8 = &bridge_list_head;
  do
  {
    v8 = (__int64 *)*v8;
    if ( v8 == &bridge_list_head )
      goto LABEL_20;
  }
  while ( v8[3] != a1 );
  v9 = *((unsigned int *)v8 + 8);
  if ( (int)v9 < 1 )
  {
    printk(&unk_11E20, 206, "qtee_shmbridge_list_dec_refcount_locked");
  }
  else
  {
    *((_DWORD *)v8 + 8) = v9 - 1;
    if ( (_DWORD)v9 != 1 )
    {
LABEL_15:
      v14 = 0;
      goto LABEL_16;
    }
    v10 = qcom_scm_delete_shm_bridge(a1, v2, v3, v4, v9, v5, v6, v7);
    if ( !v10 )
    {
      v11 = &bridge_list_head;
      while ( 1 )
      {
        v11 = (__int64 *)*v11;
        if ( v11 == &bridge_list_head )
          goto LABEL_15;
        if ( v11[3] == a1 )
        {
          v12 = (__int64 *)v11[1];
          if ( (__int64 *)*v12 == v11 && (v13 = *v11, *(__int64 **)(*v11 + 8) == v11) )
          {
            *(_QWORD *)(v13 + 8) = v12;
            *v12 = v13;
          }
          else
          {
            _list_del_entry_valid_or_report();
            v11 = v16;
          }
          *v11 = 0xDEAD000000000100LL;
          v11[1] = 0xDEAD000000000122LL;
          kfree(v11);
          goto LABEL_15;
        }
      }
    }
    v14 = v10;
    printk(&unk_1249B, 196, "qtee_shmbridge_list_dec_refcount_locked");
    ++*((_DWORD *)v8 + 8);
    if ( v14 != -22 )
      goto LABEL_16;
  }
LABEL_20:
  printk(&unk_120FF, 212, a1);
  v14 = -22;
LABEL_16:
  mutex_unlock(&unk_13920);
  return v14;
}
