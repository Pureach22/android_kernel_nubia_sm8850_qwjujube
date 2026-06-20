__int64 __fastcall hdd_restore_info_for_ssr(
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
  __int64 *v9; // x20

  v9 = *(__int64 **)(a1 + 24);
  if ( (cds_get_driver_state(a2, a3, a4, a5, a6, a7, a8, a9) & 8) != 0 )
  {
    hdd_set_vdev_phy_mode(a1, *(_DWORD *)(a1 + 52828));
    return wlan_mlme_restore_user_set_link_num(*v9);
  }
  else
  {
    hdd_set_vdev_phy_mode(a1, 0);
    return wlan_mlme_clear_user_set_link_num(*v9);
  }
}
