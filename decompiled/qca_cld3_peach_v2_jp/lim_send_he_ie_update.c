bool __fastcall lim_send_he_ie_update(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  _QWORD *context; // x0

  context = _cds_get_context(54, (__int64)"lim_send_he_ie_update", a1, a2, a3, a4, a5, a6, a7, a8);
  return (unsigned int)wma_update_he_ops_ie(context, *(unsigned __int8 *)(a10 + 10), a10 + 8740) == 0;
}
