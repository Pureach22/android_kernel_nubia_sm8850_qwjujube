__int64 __fastcall ipa3_eth_uc_init_peripheral(char a1, unsigned __int64 a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x0
  unsigned __int64 v6; // x9
  unsigned int v7; // w19
  __int64 v8; // x0
  _QWORD *v9; // x0
  unsigned int v10; // w19
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  const char *v15; // x20
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  _QWORD *v25; // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h] BYREF
  __int64 v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  if ( (a1 & 1) != 0 )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34224);
    LODWORD(v27) = 12;
    v5 = (_DWORD *)dma_alloc_attrs(v4, 12, &v26, 3264, 0);
    v25 = v5;
    if ( v5 )
    {
      v6 = HIDWORD(a2);
      *v5 = 1;
      v5[1] = a2;
      v7 = 195;
      v5[2] = v6;
      goto LABEL_6;
    }
    printk(&unk_3A6C3A, "ipa3_eth_uc_init_peripheral");
    v19 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v20 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d fail to get DMA memory.\n", "ipa3_eth_uc_init_peripheral", 124);
        v19 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v19 + 34160);
      if ( v21 )
        ipc_log_string(v21, "ipa %s:%d fail to get DMA memory.\n", "ipa3_eth_uc_init_peripheral", 124);
    }
LABEL_31:
    v10 = -12;
    goto LABEL_12;
  }
  v8 = *(_QWORD *)(ipa3_ctx + 34224);
  LODWORD(v27) = 8;
  v9 = (_QWORD *)dma_alloc_attrs(v8, 8, &v26, 3264, 0);
  v25 = v9;
  if ( !v9 )
  {
    printk(&unk_3A6C3A, "ipa3_eth_uc_init_peripheral");
    v22 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d fail to get DMA memory.\n", "ipa3_eth_uc_init_peripheral", 144);
        v22 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
        ipc_log_string(v24, "ipa %s:%d fail to get DMA memory.\n", "ipa3_eth_uc_init_peripheral", 144);
    }
    goto LABEL_31;
  }
  v7 = 196;
  *v9 = 1;
LABEL_6:
  ipa3_inc_client_enable_clks();
  v10 = ipa3_uc_send_cmd((unsigned int)v26, v7, 192, 0, 2500);
  if ( v10 )
  {
    v15 = (a1 & 1) != 0 ? "init" : "deinit";
    printk(&unk_3B22AF, "ipa3_eth_uc_init_peripheral");
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d fail to %s uc\n", "ipa3_eth_uc_init_peripheral", 164, v15);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(v18, "ipa %s:%d fail to %s uc\n", "ipa3_eth_uc_init_peripheral", 164, v15);
    }
  }
  dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34224), (unsigned int)v27, v25, v26, 0);
  ipa3_dec_client_disable_clks();
  v11 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v12 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d exit\n", "ipa3_eth_uc_init_peripheral", 171);
      v11 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v11 + 34160);
    if ( v13 )
      ipc_log_string(v13, "ipa %s:%d exit\n", "ipa3_eth_uc_init_peripheral", 171);
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v10;
}
