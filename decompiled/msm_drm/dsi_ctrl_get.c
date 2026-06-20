__int64 __fastcall dsi_ctrl_get(__int64 a1)
{
  _UNKNOWN **v2; // x9
  __int64 v3; // x19
  int v4; // w8

  mutex_lock(&dsi_ctrl_list_lock);
  v2 = &dsi_ctrl_list;
  do
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &dsi_ctrl_list )
    {
      mutex_unlock(&dsi_ctrl_list_lock);
      goto LABEL_9;
    }
    v3 = (__int64)*(v2 - 1);
  }
  while ( *(_QWORD *)(*(_QWORD *)v3 + 760LL) != a1 );
  mutex_unlock(&dsi_ctrl_list_lock);
  if ( !v3 )
  {
LABEL_9:
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Device with of node not found rc=%d\n", "inv", -517);
    return -517;
  }
  mutex_lock(v3 + 32);
  v4 = *(_DWORD *)(v3 + 24);
  if ( *(_BYTE *)(v3 + 2898) == 1 )
  {
    if ( v4 != 2 )
    {
LABEL_7:
      *(_DWORD *)(v3 + 24) = v4 + 1;
      mutex_unlock(v3 + 32);
      return v3;
    }
  }
  else if ( v4 != 1 )
  {
    goto LABEL_7;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Device in use\n", *(const char **)(v3 + 16));
  mutex_unlock(v3 + 32);
  return -16;
}
