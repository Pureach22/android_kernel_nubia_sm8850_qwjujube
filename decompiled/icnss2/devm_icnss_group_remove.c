__int64 __fastcall devm_icnss_group_remove(__int64 a1, const void **a2)
{
  const void *v2; // x19

  v2 = *a2;
  ipc_log_string(icnss_ipc_log_context, "icnss2: %s: removing group %p\n", "devm_icnss_group_remove", *a2);
  return sysfs_remove_group(a1, v2);
}
