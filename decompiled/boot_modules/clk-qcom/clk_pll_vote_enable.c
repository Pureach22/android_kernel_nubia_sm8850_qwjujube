__int64 __fastcall clk_pll_vote_enable(__int64 a1)
{
  __int64 parent; // x19
  __int64 result; // x0
  const char *name; // x20
  int v5; // w21
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  parent = clk_hw_get_parent(a1);
  result = clk_enable_regmap(a1);
  if ( !(_DWORD)result )
  {
    v6 = 0;
    name = (const char *)clk_hw_get_name(parent);
    v5 = 201;
    while ( 1 )
    {
      result = regmap_read(*(_QWORD *)(parent + 24), *(unsigned int *)(parent - 20), &v6);
      if ( (_DWORD)result )
        break;
      if ( (((unsigned __int64)v6 >> *(_BYTE *)(parent - 16)) & 1) != 0 )
      {
        result = 0;
        break;
      }
      _const_udelay(4295);
      if ( (unsigned int)--v5 <= 1 )
      {
        _warn_printk("%s didn't enable after voting for it!\n", name);
        result = 4294967186LL;
        __break(0x800u);
        break;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
