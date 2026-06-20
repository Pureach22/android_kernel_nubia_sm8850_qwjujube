__int64 __fastcall wlan_mlo_peer_get_assoc_peer(__int64 a1)
{
  __int64 v2; // x19

  if ( !a1 )
    return 0;
  qdf_mutex_acquire(a1 + 120);
  v2 = *(_QWORD *)(a1 + 16);
  qdf_mutex_release(a1 + 120);
  return v2;
}
