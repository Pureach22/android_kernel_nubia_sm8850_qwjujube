__int64 qcom_stats_ddr_freqsync_msg()
{
  unsigned int v0; // w0
  __int64 v1; // x8
  unsigned int v3; // w19

  if ( !drv || !*(_QWORD *)(drv + 240) || *(_BYTE *)(*(_QWORD *)(drv + 8) + 35LL) != 1 )
    return 4294967277LL;
  mutex_lock(drv + 192);
  v0 = qmp_send(*(_QWORD *)(drv + 240), "{class: ddr, action: freqsync}", 64);
  if ( v0 )
  {
    v3 = v0;
    printk(&unk_A305, v0);
    mutex_unlock(drv + 192);
    return v3;
  }
  else
  {
    mutex_unlock(drv + 192);
    v1 = ktime_get_with_offset(1);
    *(_QWORD *)(drv + 248) = v1;
    return 0;
  }
}
