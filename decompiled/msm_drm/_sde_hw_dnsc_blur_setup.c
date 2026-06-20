__int64 __fastcall sde_hw_dnsc_blur_setup(__int64 a1, __int64 *a2, unsigned int a3)
{
  __int64 v3; // x19
  __int64 v4; // x9
  const char *v6; // x3
  unsigned int v7; // w1
  unsigned int v8; // w2
  unsigned int v9; // w8
  int v10; // w10
  unsigned int v11; // w12
  int v13; // w9
  int v14; // w9
  unsigned int v15; // w22
  int v16; // w8
  int v17; // w24
  __int64 i; // x25
  int v19; // w8
  __int64 v20; // x23
  int v21; // w24

  v3 = a1;
  if ( !a2 || (v4 = *a2, (*a2 & 1) == 0) )
  {
    v6 = "DNSC_BLUR_OP_MODE";
    v7 = 0;
    v8 = 0;
    return sde_reg_write(a1, v7, v8, v6);
  }
  v10 = *((_DWORD *)a2 + 7);
  v9 = *((_DWORD *)a2 + 8);
  v11 = (unsigned int)v4 >> 1;
  v13 = ((_DWORD)v4 << 15) & 0x10000;
  if ( v10 )
    v14 = (v10 << 7) & 0x100 | ((v11 & 1) << 16) | 3;
  else
    v14 = v13 + 1;
  if ( v9 )
    v15 = v14 & 0xFFFFEFFF | (((v9 >> 1) & 1) << 12) | 4;
  else
    v15 = v14;
  if ( (v10 & 2) != 0 )
  {
    sde_reg_write(a1, 0xCu, *((_DWORD *)a2 + 9), "DNSC_BLUR_PCMN_PHASE_INIT_H");
    sde_reg_write(v3, 0x10u, *((_DWORD *)a2 + 10), "DNSC_BLUR_PCMN_PHASE_STEP_H");
    if ( (a2[4] & 2) == 0 )
    {
LABEL_12:
      if ( (*((_BYTE *)a2 + 28) & 1) == 0 )
        goto LABEL_13;
LABEL_29:
      sde_reg_write(v3, 4u, *((_DWORD *)a2 + 14) | (*((_DWORD *)a2 + 13) << 16), "DNSC_BLUR_BLUR_RATIO_H");
      v16 = *((_DWORD *)a2 + 8);
      if ( (v16 & 1) == 0 )
        goto LABEL_15;
      goto LABEL_14;
    }
  }
  else if ( (v9 & 2) == 0 )
  {
    goto LABEL_12;
  }
  sde_reg_write(v3, 0x14u, *((_DWORD *)a2 + 11), "DNSC_BLUR_PCMN_PHASE_INIT_V");
  sde_reg_write(v3, 0x18u, *((_DWORD *)a2 + 12), "DNSC_BLUR_PCMN_PHASE_STEP_V");
  if ( (*((_BYTE *)a2 + 28) & 1) != 0 )
    goto LABEL_29;
LABEL_13:
  v16 = *((_DWORD *)a2 + 8);
  if ( (v16 & 1) != 0 )
  {
LABEL_14:
    sde_reg_write(v3, 8u, *((_DWORD *)a2 + 16) | (*((_DWORD *)a2 + 15) << 16), "DNSC_BLUR_BLUR_RATIO_V");
    v16 = *((_DWORD *)a2 + 8);
  }
LABEL_15:
  if ( ((*((_DWORD *)a2 + 7) | v16) & 1) != 0 )
  {
    v17 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 32) + 48LL) + 20LL);
    sde_reg_write(v3, 0x20u, a3, "DNSC_BLUR_GAUS_COEF_LUT_SEL");
    if ( (*((_BYTE *)a2 + 28) & 1) != 0 )
    {
      for ( i = 0; i != 256; i += 4 )
        sde_reg_write(v3, v17 + ((a3 != 0) << 9) + i, *(_DWORD *)((char *)a2 + i + 68), "lut_off + (i * 0x4) + base");
    }
    if ( (a2[4] & 1) != 0 )
    {
      if ( a3 )
        v19 = 768;
      else
        v19 = 256;
      v20 = 0;
      v21 = v19 + v17;
      do
      {
        sde_reg_write(v3, v21 + v20, *(_DWORD *)((char *)a2 + v20 + 324), "lut_off + (i * 0x4) + base");
        v20 += 4;
      }
      while ( v20 != 256 );
    }
  }
  sde_reg_write(v3, 0, v15, "DNSC_BLUR_OP_MODE");
  sde_reg_write(v3, 0x1Cu, *((_DWORD *)a2 + 5) | (*((_DWORD *)a2 + 6) << 16), "DNSC_BLUR_OUT_IMG_SIZE");
  v6 = "DNSC_BLUR_SRC_IMG_SIZE";
  a1 = v3;
  v7 = 40;
  v8 = *((_DWORD *)a2 + 3) | (*((_DWORD *)a2 + 4) << 16);
  return sde_reg_write(a1, v7, v8, v6);
}
