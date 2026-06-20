__int64 __fastcall alpha_pll_lucid_evo_enable(__int64 a1)
{
  int v2; // w8
  unsigned int *v3; // x19
  __int64 v4; // x9
  __int64 v5; // x20
  __int64 result; // x0
  __int64 v7; // x1
  int v8; // w22
  int v9; // [xsp+Ch] [xbp-14h] BYREF
  int v10; // [xsp+10h] [xbp-10h] BYREF
  int v11; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (unsigned int *)(a1 - 48);
  v2 = *(_DWORD *)(a1 - 48);
  v4 = *(_QWORD *)(a1 - 40);
  v9 = 0;
  v5 = *(_QWORD *)(a1 + 24);
  result = regmap_read(v5, v2 + (unsigned int)*(unsigned __int8 *)(v4 + 5), &v9);
  if ( !(_DWORD)result )
  {
    if ( (v9 & 0x2000000) != 0 )
    {
      result = clk_enable_regmap(a1);
      if ( !(_DWORD)result )
        result = wait_for_pll(v3, 0x80000000, 0, "enable");
    }
    else
    {
      v7 = *(unsigned int *)(a1 - 48);
      v11 = 0;
      v10 = 0;
      v8 = regmap_read(v5, v7, &v11);
      if ( !((unsigned int)regmap_read(
                             v5,
                             *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL),
                             &v10)
           | v8)
        && (v10 & 1) != 0
        && (v11 & 1) != 0 )
      {
        clk_hw_get_name(a1);
        printk(&unk_29592);
        result = 0;
      }
      else
      {
        result = regmap_update_bits_base(v5, *v3, 4, 4, 0, 0, 0);
        if ( !(_DWORD)result )
        {
          regmap_write(v5, *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL), 1);
          result = wait_for_pll(v3, 0x80000000, 0, "enable");
          if ( !(_DWORD)result )
          {
            result = regmap_update_bits_base(v5, *v3, 1, 1, 0, 0, 0);
            if ( !(_DWORD)result )
              __dsb(0xFu);
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
