__int64 __fastcall clk_rcg2_set_force_enable(unsigned __int64 a1)
{
  unsigned int updated; // w19
  int v3; // w21
  __int64 v4; // x0
  __int64 v5; // x1
  const char **v6; // x8
  const char *name; // x1
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  updated = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 2, 2, 0, 0, 0);
  if ( !updated )
  {
    v3 = 501;
    while ( 1 )
    {
      v4 = *(_QWORD *)(a1 + 24);
      v5 = *(unsigned int *)(a1 - 48);
      v9 = 0;
      if ( (unsigned int)regmap_read(v4, v5, &v9) || (v9 & 0x80000000) == 0 )
        break;
      _const_udelay(4295);
      if ( (unsigned int)--v3 <= 1 )
      {
        clk_debug_print_hw(a1, 0);
        v6 = *(const char ***)(a1 + 16);
        if ( v6 )
          name = *v6;
        else
          name = (const char *)clk_hw_get_name(a1);
        _warn_printk("%s: rcg didn't turn on.", name);
        __break(0x800u);
        break;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return updated;
}
