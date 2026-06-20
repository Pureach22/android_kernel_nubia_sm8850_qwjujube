__int64 __fastcall gsihal_get_ch_reg_n_offset(__int64 a1, unsigned int a2, unsigned int a3)
{
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))gsihal_get_reg_nk_ofst)(a1, a3 >> 5, a2);
}
