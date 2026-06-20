__int64 __fastcall dsi_display_hfi_setup_hfi(__int64 a1, __int64 a2)
{
  __int64 *v4; // x20
  __int64 v5; // x1
  __int64 result; // x0

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid display\n");
    return 4294967274LL;
  }
  if ( !a2 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid hfi_host\n");
    return 4294967274LL;
  }
  v4 = (__int64 *)_kvmalloc_node_noprof(88, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(a1 + 1688) = v4;
  *(_QWORD *)(a1 + 1696) = dsi_hfi_prop_handler;
  *v4 = a2;
  v5 = _kmalloc_cache_noprof(_init_waitqueue_head, 3264, 144);
  v4[1] = v5;
  if ( !v5 )
    return 4294967284LL;
  *(_QWORD *)(v5 + 112) = dsi_hfi_process_cmd_buf;
  result = hfi_adapter_client_register(a2, v5);
  if ( (_DWORD)result )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: unable to register hfi client\n");
    kfree(v4[1]);
    return 4294967277LL;
  }
  return result;
}
