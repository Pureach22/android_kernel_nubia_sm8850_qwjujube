__int64 sub_604C()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return qcom_smem_is_available();
}
