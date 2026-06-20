__int64 __fastcall rmnet_offload_state_init(__int64 a1)
{
  _QWORD *v2; // x0
  __int64 v3; // x2
  unsigned int v4; // w19
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 v7; // x2
  __int64 v8; // x22
  __int64 v9; // x2
  __int64 v10; // x2

  v2 = (_QWORD *)_kmalloc_cache_noprof(_kcfi_typeid_rmnet_offload_handle_dl_header, 3520, 5312);
  rmnet_offload = (__int64)v2;
  if ( !v2 )
  {
    printk(&unk_872E, "rmnet_offload_state_init", v3);
    return 2;
  }
  *v2 = a1;
  v4 = rmnet_offload_engine_init();
  v5 = rmnet_offload;
  if ( (v4 & 0x80000000) != 0 )
  {
    kfree(rmnet_offload);
    rmnet_offload = 0;
    return v4;
  }
  v6 = *(_QWORD *)rmnet_offload;
  *(_QWORD *)(rmnet_offload + 64) = rmnet_offload_handle_powersave_on;
  *(_QWORD *)(v5 + 72) = rmnet_offload_handle_powersave_off;
  v4 = qmi_rmnet_ps_ind_register(v6, v5 + 64);
  if ( v4 )
    printk(&unk_891C, "rmnet_offload_state_register_cb", v7);
  v8 = rmnet_offload;
  *(_QWORD *)(rmnet_offload + 16) = rmnet_offload_handle_dl_header;
  *(_QWORD *)(v8 + 24) = rmnet_offload_handle_dl_trailer;
  *(_BYTE *)(v8 + 8) = 0;
  if ( (unsigned int)rmnet_map_dl_ind_register(v6, v8 + 8) )
  {
    printk(&unk_893F, "rmnet_offload_state_register_cb", v9);
    rmnet_offload_engine_enable_chain_flush();
    goto LABEL_12;
  }
  *(_BYTE *)(v8 + 56) = 1;
  rmnet_offload_engine_enable_chain_flush();
  if ( v4 )
  {
LABEL_12:
    printk(&unk_884F, "rmnet_offload_state_init", v10);
    v4 = 1;
  }
  *(_BYTE *)(rmnet_offload + 5304) = 1;
  rmnet_offload_set_hooks();
  return v4;
}
