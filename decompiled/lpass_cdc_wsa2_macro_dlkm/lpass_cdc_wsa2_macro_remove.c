__int64 __fastcall lpass_cdc_wsa2_macro_remove(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19

  v1 = *(_QWORD *)(result + 168);
  if ( v1 )
  {
    v2 = result;
    if ( *(_QWORD *)(v1 + 552) )
      thermal_cooling_device_unregister();
    if ( *(int *)(v1 + 464) >= 1 )
    {
      platform_device_unregister(*(_QWORD *)(v1 + 440));
      if ( *(int *)(v1 + 464) >= 2 )
      {
        platform_device_unregister(*(_QWORD *)(v1 + 448));
        if ( *(int *)(v1 + 464) >= 3 )
          platform_device_unregister(*(_QWORD *)(v1 + 456));
      }
    }
    _pm_runtime_disable(v2 + 16, 1);
    _pm_runtime_set_status(v2 + 16, 2);
    return lpass_cdc_unregister_macro(v2 + 16, 4);
  }
  return result;
}
