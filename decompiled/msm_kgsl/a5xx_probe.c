__int64 __fastcall a5xx_probe(__int64 a1, int a2, __int64 a3)
{
  __int64 match_data; // x19
  _DWORD *v7; // x8
  __int64 v8; // x8
  char v9; // w8
  __int64 result; // x0

  match_data = of_device_get_match_data(a1 + 16);
  memset((void *)match_data, 0, 0x5FE0u);
  *(_QWORD *)(match_data + 14264) = a3;
  *(_DWORD *)(match_data + 14248) = a2;
  v7 = **(_DWORD ***)(a3 + 40);
  if ( *v7 )
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
      goto LABEL_28;
    }
  }
  v7[1] = -1;
  if ( v7[2] )
  {
LABEL_4:
    if ( v7[3] )
      goto LABEL_5;
    goto LABEL_29;
  }
LABEL_28:
  v7[2] = -1;
  if ( v7[3] )
  {
LABEL_5:
    if ( v7[4] )
      goto LABEL_6;
    goto LABEL_30;
  }
LABEL_29:
  v7[3] = -1;
  if ( v7[4] )
  {
LABEL_6:
    if ( v7[5] )
      goto LABEL_7;
    goto LABEL_31;
  }
LABEL_30:
  v7[4] = -1;
  if ( v7[5] )
  {
LABEL_7:
    if ( v7[6] )
      goto LABEL_8;
    goto LABEL_32;
  }
LABEL_31:
  v7[5] = -1;
  if ( v7[6] )
  {
LABEL_8:
    if ( v7[7] )
      goto LABEL_9;
    goto LABEL_33;
  }
LABEL_32:
  v7[6] = -1;
  if ( v7[7] )
  {
LABEL_9:
    if ( v7[8] )
      goto LABEL_10;
    goto LABEL_34;
  }
LABEL_33:
  v7[7] = -1;
  if ( v7[8] )
  {
LABEL_10:
    if ( v7[9] )
      goto LABEL_11;
    goto LABEL_35;
  }
LABEL_34:
  v7[8] = -1;
  if ( v7[9] )
  {
LABEL_11:
    if ( v7[10] )
      goto LABEL_12;
    goto LABEL_36;
  }
LABEL_35:
  v7[9] = -1;
  if ( v7[10] )
  {
LABEL_12:
    if ( v7[11] )
      goto LABEL_13;
    goto LABEL_37;
  }
LABEL_36:
  v7[10] = -1;
  if ( v7[11] )
  {
LABEL_13:
    if ( v7[12] )
      goto LABEL_14;
    goto LABEL_38;
  }
LABEL_37:
  v7[11] = -1;
  if ( v7[12] )
  {
LABEL_14:
    if ( v7[13] )
      goto LABEL_15;
    goto LABEL_39;
  }
LABEL_38:
  v7[12] = -1;
  if ( v7[13] )
  {
LABEL_15:
    if ( v7[14] )
      goto LABEL_16;
LABEL_40:
    v7[14] = -1;
    if ( v7[15] )
      goto LABEL_17;
    goto LABEL_41;
  }
LABEL_39:
  v7[13] = -1;
  if ( !v7[14] )
    goto LABEL_40;
LABEL_16:
  if ( v7[15] )
    goto LABEL_17;
LABEL_41:
  v7[15] = -1;
LABEL_17:
  if ( v7[16] )
  {
    if ( v7[17] )
      goto LABEL_19;
  }
  else
  {
    v7[16] = -1;
    if ( v7[17] )
      goto LABEL_19;
  }
  v7[17] = -1;
LABEL_19:
  if ( v7[18] )
  {
    if ( v7[19] )
      goto LABEL_21;
  }
  else
  {
    v7[18] = -1;
    if ( v7[19] )
      goto LABEL_21;
  }
  v7[19] = -1;
LABEL_21:
  v8 = *(_QWORD *)(match_data + 14264);
  *(_BYTE *)(match_data + 20436) = *(_BYTE *)(v8 + 32) & 1;
  if ( *(_DWORD *)v8 == 540 )
    *(_BYTE *)(match_data + 20435) = 1;
  *(_BYTE *)(match_data + 20434) = 1;
  v9 = *(_BYTE *)(v8 + 32);
  *(_DWORD *)(match_data + 20632) = 5111834;
  *(_BYTE *)(match_data + 20432) = (v9 & 8) != 0;
  init_timer_key(match_data + 8792, kgsl_timer, 0, 0, 0);
  *(_QWORD *)(match_data + 8760) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(match_data + 8768) = match_data + 8768;
  *(_QWORD *)(match_data + 8776) = match_data + 8768;
  *(_QWORD *)(match_data + 8784) = kgsl_idle_check;
  *(_DWORD *)(match_data + 20888) = 869270526;
  result = adreno_device_probe(a1, (_QWORD *)match_data);
  if ( !(_DWORD)result )
  {
    a5xx_coresight_init(match_data);
    return adreno_dispatcher_init(match_data);
  }
  return result;
}
