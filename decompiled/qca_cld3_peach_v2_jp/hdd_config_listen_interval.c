__int64 __fastcall hdd_config_listen_interval(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  __int64 v11; // x21
  __int64 vdev_by_user; // x0
  __int64 v13; // x20
  unsigned int v14; // w19

  v10 = *(_DWORD *)(a2 + 4);
  if ( v10 < 0xB )
  {
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 10, "hdd_config_listen_interval");
    if ( vdev_by_user )
    {
      v13 = vdev_by_user;
      v14 = ucfg_pmo_config_listen_interval(vdev_by_user, v10);
      _hdd_objmgr_put_vdev_by_user(v13, 10, "hdd_config_listen_interval");
      return qdf_status_to_os_return(v14);
    }
  }
  else
  {
    v11 = jiffies;
    if ( hdd_config_listen_interval___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid value for listen interval - %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "hdd_config_listen_interval",
        v10);
      hdd_config_listen_interval___last_ticks = v11;
    }
  }
  return 4294967274LL;
}
