__int64 __fastcall hdd_cm_save_conn_info_mld_addr(
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
  __int64 result; // x0
  int v13; // w9

  result = wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a1 + 32), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (result & 1) != 0 )
  {
    v13 = *(_DWORD *)(a2 + 153);
    *(_WORD *)(a1 + 984) = *(_WORD *)(a2 + 157);
    *(_DWORD *)(a1 + 980) = v13;
  }
  return result;
}
