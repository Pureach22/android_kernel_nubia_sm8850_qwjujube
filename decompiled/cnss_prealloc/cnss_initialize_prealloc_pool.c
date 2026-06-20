__int64 __fastcall cnss_initialize_prealloc_pool(__int64 a1)
{
  int v2; // w8
  _UNKNOWN **v3; // x10
  int v4; // w9
  __int64 v5; // x22
  __int64 v6; // x24
  unsigned int v7; // t1
  __int64 result; // x0
  __int64 v9; // x24
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v13; // [xsp+10h] [xbp-20h]
  __int64 v14; // [xsp+14h] [xbp-1Ch]
  __int64 v15; // [xsp+1Ch] [xbp-14h]
  int v16; // [xsp+24h] [xbp-Ch]
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_6B85, a1);
  switch ( a1 )
  {
    case 43981LL:
      v2 = 5;
      v3 = &cnss_pools_adrastea;
      break;
    case 30544LL:
      v2 = 6;
      v3 = &cnss_pools_wcn7750;
      break;
    case 26448LL:
      v2 = 5;
      v3 = &cnss_pools_wcn6750;
      break;
    default:
      v2 = 6;
      v3 = &cnss_pools_default;
      break;
  }
  v4 = 0;
  cnss_pools = (__int64)v3;
  cnss_prealloc_pool_size = v2;
  _ReadStatusReg(SP_EL0);
  do
  {
    v5 = v4;
    v6 = 96LL * v4;
    v7 = *(_DWORD *)(cnss_pools + v6);
    v12 = 0;
    v14 = 0;
    v15 = 0;
    v13 = v7;
    v16 = 0;
    *(_QWORD *)(cnss_pools + v6 + 72) = _kmem_cache_create_args(cnss_pools + v6 + 12, v7, &v12, 0x2000);
    if ( *(_QWORD *)(cnss_pools + v6 + 72) )
    {
      v9 = 96 * v5;
      *(_QWORD *)(cnss_pools + 96 * v5 + 64) = mempool_create_node_noprof(
                                                 *(unsigned int *)(cnss_pools + 96LL * (int)v5 + 8),
                                                 &mempool_alloc_slab,
                                                 &mempool_free_slab,
                                                 *(_QWORD *)(cnss_pools + 96LL * (int)v5 + 72),
                                                 3264,
                                                 0xFFFFFFFFLL);
      v10 = cnss_pools + 96 * v5;
      if ( *(_QWORD *)(v10 + 64) )
      {
        *(_DWORD *)(v10 + 88) = *(_DWORD *)(v10 + 8);
        *(_QWORD *)(cnss_pools + v9 + 80) = _kmalloc_noprof(8LL * *(int *)(cnss_pools + 96LL * (int)v5 + 8), 3520);
        v11 = cnss_pools;
        if ( !*(_QWORD *)(cnss_pools + v9 + 80) )
        {
          printk(&unk_6AFC, cnss_pools + v9 + 12);
          __break(0x800u);
          v11 = cnss_pools;
        }
        result = printk(&unk_6C11, v11 + 96LL * (int)v5 + 12);
      }
      else
      {
        printk(&unk_6C4B, v10 + 12);
        result = kmem_cache_destroy(*(_QWORD *)(cnss_pools + v9 + 72));
        *(_QWORD *)(cnss_pools + v9 + 72) = 0;
      }
    }
    else
    {
      result = printk(&unk_6BE0, cnss_pools + v6 + 12);
    }
    v4 = v5 + 1;
  }
  while ( (int)v5 + 1 < (unsigned int)cnss_prealloc_pool_size );
  mempool_initialization_done = 1;
  pool_table_lock = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
