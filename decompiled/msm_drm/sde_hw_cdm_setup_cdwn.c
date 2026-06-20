__int64 __fastcall sde_hw_cdm_setup_cdwn(__int64 a1, _DWORD *a2, int a3)
{
  __int64 result; // x0
  int v4; // w8
  int v6; // w20
  _DWORD *v7; // x21
  const char *v8; // x3
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  int v12; // w9
  _DWORD *v13; // x21
  unsigned int v14; // w20
  const char *v15; // x3
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x2
  unsigned int v19; // w20

  if ( a3 == 1 )
    return 0;
  v4 = a2[3];
  if ( a2[2] == 1 )
    v6 = 2;
  else
    v6 = 130;
  if ( v4 <= 1 )
  {
    if ( !v4 )
    {
      v6 &= 0x80u;
      goto LABEL_18;
    }
    if ( v4 == 1 )
      goto LABEL_18;
    goto LABEL_13;
  }
  if ( v4 == 2 )
  {
    v6 |= 8u;
    goto LABEL_18;
  }
  if ( v4 == 3 )
  {
    v7 = a2;
    v6 |= 0x10u;
    sde_reg_write(a1, 272, 22, "CDM_CDWN2_COEFF_COSITE_H_0");
    sde_reg_write(a1, 276, 460, "CDM_CDWN2_COEFF_COSITE_H_1");
    v8 = "CDM_CDWN2_COEFF_COSITE_H_2";
    v9 = a1;
    v10 = 280;
    v11 = 16777374;
    goto LABEL_17;
  }
  if ( v4 != 4 )
  {
LABEL_13:
    printk(&unk_262F80, "sde_hw_cdm_setup_cdwn");
    return 4294967274LL;
  }
  v7 = a2;
  v6 |= 0x18u;
  sde_reg_write(a1, 284, 720901, "CDM_CDWN2_COEFF_OFFSITE_H_0");
  sde_reg_write(a1, 288, 31130091, "CDM_CDWN2_COEFF_OFFSITE_H_1");
  v8 = "CDM_CDWN2_COEFF_OFFSITE_H_2";
  v9 = a1;
  v10 = 292;
  v11 = 14942278;
LABEL_17:
  sde_reg_write(v9, v10, v11, v8);
  a2 = v7;
LABEL_18:
  v12 = a2[4];
  result = 4294967274LL;
  if ( v12 <= 1 )
  {
    if ( !v12 )
    {
      v14 = v6 & 0x9B;
      if ( a2[3] )
      {
LABEL_30:
        v19 = v14 | 1;
        goto LABEL_33;
      }
LABEL_32:
      v19 = v14 & 0x7FFFFFFE;
      goto LABEL_33;
    }
    if ( v12 != 1 )
      return result;
    v19 = v6 & 0xFFFFFF9A | 5;
  }
  else
  {
    if ( v12 != 2 )
    {
      if ( v12 == 3 )
      {
        v13 = a2;
        v14 = v6 & 0xFFFFFF9B | 0x44;
        v15 = "CDM_CDWN2_COEFF_COSITE_V";
        v16 = a1;
        v17 = 296;
        v18 = 524292;
      }
      else
      {
        if ( v12 != 4 )
          return result;
        v13 = a2;
        v14 = v6 | 0x64;
        v15 = "CDM_CDWN2_COEFF_OFFSITE_V";
        v16 = a1;
        v17 = 300;
        v18 = 393218;
      }
      sde_reg_write(v16, v17, v18, v15);
      a2 = v13;
      if ( v13[4] || v13[3] )
        goto LABEL_30;
      goto LABEL_32;
    }
    v19 = v6 & 0xFFFFFF9A | 0x25;
  }
LABEL_33:
  sde_reg_write(a1, 304, (unsigned int)*(unsigned __int16 *)a2 | (a2[1] << 16), "CDM_CDWN2_OUT_SIZE");
  sde_reg_write(a1, 256, v19, "CDM_CDWN2_OP_MODE");
  sde_reg_write(a1, 260, 67043328, "CDM_CDWN2_CLAMP_OUT");
  return 0;
}
