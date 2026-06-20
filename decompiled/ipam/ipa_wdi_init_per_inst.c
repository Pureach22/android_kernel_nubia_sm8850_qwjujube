__int64 __fastcall ipa_wdi_init_per_inst(_DWORD *a1, _BYTE *a2)
{
  int v4; // w21
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w21
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x8
  void *v13; // x8
  __int64 v14; // x9
  __int64 result; // x0
  int v16; // w8
  char v17; // w9
  __int64 v18; // x11
  int v19; // w9
  char v20; // w8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int16 v37[2]; // [xsp+8h] [xbp-28h] BYREF
  int v38; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v39; // [xsp+10h] [xbp-20h] BYREF
  void *v40; // [xsp+18h] [xbp-18h]
  __int64 v41; // [xsp+20h] [xbp-10h]
  __int64 v42; // [xsp+28h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = nullptr;
  v41 = 0;
  v39 = 0;
  v38 = 0;
  v37[0] = 0;
  if ( !a1 || !a2 )
  {
    printk(&unk_3E81FE, "ipa_wdi_init_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_wdi %s:%d empty parameters. in=%pK out=%pK\n",
        "ipa_wdi_init_per_inst",
        276,
        a1,
        a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_wdi %s:%d empty parameters. in=%pK out=%pK\n",
        "ipa_wdi_init_per_inst",
        276,
        a1,
        a2);
    }
    goto LABEL_58;
  }
  if ( *a1 >= 4u )
  {
    printk(&unk_3EDBA8, "ipa_wdi_init_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v27 = ipa3_get_ipc_logbuf();
      ipc_log_string(v27, "ipa_wdi %s:%d wrong wdi version: %d\n", "ipa_wdi_init_per_inst", 281, *a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v28 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v28, "ipa_wdi %s:%d wrong wdi version: %d\n", "ipa_wdi_init_per_inst", 281, *a1);
    }
    goto LABEL_20;
  }
  v4 = a1[8];
  if ( ipa3_get_ipc_logbuf() )
  {
    v5 = ipa3_get_ipc_logbuf();
    ipc_log_string(v5, "ipa_wdi %s:%d Assigning handle for instance id %d\n", "assign_hdl_for_inst", 131, v4);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v6, "ipa_wdi %s:%d Assigning handle for instance id %d\n", "assign_hdl_for_inst", 131, v4);
  }
  if ( v4 <= -2 )
  {
    printk(&unk_3D15DC, "assign_hdl_for_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v29 = ipa3_get_ipc_logbuf();
      ipc_log_string(v29, "ipa_wdi %s:%d Invalid instance id %d\n", "assign_hdl_for_inst", 133, v4);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v30 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v30, "ipa_wdi %s:%d Invalid instance id %d\n", "assign_hdl_for_inst", 133, (unsigned int)v4);
    }
LABEL_54:
    printk(&unk_3EAFC0, "ipa_wdi_init_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v31 = ipa3_get_ipc_logbuf();
      ipc_log_string(v31, "ipa_wdi %s:%d Error assigning hdl\n", "ipa_wdi_init_per_inst", 287);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v32 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v32, "ipa_wdi %s:%d Error assigning hdl\n", "ipa_wdi_init_per_inst", 287);
    }
LABEL_58:
    result = 4294967274LL;
    goto LABEL_59;
  }
  if ( ipa_wdi_ctx_list[0] )
  {
    if ( v4 == -1 || *(_DWORD *)(ipa_wdi_ctx_list[0] + 184) == -1 )
    {
      printk(&unk_3D15DC, "assign_hdl_for_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v23 = ipa3_get_ipc_logbuf();
        ipc_log_string(v23, "ipa_wdi %s:%d Invalid instance id %d\n", "assign_hdl_for_inst", 138, v4);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v24 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v24, "ipa_wdi %s:%d Invalid instance id %d\n", "assign_hdl_for_inst", 138, (unsigned int)v4);
      }
    }
    else
    {
      if ( !qword_204E60 )
      {
        v7 = 1;
        if ( !ipa3_get_ipc_logbuf() )
          goto LABEL_15;
        goto LABEL_14;
      }
      printk(&unk_3CB313, "assign_hdl_for_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v35 = ipa3_get_ipc_logbuf();
        ipc_log_string(v35, "ipa_wdi %s:%d Already Maximum Instance Registered\n", "assign_hdl_for_inst", 148);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v36 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v36, "ipa_wdi %s:%d Already Maximum Instance Registered\n", "assign_hdl_for_inst", 148);
      }
    }
    goto LABEL_54;
  }
  v7 = 0;
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_14:
    v8 = ipa3_get_ipc_logbuf();
    ipc_log_string(v8, "ipa_wdi %s:%d Assigned Handle %d\n", "ipa_wdi_init_per_inst", 291, v7);
  }
