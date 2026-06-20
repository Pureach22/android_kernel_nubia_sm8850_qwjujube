__int64 __fastcall wlan_crypto_register_crypto_rx_ops(_QWORD *a1)
{
  *a1 = wlan_crypto_encap;
  a1[1] = wlan_crypto_decap;
  a1[2] = &wlan_crypto_enmic;
  a1[3] = wlan_crypto_demic;
  a1[4] = wlan_crypto_set_peer_wep_keys;
  return 0;
}
