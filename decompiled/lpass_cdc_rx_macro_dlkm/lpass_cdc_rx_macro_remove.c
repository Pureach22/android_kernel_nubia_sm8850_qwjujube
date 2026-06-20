__int64 __fastcall lpass_cdc_rx_macro_remove(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19

  v1 = *(_QWORD *)(result + 168);
  if ( v1 )
  {
    v2 = result;
    if ( *(int *)(v1 + 2320) >= 1 )
    {
      platform_device_unregister(*(_QWORD *)(v1 + 2296));
      if ( *(int *)(v1 + 2320) >= 2 )
      {
        platform_device_unregister(*(_QWORD *)(v1 + 2304));
        if ( *(int *)(v1 + 2320) >= 3 )
          platform_device_unregister(*(_QWORD *)(v1 + 2312));
      }
    }
    _pm_runtime_disable(v2 + 16, 1);
    _pm_runtime_set_status(v2 + 16, 2);
    lpass_cdc_unregister_macro(v2 + 16, 1);
    return kfree(*(_QWORD *)(v1 + 200));
  }
  return result;
}
