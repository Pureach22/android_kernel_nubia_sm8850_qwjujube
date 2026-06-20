__int64 *__fastcall wma_critical_events_in_flight(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 *result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 *v17; // x19

  result = _cds_get_context(54, (__int64)"wma_critical_events_in_flight", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( result )
  {
    v17 = result;
    if ( (unsigned int)_wmi_validate_handle(
                         *result,
                         (__int64)"wma_critical_events_in_flight",
                         v9,
                         v10,
                         v11,
                         v12,
                         v13,
                         v14,
                         v15,
                         v16) )
      return nullptr;
    else
      return (__int64 *)wmi_critical_events_in_flight(*v17);
  }
  return result;
}
