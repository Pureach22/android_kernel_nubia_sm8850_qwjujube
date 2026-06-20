__int64 __fastcall hdd_open_adapter_no_trans(
        __int64 *a1,
        unsigned int a2,
        const char *a3,
        unsigned __int8 *a4,
        _BYTE *a5)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  _DWORD *v20; // x0
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  rtnl_is_locked();
  v10 = osif_vdev_sync_create(a1[12], v21);
  if ( (_DWORD)v10 )
  {
    result = qdf_status_from_os_return(v10);
  }
  else
  {
    v20 = hdd_open_adapter(a1, a2, a3, a4, 0, 1, a5, v11, v12, v13, v14, v15, v16, v17, v18);
    if ( v20 )
    {
      osif_vdev_sync_register(*((_QWORD *)v20 + 4), v21[0]);
      result = 0;
    }
    else
    {
      osif_vdev_sync_destroy(v21[0]);
      result = 4;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
