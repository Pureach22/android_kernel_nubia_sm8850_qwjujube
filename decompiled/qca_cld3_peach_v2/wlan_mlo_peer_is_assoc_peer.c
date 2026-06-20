bool __fastcall wlan_mlo_peer_is_assoc_peer(__int64 a1, __int64 a2)
{
  _BOOL4 v2; // w19

  v2 = 0;
  if ( a1 && a2 )
  {
    qdf_mutex_acquire(a1 + 120);
    v2 = *(_QWORD *)(a1 + 16) == a2;
    qdf_mutex_release(a1 + 120);
  }
  return v2;
}
