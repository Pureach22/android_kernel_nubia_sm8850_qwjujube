__int64 __fastcall wma_set_enable_disable_mcc_adaptive_scheduler(
        unsigned int a1,
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

  context = _cds_get_context(
              54,
              (__int64)"wma_set_enable_disable_mcc_adaptive_scheduler",
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9);
  if ( context )
    return wmi_unified_set_enable_disable_mcc_adaptive_scheduler_cmd(*context, a1, 0);
  else
    return 5;
}
