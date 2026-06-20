__int64 __fastcall a6xx_probe_common(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  _UNKNOWN **v4; // x21
  _DWORD *v7; // x8
  __int64 v8; // x22
  char v9; // w0
  __int64 v10; // x8
  int v12; // w9
  __int64 v13; // x8
  __int64 result; // x0

  v4 = *(_UNKNOWN ***)(a4 + 40);
  *(_QWORD *)(a2 + 14264) = a4;
  *(_DWORD *)(a2 + 14248) = a3;
  v7 = *v4;
  if ( *(_DWORD *)*v4 )
  {
    if ( v7[1] )
      goto LABEL_3;
  }
  else
  {
    *v7 = -1;
    if ( v7[1] )
    {
LABEL_3:
      if ( v7[2] )
        goto LABEL_4;
      goto LABEL_43;
    }
  }
  v7[1] = -1;
  if ( v7[2] )
  {
LABEL_4:
    if ( v7[3] )
      goto LABEL_5;
    goto LABEL_44;
  }
LABEL_43:
  v7[2] = -1;
  if ( v7[3] )
  {
LABEL_5:
    if ( v7[4] )
      goto LABEL_6;
    goto LABEL_45;
  }
LABEL_44:
  v7[3] = -1;
  if ( v7[4] )
  {
LABEL_6:
    if ( v7[5] )
      goto LABEL_7;
    goto LABEL_46;
  }
LABEL_45:
  v7[4] = -1;
  if ( v7[5] )
  {
LABEL_7:
    if ( v7[6] )
      goto LABEL_8;
    goto LABEL_47;
  }
LABEL_46:
  v7[5] = -1;
  if ( v7[6] )
  {
LABEL_8:
    if ( v7[7] )
      goto LABEL_9;
    goto LABEL_48;
  }
LABEL_47:
  v7[6] = -1;
  if ( v7[7] )
  {
LABEL_9:
    if ( v7[8] )
      goto LABEL_10;
    goto LABEL_49;
  }
LABEL_48:
  v7[7] = -1;
  if ( v7[8] )
  {
LABEL_10:
    if ( v7[9] )
      goto LABEL_11;
    goto LABEL_50;
  }
LABEL_49:
  v7[8] = -1;
  if ( v7[9] )
  {
LABEL_11:
    if ( v7[10] )
      goto LABEL_12;
    goto LABEL_51;
  }
LABEL_50:
  v7[9] = -1;
  if ( v7[10] )
  {
LABEL_12:
    if ( v7[11] )
      goto LABEL_13;
    goto LABEL_52;
  }
LABEL_51:
  v7[10] = -1;
  if ( v7[11] )
  {
LABEL_13:
    if ( v7[12] )
      goto LABEL_14;
    goto LABEL_53;
  }
LABEL_52:
  v7[11] = -1;
  if ( v7[12] )
  {
LABEL_14:
    if ( v7[13] )
      goto LABEL_15;
    goto LABEL_54;
  }
LABEL_53:
  v7[12] = -1;
  if ( v7[13] )
  {
LABEL_15:
    if ( v7[14] )
      goto LABEL_16;
    goto LABEL_55;
  }
LABEL_54:
  v7[13] = -1;
  if ( v7[14] )
  {
LABEL_16:
    if ( v7[15] )
      goto LABEL_17;
LABEL_56:
    v7[15] = -1;
    if ( v7[16] )
      goto LABEL_18;
    goto LABEL_57;
  }
LABEL_55:
  v7[14] = -1;
  if ( !v7[15] )
    goto LABEL_56;
LABEL_17:
  if ( v7[16] )
    goto LABEL_18;
LABEL_57:
  v7[16] = -1;
LABEL_18:
  if ( v7[17] )
  {
    if ( v7[18] )
      goto LABEL_20;
  }
  else
  {
    v7[17] = -1;
    if ( v7[18] )
      goto LABEL_20;
  }
  v7[18] = -1;
LABEL_20:
  v8 = a2 + 20434;
  if ( !v7[19] )
    v7[19] = -1;
  v9 = gmu_core_isenabled(a2);
  v10 = *(_QWORD *)(a2 + 14264);
  if ( v4 != &adreno_a6xx_rgmu_gpudev && (v9 & 1) != 0 )
  {
    if ( *(_DWORD *)v10 == 621 || *(_DWORD *)v10 == 662 )
      v12 = 156739;
    else
      v12 = 148508;
    *(_DWORD *)(a2 + 9116) = v12;
    if ( *(_DWORD *)v10 == 622 )
      v12 = 156741;
    *(_DWORD *)(a2 + 9116) = v12;
  }
  *(_BYTE *)v8 = 1;
  *(_DWORD *)(v8 + 3554) = 1;
  if ( (*(_BYTE *)(v10 + 32) & 4) != 0 || *(_BYTE *)(v8 + 9) == 1 )
  {
    v13 = *(_QWORD *)(v10 + 184);
    *(_DWORD *)(v8 + 142) = 1;
    *(_WORD *)(v8 + 146) = 257;
    if ( !v13 )
      v13 = 2162688;
    *(_QWORD *)(a2 + 24520) = v13;
  }
  result = adreno_device_probe(a1, (_QWORD *)a2);
  if ( !(_DWORD)result )
  {
    a6xx_coresight_init(a2);
    return 0;
  }
  return result;
}
