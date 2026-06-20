__int64 __fastcall _wlan_hdd_validate_mac_address(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  const char *v12; // x2

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    v12 = "%s: Received NULL mac address (via %s)";
LABEL_13:
    qdf_trace_msg(0x33u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "__wlan_hdd_validate_mac_address", a2);
    result = 4;
    goto LABEL_14;
  }
  if ( !(*(_DWORD *)a1 | *(unsigned __int16 *)(a1 + 4)) )
  {
    v12 = "%s: MAC is all zero (via %s)";
    goto LABEL_13;
  }
  if ( *(_DWORD *)a1 == -1 && *(__int16 *)(a1 + 4) == -1 )
  {
    v12 = "%s: MAC is Broadcast (via %s)";
    goto LABEL_13;
  }
  if ( (*(_BYTE *)a1 & 1) != 0 )
  {
    v12 = "%s: MAC is Multicast (via %s)";
    goto LABEL_13;
  }
  result = 0;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
