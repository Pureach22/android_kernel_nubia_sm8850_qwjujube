__int64 __fastcall ufs_qcom_fixup_dev_quirks(__int64 a1)
{
  return ufshcd_fixup_dev_quirks(a1, &ufs_qcom_dev_fixups);
}
