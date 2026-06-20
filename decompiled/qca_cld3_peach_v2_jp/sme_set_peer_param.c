__int64 __fastcall sme_set_peer_param(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *context; // x0

  context = _cds_get_context(54, (__int64)"sme_set_peer_param", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( context )
    return wma_set_peer_param(context, a1, a2, a3, a4);
  else
    return 16;
}
