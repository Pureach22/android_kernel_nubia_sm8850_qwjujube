__int64 __fastcall dsi_phy_get_io_resources(__int64 a1)
{
  _UNKNOWN **v2; // x20
  unsigned int io_mem; // w0
  __int64 v4; // x8
  int v5; // w3
  unsigned int v6; // w19

  mutex_lock(&dsi_phy_list_lock);
  v2 = &dsi_phy_list;
  do
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &dsi_phy_list )
    {
      mutex_unlock(&dsi_phy_list_lock);
      return 0;
    }
    io_mem = msm_dss_get_io_mem(*(_QWORD *)*(v2 - 1), (__int64 *)(a1 + 16));
  }
  while ( !io_mem );
  v4 = (__int64)*(v2 - 1);
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 8);
    v6 = io_mem;
  }
  else
  {
    v6 = io_mem;
    v5 = -1;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: failed to get io mem, rc = %d\n", v5, v6);
  return v6;
}
