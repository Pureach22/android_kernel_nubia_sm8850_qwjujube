__int64 cleanup_module()
{
  __int64 i; // x21
  _QWORD *j; // x20
  _QWORD *v2; // x8
  _QWORD *v3; // x9
  __int64 v4; // x0
  __int64 v5; // x0

  platform_driver_unregister(fastrpc_cb_driver);
  idr_destroy(&qword_27518);
  mutex_lock(&unk_26CD8);
  for ( i = 0; i != 256; ++i )
  {
    for ( j = *(_QWORD **)&g_frpc[2 * i + 26]; j; j = (_QWORD *)*j )
    {
      fastrpc_sysfs_domain_remove(j);
      v2 = (_QWORD *)j[1];
      if ( v2 )
      {
        v3 = (_QWORD *)*j;
        *v2 = *j;
        if ( v3 )
          v3[1] = v2;
        *j = 0;
        j[1] = 0;
      }
      kfree(j);
    }
  }
  v4 = mutex_unlock(&unk_26CD8);
  v5 = fastrpc_sysfs_deregister_kset(v4);
  fastrpc_transport_deinit(v5);
  return debugfs_remove(qword_27538);
}
