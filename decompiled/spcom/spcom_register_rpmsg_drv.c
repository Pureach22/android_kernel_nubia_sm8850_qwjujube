__int64 __fastcall spcom_register_rpmsg_drv(__int64 a1)
{
  __int64 *v2; // x20
  char *v3; // x0
  char *v4; // x21
  __int64 v5; // x0
  __int64 v6; // x22
  unsigned int v7; // w0
  __int64 *v9; // x0
  unsigned int v10; // w24

  if ( *(_QWORD *)(a1 + 152) )
  {
    printk(&unk_103EF, "spcom_register_rpmsg_drv", a1);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch:%s, rpmsg driver %s already registered\n",
      "spcom_register_rpmsg_drv",
      (const char *)&unk_F80E,
      (const char *)a1,
      *(const char **)(*(_QWORD *)(a1 + 152) + 176LL));
    return 4294967277LL;
  }
  v2 = (__int64 *)_kmalloc_cache_noprof(kmemdup_noprof, 3520, 216);
  if ( !v2 )
    return 4294967284LL;
  v3 = (char *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
  v4 = v3;
  if ( !v3 )
  {
    v9 = v2;
    goto LABEL_11;
  }
  snprintf(v3, 0x20u, "%s", (const char *)a1);
  v5 = kasprintf(3264, "%s_%s", "spcom_rpmsg_drv", (const char *)a1);
  if ( !v5 )
  {
    printk(&unk_10D34, "spcom_register_rpmsg_drv", a1);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: can't allocate drv_name for %s\n",
      "spcom_register_rpmsg_drv",
      (const char *)&unk_F80E,
      (const char *)a1);
    kfree(v2);
    v9 = (__int64 *)v4;
LABEL_11:
    kfree(v9);
    return 4294967284LL;
  }
  v6 = v5;
  *v2 = v5;
  v2[24] = (__int64)spcom_rpdev_remove;
  v2[25] = (__int64)spcom_rpdev_cb;
  v2[22] = (__int64)v4;
  v2[23] = (__int64)spcom_rpdev_probe;
  v7 = _register_rpmsg_driver(v2, &_this_module);
  if ( v7 )
  {
    v10 = v7;
    printk(&unk_11C63, "spcom_register_rpmsg_drv", a1);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: can't register rpmsg_driver for %s\n",
      "spcom_register_rpmsg_drv",
      (const char *)&unk_F80E,
      (const char *)a1);
    kfree(v2);
    kfree(v4);
    kfree(v6);
    return v10;
  }
  else
  {
    mutex_lock(a1 + 32);
    *(_QWORD *)(a1 + 152) = v2;
    *(_BYTE *)(a1 + 316) = 0;
    mutex_unlock(a1 + 32);
    return 0;
  }
}
