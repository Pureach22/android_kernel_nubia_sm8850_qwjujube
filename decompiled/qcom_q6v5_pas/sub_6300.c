__int64 sub_6300()
{
  __asm { PRFUM           #2, [X13,#0x6F] }
  return qcom_rproc_update_recovery_status();
}
