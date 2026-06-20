__int64 ipa3_alloc_pkt_init()
{
  __int64 v0; // x19
  unsigned __int16 *v1; // x0
  __int64 v2; // x22
  __int64 v3; // x8
  __int64 v4; // x1
  _QWORD *v5; // x19
  __int64 v6; // x0
  size_t v7; // x3
  __int64 v8; // x23
  unsigned __int16 *v9; // x0
  unsigned __int16 *v10; // x20
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  v21 = 0;
  v1 = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, int *, _QWORD))ipahal_construct_imm_cmd)(10, &v21, 0);
  if ( !v1 )
  {
    printk(&unk_3FA63B, "ipa3_alloc_pkt_init");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d failed to construct IMM cmd\n", "ipa3_alloc_pkt_init", 8839);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d failed to construct IMM cmd\n", "ipa3_alloc_pkt_init", 8839);
        result = 4294967284LL;
        goto LABEL_9;
      }
    }
LABEL_26:
    result = 4294967284LL;
    goto LABEL_9;
  }
  v2 = v0 + 49152;
  v3 = ipa3_ctx + 0x8000;
  *(_DWORD *)(ipa3_ctx + 34600) = v1[1];
  *(_DWORD *)(v0 + 50176) = *(_DWORD *)(v3 + 1540) * *v1;
  kfree(v1);
  v4 = *(unsigned int *)(v0 + 50176);
  v5 = (_QWORD *)(v0 + 50168);
  v6 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34216), v4, v2 + 1016, 3264, 0);
  v7 = *(unsigned int *)(v2 + 1024);
  *(_QWORD *)(v2 + 1008) = v6;
  if ( !v6 )
  {
    printk(&unk_3DDABF, "ipa3_alloc_pkt_init");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(
          v16,
          "ipa %s:%d failed to alloc DMA buff of size %d\n",
          "ipa3_alloc_pkt_init",
          8849,
          *(_DWORD *)(v2 + 1024));
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
      {
        ipc_log_string(
          v17,
          "ipa %s:%d failed to alloc DMA buff of size %d\n",
          "ipa3_alloc_pkt_init",
          8849,
          *(_DWORD *)(v2 + 1024));
        result = 4294967284LL;
        goto LABEL_9;
      }
    }
    goto LABEL_26;
  }
  memset(*(void **)(v2 + 1008), 0, v7);
  if ( *(_DWORD *)(ipa3_ctx + 34308) )
  {
    v8 = 0;
    while ( 1 )
    {
      v21 = v8;
      v9 = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, int *, _QWORD))ipahal_construct_imm_cmd)(10, &v21, 0);
      if ( !v9 )
        break;
      v10 = v9;
      memcpy((void *)(*(_QWORD *)(v2 + 1008) + (int)(v8 * *v9)), v9 + 2, *v9);
      if ( v8 == 36 )
        __break(0x5512u);
      *(_QWORD *)(ipa3_ctx + 8 * v8 + 34312) = *v5 + v8 * *v10;
      kfree(v10);
      if ( ++v8 >= (unsigned __int64)*(unsigned int *)(ipa3_ctx + 34308) )
        goto LABEL_8;
    }
    printk(&unk_3FA63B, "ipa3_alloc_pkt_init");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d failed to construct IMM cmd\n", "ipa3_alloc_pkt_init", 8859);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d failed to construct IMM cmd\n", "ipa3_alloc_pkt_init", 8859);
        v18 = ipa3_ctx;
      }
    }
    dma_free_attrs(
      *(_QWORD *)(v18 + 34216),
      *(unsigned int *)(v2 + 1024),
      *(_QWORD *)(v2 + 1008),
      *(_QWORD *)(v2 + 1016),
      0);
    goto LABEL_26;
  }
LABEL_8:
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
