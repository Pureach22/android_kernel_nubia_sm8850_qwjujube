__int64 __fastcall clk_rcg2_set_duty_cycle(__int64 a1, _DWORD *a2)
{
  char v2; // w21
  int v3; // w8
  int v4; // w9
  __int64 v6; // x0
  __int64 v8; // x10
  unsigned int v9; // w9
  __int64 v10; // x2
  unsigned int v11; // w8
  unsigned int v12; // w9
  unsigned int v13; // w8
  unsigned int v14; // w12
  unsigned int v15; // w8
  unsigned int v16; // w12
  __int64 result; // x0
  int v18; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v19; // [xsp+10h] [xbp-10h] BYREF
  int v20; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_BYTE *)(a1 - 44);
  if ( !v2 )
    goto LABEL_14;
  v3 = *(_DWORD *)(a1 - 48);
  v4 = *(unsigned __int8 *)(a1 + 144);
  v6 = *(_QWORD *)(a1 + 24);
  v20 = 0;
  v18 = 0;
  v19 = 0;
  regmap_read(v6, (unsigned int)(v3 + v4 + 12), &v20);
  regmap_read(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(a1 + 144) + 8, &v19);
  regmap_read(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(a1 + 144) + 4, &v18);
  if ( (v18 & 0x3000) != 0 )
  {
    v8 = -1LL << v2;
    v9 = (v19 + ~v20) & ~(unsigned int)(-1LL << v2);
    v10 = (unsigned int)~(-1 << v2);
    v11 = v9 * ((unsigned int)(100 * *a2) / a2[1]);
    v12 = v9 - v19;
    v13 = 2 * v11 + 50;
    v14 = v13 / 0x64;
    if ( v13 < 0xC8 )
      v15 = 1;
    else
      v15 = v13 / 0x64;
    if ( v14 >= (unsigned int)v10 )
      v15 = ~(_DWORD)v8;
    v16 = v15 >> 1;
    if ( v15 >> 1 < v19 >> 1 )
      v15 = v19;
    if ( v16 > v12 )
      v15 = 2 * v12;
    result = regmap_update_bits_base(
               *(_QWORD *)(a1 + 24),
               *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(a1 + 144) + 16,
               v10,
               ~v15 & ~(_DWORD)v8,
               0,
               0,
               0);
    if ( !(_DWORD)result )
      result = update_config(a1 - 48);
  }
  else
  {
LABEL_14:
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
