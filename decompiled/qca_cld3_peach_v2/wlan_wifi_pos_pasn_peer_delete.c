__int64 __fastcall wlan_wifi_pos_pasn_peer_delete(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int8 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  return wma_pasn_peer_remove(a5, a6, a7, a8, a9, a10, a11, a12, a1, a2, a3, a4);
}
