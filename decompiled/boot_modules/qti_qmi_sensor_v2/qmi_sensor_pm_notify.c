__int64 __fastcall qmi_sensor_pm_notify(__int64 a1, __int64 a2)
{
  if ( (unsigned __int64)(a2 - 1) <= 5 )
    in_suspend = dword_8870[a2 - 1];
  return 0;
}
