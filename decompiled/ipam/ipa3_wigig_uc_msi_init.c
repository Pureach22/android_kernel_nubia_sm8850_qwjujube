__int64 __fastcall ipa3_wigig_uc_msi_init(char a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v7; // x8
  __int64 v8; // x0
  const char *v9; // x4
  __int64 v10; // x0
  const char *v11; // x4
  __int64 v12; // x0
  __int64 v13; // x0
  char v14; // w21
  unsigned int v15; // w0
  unsigned int v16; // w0
  unsigned int v17; // w0
  unsigned int v18; // w0
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned int v21; // w20
  __int64 v22; // x0
  _DWORD *v23; // x0
  int v24; // w0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 result; // x0
  const char *v28; // x20
  int v29; // w24
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  const char *v33; // x19
  unsigned int v34; // w20
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  const char *v38; // x21
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  const char *v48; // x21
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x0
  const char *v52; // x21
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  _DWORD *v56; // [xsp+28h] [xbp-48h]
  __int64 v57; // [xsp+30h] [xbp-40h] BYREF
  __int64 v58; // [xsp+38h] [xbp-38h]
  __int64 v59; // [xsp+40h] [xbp-30h] BYREF
  __int64 v60; // [xsp+48h] [xbp-28h] BYREF
  __int64 v61; // [xsp+50h] [xbp-20h] BYREF
  __int64 v62; // [xsp+58h] [xbp-18h] BYREF
  _QWORD v63[2]; // [xsp+60h] [xbp-10h] BYREF

  v63[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = ipa3_ctx;
  v62 = a3;
  v63[0] = a2;
  v60 = a5;
  v61 = a4;
  v59 = a6;
  v57 = 0;
  v58 = 0;
  if ( !ipa3_ctx )
  {
    if ( (byte_A931 & 1) == 0 )
      goto LABEL_20;
LABEL_19:
    v14 = 0;
    goto LABEL_24;
  }
  v8 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v8 )
  {
    if ( (a1 & 1) != 0 )
      v9 = "init";
    else
      v9 = "deInit";
    ipc_log_string(
      v8,
      "ipa %s:%d params: %s, %pa, %pa, %pa, %pa, %pa\n",
      "ipa3_wigig_uc_msi_init",
      1527,
      v9,
      v63,
      &v62,
      &v61,
      &v60,
      &v59);
    v7 = ipa3_ctx;
  }
  v10 = *(_QWORD *)(v7 + 34160);
  if ( v10 )
  {
    if ( (a1 & 1) != 0 )
      v11 = "init";
    else
      v11 = "deInit";
    ipc_log_string(
      v10,
      "ipa %s:%d params: %s, %pa, %pa, %pa, %pa, %pa\n",
      "ipa3_wigig_uc_msi_init",
      1527,
      v11,
      v63,
      &v62,
      &v61,
      &v60,
      &v59);
    v7 = ipa3_ctx;
  }
  if ( (*(_BYTE *)(v7 + 43313) & 1) != 0 )
    goto LABEL_19;
  if ( v7 )
  {
    v12 = *(_QWORD *)(v7 + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d SMMU enabled, map %d\n", "ipa3_wigig_uc_msi_init", 1534, a1 & 1);
      v7 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v7 + 34160);
    if ( v13 )
      ipc_log_string(v13, "ipa %s:%d SMMU enabled, map %d\n", "ipa3_wigig_uc_msi_init", 1534, a1 & 1);
  }
LABEL_20:
  v15 = ipa3_smmu_map_peer_reg(v62 & 0xFFFFFFFFFFFFF000LL, a1 & 1, 3u);
  if ( v15 )
  {
    if ( (a1 & 1) != 0 )
      v33 = "map";
    else
      v33 = "unmap";
    v34 = v15;
    printk(&unk_3E1C59, "ipa3_wigig_uc_msi_init");
    v35 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v36 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v36 )
      {
        ipc_log_string(v36, "ipa %s:%d failed to %s pseudo_cause reg %d\n", "ipa3_wigig_uc_msi_init", 1544, v33, v34);
        v35 = ipa3_ctx;
      }
      v37 = *(_QWORD *)(v35 + 34160);
      if ( v37 )
        ipc_log_string(v37, "ipa %s:%d failed to %s pseudo_cause reg %d\n", "ipa3_wigig_uc_msi_init", 1544, v33, v34);
    }
    goto LABEL_93;
  }
  v16 = ipa3_smmu_map_peer_reg(v61 & 0xFFFFFFFFFFFFF000LL, a1 & 1, 3u);
  if ( v16 )
  {
    if ( (a1 & 1) != 0 )
      v38 = "map";
    else
      v38 = "unmap";
    v34 = v16;
    printk(&unk_3A7B31, "ipa3_wigig_uc_msi_init");
    v39 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v40 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v40 )
      {
        ipc_log_string(v40, "ipa %s:%d failed to %s int_gen_tx reg %d\n", "ipa3_wigig_uc_msi_init", 1556, v38, v34);
        v39 = ipa3_ctx;
      }
      v41 = *(_QWORD *)(v39 + 34160);
      if ( v41 )
        ipc_log_string(v41, "ipa %s:%d failed to %s int_gen_tx reg %d\n", "ipa3_wigig_uc_msi_init", 1556, v38, v34);
    }
    goto LABEL_92;
  }
  v17 = ipa3_smmu_map_peer_reg(v60 & 0xFFFFFFFFFFFFF000LL, a1 & 1, 3u);
  if ( v17 )
  {
    if ( (a1 & 1) != 0 )
      v48 = "map";
    else
      v48 = "unmap";
    v34 = v17;
    printk(&unk_3F34BD, "ipa3_wigig_uc_msi_init");
    v49 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v50 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v50 )
      {
        ipc_log_string(v50, "ipa %s:%d failed to %s int_gen_rx reg %d\n", "ipa3_wigig_uc_msi_init", 1568, v48, v34);
        v49 = ipa3_ctx;
      }
      v51 = *(_QWORD *)(v49 + 34160);
      if ( v51 )
        ipc_log_string(v51, "ipa %s:%d failed to %s int_gen_rx reg %d\n", "ipa3_wigig_uc_msi_init", 1568, v48, v34);
    }
    goto LABEL_91;
  }
  v18 = ipa3_smmu_map_peer_reg(v59 & 0xFFFFFFFFFFFFF000LL, a1 & 1, 3u);
  v14 = a1;
  if ( v18 )
  {
    if ( (a1 & 1) != 0 )
      v52 = "map";
    else
      v52 = "unmap";
    v34 = v18;
    printk(&unk_3D0A9A, "ipa3_wigig_uc_msi_init");
    v53 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v54 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v54 )
      {
        ipc_log_string(v54, "ipa %s:%d failed to %s dma_ep_misc reg %d\n", "ipa3_wigig_uc_msi_init", 1580, v52, v34);
        v53 = ipa3_ctx;
      }
      v55 = *(_QWORD *)(v53 + 34160);
      if ( v55 )
        ipc_log_string(v55, "ipa %s:%d failed to %s dma_ep_misc reg %d\n", "ipa3_wigig_uc_msi_init", 1580, v52, v34);
    }
    v14 = a1;
    goto LABEL_90;
  }
