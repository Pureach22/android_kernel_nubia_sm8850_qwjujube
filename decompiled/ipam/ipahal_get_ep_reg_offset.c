__int64 __fastcall ipahal_get_ep_reg_offset(__int64 a1, unsigned int a2)
{
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(a1, 0, a2 >> 5);
}
