__int64 __fastcall qcom_dynamic_hw_thermal_trip_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 168);
  if ( *(_QWORD *)(v1 + 56) )
    thermal_zone_device_unregister();
  result = *(_QWORD *)(v1 + 72);
  if ( result )
    return ipc_log_context_destroy();
  return result;
}
