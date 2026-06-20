__int64 __fastcall alpha_pll_pongo_elu_disable(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 24);
  result = regmap_update_bits_base(v1, *(unsigned int *)(a1 - 48), 1, 0, 0, 0, 0);
  if ( !(_DWORD)result )
    return regmap_write(v1, *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL), 0);
  return result;
}
