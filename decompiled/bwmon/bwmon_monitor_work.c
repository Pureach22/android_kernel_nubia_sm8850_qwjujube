__int64 __fastcall bwmon_monitor_work(__int64 a1)
{
  __int64 v1; // x19
  __int64 *v3; // x8
  __int64 v4; // x0
  int updated; // w0

  v1 = *(_QWORD *)(a1 - 16);
  mutex_lock(v1 + 496);
  if ( (bwmon_update_cur_freq(v1) & 1) != 0 )
  {
    v3 = *(__int64 **)(a1 - 136);
    v4 = v3[14];
    if ( !v4 )
      v4 = *v3;
    updated = qcom_dcvs_update_votes(
                v4,
                v1 + 16,
                (2 * *(unsigned __int8 *)(a1 - 108)) | 1u,
                *(unsigned int *)(a1 - 124));
    if ( updated < 0 )
      dev_err(*(_QWORD *)(a1 - 136), "bwmon monitor update failed: %d\n", updated);
  }
  return mutex_unlock(v1 + 496);
}
