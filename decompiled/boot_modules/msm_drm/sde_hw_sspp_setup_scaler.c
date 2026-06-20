__int64 __fastcall sde_hw_sspp_setup_scaler(__int64 result, __int64 a2, unsigned int *a3)
{
  unsigned int v3; // w8
  unsigned int v4; // w9
  unsigned int v5; // w11
  unsigned int v6; // w13
  unsigned int v7; // w10
  bool v8; // cf
  unsigned int v9; // w8
  __int64 v11; // x19
  unsigned int v12; // w9
  int v13; // w8
  unsigned int v14; // w10
  int v15; // w8
  unsigned int v16; // w9
  unsigned int v17; // w12
  int v18; // w8
  unsigned int v19; // w10
  unsigned int v20; // w9
  int v21; // w20
  int v22; // w10
  int v23; // w9
  int v24; // w9

  if ( result && a3 )
  {
    v3 = a3[73];
    v4 = a3[74];
    v5 = a3[76];
    v6 = a3[80];
    v7 = v3 << 8;
    v8 = v3 >= 4;
    v9 = v4 << 12;
    v11 = result;
    if ( v8 )
      v7 = 0;
    v8 = v4 >= 4;
    v12 = v5 << 16;
    if ( v8 )
      v9 = 0;
    v13 = v9 | v7;
    if ( v5 >= 4 )
      v12 = 0;
    v14 = a3[77];
    v15 = v13 | v12;
    v16 = a3[78];
    v17 = v14 << 10;
    if ( v15 )
      v18 = v15 + 1;
    else
      v18 = 0;
    v8 = v14 >= 4;
    v19 = v16 << 14;
    if ( v8 )
      v17 = 0;
    v8 = v16 >= 4;
    v20 = v6 << 18;
    if ( v8 )
      v19 = 0;
    v21 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 100LL);
    v22 = v19 | v17;
    if ( v6 >= 4 )
      v20 = 0;
    v23 = v22 | v20;
    if ( v23 )
      v24 = v23 | 2;
    else
      v24 = 0;
    sde_reg_write(result, v21 + 4, v24 | v18, "SCALE_CONFIG + idx");
    sde_reg_write(v11, v21 + 32, a3[1], "COMP0_3_INIT_PHASE_X + idx");
    sde_reg_write(v11, v21 + 36, a3[9], "COMP0_3_INIT_PHASE_Y + idx");
    sde_reg_write(v11, v21 + 16, a3[5], "COMP0_3_PHASE_STEP_X + idx");
    sde_reg_write(v11, v21 + 20, a3[13], "COMP0_3_PHASE_STEP_Y + idx");
    sde_reg_write(v11, v21 + 40, a3[2], "COMP1_2_INIT_PHASE_X + idx");
    sde_reg_write(v11, v21 + 44, a3[10], "COMP1_2_INIT_PHASE_Y + idx");
    sde_reg_write(v11, v21 + 24, a3[6], "COMP1_2_PHASE_STEP_X + idx");
    return sde_reg_write(v11, v21 + 28, a3[14], "COMP1_2_PHASE_STEP_Y + idx");
  }
  return result;
}
