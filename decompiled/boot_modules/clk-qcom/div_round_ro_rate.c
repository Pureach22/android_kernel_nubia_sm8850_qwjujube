__int64 __fastcall div_round_ro_rate(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v7; // w22
  unsigned int v8; // w23
  __int64 parent; // x0
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  LODWORD(result) = clk_runtime_get_regmap(a1);
  if ( (_DWORD)result )
  {
    result = (int)result;
  }
  else
  {
    regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 24), &v10);
    v10 = (v10 >> *(_DWORD *)(a1 - 20)) & ~(unsigned int)(-1LL << *(_DWORD *)(a1 - 16));
    clk_runtime_put_regmap(a1);
    v7 = *(_DWORD *)(a1 - 16);
    v8 = v10;
    parent = clk_hw_get_parent(a1);
    result = divider_ro_round_rate_parent(a1, parent, a2, a3, 0, v7, 16, v8);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
