__int64 __fastcall qcom_smd_channel_reset(__int64 *a1)
{
  _DWORD *v1; // x8
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  _DWORD *v12; // x8
  __int64 v13; // x8
  _DWORD *v14; // x8
  __int64 v15; // x20
  __int64 v16; // x0
  __int64 result; // x0

  v1 = (_DWORD *)a1[9];
  if ( !v1 )
    v1 = (_DWORD *)a1[8];
  *v1 = 0;
  v3 = a1[9];
  if ( v3 )
  {
    *(_DWORD *)(v3 + 4) = 0;
    v4 = a1[9];
    if ( v4 )
      goto LABEL_5;
  }
  else
  {
    *(_BYTE *)(a1[8] + 4) = 0;
    v4 = a1[9];
    if ( v4 )
    {
LABEL_5:
      *(_DWORD *)(v4 + 8) = 0;
      v5 = a1[9];
      if ( v5 )
        goto LABEL_6;
      goto LABEL_15;
    }
  }
  *(_BYTE *)(a1[8] + 5) = 0;
  v5 = a1[9];
  if ( v5 )
  {
LABEL_6:
    *(_DWORD *)(v5 + 12) = 0;
    v6 = a1[9];
    if ( v6 )
      goto LABEL_7;
    goto LABEL_16;
  }
LABEL_15:
  *(_BYTE *)(a1[8] + 6) = 0;
  v6 = a1[9];
  if ( v6 )
  {
LABEL_7:
    *(_DWORD *)(v6 + 16) = 0;
    v7 = a1[9];
    if ( v7 )
      goto LABEL_8;
    goto LABEL_17;
  }
LABEL_16:
  *(_BYTE *)(a1[8] + 7) = 0;
  v7 = a1[9];
  if ( v7 )
  {
LABEL_8:
    *(_DWORD *)(v7 + 20) = 0;
    v8 = a1[9];
    if ( v8 )
      goto LABEL_9;
    goto LABEL_18;
  }
LABEL_17:
  *(_BYTE *)(a1[8] + 8) = 0;
  v8 = a1[9];
  if ( v8 )
  {
LABEL_9:
    *(_DWORD *)(v8 + 24) = 0;
    v9 = a1[9];
    if ( v9 )
      goto LABEL_10;
    goto LABEL_19;
  }
LABEL_18:
  *(_BYTE *)(a1[8] + 9) = 0;
  v9 = a1[9];
  if ( v9 )
  {
LABEL_10:
    *(_DWORD *)(v9 + 28) = 1;
    v10 = a1[9];
    if ( v10 )
      goto LABEL_11;
LABEL_20:
    *(_BYTE *)(a1[8] + 11) = 1;
    v11 = a1[9];
    if ( v11 )
      goto LABEL_12;
    goto LABEL_21;
  }
LABEL_19:
  *(_BYTE *)(a1[8] + 10) = 1;
  v10 = a1[9];
  if ( !v10 )
    goto LABEL_20;
LABEL_11:
  *(_DWORD *)(v10 + 32) = 1;
  v11 = a1[9];
  if ( v11 )
  {
LABEL_12:
    v12 = (_DWORD *)(v11 + 40);
    goto LABEL_22;
  }
LABEL_21:
  v12 = (_DWORD *)(a1[8] + 16);
LABEL_22:
  *v12 = 0;
  v13 = a1[9];
  if ( v13 )
    v14 = (_DWORD *)(v13 + 80);
  else
    v14 = (_DWORD *)(a1[8] + 32);
  *v14 = 0;
  v15 = *a1;
  v16 = *(_QWORD *)(*a1 + 1016);
  if ( v16 )
  {
    mbox_send_message(v16, 0);
    result = mbox_client_txdone(*(_QWORD *)(v15 + 1016), 0);
  }
  else
  {
    result = regmap_write(*(_QWORD *)(v15 + 944), *(unsigned int *)(v15 + 952), 1LL << *(_DWORD *)(v15 + 956));
  }
  *((_DWORD *)a1 + 8) = 0;
  *((_DWORD *)a1 + 37) = 0;
  return result;
}
