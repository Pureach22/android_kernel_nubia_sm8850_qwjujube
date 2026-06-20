__int64 sub_5221C()
{
  _ReadStatusReg(TPIDR_EL2);
  __asm { LDTRSH          W0, [X10,#0x4D] }
  return _traceiter_sched_switch_with_ctrs(_X0);
}
