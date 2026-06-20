__int64 sub_12C40()
{
  unsigned __int64 *v0; // x19

  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  atomic_load(v0);
  atomic_load((unsigned int *)v0);
  if ( !atomic_load((unsigned int *)v0) )
    JUMPOUT(0xAEEE8);
  return arm_tbu_micro_idle_wake();
}
