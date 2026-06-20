__int64 __fastcall clk_gfx3d_set_rate_and_parent(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  int v4; // w8
  __int64 v5; // x19
  __int64 v6; // x9
  unsigned int v7; // w10
  __int64 v8; // x0
  int v9; // w9
  int v10; // w10
  __int64 result; // x0

  v5 = a1 - 48;
  v4 = *(_DWORD *)(a1 - 48);
  v6 = *(_QWORD *)(a1 - 40);
  v7 = *(unsigned __int8 *)(a1 - 56);
  v8 = *(_QWORD *)(a1 + 24);
  v9 = *(unsigned __int8 *)(v6 + 2LL * a4 + 1);
  if ( v7 <= 1 )
    v10 = 0;
  else
    v10 = 2 * v7 - 1;
  result = regmap_write(v8, (unsigned int)(v4 + 4), v10 | (unsigned int)(v9 << 8));
  if ( !(_DWORD)result )
    return update_config(v5);
  return result;
}
