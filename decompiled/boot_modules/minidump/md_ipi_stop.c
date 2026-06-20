__int64 __fastcall md_ipi_stop(__int64 a1, __int64 *a2)
{
  unsigned __int64 v2; // x27
  __int64 v3; // x8

  v3 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
  if ( (unsigned int)v3 >= 0x20 )
  {
    __break(0x5512u);
    _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v2);
    return md_panic_handler();
  }
  else
  {
    memcpy((char *)&regs_before_stop + _per_cpu_offset[v3], a2, 0x150u);
    return dump_stack_minidump(a2[31]);
  }
}
