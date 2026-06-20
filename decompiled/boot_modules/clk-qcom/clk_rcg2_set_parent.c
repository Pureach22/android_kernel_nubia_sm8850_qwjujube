__int64 __fastcall clk_rcg2_set_parent(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x19
  __int64 result; // x0

  v2 = a1 - 48;
  result = regmap_update_bits_base(
             *(_QWORD *)(a1 + 24),
             *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(a1 + 144) + 4,
             1792,
             *(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 2LL * a2 + 1) << 8,
             0,
             0,
             0);
  if ( !(_DWORD)result )
    return update_config(v2);
  return result;
}
