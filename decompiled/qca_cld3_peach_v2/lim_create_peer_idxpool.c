__int64 __fastcall lim_create_peer_idxpool(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  __int64 result; // x0

  v11 = *(_QWORD *)(a1 + 16);
  *(_WORD *)(a1 + 7250) = 0;
  if ( *(_DWORD *)(v11 + 16) != 1 || (wlan_vdev_mlme_is_mlo_vdev(v11, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
  {
    result = _qdf_mem_malloc(a2, "lim_create_peer_idxpool_legacy", 101);
    *(_QWORD *)(a1 + 7240) = result;
    if ( !result )
      return result;
    *(_WORD *)(a1 + 7248) = 0;
  }
  return 1;
}
