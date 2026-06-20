__int64 __fastcall clk_rcg2_shared_set_parent(__int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x19
  int v5; // t1
  __int64 result; // x0
  unsigned int v7; // w8
  __int64 v8; // x9

  if ( (clk_hw_is_enabled(a1) & 1) != 0 )
  {
    v5 = *(_DWORD *)(a1 - 48);
    v4 = a1 - 48;
    result = regmap_update_bits_base(
               *(_QWORD *)(v4 + 72),
               v5 + (unsigned int)*(unsigned __int8 *)(v4 + 192) + 4,
               1792,
               *(unsigned __int8 *)(*(_QWORD *)(v4 + 8) + 2LL * a2 + 1) << 8,
               0,
               0,
               0);
    if ( !(_DWORD)result )
      return update_config(v4);
  }
  else
  {
    v7 = *(_DWORD *)(a1 + 148) & 0xFFFFF8FF;
    v8 = *(_QWORD *)(a1 - 40) + 2LL * a2;
    *(_DWORD *)(a1 + 148) = v7;
    *(_DWORD *)(a1 + 148) = v7 | (*(unsigned __int8 *)(v8 + 1) << 8);
    return 0;
  }
  return result;
}
