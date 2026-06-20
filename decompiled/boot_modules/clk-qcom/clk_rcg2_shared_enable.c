__int64 __fastcall clk_rcg2_shared_enable(__int64 a1)
{
  __int64 result; // x0

  result = clk_rcg2_set_force_enable(a1);
  if ( !(_DWORD)result )
  {
    result = regmap_write(*(_QWORD *)(a1 + 24), (unsigned int)(*(_DWORD *)(a1 - 48) + 4), *(unsigned int *)(a1 + 148));
    if ( !(_DWORD)result )
    {
      result = update_config(a1 - 48);
      if ( !(_DWORD)result )
        return regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 2, 0, 0, 0, 0);
    }
  }
  return result;
}
