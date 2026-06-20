__int64 __fastcall wlan_wifi_pos_pasn_peer_create(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  return wma_pasn_peer_create(a1, a2, a3, 0xAu, a4, a5, a6, a7, a8, a9, a10, a11);
}
