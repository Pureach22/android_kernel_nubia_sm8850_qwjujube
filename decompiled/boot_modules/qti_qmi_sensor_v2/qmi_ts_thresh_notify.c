__int64 __fastcall qmi_ts_thresh_notify(__int64 a1)
{
  return thermal_zone_device_update(*(_QWORD *)(a1 - 40), 2);
}
