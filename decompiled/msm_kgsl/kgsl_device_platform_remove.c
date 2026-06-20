__int64 __fastcall kgsl_device_platform_remove(__int64 a1)
{
  timer_delete((timer_t)(a1 + 14040));
  kthread_destroy_worker(*(_QWORD *)(a1 + 12976));
  kgsl_device_snapshot_close(a1);
  idr_destroy(a1 + 11184);
  idr_destroy(a1 + 13376);
  kgsl_device_events_remove(a1);
  kgsl_free_globals(a1);
  kgsl_pwrctrl_close(a1);
  kgsl_device_debugfs_close(a1);
  if ( (*(_BYTE *)(a1 + 13052) & 1) != 0 )
    kobject_put(a1 + 12992);
  mutex_lock(&unk_3A878);
  if ( off_3A7F8 == (_UNKNOWN *)a1 )
  {
    device_destroy(qword_3A450, dword_3A448 & 0xFFF00000);
    off_3A7F8 = nullptr;
  }
  return mutex_unlock(&unk_3A878);
}
