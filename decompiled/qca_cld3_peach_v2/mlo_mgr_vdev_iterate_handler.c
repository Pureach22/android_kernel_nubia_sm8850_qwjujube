void __fastcall mlo_mgr_vdev_iterate_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _DWORD *a11)
{
  char is_mlo_vdev; // w0
  __int64 v14; // x20
  unsigned int v15; // w21

  if ( !*a11 && !*(_DWORD *)(a10 + 16) )
  {
    is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(a10, a1, a2, a3, a4, a5, a6, a7, a8);
    if ( a10 )
    {
      if ( (is_mlo_vdev & 1) != 0 )
      {
        v14 = *(_QWORD *)(a10 + 1360);
        if ( v14 )
        {
          qdf_mutex_acquire(v14 + 1656);
          v15 = *(_DWORD *)(*(_QWORD *)(v14 + 3880) + 164LL);
          qdf_mutex_release(v14 + 1656);
          if ( v15 >= 2 )
            *a11 = 1;
        }
      }
    }
  }
}
