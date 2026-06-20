__int64 __fastcall sme_get_ani_level(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  _QWORD *context; // x0

  context = _cds_get_context(54, (__int64)"sme_get_ani_level", a6, a7, a8, a9, a10, a11, a12, a13);
  if ( !context )
    return 16;
  *(_QWORD *)(a1 + 21976) = a4;
  *(_QWORD *)(a1 + 21984) = a5;
  return wma_send_ani_level_request(context, a2, a3);
}
