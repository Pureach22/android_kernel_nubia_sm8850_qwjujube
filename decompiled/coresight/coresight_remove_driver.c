__int64 __fastcall coresight_remove_driver(__int64 a1, __int64 a2)
{
  amba_driver_unregister(a1);
  return platform_driver_unregister(a2);
}
