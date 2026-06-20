__int64 __fastcall wlan_mlo_peer_is_disconnect_progress(__int64 a1)
{
  unsigned int v2; // w19

  if ( a1 )
  {
    qdf_mutex_acquire(a1 + 120);
    v2 = 16 * (*(_DWORD *)(a1 + 200) != 2);
    qdf_mutex_release(a1 + 120);
  }
  else
  {
    return 16;
  }
  return v2;
}
