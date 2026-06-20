__int64 __fastcall sme_set_idle_powersave_config(
        char a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0

  context = _cds_get_context(54, (__int64)"sme_set_idle_powersave_config", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
    return 16 * (unsigned int)((unsigned int)wma_set_idle_ps_config(context, a1 & 1) != 0);
  else
    return 16;
}
