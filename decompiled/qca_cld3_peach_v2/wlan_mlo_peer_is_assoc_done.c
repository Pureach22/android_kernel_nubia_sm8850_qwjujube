__int64 __fastcall wlan_mlo_peer_is_assoc_done(__int64 a1)
{
  unsigned int v2; // w19

  if ( a1 )
  {
    qdf_mutex_acquire(a1 + 120);
    v2 = 16 * (*(_DWORD *)(a1 + 200) != 1);
    qdf_mutex_release(a1 + 120);
  }
  else
  {
    return 16;
  }
  return v2;
}
