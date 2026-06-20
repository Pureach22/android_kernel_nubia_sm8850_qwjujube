__int64 ipa3_nat_ipv6ct_init_devices()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  _QWORD *v6; // x19
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x9
  int inited; // w8
  __int64 result; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0

  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d \n", "ipa3_nat_ipv6ct_init_devices", 478);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d \n", "ipa3_nat_ipv6ct_init_devices", 478);
      v0 = ipa3_ctx;
    }
    if ( v0 )
    {
      v3 = *(_QWORD *)(v0 + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d \n", "ipa3_nat_ipv6ct_allocate_tmp_memory", 321);
        v0 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v0 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d \n", "ipa3_nat_ipv6ct_allocate_tmp_memory", 321);
    }
  }
  v5 = _kmalloc_cache_noprof(kfree, 3520, 16);
  v6 = (_QWORD *)v5;
  if ( !v5 )
    goto LABEL_30;
  v7 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34216), 128, v5 + 8, 3520, 0);
  *v6 = v7;
  if ( !v7 )
  {
    kfree(v6);
LABEL_30:
    printk(&unk_3A9E71, "ipa3_nat_ipv6ct_init_devices");
    v17 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967284LL;
    v18 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v18 )
    {
      ipc_log_string(v18, "ipa %s:%d unable to allocate tmp_mem\n", "ipa3_nat_ipv6ct_init_devices", 487);
      v17 = ipa3_ctx;
    }
    v19 = *(_QWORD *)(v17 + 34160);
    if ( !v19 )
      return 4294967284LL;
    ipc_log_string(v19, "ipa %s:%d unable to allocate tmp_mem\n", "ipa3_nat_ipv6ct_init_devices", 487);
    return 4294967284LL;
  }
  v8 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(
        v9,
        "ipa %s:%d IPA successfully allocated temp memory\n",
        "ipa3_nat_ipv6ct_allocate_tmp_memory",
        333);
      v8 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v8 + 34160);
    if ( v10 )
    {
      ipc_log_string(
        v10,
        "ipa %s:%d IPA successfully allocated temp memory\n",
        "ipa3_nat_ipv6ct_allocate_tmp_memory",
        333);
      v8 = ipa3_ctx;
    }
  }
  v11 = *(_QWORD *)(v8 + 34176);
  *(_BYTE *)(v8 + 29864) = 1;
  if ( (unsigned int)ipa3_nat_ipv6ct_init_device(
                       v8 + 29528,
                       "ipaNatTable",
                       *(unsigned int *)(*(_QWORD *)v11 + 184LL),
                       *(unsigned int *)(*(_QWORD *)v11 + 180LL),
                       v6) )
  {
    printk(&unk_3B2678, "ipa3_nat_ipv6ct_init_devices");
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d unable to create nat device\n", "ipa3_nat_ipv6ct_init_devices", 498);
        v20 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
        ipc_log_string(v22, "ipa %s:%d unable to create nat device\n", "ipa3_nat_ipv6ct_init_devices", 498);
    }
  }
  else
  {
    if ( *(_DWORD *)(ipa3_ctx + 32240) < 0xEu )
      return 0;
    inited = ipa3_nat_ipv6ct_init_device(ipa3_ctx + 30080, "ipaIpv6CTTable", 0, 0, v6);
    result = 0;
    if ( !inited )
      return result;
    printk(&unk_3C9D32, "ipa3_nat_ipv6ct_init_devices");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d unable to create IPv6CT device\n", "ipa3_nat_ipv6ct_init_devices", 510);
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d unable to create IPv6CT device\n", "ipa3_nat_ipv6ct_init_devices", 510);
        v14 = ipa3_ctx;
      }
    }
    ipa3_nat_ipv6ct_destroy_device(v14 + 29528);
  }
  if ( *(_BYTE *)(ipa3_ctx + 29864) == 1 )
  {
    dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), 128, *v6, v6[1], 0);
    kfree(v6);
    *(_BYTE *)(ipa3_ctx + 29864) = 0;
  }
  return 4294967277LL;
}
