__int64 __fastcall sme_set_peer_authorized(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0

  context = _cds_get_context(54, (__int64)"sme_set_peer_authorized", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
    return wma_set_peer_param(context, a1, 3, 1, a2);
  else
    return 16;
}
