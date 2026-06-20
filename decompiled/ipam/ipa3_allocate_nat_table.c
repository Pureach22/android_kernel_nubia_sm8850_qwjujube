__int64 __fastcall ipa3_allocate_nat_table(_QWORD *a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  int mem; // w0
  unsigned int v7; // w19
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  int v15; // w23
  __int64 v16; // x1
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x2
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  unsigned int v27; // w8
  _QWORD *v28; // x9
  _QWORD *v29; // x23
  __int64 v30; // x2
  __int64 v31; // x0
  _QWORD *v32; // x23
  __int64 v33; // t1
  _QWORD v34[2]; // [xsp+0h] [xbp-10h] BYREF

  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    v4 = ipa3_ctx;
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d table size:%lu offset:%lu\n", "ipa3_allocate_nat_table", 747, *a1, a1[1]);
      v4 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v4 + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d table size:%lu offset:%lu\n", "ipa3_allocate_nat_table", 747, *a1, a1[1]);
  }
  mutex_lock(v2 + 29544);
  mem = ipa3_nat_ipv6ct_allocate_mem(v2 + 29528, a1, 0);
  if ( mem )
    goto LABEL_7;
  v9 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 32240) < 0xEu || *(_QWORD *)(v2 + 29840) )
  {
LABEL_10:
    if ( v9 )
    {
      v10 = *(_QWORD *)(v9 + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d IPA NAT dev init successfully\n", "ipa3_allocate_nat_table", 794);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d IPA NAT dev init successfully\n", "ipa3_allocate_nat_table", 794);
    }
    mutex_unlock(v2 + 29544);
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d return\n", "ipa3_allocate_nat_table", 798);
        v12 = ipa3_ctx;
      }
      result = *(_QWORD *)(v12 + 34160);
      if ( !result )
        goto LABEL_21;
      ipc_log_string(result, "ipa %s:%d return\n", "ipa3_allocate_nat_table", 798);
    }
    result = 0;
LABEL_21:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v34[0] = 0;
  v14 = ipahal_nat_entry_size(2, v34);
  v15 = v34[0];
  v16 = (unsigned int)ipa3_get_max_pdn(v14) * v15;
  *(_DWORD *)(v2 + 29856) = v16;
  if ( *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 292LL) < (unsigned int)v16 )
  {
    v20 = printk(&unk_3D2E83, "ipa3_allocate_nat_table");
    v23 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(
          v24,
          "ipa %s:%d number of PDN entries exceeds SRAM available space\n",
          "ipa3_allocate_nat_table",
          773);
        v23 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v23 + 34160);
      if ( v20 )
        v20 = ipc_log_string(
                v20,
                "ipa %s:%d number of PDN entries exceeds SRAM available space\n",
                "ipa3_allocate_nat_table",
                773);
    }
  }
  else
  {
    v17 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34216), v16, v2 + 29848, 3520, 0);
    *(_QWORD *)(v2 + 29840) = v17;
    if ( v17 )
    {
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v18 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v18 )
        {
          ipc_log_string(
            v18,
            "ipa %s:%d IPA NAT dev allocated PDN memory successfully\n",
            "ipa3_allocate_nat_table",
            791);
          v9 = ipa3_ctx;
        }
        v19 = *(_QWORD *)(v9 + 34160);
        if ( v19 )
        {
          ipc_log_string(
            v19,
            "ipa %s:%d IPA NAT dev allocated PDN memory successfully\n",
            "ipa3_allocate_nat_table",
            791);
          v9 = ipa3_ctx;
        }
      }
      goto LABEL_10;
    }
    v20 = printk(&unk_3BE334, "ipa3_allocate_nat_table");
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d fail to allocate PDN memory\n", "ipa3_allocate_nat_table", 786);
        v25 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v25 + 34160);
      if ( v20 )
        v20 = ipc_log_string(v20, "ipa %s:%d fail to allocate PDN memory\n", "ipa3_allocate_nat_table", 786);
    }
  }
  v27 = *(_DWORD *)(v2 + 29868);
  if ( v27 < 3 )
  {
    v28 = (_QWORD *)(v2 + 96LL * v27);
    v29 = v28 + 3736;
    if ( !v27 )
    {
      v30 = v28[3738];
      if ( !v30 )
        goto LABEL_46;
      dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), v28[3741], v30, v28[3739], 0);
      v27 = *(_DWORD *)(v2 + 29868);
      v29[2] = 0;
    }
    if ( v27 == 1 )
    {
      v33 = v29[1];
      v32 = v29 + 1;
      v31 = v33;
      if ( v33 )
      {
        iounmap(v31);
        mem = -12;
        *v32 = 0;
        v32[1] = 0;
LABEL_7:
        v7 = mem;
        mutex_unlock(v2 + 29544);
        result = v7;
        goto LABEL_21;
      }
    }
LABEL_46:
    mem = -12;
    goto LABEL_7;
  }
  __break(0x5512u);
  return ipa3_nat_ipv6ct_allocate_mem(v20, v21, v22);
}
