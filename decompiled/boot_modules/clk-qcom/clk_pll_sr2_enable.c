__int64 __fastcall clk_pll_sr2_enable(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 result; // x0
  const char *name; // x20
  int v6; // w21
  int v7; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 24);
  v3 = *(unsigned int *)(a1 - 24);
  v7 = 0;
  result = regmap_read(v2, v3, &v7);
  if ( !(_DWORD)result )
  {
    result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 24), 2, 2, 0, 0, 0);
    if ( !(_DWORD)result )
    {
      _const_udelay(42950);
      result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 24), 4, 4, 0, 0, 0);
      if ( !(_DWORD)result )
      {
        v8 = 0;
        name = (const char *)clk_hw_get_name(a1);
        v6 = 201;
        while ( 1 )
        {
          result = regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 20), &v8);
          if ( (_DWORD)result )
            break;
          if ( (((unsigned __int64)v8 >> *(_BYTE *)(a1 - 16)) & 1) != 0 )
          {
            result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 24), 1, 1, 0, 0, 0);
            break;
          }
          _const_udelay(4295);
          if ( (unsigned int)--v6 <= 1 )
          {
            _warn_printk("%s didn't enable after voting for it!\n", name);
            __break(0x800u);
            result = 4294967186LL;
            break;
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
