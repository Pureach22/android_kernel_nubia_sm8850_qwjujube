void __fastcall lim_send_epcs_update_edca_params(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0

  context = _cds_get_context(53, (__int64)"lim_send_epcs_update_edca_params", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( context )
    lim_send_edca_params(context, a2, *(unsigned __int8 *)(a1 + 168), a3 & 1);
}
