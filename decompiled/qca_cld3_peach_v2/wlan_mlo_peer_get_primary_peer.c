__int64 __fastcall wlan_mlo_peer_get_primary_peer(__int64 a1)
{
  __int64 *v2; // x8
  __int64 v3; // x20

  if ( !a1 )
    return 0;
  qdf_mutex_acquire(a1 + 120);
  v2 = (__int64 *)(a1 + 16);
  if ( (a1 == -16 || *(_BYTE *)(a1 + 31) != 1)
    && ((v2 = (__int64 *)(a1 + 56), a1 == -56) || (*(_BYTE *)(a1 + 71) & 1) == 0) )
  {
    v3 = 0;
  }
  else
  {
    v3 = *v2;
  }
  qdf_mutex_release(a1 + 120);
  return v3;
}
