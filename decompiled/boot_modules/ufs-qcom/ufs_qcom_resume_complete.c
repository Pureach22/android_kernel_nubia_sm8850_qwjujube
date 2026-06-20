__int64 __fastcall ufs_qcom_resume_complete(__int64 a1)
{
  if ( (is_bootdevice_ufs & 1) != 0 )
    return ufshcd_resume_complete();
  else
    return dev_info(a1, "UFS is not boot dev.\n");
}
