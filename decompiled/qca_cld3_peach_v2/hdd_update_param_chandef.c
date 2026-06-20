_DWORD *__fastcall hdd_update_param_chandef(__int64 *a1, _DWORD *a2)
{
  _DWORD *result; // x0

  result = (_DWORD *)wlan_vdev_get_active_channel(a1[4]);
  if ( result )
    return (_DWORD *)hdd_create_chandef(*a1, result, a2);
  return result;
}
