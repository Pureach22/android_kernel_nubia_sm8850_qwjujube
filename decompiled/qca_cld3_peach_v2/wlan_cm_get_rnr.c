__int64 __fastcall wlan_cm_get_rnr(
        __int64 a1,
        int a2,
        void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) == 0 )
    return cm_get_rnr(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev %d Invalid mode %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_cm_get_rnr",
    *(unsigned __int8 *)(a1 + 168));
  return 11;
}
