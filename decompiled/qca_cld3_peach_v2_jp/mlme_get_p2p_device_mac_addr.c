__int64 __fastcall mlme_get_p2p_device_mac_addr(
        __int64 a1,
        __int64 a2,
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
  int v14; // w9

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !cmpt_obj )
    return 16;
  v12 = cmpt_obj;
  v14 = *(_DWORD *)(v12 + 994);
  *(_WORD *)(a2 + 4) = *(_WORD *)(v12 + 998);
  *(_DWORD *)a2 = v14;
  return 0;
}
