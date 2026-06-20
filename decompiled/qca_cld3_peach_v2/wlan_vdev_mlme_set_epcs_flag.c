__int64 __fastcall wlan_vdev_mlme_set_epcs_flag(
        __int64 result,
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
  __int64 v10; // x29
  __int64 v11; // x30

  if ( !result )
    return qdf_trace_msg(
             0x57u,
             2u,
             "%s: vdev is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_vdev_mlme_set_epcs_flag",
             v10,
             v11);
  *(_BYTE *)(result + 92) = a2 & 1;
  return result;
}
