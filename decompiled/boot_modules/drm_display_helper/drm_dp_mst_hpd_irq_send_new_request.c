__int64 __fastcall drm_dp_mst_hpd_irq_send_new_request(__int64 a1)
{
  __int64 v2; // x8

  mutex_lock(a1 + 936);
  v2 = *(_QWORD *)(a1 + 984);
  if ( v2 == a1 + 984 || v2 == 320 || (unsigned int)(*(_DWORD *)(v2 + 20) - 1) <= 1 )
    return mutex_unlock(a1 + 936);
  mutex_unlock(a1 + 936);
  return queue_work_on(32, system_long_wq, a1 + 1056);
}
