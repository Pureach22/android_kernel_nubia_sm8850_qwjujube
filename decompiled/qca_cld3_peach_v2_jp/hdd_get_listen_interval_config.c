__int64 __fastcall hdd_get_listen_interval_config(
        __int64 *a1,
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
  __int64 v10; // x8
  __int64 vdev_by_user; // x0
  __int64 v13; // x20
  int listen_interval; // w21
  const char *v15; // x2
  __int64 result; // x0
  __int64 v17; // [xsp+0h] [xbp-10h] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  LODWORD(v17) = 0;
  if ( (*(_DWORD *)(v10 + 40) | 2) != 2 )
  {
    v15 = "%s: Device not in STA / P2P-CLI mode";
    goto LABEL_9;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_get_listen_interval_config");
  if ( !vdev_by_user )
  {
    v15 = "%s: Failed to get vdev";
    goto LABEL_9;
  }
  v13 = vdev_by_user;
  listen_interval = ucfg_pmo_get_listen_interval(vdev_by_user, &v17);
  _hdd_objmgr_put_vdev_by_user(v13, 6, "hdd_get_listen_interval_config");
  if ( listen_interval )
  {
    v15 = "%s: vdev/vdev ctx NULL for getting listen interval";
LABEL_9:
    qdf_trace_msg(0x33u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_get_listen_interval_config", v17, v18);
    result = 4294967274LL;
    goto LABEL_10;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: listen interval %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_get_listen_interval_config",
    (unsigned int)v17);
  HIDWORD(v17) = v17;
  result = nla_put(a2, 48, 4, (char *)&v17 + 4);
  if ( (_DWORD)result )
  {
    v15 = "%s: nla_put failure";
    goto LABEL_9;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
