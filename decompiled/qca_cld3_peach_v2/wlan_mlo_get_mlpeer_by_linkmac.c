__int64 __fastcall wlan_mlo_get_mlpeer_by_linkmac(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x7
  int v16; // w8
  __int16 v17; // w9
  int v18; // w0
  __int64 v20; // [xsp+8h] [xbp-18h] BYREF
  __int64 v21; // [xsp+10h] [xbp-10h]
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned __int8 *)(a1 + 16);
  if ( a2 )
  {
    v13 = *a2;
    v14 = a2[1];
    v15 = a2[2];
    v16 = a2[5];
  }
  else
  {
    v15 = 0;
    v13 = 0;
    v14 = 0;
    v16 = 0;
  }
  v20 = 0;
  v21 = 0;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: MLD ID %d ML Peer search with link mac %02x:%02x:%02x:**:**:%02x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_mlo_get_mlpeer_by_linkmac",
    v12,
    v13,
    v14,
    v15,
    v16);
  v17 = *((_WORD *)a2 + 2);
  LODWORD(v21) = *(_DWORD *)a2;
  WORD2(v21) = v17;
  v18 = wlan_mlo_iterate_ml_peerlist(a1, wlan_find_mlpeer_link_mac_addr, (__int64)&v20);
  _ReadStatusReg(SP_EL0);
  if ( v18 )
    return 0;
  else
    return v20;
}
