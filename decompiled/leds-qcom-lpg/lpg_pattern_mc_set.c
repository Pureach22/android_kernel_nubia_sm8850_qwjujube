__int64 __fastcall lpg_pattern_mc_set(__int64 a1)
{
  int v1; // w9
  __int64 v3; // x20
  signed int v4; // w10
  unsigned int v5; // w8
  int v6; // w8
  int v7; // w11
  __int64 *v8; // x12
  unsigned int v9; // w13
  __int64 v10; // x14
  __int64 v11; // x15
  __int64 v12; // x12
  int v13; // w9
  __int64 result; // x0

  v1 = *(_DWORD *)(a1 + 464);
  v3 = a1 - 456;
  if ( !v1 )
  {
    v5 = 0;
    goto LABEL_9;
  }
  if ( (unsigned int)(v1 + 0x7FFFFFFF) < 0x80000001 )
  {
    v4 = 0;
    v5 = 0;
    do
    {
LABEL_8:
      v12 = *(_QWORD *)(a1 + 472 + 8LL * v4++);
      v5 |= *(_DWORD *)(v12 + 12);
    }
    while ( v1 != v4 );
    goto LABEL_9;
  }
  v4 = v1 & 0xFFFFFFFE;
  v6 = 0;
  v7 = 0;
  v8 = (__int64 *)(a1 + 480);
  v9 = v1 & 0xFFFFFFFE;
  do
  {
    v10 = *(v8 - 1);
    v11 = *v8;
    v9 -= 2;
    v8 += 2;
    v6 |= *(_DWORD *)(v10 + 12);
    v7 |= *(_DWORD *)(v11 + 12);
  }
  while ( v9 );
  v5 = v7 | v6;
  if ( v1 != v4 )
    goto LABEL_8;
LABEL_9:
  v13 = *(_DWORD *)(*(_QWORD *)v3 + 128LL);
  if ( v13 )
    regmap_update_bits_base(*(_QWORD *)(*(_QWORD *)v3 + 8LL), (unsigned int)(v13 + 70), v5, 0, 0, 0, 0);
  result = lpg_pattern_set(v3);
  if ( (result & 0x80000000) == 0 )
  {
    led_mc_calc_color_components(a1, 255);
    lpg_brightness_set(v3, a1, *(_QWORD *)(a1 + 456));
    return 0;
  }
  return result;
}
