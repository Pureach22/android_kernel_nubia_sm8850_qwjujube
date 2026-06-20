__int64 __fastcall lpass_cdc_wsa_macro_remove(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19

  v1 = *(_QWORD *)(result + 168);
  if ( v1 )
  {
    v2 = result;
    cancel_delayed_work_sync(v1 + 48);
    if ( *(_QWORD *)(v1 + 680) )
      thermal_cooling_device_unregister();
    if ( *(int *)(v1 + 592) >= 1 )
    {
      platform_device_unregister(*(_QWORD *)(v1 + 568));
      if ( *(int *)(v1 + 592) >= 2 )
      {
        platform_device_unregister(*(_QWORD *)(v1 + 576));
        if ( *(int *)(v1 + 592) >= 3 )
          platform_device_unregister(*(_QWORD *)(v1 + 584));
      }
    }
    _pm_runtime_disable(v2 + 16, 1);
    _pm_runtime_set_status(v2 + 16, 2);
    return lpass_cdc_unregister_macro(v2 + 16, 2);
  }
  return result;
}
