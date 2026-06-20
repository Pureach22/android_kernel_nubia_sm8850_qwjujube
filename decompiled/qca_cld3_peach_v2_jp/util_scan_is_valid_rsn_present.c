__int64 __fastcall util_scan_is_valid_rsn_present(_QWORD *a1, _DWORD *a2)
{
  unsigned __int8 *v2; // x8
  __int64 result; // x0
  unsigned __int8 *v6; // x1
  unsigned __int8 *v7; // x1

  v2 = (unsigned __int8 *)a1[161];
  if ( !v2 || (result = wlan_crypto_rsnie_check(a2, v2, nullptr), (_DWORD)result) )
  {
    v6 = (unsigned __int8 *)a1[210];
    if ( !v6 || (result = wlan_crypto_rsnie_check(a2, v6, nullptr), (_DWORD)result) )
    {
      v7 = (unsigned __int8 *)a1[212];
      if ( !v7 )
        return 4;
      result = wlan_crypto_rsnie_check(a2, v7, nullptr);
      if ( (_DWORD)result )
        return 4;
    }
  }
  return result;
}
