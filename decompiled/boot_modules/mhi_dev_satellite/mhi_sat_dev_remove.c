__int64 __fastcall mhi_sat_dev_remove(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 *v2; // x19
  __int64 v3; // x22
  _QWORD *v4; // x8
  __int64 v5; // x9
  _QWORD *v6; // x24
  __int64 v7; // x0
  __int64 v8; // x20
  __int16 v9; // w8
  __int64 v10; // x10
  __int16 v11; // w8
  int v12; // w21
  bool v13; // zf
  int v14; // w8
  _QWORD *v15; // x24
  bool v16; // zf
  int v17; // w20
  __int64 v18; // x0
  int v19; // w0
  int v20; // w21
  __int64 *v21; // x20
  __int64 *v22; // x24
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x0
  __int64 **v26; // x8
  __int64 *v27; // x9
  __int64 **v28; // x8
  __int64 *v29; // x9

  v1 = *(_QWORD **)(a1 + 192);
  v2 = (__int64 *)v1[3];
  v3 = v2[3];
  mutex_lock(v2 + 8);
  v4 = (_QWORD *)v1[1];
  if ( (_QWORD *)*v4 == v1 && (v5 = *v1, *(_QWORD **)(*v1 + 8LL) == v1) )
  {
    *(_QWORD *)(v5 + 8) = v4;
    *v4 = v5;
  }
  else
  {
    _list_del_entry_valid_or_report(v1);
  }
  *v1 = 0xDEAD000000000100LL;
  v1[1] = 0xDEAD000000000122LL;
  mutex_unlock(v2 + 8);
  --*((_DWORD *)v2 + 62);
  mutex_lock(v3 + 32);
  cancel_work_sync(v2 + 25);
  raw_spin_lock_irq(v2 + 33);
  if ( (*((_DWORD *)v2 + 65) | 2) != 3 )
  {
    *((_DWORD *)v2 + 65) = 4;
    raw_spin_unlock_irq(v2 + 33);
    if ( *((_DWORD *)v2 + 62) )
      return mutex_unlock(v3 + 32);
    goto LABEL_42;
  }
  *((_DWORD *)v2 + 65) = 4;
  raw_spin_unlock_irq(v2 + 33);
  v6 = (_QWORD *)v2[3];
  flush_work(v2 + 17);
  flush_work(v2 + 21);
  v7 = _kmalloc_cache_noprof(_mhi_driver_register, 3264, 40);
  if ( !v7 )
  {
    if ( v2 && v6 )
    {
      printk(&unk_8901, "mhi_sat_send_sys_err", *v6, *((unsigned int *)v2 + 58));
      ipc_log_string(
        v6[11],
        "%s[E][%s][%x] Unable to malloc for SYS_ERR message!\n",
        (const char *)&unk_8360,
        "mhi_sat_send_sys_err",
        *((_DWORD *)v2 + 58));
      if ( *((_DWORD *)v2 + 62) )
        return mutex_unlock(v3 + 32);
    }
    else if ( *((_DWORD *)v2 + 62) )
    {
      return mutex_unlock(v3 + 32);
    }
    goto LABEL_42;
  }
  v8 = v7;
  *(_QWORD *)(v7 + 24) = 0;
  *(_QWORD *)(v7 + 32) = 0xFF000000000000LL;
  mutex_lock(v2 + 39);
  v9 = *((_WORD *)v2 + 128);
  v10 = v2[3];
  if ( v9 == -2 )
    v11 = 0;
  else
    v11 = v9 + 1;
  *((_WORD *)v2 + 128) = v11;
  *(_DWORD *)v8 = 1;
  *(_WORD *)(v8 + 4) = 12;
  *(_WORD *)(v8 + 6) = v11;
  *(_DWORD *)(v8 + 8) = 1114111;
  *(_DWORD *)(v8 + 12) = *((_DWORD *)v2 + 58);
  *((_WORD *)v2 + 134) = v11;
  v12 = rpmsg_send(*(_QWORD *)(*(_QWORD *)(v10 + 8) + 968LL), v8, 40);
  kfree(v8);
  if ( v2 )
    v13 = v6 == nullptr;
  else
    v13 = 1;
  v14 = !v13;
  if ( v12 )
  {
    if ( v14 )
    {
      printk(&unk_837B, "mhi_sat_send_sys_err", *v6, *((unsigned int *)v2 + 58));
      ipc_log_string(
        v6[11],
        "%s[E][%s][%x] Failed to notify SYS_ERR cmd\n",
        (const char *)&unk_8360,
        "mhi_sat_send_sys_err",
        *((_DWORD *)v2 + 58));
    }
  }
  else
  {
    if ( v14 )
      ipc_log_string(
        v6[11],
        "%s[I][%s][%x] SYS_ERR command sent\n",
        (const char *)&unk_8360,
        "mhi_sat_send_sys_err",
        *((_DWORD *)v2 + 58));
    v15 = (_QWORD *)v2[3];
    *((_DWORD *)v2 + 70) = 0;
    if ( v2 )
      v16 = v15 == nullptr;
    else
      v16 = 1;
    v17 = !v16;
    if ( !v16 )
      ipc_log_string(
        v15[11],
        "%s[I][%s][%x] Wait for command completion\n",
        (const char *)&unk_8360,
        "mhi_sat_wait_cmd_completion",
        *((_DWORD *)v2 + 58));
    v18 = _msecs_to_jiffies(*(unsigned int *)(v2[2] + 328));
    v19 = wait_for_completion_timeout(v2 + 35, v18);
    if ( v19 && *((_DWORD *)v2 + 68) == 1 )
    {
      if ( v17 )
        ipc_log_string(
          v15[11],
          "%s[I][%s][%x] Command completion successful for seq:%u\n",
          (const char *)&unk_8360,
          "mhi_sat_wait_cmd_completion",
          *((_DWORD *)v2 + 58),
          *((unsigned __int16 *)v2 + 134));
    }
    else if ( v17 )
    {
      v20 = v19;
      printk(&unk_8676, "mhi_sat_wait_cmd_completion", *v15, *((unsigned int *)v2 + 58));
      ipc_log_string(
        v15[11],
        "%s[E][%s][%x] Command completion failure:seq:%u:ret:%d:ccs:%d\n",
        (const char *)&unk_8360,
        "mhi_sat_wait_cmd_completion",
        *((_DWORD *)v2 + 58),
        *((unsigned __int16 *)v2 + 134),
        v20,
        *((_DWORD *)v2 + 68));
    }
  }
  mutex_unlock(v2 + 39);
  if ( !*((_DWORD *)v2 + 62) )
  {
LABEL_42:
    cancel_work_sync(v2 + 17);
    cancel_work_sync(v2 + 21);
    mutex_lock(v2 + 8);
    v21 = (__int64 *)v2[6];
    if ( v21 != v2 + 6 )
    {
      do
      {
        v22 = (__int64 *)*v21;
        v23 = v21[4];
        v24 = v21[6];
        v25 = *(_QWORD *)(*(_QWORD *)(v2[2] + 16) + 136LL);
        if ( *((_BYTE *)v21 + 56) == 1 )
          dma_unmap_resource(v25, v23, v24, 0, 0);
        else
          dma_unmap_page_attrs(v25, v23, v24, 0, 32);
        v26 = (__int64 **)v21[1];
        if ( *v26 == v21 && (v27 = (__int64 *)*v21, *(__int64 **)(*v21 + 8) == v21) )
        {
          v27[1] = (__int64)v26;
          *v26 = v27;
        }
        else
        {
          _list_del_entry_valid_or_report(v21);
        }
        *v21 = 0xDEAD000000000100LL;
        v21[1] = 0xDEAD000000000122LL;
        kfree(v21);
        v21 = v22;
      }
      while ( v22 != v2 + 6 );
    }
    mutex_unlock(v2 + 8);
    raw_spin_lock_irq(v3 + 80);
    v28 = (__int64 **)v2[1];
    if ( *v28 == v2 && (v29 = (__int64 *)*v2, *(__int64 **)(*v2 + 8) == v2) )
    {
      v29[1] = (__int64)v28;
      *v28 = v29;
    }
    else
    {
      _list_del_entry_valid_or_report(v2);
    }
    *v2 = 0xDEAD000000000100LL;
    v2[1] = 0xDEAD000000000122LL;
    raw_spin_unlock_irq(v3 + 80);
    if ( v2 && v3 )
      ipc_log_string(
        *(_QWORD *)(v3 + 88),
        "%s[I][%s][%x] Satellite controller node removed\n",
        (const char *)&unk_8360,
        "mhi_sat_dev_remove",
        *((_DWORD *)v2 + 58));
    kfree(v2);
  }
  return mutex_unlock(v3 + 32);
}
