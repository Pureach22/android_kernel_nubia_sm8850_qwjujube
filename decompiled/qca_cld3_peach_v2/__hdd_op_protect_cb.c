__int64 __fastcall _hdd_op_protect_cb(
        __int64 a1,
        __int64 a2,
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

  context = _cds_get_context(51, (__int64)"__hdd_op_protect_cb", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
    return _osif_psoc_sync_op_start(context[12], a1, a2);
  else
    return 4294967285LL;
}
