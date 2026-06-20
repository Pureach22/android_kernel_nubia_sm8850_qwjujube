__int64 __fastcall mlo_peer_cleanup(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *v11; // x2

  if ( a1 )
  {
    if ( *(_QWORD *)(a1 + 192) )
    {
      mlo_dev_mlpeer_detach(*(_QWORD *)(a1 + 192), a1);
      return mlo_peer_free(a1);
    }
    v11 = "%s: ML DEV is NULL";
  }
  else
  {
    v11 = "%s: ML PEER is NULL";
  }
  return qdf_trace_msg(0x8Fu, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "mlo_peer_cleanup");
}