LABEL_15:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v9 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v9, "ipa_wdi %s:%d Assigned Handle %d\n", "ipa_wdi_init_per_inst", 291, v7);
  }
  v10 = _kmalloc_cache_noprof(raw_spin_lock_irqsave, 3520, 200);
  ipa_wdi_ctx_list[v7] = v10;
  if ( v10 )
  {
    _mutex_init(v10 + 48, "&ipa_wdi_ctx_list[hdl]->lock", &ipa_wdi_init_per_inst___key);
    _mutex_init(ipa_wdi_ctx_list[v7] + 96, "&ipa_wdi_ctx_list[hdl]->clk_lock", &ipa_wdi_init_per_inst___key_15);
    v11 = ipa_wdi_ctx_list[v7];
    *(_DWORD *)(v11 + 16) = 0;
    _init_swait_queue_head(v11 + 24, "&x->wait", &init_completion___key_8);
    v12 = ipa_wdi_ctx_list[v7];
    *(_QWORD *)v12 = v12;
    *(_QWORD *)(v12 + 8) = v12;
    *(_DWORD *)(v12 + 184) = a1[8];
    *(_DWORD *)(v12 + 144) = *a1;
    v13 = *((void **)a1 + 2);
    *(&opt_dpath_info + 17 * v7 + 10) = v13;
    v14 = *((_QWORD *)a1 + 1);
    v40 = v13;
    v41 = v14;
    if ( (unsigned int)ipa3_uc_reg_rdyCB((__int64)&v39) )
    {
      kfree(ipa_wdi_ctx_list[v7]);
      ipa_wdi_ctx_list[v7] = 0;
LABEL_20:
      result = 4294967282LL;
      goto LABEL_59;
    }
    *a2 = v39;
    if ( (unsigned int)(*(_DWORD *)(ipa_wdi_ctx_list[v7] + 184) + 1) >= 2 )
      v16 = 3;
    else
      v16 = 0;
    v38 = v16;
    if ( (unsigned int)ipa_get_smmu_params(&v38, v37) )
      v17 = 0;
    else
      v17 = v37[0];
    a2[1] = v17;
    v18 = ipa3_ctx;
    *(_BYTE *)(ipa_wdi_ctx_list[v7] + 148) = v17;
    if ( *(_BYTE *)(v18 + 32265) != 1
      || !ipa_wdi_ctx_list[0]
      || (v19 = *(_DWORD *)(ipa_wdi_ctx_list[0] + 144), v19 != 1) )
    {
      LOBYTE(v19) = *a1 > 1u;
    }
    a2[2] = v19;
    v20 = *(_BYTE *)(ipa3_ctx + 32267);
    a2[8] = v20;
    a2[9] = v20;
    if ( ipa3_get_ipc_logbuf() )
    {
      v21 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v21,
        "ipa_wdi %s:%d opt_wdi_dpath enabled: %d, hdl: %d\n",
        "ipa_wdi_init_per_inst",
        343,
        (unsigned __int8)a2[8],
        v7);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v22 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v22,
        "ipa_wdi %s:%d opt_wdi_dpath enabled: %d, hdl: %d\n",
        "ipa_wdi_init_per_inst",
        343,
        (unsigned __int8)a2[8],
        v7);
    }
    result = 0;
    *((_DWORD *)a2 + 1) = v7;
  }
  else
  {
    printk(&unk_3DA039, "ipa_wdi_init_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v33 = ipa3_get_ipc_logbuf();
      ipc_log_string(v33, "ipa_wdi %s:%d fail to alloc wdi ctx\n", "ipa_wdi_init_per_inst", 294);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v34 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v34, "ipa_wdi %s:%d fail to alloc wdi ctx\n", "ipa_wdi_init_per_inst", 294);
    }
    result = 4294967284LL;
  }
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return result;
}
