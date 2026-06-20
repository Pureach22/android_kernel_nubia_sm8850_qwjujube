__int64 __fastcall wlan_cm_roaming_get_peer_mld_addr(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
  {
    result = 0;
  }
  else
  {
    result = cm_get_ext_hdl_fl(
               a1,
               (__int64)"wlan_cm_roaming_get_peer_mld_addr",
               0x181Eu,
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9);
    if ( result )
    {
      if ( *(_DWORD *)(result + 949) | *(unsigned __int16 *)(result + 953) )
        result += 949;
      else
        result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
