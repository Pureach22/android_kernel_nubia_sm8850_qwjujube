__int64 __fastcall sde_encoder_phys_wb_mode_set(_QWORD *a1, __int64 a2, __int64 *a3, _BYTE *a4)
{
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x10
  int v9; // w21
  __int64 v10; // x22
  int v11; // w23
  __int64 v12; // x8
  __int64 v13; // x10
  __int64 v14; // x9
  __int64 v15; // x11
  __int64 v16; // x10
  __int64 v17; // x9
  __int64 v18; // x11
  __int64 v19; // x8
  __int64 v20; // x10
  __int64 v21; // x11
  int v22; // w4
  __int64 v23; // x8
  int v24; // w5
  __int64 v25; // x8
  int v26; // w24
  int v27; // w27
  int v28; // w28
  int v29; // w7
  __int64 v30; // x9
  __int64 v31; // x8
  unsigned __int64 v32; // x8
  int v33; // w20
  int v34; // w21
  __int64 result; // x0
  __int64 v36; // x8
  char v37; // [xsp+0h] [xbp-30h]
  _QWORD v38[4]; // [xsp+10h] [xbp-20h] BYREF

  v38[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a3;
  v7 = a3[1];
  v8 = a3[2];
  v9 = *((_DWORD *)a1 + 166);
  v10 = a1[64];
  v38[1] = 0;
  v38[2] = 0;
  a1[67] = v8;
  a1[65] = v6;
  a1[66] = v7;
  v11 = v9 == 3;
  v12 = a3[3];
  v13 = a3[4];
  v38[0] = 0;
  v15 = a3[5];
  v14 = a3[6];
  a1[68] = v12;
  a1[71] = v14;
  a1[70] = v15;
  a1[69] = v13;
  v16 = a3[8];
  v18 = a3[9];
  v17 = a3[10];
  a1[72] = a3[7];
  a1[75] = v17;
  a1[74] = v18;
  a1[73] = v16;
  v19 = a3[12];
  v20 = a3[13];
  v21 = a3[14];
  a1[76] = a3[11];
  LOBYTE(v17) = _drm_debug;
  a1[79] = v21;
  a1[78] = v20;
  a1[77] = v19;
  if ( (v17 & 4) != 0 )
  {
    if ( *a1 )
    {
      v22 = *(_DWORD *)(*a1 + 24LL);
      if ( !a1 )
        goto LABEL_8;
    }
    else
    {
      v22 = -1;
      if ( !a1 )
        goto LABEL_8;
    }
    v23 = a1[358];
    if ( v23 )
    {
      v24 = *(_DWORD *)(v23 + 12) - 1;
LABEL_9:
      _drm_dev_dbg(
        0,
        0,
        0,
        "[enc:%d wb:%d] mode_set_cache:\"%s\",%d,%d\n",
        v22,
        v24,
        (const char *)(a2 + 80),
        *(unsigned __int16 *)(a2 + 4),
        *(unsigned __int16 *)(a2 + 14));
      goto LABEL_10;
    }
LABEL_8:
    v24 = -1;
    goto LABEL_9;
  }
LABEL_10:
  v25 = *a1;
  a1[52] = 0;
  a1[54] = 0;
  a1[63] = 0;
  sde_rm_init_hw_iter((__int64)v38, *(_DWORD *)(v25 + 24), 5);
  if ( v9 == 3 )
    v26 = 2;
  else
    v26 = 1;
  v27 = v9 == 3;
  v28 = v26;
  do
  {
    sde_rm_get_hw(v10 + 2144, (__int64)v38);
    if ( !v27 )
    {
      v30 = a1[52];
      v31 = v38[0];
      if ( v30 && v30 != v38[0] )
      {
        *a4 = 1;
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_phys_wb_mode_set",
          2243,
          -1,
          *(_DWORD *)(a1[52] + 64LL),
          *(_DWORD *)(v31 + 64),
          -1059143953,
          v29,
          v37);
        v31 = v38[0];
      }
      a1[52] = v31;
    }
    --v28;
    --v27;
  }
  while ( v28 );
  v32 = a1[52];
  if ( v32 && v32 < 0xFFFFFFFFFFFFF001LL )
  {
    sde_rm_init_hw_iter((__int64)v38, *(_DWORD *)(*a1 + 24LL), 6);
    v33 = v9 == 3;
    v34 = v26;
    do
    {
      sde_rm_get_hw(v10 + 2144, (__int64)v38);
      if ( !v33 )
        a1[54] = v38[0];
      --v34;
      --v33;
    }
    while ( v34 );
    if ( a1[54] >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_27B32A, "sde_encoder_phys_wb_mode_set");
      a1[54] = 0;
    }
    sde_rm_init_hw_iter((__int64)v38, *(_DWORD *)(*a1 + 24LL), 14);
    do
    {
      sde_rm_get_hw(v10 + 2144, (__int64)v38);
      if ( !v11 )
        a1[63] = v38[0];
      --v26;
      --v11;
    }
    while ( v26 );
    if ( a1[63] >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_22F72A, "sde_encoder_phys_wb_mode_set");
      a1[63] = 0;
    }
    result = sde_encoder_helper_get_kickoff_timeout_ms((__int64 *)*a1);
    v36 = a1[52];
    *((_DWORD *)a1 + 248) = result;
    *((_DWORD *)a1 + 338) = *(_DWORD *)(v36 + 64);
  }
  else
  {
    result = printk(&unk_24A5BE, "sde_encoder_phys_wb_mode_set");
    a1[52] = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
