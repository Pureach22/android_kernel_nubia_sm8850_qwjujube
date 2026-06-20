__int64 __fastcall ufs_qcom_write_msi_msg(__int64 a1)
{
  return ufshcd_mcq_config_esi(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 152LL));
}
