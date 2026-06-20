__int64 __fastcall ipa_uc_ntn_alloc_conn_smmu_info(__int64 a1, __int64 *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x8
  __int64 v7; // x10
  __int64 v8; // x11
  __int64 v9; // x8
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x8
  __int64 v13; // x10
  __int64 v14; // x11
  __int64 v15; // x21
  __int64 v16; // x0
  size_t v17; // x2
  unsigned int v18; // w0
  unsigned int v19; // w20
  __int64 result; // x0
  unsigned int v21; // w20
  unsigned __int64 StatusReg; // x22
  __int64 v23; // x23
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_uc_offload %s:%d Allocating smmu info\n", "ipa_uc_ntn_alloc_conn_smmu_info", 364);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa_uc_offload %s:%d Allocating smmu info\n",
      "ipa_uc_ntn_alloc_conn_smmu_info",
      364);
  }
  v6 = a2[3];
  v7 = *a2;
  v8 = a2[1];
  *(_QWORD *)(a1 + 16) = a2[2];
  *(_QWORD *)(a1 + 24) = v6;
  *(_QWORD *)a1 = v7;
  *(_QWORD *)(a1 + 8) = v8;
  v9 = a2[7];
  v10 = a2[4];
  v11 = a2[5];
  *(_QWORD *)(a1 + 48) = a2[6];
  *(_QWORD *)(a1 + 56) = v9;
  *(_QWORD *)(a1 + 32) = v10;
  *(_QWORD *)(a1 + 40) = v11;
  v12 = a2[11];
  v13 = a2[8];
  v14 = a2[9];
  *(_QWORD *)(a1 + 80) = a2[10];
  *(_QWORD *)(a1 + 88) = v12;
  *(_QWORD *)(a1 + 64) = v13;
  *(_QWORD *)(a1 + 72) = v14;
  v15 = *(unsigned int *)(a1 + 72);
  v16 = _kmalloc_noprof(16 * v15, 3520);
  *(_QWORD *)(a1 + 64) = v16;
  if ( v16 )
  {
    while ( 1 )
    {
      v17 = 16LL * *(unsigned int *)(a1 + 72);
      if ( 16 * v15 >= v17 )
        break;
      _fortify_panic(17, 16 * v15, v17);
      StatusReg = _ReadStatusReg(SP_EL0);
      v23 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &ipa_uc_ntn_alloc_conn_smmu_info__alloc_tag;
      v15 = *(unsigned int *)(a1 + 72);
      v24 = _kmalloc_noprof(16 * v15, 3520);
      *(_QWORD *)(StatusReg + 80) = v23;
      *(_QWORD *)(a1 + 64) = v24;
      if ( !v24 )
        goto LABEL_12;
    }
    memcpy(*(void **)(a1 + 64), (const void *)a2[8], v17);
    v18 = ipa_smmu_store_sgt((__int64 *)(a1 + 56), a2[7]);
    if ( v18 )
    {
      v19 = v18;
      kfree(*(_QWORD *)(a1 + 64));
      *(_QWORD *)(a1 + 64) = 0;
      return v19;
    }
    else
    {
      result = ipa_smmu_store_sgt((__int64 *)(a1 + 24), a2[3]);
      if ( (_DWORD)result )
      {
        v21 = result;
        kfree(*(_QWORD *)(a1 + 64));
        *(_QWORD *)(a1 + 64) = 0;
        ipa_smmu_free_sgt((_QWORD **)(a1 + 56));
        return v21;
      }
    }
  }
  else
  {
LABEL_12:
    printk(&unk_3B3749, "ipa_uc_ntn_alloc_conn_smmu_info");
    if ( ipa3_get_ipc_logbuf() )
    {
      v25 = ipa3_get_ipc_logbuf();
      ipc_log_string(v25, "ipa_uc_offload %s:%d failed to alloc smmu info\n", "ipa_uc_ntn_alloc_conn_smmu_info", 372);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v26 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v26, "ipa_uc_offload %s:%d failed to alloc smmu info\n", "ipa_uc_ntn_alloc_conn_smmu_info", 372);
    }
    return 4294967284LL;
  }
  return result;
}
