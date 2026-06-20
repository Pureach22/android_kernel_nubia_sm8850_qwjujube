__int64 __fastcall wlan_cm_disconnect_rsp(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 cm_ctx_fl; // x0

  cm_ctx_fl = cm_get_cm_ctx_fl(a1, (__int64)"wlan_cm_disconnect_rsp", 0x7Du, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !cm_ctx_fl )
    return 4;
  if ( (~*(_DWORD *)(cm_ctx_fl + 88) & 0xF000000) != 0 )
    return cm_disconnect_rsp(a1, a2);
  return 0;
}
