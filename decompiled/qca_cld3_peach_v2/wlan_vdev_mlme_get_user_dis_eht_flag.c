__int64 __fastcall wlan_vdev_mlme_get_user_dis_eht_flag(
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
  __int64 v9; // x29
  __int64 v10; // x30

  if ( a1 )
    return *(_BYTE *)(a1 + 95) & 1;
  qdf_trace_msg(
    0x57u,
    2u,
    "%s: vdev is NULL",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_vdev_mlme_get_user_dis_eht_flag",
    v9,
    v10);
  return 0;
}
