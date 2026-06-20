_QWORD *__fastcall etm_addr_filters_sync(_QWORD *result)
{
  _QWORD *v1; // x8
  __int64 ********v2; // x11
  __int64 *v3; // x9
  __int64 v4; // x8
  __int64 *v5; // x10
  int v6; // w14
  __int64 v7; // x12
  __int64 v8; // x13
  int v9; // w12
  __int64 *******v10; // x11
  __int64 v11; // x14
  int v12; // w13
  __int64 v13; // x12
  __int64 ******v14; // x11
  __int64 v15; // x14
  int v16; // w13
  __int64 v17; // x12
  __int64 *****v18; // x11
  __int64 v19; // x14
  int v20; // w13
  __int64 v21; // x12
  __int64 ****v22; // x11
  __int64 v23; // x14
  int v24; // w13
  __int64 v25; // x12
  __int64 ***v26; // x11
  __int64 v27; // x14
  int v28; // w13
  __int64 v29; // x12
  __int64 **v30; // x11
  __int64 v31; // x14
  int v32; // w13
  __int64 v33; // x12
  __int64 *v34; // x11
  __int64 v35; // x14
  int v36; // w13
  __int64 v37; // x12
  __int64 v38; // x11
  __int64 v39; // x13
  int v40; // w12
  __int64 v41; // x10

  v1 = (_QWORD *)result[82];
  if ( !v1 )
    v1 = result;
  v2 = (__int64 ********)v1[117];
  v3 = v1 + 117;
  v4 = result[58];
  if ( v2 == (__int64 ********)v3 )
  {
    *(_DWORD *)(v4 + 192) = 0;
    return result;
  }
  v5 = (__int64 *)result[120];
  v6 = *((_DWORD *)v2 + 12);
  v7 = *v5;
  v8 = v5[1] + *v5;
  if ( v6 )
  {
    if ( v6 == 1 )
    {
      *(_QWORD *)v4 = v7;
      v9 = 3;
    }
    else
    {
      if ( v6 != 2 )
        goto LABEL_12;
      *(_QWORD *)v4 = v7;
      *(_QWORD *)(v4 + 8) = v8;
      v9 = 2;
    }
  }
  else
  {
    v9 = 4;
    *(_QWORD *)(v4 + 8) = v8;
  }
  *(_DWORD *)(v4 + 16) = v9;
LABEL_12:
  v10 = *v2;
  if ( v10 == (__int64 *******)v3 )
  {
    *(_DWORD *)(v4 + 192) = 1;
    return result;
  }
  v11 = v5[2];
  v12 = *((_DWORD *)v10 + 12);
  v13 = v5[3] + v11;
  if ( v12 == 2 )
  {
    *(_QWORD *)(v4 + 24) = v11;
    *(_QWORD *)(v4 + 32) = v13;
  }
  else if ( v12 == 1 )
  {
    *(_QWORD *)(v4 + 24) = v11;
    v12 = 3;
  }
  else
  {
    if ( v12 )
      goto LABEL_21;
    *(_QWORD *)(v4 + 32) = v13;
    v12 = 4;
  }
  *(_DWORD *)(v4 + 40) = v12;
LABEL_21:
  v14 = *v10;
  if ( v14 == (__int64 ******)v3 )
  {
    *(_DWORD *)(v4 + 192) = 2;
    return result;
  }
  v15 = v5[4];
  v16 = *((_DWORD *)v14 + 12);
  v17 = v5[5] + v15;
  if ( v16 == 2 )
  {
    *(_QWORD *)(v4 + 48) = v15;
    *(_QWORD *)(v4 + 56) = v17;
  }
  else if ( v16 == 1 )
  {
    *(_QWORD *)(v4 + 48) = v15;
    v16 = 3;
  }
  else
  {
    if ( v16 )
      goto LABEL_30;
    *(_QWORD *)(v4 + 56) = v17;
    v16 = 4;
  }
  *(_DWORD *)(v4 + 64) = v16;
LABEL_30:
  v18 = *v14;
  if ( v18 == (__int64 *****)v3 )
  {
    *(_DWORD *)(v4 + 192) = 3;
    return result;
  }
  v19 = v5[6];
  v20 = *((_DWORD *)v18 + 12);
  v21 = v5[7] + v19;
  if ( v20 == 2 )
  {
    *(_QWORD *)(v4 + 72) = v19;
    *(_QWORD *)(v4 + 80) = v21;
  }
  else if ( v20 == 1 )
  {
    *(_QWORD *)(v4 + 72) = v19;
    v20 = 3;
  }
  else
  {
    if ( v20 )
      goto LABEL_39;
    *(_QWORD *)(v4 + 80) = v21;
    v20 = 4;
  }
  *(_DWORD *)(v4 + 88) = v20;
LABEL_39:
  v22 = *v18;
  if ( v22 == (__int64 ****)v3 )
  {
    *(_DWORD *)(v4 + 192) = 4;
    return result;
  }
  v23 = v5[8];
  v24 = *((_DWORD *)v22 + 12);
  v25 = v5[9] + v23;
  if ( v24 == 2 )
  {
    *(_QWORD *)(v4 + 96) = v23;
    *(_QWORD *)(v4 + 104) = v25;
  }
  else if ( v24 == 1 )
  {
    *(_QWORD *)(v4 + 96) = v23;
    v24 = 3;
  }
  else
  {
    if ( v24 )
      goto LABEL_48;
    *(_QWORD *)(v4 + 104) = v25;
    v24 = 4;
  }
  *(_DWORD *)(v4 + 112) = v24;
LABEL_48:
  v26 = *v22;
  if ( v26 == (__int64 ***)v3 )
  {
    *(_DWORD *)(v4 + 192) = 5;
    return result;
  }
  v27 = v5[10];
  v28 = *((_DWORD *)v26 + 12);
  v29 = v5[11] + v27;
  if ( v28 == 2 )
  {
    *(_QWORD *)(v4 + 120) = v27;
    *(_QWORD *)(v4 + 128) = v29;
  }
  else if ( v28 == 1 )
  {
    *(_QWORD *)(v4 + 120) = v27;
    v28 = 3;
  }
  else
  {
    if ( v28 )
      goto LABEL_57;
    *(_QWORD *)(v4 + 128) = v29;
    v28 = 4;
  }
  *(_DWORD *)(v4 + 136) = v28;
LABEL_57:
  v30 = *v26;
  if ( v30 == (__int64 **)v3 )
  {
    *(_DWORD *)(v4 + 192) = 6;
    return result;
  }
  v31 = v5[12];
  v32 = *((_DWORD *)v30 + 12);
  v33 = v5[13] + v31;
  if ( v32 == 2 )
  {
    *(_QWORD *)(v4 + 144) = v31;
    *(_QWORD *)(v4 + 152) = v33;
  }
  else if ( v32 == 1 )
  {
    *(_QWORD *)(v4 + 144) = v31;
    v32 = 3;
  }
  else
  {
    if ( v32 )
      goto LABEL_66;
    *(_QWORD *)(v4 + 152) = v33;
    v32 = 4;
  }
  *(_DWORD *)(v4 + 160) = v32;
LABEL_66:
  v34 = *v30;
  if ( v34 == v3 )
  {
    *(_DWORD *)(v4 + 192) = 7;
    return result;
  }
  v35 = v5[14];
  v36 = *((_DWORD *)v34 + 12);
  v37 = v5[15] + v35;
  if ( v36 == 2 )
  {
    *(_QWORD *)(v4 + 168) = v35;
    *(_QWORD *)(v4 + 176) = v37;
  }
  else if ( v36 == 1 )
  {
    *(_QWORD *)(v4 + 168) = v35;
    v36 = 3;
  }
  else
  {
    if ( v36 )
      goto LABEL_75;
    *(_QWORD *)(v4 + 176) = v37;
    v36 = 4;
  }
  *(_DWORD *)(v4 + 184) = v36;
LABEL_75:
  v38 = *v34;
  if ( (__int64 *)v38 == v3 )
  {
    *(_DWORD *)(v4 + 192) = 8;
    return result;
  }
  v39 = v5[16];
  v40 = *(_DWORD *)(v38 + 48);
  v41 = v5[17] + v39;
  if ( v40 == 2 )
  {
    *(_QWORD *)(v4 + 192) = v39;
    *(_QWORD *)(v4 + 200) = v41;
  }
  else if ( v40 == 1 )
  {
    *(_QWORD *)(v4 + 192) = v39;
    v40 = 3;
  }
  else
  {
    if ( v40 )
      goto LABEL_84;
    *(_QWORD *)(v4 + 200) = v41;
    v40 = 4;
  }
  *(_DWORD *)(v4 + 208) = v40;
LABEL_84:
  if ( *(__int64 **)v38 == v3 )
  {
    *(_DWORD *)(v4 + 192) = 9;
  }
  else
  {
    __break(0x5512u);
    return (_QWORD *)etm_addr_filters_validate();
  }
  return result;
}
