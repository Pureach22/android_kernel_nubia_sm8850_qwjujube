__int64 __fastcall sde_hw_dsc_config_0(__int64 result, __int64 a2, unsigned int a3, char a4)
{
  __int64 v7; // x19
  unsigned int v8; // w24
  unsigned int v9; // w22
  __int64 v10; // x8
  int v11; // w11
  int v12; // w9
  bool v13; // zf
  int v14; // w10
  int v15; // w11
  unsigned int v16; // w2
  int v17; // w9
  int v18; // w8
  int v19; // w9
  int v20; // w22
  int v21; // w8
  int v22; // w2
  int v23; // w0
  const char *v24; // x3
  unsigned int v25; // w1
  int v26; // w8
  __int64 v27; // x0
  unsigned int v28; // w2
  int v29; // w9
  int v30; // w10
  int v31; // w20
  unsigned int v32; // w2

  if ( !result || !a2 )
    return result;
  v7 = result;
  v8 = a3 >> 2;
  v9 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 40) + 56LL) + 20LL);
  sde_reg_write(result, 0, a3 & 3 | ((*(_DWORD *)(a2 + 172) & 3) << 7), "DSC_CMN_MAIN_CNF");
  v10 = *(_QWORD *)(v7 + 40);
  v11 = *(_DWORD *)(a2 + 172);
  v12 = *(unsigned __int8 *)(a2 + 140) | ((v8 & 1) << 9);
  if ( (a4 & 1) != 0 )
    v12 |= 0xC00u;
  if ( (*(_QWORD *)(v10 + 32) & 0x10) == 0 )
  {
    if ( v11 != 2 )
    {
      if ( v11 == 1 )
      {
        v13 = (*(_QWORD *)(v10 + 32) & 0x20LL) == 0;
        v14 = 314310656;
        v15 = 628883456;
        goto LABEL_14;
      }
LABEL_12:
      v14 = 0;
      goto LABEL_16;
    }
    goto LABEL_11;
  }
  if ( v11 != 2 )
  {
    if ( v11 != 1 )
      goto LABEL_12;
LABEL_11:
    v13 = (*(_QWORD *)(v10 + 32) & 0x20LL) == 0;
    v14 = 157024256;
    v15 = 314310656;
    goto LABEL_14;
  }
  v13 = (*(_QWORD *)(v10 + 32) & 0x20LL) == 0;
  v14 = 78381056;
  v15 = 157024256;
LABEL_14:
  if ( v13 )
    v14 = v15;
LABEL_16:
  v16 = v14 | v12;
  if ( (*(_QWORD *)(v10 + 32) & 0x200) != 0 && *(unsigned __int8 *)(a2 + 1) > 8u )
    v16 |= 0x1000u;
  sde_reg_write(v7, v9, v16, "ENC_DF_CTRL + idx");
  v17 = *(unsigned __int8 *)(a2 + 126);
  v18 = v17 << 28;
  if ( v17 == 2 )
  {
    if ( (*(_BYTE *)(a2 + 128) & 1) != 0 )
      v18 = 541065216;
    v19 = *(unsigned __int16 *)(a2 + 16);
    if ( *(_BYTE *)(a2 + 129) )
      v18 |= 0x200000u;
    if ( (*(_BYTE *)(a2 + 128) & 1) != 0 )
      goto LABEL_28;
  }
  else
  {
    v19 = *(unsigned __int16 *)(a2 + 16);
    if ( (*(_BYTE *)(a2 + 128) & 1) != 0 )
    {
LABEL_28:
      v19 *= 2;
      goto LABEL_29;
    }
  }
  if ( *(_BYTE *)(a2 + 129) == 1 )
    goto LABEL_28;
