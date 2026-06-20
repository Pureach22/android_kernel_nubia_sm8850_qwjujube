__int64 __fastcall backlight_cdev_unregister(__int64 result)
{
  if ( result )
    return thermal_cooling_device_unregister(*(_QWORD *)(result + 72));
  return result;
}
