__int64 __fastcall ufs_qcom_system_suspend(__int64 a1)
{
  if ( !of_find_property(*(_QWORD *)(a1 + 744), "non-removable", 0) || (is_bootdevice_ufs & 1) != 0 )
    return ufshcd_system_suspend(a1);
  dev_info(a1, "UFS is not boot dev.\n");
  return 0;
}
