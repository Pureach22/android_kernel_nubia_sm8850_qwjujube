__int64 __fastcall qcom_slim_ngd_ctrl_remove(__int64 a1)
{
  __int64 v2; // x20
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 168);
  platform_driver_unregister(qcom_slim_ngd_driver);
  if ( *(_BYTE *)(v2 + 5480) == 1 )
    sysfs_remove_file_ns(a1 + 16, &dev_attr_debug_mask, 0);
  result = ipc_log_context_destroy(*(_QWORD *)(v2 + 5488));
  *(_QWORD *)(v2 + 5488) = 0;
  return result;
}
