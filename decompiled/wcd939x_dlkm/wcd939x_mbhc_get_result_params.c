__int64 __fastcall wcd939x_mbhc_get_result_params(__int64 a1, __int64 a2, unsigned __int16 a3, unsigned int *a4)
{
  __int64 v10; // x23
  __int64 v11; // x0
  int v12; // w8
  int v13; // w24
  __int64 v14; // x0
  int v15; // w8
  __int64 v16; // x0
  __int64 updated; // x0
  unsigned __int16 v18; // w25
  int v19; // w24
  unsigned int v20; // w26
  int v21; // w8
  unsigned int v22; // w8
  int v23; // w20
  int v24; // w8
  __int64 result; // x0
  _QWORD v31[2]; // [xsp+0h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 256);
  v11 = *(_QWORD *)(a1 + 32);
  v31[0] = 0;
  regmap_update_bits_base(v11, 12310, 32, 32, 0, 0, 0);
  v12 = 899;
  do
  {
    v13 = v12;
    regmap_read(*(_QWORD *)(a1 + 32), 12312, (char *)v31 + 4);
    if ( (v31[0] & 0x8000000000LL) != 0 )
      break;
    v12 = v13 - 1;
  }
  while ( v13 );
  v14 = *(_QWORD *)(a1 + 32);
  HIDWORD(v31[0]) <<= 8;
  regmap_read(v14, 12311, v31);
  v15 = HIDWORD(v31[0]) | LODWORD(v31[0]);
  *(_DWORD *)(v10 + 1096) = HIDWORD(v31[0]) | LODWORD(v31[0]);
  v16 = *(_QWORD *)(a1 + 32);
  HIDWORD(v31[0]) = v15;
  updated = regmap_update_bits_base(v16, 12310, 32, 0, 0, 0, 0);
  v18 = WORD2(v31[0]);
  v19 = WORD2(v31[0]) & 0x3FFF;
  v20 = WORD2(v31[0]);
  if ( (v31[0] & 0x800000000000LL) == 0 && (v31[0] & 0x3FFF00000000LL) != 0 )
    updated = usleep_range_state(5000, 5050, 2);
  if ( v20 < 0x4000 || !v19 )
    goto LABEL_15;
  v21 = (-1 << (14 - a3)) + v19 * *(__int16 *)(a2 + 2LL * (v18 >> 14));
  if ( v21 >= 1 )
  {
    v22 = 0x415E6000u / v21;
LABEL_14:
    *a4 = v22;
    goto LABEL_15;
  }
  if ( a3 >= 8u )
  {
    __break(0x5512u);
    __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
    return wcd939x_hph_impedance_get(updated);
  }
  if ( v19 < dword_274F4[a3] )
  {
    v22 = 268435454;
    goto LABEL_14;
  }
LABEL_15:
  *(_BYTE *)(v10 + 1100) = 0;
  mod_timer(v10 + 1056, jiffies + 25LL);
  if ( v19 )
  {
    v23 = 900;
    do
    {
      regmap_read(*(_QWORD *)(a1 + 32), 12311, (char *)v31 + 4);
      regmap_read(*(_QWORD *)(a1 + 32), 12312, v31);
      --v23;
      v24 = LODWORD(v31[0]) | (HIDWORD(v31[0]) << 8);
      HIDWORD(v31[0]) = v24;
      if ( !v23 || *(_BYTE *)(v10 + 1100) == 1 && *(_DWORD *)(v10 + 1096) == v24 )
        break;
      *(_DWORD *)(v10 + 1096) = v24;
    }
    while ( (v24 & 0x3FFF) != 0 );
  }
  result = timer_delete((timer_t)(v10 + 1056));
  _ReadStatusReg(SP_EL0);
  return result;
}
