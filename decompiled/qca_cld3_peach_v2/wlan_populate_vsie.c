const void **__fastcall wlan_populate_vsie(
        const void **result,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v12; // w8

  if ( (a3 & 1) == 0 )
  {
    result = (const void **)mlme_get_peer_disconnect_ies((__int64)result, a4, a5, a6, a7, a8, a9, a10, a11);
    if ( result )
    {
      v12 = *(_DWORD *)result;
      *(_BYTE *)(a2 + 63) = *(_DWORD *)result;
      return (const void **)qdf_mem_copy((void *)(a2 + 64), result[1], (unsigned __int8)v12);
    }
  }
  return result;
}
