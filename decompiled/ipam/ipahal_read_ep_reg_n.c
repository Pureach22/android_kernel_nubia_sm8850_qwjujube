__int64 __fastcall ipahal_read_ep_reg_n(__int64 a1, unsigned int a2, unsigned int a3)
{
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_read_reg_mn)(a1, a3 >> 5, a2);
}
