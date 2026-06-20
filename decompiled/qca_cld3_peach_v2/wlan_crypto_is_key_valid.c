bool __fastcall wlan_crypto_is_key_valid(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x0

  if ( !(a1 | a2) )
    return 0;
  if ( a2 )
  {
    v3 = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_crypto_peer_getkey)(a2, a3);
    if ( !v3 )
      return 0;
  }
  else
  {
    if ( !a1 )
      return 0;
    v3 = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_crypto_vdev_getkey)(a1, a3);
    if ( !v3 )
      return 0;
  }
  return (*(_BYTE *)(v3 + 1) & 1) != 0;
}
