__int64 cscfg_init()
{
  unsigned int v0; // w19
  __int64 v2; // x0
  __int64 v3; // x20
  unsigned int v4; // w0

  mutex_lock(&cscfg_mutex);
  if ( cscfg_mgr )
  {
    v0 = -22;
LABEL_3:
    mutex_unlock(&cscfg_mutex);
    return v0;
  }
  v2 = _kmalloc_cache_noprof(idr_remove, 3520, 1184);
  v3 = v2;
  cscfg_mgr = v2;
  if ( !v2 )
  {
    v0 = -12;
    goto LABEL_3;
  }
  *(_QWORD *)(v2 + 912) = v2 + 912;
  *(_QWORD *)(v2 + 920) = v2 + 912;
  *(_QWORD *)(v2 + 928) = v2 + 928;
  *(_QWORD *)(v2 + 936) = v2 + 928;
  *(_QWORD *)(v2 + 944) = v2 + 944;
  *(_QWORD *)(v2 + 952) = v2 + 944;
  *(_QWORD *)(v2 + 960) = v2 + 960;
  *(_QWORD *)(v2 + 968) = v2 + 960;
  *(_DWORD *)(v2 + 976) = 0;
  *(_QWORD *)(v2 + 808) = cscfg_dev_release;
  *(_DWORD *)(v2 + 1176) = 0;
  *(_QWORD *)(v2 + 112) = "cs_system_cfg";
  v4 = device_register(v2);
  if ( v4 )
  {
    v0 = v4;
    put_device(v3);
    goto LABEL_3;
  }
  mutex_unlock(&cscfg_mutex);
  v0 = cscfg_configfs_init((_QWORD *)cscfg_mgr);
  if ( v0 || (v0 = cscfg_preload((__int64)&_this_module)) != 0 )
    cscfg_clear_device();
  else
    dev_info(cscfg_mgr, "CoreSight Configuration manager initialised");
  return v0;
}
