__int64 __fastcall ufs_qcom_system_thaw(__int64 a1)
{
  if ( (is_bootdevice_ufs & 1) != 0 )
    return ufshcd_system_thaw();
  dev_info(a1, "UFS is not boot dev.\n");
  return 0;
}
