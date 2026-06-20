__int64 __fastcall dot11f_pack_ie_transmit_power_env(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  unsigned int v6; // w9
  unsigned int v7; // w8
  __int64 result; // x0
  int v9; // w21
  _BYTE *v10; // x20
  unsigned int v13; // w23
  int v14; // w9
  unsigned int v15; // w10
  _BYTE *v16; // x0
  bool v17; // zf
  _BYTE *v18; // x10
  int v19; // w20

  if ( !*a2 )
    return 0;
  v6 = (((unsigned __int8)a2[1] >> 3) & 7) - 1;
  v7 = (unsigned __int8)a2[2] + 1;
  if ( v6 <= 4 )
    v7 += dword_A160B0[v6];
  if ( v7 > a4 )
    return 268435461;
  v9 = *a5;
  v10 = a3 + 3;
  *a3 = -61;
  v13 = a4 - 1;
  *a5 += 2;
  a3[2] = a2[1];
  ++*a5;
  qdf_mem_copy(a3 + 3, a2 + 3, (unsigned __int8)a2[2]);
  v14 = *a5 + (unsigned __int8)a2[2];
  *a5 = v14;
  v15 = ((unsigned __int8)a2[1] >> 3) & 7;
  v16 = &v10[(unsigned __int8)a2[2]];
  if ( v15 > 2 )
  {
    if ( v15 != 3 )
    {
      if ( v15 == 4 )
      {
        v19 = 1;
        *v16 = a2[11];
LABEL_19:
        v18 = a3;
        goto LABEL_20;
      }
      v17 = v15 == 5;
      v18 = a3;
      if ( !v17 )
        goto LABEL_21;
    }
LABEL_16:
    if ( !v13 )
      return 4;
    v19 = 15;
    *v16 = a2[11];
    ++*a5;
    qdf_mem_copy(v16 + 1, a2 + 12, 0xFu);
    goto LABEL_19;
  }
  if ( v15 == 1 )
    goto LABEL_16;
  v17 = v15 == 2;
  v18 = a3;
  if ( v17 )
  {
    v19 = 1;
    *v16 = a2[11];
LABEL_20:
    v14 = *a5 + v19;
    *a5 = v14;
  }
LABEL_21:
  result = 0;
  if ( v18 != (_BYTE *)-1LL )
    v18[1] = v14 - v9 - 2;
  return result;
}
