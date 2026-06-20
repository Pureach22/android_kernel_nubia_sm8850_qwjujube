__int64 __fastcall sde_dsc_populate_dsc_config(__int64 a1, int a2)
{
  int v2; // w10
  int v3; // w8
  int v5; // w8
  unsigned int v6; // w9
  unsigned int v7; // w8
  unsigned __int8 v8; // w9
  unsigned int v9; // w10
  unsigned __int8 v10; // w11
  unsigned int v11; // w21
  unsigned int v12; // w20
  char v13; // w8
  __int64 rc_table_index; // x0
  __int64 result; // x0
  signed int v16; // w8
  __int64 v17; // x13
  unsigned __int64 v18; // x10
  __int64 v19; // x15
  char v20; // w16
  __int64 v21; // x10
  _DWORD *v22; // x9
  int v23; // w11
  int v24; // w14
  int v25; // w13
  int v26; // w10
  unsigned int v27; // w12
  int v28; // w15
  int v29; // w9
  int v30; // w0
  int v31; // w15
  int v32; // w1
  int v33; // w3
  __int64 v34; // x14
  int v35; // w13
  unsigned int v36; // w12
  int v37; // w16
  int v38; // w17
  unsigned __int16 v39; // w12
  int v40; // w8
  int v41; // w10
  int v42; // w9
  int v43; // w10
  int v44; // w9

  v2 = *(unsigned __int8 *)(a1 + 127);
  v3 = *(unsigned __int8 *)(a1 + 126);
  *(_WORD *)(a1 + 104) = 0x2000;
  if ( v2 == 1 && v3 == 1 )
  {
    if ( a2 == 1 )
      LOBYTE(v5) = 15;
    else
      LOBYTE(v5) = 12;
  }
  else
  {
    if ( v3 != 2 )
      goto LABEL_24;
    v6 = *(unsigned __int16 *)(a1 + 6);
    v7 = *(unsigned __int16 *)(a1 + 16);
    if ( v6 > 7 )
    {
      if ( v6 >= 0x14 )
      {
        if ( v6 >= 0x1F )
        {
          if ( v6 < 0x2A )
            v8 = 14;
          else
            v8 = 15;
        }
        else
        {
          v8 = 13;
        }
      }
      else
      {
        v8 = 12;
      }
    }
    else
    {
      v8 = 2 * v6 - 2;
    }
    v9 = v7 >> 4;
    if ( *(_BYTE *)(a1 + 128) == 1 )
    {
      v10 = 12 * v9;
    }
    else if ( *(_BYTE *)(a1 + 129) == 1 )
    {
      v10 = 3 * v9;
    }
    else
    {
      v10 = 9 * v9 + 6;
    }
    v5 = v10 - 3 * (unsigned __int8)(v7 >> 4);
    if ( v5 > v8 )
      LOBYTE(v5) = v8;
  }
  *(_BYTE *)(a1 + 27) = v5;
LABEL_24:
  v11 = *(unsigned __int16 *)(a1 + 16);
  v12 = *(unsigned __int8 *)(a1 + 1);
  v13 = *(_BYTE *)(a1 + 129) | *(_BYTE *)(a1 + 128);
  *(_BYTE *)(a1 + 8) = 0;
  *(_BYTE *)(a1 + 18) = 6;
  *(_WORD *)(a1 + 14) = 771;
  *(_BYTE *)(a1 + 2) = v13 ^ 1;
  *(_BYTE *)(a1 + 120) = 0;
  rc_table_index = get_rc_table_index(a1);
  if ( (unsigned int)rc_table_index > 0xD )
    return 4294967274LL;
  *(_DWORD *)(a1 + 54) = 8257661;
  v16 = v11 >> 4;
  v17 = 58;
  *(_QWORD *)(a1 + 30) = 0x38002A001C000ELL;
  *(_QWORD *)(a1 + 38) = 0x69006200540046LL;
  *(_QWORD *)(a1 + 46) = 0x7B007900770070LL;
  v18 = 15LL * (unsigned int)rc_table_index;
  do
  {
    if ( v18 > 0xD1 )
      goto LABEL_57;
    *(_BYTE *)(a1 + v17) = sde_dsc_rc_range_min_qp[v18];
    v19 = a1 + v17;
    *(_BYTE *)(a1 + v17 + 1) = sde_dsc_rc_range_max_qp[v18];
    v20 = sde_dsc_rc_range_bpg[v18];
    v17 += 3;
    ++v18;
    *(_BYTE *)(v19 + 2) = v20;
  }
  while ( v17 != 103 );
  v21 = 32LL * (unsigned int)rc_table_index;
  v22 = (_DWORD *)((char *)&sde_dsc_rc_init_param_lut + v21);
  *(_BYTE *)(a1 + 20) = *(_DWORD *)((char *)&sde_dsc_rc_init_param_lut + v21);
  if ( (v21 | 4uLL) > 0x1E0 )
    goto LABEL_57;
  *(_BYTE *)(a1 + 19) = v22[1];
  if ( (v21 | 8uLL) > 0x1E0 )
    goto LABEL_57;
  v23 = v22[2];
  *(_WORD *)(a1 + 28) = v23;
  if ( (v21 | 0xCuLL) > 0x1E0
    || (v24 = v22[3], *(_WORD *)(a1 + 22) = v24, (v21 | 0x10uLL) > 0x1E0)
    || (v25 = v22[4], *(_BYTE *)(a1 + 130) = v25, (v21 | 0x14uLL) > 0x1E0)
    || (*(_WORD *)(a1 + 134) = v22[5], (v21 | 0x18uLL) > 0x1E0)
    || (*(_BYTE *)(a1 + 106) = v22[6], (v21 | 0x1CuLL) > 0x1E0) )
  {
LABEL_57:
    __break(1u);
    return get_rc_table_index(rc_table_index);
  }
  v26 = *(unsigned __int8 *)(a1 + 128);
  v27 = *(unsigned __int16 *)(a1 + 4);
  *(_BYTE *)(a1 + 107) = v22[7];
  if ( (v26 & 1) != 0 || *(_BYTE *)(a1 + 129) == 1 )
  {
    v27 >>= 1;
    v16 *= 2;
  }
  v28 = *(unsigned __int8 *)(a1 + 126);
  *(_BYTE *)a1 = v12 + 1;
  if ( v12 <= 0xA )
    v29 = 48;
  else
    v29 = 64;
  v30 = (unsigned __int16)v24;
  *(_BYTE *)(a1 + 121) = v29;
  if ( v28 == 2 && *(_BYTE *)(a1 + 129) == 1 )
    *(_WORD *)(a1 + 132) = (unsigned __int16)(((unsigned __int8)v25 + *(unsigned __int16 *)(a1 + 6) - 1 - 1)
                                            / (*(unsigned __int16 *)(a1 + 6) - 1)) << 11;
  v31 = v16 * (unsigned __int16)v24;
  v32 = *(unsigned __int8 *)(a1 + 27);
  v33 = *(unsigned __int16 *)(a1 + 6);
  v34 = 1431655766LL * (v27 + 2);
  v35 = *(unsigned __int16 *)(a1 + 104);
  v36 = v16 * v27;
  v37 = v35 - (unsigned __int16)v23;
  v38 = 8 * v35;
  if ( (v36 & 7) != 0 )
    v39 = (v36 >> 3) + 1;
  else
    v39 = v36 >> 3;
  *(_WORD *)(a1 + 122) = v39;
  *(_WORD *)(a1 + 24) = (v16 + v35 - (unsigned __int16)v23 + v16 * v30 + HIDWORD(v34) * v32 - 1) / v16 - v30;
  v40 = (v33 - 1 + (v32 << 11) - 1) / (v33 - 1);
  *(_BYTE *)(a1 + 108) = v38 / v37;
  *(_WORD *)(a1 + 114) = v40;
  if ( v26 )
  {
    v41 = (12 * v12 + 4 * (v29 + v12)) | 2;
  }
  else if ( *(_BYTE *)(a1 + 129) == 1 )
  {
    v41 = 3 * v29 + 12 * v12 + 2;
  }
  else
  {
    v41 = 3 * (v29 + 4 * v12) + 6;
  }
  result = 0;
  v42 = (8 * v39 * v33 - v41) % v29 - v29 + v41;
  v43 = (HIDWORD(v34) * v33 + ((v42 + v37) << 11) - 1) / (HIDWORD(v34) * v33);
  v44 = v42 + v35 - v31;
  *(_WORD *)(a1 + 118) = v44;
  *(_WORD *)(a1 + 116) = v43;
  *(_WORD *)(a1 + 112) = ((unsigned __int16)v44 << 11)
                       / ((v38 / (v35 - v44) - 9)
                        * ((unsigned __int16)v43 + (unsigned __int16)v40));
  *(_WORD *)(a1 + 110) = SWORD2(v34) / ((unsigned __int8)(v38 / v37) - 8);
  return result;
}
