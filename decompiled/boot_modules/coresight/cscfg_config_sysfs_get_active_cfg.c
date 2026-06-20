__int64 __fastcall cscfg_config_sysfs_get_active_cfg(_QWORD *a1, _DWORD *a2)
{
  __int64 v4; // x8

  mutex_lock(&cscfg_mutex);
  v4 = cscfg_mgr;
  *a2 = *(_DWORD *)(cscfg_mgr + 1172);
  *a1 = *(unsigned int *)(v4 + 1168);
  return mutex_unlock(&cscfg_mutex);
}
