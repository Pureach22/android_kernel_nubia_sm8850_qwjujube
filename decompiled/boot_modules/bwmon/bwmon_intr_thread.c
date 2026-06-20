__int64 __fastcall bwmon_intr_thread(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 *v4; // x8
  __int64 v5; // x0
  int updated; // w0
  __int64 v7; // x0

  v2 = *(_QWORD *)(a2 + 216);
  mutex_lock(v2 + 448);
  if ( *(_BYTE *)(v2 + 321) == 1 )
  {
    *(_BYTE *)(a2 + 264) = 0;
    cancel_work_sync(a2 + 232);
    mutex_lock(v2 + 496);
    if ( (bwmon_update_cur_freq(v2) & 1) != 0 )
    {
      v4 = *(__int64 **)(a2 + 96);
      v5 = v4[14];
      if ( !v5 )
        v5 = *v4;
      updated = qcom_dcvs_update_votes(
                  v5,
                  v2 + 16,
                  (2 * *(unsigned __int8 *)(a2 + 124)) | 1u,
                  *(unsigned int *)(a2 + 108));
      if ( updated < 0 )
        dev_err(*(_QWORD *)(a2 + 96), "bwmon irq update failed: %d\n", updated);
    }
    v7 = mutex_unlock(v2 + 496);
    *(_QWORD *)(a2 + 224) = ktime_get(v7);
    *(_BYTE *)(a2 + 264) = 1;
  }
  mutex_unlock(v2 + 448);
  return 1;
}
