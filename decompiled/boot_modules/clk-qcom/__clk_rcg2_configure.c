__int64 __fastcall _clk_rcg2_configure(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 result; // x0
  __int16 v7; // w9
  int v8; // w23
  unsigned int v9; // w22
  unsigned int v10; // w8
  unsigned int v11; // w9
  unsigned int v12; // w10
  unsigned int v13; // w8
  int v14; // w8

  result = qcom_find_src_index(a1 + 48, *(_QWORD *)(a1 + 8), *(unsigned __int8 *)(a2 + 8));
  if ( (result & 0x80000000) != 0 )
    return result;
  if ( !*(_BYTE *)(a1 + 4) )
  {
    LOBYTE(v7) = 1;
LABEL_14:
    v14 = *(unsigned __int8 *)(a2 + 9)
        | (*(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 2LL * (unsigned int)result + 1) << 8);
    if ( (v7 & 1) == 0 && *(_WORD *)(a2 + 12) && *(unsigned __int16 *)(a2 + 10) != *(unsigned __int16 *)(a2 + 12) )
      v14 |= 0x2000u;
    if ( (*(_BYTE *)(a1 + 202) & 1) != 0 || (*(_BYTE *)(a1 + 200) & 2) != 0 )
      v14 |= 0x100000u;
    *a3 = (-1LL << *(_BYTE *)(a1 + 5)) & 0xFFEFC8FF & *a3 | v14;
    return 0;
  }
  v7 = *(_WORD *)(a2 + 12);
  if ( !v7 )
    goto LABEL_14;
  v8 = result;
  v9 = ~(-1 << *(_BYTE *)(a1 + 4));
  result = regmap_update_bits_base(
             *(_QWORD *)(a1 + 72),
             *(_DWORD *)a1 + (unsigned int)*(unsigned __int8 *)(a1 + 192) + 8,
             v9,
             *(unsigned __int16 *)(a2 + 10),
             0,
             0,
             0);
  if ( !(_DWORD)result )
  {
    result = regmap_update_bits_base(
               *(_QWORD *)(a1 + 72),
               *(_DWORD *)a1 + (unsigned int)*(unsigned __int8 *)(a1 + 192) + 12,
               v9,
               *(unsigned __int16 *)(a2 + 10) + ~*(unsigned __int16 *)(a2 + 12),
               0,
               0,
               0);
    if ( !(_DWORD)result )
    {
      v10 = *(unsigned __int16 *)(a2 + 12);
      v11 = *(unsigned __int16 *)(a2 + 10);
      v12 = 2 * (v10 - v11);
      if ( v10 > v11 )
        v11 = *(unsigned __int16 *)(a2 + 12);
      v13 = v12 <= v10 ? v12 : v11;
      result = regmap_update_bits_base(
                 *(_QWORD *)(a1 + 72),
                 *(_DWORD *)a1 + (unsigned int)*(unsigned __int8 *)(a1 + 192) + 16,
                 v9,
                 v9 & ~v13,
                 0,
                 0,
                 0);
      if ( !(_DWORD)result )
      {
        LODWORD(result) = v8;
        LOBYTE(v7) = *(_BYTE *)(a1 + 4) == 0;
        goto LABEL_14;
      }
    }
  }
  return result;
}
