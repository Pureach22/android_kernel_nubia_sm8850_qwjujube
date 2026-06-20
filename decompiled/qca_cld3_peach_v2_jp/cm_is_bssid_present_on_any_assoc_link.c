bool __fastcall cm_is_bssid_present_on_any_assoc_link(
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
  int bss_peer_mac; // w8
  _BOOL8 result; // x0
  int v14; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v15; // [xsp+4h] [xbp-Ch]
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v14 = 0;
  bss_peer_mac = wlan_vdev_get_bss_peer_mac(a1, &v14, a3, a4, a5, a6, a7, a8, a9, a10);
  result = 0;
  if ( !bss_peer_mac )
    result = *(_DWORD *)a2 == v14 && *(unsigned __int16 *)(a2 + 4) == v15;
  _ReadStatusReg(SP_EL0);
  return result;
}
