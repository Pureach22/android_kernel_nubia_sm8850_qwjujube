__int64 __fastcall lim_init_peer_idxpool(
        __int64 result,
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
  __int64 v11; // x20
  __int64 v12; // x10
  __int64 v13; // x9
  unsigned int v14; // w11
  bool v15; // zf

  v11 = result;
  if ( *(_DWORD *)(*(_QWORD *)(a2 + 16) + 16LL) != 1
    || (result = wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a2 + 16), a3, a4, a5, a6, a7, a8, a9, a10), (result & 1) == 0) )
  {
    v12 = 1;
    v13 = *(unsigned __int8 *)(v11 + 12272);
    **(_BYTE **)(a2 + 7240) = 0;
    if ( *(_DWORD *)(a2 + 88) == 2 )
      v14 = 2;
    else
      v14 = 1;
    if ( *(_DWORD *)(a2 + 88) == 2 )
      v12 = 2;
    *(_BYTE *)(a2 + 7248) = v14;
    if ( v14 < (unsigned int)v13 )
    {
      do
      {
        v15 = v13 == v12 + 1;
        *(_BYTE *)(*(_QWORD *)(a2 + 7240) + v12) = v12 + 1;
        ++v12;
      }
      while ( !v15 );
      v12 = v13;
      LOBYTE(v14) = v13;
    }
    *(_BYTE *)(*(_QWORD *)(a2 + 7240) + v12) = 0;
    *(_BYTE *)(a2 + 7249) = v14;
  }
  return result;
}
