__int64 __fastcall hfi_crtc_init(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x1
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  int v8; // w0
  int v9; // w21
  void *v11; // x0

  if ( !a1 )
    return 4294967274LL;
  v2 = _kvmalloc_node_noprof(152, 0, 3520, 0xFFFFFFFFLL);
  v3 = v2;
  if ( !v2 )
  {
    printk(&unk_2688BD, "hfi_crtc_init");
    return 4294967284LL;
  }
  a1[1009] = hfi_crtc_destroy;
  a1[1033] = hfi_crtc_atomic_begin;
  a1[1051] = hfi_crtc_debugfs_misr_setup;
  a1[1054] = hfi_crtc_debugfs_misr_read;
  _mutex_init(v2 + 8, "&crtc->hfi_lock", &hfi_crtc_custom_kv_props_map);
  v5 = hfi_util_kv_helper_alloc(128, v4);
  *(_QWORD *)(v3 + 72) = v5;
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_219369, "hfi_crtc_init");
LABEL_16:
    kfree(v3);
    return 4294967284LL;
  }
  v6 = hfi_util_u32_prop_helper_alloc(1024);
  *(_QWORD *)(v3 + 56) = v6;
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = &unk_242684;
LABEL_15:
    printk(v11, "hfi_crtc_init");
    kfree(*(_QWORD *)(v3 + 56));
    kfree(*(_QWORD *)(v3 + 72));
    goto LABEL_16;
  }
  v7 = hfi_util_u32_prop_helper_alloc(1024);
  *(_QWORD *)(v3 + 64) = v7;
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = &unk_27693C;
    goto LABEL_15;
  }
  *(_DWORD *)(v3 + 104) = 4224;
  v8 = hfi_adapter_buffer_alloc(v3 + 88);
  if ( v8 )
  {
    *(_DWORD *)(v3 + 104) = 0;
    if ( (_drm_debug & 4) != 0 )
    {
      v9 = v8;
      _drm_dev_dbg(0, 0, 0, "failed to allocate shared memory for SPR Dither, ret: %d\n", v8);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "failed to allocated shared memory for dither payloads ret: %d\n", v9);
    }
  }
  *(_QWORD *)v3 = a1;
  a1[1004] = v3;
  return 0;
}
