__int64 __fastcall gen7_probe_common(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  _DWORD **v4; // x8
  _DWORD *v8; // x8
  __int64 v9; // x22
  _DWORD *v10; // x9
  int v11; // w10
  int v12; // w8
  __int64 result; // x0
  __int64 v14; // x8
  __int64 v15; // x9
  int v16; // w8
  __int64 v17; // x8
  unsigned __int64 v24; // x9

  v4 = *(_DWORD ***)(a4 + 40);
  *(_QWORD *)(a2 + 14264) = a4;
  *(_DWORD *)(a2 + 14248) = a3;
  v8 = *v4;
  if ( *v8 )
  {
    if ( v8[1] )
      goto LABEL_3;
  }
  else
  {
    *v8 = -1;
    if ( v8[1] )
    {
LABEL_3:
      if ( v8[2] )
        goto LABEL_4;
      goto LABEL_39;
    }
  }
  v8[1] = -1;
  if ( v8[2] )
  {
LABEL_4:
    if ( v8[3] )
      goto LABEL_5;
    goto LABEL_40;
  }
LABEL_39:
  v8[2] = -1;
  if ( v8[3] )
  {
LABEL_5:
    if ( v8[4] )
      goto LABEL_6;
    goto LABEL_41;
  }
LABEL_40:
  v8[3] = -1;
  if ( v8[4] )
  {
LABEL_6:
    if ( v8[5] )
      goto LABEL_7;
    goto LABEL_42;
  }
LABEL_41:
  v8[4] = -1;
  if ( v8[5] )
  {
LABEL_7:
    if ( v8[6] )
      goto LABEL_8;
    goto LABEL_43;
  }
LABEL_42:
  v8[5] = -1;
  if ( v8[6] )
  {
LABEL_8:
    if ( v8[7] )
      goto LABEL_9;
    goto LABEL_44;
  }
LABEL_43:
  v8[6] = -1;
  if ( v8[7] )
  {
LABEL_9:
    if ( v8[8] )
      goto LABEL_10;
    goto LABEL_45;
  }
LABEL_44:
  v8[7] = -1;
  if ( v8[8] )
  {
LABEL_10:
    if ( v8[9] )
      goto LABEL_11;
    goto LABEL_46;
  }
LABEL_45:
  v8[8] = -1;
  if ( v8[9] )
  {
LABEL_11:
    if ( v8[10] )
      goto LABEL_12;
    goto LABEL_47;
  }
LABEL_46:
  v8[9] = -1;
  if ( v8[10] )
  {
LABEL_12:
    if ( v8[11] )
      goto LABEL_13;
    goto LABEL_48;
  }
LABEL_47:
  v8[10] = -1;
  if ( v8[11] )
  {
LABEL_13:
    if ( v8[12] )
      goto LABEL_14;
    goto LABEL_49;
  }
LABEL_48:
  v8[11] = -1;
  if ( v8[12] )
  {
LABEL_14:
    if ( v8[13] )
      goto LABEL_15;
    goto LABEL_50;
  }
LABEL_49:
  v8[12] = -1;
  if ( v8[13] )
  {
LABEL_15:
    if ( v8[14] )
      goto LABEL_16;
LABEL_51:
    v8[14] = -1;
    if ( v8[15] )
      goto LABEL_17;
    goto LABEL_52;
  }
LABEL_50:
  v8[13] = -1;
  if ( !v8[14] )
    goto LABEL_51;
LABEL_16:
  if ( v8[15] )
    goto LABEL_17;
LABEL_52:
  v8[15] = -1;
LABEL_17:
  if ( v8[16] )
  {
    if ( v8[17] )
      goto LABEL_19;
  }
  else
  {
    v8[16] = -1;
    if ( v8[17] )
      goto LABEL_19;
  }
  v8[17] = -1;
LABEL_19:
  v9 = a2 + 20434;
  if ( v8[18] )
  {
    if ( v8[19] )
      goto LABEL_21;
  }
  else
  {
    v8[18] = -1;
    if ( v8[19] )
      goto LABEL_21;
  }
  v8[19] = -1;
LABEL_21:
  *(_BYTE *)v9 = 1;
  *(_DWORD *)(a2 + 23988) = 1;
  kgsl_pwrscale_fast_bus_hint(*(unsigned __int8 *)(a4 + 252));
  v10 = *(_DWORD **)(a2 + 14264);
  *(_DWORD *)(a2 + 10940) = *(_DWORD *)(a4 + 248);
  if ( *v10 == 463104 )
    v11 = 156741;
  else
    v11 = 156739;
  if ( *v10 == 461568 )
    v12 = 156708;
  else
    v12 = v11;
  *(_DWORD *)(a2 + 9116) = v12;
  result = adreno_device_probe(a1, (_QWORD *)a2);
  if ( !(_DWORD)result )
  {
    v14 = *(_QWORD *)(a2 + 14264);
    if ( (*(_BYTE *)(v14 + 32) & 4) != 0 || *(_BYTE *)(v9 + 9) == 1 )
    {
      v15 = *(_QWORD *)(v14 + 192);
      if ( !v15 )
        v15 = 4292608;
      *(_QWORD *)(a2 + 24520) = v15;
      v16 = *(_DWORD *)(v14 + 228);
      *(_WORD *)(v9 + 146) = 257;
      *(_DWORD *)(v9 + 142) = v16;
      _X8 = (unsigned __int64 *)(a2 + 14240);
      __asm { PRFM            #0x11, [X8] }
      do
        v24 = __ldxr(_X8);
      while ( __stxr(v24 | 0x200, _X8) );
    }
    debugfs_create_file("acd_calibrate", 420, *(_QWORD *)(a2 + 11176), a2, &acd_cal_fops);
    gen7_coresight_init(a2);
    result = 0;
    v17 = 114688;
    if ( (*(_QWORD *)(*(_QWORD *)(a2 + 14264) + 32LL) & 0x40000LL) == 0 )
      v17 = 98304;
    *(_QWORD *)(a2 + 11312) = v17;
  }
  return result;
}
