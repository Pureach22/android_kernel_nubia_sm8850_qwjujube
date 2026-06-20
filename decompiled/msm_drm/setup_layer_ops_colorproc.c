_QWORD *__fastcall setup_layer_ops_colorproc(_QWORD *result, unsigned __int64 a2, char a3)
{
  _QWORD *v3; // x19
  int v4; // w8
  void *v5; // x8
  __int64 v6; // x9
  int v7; // w8
  __int64 v8; // x9
  void *v9; // x8
  int v10; // w8
  __int64 v11; // x9
  void *v12; // x8
  int v13; // w8
  __int64 v14; // x9
  void *v15; // x8
  int v16; // w8
  __int64 v17; // x9
  void *v18; // x8
  unsigned __int64 v19; // [xsp+18h] [xbp+18h]

  v3 = result;
  v19 = a2;
  if ( (a3 & 1) != 0 )
  {
    v19 = a2 & 0xFFFFFFFFFFFF9FFFLL;
    *(_QWORD *)(result[7] + 32LL) = a2 & 0xFFFFFFFFFFFF9FFFLL;
  }
  if ( (v19 & 0x40) != 0 && *(_DWORD *)(*(_QWORD *)(result[7] + 48LL) + 192LL) == 65543 )
  {
    result[41] = sde_setup_pipe_pa_hue_v1_7;
    result[44] = sde_setup_pipe_pa_sat_v1_7;
    result[47] = sde_setup_pipe_pa_val_v1_7;
    result[50] = sde_setup_pipe_pa_cont_v1_7;
  }
  if ( (v19 & 0x80) != 0 && *(_DWORD *)(*(_QWORD *)(result[7] + 48LL) + 228LL) == 65543 )
    result[53] = sde_setup_pipe_pa_memcol_v1_7;
  if ( (v19 & 0x4000) != 0 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(result[7] + 48LL) + 300LL) == 327680 )
    {
      result = (_QWORD *)reg_dmav1_init_sspp_op_v4(14, (__int64)result);
      if ( !(_DWORD)result )
        v3[56] = reg_dmav1_setup_vig_gamutv5;
    }
    v4 = *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 300LL);
    if ( v4 == 393217 )
    {
      result = (_QWORD *)reg_dmav1_init_sspp_op_v4(14, (__int64)v3);
      if ( (_DWORD)result )
        goto LABEL_20;
      v5 = reg_dmav2_setup_vig_gamutv61;
      v6 = 57;
      v3[56] = reg_dmav2_setup_vig_gamutv61;
      goto LABEL_19;
    }
    if ( v4 == 393216 )
    {
      result = (_QWORD *)reg_dmav1_init_sspp_op_v4(14, (__int64)v3);
      if ( !(_DWORD)result )
      {
        v5 = reg_dmav1_setup_vig_gamutv6;
        v6 = 56;
LABEL_19:
        v3[v6] = v5;
      }
    }
  }
LABEL_20:
  if ( (v19 & 0x2000) != 0 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 340LL) == 327680 )
    {
      result = (_QWORD *)reg_dmav1_init_sspp_op_v4(13, (__int64)v3);
      if ( !(_DWORD)result )
        v3[59] = reg_dmav1_setup_vig_igcv5;
    }
    if ( *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 340LL) == 393216 )
    {
      result = (_QWORD *)reg_dmav1_init_sspp_op_v4(13, (__int64)v3);
      if ( !(_DWORD)result )
        v3[59] = &reg_dmav1_setup_vig_igcv6;
    }
  }
  if ( (v19 & 0x8000) != 0 && *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 340LL) == 327680 )
  {
    result = (_QWORD *)reg_dmav1_init_sspp_op_v4(15, (__int64)v3);
    if ( !(_DWORD)result )
      v3[62] = reg_dmav1_setup_dma_igcv5;
  }
  if ( (v19 & 0x10000) != 0 && *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 416LL) == 327680 )
  {
    result = (_QWORD *)reg_dmav1_init_sspp_op_v4(16, (__int64)v3);
    if ( !(_DWORD)result )
      v3[65] = reg_dmav1_setup_dma_gcv5;
  }
  if ( (v19 & 0x10000000) != 0 && *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 568LL) == 0x10000 )
    v3[140] = sde_setup_fp16_igcv1;
  if ( (v19 & 0x20000000) != 0 && *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 644LL) == 0x10000 )
    v3[137] = sde_setup_fp16_gcv1;
  if ( (v19 & 0x40000000) != 0 && *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 720LL) == 0x10000 )
    v3[134] = &sde_setup_fp16_cscv1;
  if ( (v19 & 0x80000000) != 0 && *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 796LL) == 0x10000 )
    v3[143] = sde_setup_fp16_unmultv1;
  if ( (v19 & 0x800000000LL) != 0 )
  {
    v7 = *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 872LL);
    if ( v7 == 0x10000 )
    {
      v9 = sde_setup_ucsc_igcv1;
      v8 = 155;
    }
    else
    {
      if ( v7 != 65537 )
        goto LABEL_53;
      v8 = 156;
      v3[155] = sde_setup_ucsc_igcv1_1;
      v9 = hfi_setup_ucsc_igcv1;
    }
    v3[v8] = v9;
  }
LABEL_53:
  if ( (v19 & 0x1000000000LL) == 0 )
    goto LABEL_59;
  v10 = *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 948LL);
  if ( v10 == 0x10000 )
  {
    v12 = sde_setup_ucsc_gcv1;
    v11 = 152;
  }
  else
  {
    if ( v10 != 65537 )
      goto LABEL_59;
    v11 = 153;
    v3[152] = sde_setup_ucsc_gcv1_1;
    v12 = hfi_setup_ucsc_gcv1;
  }
  v3[v11] = v12;
LABEL_59:
  if ( (v19 & 0x2000000000LL) == 0 )
    goto LABEL_65;
  v13 = *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 1024LL);
  if ( v13 == 0x10000 )
  {
    v15 = sde_setup_ucsc_cscv1;
    v14 = 149;
  }
  else
  {
    if ( v13 != 65537 )
      goto LABEL_65;
    v14 = 150;
    v3[149] = sde_setup_ucsc_cscv1_1;
    v15 = hfi_setup_ucsc_cscv1;
  }
  v3[v14] = v15;
LABEL_65:
  if ( (v19 & 0x4000000000LL) == 0 )
    goto LABEL_71;
  v16 = *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 1100LL);
  if ( v16 == 0x10000 )
  {
    v18 = sde_setup_ucsc_unmultv1;
    v17 = 158;
  }
  else
  {
    if ( v16 != 65537 )
      goto LABEL_71;
    v17 = 159;
    v3[158] = sde_setup_ucsc_unmultv1_1;
    v18 = hfi_setup_ucsc_unmultv1;
  }
  v3[v17] = v18;
LABEL_71:
  if ( (v19 & 0x8000000000LL) != 0 && *(_DWORD *)(*(_QWORD *)(v3[7] + 48LL) + 1176LL) == 0x10000 )
  {
    v3[161] = sde_setup_ucsc_alpha_ditherv1;
    v3[162] = hfi_setup_ucsc_alpha_ditherv1;
  }
  return result;
}
