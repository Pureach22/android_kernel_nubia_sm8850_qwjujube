__int64 __fastcall dsi_phy_get(__int64 a1)
{
  _UNKNOWN **v2; // x9
  __int64 v3; // x19
  int v4; // w8

  mutex_lock(&dsi_phy_list_lock);
  v2 = &dsi_phy_list;
  do
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &dsi_phy_list )
    {
      mutex_unlock(&dsi_phy_list_lock);
      goto LABEL_9;
    }
    v3 = (__int64)*(v2 - 1);
  }
  while ( *(_QWORD *)(*(_QWORD *)v3 + 760LL) != a1 );
  mutex_unlock(&dsi_phy_list_lock);
  if ( !v3 )
  {
LABEL_9:
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Device with of node not found rc=%d\n", -1, -517);
    return -517;
  }
  mutex_lock(v3 + 32);
  v4 = *(_DWORD *)(v3 + 24);
  if ( *(_BYTE *)(v3 + 1362) == 1 )
  {
    if ( v4 != 2 )
      goto LABEL_7;
LABEL_11:
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Device under use\n", *(_DWORD *)(v3 + 8));
    v3 = -22;
  }
  else
  {
    if ( v4 == 1 )
      goto LABEL_11;
LABEL_7:
    *(_DWORD *)(v3 + 24) = v4 + 1;
  }
  *(_DWORD *)(v3 + 28) = 0;
  mutex_unlock(v3 + 32);
  return v3;
}