LABEL_29:
  sde_reg_write(
    v7,
    v9 + 48,
    v18
  | (v19 << 10)
  | (*(unsigned __int8 *)(a2 + 26) << 20)
  | ((*(_BYTE *)a2 & 0xF) << 6)
  | (16 * *(unsigned __int8 *)(a2 + 2))
  | *(_BYTE *)(a2 + 1) & 0xF,
    "DSC_MAIN_CONF + idx");
  sde_reg_write(v7, v9 + 52, *(_DWORD *)(a2 + 10), "DSC_PICTURE_SIZE + idx");
  sde_reg_write(v7, v9 + 56, *(_DWORD *)(a2 + 4), "DSC_SLICE_SIZE + idx");
  sde_reg_write(v7, v9 + 60, *(unsigned __int16 *)(a2 + 122), "DSC_MISC_SIZE + idx");
  sde_reg_write(v7, v9 + 64, *(_DWORD *)(a2 + 22), "DSC_HRD_DELAYS + idx");
  sde_reg_write(v7, v9 + 68, *(_BYTE *)(a2 + 108) & 0x3F, "DSC_RC_SCALE + idx");
  sde_reg_write(
    v7,
    v9 + 72,
    *(unsigned __int16 *)(a2 + 112) | ((*(_WORD *)(a2 + 110) & 0x7FF) << 16),
    "DSC_RC_SCALE_INC_DEC + idx");
  sde_reg_write(
    v7,
    v9 + 76,
    *(_BYTE *)(a2 + 27) & 0x1F | (32 * (*(_BYTE *)(a2 + 130) & 0x1F)),
    "DSC_RC_OFFSETS_1 + idx");
  sde_reg_write(v7, v9 + 80, *(_DWORD *)(a2 + 114), "DSC_RC_OFFSETS_2 + idx");
  sde_reg_write(
    v7,
    v9 + 84,
    *(unsigned __int16 *)(a2 + 28) | (*(unsigned __int16 *)(a2 + 118) << 16),
    "DSC_RC_OFFSETS_3 + idx");
  sde_reg_write(v7, v9 + 88, *(_DWORD *)(a2 + 132), "DSC_RC_OFFSETS_4 + idx");
  sde_reg_write(
    v7,
    v9 + 92,
    *(_BYTE *)(a2 + 106) & 0x1F
  | (32 * (*(_BYTE *)(a2 + 107) & 0x1F)) & 0x3FF
  | ((unsigned __int8)*(_DWORD *)(a2 + 184) << 10),
    "DSC_FLATNESS_QP + idx");
  sde_reg_write(v7, v9 + 96, *(unsigned __int16 *)(a2 + 104), "DSC_RC_MODEL_SIZE + idx");
  sde_reg_write(
    v7,
    v9 + 100,
    *(_BYTE *)(a2 + 18) & 0xF
  | ((*(_BYTE *)(a2 + 20) & 0x1F) << 8) & 0x1FFF
  | ((*(_BYTE *)(a2 + 19) & 0x1F) << 13) & 0xF00FFFFF
  | ((*(_BYTE *)(a2 + 14) & 0xF) << 20) & 0xF0FFFFFF
  | ((*(_BYTE *)(a2 + 15) & 0xF) << 24),
    "DSC_RC_CONFIG + idx");
  v20 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 40) + 56LL) + 48LL);
  if ( (*(_BYTE *)(a2 + 128) & 1) != 0 )
  {
    v21 = 257;
  }
  else if ( *(_BYTE *)(a2 + 129) )
  {
    v21 = 513;
  }
  else
  {
    v21 = 1;
  }
  if ( !*(_BYTE *)(a2 + 2) )
    v21 |= 0x400u;
  if ( *(_BYTE *)(a2 + 1) == 8 )
    v22 = v21 | 0x800;
  else
    v22 = v21;
  result = sde_reg_write(v7, v20 + 4, v22 & 0xFFFFCFFF | ((a3 & 3) << 12), "DSC_CFG + idx");
  __dsb(0xEu);
  if ( (*(_QWORD *)(*(_QWORD *)(v7 + 40) + 32LL) & 0x100) != 0 )
  {
    if ( *(_BYTE *)(a2 + 196) )
    {
      v30 = *(_DWORD *)(a2 + 200);
      v29 = *(_DWORD *)(a2 + 204);
      v31 = 1;
      v32 = (a3 >> 2) & 1 | (v29 << 12) | (v30 << 8);
    }
    else
    {
      v32 = 0;
      v31 = 0;
    }
    sde_reg_write(v7, v20 + 20, v32, "DSC_4HS_MERGE_CFG + idx");
    v24 = "DSC_4HS_MERGE_EN + idx";
    v25 = v20 + 16;
    v27 = v7;
    v28 = v31;
  }
  else
  {
    if ( !*(_BYTE *)(a2 + 196) )
      return result;
    v23 = sde_reg_read(v7, v20 + 4);
    v24 = "DSC_CFG + idx";
    v25 = v20 + 4;
    v26 = (a3 << 15) & 0x20000 | v23;
    v27 = v7;
    v28 = v26 | (*(_DWORD *)(a2 + 200) << 18) | (*(_DWORD *)(a2 + 204) << 22) | 0x10000;
  }
  return sde_reg_write(v27, v25, v28, v24);
}
