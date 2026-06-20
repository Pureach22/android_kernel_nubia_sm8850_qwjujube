bool __fastcall mlo_ap_vdev_quiet_is_any_idx_set(
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
  __int64 v9; // x19

  v9 = *(_QWORD *)(a1 + 1360);
  return v9
      && *(_DWORD *)(a1 + 16) == 1
      && (wlan_vdev_mlme_is_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0
      && wlan_util_map_is_any_index_set(*(_QWORD *)(v9 + 2232) + 80LL, 8);
}
