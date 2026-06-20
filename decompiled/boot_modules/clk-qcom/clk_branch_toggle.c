__int64 __fastcall clk_branch_toggle(__int64 a1, int a2, _DWORD *a3)
{
  __int64 result; // x0
  int v7; // w23
  __int64 v8; // x1
  __int64 v9; // x0
  unsigned int v10; // w8
  int v11; // w8
  unsigned int v12; // w23
  unsigned int v13; // w24
  __int64 *v14; // x8
  __int64 name; // x1
  const char *v16; // x2
  unsigned int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
  {
    result = clk_enable_regmap(a1);
    if ( (_DWORD)result )
      goto LABEL_26;
  }
  else
  {
    clk_disable_regmap(a1);
  }
  v7 = *(unsigned __int8 *)(a1 - 6);
  if ( v7 != 3 )
  {
    v8 = *(unsigned int *)(a1 - 16);
    if ( (_DWORD)v8 )
    {
      v9 = *(_QWORD *)(a1 + 24);
      v17 = 0;
      regmap_read(v9, v8, &v17);
      result = 0;
      if ( (((unsigned __int64)v17 >> *(_BYTE *)(a1 - 8)) & 1) != 0 )
        goto LABEL_26;
      v10 = *(unsigned __int8 *)(a1 - 6);
    }
    else
    {
      v10 = *(unsigned __int8 *)(a1 - 6);
    }
    if ( (((v7 & 0x80u) != 0) & (a2 ^ 1)) != 0 || v10 == 2 )
    {
      _const_udelay(42950);
      result = 0;
      goto LABEL_26;
    }
    if ( (((v7 & 0x80u) != 0) & (unsigned __int8)a2) != 0 || v10 <= 1 )
    {
      v11 = 3 * (1000000 / (int)clk_hw_get_rate(a1));
      if ( v11 <= 200 )
        v12 = 200;
      else
        v12 = v11;
      v13 = v12 + 1;
      while ( 1 )
      {
        if ( *(a3 - 1) != -1859394466 )
          __break(0x8235u);
        if ( (((__int64 (__fastcall *)(__int64, _QWORD))a3)(a1 - 16, a2 & 1) & 1) != 0 )
          break;
        _const_udelay(4295);
        if ( (int)--v13 <= 1 )
        {
          clk_debug_print_hw(a1, 0);
          v14 = *(__int64 **)(a1 + 16);
          if ( v14 )
            name = *v14;
          else
            name = clk_hw_get_name(a1);
          if ( (a2 & 1) != 0 )
            v16 = "ff";
          else
            v16 = (const char *)&unk_282F4;
          _warn_printk("%s: status stuck at 'o%s' after %d us", name, v16, v12);
          result = 4294967280LL;
          __break(0x800u);
          goto LABEL_26;
        }
      }
    }
  }
  result = 0;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
