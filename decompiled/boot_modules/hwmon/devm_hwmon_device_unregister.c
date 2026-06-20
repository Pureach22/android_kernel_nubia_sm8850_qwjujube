__int64 __fastcall devm_hwmon_device_unregister(__int64 a1)
{
  __int64 result; // x0

  result = devres_release(a1, devm_hwmon_release, devm_hwmon_match, a1);
  if ( (_DWORD)result )
    __break(0x800u);
  return result;
}
