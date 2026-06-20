__int64 __fastcall ucfg_spatial_reuse_set_sr_config(
        __int64 a1,
        char a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 cmpt_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( cmpt_obj )
    *(_BYTE *)(cmpt_obj + 182) = a2;
  result = wlan_vdev_mlme_get_cmpt_obj(a1, v15, v16, v17, v18, v19, v20, v21, v22);
  if ( result )
    *(_BYTE *)(result + 183) = a3;
  return result;
}
