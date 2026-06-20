__int64 __fastcall qcom_icc_aggregate(
        __int64 a1,
        int a2,
        unsigned int a3,
        unsigned int a4,
        _DWORD *a5,
        unsigned int *a6)
{
  __int16 v6; // w10
  __int64 v7; // x8
  bool v9; // w9
  unsigned int v10; // w13
  __int64 v11; // x12
  unsigned __int64 v12; // x12
  unsigned __int64 v13; // x12
  unsigned int v14; // w13
  __int64 v15; // x12
  unsigned __int64 v16; // x12
  unsigned __int64 v17; // x12
  unsigned int v18; // w13
  __int64 v19; // x12
  unsigned __int64 v20; // x12
  unsigned __int64 v21; // x12
  unsigned int v22; // w13
  __int64 v23; // x12
  unsigned __int64 v24; // x12
  unsigned __int64 v25; // x12
  unsigned int v26; // w12
  __int64 v27; // x10
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x9
  __int64 result; // x0
  unsigned int v31; // w8

  if ( a2 )
    v6 = a2;
  else
    v6 = 7;
  v7 = *(_QWORD *)(a1 + 112);
  v9 = (v6 & 0x100) == 0 || (a4 | a3) == 0;
  if ( (v6 & 1) != 0 )
  {
    v10 = *(_DWORD *)(v7 + 312);
    *(_QWORD *)(v7 + 272) += a3;
    v11 = v10 <= a4 ? a4 : v10;
    *(_QWORD *)(v7 + 312) = v11;
    if ( !v9 )
      *(_BYTE *)(v7 + 352) = 1;
  }
  v12 = *(unsigned int *)(a1 + 104);
  if ( *(_QWORD *)(a1 + 104) )
  {
    if ( *(_QWORD *)(v7 + 272) > v12 )
      v12 = *(_QWORD *)(v7 + 272);
    *(_QWORD *)(v7 + 272) = v12;
    v13 = *(_QWORD *)(v7 + 312);
    if ( v13 <= *(unsigned int *)(a1 + 108) )
      v13 = *(unsigned int *)(a1 + 108);
    *(_QWORD *)(v7 + 312) = v13;
  }
  if ( (v6 & 2) != 0 )
  {
    v14 = *(_DWORD *)(v7 + 320);
    *(_QWORD *)(v7 + 280) += a3;
    v15 = v14 <= a4 ? a4 : v14;
    *(_QWORD *)(v7 + 320) = v15;
    if ( !v9 )
      *(_BYTE *)(v7 + 353) = 1;
  }
  v16 = *(unsigned int *)(a1 + 104);
  if ( *(_QWORD *)(a1 + 104) )
  {
    if ( *(_QWORD *)(v7 + 280) > v16 )
      v16 = *(_QWORD *)(v7 + 280);
    *(_QWORD *)(v7 + 280) = v16;
    v17 = *(_QWORD *)(v7 + 320);
    if ( v17 <= *(unsigned int *)(a1 + 108) )
      v17 = *(unsigned int *)(a1 + 108);
    *(_QWORD *)(v7 + 320) = v17;
  }
  if ( (v6 & 4) != 0 )
  {
    v18 = *(_DWORD *)(v7 + 328);
    *(_QWORD *)(v7 + 288) += a3;
    v19 = v18 <= a4 ? a4 : v18;
    *(_QWORD *)(v7 + 328) = v19;
    if ( !v9 )
      *(_BYTE *)(v7 + 354) = 1;
  }
  v20 = *(unsigned int *)(a1 + 104);
  if ( *(_QWORD *)(a1 + 104) )
  {
    if ( *(_QWORD *)(v7 + 288) > v20 )
      v20 = *(_QWORD *)(v7 + 288);
    *(_QWORD *)(v7 + 288) = v20;
    v21 = *(_QWORD *)(v7 + 328);
    if ( v21 <= *(unsigned int *)(a1 + 108) )
      v21 = *(unsigned int *)(a1 + 108);
    *(_QWORD *)(v7 + 328) = v21;
  }
  if ( (v6 & 8) != 0 )
  {
    v22 = *(_DWORD *)(v7 + 336);
    *(_QWORD *)(v7 + 296) += a3;
    v23 = v22 <= a4 ? a4 : v22;
    *(_QWORD *)(v7 + 336) = v23;
    if ( !v9 )
      *(_BYTE *)(v7 + 355) = 1;
  }
  v24 = *(unsigned int *)(a1 + 104);
  if ( *(_QWORD *)(a1 + 104) )
  {
    if ( *(_QWORD *)(v7 + 296) > v24 )
      v24 = *(_QWORD *)(v7 + 296);
    *(_QWORD *)(v7 + 296) = v24;
    v25 = *(_QWORD *)(v7 + 336);
    if ( v25 <= *(unsigned int *)(a1 + 108) )
      v25 = *(unsigned int *)(a1 + 108);
    *(_QWORD *)(v7 + 336) = v25;
  }
  if ( (v6 & 0x10) != 0 )
  {
    v26 = *(_DWORD *)(v7 + 344);
    *(_QWORD *)(v7 + 304) += a3;
    v27 = v26 <= a4 ? a4 : v26;
    *(_QWORD *)(v7 + 344) = v27;
    if ( !v9 )
      *(_BYTE *)(v7 + 356) = 1;
  }
  v28 = *(unsigned int *)(a1 + 104);
  if ( *(_QWORD *)(a1 + 104) )
  {
    if ( *(_QWORD *)(v7 + 304) > v28 )
      v28 = *(_QWORD *)(v7 + 304);
    *(_QWORD *)(v7 + 304) = v28;
    v29 = *(_QWORD *)(v7 + 344);
    if ( v29 <= *(unsigned int *)(a1 + 108) )
      v29 = *(unsigned int *)(a1 + 108);
    *(_QWORD *)(v7 + 344) = v29;
  }
  result = 0;
  *a5 += a3;
  v31 = *a6;
  if ( *a6 <= a4 )
    v31 = a4;
  *a6 = v31;
  return result;
}
