__int64 __fastcall dsi_ctrl_get_io_resources(__int64 a1)
{
  _UNKNOWN **v2; // x20
  unsigned int io_mem; // w0
  __int64 v4; // x8
  const char *v5; // x3
  unsigned int v6; // w19

  mutex_lock(&dsi_ctrl_list_lock);
  v2 = &dsi_ctrl_list;
  do
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &dsi_ctrl_list )
    {
      mutex_unlock(&dsi_ctrl_list_lock);
      return 0;
    }
    io_mem = msm_dss_get_io_mem(*(_QWORD *)*(v2 - 1), (__int64 *)(a1 + 16));
  }
  while ( !io_mem );
  v4 = (__int64)*(v2 - 1);
  if ( v4 )
  {
    v5 = *(const char **)(v4 + 16);
    v6 = io_mem;
  }
  else
  {
    v6 = io_mem;
    v5 = "inv";
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: failed to get io mem, rc = %d\n", v5, v6);
  return v6;
}
