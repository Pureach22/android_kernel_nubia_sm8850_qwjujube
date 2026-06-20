__int64 __fastcall stm_ftrace_write(__int64 a1, __int64 a2, unsigned int a3)
{
  return stm_source_write(a1 - 48, *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40), a2, a3);
}
