__int64 __fastcall ipa3_tear_down_uc_offload_pipes(signed int a1, signed int a2, __int64 a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x23
  __int64 v12; // x24
  __int64 v13; // x1
  __int64 v14; // x27
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned int v18; // w0
  unsigned int v19; // w0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  unsigned int v23; // w21
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
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x0
  _BYTE *v49; // [xsp+20h] [xbp-20h]
  __int64 v50; // [xsp+28h] [xbp-18h] BYREF
  __int64 v51; // [xsp+30h] [xbp-10h]
  __int64 v52; // [xsp+38h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = ipa3_ctx;
  v50 = 0;
  v51 = 0;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d ep_ul = %d\n", "ipa3_tear_down_uc_offload_pipes", 607, a1);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d ep_ul = %d\n", "ipa3_tear_down_uc_offload_pipes", 607, a1);
      v6 = ipa3_ctx;
    }
    if ( v6 )
    {
      v9 = *(_QWORD *)(v6 + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d ep_dl = %d\n", "ipa3_tear_down_uc_offload_pipes", 608, a2);
        v6 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v6 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d ep_dl = %d\n", "ipa3_tear_down_uc_offload_pipes", 608, a2);
    }
  }
  if ( a1 == -1 || a1 >= 31 )
  {
    printk(&unk_3F2EDE, "ipa3_tear_down_uc_offload_pipes");
    v25 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_59;
    v26 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v26 )
    {
      ipc_log_string(v26, "ipa %s:%d ipa_ep_idx_ul %d invalid\n", "ipa3_tear_down_uc_offload_pipes", 613, a1);
      v25 = ipa3_ctx;
    }
    v27 = *(_QWORD *)(v25 + 34160);
    if ( !v27 )
      goto LABEL_59;
    ipc_log_string(
      v27,
      "ipa %s:%d ipa_ep_idx_ul %d invalid\n",
      "ipa3_tear_down_uc_offload_pipes",
      613,
      (unsigned int)a1);
    goto LABEL_53;
  }
  if ( a2 == -1 || a2 >= 31 )
  {
    printk(&unk_3C1730, "ipa3_tear_down_uc_offload_pipes");
    v28 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_59;
    v29 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v29 )
    {
      ipc_log_string(v29, "ipa %s:%d ep ipa_ep_idx_dl %d invalid\n", "ipa3_tear_down_uc_offload_pipes", 620, a2);
      v28 = ipa3_ctx;
    }
    v30 = *(_QWORD *)(v28 + 34160);
    if ( !v30 )
      goto LABEL_59;
    ipc_log_string(
      v30,
      "ipa %s:%d ep ipa_ep_idx_dl %d invalid\n",
      "ipa3_tear_down_uc_offload_pipes",
      620,
      (unsigned int)a2);
LABEL_53:
    v23 = -14;
    goto LABEL_42;
  }
  if ( (unsigned int)a1 >= 0x25 || (unsigned int)a2 > 0x24 )
    __break(0x5512u);
  v11 = ipa3_ctx + 168 + 480LL * a1;
  v12 = ipa3_ctx + 168 + 480LL * a2;
  if ( *(_DWORD *)(v11 + 448) != 1 || *(_DWORD *)(v12 + 448) != 1 )
  {
    printk(&unk_3D04BE, "ipa3_tear_down_uc_offload_pipes");
    v31 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v32 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v32 )
      {
        ipc_log_string(
          v32,
          "ipa %s:%d channel bad state: ul %d dl %d\n",
          "ipa3_tear_down_uc_offload_pipes",
          630,
          *(_DWORD *)(v11 + 448),
          *(_DWORD *)(v12 + 448));
        v31 = ipa3_ctx;
      }
      v33 = *(_QWORD *)(v31 + 34160);
      if ( v33 )
      {
        ipc_log_string(
          v33,
          "ipa %s:%d channel bad state: ul %d dl %d\n",
          "ipa3_tear_down_uc_offload_pipes",
          630,
          *(_DWORD *)(v11 + 448),
          *(_DWORD *)(v12 + 448));
        v23 = -14;
        goto LABEL_42;
      }
    }
