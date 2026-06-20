__int64 __fastcall wlan_find_mlpeer_mld_mac_addr(
        __int64 a1,
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
  int v15; // [xsp+0h] [xbp-10h]

  v15 = *(unsigned __int8 *)(a2 + 109);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: MLD ID %d ML Peer mac %02x:%02x:%02x:**:**:%02x",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_find_mlpeer_mld_mac_addr",
    *(unsigned __int8 *)(a1 + 16),
    *(unsigned __int8 *)(a2 + 104),
    *(unsigned __int8 *)(a2 + 105),
    *(unsigned __int8 *)(a2 + 106),
    v15);
  if ( *(_DWORD *)(a3 + 8) != *(_DWORD *)(a2 + 104) || *(unsigned __int16 *)(a3 + 12) != *(unsigned __int16 *)(a2 + 108) )
    return 17;
  *(_QWORD *)a3 = a2;
  return 0;
}
