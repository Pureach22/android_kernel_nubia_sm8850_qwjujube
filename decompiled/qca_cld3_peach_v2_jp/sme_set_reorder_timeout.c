__int64 __fastcall sme_set_reorder_timeout(
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

  context = _cds_get_context(54, (__int64)"sme_set_reorder_timeout", a1, a2, a3, a4, a5, a6, a7, a8);
  return wma_set_rx_reorder_timeout_val(context, a10);
}
