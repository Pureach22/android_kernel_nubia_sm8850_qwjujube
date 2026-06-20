__int64 __fastcall ipa3_init_smem_region(unsigned int a1, int a2)
{
  __int64 v3; // x8
  int v4; // w8
  __int64 v5; // x0
  __int64 v6; // x19
  int v7; // w0
  unsigned int v8; // w20
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  int v16; // w20
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // [xsp+0h] [xbp-A0h]
  __int64 v21; // [xsp+8h] [xbp-98h] BYREF
  __int64 v22; // [xsp+10h] [xbp-90h]
  _QWORD v23[13]; // [xsp+18h] [xbp-88h] BYREF
  __int64 v24; // [xsp+80h] [xbp-20h] BYREF
  int v25; // [xsp+88h] [xbp-18h]
  int v26; // [xsp+8Ch] [xbp-14h]
  __int64 v27; // [xsp+90h] [xbp-10h]
  __int64 v28; // [xsp+98h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v8 = 0;
    goto LABEL_8;
  }
  memset(v23, 0, sizeof(v23));
  v22 = a1;
  v3 = *(_QWORD *)(ipa3_ctx + 34216);
  v27 = 0;
  v21 = 0;
  v20 = dma_alloc_attrs(v3, a1, &v21, 3264, 0);
  if ( !v20 )
  {
    printk(&unk_3DDABF, "ipa3_init_smem_region");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d failed to alloc DMA buff of size %d\n", "ipa3_init_smem_region", 4613, v22);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d failed to alloc DMA buff of size %d\n", "ipa3_init_smem_region", 4613, v22);
        v8 = -12;
        goto LABEL_8;
      }
    }
LABEL_19:
    v8 = -12;
    goto LABEL_8;
  }
  v4 = *(unsigned __int16 *)(ipa3_ctx + 29522);
  *(_WORD *)((char *)&v27 + 1) = 0;
  HIDWORD(v27) = 0;
  v24 = v21;
  v25 = v22;
  v26 = v4 + a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v24, 0);
  if ( !v5 )
  {
    printk(&unk_3A8EB0, "ipa3_init_smem_region");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d failed to construct dma_shared_mem imm cmd\n", "ipa3_init_smem_region", 4627);
        v13 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v13 + 34160);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d failed to construct dma_shared_mem imm cmd\n", "ipa3_init_smem_region", 4627);
        v8 = -12;
        goto LABEL_8;
      }
    }
    goto LABEL_19;
  }
  v6 = v5;
  ipa3_init_imm_cmd_desc(v23, v5);
  v7 = ((__int64 (__fastcall *)(__int64, _QWORD *))ipa3_send_cmd)(1, v23);
  if ( v7 )
  {
    v16 = v7;
    printk(&unk_3B18DA, "ipa3_init_smem_region");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(
          v18,
          "ipa %s:%d failed to send immediate command (error %d)\n",
          "ipa3_init_smem_region",
          4634,
          v16);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(
          v19,
          "ipa %s:%d failed to send immediate command (error %d)\n",
          "ipa3_init_smem_region",
          4634,
          v16);
    }
    v8 = -14;
  }
  else
  {
    v8 = 0;
  }
  kfree(v6);
  dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v22, v20, v21, 0);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v8;
}
