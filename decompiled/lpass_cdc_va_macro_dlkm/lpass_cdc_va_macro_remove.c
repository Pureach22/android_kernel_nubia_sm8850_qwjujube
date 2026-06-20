__int64 __fastcall lpass_cdc_va_macro_remove(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19

  v1 = *(_QWORD *)(result + 168);
  if ( v1 )
  {
    v2 = result;
    if ( *(_DWORD *)(v1 + 1524) )
    {
      if ( *(_QWORD *)(v1 + 1360) )
        kfree();
      if ( *(int *)(v1 + 1456) >= 1 )
      {
        platform_device_unregister(*(_QWORD *)(v1 + 1480));
        if ( *(int *)(v1 + 1456) >= 2 )
        {
          platform_device_unregister(*(_QWORD *)(v1 + 1488));
          if ( *(int *)(v1 + 1456) >= 3 )
            platform_device_unregister(*(_QWORD *)(v1 + 1496));
        }
      }
    }
    cancel_delayed_work_sync(v1 + 192);
    _pm_runtime_disable(v2 + 16, 1);
    _pm_runtime_set_status(v2 + 16, 2);
    return lpass_cdc_unregister_macro(v2 + 16, 3);
  }
  return result;
}
