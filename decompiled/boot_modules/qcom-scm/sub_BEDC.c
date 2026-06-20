__int64 sub_BEDC()
{
  __asm { PRFM            #0x19, 0xFFFFFFFFFFFEC350 }
  return qcom_scm_mem_protect_sd_ctrl();
}
