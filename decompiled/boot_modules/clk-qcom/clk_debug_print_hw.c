unsigned __int64 __fastcall clk_debug_print_hw(unsigned __int64 result, __int64 a2)
{
  unsigned __int64 v2; // x19
  __int64 parent; // x0
  const char *name; // x2
  void (__fastcall **v6)(__int64, unsigned __int64); // x8
  void (__fastcall *v7)(__int64, unsigned __int64); // x8

  if ( result )
  {
    v2 = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( *(_QWORD *)result )
      {
        parent = clk_hw_get_parent(result);
        clk_debug_print_hw(parent, a2);
        name = (const char *)clk_hw_get_name(v2);
        if ( a2 )
          seq_printf(a2, "%s\n", name);
        else
          printk(&unk_295AF);
        result = clk_is_regmap_clk(v2);
        if ( (result & 1) != 0 )
        {
          result = clk_runtime_get_regmap(v2);
          if ( !(_DWORD)result )
          {
            v6 = *(void (__fastcall ***)(__int64, unsigned __int64))(v2 + 88);
            if ( v6 )
            {
              v7 = *v6;
              if ( v7 )
              {
                if ( *((_DWORD *)v7 - 1) != -338772572 )
                  __break(0x8228u);
                v7(a2, v2);
              }
            }
            return clk_runtime_put_regmap(v2);
          }
        }
      }
    }
  }
  return result;
}
