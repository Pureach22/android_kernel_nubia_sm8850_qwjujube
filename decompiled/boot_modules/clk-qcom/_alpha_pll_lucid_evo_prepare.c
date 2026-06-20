__int64 __fastcall alpha_pll_lucid_evo_prepare(__int64 a1, char a2)
{
  __int64 v4; // x21
  __int64 result; // x0
  __int64 parent; // x0
  __int64 v7; // x22
  __int64 v8; // x21
  __int64 rate; // x0
  __int64 v10; // x0
  unsigned int vdd_level; // w21
  int v12; // w0
  int v13; // w22
  unsigned int v14; // w20
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  v15 = 0;
  result = clk_prepare_regmap(a1);
  if ( !(_DWORD)result )
  {
    regmap_read(v4, *(unsigned int *)(a1 - 48), &v15);
    if ( (v15 & 0x100) == 0 && (*(_BYTE *)(a1 - 8) & 0x40) == 0 )
    {
LABEL_4:
      result = 0;
      goto LABEL_14;
    }
    parent = clk_hw_get_parent(a1);
    if ( parent )
    {
      v7 = parent;
      regmap_read(v4, *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL), &v15);
      v8 = BYTE2(v15);
      v15 = BYTE2(v15);
      rate = clk_hw_get_rate(v7);
      v10 = clk_hw_round_rate(a1, rate * v8);
      vdd_level = clk_find_vdd_level(a1, a1 + 48, v10);
      if ( (vdd_level & 0x80000000) != 0 )
      {
        v12 = vdd_level;
      }
      else
      {
        v12 = clk_vote_vdd_level(a1 + 48, vdd_level);
        if ( !v12 )
        {
          v13 = alpha_pll_lucid_evo_enable(a1);
          clk_unvote_vdd_level(a1 + 48, vdd_level);
          v12 = v13;
          if ( !v13 )
          {
            if ( (*(_BYTE *)(a1 - 8) & 0x40) == 0 )
              alpha_pll_lucid_evo_disable(a1, a2 & 1);
            goto LABEL_4;
          }
        }
      }
    }
    else
    {
      v12 = -22;
    }
    v14 = v12;
    clk_unprepare_regmap(a1);
    result = v14;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
