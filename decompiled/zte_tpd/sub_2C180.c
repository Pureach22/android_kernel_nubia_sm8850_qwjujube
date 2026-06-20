__int64 sub_2C180()
{
  __asm { STZG            X9, [X14],#0x6A0 }
  return syna_tcm_read_mtp_data();
}
