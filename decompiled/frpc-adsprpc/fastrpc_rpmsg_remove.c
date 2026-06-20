__int64 __fastcall fastrpc_rpmsg_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  _QWORD *v3; // x26
  _QWORD *v4; // x25
  __int64 *v5; // x27
  __int64 *v6; // x24
  _QWORD *v7; // x9
  __int64 v8; // x0
  __int64 v9; // x22
  __int64 v10; // x21
  __int64 *v11; // x20
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 i; // x1
  __int64 *j; // x21
  __int64 result; // x0
  __int64 *v18; // x21
  _QWORD *v19; // x1
  _QWORD ***v20; // x0
  _QWORD *v21; // x8
  _QWORD *v22; // x22
  __int64 v23; // x0
  __int64 v24; // [xsp+0h] [xbp-50h]
  __int64 v25; // [xsp+8h] [xbp-48h]
  _QWORD v26[5]; // [xsp+10h] [xbp-40h] BYREF
  _QWORD *v27; // [xsp+38h] [xbp-18h] BYREF
  _QWORD ***v28; // [xsp+40h] [xbp-10h]
  __int64 v29; // [xsp+48h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 152);
  v25 = a1;
  v2 = *(_QWORD *)(v1 + 24);
  v27 = &v27;
  v3 = (_QWORD *)(v1 + 64040);
  v28 = (_QWORD ***)&v27;
  v4 = (_QWORD *)(v1 + 51392);
  dev_info(*(_QWORD *)(v1 + 168), "%s started", "fastrpc_rpmsg_remove");
  v24 = raw_spin_lock_irqsave(v1 + 51600);
  v5 = (__int64 *)(v1 + 51648);
  *(_DWORD *)(v1 + 64136) = 1;
  *(_BYTE *)(v2 + 50) = 0;
  *(_QWORD *)(v2 + 176) = 0;
  v6 = *(__int64 **)(v1 + 51648);
  *(_BYTE *)(v1 + 51670) = 0;
  if ( v6 != (__int64 *)(v1 + 51648) )
  {
    do
    {
      v18 = (__int64 *)*v6;
      if ( *((_DWORD *)v6 + 157) == 2 )
      {
        if ( (unsigned int)fastrpc_file_get((__int64)v6) )
        {
          dev_warn(
            *(_QWORD *)(v1 + 168),
            "Warning: %s: user-obj for fl (%pK) being released\n",
            "fastrpc_rpmsg_remove",
            v6);
        }
        else
        {
          v19 = v28;
          v20 = (_QWORD ***)(v6 + 81);
          if ( v6 + 81 == (__int64 *)&v27 || v28 == v20 || *v28 != &v27 )
          {
            _list_add_valid_or_report(v20, v28, &v27);
          }
          else
          {
            v28 = (_QWORD ***)(v6 + 81);
            v6[81] = (__int64)&v27;
            v6[82] = (__int64)v19;
            *v19 = v20;
          }
        }
      }
      v6 = v18;
    }
    while ( v18 != v5 );
  }
  raw_spin_unlock_irqrestore(v1 + 51600, v24);
  complete_all(v1 + 64264);
  frpc_coredump(v1, &v27);
  v7 = v27;
  if ( v27 != &v27 )
  {
    do
    {
      v22 = (_QWORD *)*v7;
      v21 = (_QWORD *)v7[1];
      if ( (_QWORD *)*v21 == v7 && (_QWORD *)v22[1] == v7 )
      {
        v22[1] = v21;
        *v21 = v22;
      }
      else
      {
        _list_del_entry_valid_or_report(v7);
      }
      *v7 = 0xDEAD000000000100LL;
      v7[1] = 0xDEAD000000000122LL;
      fastrpc_file_put(v7 - 81, 1);
      v7 = v22;
    }
    while ( v22 != &v27 );
  }
  v8 = raw_spin_lock_irqsave(v1 + 51600);
  v9 = *v5;
  v10 = v8;
  if ( (__int64 *)*v5 != v5 )
  {
    do
    {
      v11 = *(__int64 **)v9;
      fastrpc_queue_pd_status(v9, *(_DWORD *)v1, 4, *(_DWORD *)(v9 + 284));
      fastrpc_notify_users(v9);
      v9 = (__int64)v11;
    }
    while ( v11 != v5 );
  }
  raw_spin_unlock_irqrestore(v1 + 51600, v10);
  v12 = *(_QWORD *)(v1 + 52704);
  if ( v12 )
  {
    misc_deregister(v12 + 8);
    v13 = *(_QWORD *)(v1 + 52712);
    if ( !v13 )
    {
LABEL_7:
      v14 = *(_QWORD *)(v1 + 52720);
      if ( !v14 )
        goto LABEL_8;
      goto LABEL_39;
    }
  }
  else
  {
    v13 = *(_QWORD *)(v1 + 52712);
    if ( !v13 )
      goto LABEL_7;
  }
  misc_deregister(v13 + 8);
  v14 = *(_QWORD *)(v1 + 52720);
  if ( !v14 )
  {
LABEL_8:
    if ( !*v4 )
      goto LABEL_9;
    goto LABEL_40;
  }
