__int64 __fastcall wlan_cm_bss_peer_create_rsp(
        __int64 a1,
        int a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 cm_ctx_fl; // x0

  cm_ctx_fl = cm_get_cm_ctx_fl(a1, (__int64)"wlan_cm_bss_peer_create_rsp", 0x50u, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !cm_ctx_fl )
    return 4;
  if ( (~*(_DWORD *)(cm_ctx_fl + 88) & 0xF000000) != 0 )
    return cm_bss_peer_create_rsp(a1, a2, a3);
  return 0;
}
