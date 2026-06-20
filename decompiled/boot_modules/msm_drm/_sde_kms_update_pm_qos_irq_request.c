__int64 __fastcall sde_kms_update_pm_qos_irq_request(__int64 result, __int64 *a2)
{
  __int64 v2; // x10
  unsigned int v3; // w20
  __int64 v4; // x19
  char v5; // w8
  __int64 v6; // x24
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x23

  v2 = *a2;
  v3 = *(_DWORD *)(*(_QWORD *)(result + 152) + 21868LL);
  *(_QWORD *)(result + 3752) = *a2;
  if ( (_DWORD)v2 )
  {
    v4 = result;
    v5 = 0;
    v6 = result + 3768;
    do
    {
      v7 = (unsigned int)(-1LL << v5) & *(_DWORD *)(v4 + 3752);
      if ( !(_DWORD)v7 )
        break;
      v8 = __clz(__rbit64(v7));
      result = get_cpu_device((unsigned int)v8);
      if ( result )
      {
        result = *(_QWORD *)(v6 + 80LL * (unsigned int)v8 + 72)
               ? dev_pm_qos_update_request(v6 + 80LL * (unsigned int)v8, v3)
               : dev_pm_qos_add_request();
      }
      else if ( (_drm_debug & 4) != 0 )
      {
        result = _drm_dev_dbg(0, 0, 0, "%s: failed to get cpu%d device\n", "_sde_kms_update_pm_qos_irq_request", v8);
      }
      v5 = v8 + 1;
    }
    while ( v8 < 0x1F );
  }
  else if ( (_drm_debug & 4) != 0 )
  {
    return _drm_dev_dbg(0, 0, 0, "%s: irq_cpu_mask is empty\n", "_sde_kms_update_pm_qos_irq_request");
  }
  return result;
}
