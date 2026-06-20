__int64 __fastcall ipa3_uc_memcpy(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  _DWORD *v8; // x0
  int v9; // w8
  unsigned int v10; // w19
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  _DWORD *v18; // [xsp+0h] [xbp-30h]
  __int64 v19; // [xsp+8h] [xbp-28h] BYREF
  __int64 v20; // [xsp+10h] [xbp-20h]
  __int64 v21; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v22[2]; // [xsp+20h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = ipa3_ctx;
  v22[0] = a1;
  v20 = 0;
  v21 = a2;
  v19 = 0;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d dest 0x%pa src 0x%pa len %d\n", "ipa3_uc_memcpy", 1519, v22, &v21, a3);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d dest 0x%pa src 0x%pa len %d\n", "ipa3_uc_memcpy", 1519, v22, &v21, a3);
      v4 = ipa3_ctx;
    }
  }
  v7 = *(_QWORD *)(v4 + 34216);
  LODWORD(v20) = 16;
  v8 = (_DWORD *)dma_alloc_attrs(v7, 16, &v19, 3264, 0);
  v18 = v8;
  if ( v8 )
  {
    v8[1] = 0;
    v8[2] = a3;
    v9 = v22[0];
    v8[3] = a3;
    *v8 = v9;
    v8[1] = v21;
    v10 = ipa3_uc_send_cmd_64b_param(v19, 0, 7, 0, 1, 2500);
    if ( v10 )
    {
      printk(&unk_3D039E, "ipa3_uc_memcpy");
      v15 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v16 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v16 )
        {
          ipc_log_string(v16, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_memcpy", 1536, v10);
          v15 = ipa3_ctx;
        }
        v17 = *(_QWORD *)(v15 + 34160);
        if ( v17 )
          ipc_log_string(v17, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_memcpy", 1536, v10);
      }
    }
    dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v20, v18, v19, 0);
  }
  else
  {
    printk(&unk_3B73AF, "ipa3_uc_memcpy");
    v12 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_20;
    v13 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d fail to alloc DMA buff of size %d\n", "ipa3_uc_memcpy", 1524, v20);
      v12 = ipa3_ctx;
    }
    v14 = *(_QWORD *)(v12 + 34160);
    if ( v14 )
    {
      ipc_log_string(v14, "ipa %s:%d fail to alloc DMA buff of size %d\n", "ipa3_uc_memcpy", 1524, v20);
      v10 = -12;
    }
    else
    {
LABEL_20:
      v10 = -12;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v10;
}
