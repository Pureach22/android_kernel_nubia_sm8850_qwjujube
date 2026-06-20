__int64 ipa3_allocate_dma_task_for_gsi()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  _QWORD *v14; // x8
  __int64 v15; // [xsp+0h] [xbp-20h] BYREF
  __int64 v16; // [xsp+8h] [xbp-18h]
  int v17; // [xsp+10h] [xbp-10h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  v17 = 0;
  v15 = 0;
  v16 = 0;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d Allocate mem\n", "ipa3_allocate_dma_task_for_gsi", 12988);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d Allocate mem\n", "ipa3_allocate_dma_task_for_gsi", 12988);
      v0 = ipa3_ctx;
    }
  }
  v3 = *(_QWORD *)(v0 + 34216);
  *(_DWORD *)(v0 + 43784) = 1;
  v4 = dma_alloc_attrs(v3, 1, v0 + 43776, 3264, 0);
  v5 = ipa3_ctx + 40960;
  *(_QWORD *)(ipa3_ctx + 43768) = v4;
  if ( !v4 )
  {
    printk(&unk_3CF6DE, "ipa3_allocate_dma_task_for_gsi");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d no mem\n", "ipa3_allocate_dma_task_for_gsi", 12995);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d no mem\n", "ipa3_allocate_dma_task_for_gsi", 12995);
    }
    goto LABEL_20;
  }
  BYTE2(v15) = 1;
  LODWORD(v16) = *(_DWORD *)(v5 + 2824);
  HIDWORD(v16) = *(_QWORD *)(v5 + 2816);
  v17 = v16;
  v6 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(13, &v15, 0);
  result = 0;
  *(_QWORD *)(ipa3_ctx + 43792) = v6;
  if ( !v6 )
  {
    printk(&unk_3F329F, "ipa3_allocate_dma_task_for_gsi");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(
          v12,
          "ipa %s:%d failed to construct dma_task_32b_addr cmd\n",
          "ipa3_allocate_dma_task_for_gsi",
          13006);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
      {
        ipc_log_string(
          v13,
          "ipa %s:%d failed to construct dma_task_32b_addr cmd\n",
          "ipa3_allocate_dma_task_for_gsi",
          13006);
        v11 = ipa3_ctx;
      }
    }
    dma_free_attrs(
      *(_QWORD *)(v11 + 34216),
      *(unsigned int *)(v11 + 43784),
      *(_QWORD *)(v11 + 43768),
      *(_QWORD *)(v11 + 43776),
      0);
    v14 = (_QWORD *)(ipa3_ctx + 43768);
    *(_QWORD *)(ipa3_ctx + 43768) = 0;
    v14[1] = 0;
    v14[2] = 0;
    v14[3] = 0;
LABEL_20:
    result = 4294967282LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
