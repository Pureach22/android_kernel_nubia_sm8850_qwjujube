__int64 __fastcall sub_FA28(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int16 a7)
{
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  return mhi_read_reg(a1, a2, 2 * (a7 & 0x7FFFu), a4);
}
