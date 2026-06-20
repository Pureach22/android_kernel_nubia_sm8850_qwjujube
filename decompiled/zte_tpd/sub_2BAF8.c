__int64 sub_2BAF8()
{
  __asm { STZG            X9, [X14],#0x6A0 }
  return syna_tcm_read_cs_data();
}
