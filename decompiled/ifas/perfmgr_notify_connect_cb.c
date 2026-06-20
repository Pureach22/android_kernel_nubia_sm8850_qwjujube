int __fastcall perfmgr_notify_connect_cb(int pid, unsigned __int64 identifier, int connectedAPI)
{
  int v4; // w24
  __int64 *v6; // x8
  void *v7; // x0
  _QWORD *v8; // x0
  __int64 **v9; // x1
  __int64 *v10; // x8
  __int64 v12; // x1
  __int64 *v13; // x9
  __int64 *v14; // x8
  __int64 *v15; // x0
  __int64 v16; // x10
  __int64 v17; // x0
  __int64 *v18; // x26
  int v19; // w8
  int v20; // w19
  __int64 v21; // x1
  __int64 v22; // x9
  __int64 **v23; // x8
  __int64 *v24; // x20
  __int64 *v26; // x10

  v4 = ifas_enable;
  if ( ifas_log_enable )
  {
    printk(&unk_FD8B, "perfmgr_notify_connect_cb");
    if ( connectedAPI )
      goto LABEL_3;
LABEL_16:
    mutex_lock(&list_lock);
    v13 = &connected_buffer_list;
    while ( 1 )
    {
      v13 = (__int64 *)*v13;
      if ( v13 == &connected_buffer_list )
        break;
      if ( *(v13 - 11) == identifier )
      {
        v14 = (__int64 *)v13[1];
        v15 = v13 - 22;
        if ( (__int64 *)*v14 == v13 && (v16 = *v13, *(__int64 **)(*v13 + 8) == v13) )
        {
          *(_QWORD *)(v16 + 8) = v14;
          *v14 = v16;
        }
        else
        {
          _list_del_entry_valid_or_report(v13);
          v15 = v26;
        }
        *v13 = 0xDEAD000000000100LL;
        v13[1] = 0xDEAD000000000122LL;
        kfree(v15, v12);
        if ( ifas_log_enable )
          printk(&unk_E9DE, "perfmgr_notify_connect_cb");
        break;
      }
    }
    v17 = mutex_unlock(&list_lock);
    v18 = (__int64 *)connected_buffer_list;
    if ( (__int64 *)connected_buffer_list == &connected_buffer_list )
    {
      do_maxfreq_release(v17);
    }
    else
    {
      v19 = ifas_log_enable;
      v20 = 0;
      do
      {
        ++v20;
        if ( v19 )
        {
          v17 = printk(&unk_F04C, "perfmgr_notify_connect_cb");
          v19 = ifas_log_enable;
        }
        v18 = (__int64 *)*v18;
      }
      while ( v18 != &connected_buffer_list );
      do_maxfreq_release(v17);
      if ( v20 >= 25 )
      {
        if ( v4 )
          ifas_enable = 0;
        mutex_lock(&list_lock);
        v22 = connected_buffer_list;
        if ( (__int64 *)connected_buffer_list != &connected_buffer_list )
        {
          do
          {
            v24 = *(__int64 **)v22;
            v23 = *(__int64 ***)(v22 + 8);
            if ( *v23 == (__int64 *)v22 && v24[1] == v22 )
            {
              v24[1] = (__int64)v23;
              *v23 = v24;
            }
            else
            {
              _list_del_entry_valid_or_report(v22);
            }
            *(_QWORD *)v22 = 0xDEAD000000000100LL;
            *(_QWORD *)(v22 + 8) = 0xDEAD000000000122LL;
            kfree(v22 - 176, v21);
            v22 = (__int64)v24;
          }
          while ( v24 != &connected_buffer_list );
        }
        mutex_unlock(&list_lock);
        if ( v4 )
          ifas_enable = 1;
        if ( ifas_log_enable )
          printk(&unk_F8D2, "perfmgr_notify_connect_cb");
      }
    }
    return 0;
  }
  if ( !connectedAPI )
    goto LABEL_16;
LABEL_3:
  v6 = &connected_buffer_list;
  while ( 1 )
  {
    v6 = (__int64 *)*v6;
    if ( v6 == &connected_buffer_list )
      break;
    if ( *(v6 - 11) == identifier )
    {
      if ( !ifas_log_enable )
        return 0;
      v7 = &unk_FC11;
      goto LABEL_14;
    }
  }
  v8 = (_QWORD *)_kmalloc_cache_noprof(mutex_lock, 3520, 192);
  if ( v8 )
  {
    v9 = (__int64 **)qword_D410;
    v8[23] = 0;
    v8[22] = 0;
    v10 = v8 + 22;
    v8[20] = 0;
    v8[21] = 0;
    v8[18] = 0;
    v8[19] = 0;
    v8[16] = 0;
    v8[17] = 0;
    v8[14] = 0;
    v8[15] = 0;
    v8[12] = 0;
    v8[13] = 0;
    v8[10] = 0;
    v8[11] = 0;
    v8[8] = 0;
    v8[9] = 0;
    v8[6] = 0;
    v8[7] = 0;
    v8[4] = 0;
    v8[5] = 0;
    v8[2] = 0;
    v8[3] = 0;
    *v8 = 0;
    v8[1] = 0;
    *(_DWORD *)v8 = pid;
    v8[11] = identifier;
    if ( v8 + 22 != &connected_buffer_list && v9 != (__int64 **)v10 && *v9 == &connected_buffer_list )
    {
      qword_D410 = (__int64)(v8 + 22);
      v8[22] = &connected_buffer_list;
      v8[23] = v9;
      *v9 = v10;
      if ( !ifas_log_enable )
        return 0;
      goto LABEL_13;
    }
    _list_add_valid_or_report(v8 + 22, v9, &connected_buffer_list);
    if ( ifas_log_enable )
    {
LABEL_13:
      v7 = &unk_10229;
LABEL_14:
      printk(v7, "perfmgr_notify_connect_cb");
      return 0;
    }
    return 0;
  }
  return -12;
}
