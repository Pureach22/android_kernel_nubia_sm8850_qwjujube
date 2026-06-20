void *__fastcall ipa3_replenish_rx_cache_recycle(_QWORD *a1)
{
  void *result; // x0
  unsigned int v3; // w26
  __int64 v4; // x10
  int v5; // w9
  unsigned int v6; // w8
  __int64 v7; // x23
  unsigned int v8; // w20
  const void ***v9; // x21
  _UNKNOWN **v10; // x25
  unsigned int v11; // w8
  const void **v12; // x22
  const void ***v13; // x8
  const void **v14; // x9
  unsigned int v15; // w28
  char *v16; // x8
  __int64 v17; // x9
  const void **v18; // x0
  __int64 (__fastcall *v19)(__int64, __int64); // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  _UNKNOWN **v23; // x27
  __int64 v24; // x26
  __int64 v25; // x24
  const char **v26; // x25
  char v27; // w0
  __int64 v28; // x0
  __int64 *v29; // x8
  __int64 v30; // x10
  int v31; // w0
  const char *v32; // x0
  const char *v33; // x2
  const void **v34; // x23
  _QWORD *v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  _QWORD *v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  int v41; // w19
  __int64 v42; // x8
  __int64 v43; // x0
  int v44; // w20
  _QWORD *v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  char v48; // [xsp+4h] [xbp-37Ch]
  _QWORD s[110]; // [xsp+10h] [xbp-370h] BYREF

  s[108] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = memset(s, 0, 0x360u);
  v3 = *(_DWORD *)a1;
  v4 = 1;
  v5 = *(_DWORD *)(a1[203] + 4LL);
  v6 = *((_DWORD *)a1 + 41);
  if ( v5 != 33 )
    v4 = 2;
  if ( v5 == 127 )
    v7 = 0;
  else
    v7 = v4;
  if ( v6 - v3 < 0x14 )
    goto LABEL_51;
  if ( v6 <= v3 )
  {
    v8 = 0;
LABEL_49:
    result = (void *)gsi_queue_xfer(*(_QWORD *)(a1[203] + 8LL), v8, s, 1);
    if ( (_DWORD)result )
    {
      v41 = (int)result;
      result = (void *)printk(&unk_3D5757, "ipa3_replenish_rx_cache_recycle");
      v42 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v43 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v43 )
        {
          ipc_log_string(v43, "ipa %s:%d failed to provide buffer: %d\n", "ipa3_replenish_rx_cache_recycle", 3701, v41);
          v42 = ipa3_ctx;
        }
        result = *(void **)(v42 + 34160);
        if ( result )
          result = (void *)ipc_log_string(
                             result,
                             "ipa %s:%d failed to provide buffer: %d\n",
                             "ipa3_replenish_rx_cache_recycle",
                             3701,
                             v41);
      }
      __break(0x800u);
    }
    else
    {
      *(_DWORD *)a1 = v3;
    }
    goto LABEL_51;
  }
  v8 = 0;
  v9 = (const void ***)(a1 + 206);
  v10 = &off_1F7000;
  _ReadStatusReg(SP_EL0);
  v11 = v3;
  while ( 1 )
  {
    v3 = v11;
    if ( *v9 == (const void **)v9 )
      break;
    raw_spin_lock_bh((char *)a1 + 1684);
    v12 = *v9;
    v13 = (const void ***)(*v9)[1];
    if ( *v13 == *v9 && (v14 = (const void **)*v12, *((const void ***)*v12 + 1) == v12) )
    {
      v14[1] = v13;
      *v13 = v14;
    }
    else
    {
      _list_del_entry_valid_or_report(*v9);
    }
    v15 = v3;
    *v12 = v12;
    v12[1] = v12;
    raw_spin_unlock_bh((char *)a1 + 1684);
    v16 = (char *)v10[257];
    v17 = 32992;
LABEL_20:
    ++*(_QWORD *)&v16[24 * v7 + v17];
    v22 = skb_put(v12[2], *((unsigned int *)a1 + 40));
    v23 = v10;
    v24 = *((unsigned int *)a1 + 40);
    v25 = v22;
    v26 = *((const char ***)v10[257] + 4277);
    v27 = is_vmalloc_addr(v22);
    if ( (v27 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
    {
      v48 = v27;
      dma_map_single_attrs___already_done = 1;
      v32 = (const char *)dev_driver_string(v26);
      v33 = v26[14];
      if ( !v33 )
        v33 = *v26;
      _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v32, v33);
      __break(0x800u);
      if ( (v48 & 1) != 0 )
      {
LABEL_35:
        v12[3] = (const void *)-1LL;
        v34 = v12 + 3;
LABEL_36:
        printk(&unk_3D288A, "ipa3_replenish_rx_cache_recycle");
        v35 = v23[257];
        if ( v35 )
        {
          v36 = v35[4269];
          if ( v36 )
          {
            ipc_log_string(
              v36,
              "ipa %s:%d dma_map_single failure %pK for %pK\n",
              "ipa3_replenish_rx_cache_recycle",
              3650,
              *v34,
              (const void *)v25);
            v35 = v23[257];
          }
          v37 = v35[4270];
          if ( v37 )
            ipc_log_string(
              v37,
              "ipa %s:%d dma_map_single failure %pK for %pK\n",
              "ipa3_replenish_rx_cache_recycle",
              3650,
              *v34,
              (const void *)v25);
        }
        raw_spin_lock_bh((char *)a1 + 1684);
        ipa3_skb_recycle(v12[2]);
        _list_add(v12, (_QWORD *)a1[207], (__int64)(a1 + 206));
        raw_spin_unlock_bh((char *)a1 + 1684);
        v3 = v15;
        goto LABEL_48;
      }
    }
    else if ( (v27 & 1) != 0 )
    {
      goto LABEL_35;
    }
    v28 = dma_map_page_attrs(
            v26,
            ((unsigned __int64)((v25 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
            v25 & 0xFFF,
            v24,
            2,
            0);
    v12[3] = (const void *)v28;
    if ( v28 == -1 )
    {
      v34 = v12 + 3;
      goto LABEL_36;
    }
    if ( v8 > 0x23 )
      __break(1u);
    v10 = v23;
    v29 = &s[3 * v8];
    v30 = (__int64)v23[257] + 24 * v7;
    ++v8;
    *((_WORD *)v29 + 4) = *((_DWORD *)a1 + 40);
    *v29 = v28;
    *((_WORD *)v29 + 5) = 1792;
    *((_DWORD *)v29 + 3) = 0;
    v29[2] = (__int64)v12;
    ++*(_QWORD *)(v30 + 33000);
    if ( v8 == 36 )
    {
      v31 = gsi_queue_xfer(*(_QWORD *)(a1[203] + 8LL), 36, s, 0);
      v8 = 0;
      if ( v31 )
      {
        v44 = v31;
        printk(&unk_3D5757, "ipa3_replenish_rx_cache_recycle");
        v45 = v23[257];
        v3 = v15 + 1;
        if ( v45 )
        {
          v46 = v45[4269];
          if ( v46 )
          {
            ipc_log_string(
              v46,
              "ipa %s:%d failed to provide buffer: %d\n",
              "ipa3_replenish_rx_cache_recycle",
              3673,
              v44);
            v45 = v23[257];
          }
          v47 = v45[4270];
          if ( v47 )
            ipc_log_string(
              v47,
              "ipa %s:%d failed to provide buffer: %d\n",
              "ipa3_replenish_rx_cache_recycle",
              3673,
              v44);
        }
        __break(0x800u);
        v8 = 36;
        goto LABEL_49;
      }
    }
    v11 = v15 + 1;
    if ( v15 + 1 >= *((_DWORD *)a1 + 41) )
    {
      v3 = v15 + 1;
      goto LABEL_49;
    }
  }
  v18 = (const void **)kmem_cache_alloc_noprof(*((_QWORD *)v10[257] + 3681), 10496);
  v12 = v18;
  if ( !v18 )
    goto LABEL_48;
  v18[6] = (const void *)0xFFFFFFFE00000LL;
  v18[7] = v18 + 7;
  v18[8] = v18 + 7;
  v19 = (__int64 (__fastcall *)(__int64, __int64))a1[17];
  v20 = *((unsigned int *)a1 + 40);
  v12[9] = ipa3_wq_rx_avail;
  v12[10] = a1;
  if ( *((_DWORD *)v19 - 1) != 993109518 )
    __break(0x8228u);
  v21 = v19(v20, 10240);
  v12[2] = (const void *)v21;
  if ( v21 )
  {
    v16 = (char *)v10[257];
    v15 = v3;
    v17 = 32984;
    goto LABEL_20;
  }
  printk(&unk_3CC773, "ipa3_replenish_rx_cache_recycle");
  v38 = v10[257];
  if ( v38 )
  {
    v39 = v38[4269];
    if ( v39 )
    {
      ipc_log_string(v39, "ipa %s:%d failed to alloc skb\n", "ipa3_replenish_rx_cache_recycle", 3627);
      v38 = v10[257];
    }
    v40 = v38[4270];
    if ( v40 )
    {
      ipc_log_string(v40, "ipa %s:%d failed to alloc skb\n", "ipa3_replenish_rx_cache_recycle", 3627);
      v38 = v10[257];
    }
  }
  kmem_cache_free(v38[3681], v12);
LABEL_48:
  if ( v3 )
    goto LABEL_49;
  result = (void *)queue_delayed_work_on(32, a1[219], a1 + 28, 1);
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
