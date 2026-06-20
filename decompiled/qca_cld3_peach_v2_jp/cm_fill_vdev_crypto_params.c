__int64 __fastcall cm_fill_vdev_crypto_params(__int64 *a1, __int64 a2)
{
  wlan_crypto_set_vdev_param(*a1, 0, *(_DWORD *)(a2 + 76));
  wlan_crypto_set_vdev_param(*a1, 7u, *(_DWORD *)(a2 + 88));
  wlan_crypto_set_vdev_param(*a1, 1u, *(_DWORD *)(a2 + 84));
  wlan_crypto_set_vdev_param(*a1, 2u, *(_DWORD *)(a2 + 80));
  wlan_crypto_set_vdev_param(*a1, 3u, *(_DWORD *)(a2 + 124));
  return wlan_crypto_set_vdev_param(*a1, 5u, *(unsigned __int16 *)(a2 + 120));
}
