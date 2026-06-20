__int64 __fastcall epping_ndev_ioctl(
        __int64 a1,
        __int64 a2,
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
  if ( *(_QWORD *)(a1 + 2704) != a1 )
  {
    qdf_trace_msg(0x33u, 1u, "%s: HDD adapter/dev inconsistency", a4, a5, a6, a7, a8, a9, a10, a11, "epping_ndev_ioctl");
    return 4294967277LL;
  }
  if ( a2 && *(_QWORD *)(a2 + 16) )
  {
    if ( a3 == 35313 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: do not support ioctl %d (SIOCDEVPRIVATE + 1)",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "epping_ndev_ioctl",
        35313);
      return 0;
    }
    qdf_trace_msg(0x33u, 2u, "%s: unknown ioctl %d", a4, a5, a6, a7, a8, a9, a10, a11, "epping_ndev_ioctl", a3);
  }
  return 4294967274LL;
}
