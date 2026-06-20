__int64 __fastcall mlme_set_p2p_device_seq_num(
        __int64 a1,
        __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 cmpt_obj; // x0
  __int64 v12; // x8

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !cmpt_obj )
    return 16;
  v12 = cmpt_obj;
  *(_WORD *)(v12 + 1016) = a2;
  return 0;
}
