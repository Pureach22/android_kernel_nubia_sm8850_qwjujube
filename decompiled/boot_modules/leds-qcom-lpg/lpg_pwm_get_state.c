__int64 __fastcall lpg_pwm_get_state(__int64 a1, __int64 a2, unsigned __int64 *a3)
{
  __int64 v4; // x20
  unsigned int v5; // w8
  __int64 v6; // x21
  __int64 result; // x0
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x11
  int *v10; // x9
  char *v11; // x10
  unsigned __int64 v12; // x13
  unsigned __int64 v13; // x12
  unsigned __int64 v14; // x22
  int v15; // w23
  char v16; // w24
  unsigned int v17; // w25
  __int64 v18; // x9
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x9
  char v21; // w9
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x10
  _WORD v24[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v5 = *(_DWORD *)(a2 + 16);
  v25 = 0;
  v24[0] = 0;
  v6 = *(_QWORD *)(v4 + 144) + 104LL * v5;
  result = regmap_read(*(_QWORD *)(v4 + 8), (unsigned int)(*(_DWORD *)(v6 + 8) + 65), &v25);
  if ( (_DWORD)result )
    goto LABEL_2;
  if ( *(_DWORD *)(v6 + 20) == 12 )
  {
    v8 = v25 & 7;
    if ( v8 >= 5 )
    {
LABEL_18:
      __break(0x5512u);
      JUMPOUT(0x8924);
    }
    v9 = ((unsigned __int64)v25 >> 4) & 7;
    v10 = &lpg_clk_rates_hi_res[v8];
    v11 = (char *)&lpg_pwm_resolution_hi_res + 4 * v9;
    v12 = 32;
    v13 = 20;
  }
  else
  {
    v9 = ((unsigned __int64)v25 >> 2) & 1;
    v8 = v25 & 3;
    v10 = &lpg_clk_rates[v8];
    v11 = (char *)&lpg_pwm_resolution + 4 * v9;
    v12 = 8;
    v13 = 16;
  }
  if ( v12 <= 4 * v9 || v13 <= 4 * v8 )
  {
    __break(1u);
    goto LABEL_18;
  }
  v14 = (unsigned int)*v10;
  if ( (_DWORD)v14 )
  {
    v15 = *(_DWORD *)v11;
    result = regmap_read(*(_QWORD *)(v4 + 8), (unsigned int)(*(_DWORD *)(v6 + 8) + 66), &v25);
    if ( (_DWORD)result )
      goto LABEL_2;
    v16 = v25;
    v17 = lpg_pre_divs[((unsigned __int64)v25 >> 5) & 3];
    result = regmap_bulk_read(*(_QWORD *)(v4 + 8), (unsigned int)(*(_DWORD *)(v6 + 8) + 68), v24, 2);
    if ( (_DWORD)result )
      goto LABEL_2;
    v18 = 1000000000LL * v17;
    v19 = (v14 - 1 + ((v18 * (unsigned int)~(-1 << v15)) << (v16 & 7))) / v14;
    v20 = (v14 - 1 + ((v18 * v24[0]) << (v16 & 7))) / v14;
    *a3 = v19;
    a3[1] = v20;
  }
  else
  {
    *a3 = 0;
    a3[1] = 0;
  }
  result = regmap_read(*(_QWORD *)(v4 + 8), (unsigned int)(*(_DWORD *)(v6 + 8) + 70), &v25);
  if ( !(_DWORD)result )
  {
    v21 = v25;
    v22 = *a3;
    v23 = a3[1];
    *((_DWORD *)a3 + 4) = 0;
    *((_BYTE *)a3 + 20) = v21 < 0;
    if ( v23 > v22 )
    {
      result = 0;
      a3[1] = v22;
    }
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
