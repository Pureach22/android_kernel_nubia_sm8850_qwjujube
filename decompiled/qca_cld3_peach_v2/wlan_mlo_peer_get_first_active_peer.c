__int64 __fastcall wlan_mlo_peer_get_first_active_peer(__int64 a1)
{
  __int64 *v2; // x8
  __int64 v3; // x20
  __int64 *v4; // x8

  if ( !a1 )
    return 0;
  qdf_mutex_acquire(a1 + 120);
  v2 = (__int64 *)(a1 + 16);
  if ( a1 == -16 || (v3 = *v2) == 0 || *(_DWORD *)(v3 + 68) == 13 )
  {
    v4 = (__int64 *)(a1 + 56);
    if ( a1 == -56 || (v3 = *v4) == 0 || *(_DWORD *)(v3 + 68) == 13 )
      v3 = 0;
  }
  qdf_mutex_release(a1 + 120);
  return v3;
}
