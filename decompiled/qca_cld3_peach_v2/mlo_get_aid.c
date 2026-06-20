__int64 __fastcall mlo_get_aid(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x0

  v1 = *(_QWORD *)(a1 + 1360);
  if ( !v1 )
    return 0xFFFF;
  v2 = *(_QWORD *)(v1 + 2232);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 8);
    if ( v3 )
      return wlan_mlo_peer_alloc_aid(v3, 1, 0, 0xFFu);
    return 0xFFFF;
  }
  return 4;
}
