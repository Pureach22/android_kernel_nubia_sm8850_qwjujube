bool __fastcall qcom_smd_channel_intr(__int64 *a1)
{
  __int64 v2; // x8
  int *v3; // x9
  int v4; // w22
  int v5; // w23
  __int64 v6; // x8
  __int64 v7; // x8
  _DWORD *v8; // x8
  int *v9; // x8
  int v10; // w11
  int *v11; // x9
  _DWORD *i; // x10
  __int64 v13; // x10
  int v14; // w11
  unsigned int v15; // w9
  int v16; // w20
  int v17; // w10
  __int64 v18; // x8
  unsigned int *v19; // x8
  __int64 v20; // x8
  __int64 *v21; // x24
  __int64 v22; // x21
  _DWORD *v23; // x8
  __int64 v24; // x0
  __int64 v25; // x3
  int v26; // w0
  int *v27; // x8
  __int64 v28; // x8
  __int64 v29; // x19
  __int64 v30; // x0
  int v32; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[9];
  if ( v2 )
    v3 = (int *)(v2 + 44);
  else
    v3 = (int *)(a1[8] + 20);
  v4 = *v3;
  v5 = *((_DWORD *)a1 + 9);
  v32 = 0;
  if ( v4 != v5 )
  {
    *((_DWORD *)a1 + 9) = v4;
    _wake_up(a1 + 5, 1, 0, 0);
    v2 = a1[9];
  }
  if ( v2 )
  {
    *(_DWORD *)(v2 + 72) = 0;
    v6 = a1[9];
    if ( v6 )
      goto LABEL_8;
LABEL_15:
    if ( *(_BYTE *)(a1[8] + 11) )
      goto LABEL_10;
    goto LABEL_9;
  }
  *(_BYTE *)(a1[8] + 30) = 0;
  v6 = a1[9];
  if ( !v6 )
    goto LABEL_15;
LABEL_8:
  if ( !*(_DWORD *)(v6 + 32) )
LABEL_9:
    _wake_up(a1 + 11, 1, 0, 0);
LABEL_10:
  if ( *((_DWORD *)a1 + 8) != 2 )
    goto LABEL_52;
  v7 = a1[9];
  if ( v7 )
  {
    *(_DWORD *)(v7 + 64) = 0;
    v8 = (_DWORD *)a1[9];
    if ( v8 )
      goto LABEL_21;
  }
  else
  {
    *(_BYTE *)(a1[8] + 28) = 0;
    v8 = (_DWORD *)a1[9];
    if ( v8 )
      goto LABEL_21;
  }
LABEL_22:
  v13 = a1[8];
  v11 = (int *)(v13 + 36);
  for ( i = (_DWORD *)(v13 + 32); ; i = v8 + 20 )
  {
    v14 = *v11;
    v15 = *((_DWORD *)a1 + 32);
    v16 = *((_DWORD *)a1 + 37);
    v17 = (v15 - 1) & (v14 - *i);
    if ( !v16 && v17 >= 20 )
    {
      qcom_smd_channel_peek(a1, &v32, 4);
      v18 = a1[9];
      if ( v18 )
        v9 = (int *)(v18 + 80);
      else
        v9 = (int *)(a1[8] + 32);
      v10 = v32;
      *v9 = (*((_DWORD *)a1 + 32) - 1) & (*v9 + 20);
      *((_DWORD *)a1 + 37) = v10;
      v8 = (_DWORD *)a1[9];
      if ( !v8 )
        goto LABEL_22;
      goto LABEL_21;
    }
    if ( !v16 || v16 > v17 )
      break;
    if ( v8 )
      v19 = v8 + 20;
    else
      v19 = (unsigned int *)(a1[8] + 32);
    v20 = *v19;
    v21 = (__int64 *)a1[1];
    if ( (int)v20 + v16 >= v15 )
    {
      v22 = a1[17];
      qcom_smd_channel_peek(a1, v22, *((int *)a1 + 37));
    }
    else
    {
      v22 = a1[15] + v20;
    }
    v23 = (_DWORD *)v21[2];
    v24 = *v21;
    v25 = v21[11];
    if ( *(v23 - 1) != -384116476 )
      __break(0x8228u);
    v26 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64))v23)(
            v24,
            v22,
            (unsigned int)v16,
            v25,
            0xFFFFFFFFLL);
    v8 = (_DWORD *)a1[9];
    if ( v26 < 0 )
      break;
    if ( v8 )
      v27 = v8 + 20;
    else
      v27 = (int *)(a1[8] + 32);
    *v27 = (*((_DWORD *)a1 + 32) - 1) & (*v27 + v16);
    *((_DWORD *)a1 + 37) = 0;
    v8 = (_DWORD *)a1[9];
    if ( !v8 )
      goto LABEL_22;
LABEL_21:
    v11 = v8 + 21;
  }
  if ( v8 )
  {
    v8[17] = 1;
    v28 = a1[9];
    if ( v28 )
      goto LABEL_45;
LABEL_48:
    if ( !*(_BYTE *)(a1[8] + 31) )
      goto LABEL_49;
  }
  else
  {
    *(_BYTE *)(a1[8] + 29) = 1;
    v28 = a1[9];
    if ( !v28 )
      goto LABEL_48;
LABEL_45:
    if ( !*(_DWORD *)(v28 + 76) )
    {
LABEL_49:
      __dsb(0xEu);
      v29 = *a1;
      v30 = *(_QWORD *)(v29 + 1016);
      if ( v30 )
      {
        mbox_send_message(v30, 0);
        mbox_client_txdone(*(_QWORD *)(v29 + 1016), 0);
      }
      else
      {
        regmap_write(*(_QWORD *)(v29 + 944), *(unsigned int *)(v29 + 952), 1LL << *(_DWORD *)(v29 + 956));
      }
    }
  }
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return v4 != v5;
}
