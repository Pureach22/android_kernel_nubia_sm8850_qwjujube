__int64 __fastcall ucfg_spatial_reuse_set_sr_enable(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0

  result = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
    *(_BYTE *)(result + 202) = a2 & 1;
  return result;
}
