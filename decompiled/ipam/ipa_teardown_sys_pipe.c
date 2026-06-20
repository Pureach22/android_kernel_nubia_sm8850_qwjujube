__int64 __fastcall ipa_teardown_sys_pipe(unsigned int a1)
{
  __int64 v2; // x22
  __int64 v3; // x22
  int v4; // t1
  __int64 v5; // x0
  unsigned int v6; // w8
  __int64 v7; // x8
  __int64 v8; // x24
  __int64 v9; // x25
  __int64 v10; // x8
  _QWORD *v11; // x9
  _QWORD *v12; // x8
  _QWORD *v13; // x24
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  int v18; // w20
  __int64 v19; // x8
  unsigned int v20; // w9
  unsigned int v21; // w8
  __int64 ep_mapping; // x0
  unsigned int v23; // w0
  int v24; // w8
  __int64 v25; // x0
  __int64 v26; // x0
  unsigned int v27; // w0
  unsigned int v28; // w0
  unsigned int v29; // w0
  __int64 v30; // x0
  int v31; // w0
  __int64 v32; // x2
  int v33; // w0
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  unsigned int v38; // w8
  __int64 v39; // x0
  unsigned int v40; // w8
  __int64 v41; // x9
  int v42; // w8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 result; // x0
  __int64 v50; // x8
  _QWORD *v51; // x20
  _QWORD *v52; // x8
  _QWORD *v53; // x27
  __int64 v54; // x1
  int v55; // w3
  int v56; // w10
  __int64 v57; // x8
  __int64 v58; // x0
  unsigned int v59; // w19
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x8
  __int64 v64; // x0
  __int64 v65; // x8
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x8
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x8
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x8
  __int64 v81; // x0
  __int64 v82; // x0
  unsigned int v83; // w19
  unsigned int v84; // w19
  unsigned int v90; // w10

  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    goto LABEL_99;
  if ( a1 >= 0x24 )
    goto LABEL_183;
  v2 = ipa3_ctx + 480LL * a1;
  v4 = *(_DWORD *)(v2 + 168);
  v3 = v2 + 168;
  if ( !v4 )
  {
LABEL_99:
    printk(&unk_3F1C1D, "ipa_teardown_sys_pipe");
    v45 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_130;
    v46 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v46 )
    {
      ipc_log_string(v46, "ipa %s:%d bad parm.\n", "ipa_teardown_sys_pipe", 2029);
      v45 = ipa3_ctx;
    }
    v47 = *(_QWORD *)(v45 + 34160);
    if ( v47 )
    {
      ipc_log_string(v47, "ipa %s:%d bad parm.\n", "ipa_teardown_sys_pipe", 2029);
      result = 4294967274LL;
    }
    else
    {
LABEL_130:
      result = 4294967274LL;
    }
    goto LABEL_148;
  }
  if ( (*(_BYTE *)(v3 + 405) & 1) == 0 )
  {
    ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
      ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
    ipa3_inc_client_enable_clks();
  }
  v5 = ipa3_disable_data_path(a1);
  v6 = *(_DWORD *)(v3 + 4);
  if ( v6 <= 0x85 && (v6 & 1) == 0 )
  {
    raw_spin_lock_bh(*(_QWORD *)(v3 + 472) + 1684LL);
    while ( 1 )
    {
      *(_DWORD *)(v3 + 456) = 1;
      v7 = *(_QWORD *)(v3 + 472);
      v8 = *(_QWORD *)(v7 + 1632);
      v9 = v7 + 1632;
      raw_spin_unlock_bh(v7 + 1684);
      if ( v8 == v9 )
        break;
      usleep_range_state(95, 105, 2);
      raw_spin_lock_bh(*(_QWORD *)(v3 + 472) + 1684LL);
    }
    raw_spin_lock_bh(*(_QWORD *)(v3 + 472) + 1684LL);
    v10 = *(_QWORD *)(v3 + 472);
    v11 = *(_QWORD **)(v10 + 1664);
    if ( v11 != (_QWORD *)(v10 + 1664) )
    {
      do
      {
        v13 = (_QWORD *)*v11;
        v12 = (_QWORD *)v11[1];
        if ( (_QWORD *)*v12 == v11 && (_QWORD *)v13[1] == v11 )
        {
          v13[1] = v12;
          *v12 = v13;
        }
        else
        {
          _list_del_entry_valid_or_report(v11);
        }
        *v11 = 0xDEAD000000000100LL;
        v11[1] = 0xDEAD000000000122LL;
        kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29440), v11 - 4);
        --*(_DWORD *)(*(_QWORD *)(v3 + 472) + 1680LL);
        v10 = *(_QWORD *)(v3 + 472);
        v11 = v13;
      }
      while ( v13 != (_QWORD *)(v10 + 1664) );
    }
    *(_DWORD *)(v10 + 1680) = 0;
    v5 = raw_spin_unlock_bh(*(_QWORD *)(v3 + 472) + 1684LL);
    v14 = *(_QWORD *)(v3 + 472);
    if ( *(_BYTE *)(v14 + 1585) == 1 )
    {
      v15 = _netif_napi_del(v14 + 720);
      v5 = synchronize_net(v15);
    }
    v6 = *(_DWORD *)(v3 + 4);
  }
  if ( v6 == 121 )
  {
    napi_disable(*(_QWORD *)(v3 + 472) + 1152LL);
    v16 = _netif_napi_del(*(_QWORD *)(v3 + 472) + 1152LL);
    v5 = synchronize_net(v16);
    v6 = *(_DWORD *)(v3 + 4);
  }
  if ( v6 == 95 )
  {
    stop_coalescing(v5);
    ipa3_force_close_coal(0, 1);
  }
  v17 = ipa_stop_gsi_channel(a1);
  if ( (_DWORD)v17 )
  {
    if ( (unsigned int)(v17 + 10) > 0xFFFFFFFD )
    {
      v17 = ipa_stop_gsi_channel(a1);
      if ( (_DWORD)v17 )
      {
        if ( (unsigned int)(v17 + 10) >= 0xFFFFFFFE )
        {
          v17 = ipa_stop_gsi_channel(a1);
          if ( (_DWORD)v17 )
          {
            if ( (unsigned int)(v17 + 10) >= 0xFFFFFFFE )
            {
              v17 = ipa_stop_gsi_channel(a1);
              if ( (_DWORD)v17 )
              {
                if ( (unsigned int)(v17 + 10) >= 0xFFFFFFFE )
                {
                  v17 = ipa_stop_gsi_channel(a1);
                  if ( (_DWORD)v17 )
                  {
                    if ( (unsigned int)(v17 + 10) >= 0xFFFFFFFE )
                    {
                      v17 = ipa_stop_gsi_channel(a1);
                      if ( (_DWORD)v17 )
                      {
                        if ( (unsigned int)(v17 + 10) >= 0xFFFFFFFE )
                        {
                          v17 = ipa_stop_gsi_channel(a1);
                          if ( (_DWORD)v17 )
                          {
                            if ( (unsigned int)(v17 + 10) >= 0xFFFFFFFE )
                            {
                              v17 = ipa_stop_gsi_channel(a1);
                              if ( (_DWORD)v17 )
                              {
                                if ( (unsigned int)(v17 + 10) >= 0xFFFFFFFE )
                                {
                                  v17 = ipa_stop_gsi_channel(a1);
                                  if ( (_DWORD)v17 )
                                  {
                                    if ( (unsigned int)(v17 + 10) >= 0xFFFFFFFE )
                                      v17 = ipa_stop_gsi_channel(a1);
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( *(_DWORD *)(v3 + 4) == 95 )
  {
    v18 = v17;
    start_coalescing(v17);
    LODWORD(v17) = v18;
  }
  if ( (_DWORD)v17 )
  {
    v59 = v17;
    v60 = printk(&unk_3F1F48, "ipa_teardown_sys_pipe");
    v61 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v62 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v62 )
      {
        ipc_log_string(v62, "ipa %s:%d GSI stop chan err: %d.\n", "ipa_teardown_sys_pipe", 2084, v59);
        v61 = ipa3_ctx;
      }
      v60 = *(_QWORD *)(v61 + 34160);
      if ( v60 )
        v60 = ipc_log_string(v60, "ipa %s:%d GSI stop chan err: %d.\n", "ipa_teardown_sys_pipe", 2084, v59);
    }
    goto LABEL_146;
  }
  do
  {
    usleep_range_state(95, 105, 2);
    v19 = *(_QWORD *)(v3 + 472);
  }
  while ( *(_DWORD *)(v19 + 4) );
  v20 = *(_DWORD *)(v3 + 4);
  if ( v20 <= 0x85 && (v20 & 1) != 0 )
  {
    cancel_delayed_work_sync(v19 + 224);
    v19 = *(_QWORD *)(v3 + 472);
  }
  _flush_workqueue(*(_QWORD *)(v19 + 1752));
  v21 = *(_DWORD *)(v3 + 4);
  if ( v21 <= 0x85 && (v21 & 1) == 0 )
  {
    *(_DWORD *)(*(_QWORD *)(v3 + 472) + 8LL) = 1;
    v21 = *(_DWORD *)(v3 + 4);
  }
  if ( v21 == 95 )
  {
    ep_mapping = ipa_get_ep_mapping(35);
    if ( (_DWORD)ep_mapping == -1 )
    {
      printk(&unk_3EC277, "ipa_teardown_sys_pipe");
      v67 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v68 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v68 )
        {
          ipc_log_string(v68, "ipa %s:%d Failed to get idx for IPA_CLIENT_APPS_WAN_CONS", "ipa_teardown_sys_pipe", 2106);
          v67 = ipa3_ctx;
        }
        v69 = *(_QWORD *)(v67 + 34160);
        if ( v69 )
        {
          ipc_log_string(v69, "ipa %s:%d Failed to get idx for IPA_CLIENT_APPS_WAN_CONS", "ipa_teardown_sys_pipe", 2106);
LABEL_159:
          result = 0xFFFFFFFFLL;
          goto LABEL_148;
        }
      }
LABEL_160:
      result = 0xFFFFFFFFLL;
      goto LABEL_148;
    }
    if ( (unsigned int)ep_mapping > 0x23 )
      goto LABEL_183;
    if ( *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
    {
      v23 = ((__int64 (__fastcall *)(__int64))ipa3_teardown_pipe)(ep_mapping);
      if ( v23 )
      {
        v59 = v23;
        printk(&unk_3AF774, "ipa_teardown_sys_pipe");
        v77 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v78 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v78 )
          {
            ipc_log_string(v78, "ipa %s:%d failed to teardown default coal pipe\n", "ipa_teardown_sys_pipe", 2116);
            v77 = ipa3_ctx;
          }
          v79 = *(_QWORD *)(v77 + 34160);
          if ( v79 )
            ipc_log_string(v79, "ipa %s:%d failed to teardown default coal pipe\n", "ipa_teardown_sys_pipe", 2116);
        }
        goto LABEL_147;
      }
    }
  }
  v24 = *(_DWORD *)(v3 + 4);
  if ( v24 == 95 || v24 == 35 )
  {
    napi_disable(*(_QWORD *)(*(_QWORD *)(v3 + 472) + 384LL));
    v25 = _netif_napi_del(*(_QWORD *)(*(_QWORD *)(v3 + 472) + 384LL));
    synchronize_net(v25);
    v24 = *(_DWORD *)(v3 + 4);
  }
  if ( v24 != 127 )
    goto LABEL_69;
  v26 = ipa_get_ep_mapping(33);
  if ( (_DWORD)v26 == -1 )
  {
    printk(&unk_3F1F6C, "ipa_teardown_sys_pipe");
    v70 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v71 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v71 )
      {
        ipc_log_string(v71, "ipa %s:%d Failed to get idx for IPA_CLIENT_APPS_LAN_CONS,", "ipa_teardown_sys_pipe", 2133);
        v70 = ipa3_ctx;
      }
      v72 = *(_QWORD *)(v70 + 34160);
      if ( v72 )
      {
        ipc_log_string(v72, "ipa %s:%d Failed to get idx for IPA_CLIENT_APPS_LAN_CONS,", "ipa_teardown_sys_pipe", 2133);
        goto LABEL_159;
      }
    }
    goto LABEL_160;
  }
  if ( (unsigned int)v26 > 0x23 )
LABEL_183:
    __break(0x5512u);
  if ( *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)v26 + 168) )
  {
    v27 = ((__int64 (__fastcall *)(__int64))ipa3_teardown_pipe)(v26);
    if ( v27 )
    {
      v59 = v27;
      printk(&unk_3AF774, "ipa_teardown_sys_pipe");
      v80 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v81 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v81 )
        {
          ipc_log_string(v81, "ipa %s:%d failed to teardown default coal pipe\n", "ipa_teardown_sys_pipe", 2143);
          v80 = ipa3_ctx;
        }
        v82 = *(_QWORD *)(v80 + 34160);
        if ( v82 )
          ipc_log_string(v82, "ipa %s:%d failed to teardown default coal pipe\n", "ipa_teardown_sys_pipe", 2143);
      }
      goto LABEL_147;
    }
  }
LABEL_69:
  v28 = ipa3_reset_gsi_channel((_QWORD *)a1);
  if ( v28 )
  {
    v59 = v28;
    v60 = printk(&unk_3FDCAE, "ipa_teardown_sys_pipe");
    v63 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v64 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v64 )
      {
        ipc_log_string(v64, "ipa %s:%d Failed to reset chan: %d.\n", "ipa_teardown_sys_pipe", 2151, v59);
        v63 = ipa3_ctx;
      }
      v60 = *(_QWORD *)(v63 + 34160);
      if ( v60 )
        v60 = ipc_log_string(v60, "ipa %s:%d Failed to reset chan: %d.\n", "ipa_teardown_sys_pipe", 2151, v59);
    }
    goto LABEL_146;
  }
  dma_free_attrs(
    *(_QWORD *)(ipa3_ctx + 34216),
    *(unsigned int *)(v3 + 48),
    *(_QWORD *)(v3 + 64),
    *(_QWORD *)(v3 + 56),
    0);
  v29 = gsi_dealloc_channel(*(_QWORD *)(v3 + 8));
  if ( v29 )
  {
    v59 = v29;
    v60 = printk(&unk_3FDCD5, "ipa_teardown_sys_pipe");
    v65 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v66 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v66 )
      {
        ipc_log_string(v66, "ipa %s:%d Failed to dealloc chan: %d.\n", "ipa_teardown_sys_pipe", 2161, v59);
        v65 = ipa3_ctx;
      }
      v60 = *(_QWORD *)(v65 + 34160);
      if ( v60 )
        v60 = ipc_log_string(v60, "ipa %s:%d Failed to dealloc chan: %d.\n", "ipa_teardown_sys_pipe", 2161, v59);
    }
LABEL_146:
    ((void (__fastcall *)(__int64))ipa_assert)(v60);
LABEL_147:
    result = v59;
    goto LABEL_148;
  }
  if ( *(_BYTE *)(*(_QWORD *)(v3 + 472) + 124LL) == 1 )
  {
    *(_DWORD *)(ipa3_ctx + 32032) += *(_DWORD *)(v3 + 48);
  }
  else
  {
    v30 = *(_QWORD *)(v3 + 16);
    if ( v30 != -1 )
    {
      v31 = gsi_reset_evt_ring(v30);
      if ( v31 )
      {
        v83 = v31;
        _warn_printk("reset evt %d", v31);
        result = v83;
        __break(0x800u);
        goto LABEL_148;
      }
      dma_free_attrs(
        *(_QWORD *)(ipa3_ctx + 34216),
        *(unsigned int *)(v3 + 24),
        *(_QWORD *)(v3 + 40),
        *(_QWORD *)(v3 + 32),
        0);
      v32 = *(_QWORD *)(v3 + 80);
      if ( v32 )
      {
        dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), 8, v32, *(_QWORD *)(v3 + 72), 0);
        *(_QWORD *)(v3 + 72) = 0;
        *(_QWORD *)(v3 + 80) = 0;
      }
      v33 = gsi_dealloc_evt_ring(*(_QWORD *)(v3 + 16));
      if ( v33 )
      {
        v84 = v33;
        _warn_printk("deall evt %d", v33);
        result = v84;
        __break(0x800u);
        goto LABEL_148;
      }
    }
  }
  v34 = *(_QWORD *)(v3 + 472);
  v35 = *(_QWORD *)(v34 + 1760);
  if ( v35 )
  {
    _flush_workqueue(v35);
    v34 = *(_QWORD *)(v3 + 472);
  }
  if ( *(int *(__fastcall **)(int *))(v34 + 360) == ipa3_replenish_rx_page_recycle )
  {
    cancel_delayed_work_sync(*(_QWORD *)(v34 + 1944) + 1800LL);
    v36 = *(_QWORD *)(v3 + 472);
    v37 = *(_QWORD *)(v36 + 1792);
    if ( v37 )
    {
      _flush_workqueue(v37);
      v36 = *(_QWORD *)(v3 + 472);
    }
    tasklet_kill(*(_QWORD *)(v36 + 1944) + 1904LL);
  }
  v38 = *(_DWORD *)(v3 + 4);
  if ( v38 <= 0x85 && (v38 & 1) != 0 )
  {
    v39 = *(_QWORD *)(v3 + 472);
    if ( (*(_BYTE *)(v39 + 1609) & 1) == 0 )
      ipa3_cleanup_rx(v39);
  }
  if ( (*(_BYTE *)(v3 + 404) & 1) != 0 )
    goto LABEL_105;
  v40 = *(_DWORD *)(v3 + 4);
  if ( v40 <= 0x85 && (v40 & 1) == 0 )
  {
    v41 = ipa3_ctx;
    if ( *(_BYTE *)(ipa3_ctx + 32262) == 1 && ((v42 = (unsigned __int8)*(_DWORD *)(v3 + 4), v42 == 120) || v42 == 34) )
    {
      if ( ipa3_ctx )
      {
        v43 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v43 )
        {
          ipc_log_string(v43, "ipa %s:%d modem cfg emb pipe flt\n", "ipa_teardown_sys_pipe", 2212);
          v41 = ipa3_ctx;
        }
        v44 = *(_QWORD *)(v41 + 34160);
        if ( v44 )
          ipc_log_string(v44, "ipa %s:%d modem cfg emb pipe flt\n", "ipa_teardown_sys_pipe", 2212);
      }
    }
    else
    {
      ((void (__fastcall *)(_QWORD))ipa3_delete_dflt_flt_rules)(a1);
    }
