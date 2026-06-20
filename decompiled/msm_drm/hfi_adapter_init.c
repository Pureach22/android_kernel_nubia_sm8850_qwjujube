__int64 __fastcall hfi_adapter_init(int a1)
{
  __int64 v2; // x19
  __int64 (__fastcall **v3)(__int64, __int64); // x23
  __int64 v4; // x0
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x21
  _QWORD *v7; // x0
  _QWORD *v8; // x21
  _QWORD *v9; // x22
  int v10; // w20
  __int64 v11; // x0
  __int64 v12; // x27
  _QWORD *v13; // x0
  _QWORD *v14; // x1
  void *v15; // x0
  __int64 v17; // [xsp+20h] [xbp-20h] BYREF
  __int64 (__fastcall **v18)(__int64, __int64); // [xsp+28h] [xbp-18h]
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = nullptr;
  v19 = 0;
  v17 = 0;
  v2 = _kmalloc_cache_noprof(msleep, 3264, 416);
  if ( v2 )
  {
    v3 = (__int64 (__fastcall **)(__int64, __int64))_kmalloc_cache_noprof(kthread_create_on_node, 3264, 16);
    if ( !v3 )
    {
      printk(&unk_211CB9, "hfi_adapter_init");
LABEL_23:
      kfree(v2);
      v2 = 0;
      goto LABEL_24;
    }
    *v3 = callback_function_hfi;
    v3[1] = (__int64 (__fastcall *)(__int64, __int64))v2;
    LODWORD(v17) = 1;
    v18 = v3;
    v4 = hfi_core_open_session(&v17);
    if ( v4 )
    {
      *(_DWORD *)v2 = a1;
      *(_QWORD *)(v2 + 8) = v2 + 8;
      *(_QWORD *)(v2 + 16) = v2 + 8;
      *(_QWORD *)(v2 + 24) = v3;
      *(_QWORD *)(v2 + 32) = v4;
      *(_QWORD *)(v2 + 64) = 0;
      *(_QWORD *)(v2 + 72) = 0;
      *(_QWORD *)(v2 + 40) = v2 + 40;
      *(_QWORD *)(v2 + 48) = v2 + 40;
      *(_QWORD *)(v2 + 56) = process_cb_buffer_work;
      *(_QWORD *)(v2 + 80) = v2;
      *(_DWORD *)(v2 + 88) = 0;
      *(_QWORD *)(v2 + 120) = 0;
      *(_QWORD *)(v2 + 128) = 0;
      *(_QWORD *)(v2 + 96) = v2 + 96;
      *(_QWORD *)(v2 + 104) = v2 + 96;
      *(_QWORD *)(v2 + 112) = process_cb_buffer_work;
      *(_QWORD *)(v2 + 136) = v2;
      *(_DWORD *)(v2 + 144) = 1;
      *(_QWORD *)(v2 + 176) = 0;
      *(_QWORD *)(v2 + 184) = 0;
      *(_QWORD *)(v2 + 152) = v2 + 152;
      *(_QWORD *)(v2 + 160) = v2 + 152;
      *(_DWORD *)(v2 + 200) = 2;
      *(_QWORD *)(v2 + 168) = process_cb_buffer_work;
      *(_QWORD *)(v2 + 192) = v2;
      *(_QWORD *)(v2 + 232) = 0;
      *(_QWORD *)(v2 + 240) = 0;
      *(_QWORD *)(v2 + 208) = v2 + 208;
      *(_QWORD *)(v2 + 216) = v2 + 208;
      *(_QWORD *)(v2 + 224) = process_cb_buffer_work;
      *(_QWORD *)(v2 + 248) = v2;
      *(_DWORD *)(v2 + 256) = 3;
      _kthread_init_worker(v2 + 264, "(&hfi_host->cb_worker)->lock", &hfi_adapter_init___key);
      v5 = kthread_create_on_node(&kthread_worker_fn, v2 + 264, 0xFFFFFFFFLL, "adapter_cb_thread");
      v6 = v5;
      if ( v5 >= 0xFFFFFFFFFFFFF001LL )
      {
        v15 = &unk_279B1D;
        *(_QWORD *)(v2 + 320) = v6;
      }
      else
      {
        wake_up_process(v5);
        *(_QWORD *)(v2 + 320) = v6;
        *(_QWORD *)(v2 + 328) = 0x1000000400000000LL;
        *(_QWORD *)(v2 + 336) = 0;
        *(_QWORD *)(v2 + 344) = 0;
        *(_DWORD *)(v2 + 360) = 0;
        _mutex_init(v2 + 368, "&hfi_host->hfi_adapter_cmd_buf_list_lock", &hfi_adapter_init___key_14);
        v7 = (_QWORD *)_kmalloc_cache_noprof(drm_dp_dpcd_read, 3264, 232);
        v8 = v7;
        if ( v7 )
        {
          v9 = v7 + 6;
          v7[6] = v7 + 6;
          v7[7] = v7 + 6;
          v7[22] = v7 + 22;
          v7[23] = v7 + 22;
          _mutex_init(v7, "&pool->lock", &hfi_adapter_init___key_19);
          _mutex_init(v8 + 9, "&pool->buffer_t.lock", &hfi_adapter_init___key_21);
          v10 = 8;
          v8[27] = v8;
          _ReadStatusReg(SP_EL0);
          *((_DWORD *)v8 + 30) = 0;
          v8[16] = 0;
          *((_DWORD *)v8 + 16) = 1;
          *((_DWORD *)v8 + 56) = 0;
          while ( 1 )
          {
            v11 = _kmalloc_cache_noprof(drm_dp_dpcd_read, 3264, 232);
            v12 = v11;
            if ( !v11 )
              break;
            v13 = (_QWORD *)(v11 + 48);
            *(_QWORD *)(v12 + 176) = v12 + 176;
            *(_QWORD *)(v12 + 184) = v12 + 176;
            v14 = (_QWORD *)v8[7];
            if ( (_QWORD *)v12 == v8 || v14 == v13 || (_QWORD *)*v14 != v9 )
            {
              _list_add_valid_or_report(v13, v14);
            }
            else
            {
              v8[7] = v13;
              *(_QWORD *)(v12 + 48) = v9;
              *(_QWORD *)(v12 + 56) = v14;
              *v14 = v13;
            }
            *(_DWORD *)(v12 + 64) = 1;
            _mutex_init(v12, "&link->lock", &hfi_adapter_init___key_25);
            _mutex_init(v12 + 72, "&link->buffer_t.lock", &hfi_adapter_init___key_27);
            --v10;
            *(_QWORD *)(v12 + 216) = v12;
            *(_DWORD *)(v12 + 120) = 0;
            *(_QWORD *)(v12 + 128) = 0;
            *(_DWORD *)(v12 + 64) = 1;
            *(_DWORD *)(v12 + 224) = 0;
            if ( !v10 )
            {
              *(_QWORD *)(v2 + 352) = v8;
              goto LABEL_24;
            }
          }
          printk(&unk_256A13, "hfi_adapter_init");
          kfree(v8);
          goto LABEL_22;
        }
        v15 = &unk_256A13;
      }
    }
    else
    {
      v15 = &unk_2652CE;
    }
    printk(v15, "hfi_adapter_init");
LABEL_22:
    kfree(v3);
    goto LABEL_23;
  }
  printk(&unk_237CF5, "hfi_adapter_init");
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v2;
}
