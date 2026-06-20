__int64 __fastcall ipa3_uc_mhi_init_engine(int *a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int updated; // w0
  __int64 v13; // x0
  int *v14; // x0
  int v15; // w8
  unsigned int v16; // w0
  __int64 v17; // x0
  int *v18; // x0
  unsigned int v19; // w0
  unsigned int v20; // w19
  __int64 result; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  int *v39; // [xsp+20h] [xbp-20h]
  __int64 v40; // [xsp+28h] [xbp-18h] BYREF
  __int64 v41; // [xsp+30h] [xbp-10h]
  __int64 v42; // [xsp+38h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  v41 = 0;
  if ( ipa3_uc_mhi_ctx )
  {
    ipa3_inc_client_enable_clks();
    updated = ipa3_uc_update_hw_flags(0);
    if ( updated )
    {
      v20 = updated;
      printk(&unk_3EA088, "ipa3_uc_mhi_init_engine");
      v25 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v26 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v26 )
        {
          ipc_log_string(v26, "ipa %s:%d ipa3_uc_update_hw_flags failed %d\n", "ipa3_uc_mhi_init_engine", 634, v20);
          v25 = ipa3_ctx;
        }
        v27 = *(_QWORD *)(v25 + 34160);
        if ( v27 )
          ipc_log_string(v27, "ipa %s:%d ipa3_uc_update_hw_flags failed %d\n", "ipa3_uc_mhi_init_engine", 634, v20);
      }
      goto LABEL_8;
    }
    v13 = *(_QWORD *)(ipa3_ctx + 34216);
    LODWORD(v41) = 24;
    v14 = (int *)dma_alloc_attrs(v13, 24, &v40, 3264, 0);
    v39 = v14;
    if ( v14 )
    {
      v15 = *a1;
      v14[2] = a3;
      v14[3] = a4;
      v14[4] = a5;
      v14[5] = a6;
      *v14 = v15;
      v14[1] = a2;
      v16 = ipa3_uc_send_cmd((unsigned int)v40, 0x20u, 0, 0, 250);
      if ( v16 )
      {
        v20 = v16;
        printk(&unk_3D039E, "ipa3_uc_mhi_init_engine");
        v31 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_43;
        v32 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v32 )
        {
          ipc_log_string(v32, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_init_engine", 656, v20);
          v31 = ipa3_ctx;
        }
        v33 = *(_QWORD *)(v31 + 34160);
        if ( !v33 )
          goto LABEL_43;
        ipc_log_string(v33, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_init_engine", 656, v20);
        goto LABEL_42;
      }
      dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v41, v39, v40, 0);
      v17 = *(_QWORD *)(ipa3_ctx + 34216);
      LODWORD(v41) = 16;
      v18 = (int *)dma_alloc_attrs(v17, 16, &v40, 3264, 0);
      v39 = v18;
      if ( v18 )
      {
        v18[1] = a1[1];
        *v18 = *a1;
        v18[3] = a1[2];
        v18[2] = a1[3];
        v19 = ipa3_uc_send_cmd((unsigned int)v40, 0x22u, 0, 0, 250);
        if ( !v19 )
        {
          dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v41, v39, v40, 0);
          v20 = 0;
LABEL_8:
          ipa3_dec_client_disable_clks();
          result = v20;
          goto LABEL_9;
        }
        v20 = v19;
        printk(&unk_3D039E, "ipa3_uc_mhi_init_engine");
        v31 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_43;
        v37 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v37 )
        {
          ipc_log_string(v37, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_init_engine", 681, v20);
          v31 = ipa3_ctx;
        }
        v38 = *(_QWORD *)(v31 + 34160);
        if ( !v38 )
        {
LABEL_43:
          dma_free_attrs(*(_QWORD *)(v31 + 34216), (unsigned int)v41, v39, v40, 0);
          goto LABEL_8;
        }
        ipc_log_string(v38, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_uc_mhi_init_engine", 681, v20);
LABEL_42:
        v31 = ipa3_ctx;
        goto LABEL_43;
      }
      printk(&unk_3B73AF, "ipa3_uc_mhi_init_engine");
      v34 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v35 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v35 )
        {
          ipc_log_string(v35, "ipa %s:%d fail to alloc DMA buff of size %d\n", "ipa3_uc_mhi_init_engine", 668, v41);
          v34 = ipa3_ctx;
        }
        v36 = *(_QWORD *)(v34 + 34160);
        if ( v36 )
        {
          ipc_log_string(
            v36,
            "ipa %s:%d fail to alloc DMA buff of size %d\n",
            "ipa3_uc_mhi_init_engine",
            668,
            (unsigned int)v41);
          goto LABEL_35;
        }
      }
    }
    else
    {
      printk(&unk_3B73AF, "ipa3_uc_mhi_init_engine");
      v28 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v29 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v29 )
        {
          ipc_log_string(v29, "ipa %s:%d fail to alloc DMA buff of size %d\n", "ipa3_uc_mhi_init_engine", 642, v41);
          v28 = ipa3_ctx;
        }
        v30 = *(_QWORD *)(v28 + 34160);
        if ( v30 )
        {
          ipc_log_string(
            v30,
            "ipa %s:%d fail to alloc DMA buff of size %d\n",
            "ipa3_uc_mhi_init_engine",
            642,
            (unsigned int)v41);
LABEL_35:
          v20 = -12;
          goto LABEL_8;
        }
      }
    }
    v20 = -12;
    goto LABEL_8;
  }
  printk(&unk_3B8A54, "ipa3_uc_mhi_init_engine");
  v22 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_44;
  v23 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v23 )
  {
    ipc_log_string(v23, "ipa %s:%d Not initialized\n", "ipa3_uc_mhi_init_engine", 626);
    v22 = ipa3_ctx;
  }
  v24 = *(_QWORD *)(v22 + 34160);
  if ( v24 )
  {
    ipc_log_string(v24, "ipa %s:%d Not initialized\n", "ipa3_uc_mhi_init_engine", 626);
    result = 4294967282LL;
  }
  else
  {
LABEL_44:
    result = 4294967282LL;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
