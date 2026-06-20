__int64 __fastcall kgsl_pwrctrl_clk_set_rate(__int64 a1, unsigned int a2, const char *a3)
{
  __int64 result; // x0

  result = clk_set_rate(a1, a2);
  if ( (_DWORD)result )
  {
    result = _warn_printk("%s set freq %d failed:%d\n", a3, a2, result);
    __break(0x800u);
  }
  return result;
}
