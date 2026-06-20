__int64 __fastcall ipa3_wigig_config_uc(char a1, char a2, char a3, unsigned __int8 a4, __int64 a5)
{
  __int64 v10; // x8
  __int64 v11; // x0
  const char *v12; // x4
  __int64 v13; // x0
  const char *v14; // x4
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v17; // w23
  __int64 v18; // x0
  __int64 v19; // x0
  unsigned int v20; // w20
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  const char *v25; // x22
  const char *v26; // x21
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // [xsp+20h] [xbp-20h]
  __int64 v37; // [xsp+28h] [xbp-18h] BYREF
  __int64 v38; // [xsp+30h] [xbp-10h]
  __int64 v39; // [xsp+38h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = ipa3_ctx;
  v37 = 0;
  v38 = 0;
  if ( ipa3_ctx )
  {
    v11 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v11 )
    {
      if ( (a1 & 1) != 0 )
        v12 = "init";
      else
        v12 = "Deinit";
      ipc_log_string(v11, "ipa %s:%d %s\n", "ipa3_wigig_config_uc", 888, v12);
      v10 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v10 + 34160);
    if ( v13 )
    {
      if ( (a1 & 1) != 0 )
        v14 = "init";
      else
        v14 = "Deinit";
      ipc_log_string(v13, "ipa %s:%d %s\n", "ipa3_wigig_config_uc", 888, v14);
    }
  }
  if ( (a1 & 1) != 0 )
  {
    v15 = *(_QWORD *)(ipa3_ctx + 34224);
    LODWORD(v38) = 28;
    v16 = dma_alloc_attrs(v15, 28, &v37, 3264, 0);
    v36 = v16;
    if ( v16 )
    {
      *(_BYTE *)(v16 + 6) = a4;
      *(_DWORD *)v16 = 2;
      *(_BYTE *)(v16 + 4) = (a2 & 1) == 0;
      *(_BYTE *)(v16 + 5) = a3;
      v17 = 193;
      *(_QWORD *)(v16 + 8) = a5;
      goto LABEL_17;
    }
    printk(&unk_3A6C3A, "ipa3_wigig_config_uc");
    v30 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v31 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v31 )
      {
        ipc_log_string(v31, "ipa %s:%d fail to get DMA memory.\n", "ipa3_wigig_config_uc", 896);
        v30 = ipa3_ctx;
      }
      v32 = *(_QWORD *)(v30 + 34160);
      if ( v32 )
        ipc_log_string(v32, "ipa %s:%d fail to get DMA memory.\n", "ipa3_wigig_config_uc", 896);
    }
LABEL_45:
    v20 = -12;
    goto LABEL_23;
  }
  v18 = *(_QWORD *)(ipa3_ctx + 34224);
  LODWORD(v38) = 8;
  v19 = dma_alloc_attrs(v18, 8, &v37, 3264, 0);
  v36 = v19;
  if ( !v19 )
  {
    printk(&unk_3A6C3A, "ipa3_wigig_config_uc");
    v33 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v34 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v34 )
      {
        ipc_log_string(v34, "ipa %s:%d fail to get DMA memory.\n", "ipa3_wigig_config_uc", 921);
        v33 = ipa3_ctx;
      }
      v35 = *(_QWORD *)(v33 + 34160);
      if ( v35 )
        ipc_log_string(v35, "ipa %s:%d fail to get DMA memory.\n", "ipa3_wigig_config_uc", 921);
    }
    goto LABEL_45;
  }
  v17 = 194;
  *(_BYTE *)(v19 + 4) = a4;
  *(_DWORD *)v19 = 2;
LABEL_17:
  ipa3_inc_client_enable_clks();
  v20 = ipa3_uc_send_cmd((unsigned int)v37, v17, 0xC0u, 0, 2500);
  if ( v20 )
  {
    v25 = (a1 & 1) != 0 ? "init" : "deinit";
    v26 = (a2 & 1) != 0 ? "Rx" : "Tx";
    printk(&unk_3E977E, "ipa3_wigig_config_uc");
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(
          v28,
          "ipa %s:%d fail to %s uc for %s gsi channel %d\n",
          "ipa3_wigig_config_uc",
          942,
          v25,
          v26,
          a4);
        v27 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v27 + 34160);
      if ( v29 )
        ipc_log_string(
          v29,
          "ipa %s:%d fail to %s uc for %s gsi channel %d\n",
          "ipa3_wigig_config_uc",
          942,
          v25,
          v26,
          a4);
    }
  }
  dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34224), (unsigned int)v38, v36, v37, 0);
  ipa3_dec_client_disable_clks();
  v21 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v22 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v22 )
    {
      ipc_log_string(v22, "ipa %s:%d exit\n", "ipa3_wigig_config_uc", 949);
      v21 = ipa3_ctx;
    }
    v23 = *(_QWORD *)(v21 + 34160);
    if ( v23 )
      ipc_log_string(v23, "ipa %s:%d exit\n", "ipa3_wigig_config_uc", 949);
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return v20;
}