LABEL_105:
    v40 = *(_DWORD *)(v3 + 4);
  }
  if ( v40 <= 0x11 && ((1 << v40) & 0x2A800) != 0 || v40 == 119 )
  {
    _X8 = (unsigned int *)(ipa3_ctx + 34648);
    __asm { PRFM            #0x11, [X8] }
    do
      v90 = __ldxr(_X8);
    while ( __stxr(v90 - 1, _X8) );
  }
  *(_QWORD *)(v3 + 432) = 0;
  *(_QWORD *)(v3 + 440) = 0;
  *(_QWORD *)(v3 + 416) = 0;
  *(_QWORD *)(v3 + 424) = 0;
  *(_QWORD *)(v3 + 408) = 0;
  if ( !*(_DWORD *)(ipa3_ctx + 34648) )
  {
    raw_spin_lock_bh(ipa3_ctx + 34608);
    v50 = ipa3_ctx;
    v51 = *(_QWORD **)(ipa3_ctx + 34632);
    if ( v51 == (_QWORD *)(ipa3_ctx + 34632) )
    {
      v55 = *(_DWORD *)(ipa3_ctx + 34620);
    }
    else
    {
      do
      {
        v53 = (_QWORD *)*v51;
        v52 = (_QWORD *)v51[1];
        if ( (_QWORD *)*v52 == v51 && (_QWORD *)v53[1] == v51 )
        {
          v53[1] = v52;
          *v52 = v53;
        }
        else
        {
          _list_del_entry_valid_or_report(v51);
        }
        v54 = v51[3];
        *v51 = 0xDEAD000000000100LL;
        v51[1] = 0xDEAD000000000122LL;
        dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), v54, 2048, 2, 0);
        dev_kfree_skb_any_reason(v51[2], 2);
        kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29448), v51);
        v50 = ipa3_ctx;
        v51 = v53;
        v55 = *(_DWORD *)(ipa3_ctx + 34620) - 1;
        v56 = *(_DWORD *)(ipa3_ctx + 34616) - 1;
        *(_DWORD *)(ipa3_ctx + 34620) = v55;
        *(_DWORD *)(v50 + 34616) = v56;
      }
      while ( v53 != (_QWORD *)(v50 + 34632) );
    }
    *(_DWORD *)(v50 + 34624) = 0;
    if ( v55 )
    {
      printk(&unk_3F516D, "ipa3_cleanup_wlan_rx_common_cache");
      v50 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v73 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v73 )
        {
          ipc_log_string(
            v73,
            "ipa %s:%d wlan comm buff free cnt: %d\n",
            "ipa3_cleanup_wlan_rx_common_cache",
            3323,
            *(_DWORD *)(ipa3_ctx + 34620));
          v50 = ipa3_ctx;
        }
        v74 = *(_QWORD *)(v50 + 34160);
        if ( v74 )
        {
          ipc_log_string(
            v74,
            "ipa %s:%d wlan comm buff free cnt: %d\n",
            "ipa3_cleanup_wlan_rx_common_cache",
            3323,
            *(_DWORD *)(v50 + 34620));
          v50 = ipa3_ctx;
        }
      }
    }
    if ( *(_DWORD *)(v50 + 34616) )
    {
      printk(&unk_3C99BB, "ipa3_cleanup_wlan_rx_common_cache");
      v50 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v75 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v75 )
        {
          ipc_log_string(
            v75,
            "ipa %s:%d wlan comm buff total cnt: %d\n",
            "ipa3_cleanup_wlan_rx_common_cache",
            3327,
            *(_DWORD *)(ipa3_ctx + 34616));
          v50 = ipa3_ctx;
        }
        v76 = *(_QWORD *)(v50 + 34160);
        if ( v76 )
        {
          ipc_log_string(
            v76,
            "ipa %s:%d wlan comm buff total cnt: %d\n",
            "ipa3_cleanup_wlan_rx_common_cache",
            3327,
            *(_DWORD *)(v50 + 34616));
          v50 = ipa3_ctx;
        }
      }
    }
    raw_spin_unlock_bh(v50 + 34608);
  }
  *(_DWORD *)v3 = 0;
  ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
    ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
  ipa3_dec_client_disable_clks();
  v57 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_129;
  v58 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v58 )
  {
    ipc_log_string(v58, "ipa %s:%d client (ep: %d) disconnected\n", "ipa_teardown_sys_pipe", 2229, a1);
    v57 = ipa3_ctx;
  }
  result = *(_QWORD *)(v57 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d client (ep: %d) disconnected\n", "ipa_teardown_sys_pipe", 2229, a1);
LABEL_129:
    result = 0;
  }
LABEL_148:
  _ReadStatusReg(SP_EL0);
  return result;
}
