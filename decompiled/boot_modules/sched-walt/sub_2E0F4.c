__int64 __fastcall sub_2E0F4(__int64 a1)
{
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  return walt_init_tg(a1);
}
