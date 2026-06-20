__int64 sub_D490()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return qcom_scm_ocmem_lock_available();
}
