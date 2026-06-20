__int64 __fastcall llcc_staling_conf_notify(int a1, __int64 a2)
{
  unsigned int v2; // w8
  __int64 result; // x0
  unsigned int v4; // w8
  unsigned int v5; // w19
  __int64 v7; // x3

  v2 = *(_DWORD *)(a2 + 8);
  if ( v2 > 1 )
    return 4294967274LL;
  v4 = v2 << 12;
  v5 = (a1 << 12) | 0x10;
  if ( *(_DWORD *)(drv_data + 116) >> 25 > 2u )
    v7 = v4 + 1;
  else
    v7 = 1;
  result = regmap_update_bits_base(*(_QWORD *)(drv_data + 8), v5, 4097, v7, 0, 0, 0);
  if ( !(_DWORD)result )
    return regmap_update_bits_base(
             *(_QWORD *)(drv_data + 8),
             v5,
             112,
             16 * (unsigned int)*(unsigned __int8 *)(a2 + 4),
             0,
             0,
             0);
  return result;
}
