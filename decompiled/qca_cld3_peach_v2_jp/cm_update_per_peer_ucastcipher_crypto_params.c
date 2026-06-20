__int64 __fastcall cm_update_per_peer_ucastcipher_crypto_params(__int64 a1, __int64 a2)
{
  int v2; // w8
  unsigned int v4; // w20
  __int64 result; // x0

  v2 = *(_DWORD *)(a2 + 8);
  if ( (v2 & 0x400) != 0 )
  {
    v4 = 1024;
  }
  else if ( (v2 & 0x80) != 0 )
  {
    v4 = 128;
  }
  else if ( (v2 & 0x200) != 0 )
  {
    v4 = 512;
  }
  else if ( (v2 & 8) != 0 )
  {
    v4 = 8;
  }
  else if ( (v2 & 2) != 0 )
  {
    v4 = 2;
  }
  else
  {
    v4 = *(_DWORD *)(a2 + 8);
  }
  result = wlan_crypto_set_vdev_param(a1, 1u, v4);
  *(_DWORD *)(a2 + 8) = v4;
  return result;
}
