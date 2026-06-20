__int64 __fastcall wcnss_prealloc_get(unsigned __int64 a1)
{
  unsigned __int64 StatusReg; // x22
  unsigned int v3; // w20
  unsigned int v4; // w8
  int v5; // w9
  __int64 v6; // x24
  unsigned __int64 *v7; // x10
  __int64 v8; // x0
  __int64 v9; // x25
  __int64 v10; // x21
  __int64 v11; // x9
  __int64 v12; // x26
  __int64 *v13; // x9
  __int64 v14; // x10
  __int64 v15; // x8

  if ( !cnss_pools || mempool_initialization_done != 1 )
    return 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 || *(_DWORD *)(StatusReg + 16) )
  {
    v3 = 2336;
  }
  else
  {
    v3 = 2336;
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      if ( *(_DWORD *)(StatusReg + 1412) )
        v3 = 2336;
      else
        v3 = 3520;
    }
  }
  if ( *(_QWORD *)cnss_pools > a1 )
    goto LABEL_29;
  v4 = cnss_prealloc_pool_size;
  if ( !cnss_prealloc_pool_size )
    goto LABEL_29;
  v5 = 0;
  while ( 1 )
  {
    v6 = v5;
    v7 = (unsigned __int64 *)(cnss_pools + 96LL * v5);
    if ( *v7 < a1 || !v7[8] )
      goto LABEL_14;
    if ( !v7[10] )
    {
      printk(&unk_6C6F, (char *)v7 + 12);
      goto LABEL_29;
    }
    v8 = mempool_alloc_noprof(*(_QWORD *)(cnss_pools + 96LL * v5 + 64), v3);
    if ( v8 )
      break;
    v4 = cnss_prealloc_pool_size;
LABEL_14:
    v5 = v6 + 1;
    if ( (int)v6 + 1 >= v4 )
      goto LABEL_29;
  }
  v9 = v8;
  v10 = raw_spin_lock_irqsave(&pool_table_lock);
  v11 = cnss_pools + 96LL * (int)v6;
  v12 = *(int *)(v11 + 88);
  if ( (_DWORD)v12 )
  {
    v13 = *(__int64 **)(v11 + 80);
    v14 = v12;
    while ( *v13 )
    {
      --v14;
      ++v13;
      if ( !v14 )
        goto LABEL_23;
    }
    *v13 = v9;
    goto LABEL_26;
  }
LABEL_23:
  *(_QWORD *)(cnss_pools + 96 * v6 + 80) = krealloc_noprof(
                                             *(_QWORD *)(cnss_pools + 96LL * (int)v6 + 80),
                                             8LL * ((int)v12 + 1),
                                             2080);
  v15 = *(_QWORD *)(cnss_pools + 96 * v6 + 80);
  if ( v15 )
  {
    *(_QWORD *)(v15 + 8 * v12) = v9;
    ++*(_DWORD *)(cnss_pools + 96LL * (int)v6 + 88);
LABEL_26:
    raw_spin_unlock_irqrestore(&pool_table_lock, v10);
    return v9;
  }
  raw_spin_unlock_irqrestore(&pool_table_lock, v10);
  mempool_free(v9, *(_QWORD *)(cnss_pools + 96LL * (int)v6 + 64));
LABEL_29:
  if ( *(_QWORD *)cnss_pools <= a1 )
    printk(&unk_6AC6, a1);
  return 0;
}