LABEL_59:
    v23 = -14;
    goto LABEL_42;
  }
  *(_DWORD *)(v11 + 456) = 1;
  *(_DWORD *)(v12 + 456) = 1;
  if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
    v13 = 5;
  else
    v13 = 8;
  LODWORD(v51) = v13;
  v49 = (_BYTE *)dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34224), v13, &v50, 3264, 0);
  if ( v49 )
  {
    ipa3_inc_client_enable_clks();
    if ( *(_DWORD *)(ipa3_ctx + 32240) < 0xEu )
    {
      v14 = 1;
      *v49 = 5;
    }
    else
    {
      v14 = 4;
      *(_DWORD *)v49 = 5;
    }
    ipa3_disable_data_path(a2);
    memset((void *)(ipa3_ctx + 480LL * a2 + 168), 0, 0x1E0u);
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d dl client (ep: %d) disconnected\n", "ipa3_tear_down_uc_offload_pipes", 668, a2);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(v17, "ipa %s:%d dl client (ep: %d) disconnected\n", "ipa3_tear_down_uc_offload_pipes", 668, a2);
    }
    *(_DWORD *)&v49[v14] = *(_DWORD *)&v49[v14] & 0xFFFFFF00 | a2;
    if ( (unsigned int)ipa3_uc_send_cmd((unsigned int)v50, 0xC2u, 0xC0u, 0, 2500) )
    {
      printk(&unk_3D0514, "ipa3_tear_down_uc_offload_pipes");
      v37 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v38 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v38 )
        {
          ipc_log_string(v38, "ipa %s:%d fail to tear down dl pipe\n", "ipa3_tear_down_uc_offload_pipes", 675);
          v37 = ipa3_ctx;
        }
        v39 = *(_QWORD *)(v37 + 34160);
        if ( v39 )
        {
          ipc_log_string(v39, "ipa %s:%d fail to tear down dl pipe\n", "ipa3_tear_down_uc_offload_pipes", 675);
LABEL_80:
          v23 = -14;
LABEL_41:
          dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34224), (unsigned int)v51, v49, v50, 0);
          ipa3_dec_client_disable_clks();
          goto LABEL_42;
        }
      }
    }
    else
    {
      v18 = ipa3_smmu_map_uc_ntn_pipes(a3 + 96, 0);
      if ( v18 )
      {
        v23 = v18;
        printk(&unk_3E43A1, "ipa3_tear_down_uc_offload_pipes");
        v40 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v41 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v41 )
          {
            ipc_log_string(
              v41,
              "ipa %s:%d failed to unmap SMMU for DL %d\n",
              "ipa3_tear_down_uc_offload_pipes",
              683,
              v23);
            v40 = ipa3_ctx;
          }
          v42 = *(_QWORD *)(v40 + 34160);
          if ( v42 )
            ipc_log_string(
              v42,
              "ipa %s:%d failed to unmap SMMU for DL %d\n",
              "ipa3_tear_down_uc_offload_pipes",
              683,
              v23);
        }
        goto LABEL_41;
      }
      ipa3_disable_data_path(a1);
      *(_DWORD *)&v49[v14] = *(_DWORD *)&v49[v14] & 0xFFFFFF00 | a1;
      if ( !(unsigned int)ipa3_uc_send_cmd((unsigned int)v50, 0xC2u, 0xC0u, 0, 2500) )
      {
        v19 = ipa3_smmu_map_uc_ntn_pipes(a3, 0);
        if ( v19 )
        {
          v23 = v19;
          printk(&unk_3A76E9, "ipa3_tear_down_uc_offload_pipes");
          v46 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v47 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v47 )
            {
              ipc_log_string(
                v47,
                "ipa %s:%d failed to unmap SMMU for UL %d\n",
                "ipa3_tear_down_uc_offload_pipes",
                704,
                v23);
              v46 = ipa3_ctx;
            }
            v48 = *(_QWORD *)(v46 + 34160);
            if ( v48 )
              ipc_log_string(
                v48,
                "ipa %s:%d failed to unmap SMMU for UL %d\n",
                "ipa3_tear_down_uc_offload_pipes",
                704,
                v23);
          }
        }
        else
        {
          ((void (__fastcall *)(_QWORD))ipa3_delete_dflt_flt_rules)((unsigned int)a1);
          memset((void *)(ipa3_ctx + 480LL * a1 + 168), 0, 0x1E0u);
          v20 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v21 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v21 )
            {
              ipc_log_string(
                v21,
                "ipa %s:%d ul client (ep: %d) disconnected\n",
                "ipa3_tear_down_uc_offload_pipes",
                710,
                a1);
              v20 = ipa3_ctx;
            }
            v22 = *(_QWORD *)(v20 + 34160);
            if ( v22 )
              ipc_log_string(
                v22,
                "ipa %s:%d ul client (ep: %d) disconnected\n",
                "ipa3_tear_down_uc_offload_pipes",
                710,
                a1);
          }
          v23 = 0;
        }
        goto LABEL_41;
      }
      printk(&unk_3ECC66, "ipa3_tear_down_uc_offload_pipes");
      v43 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v44 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v44 )
        {
          ipc_log_string(v44, "ipa %s:%d fail to tear down ul pipe\n", "ipa3_tear_down_uc_offload_pipes", 696);
          v43 = ipa3_ctx;
        }
        v45 = *(_QWORD *)(v43 + 34160);
        if ( v45 )
        {
          ipc_log_string(v45, "ipa %s:%d fail to tear down ul pipe\n", "ipa3_tear_down_uc_offload_pipes", 696);
          goto LABEL_80;
        }
      }
    }
    v23 = -14;
    goto LABEL_41;
  }
  printk(&unk_3A6C3A, "ipa3_tear_down_uc_offload_pipes");
  v34 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_88;
  v35 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v35 )
  {
    ipc_log_string(v35, "ipa %s:%d fail to get DMA memory.\n", "ipa3_tear_down_uc_offload_pipes", 644);
    v34 = ipa3_ctx;
  }
  v36 = *(_QWORD *)(v34 + 34160);
  if ( v36 )
  {
    ipc_log_string(v36, "ipa %s:%d fail to get DMA memory.\n", "ipa3_tear_down_uc_offload_pipes", 644);
    v23 = -12;
  }
  else
  {
LABEL_88:
    v23 = -12;
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v23;
}
