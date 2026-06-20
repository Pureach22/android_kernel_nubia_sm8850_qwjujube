__int64 __fastcall lim_assign_peer_idx(__int64 a1, __int64 a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x0
  __int64 result; // x0
  int v13; // w9

  if ( *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 3407LL) <= (unsigned int)(unsigned __int8)pe_get_current_stas_count(a1) )
    return 0;
  v11 = *(_QWORD *)(a2 + 16);
  if ( *(_DWORD *)(v11 + 16) == 1 && (wlan_vdev_mlme_is_mlo_vdev(v11, v3, v4, v5, v6, v7, v8, v9, v10) & 1) != 0 )
  {
    result = mlme_get_aid(*(_QWORD *)(a2 + 16));
    if ( !(_WORD)result )
      return 0;
  }
  else
  {
    result = *(unsigned __int8 *)(a2 + 7248);
    if ( *(_BYTE *)(a2 + 7248)
      && (v13 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 7240) + result), *(_BYTE *)(a2 + 7248) = v13, !v13) )
    {
      *(_BYTE *)(a2 + 7249) = 0;
      if ( !(_WORD)result )
        return 0;
    }
    else if ( !(_WORD)result )
    {
      return 0;
    }
  }
  ++*(_WORD *)(a2 + 7250);
  return result;
}
