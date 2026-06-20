__int64 __fastcall alpha_pll_fabia_enable(__int64 a1)
{
  __int64 v2; // x1
  unsigned int *v3; // x19
  __int64 v4; // x20
  __int64 result; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (unsigned int *)(a1 - 48);
  v2 = *(unsigned int *)(a1 - 48);
  v4 = *(_QWORD *)(a1 + 24);
  v6[0] = 0;
  result = regmap_read(v4, v2, (char *)v6 + 4);
  if ( !(_DWORD)result )
  {
    if ( (v6[0] & 0x10000000000000LL) != 0 )
    {
      result = clk_enable_regmap(a1);
      if ( !(_DWORD)result )
        result = wait_for_pll(v3, 0x40000000, 0, "enable");
    }
    else
    {
      result = regmap_read(
                 v4,
                 *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL),
                 v6);
      if ( !(_DWORD)result )
      {
        if ( (v6[0] & 1) != 0 && (v6[0] & 0x100000000LL) != 0 )
        {
          result = 0;
        }
        else
        {
          result = regmap_update_bits_base(v4, *v3, 1, 0, 0, 0, 0);
          if ( !(_DWORD)result )
          {
            result = regmap_write(
                       v4,
                       *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL),
                       0);
            if ( !(_DWORD)result )
            {
              result = regmap_update_bits_base(v4, *v3, 4, 4, 0, 0, 0);
              if ( !(_DWORD)result )
              {
                result = regmap_write(
                           v4,
                           *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL),
                           1);
                if ( !(_DWORD)result )
                {
                  result = wait_for_pll(v3, 0x80000000LL, 0, "enable");
                  if ( !(_DWORD)result )
                  {
                    result = regmap_update_bits_base(
                               v4,
                               *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
                               7,
                               7,
                               0,
                               0,
                               0);
                    if ( !(_DWORD)result )
                      result = regmap_update_bits_base(v4, *v3, 1, 1, 0, 0, 0);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
