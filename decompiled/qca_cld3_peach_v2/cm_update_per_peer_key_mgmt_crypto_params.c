__int64 __fastcall cm_update_per_peer_key_mgmt_crypto_params(__int64 a1, __int64 a2)
{
  int secure_akm_available; // w0
  unsigned int v5; // w21
  __int64 result; // x0

  secure_akm_available = wlan_crypto_get_secure_akm_available(*(_DWORD *)(a2 + 4));
  if ( secure_akm_available == 30 )
    v5 = *(_DWORD *)(a2 + 4);
  else
    v5 = 1 << secure_akm_available;
  result = wlan_crypto_set_vdev_param(a1, 7u, v5);
  *(_DWORD *)(a2 + 4) = v5;
  return result;
}
