__int64 sub_D6B0()
{
  __int64 v0; // x0

  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  v0 = MEMORY[0xFFFFFFFFFE378FCC]();
  return coresight_add_out_conn(v0);
}
