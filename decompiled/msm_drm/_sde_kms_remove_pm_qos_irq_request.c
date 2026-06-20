__int64 __fastcall sde_kms_remove_pm_qos_irq_request(__int64 result, _DWORD *a2)
{
  char v3; // w8
  __int64 v4; // x23
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x22

  if ( *a2 )
  {
    v3 = 0;
    v4 = result + 3768;
    do
    {
      v5 = (unsigned int)(-1LL << v3) & *a2;
      if ( !(_DWORD)v5 )
        break;
      v6 = __clz(__rbit64(v5));
      result = get_cpu_device((unsigned int)v6);
      if ( result )
      {
        result = v4 + 80LL * (unsigned int)v6;
        if ( *(_QWORD *)(result + 72) )
          result = dev_pm_qos_remove_request(result);
      }
      else if ( (_drm_debug & 4) != 0 )
      {
        result = _drm_dev_dbg(0, 0, 0, "%s: failed to get cpu%d device\n", "_sde_kms_remove_pm_qos_irq_request", v6);
      }
      v3 = v6 + 1;
    }
    while ( v6 < 0x1F );
  }
  else if ( (_drm_debug & 4) != 0 )
  {
    return _drm_dev_dbg(0, 0, 0, "%s: irq_cpu_mask is empty\n", "_sde_kms_remove_pm_qos_irq_request");
  }
  return result;
}
