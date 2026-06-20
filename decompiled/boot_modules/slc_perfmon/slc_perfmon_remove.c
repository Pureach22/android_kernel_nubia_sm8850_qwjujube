__int64 __fastcall slc_perfmon_remove(__int64 a1)
{
  __int64 v1; // x20

  v1 = *(_QWORD *)(a1 + 168);
  mutex_lock(v1 + 136);
  if ( ((*(_BYTE *)(v1 + 128) & 1) != 0 || *(_BYTE *)(v1 + 133)) && (unsigned int)perf_remove(a1 + 16, v1) )
  {
    dev_err(a1 + 16, "Can't remove config, module can't be removed.\n");
    return mutex_unlock(v1 + 136);
  }
  else
  {
    mutex_unlock(v1 + 136);
    sysfs_remove_group(a1 + 16, &slc_perfmon_group);
    *(_QWORD *)(a1 + 168) = 0;
    return dev_info(a1 + 16, "Module removed successfully.\n");
  }
}
