__int64 __fastcall ipa_eth_register_ready_cb(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 *v7; // x0
  __int64 v8; // x2
  __int64 *v9; // x20
  __int64 *v10; // x1
  unsigned int ready; // w0
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 *v17; // x0
  __int64 v18; // x2
  __int64 *v19; // x1
  unsigned int v20; // w19
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 **v23; // x9
  __int64 v24; // x10
  __int64 *v25; // x8
  __int64 v26; // x9
  _QWORD *v27; // x0
  _QWORD *v28; // x8
  _QWORD *v29; // x22
  _QWORD *v30; // x9
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x8
  _QWORD *v36; // x0
  _QWORD *v37; // x8
  _QWORD *v38; // x20
  _QWORD *v39; // x9
  _QWORD v40[5]; // [xsp+8h] [xbp-28h] BYREF

  v40[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    printk(&unk_3CE0D5, "ipa_eth_register_ready_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_eth %s:%d null ready_info", "ipa_eth_register_ready_cb", 225);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_eth %s:%d null ready_info", "ipa_eth_register_ready_cb", 225);
    }
    result = 4294967282LL;
    goto LABEL_73;
  }
  if ( ipa_eth_ctx )
  {
    printk(&unk_3F6386, "ipa_eth_register_ready_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      v15 = ipa3_get_ipc_logbuf();
      ipc_log_string(v15, "ipa_eth %s:%d multiple eth register happens\n", "ipa_eth_register_ready_cb", 256);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v16 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v16, "ipa_eth %s:%d multiple eth register happens\n", "ipa_eth_register_ready_cb", 256);
    }
    mutex_lock(ipa_eth_ctx + 192);
    v17 = (__int64 *)_kmalloc_cache_noprof(of_property_read_variable_u32_array, 3264, 24);
    if ( !v17 )
    {
      mutex_unlock(ipa_eth_ctx + 192);
LABEL_72:
      result = 4294967284LL;
      goto LABEL_73;
    }
    v18 = ipa_eth_ctx;
    v17[2] = a1;
    v19 = *(__int64 **)(v18 + 8);
    if ( v17 == (__int64 *)v18 || v19 == v17 || *v19 != v18 )
    {
      _list_add_valid_or_report(v17, v19);
      if ( !(unsigned int)ipa3_uc_loaded_check() )
      {
LABEL_32:
        mutex_unlock(ipa_eth_ctx + 192);
        result = ipa3_uc_loaded_check();
        if ( !(_DWORD)result )
          goto LABEL_73;
        goto LABEL_16;
      }
    }
    else
    {
      *(_QWORD *)(v18 + 8) = v17;
      *v17 = v18;
      v17[1] = (__int64)v19;
      *v19 = (__int64)v17;
      if ( !(unsigned int)ipa3_uc_loaded_check() )
        goto LABEL_32;
    }
    queue_work_on(32, *(_QWORD *)(ipa_eth_ctx + 240), &ipa_eth_ready_notify);
    goto LABEL_32;
  }
  memset((char *)&v40[2] + 3, 0, 13);
  *(_QWORD *)((char *)&v40[1] + 3) = 0;
  ipa_eth_ctx = _kmalloc_cache_noprof(scnprintf, 3520, 312);
  if ( !ipa_eth_ctx )
  {
    printk(&unk_3F3AE1, "ipa_eth_init_internal");
    if ( ipa3_get_ipc_logbuf() )
    {
      v31 = ipa3_get_ipc_logbuf();
      ipc_log_string(v31, "ipa_eth %s:%d fail to alloc eth ctx\n", "ipa_eth_init_internal", 137);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v32 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v32, "ipa_eth %s:%d fail to alloc eth ctx\n", "ipa_eth_init_internal", 137);
    }
    goto LABEL_59;
  }
  strcpy((char *)v40, "ipa_eth_wq");
  v2 = alloc_workqueue((const char *)v40, 74, 1);
  v3 = ipa_eth_ctx;
  *(_QWORD *)(ipa_eth_ctx + 240) = v2;
  if ( !v2 )
  {
    kfree(v3);
    ipa_eth_ctx = 0;
LABEL_59:
    printk(&unk_3A4F33, "ipa_eth_register_ready_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      v33 = ipa3_get_ipc_logbuf();
      ipc_log_string(v33, "ipa_eth %s:%d initialization failure\n", "ipa_eth_register_ready_cb", 233);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v34 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v34, "ipa_eth %s:%d initialization failure\n", "ipa_eth_register_ready_cb", 233);
    }
    goto LABEL_72;
  }
  _mutex_init(v3 + 192, "&ipa_eth_ctx->lock", &ipa_eth_init_internal___key);
  v4 = ipa_eth_ctx;
  *(_QWORD *)ipa_eth_ctx = ipa_eth_ctx;
  *(_QWORD *)(v4 + 8) = v4;
  *(_BYTE *)(v4 + 248) = 0;
  *(_DWORD *)(v4 + 48) = 0;
  *(_BYTE *)(v4 + 56) = 0;
  *(_DWORD *)(v4 + 52) = 0;
  *(_DWORD *)(v4 + 60) = 0;
  *(_BYTE *)(v4 + 68) = 0;
  *(_DWORD *)(v4 + 64) = 0;
  *(_DWORD *)(v4 + 72) = 0;
  *(_BYTE *)(v4 + 80) = 0;
  *(_DWORD *)(v4 + 76) = 0;
  *(_DWORD *)(v4 + 84) = 0;
  *(_BYTE *)(v4 + 92) = 0;
  *(_DWORD *)(v4 + 88) = 0;
  *(_DWORD *)(v4 + 96) = 0;
  *(_BYTE *)(v4 + 104) = 0;
  *(_DWORD *)(v4 + 100) = 0;
  *(_DWORD *)(v4 + 108) = 0;
  *(_BYTE *)(v4 + 116) = 0;
  *(_DWORD *)(v4 + 112) = 0;
  *(_DWORD *)(v4 + 120) = 0;
  *(_BYTE *)(v4 + 128) = 0;
  *(_DWORD *)(v4 + 124) = 0;
  *(_DWORD *)(v4 + 132) = 0;
  *(_BYTE *)(v4 + 140) = 0;
  *(_DWORD *)(v4 + 136) = 0;
  *(_DWORD *)(v4 + 144) = 0;
  *(_BYTE *)(v4 + 152) = 0;
  *(_DWORD *)(v4 + 148) = 0;
  *(_DWORD *)(v4 + 156) = 0;
  *(_BYTE *)(v4 + 164) = 0;
  *(_DWORD *)(v4 + 160) = 0;
  *(_DWORD *)(v4 + 168) = 0;
  *(_BYTE *)(v4 + 176) = 0;
  *(_DWORD *)(v4 + 172) = 0;
  *(_DWORD *)(v4 + 180) = 0;
  *(_BYTE *)(v4 + 188) = 0;
  *(_DWORD *)(v4 + 184) = 0;
  *(_QWORD *)(v4 + 256) = 0x1000000400000000LL;
  *(_DWORD *)(v4 + 280) = 0;
  *(_QWORD *)(v4 + 264) = 0;
  *(_QWORD *)(v4 + 272) = 0;
  *(_QWORD *)(v4 + 288) = v4 + 288;
  *(_QWORD *)(v4 + 296) = v4 + 288;
  *(_QWORD *)(v4 + 304) = 0;
  ipa3_eth_debugfs_init();
  if ( ipa3_get_ipc_logbuf() )
  {
    v5 = ipa3_get_ipc_logbuf();
    ipc_log_string(v5, "ipa_eth %s:%d ipa_eth register ready cb\n", "ipa_eth_register_ready_cb", 236);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v6, "ipa_eth %s:%d ipa_eth register ready cb\n", "ipa_eth_register_ready_cb", 236);
  }
  mutex_lock(ipa_eth_ctx + 192);
  v7 = (__int64 *)_kmalloc_cache_noprof(of_property_read_variable_u32_array, 3264, 24);
  if ( !v7 )
  {
    mutex_unlock(ipa_eth_ctx + 192);
    v35 = ipa_eth_ctx;
    if ( ipa_eth_ctx )
    {
      v36 = *(_QWORD **)(ipa_eth_ctx + 288);
      if ( v36 != (_QWORD *)(ipa_eth_ctx + 288) )
      {
        do
        {
          v38 = (_QWORD *)*v36;
          v37 = (_QWORD *)v36[1];
          if ( (_QWORD *)*v37 == v36 && (_QWORD *)v38[1] == v36 )
          {
            v38[1] = v37;
            *v37 = v38;
          }
          else
          {
            _list_del_entry_valid_or_report(v36);
            v36 = v39;
          }
          *v36 = 0xDEAD000000000100LL;
          v36[1] = 0xDEAD000000000122LL;
          kfree(v36);
          v35 = ipa_eth_ctx;
          v36 = v38;
        }
        while ( v38 != (_QWORD *)(ipa_eth_ctx + 288) );
      }
      destroy_workqueue(*(_QWORD *)(v35 + 240));
      kfree(ipa_eth_ctx);
      ipa_eth_ctx = 0;
    }
    goto LABEL_72;
  }
  v8 = ipa_eth_ctx;
  v7[2] = a1;
  v9 = v7;
  v10 = *(__int64 **)(v8 + 8);
  if ( v7 == (__int64 *)v8 || v10 == v7 || *v10 != v8 )
  {
    _list_add_valid_or_report(v7, v10);
    v8 = ipa_eth_ctx;
  }
  else
  {
    *(_QWORD *)(v8 + 8) = v7;
    *v7 = v8;
    v7[1] = (__int64)v10;
    *v10 = (__int64)v7;
  }
  mutex_unlock(v8 + 192);
  ready = ipa3_uc_register_ready_cb((_DWORD **)&uc_rdy_cb);
  if ( ready )
  {
    v20 = ready;
    printk(&unk_3DF7E7, "ipa_eth_register_ready_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      v21 = ipa3_get_ipc_logbuf();
      ipc_log_string(v21, "ipa_eth %s:%d Failed to register ready cb\n", "ipa_eth_register_ready_cb", 251);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v22 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v22, "ipa_eth %s:%d Failed to register ready cb\n", "ipa_eth_register_ready_cb", 251);
    }
    v23 = (__int64 **)v9[1];
    if ( *v23 == v9 && (v24 = *v9, v25 = v9, *(__int64 **)(*v9 + 8) == v9) )
    {
      *(_QWORD *)(v24 + 8) = v23;
      *v23 = (__int64 *)v24;
    }
    else
    {
      _list_del_entry_valid_or_report(v9);
      v25 = v9;
    }
    v26 = ipa_eth_ctx;
    *v25 = 0xDEAD000000000100LL;
    v25[1] = 0xDEAD000000000122LL;
    if ( v26 )
    {
      v27 = *(_QWORD **)(v26 + 288);
      if ( v27 != (_QWORD *)(v26 + 288) )
      {
        do
        {
          v29 = (_QWORD *)*v27;
          v28 = (_QWORD *)v27[1];
          if ( (_QWORD *)*v28 == v27 && (_QWORD *)v29[1] == v27 )
          {
            v29[1] = v28;
            *v28 = v29;
          }
          else
          {
            _list_del_entry_valid_or_report(v27);
            v27 = v30;
          }
          *v27 = 0xDEAD000000000100LL;
          v27[1] = 0xDEAD000000000122LL;
          kfree(v27);
          v26 = ipa_eth_ctx;
          v27 = v29;
        }
        while ( v29 != (_QWORD *)(ipa_eth_ctx + 288) );
      }
      destroy_workqueue(*(_QWORD *)(v26 + 240));
      kfree(ipa_eth_ctx);
      ipa_eth_ctx = 0;
    }
    result = v20;
  }
  else
  {
    result = ipa3_uc_loaded_check();
    if ( (_DWORD)result )
    {
LABEL_16:
      result = 0;
      *(_BYTE *)(a1 + 16) = 1;
    }
  }
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return result;
}
