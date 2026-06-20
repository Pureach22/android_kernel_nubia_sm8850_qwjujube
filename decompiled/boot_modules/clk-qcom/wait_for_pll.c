__int64 __fastcall wait_for_pll(unsigned int *a1, int a2, unsigned __int8 a3, const char *a4)
{
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 result; // x0
  int v11; // w23
  const char **v12; // x8
  const char *name; // x1
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *((_QWORD *)a1 + 9);
  v9 = *a1;
  v14 = 0;
  result = regmap_read(v8, v9, &v14);
  if ( !(_DWORD)result )
  {
    v11 = 1501;
    while ( 1 )
    {
      result = regmap_read(*((_QWORD *)a1 + 9), *a1, &v14);
      if ( (_DWORD)result || (a3 & ((v14 & a2) == 0)) != 0 || (v14 & a2) == a2 )
        break;
      _const_udelay(4295);
      if ( (unsigned int)--v11 <= 1 )
      {
        clk_debug_print_hw(a1 + 12, 0);
        v12 = *((const char ***)a1 + 8);
        if ( v12 )
          name = *v12;
        else
          name = (const char *)clk_hw_get_name(a1 + 12);
        _warn_printk("%s: pll failed to %s!\n", name, a4);
        result = 4294967186LL;
        __break(0x800u);
        break;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
