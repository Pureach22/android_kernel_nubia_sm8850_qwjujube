__int64 __fastcall ipahal_read_ep_reg(unsigned int a1, unsigned int a2)
{
  return ipahal_read_reg_n(a1, a2 >> 5);
}
