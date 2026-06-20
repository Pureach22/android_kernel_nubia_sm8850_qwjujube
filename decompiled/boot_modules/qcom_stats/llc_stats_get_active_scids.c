__int64 __fastcall llc_stats_get_active_scids(__int64 a1)
{
  unsigned __int64 v3; // x0
  int v4; // w8
  unsigned int v5; // w19

  if ( !drv || *(_BYTE *)(*(_QWORD *)(drv + 8) + 40LL) != 1 )
    return 4294967277LL;
  mutex_lock(drv + 192);
  if ( llc_stats_get_active_scids_local_scids
    && (unsigned __int64)llc_stats_get_active_scids_local_scids < 0xFFFFFFFFFFFFF001LL )
  {
    _memcpy_fromio(a1, llc_stats_get_active_scids_local_scids, 548);
  }
  else
  {
    v3 = qcom_smem_get(2, 661, 0);
    v4 = -12;
    llc_stats_get_active_scids_local_scids = v3;
    if ( !v3 || v3 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_10;
  }
  v4 = 0;
LABEL_10:
  v5 = v4;
  mutex_unlock(drv + 192);
  return v5;
}