LABEL_24:
  if ( (a1 & 1) != 0 )
  {
    v19 = *(_QWORD *)(ipa3_ctx + 34224);
    LODWORD(v58) = 12;
    v20 = dma_alloc_attrs(v19, 12, &v57, 3264, 0);
    v56 = (_DWORD *)v20;
    if ( v20 )
    {
      v21 = 195;
      *(_DWORD *)v20 = 2;
      *(_QWORD *)(v20 + 4) = v63[0];
      goto LABEL_29;
    }
    printk(&unk_3A6C3A, "ipa3_wigig_uc_msi_init");
    v42 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v43 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v43 )
      {
        ipc_log_string(v43, "ipa %s:%d fail to get DMA memory.\n", "ipa3_wigig_uc_msi_init", 1593);
        v42 = ipa3_ctx;
      }
      v44 = *(_QWORD *)(v42 + 34160);
      if ( v44 )
        ipc_log_string(v44, "ipa %s:%d fail to get DMA memory.\n", "ipa3_wigig_uc_msi_init", 1593);
    }
LABEL_71:
    result = 4294967284LL;
    if ( (v14 & 1) == 0 )
      goto LABEL_94;
    goto LABEL_72;
  }
  v22 = *(_QWORD *)(ipa3_ctx + 34224);
  LODWORD(v58) = 8;
  v23 = (_DWORD *)dma_alloc_attrs(v22, 8, &v57, 3264, 0);
  v56 = v23;
  if ( !v23 )
  {
    printk(&unk_3A6C3A, "ipa3_wigig_uc_msi_init");
    v45 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v46 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v46 )
      {
        ipc_log_string(v46, "ipa %s:%d fail to get DMA memory.\n", "ipa3_wigig_uc_msi_init", 1613);
        v45 = ipa3_ctx;
      }
      v47 = *(_QWORD *)(v45 + 34160);
      if ( v47 )
        ipc_log_string(v47, "ipa %s:%d fail to get DMA memory.\n", "ipa3_wigig_uc_msi_init", 1613);
    }
    goto LABEL_71;
  }
  v21 = 196;
  *v23 = 2;
