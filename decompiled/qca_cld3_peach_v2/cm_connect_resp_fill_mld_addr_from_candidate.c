__int64 __fastcall cm_connect_resp_fill_mld_addr_from_candidate(
        __int64 result,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v13; // w8

  _ReadStatusReg(SP_EL0);
  if ( result )
  {
    if ( a2 )
    {
      result = wlan_vdev_mlme_is_mlo_vdev(result, a4, a5, a6, a7, a8, a9, a10, a11);
      if ( (result & 1) != 0 )
      {
        if ( *(_DWORD *)(a2 + 1912) | *(unsigned __int16 *)(a2 + 1916) )
        {
          v13 = *(_DWORD *)(a2 + 1912);
          *(_WORD *)(a3 + 157) = *(_WORD *)(a2 + 1916);
          *(_DWORD *)(a3 + 153) = v13;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
