__int64 __fastcall sme_set_apf_enable_disable(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10,
        char a11)
{
  _QWORD *context; // x0

  context = _cds_get_context(54, (__int64)"sme_set_apf_enable_disable", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
    return wma_send_apf_enable_cmd(context, a10, a11 & 1);
  else
    return 16;
}
