__int64 __fastcall clk_regera_pll_enable(__int64 a1)
{
  __int64 v2; // x1
  unsigned int *v3; // x20
  __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // w21
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (unsigned int *)(a1 - 48);
  v2 = *(unsigned int *)(a1 - 48);
  v4 = *(_QWORD *)(a1 + 24);
  v7[0] = 0;
  result = regmap_read(v4, v2, (char *)v7 + 4);
  if ( !(_DWORD)result )
  {
    if ( (v7[0] & 0x10000000000000LL) != 0 )
    {
      result = clk_enable_regmap(a1);
      if ( !(_DWORD)result )
        result = wait_for_pll(v3, 0x40000000, 0, "enable");
    }
    else
    {
      result = regmap_read(
                 *(_QWORD *)(a1 + 24),
                 *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL),
                 v7);
      if ( !(_DWORD)result )
      {
        if ( !LODWORD(v7[0]) )
        {
          v6 = clk_regera_pll_configure(v3, *(_QWORD *)(a1 + 24), *(unsigned int **)(a1 - 32));
          clk_hw_get_name(a1);
          if ( v6 )
          {
            printk(&unk_28177);
            result = v6;
            goto LABEL_2;
          }
          printk(&unk_28578);
        }
        result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 2, 2, 0, 0, 0);
        if ( !(_DWORD)result )
        {
          __dsb(0xFu);
          _const_udelay(4295);
          result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 4, 4, 0, 0, 0);
          if ( !(_DWORD)result )
          {
            regmap_write(
              *(_QWORD *)(a1 + 24),
              *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL),
              1);
            result = wait_for_pll(v3, 0x80000000, 0, "enable");
            if ( !(_DWORD)result )
            {
              result = regmap_update_bits_base(
                         *(_QWORD *)(a1 + 24),
                         *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
                         15,
                         15,
                         0,
                         0,
                         0);
              if ( !(_DWORD)result )
              {
                result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 1, 1, 0, 0, 0);
                if ( !(_DWORD)result )
                  __dsb(0xFu);
              }
            }
          }
        }
      }
    }
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
