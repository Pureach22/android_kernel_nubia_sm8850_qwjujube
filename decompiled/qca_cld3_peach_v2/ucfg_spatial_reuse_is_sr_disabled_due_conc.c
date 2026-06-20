__int64 __fastcall ucfg_spatial_reuse_is_sr_disabled_due_conc(
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
  __int64 cmpt_obj; // x0
  char v10; // w8

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( cmpt_obj )
    v10 = *(_BYTE *)(cmpt_obj + 203);
  else
    v10 = 0;
  return v10 & 1;
}
