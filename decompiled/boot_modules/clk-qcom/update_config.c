__int64 __fastcall update_config(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 result; // x0
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x10
  int v7; // w20
  int v8; // w21
  const char **v9; // x8
  const char *name; // x1
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[9];
  v3 = *(unsigned int *)a1;
  v11 = 0;
  result = regmap_update_bits_base(v2, v3, 1, 1, 0, 0, 0);
  if ( !(_DWORD)result )
  {
    v5 = a1[3];
    if ( v5 )
      LODWORD(v5) = 3 * (0xF4240 / v5);
    v6 = a1[2];
    if ( v6 )
      LODWORD(v5) = 3 * (0xF4240 / v6) + v5;
    if ( (unsigned int)v5 <= 0x1F4 )
      v7 = 500;
    else
      v7 = v5;
    v8 = v7 + 1;
    while ( 1 )
    {
      result = regmap_read(a1[9], *(unsigned int *)a1, &v11);
      if ( (_DWORD)result )
        break;
      if ( (v11 & 1) == 0 )
      {
        result = 0;
        break;
      }
      _const_udelay(4295);
      if ( --v8 <= 1 )
      {
        clk_debug_print_hw((unsigned __int64)(a1 + 6), 0);
        v9 = (const char **)a1[8];
        if ( v9 )
          name = *v9;
        else
          name = (const char *)clk_hw_get_name(a1 + 6);
        _warn_printk("%s: rcg didn't update its configuration after %d us.", name, v7);
        result = 4294967280LL;
        __break(0x800u);
        break;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
