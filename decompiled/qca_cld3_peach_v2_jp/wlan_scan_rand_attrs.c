__int64 __fastcall wlan_scan_rand_attrs(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0

  result = wlan_fill_scan_rand_attrs(a1, *(unsigned int *)(a2 + 36), a2 + 72, a2 + 78, a3 + 1900, a3 + 1901, a3 + 1907);
  if ( *(_BYTE *)(a3 + 1900) == 1 )
    *(_DWORD *)(a3 + 92) |= 0xC0000u;
  return result;
}
