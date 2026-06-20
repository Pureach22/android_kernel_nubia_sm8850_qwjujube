__int64 __fastcall hfi_connector_init(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x0
  _QWORD *v4; // x20
  __int64 v5; // x1
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  __int64 result; // x0

  v3 = _kvmalloc_node_noprof(72, 0, 3520, 0xFFFFFFFFLL);
  v4 = (_QWORD *)v3;
  if ( !v3 )
  {
    printk(&unk_24F85C, "hfi_connector_init");
    return 4294967284LL;
  }
  _mutex_init(v3 + 8, "&hfi_conn->hfi_lock", &hfi_connector_init___key);
  if ( a2 )
  {
    a2[647] = hfi_connector_destroy;
    a2[668] = hfi_connector_prepare_commit;
  }
  else
  {
    printk(&unk_211DA1, "_sde_connector_hal_funcs_install");
  }
  v6 = hfi_util_kv_helper_alloc(128, v5);
  v4[8] = v6;
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_24C20C, "hfi_connector_init");
LABEL_11:
    kfree(v4);
    return 4294967284LL;
  }
  v7 = hfi_util_u32_prop_helper_alloc(1024);
  v4[7] = v7;
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_242684, "hfi_connector_init");
    kfree(v4[7]);
    goto LABEL_11;
  }
  result = 0;
  *v4 = a2;
  a2[642] = v4;
  return result;
}
