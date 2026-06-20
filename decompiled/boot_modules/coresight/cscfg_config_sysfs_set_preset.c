__int64 __fastcall cscfg_config_sysfs_set_preset(int a1)
{
  mutex_lock(&cscfg_mutex);
  *(_DWORD *)(cscfg_mgr + 1172) = a1;
  return mutex_unlock(&cscfg_mutex);
}
