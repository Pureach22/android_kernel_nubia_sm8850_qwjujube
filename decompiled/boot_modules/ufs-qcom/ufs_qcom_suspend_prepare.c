__int64 __fastcall ufs_qcom_suspend_prepare(__int64 a1)
{
  if ( (is_bootdevice_ufs & 1) != 0 )
    return ufshcd_suspend_prepare();
  dev_info(a1, "UFS is not boot dev.\n");
  return 0;
}
