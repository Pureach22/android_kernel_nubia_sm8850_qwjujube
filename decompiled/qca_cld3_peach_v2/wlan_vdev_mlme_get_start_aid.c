__int64 __fastcall wlan_vdev_mlme_get_start_aid(
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

  result = wlan_vdev_mlme_get_cmpt_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v10 = *(_QWORD *)(result + 248);
    if ( v10 )
      return *(unsigned __int16 *)(v10 + 256);
    else
      return 0;
  }
  return result;
}
