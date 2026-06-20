__int64 __fastcall wlan_mlo_get_cu_bpcc(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11)
{
  if ( a1 && a11 )
    return mlo_get_cu_bpcc();
  qdf_trace_msg(0x8Fu, 8u, "%s: vdev or bpcc is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mlo_get_cu_bpcc");
  return 4;
}
