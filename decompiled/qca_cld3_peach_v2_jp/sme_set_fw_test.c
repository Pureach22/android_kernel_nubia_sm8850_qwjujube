__int64 __fastcall sme_set_fw_test(
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
  _QWORD *context; // x0

  context = _cds_get_context(54, (__int64)"sme_set_fw_test", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
    return wma_process_fw_test_cmd(context, a1);
  else
    return 16;
}
