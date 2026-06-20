__int64 (__fastcall **__fastcall target_if_nan_register_rx_ops(
        __int64 (__fastcall **result)(unsigned __int16 *a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9)))(unsigned __int16 *a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9)
{
  *result = nan_discovery_event_handler;
  result[1] = (__int64 (__fastcall *)(unsigned __int16 *, double, double, double, double, double, double, double, double))nan_datapath_event_handler;
  return result;
}