LABEL_39:
  misc_deregister(v14 + 8);
  if ( !*v4 )
  {
LABEL_9:
    if ( !*(_QWORD *)(v1 + 51448) )
      goto LABEL_10;
    goto LABEL_41;
  }
LABEL_40:
  pdr_handle_release();
  if ( !*(_QWORD *)(v1 + 51448) )
  {
LABEL_10:
    if ( !*(_QWORD *)(v1 + 51504) )
      goto LABEL_11;
    goto LABEL_42;
  }
LABEL_41:
  pdr_handle_release();
  if ( !*(_QWORD *)(v1 + 51504) )
  {
LABEL_11:
    if ( !*(_QWORD *)(v1 + 51560) )
      goto LABEL_13;
    goto LABEL_12;
  }
LABEL_42:
  pdr_handle_release();
  if ( *(_QWORD *)(v1 + 51560) )
LABEL_12:
    pdr_handle_release();
LABEL_13:
  for ( i = raw_spin_lock_irqsave(v1 + 51600); *(_DWORD *)(v1 + 64180); i = raw_spin_lock_irqsave(v1 + 51600) )
  {
    raw_spin_unlock_irqrestore(v1 + 51600, i);
    if ( *(_DWORD *)(v1 + 64180) )
    {
      memset(v26, 0, sizeof(v26));
      init_wait_entry(v26, 0);
      while ( 1 )
      {
        v23 = prepare_to_wait_event(v1 + 64216, v26, 1);
        if ( !*(_DWORD *)(v1 + 64180) )
          break;
        if ( v23 )
          goto LABEL_46;
        schedule();
      }
      finish_wait(v1 + 64216, v26);
    }
LABEL_46:
    ;
  }
  raw_spin_unlock_irqrestore(v1 + 51600, i);
  for ( j = (__int64 *)*v5; j != v5; j = (__int64 *)*j )
    fastrpc_free_user(j);
  mutex_lock(v1 + 64056);
  if ( *(_QWORD *)(v1 + 64048) )
  {
    wakeup_source_unregister();
    *(_QWORD *)(v1 + 64048) = 0;
  }
  if ( *v3 )
  {
    wakeup_source_unregister();
    *v3 = 0;
  }
  mutex_unlock(v1 + 64056);
  dev_info(*(_QWORD *)(v1 + 168), "Closing rpmsg channel for %s", (const char *)(*(_QWORD *)(v1 + 24) + 20LL));
  kfree(*(_QWORD *)(v1 + 52728));
  of_platform_depopulate(v25);
  fastrpc_mmap_remove_ssr(v1, 0);
  *(_QWORD *)(v1 + 24) = 0;
  *(_QWORD *)(v1 + 160) = 0;
  *(_QWORD *)(v1 + 168) = 0;
  complete_all(v1 + 64184);
  result = fastrpc_channel_ctx_put(v1);
  _ReadStatusReg(SP_EL0);
  return result;
}
