__int64 __fastcall rmnet_wlan_add_fwd_info(unsigned __int64 *a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 lock; // x0
  int v6; // w8
  __int64 *v7; // x9
  int v8; // w10
  _QWORD *v9; // x20
  __int64 v10; // x0
  unsigned int v11; // w22
  unsigned __int64 *i; // x21
  unsigned __int64 v13; // x10
  unsigned __int64 v14; // x22
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x9
  const char *v17; // x0
  size_t v18; // x0
  unsigned __int64 v19; // x2
  unsigned int v20; // w0
  _QWORD *v21; // x20
  unsigned __int64 *v22; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v25; // x25
  __int64 (__fastcall *v26)(_QWORD); // x0
  _QWORD *v27; // x20

  v4 = mutex_lock(&rmnet_wlan_fwd_mutex);
  lock = _rcu_read_lock(v4);
  v6 = *((_DWORD *)a1 + 2);
  v7 = (__int64 *)rmnet_wlan_fwd_hash[(unsigned int)(1640531527 * v6) >> 28];
  if ( v7 )
  {
    v8 = *((unsigned __int8 *)a1 + 24);
    do
    {
      if ( *((unsigned __int8 *)v7 + 96) == v8 )
      {
        if ( v8 == 4 )
        {
          if ( *((_DWORD *)v7 + 20) == v6 )
          {
LABEL_8:
            v9 = *(_QWORD **)(a2 + 64);
            v10 = do_trace_netlink_extack("FWD information already present");
            if ( v9 )
              *v9 = "FWD information already present";
            _rcu_read_unlock(v10);
            v11 = -17;
            goto LABEL_28;
          }
        }
        else if ( a1[1] == v7[10] )
        {
          goto LABEL_8;
        }
      }
      v7 = (__int64 *)*v7;
    }
    while ( v7 );
  }
  _rcu_read_unlock(lock);
  for ( i = (unsigned __int64 *)_kmalloc_cache_noprof(dst_release, 3520, 104); i; *(_QWORD *)(StatusReg + 80) = v25 )
  {
    v14 = *a1;
    v13 = a1[1];
    v15 = a1[2];
    v16 = a1[3];
    v17 = (const char *)(*a1 + 296);
    i[9] = 0;
    i[10] = v13;
    i[11] = v15;
    i[12] = v16;
    v18 = strnlen(v17, 0x10u);
    if ( v18 >= 0x11 )
    {
      _fortify_panic(2, 16, v18 + 1);
    }
    else
    {
      if ( v18 == 16 )
        v19 = 16;
      else
        v19 = v18 + 1;
      if ( v19 < 0x11 )
      {
        sized_strscpy(i + 7, v14 + 296);
        i[4] = (unsigned __int64)rmnet_wlan_fwd_info_notifier;
        v20 = register_netdevice_notifier(i + 4);
        if ( v20 )
        {
          v21 = *(_QWORD **)(a2 + 64);
          v11 = v20;
          do_trace_netlink_extack("Registering FWD notifier failed");
          if ( v21 )
            *v21 = "Registering FWD notifier failed";
          kfree(i);
        }
        else
        {
          v11 = 0;
          v22 = &rmnet_wlan_fwd_hash[(unsigned int)(1640531527 * *((_DWORD *)a1 + 2)) >> 28];
          v23 = *v22;
          *i = *v22;
          i[1] = (unsigned __int64)v22;
          atomic_store((unsigned __int64)i, v22);
          if ( v23 )
            *(_QWORD *)(v23 + 8) = i;
        }
        goto LABEL_28;
      }
    }
    _fortify_panic(7, 16, v19);
    StatusReg = _ReadStatusReg(SP_EL0);
    v25 = *(_QWORD *)(StatusReg + 80);
    v26 = dst_release;
    *(_QWORD *)(StatusReg + 80) = &_rmnet_wlan_add_fwd_info__alloc_tag;
    i = (unsigned __int64 *)_kmalloc_cache_noprof(v26, 3520, 104);
  }
  v27 = *(_QWORD **)(a2 + 64);
  do_trace_netlink_extack("Cannot allocate FWD context");
  if ( v27 )
    *v27 = "Cannot allocate FWD context";
  v11 = -12;
LABEL_28:
  mutex_unlock(&rmnet_wlan_fwd_mutex);
  return v11;
}
