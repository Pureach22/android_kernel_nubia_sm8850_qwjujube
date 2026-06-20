__int64 __fastcall _clk_hfpll_enable(__int64 a1)
{
  unsigned int *v1; // x21
  __int64 v2; // x19
  __int64 updated; // x0
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 result; // x0
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned int **)(a1 - 16);
  v2 = *(_QWORD *)(a1 + 24);
  v8 = 0;
  _clk_hfpll_init_once(a1);
  regmap_update_bits_base(v2, *v1, 2, 2, 0, 0, 0);
  _const_udelay(42950);
  updated = regmap_update_bits_base(v2, *v1, 4, 4, 0, 0, 0);
  if ( v1[7] )
  {
    v4 = ktime_get(updated);
    v5 = regmap_read(v2, v1[7], &v8);
    if ( !(_DWORD)v5 )
    {
      v6 = v4 + 100000000;
      while ( (((unsigned __int64)v8 >> *((_BYTE *)v1 + 32)) & 1) != 0 )
      {
        if ( ktime_get(v5) > v6 )
        {
          regmap_read(v2, v1[7], &v8);
          break;
        }
        __yield();
        v5 = regmap_read(v2, v1[7], &v8);
        if ( (_DWORD)v5 )
          break;
      }
    }
  }
  else
  {
    _const_udelay(257700);
  }
  result = regmap_update_bits_base(v2, *v1, 1, 1, 0, 0, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
