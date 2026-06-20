__int64 __fastcall mlme_get_p2p_device_seq_num(
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

  result = wlan_vdev_mlme_get_cmpt_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
    return *(unsigned __int16 *)(result + 1016);
  return result;
}
