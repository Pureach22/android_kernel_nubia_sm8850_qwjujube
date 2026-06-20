__int64 __fastcall sde_kms_irq_affinity_notify(__int64 result, __int64 *a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 v5; // x22

  v2 = result - 6328;
  if ( result != 6328 )
  {
    v3 = *(_QWORD *)(result - 6192);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v3 + 56);
      if ( v4 )
      {
        v5 = result;
        mutex_lock(v4 + 64);
        sde_kms_remove_pm_qos_irq_request(v2, (_DWORD *)(v5 - 2576));
        if ( *(_DWORD *)(v5 - 2568) )
          sde_kms_update_pm_qos_irq_request(v2, a2);
        return mutex_unlock(v4 + 64);
      }
    }
  }
  return result;
}
