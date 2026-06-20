__int64 __fastcall wcd9378_mbhc_get_result_params(__int64 a1, __int64 a2, unsigned __int16 a3, unsigned int *a4)
{
  __int64 v10; // x0
  int v11; // w8
  int v12; // w24
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 result; // x0
  unsigned __int16 v16; // w25
  int v17; // w24
  unsigned int v18; // w26
  int v19; // w8
  unsigned int v20; // w8
  int v21; // w20
  __int16 v23; // w8
  _QWORD v28[2]; // [xsp+0h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 48);
  v28[0] = 0;
  regmap_update_bits_base(v10, 1075314710, 32, 32, 0, 0, 0);
  v11 = 899;
  do
  {
    v12 = v11;
    regmap_read(*(_QWORD *)(a1 + 48), 1075314712, (char *)v28 + 4);
    if ( (v28[0] & 0x8000000000LL) != 0 )
      break;
    v11 = v12 - 1;
  }
  while ( v12 );
  v13 = *(_QWORD *)(a1 + 48);
  HIDWORD(v28[0]) <<= 8;
  regmap_read(v13, 1075314711, v28);
  v14 = *(_QWORD *)(a1 + 48);
  HIDWORD(v28[0]) |= LODWORD(v28[0]);
  result = regmap_update_bits_base(v14, 1075314710, 32, 0, 0, 0, 0);
  v16 = WORD2(v28[0]);
  v17 = WORD2(v28[0]) & 0x3FFF;
  v18 = WORD2(v28[0]);
  if ( (v28[0] & 0x800000000000LL) == 0 && (v28[0] & 0x3FFF00000000LL) != 0 )
    result = usleep_range_state(5000, 5050, 2);
  if ( v18 < 0x4000 || !v17 )
  {
    *a4 = 0;
    if ( !v17 )
    {
LABEL_21:
      _ReadStatusReg(SP_EL0);
      return result;
    }
LABEL_17:
    v21 = 899;
    do
    {
      regmap_read(*(_QWORD *)(a1 + 48), 1075314711, (char *)v28 + 4);
      result = regmap_read(*(_QWORD *)(a1 + 48), 1075314712, v28);
      _CF = v21-- != 0;
      v23 = LOWORD(v28[0]) | (WORD2(v28[0]) << 8);
      HIDWORD(v28[0]) = LODWORD(v28[0]) | (HIDWORD(v28[0]) << 8);
    }
    while ( _CF && (v23 & 0x3FFF) != 0 );
    goto LABEL_21;
  }
  v19 = (-1 << (14 - a3)) + v17 * *(__int16 *)(a2 + 2LL * (v16 >> 14));
  if ( v19 >= 1 )
  {
    v20 = 0x53FC0000u / v19;
LABEL_16:
    *a4 = v20;
    goto LABEL_17;
  }
  if ( a3 < 8u )
  {
    if ( v17 >= dword_5F844[a3] )
      goto LABEL_17;
    v20 = 268435454;
    goto LABEL_16;
  }
  __break(0x5512u);
  __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
  return wcd9378_hph_impedance_get(result);
}
