__int64 __fastcall lim_release_peer_idx(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10,
        __int64 a11)
{
  __int64 result; // x0
  __int64 v14; // x9

  result = *(_QWORD *)(a11 + 16);
  --*(_WORD *)(a11 + 7250);
  if ( *(_DWORD *)(result + 16) == 1 )
  {
    result = wlan_vdev_mlme_is_mlo_vdev(result, a1, a2, a3, a4, a5, a6, a7, a8);
    if ( (result & 1) != 0 )
      return mlme_free_aid(*(_QWORD *)(a11 + 16), a10);
  }
  if ( *(_BYTE *)(a11 + 7249) )
    *(_BYTE *)(*(_QWORD *)(a11 + 7240) + *(unsigned __int8 *)(a11 + 7249)) = a10;
  else
    *(_BYTE *)(a11 + 7248) = a10;
  v14 = *(_QWORD *)(a11 + 7240);
  *(_BYTE *)(a11 + 7249) = a10;
  *(_BYTE *)(v14 + (unsigned __int8)a10) = 0;
  return result;
}
