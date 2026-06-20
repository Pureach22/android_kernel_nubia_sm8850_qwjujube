__int64 __fastcall gsihal_get_ch_reg_offset(__int64 a1, unsigned int a2)
{
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))gsihal_get_reg_nk_ofst)(a1, 0, a2 >> 5);
}
