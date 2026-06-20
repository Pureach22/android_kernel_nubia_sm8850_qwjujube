__int64 __fastcall msm_hw_fence_register(unsigned int a1, _QWORD *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v8; // x20
  int v9; // w0
  unsigned int *v10; // x19
  unsigned int client_id_priv; // w23
  __int64 v13; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  unsigned int v18; // w8
  unsigned int v19; // t1
  unsigned int v20; // w9
  unsigned int v26; // w10
  __int64 v27; // x8
  __int64 v28; // x4
  __int64 v29; // x3
  __int64 v30; // x4
  __int64 v31; // x8
  __int64 v32; // x10
  __int64 v33; // x11
  __int64 v34; // x0
  unsigned int client_virt_id; // w0
  __int64 v36; // x8
  int client_phys_id; // w0
  int v38; // w5
  unsigned int signal_id; // w0
  char v40; // w0
  __int64 v41; // x8
  char v42; // w0
  __int64 v43; // x8
  char v44; // w0
  __int64 v45; // x8
  char updated; // w0
  __int64 v47; // x8
  int queues_num; // w0
  bool v49; // w9
  __int64 v50; // x0
  int inited; // w0
  __int64 v52; // x0
  int v53; // w8
  unsigned int v54; // w1
  int v55; // w0
  int v56; // w22
  __int64 v57; // x30
  const char *v58; // x3
  const char *v59; // x4
  int v61; // w8
  unsigned int v62; // [xsp+Ch] [xbp-4h]

  if ( hw_fence_driver_enable != 1 )
    return -19;
  v8 = v5;
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
    printk(&unk_24BF9, "msm_hw_fence_register", 64, a1, a5);
  v9 = hw_fence_check_hw_fence_driver(hw_fence_drv_data, (__int64)a2, a3, a4, a5);
  if ( v9 )
    return v9;
  if ( a1 >= 0x681 )
  {
    printk(&unk_28DBD, "msm_hw_fence_register", 71, v8, a1);
    return -22;
  }
  client_id_priv = hw_fence_utils_get_client_id_priv(hw_fence_drv_data, a1);
  if ( client_id_priv >= 0x681 )
  {
    printk(&unk_26875, "msm_hw_fence_register", 78, v8, client_id_priv);
    return -22;
  }
  v13 = _kmalloc_cache_noprof(_arch_copy_to_user, 3520, 232);
  v10 = (unsigned int *)v13;
  if ( !v13 )
    return -12;
  *(_DWORD *)(v13 + 196) = 1;
  _X21 = (unsigned int *)(v13 + 196);
  mutex_lock(hw_fence_drv_data + 680);
  v15 = *(_QWORD *)(hw_fence_drv_data + 728);
  v16 = *(_QWORD *)(v15 + 8LL * client_id_priv);
  if ( v16 )
  {
    v19 = *(_DWORD *)(v16 + 196);
    _X0 = (unsigned int *)(v16 + 196);
    v18 = v19;
    if ( v19 )
    {
      do
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v26 = __ldxr(_X0);
        while ( v26 == v18 && __stxr(v18 + 1, _X0) );
        v20 = v18;
        if ( v26 == v18 )
          break;
        v20 = 0;
        v18 = v26;
      }
      while ( v26 );
    }
    else
    {
      v20 = 0;
    }
    if ( (((v20 + 1) | v20) & 0x80000000) != 0 )
    {
      v62 = v20;
      refcount_warn_saturate(_X0, 0);
      v27 = hw_fence_drv_data;
      if ( v62 )
        goto LABEL_23;
    }
    else
    {
      v27 = hw_fence_drv_data;
      if ( v20 )
      {
LABEL_23:
        mutex_unlock(v27 + 680);
        if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
          printk(&unk_24C24, "msm_hw_fence_register", 93, client_id_priv, v28);
        kfree(v10);
        v10 = *(unsigned int **)(*(_QWORD *)(hw_fence_drv_data + 728) + 8LL * client_id_priv);
        if ( a2 && (unsigned __int64)a2 <= 0xFFFFFFFFFFFFF000LL )
        {
          v31 = *((_QWORD *)v10 + 4);
          v32 = *((_QWORD *)v10 + 1);
          v33 = *((_QWORD *)v10 + 2);
          a2[2] = *((_QWORD *)v10 + 3);
          a2[3] = v31;
          *a2 = v32;
          a2[1] = v33;
        }
        else if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
        {
          printk(&unk_26666, "msm_hw_fence_register", 104, v29, v30);
        }
        return (__int64)v10;
      }
    }
    v15 = *(_QWORD *)(v27 + 728);
  }
  *(_QWORD *)(v15 + 8LL * client_id_priv) = v10;
  mutex_unlock(hw_fence_drv_data + 680);
  v34 = hw_fence_drv_data;
  *v10 = client_id_priv;
  v10[1] = a1;
  client_virt_id = hw_fence_ipcc_get_client_virt_id(v34, client_id_priv);
  v36 = hw_fence_drv_data;
  v10[42] = client_virt_id;
  client_phys_id = hw_fence_ipcc_get_client_phys_id(v36, client_id_priv);
  v38 = v10[42];
  v10[43] = client_phys_id;
  if ( v38 < 1 || client_phys_id <= 0 )
  {
    printk(&unk_2A9DE, "msm_hw_fence_register", 122, v8, client_id_priv);
    v56 = -22;
    goto LABEL_64;
  }
  signal_id = hw_fence_ipcc_get_signal_id(hw_fence_drv_data, client_id_priv);
  v10[41] = signal_id;
  if ( (signal_id & 0x80000000) != 0 )
  {
    printk(&unk_2A530, "msm_hw_fence_register", 129, v8, client_id_priv);
    v56 = -22;
    goto LABEL_64;
  }
  v40 = hw_fence_ipcc_needs_rxq_update(hw_fence_drv_data, client_id_priv);
  v41 = hw_fence_drv_data;
  *((_BYTE *)v10 + 176) = v40 & 1;
  v42 = hw_fence_ipcc_signaled_needs_rxq_update(v41, client_id_priv);
  v43 = hw_fence_drv_data;
  *((_BYTE *)v10 + 177) = v42 & 1;
  v44 = hw_fence_ipcc_signaled_needs_ipc_irq(v43, client_id_priv);
  v45 = hw_fence_drv_data;
  *((_BYTE *)v10 + 178) = v44 & 1;
  updated = hw_fence_ipcc_txq_update_needs_ipc_irq(v45, client_id_priv);
  v47 = hw_fence_drv_data;
  *((_BYTE *)v10 + 179) = updated & 1;
  queues_num = hw_fence_utils_get_queues_num(v47, client_id_priv);
  v10[34] = queues_num;
  if ( !queues_num )
  {
    printk(&unk_2605B, "msm_hw_fence_register", 144, v8, client_id_priv);
    v56 = -22;
    goto LABEL_64;
  }
  if ( queues_num <= 1 )
    *((_WORD *)v10 + 88) = 0;
  v49 = (unsigned int)hw_fence_utils_get_skip_fctl_ref(hw_fence_drv_data, client_id_priv) != 0;
  v50 = hw_fence_drv_data;
  *((_BYTE *)v10 + 180) = v49;
  inited = hw_fence_alloc_client_resources(v50, v10, a2);
  if ( inited
    || (inited = hw_fence_init_controller_signal(hw_fence_drv_data, (__int64)v10)) != 0
    || (inited = hw_fence_init_controller_resources()) != 0 )
  {
    v56 = inited;
    goto LABEL_64;
  }
  v52 = dma_fence_context_alloc(1);
  v53 = msm_hw_fence_debug_level;
  *((_QWORD *)v10 + 23) = v52;
  v10[40] = 0;
  if ( (~v53 & 0x10008) == 0 )
  {
    printk(&unk_29313, "msm_hw_fence_register", 181, v10, *v10);
    if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
    {
      if ( *((_BYTE *)v10 + 176) )
        v58 = "true";
      else
        v58 = "false";
      if ( *((_BYTE *)v10 + 177) )
        v59 = "true";
      else
        v59 = "false";
      printk(&unk_205DF, "msm_hw_fence_register", 187, v58, v59);
    }
  }
  _init_waitqueue_head(v10 + 50, "&hw_fence_client->wait_queue", &msm_hw_fence_register___key);
  if ( *(_BYTE *)(hw_fence_drv_data + 33520) == 1 )
  {
    v54 = v10[1];
    if ( v54 - 129 < 0x40 || v54 - 577 <= 0xFF )
    {
      v55 = hw_fence_utils_set_power_vote(hw_fence_drv_data, v54, 1);
      if ( v55 )
      {
        v56 = v55;
        printk(&unk_21A66, "msm_hw_fence_register", 196, v8, v10[1]);
LABEL_64:
        __asm { PRFM            #0x11, [X21] }
        do
          v61 = __ldxr(_X21);
        while ( __stlxr(v61 - 1, _X21) );
        if ( v61 == 1 )
        {
          __dmb(9u);
          hw_fence_cleanup_client(hw_fence_drv_data, v10);
        }
        else
        {
          v57 = v8;
          if ( v61 > 0 )
            goto LABEL_68;
          refcount_warn_saturate(v10 + 49, 3);
        }
        v57 = v8;
LABEL_68:
        printk(&unk_21AC4, "msm_hw_fence_register", 206, v57, (unsigned int)v56);
        return v56;
      }
    }
  }
  return (__int64)v10;
}
