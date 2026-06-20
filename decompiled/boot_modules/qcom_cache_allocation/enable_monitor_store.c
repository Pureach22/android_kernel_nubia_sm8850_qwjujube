__int64 __fastcall enable_monitor_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  char v6; // w8
  unsigned int partition; // w0
  unsigned int v8; // w0
  __int64 v9; // x0
  _DWORD *v10; // x8
  _DWORD *v11; // x9
  int v12; // w21
  __int64 v13; // x0
  __int64 v15; // x2
  void *v16; // x0
  _BYTE v17[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v17[0] = 0;
  if ( (unsigned int)kstrtobool(a3, v17) )
  {
    a4 = -22;
LABEL_9:
    _ReadStatusReg(SP_EL0);
    return a4;
  }
  mutex_lock(v5 + 192);
  v6 = v17[0];
  *(_BYTE *)(v5 + 52) = v17[0];
  *(_BYTE *)(v5 + 53) = v6;
  mutex_unlock(v5 + 192);
  if ( *(_BYTE *)(v5 + 52) == 1 )
  {
    partition = msc_system_get_partition(2, &msc_queries, *(_QWORD *)(v5 + 72));
    if ( (partition & 0x80000000) != 0 )
    {
      v15 = partition;
      v16 = &unk_AC2F;
    }
    else
    {
      v8 = msc_system_get_partition(2, &unk_D40, *(_QWORD *)(v5 + 72) + 4LL);
      if ( (v8 & 0x80000000) == 0 )
      {
LABEL_6:
        v9 = _msecs_to_jiffies(*(unsigned int *)(v5 + 80));
        queue_delayed_work_on(32, system_wq, v5 + 88, v9);
        goto LABEL_9;
      }
      v15 = v8;
      v16 = &unk_ABB7;
    }
    printk(v16, "save_gear_for_client", v15);
    goto LABEL_6;
  }
  mutex_lock(v5 + 192);
  v11 = *(_DWORD **)(v5 + 64);
  v10 = *(_DWORD **)(v5 + 72);
  *(_DWORD *)(v5 + 48) = 0;
  *(_DWORD *)(v5 + 256) = 0;
  *v11 = *v10;
  *(_DWORD *)(*(_QWORD *)(v5 + 64) + 4LL) = *(_DWORD *)(*(_QWORD *)(v5 + 72) + 4LL);
  v12 = cache_allocation_configure(v5);
  v13 = mutex_unlock(v5 + 192);
  if ( (v12 & 0x80000000) == 0 )
  {
    cancel_delayed_work_sync(v5 + 88);
    goto LABEL_9;
  }
  __break(0x800u);
  return cache_allocation_configure(v13);
}
