__int64 __fastcall tdls_notify_reset_adapter(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 comp_private_obj; // x0
  unsigned int *v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( result )
  {
    v9 = result;
    result = wlan_objmgr_vdev_try_get_ref(result, 0x11u, a2, a3, a4, a5, a6, a7, a8, a9);
    if ( !(_DWORD)result )
    {
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v9, 0xAu);
      if ( comp_private_obj )
        tdls_timers_stop(comp_private_obj);
      return wlan_objmgr_vdev_release_ref(v9, 0x11u, v11, v12, v13, v14, v15, v16, v17, v18, v19);
    }
  }
  return result;
}
