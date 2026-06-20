unsigned __int64 __fastcall qcom_clk_dump(unsigned __int64 result, unsigned __int64 a2, char a3)
{
  unsigned __int64 v4; // x20
  unsigned __int64 v5; // x20
  const char **v6; // x8
  const char *name; // x1

  if ( a2 && a2 <= 0xFFFFFFFFFFFFF000LL )
  {
    v4 = result;
    gdsc_debug_print_regs(a2);
    result = v4;
  }
  if ( result )
  {
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      result = _clk_get_hw();
      if ( result )
      {
        if ( result <= 0xFFFFFFFFFFFFF000LL )
        {
          v5 = result;
          clk_hw_get_name(result);
          printk(&unk_28383);
          result = clk_debug_print_hw(v5, 0);
          if ( (a3 & 1) != 0 )
          {
            v6 = *(const char ***)(v5 + 16);
            if ( v6 )
              name = *v6;
            else
              name = (const char *)clk_hw_get_name(v5);
            result = _warn_printk("%s: ", name);
            __break(0x800u);
          }
        }
      }
    }
  }
  return result;
}
