__int64 __fastcall ucfg_mlo_get_active_vdev_id(
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
  unsigned __int8 *v10; // x8

  if ( !*(_QWORD *)(a1 + 1360) )
    return 255;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
  {
    v10 = *(unsigned __int8 **)(*(_QWORD *)(a1 + 1360) + 3880LL);
    if ( (v10[40] & 1) != 0 )
      return v10[12];
    if ( (v10[88] & 1) != 0 )
      return v10[60];
    if ( v10[136] == 1 )
    {
      v10 += 96;
      return v10[12];
    }
  }
  return 255;
}