LABEL_29:
  ipa3_inc_client_enable_clks();
  v24 = ipa3_uc_send_cmd((unsigned int)v57, v21, 0xC0u, 0, 2500);
  if ( v24 )
  {
    if ( (a1 & 1) != 0 )
      v28 = "init";
    else
      v28 = "deinit";
    v29 = v24;
    printk(&unk_3C50F3, "ipa3_wigig_uc_msi_init");
    v30 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v31 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v31 )
      {
        ipc_log_string(v31, "ipa %s:%d fail to %s uc MSI config\n", "ipa3_wigig_uc_msi_init", 1631, v28);
        v30 = ipa3_ctx;
      }
      v32 = *(_QWORD *)(v30 + 34160);
      if ( v32 )
      {
        ipc_log_string(v32, "ipa %s:%d fail to %s uc MSI config\n", "ipa3_wigig_uc_msi_init", 1631, v28);
        v30 = ipa3_ctx;
      }
    }
    dma_free_attrs(*(_QWORD *)(v30 + 34224), (unsigned int)v58, v56, v57, 0);
    ipa3_dec_client_disable_clks();
    LODWORD(result) = v29;
LABEL_72:
    v34 = result;
    ipa3_smmu_map_peer_reg(v59 & 0xFFFFFFFFFFFFF000LL, (v14 & 1) == 0, 3u);
LABEL_90:
    ipa3_smmu_map_peer_reg(v60 & 0xFFFFFFFFFFFFF000LL, (v14 & 1) == 0, 3u);
    a1 = v14;
LABEL_91:
    ipa3_smmu_map_peer_reg(v61 & 0xFFFFFFFFFFFFF000LL, (a1 & 1) == 0, 3u);
LABEL_92:
    ipa3_smmu_map_peer_reg(v62 & 0xFFFFFFFFFFFFF000LL, (a1 & 1) == 0, 3u);
LABEL_93:
    result = v34;
    goto LABEL_94;
  }
  dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34224), (unsigned int)v58, v56, v57, 0);
  ipa3_dec_client_disable_clks();
  v25 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_35:
    result = 0;
    goto LABEL_94;
  }
  v26 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v26 )
  {
    ipc_log_string(v26, "ipa %s:%d exit\n", "ipa3_wigig_uc_msi_init", 1639);
    v25 = ipa3_ctx;
  }
  result = *(_QWORD *)(v25 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_wigig_uc_msi_init", 1639);
    goto LABEL_35;
  }
LABEL_94:
  _ReadStatusReg(SP_EL0);
  return result;
}
