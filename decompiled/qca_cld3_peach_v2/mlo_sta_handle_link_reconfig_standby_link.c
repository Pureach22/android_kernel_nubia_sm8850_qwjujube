__int64 __fastcall mlo_sta_handle_link_reconfig_standby_link(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  __int64 v10; // x8
  __int64 (*v11)(void); // x8

  result = wlan_vdev_mlme_get_cmpt_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v10 = *(_QWORD *)(result + 528);
    if ( v10 )
    {
      v11 = *(__int64 (**)(void))(v10 + 224);
      if ( v11 )
      {
        if ( *((_DWORD *)v11 - 1) != 1578638804 )
          __break(0x8228u);
        return v11();
      }
    }
  }
  return result;
}
