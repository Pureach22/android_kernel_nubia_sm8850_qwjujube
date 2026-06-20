__int64 __fastcall clk_regmap_div_list_rate(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 parent; // x21
  __int64 result; // x0
  __int64 v8; // x8
  _DWORD *v9; // x8
  __int64 v10; // x0
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  parent = clk_hw_get_parent(a1);
  v11 = 0;
  LODWORD(result) = clk_runtime_get_regmap(a1);
  if ( (_DWORD)result )
  {
    result = (int)result;
  }
  else
  {
    regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 24), &v11);
    v11 = ((v11 >> *(_DWORD *)(a1 - 20)) & ~(unsigned int)(-1LL << *(_DWORD *)(a1 - 16))) + 1;
    clk_runtime_put_regmap(a1);
    if ( parent && (v8 = *(_QWORD *)(parent + 88)) != 0 && (v9 = *(_DWORD **)(v8 + 8)) != nullptr )
    {
      if ( *(v9 - 1) != -958950422 )
        __break(0x8228u);
      v10 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v9)(parent, a2, a3);
      result = v10 / v11;
    }
    else
    {
      result = -22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
