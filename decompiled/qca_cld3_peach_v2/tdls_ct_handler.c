__int64 __fastcall tdls_ct_handler(__int64 result)
{
  __int64 v1; // x20
  __int64 tdls_link_vdev; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  double v12; // d0
  unsigned int *v13; // x8
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( result )
  {
    v1 = result;
    tdls_link_vdev = tdls_mlo_get_tdls_link_vdev(result);
    if ( tdls_link_vdev )
    {
      v11 = tdls_link_vdev;
      result = wlan_objmgr_vdev_try_get_ref(tdls_link_vdev, 0x11u, v3, v4, v5, v6, v7, v8, v9, v10);
      if ( !(_DWORD)result )
      {
        v12 = tdls_ct_process_handler(v11);
        return wlan_objmgr_vdev_release_ref(v11, 0x11u, v13, v12, v14, v15, v16, v17, v18, v19, v20);
      }
    }
    else
    {
      return ((__int64 (__fastcall *)(__int64))tdls_ct_process_handler)(v1);
    }
  }
  return result;
}
