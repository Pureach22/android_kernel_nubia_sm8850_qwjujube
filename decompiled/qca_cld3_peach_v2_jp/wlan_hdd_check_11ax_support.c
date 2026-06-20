unsigned __int8 *__fastcall wlan_hdd_check_11ax_support(__int64 a1, __int64 a2)
{
  unsigned __int8 *result; // x0

  result = wlan_get_ext_ie_ptr_from_ext_id("#", 1u, *(unsigned __int8 **)(a1 + 8), *(_DWORD *)(a1 + 36));
  if ( result )
    *(_DWORD *)(a2 + 40) = 2048;
  return result;
}
