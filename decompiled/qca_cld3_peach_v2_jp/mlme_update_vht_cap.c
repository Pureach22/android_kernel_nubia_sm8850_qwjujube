__int64 __fastcall mlme_update_vht_cap(__int64 a1, unsigned int *a2, unsigned int a3)
{
  __int64 psoc_ext_obj_fl; // x0
  unsigned int v7; // w8
  __int64 v8; // x20
  int v9; // w8
  unsigned __int8 v10; // w9
  int v11; // w10
  int v12; // w12
  int v13; // w9
  int v14; // w12
  int v15; // w9
  int v16; // w10
  int v17; // w9
  int v19; // w14
  int v20; // w16
  int v21; // w13
  int v22; // w17
  int v23; // w0
  int v24; // w13
  int v25; // w12
  int v26; // w14
  int v27; // w16
  int v28; // w17
  int v29; // w0
  int v30; // w13
  int v31; // w12
  int v32; // w14
  int v33; // w15
  int v34; // w16
  unsigned int v35; // w8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x4

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v7 = *(unsigned __int8 *)(psoc_ext_obj_fl + 2674);
  v8 = psoc_ext_obj_fl;
  if ( *a2 < v7 )
  {
    v7 = (unsigned __int8)*a2;
    *(_BYTE *)(psoc_ext_obj_fl + 2674) = *a2;
  }
  if ( v7 )
    *(_WORD *)(psoc_ext_obj_fl + 1268) |= 0x800u;
  v9 = *(unsigned __int8 *)(psoc_ext_obj_fl + 2667);
  if ( v9 + 1 < a3 )
    v10 = v9 + 1;
  else
    v10 = a3;
  v11 = (-1LL << (2 * v10)) ^ 0xFFFF0000;
  v12 = v11 | *(_DWORD *)(psoc_ext_obj_fl + 2648) | 0xFFFC;
  if ( *(_BYTE *)(psoc_ext_obj_fl + 2667) && v10 >= 2u )
  {
    v19 = 2;
    v20 = 2;
    v21 = *(_BYTE *)(psoc_ext_obj_fl + 2664) & 3;
    do
    {
      v22 = 3 << v19;
      ++v20;
      v23 = v21 << v19;
      v19 += 2;
      v12 = v23 | v12 & ~v22;
    }
    while ( (unsigned __int8)v20 <= (unsigned int)v10 );
    v24 = *(_DWORD *)(v8 + 2656);
    *(_DWORD *)(v8 + 2648) = v12;
    v25 = v11 | v24 | 0xFFFC;
    v26 = 2;
    v27 = 2;
    do
    {
      v28 = 3 << v26;
      ++v27;
      v29 = (*(_BYTE *)(v8 + 2664) & 3) << v26;
      v26 += 2;
      v25 = v29 | v25 & ~v28;
    }
    while ( (unsigned __int8)v27 <= (unsigned int)v10 );
    v30 = *(_DWORD *)(v8 + 2660);
    *(_DWORD *)(v8 + 2632) = v25;
    v16 = v11 | v30 | 0xFFFC;
    v31 = 2;
    v32 = 2;
    do
    {
      v33 = 3 << v31;
      ++v32;
      v34 = (*(_BYTE *)(v8 + 2665) & 3) << v31;
      v31 += 2;
      v16 = v34 | v16 & ~v33;
    }
    while ( (unsigned __int8)v32 <= (unsigned int)v10 );
  }
  else
  {
    v13 = *(_DWORD *)(psoc_ext_obj_fl + 2656);
    *(_DWORD *)(psoc_ext_obj_fl + 2648) = v12;
    v14 = v11 | v13 | 0xFFFC;
    v15 = *(_DWORD *)(psoc_ext_obj_fl + 2660);
    *(_DWORD *)(psoc_ext_obj_fl + 2632) = v14;
    v16 = v11 | v15 | 0xFFFC;
  }
  v17 = *(unsigned __int8 *)(v8 + 2617);
  *(_DWORD *)(v8 + 2636) = v16;
  if ( v17 == 1 && !a2[2] )
    *(_BYTE *)(v8 + 2617) = 0;
  if ( *(_BYTE *)(v8 + 2618) == 1 && !a2[3] )
  {
    *(_BYTE *)(v8 + 2618) = 0;
    if ( v9 )
      goto LABEL_19;
  }
  else if ( v9 )
  {
LABEL_19:
    if ( *(_BYTE *)(v8 + 2620) == 1 && !a2[5] )
      *(_BYTE *)(v8 + 2620) = 0;
    if ( *(_BYTE *)(v8 + 2621) != 1 || a2[6] )
      goto LABEL_38;
    goto LABEL_37;
  }
  *(_BYTE *)(v8 + 2620) = 0;
LABEL_37:
  *(_BYTE *)(v8 + 2621) = 0;
LABEL_38:
  if ( *(_BYTE *)(v8 + 2622) == 1 && !a2[7] )
    *(_BYTE *)(v8 + 2622) = 0;
  if ( *(_BYTE *)(v8 + 2623) == 1 && !a2[8] )
    *(_BYTE *)(v8 + 2623) = 0;
  if ( *(_BYTE *)(v8 + 2626) == 1 && !a2[9] )
    *(_BYTE *)(v8 + 2626) = 0;
  if ( *(_BYTE *)(v8 + 2668) == 1 && !a2[10] )
    *(_BYTE *)(v8 + 2668) = 0;
  v35 = a2[11];
  if ( v35 < *(unsigned __int8 *)(v8 + 2673) )
    *(_BYTE *)(v8 + 2673) = v35;
  if ( *(_BYTE *)(v8 + 2627) == 1 && !a2[12] )
    *(_BYTE *)(v8 + 2627) = 0;
  if ( *(_BYTE *)(v8 + 2619) == 1 && !a2[4] )
    *(_BYTE *)(v8 + 2619) = 0;
  if ( (*(_BYTE *)(cfg_psoc_get_values(a1) + 10163) & 1) != 0 )
  {
    v44 = a2[13] != 0;
    *(_BYTE *)(v8 + 2680) = v44;
  }
  else
  {
    v44 = *(unsigned __int8 *)(v8 + 2680);
  }
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: vht_mcs_10_11_supp %d",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "mlme_update_vht_cap",
    v44);
  return 0;
}
