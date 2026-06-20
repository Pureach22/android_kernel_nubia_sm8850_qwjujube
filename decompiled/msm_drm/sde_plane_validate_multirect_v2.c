__int64 __fastcall sde_plane_validate_multirect_v2(__int64 a1)
{
  __int64 *v1; // x21
  __int64 *v2; // x22
  char v3; // w9
  __int64 *v4; // x12
  __int64 *v5; // x10
  int *v6; // x11
  __int64 *v7; // x8
  int *v8; // x28
  char v9; // w24
  char v10; // w23
  char v11; // w27
  bool v12; // zf
  __int64 v13; // x9
  __int64 *v14; // x25
  __int64 v15; // x20
  __int64 v16; // x9
  int v17; // w7
  __int64 v18; // x0
  int v19; // w8
  unsigned int v20; // w10
  __int16 v21; // w9
  unsigned int v22; // w10
  unsigned int v23; // w12
  int v24; // w11
  int v25; // w13
  int v26; // w9
  unsigned int v27; // w10
  int v28; // w11
  int v29; // w12
  __int64 v30; // x13
  int v31; // w10
  int v32; // w8
  bool v33; // w8
  int v34; // w20
  char v35; // w9
  int v36; // w8
  __int64 v37; // x10
  __int64 v38; // x11
  __int64 v39; // x8
  char v40; // w9
  int v41; // w13
  int v42; // w12
  int v43; // w4
  __int64 result; // x0
  int v45; // w4
  void *v46; // x0
  void *v47; // x0
  int v48; // [xsp+0h] [xbp-80h]
  unsigned int v49; // [xsp+4h] [xbp-7Ch]
  int v51; // [xsp+14h] [xbp-6Ch] BYREF
  __int64 v52; // [xsp+18h] [xbp-68h] BYREF
  int v53; // [xsp+20h] [xbp-60h] BYREF
  __int64 v54; // [xsp+28h] [xbp-58h] BYREF
  __int64 v55; // [xsp+30h] [xbp-50h] BYREF
  __int64 v56; // [xsp+38h] [xbp-48h] BYREF
  __int64 v57; // [xsp+40h] [xbp-40h] BYREF
  __int64 v58; // [xsp+48h] [xbp-38h] BYREF
  __int64 v59; // [xsp+50h] [xbp-30h] BYREF
  __int64 v60; // [xsp+58h] [xbp-28h] BYREF
  __int64 v61; // [xsp+60h] [xbp-20h] BYREF
  __int64 v62; // [xsp+68h] [xbp-18h] BYREF
  _QWORD v63[2]; // [xsp+70h] [xbp-10h] BYREF

  v1 = &v62;
  v2 = &v60;
  v48 = 0;
  v3 = 1;
  v4 = &v57;
  v5 = &v55;
  v6 = &v53;
  v63[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = &v59;
  v8 = (int *)&v52;
  v9 = 1;
  v10 = 1;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v62 = 0;
  v63[0] = 0;
  v60 = 0;
  v61 = 0;
  v54 = 0;
  v55 = 0;
  v53 = 0;
  v52 = 0;
  v49 = 1;
  v51 = 0;
  do
  {
    v11 = v3;
    v12 = (v3 & 1) == 0;
    v13 = 8;
    if ( !v12 )
      v13 = 0;
    v14 = *(__int64 **)(a1 + v13);
    *v4 = (__int64)v14;
    if ( !v14 )
    {
      printk(&unk_227A13, "sde_plane_validate_multirect_v2");
LABEL_66:
      result = 4294967274LL;
      goto LABEL_67;
    }
    v15 = *v14;
    *v7 = (__int64)v14;
    v16 = *(_QWORD *)(v15 + 2208);
    *v5 = v15;
    v17 = *(_DWORD *)(*(_QWORD *)(v16 + 56) + 56LL);
    *v6 = v17;
    if ( !(v11 & 1 | (v17 == v53)) )
    {
      printk(&unk_2129B0, "sde_plane_validate_multirect_v2");
      goto LABEL_66;
    }
    v18 = msm_framebuffer_format(v14[2]);
    if ( !v18 )
    {
      v46 = &unk_235542;
      goto LABEL_65;
    }
    v19 = *(_DWORD *)(v18 + 28);
    if ( v19 == 2 && (*(_QWORD *)(v18 + 32) & 4) != 0 )
    {
      v20 = v49;
      if ( v49 <= *(unsigned __int16 *)(v18 + 42) )
        v20 = *(unsigned __int16 *)(v18 + 42);
      v49 = v20;
    }
    v21 = *((_WORD *)v14 + 25);
    v23 = *((_DWORD *)v14 + 14);
    v22 = *((_DWORD *)v14 + 15);
    *((_WORD *)v1 + 1) = *((_WORD *)v14 + 27);
    v24 = *((_DWORD *)v14 + 8);
    v25 = *((_DWORD *)v14 + 9);
    *(_WORD *)v1 = v21;
    v26 = HIWORD(v22);
    v27 = HIWORD(v23);
    *(_WORD *)v2 = v24;
    v29 = *((_DWORD *)v14 + 10);
    v28 = *((_DWORD *)v14 + 11);
    *((_WORD *)v2 + 1) = v25;
    v30 = v14[206];
    *((_WORD *)v1 + 2) = v26;
    *((_WORD *)v1 + 3) = v27;
    *((_WORD *)v2 + 2) = v29;
    *((_WORD *)v2 + 3) = v28;
    if ( !v30 && (v26 != (unsigned __int16)v29 || v27 != (unsigned __int16)v28) )
    {
      v46 = &unk_27409E;
LABEL_65:
      printk(v46, "sde_plane_validate_multirect_v2");
      goto LABEL_66;
    }
    if ( (*((_BYTE *)v14 + 2740) & 2) != 0 )
    {
      v46 = &unk_25B2C9;
      goto LABEL_65;
    }
    if ( (*(_QWORD *)(v18 + 32) & 1) != 0 )
    {
      v46 = &unk_27A61D;
      goto LABEL_65;
    }
    v31 = **(_DWORD **)(v15 + 3320);
    *v8 = v31;
    if ( v19 == 2 && (*(_QWORD *)(v18 + 32) & 4) != 0 )
    {
      if ( v31 >= 0 )
        v32 = v31;
      else
        v32 = v31 + 1;
      v31 = v32 >> 1;
      *v8 = v32 >> 1;
    }
    v33 = v31 >= v26;
    if ( *(_BYTE *)(v15 + 2388) == 1 )
      v48 = *((_DWORD *)v14 + 388);
    v3 = 0;
    v9 &= v33;
    v7 = &v58;
    v4 = &v56;
    v5 = &v54;
    v6 = (int *)&v52 + 1;
    if ( *((_BYTE *)v14 + 1784) != (v10 & 1) )
      v10 = 0;
    v8 = &v51;
    v2 = &v61;
    v1 = v63;
  }
  while ( (v11 & 1) != 0 );
  v34 = 2 * v49;
  if ( v48 == 2 )
  {
    if ( v34 + WORD1(v60) + (unsigned int)HIWORD(v60) <= WORD1(v61)
      || v34 + WORD1(v61) + (unsigned int)HIWORD(v61) <= WORD1(v60) )
    {
      goto LABEL_37;
    }
    printk(&unk_26CECF, "sde_plane_validate_multirect_v2");
    printk(&unk_212A13, "sde_plane_validate_multirect_v2");
    v47 = &unk_219DA9;
LABEL_69:
    printk(v47, "sde_plane_validate_multirect_v2");
    goto LABEL_70;
  }
  if ( v48 == 1 )
  {
    if ( (v9 & 1) != 0 )
      goto LABEL_39;
    printk(&unk_219D67, "sde_plane_validate_multirect_v2");
    printk(&unk_253EB2, "sde_plane_validate_multirect_v2");
    v47 = &unk_262864;
    goto LABEL_69;
  }
  if ( v48 )
  {
    printk(&unk_249949, "sde_plane_validate_multirect_v2");
LABEL_70:
    v36 = 0;
    v35 = 1;
    goto LABEL_40;
  }
  if ( (v9 & 1) != 0 )
  {
LABEL_39:
    v35 = 0;
    v36 = 1;
    goto LABEL_40;
  }
  if ( v34 + WORD1(v60) + (unsigned int)HIWORD(v60) > WORD1(v61)
    && v34 + WORD1(v61) + (unsigned int)HIWORD(v61) > WORD1(v60) )
  {
    printk(&unk_25B31D, "sde_plane_validate_multirect_v2");
    goto LABEL_70;
  }
LABEL_37:
  v35 = 0;
  v36 = 2;
LABEL_40:
  v38 = v58;
  v37 = v59;
  *(_DWORD *)(v59 + 1780) = v36;
  *(_BYTE *)(v37 + 1784) = v10 & 1;
  *(_DWORD *)(v38 + 1780) = v36;
  *(_BYTE *)(v38 + 1784) = v10 & 1;
  if ( (v35 & 1) != 0 )
    goto LABEL_66;
  v39 = v55;
  v40 = _drm_debug;
  if ( *(_BYTE *)(v55 + 2388) )
    v41 = 2;
  else
    v41 = 1;
  if ( *(_BYTE *)(v55 + 2388) )
    v42 = 1;
  else
    v42 = 2;
  *(_DWORD *)(v37 + 1776) = v41;
  *(_DWORD *)(v38 + 1776) = v42;
  if ( (v40 & 4) == 0 )
    goto LABEL_61;
  if ( v39 )
    v43 = *(_DWORD *)(v39 + 104);
  else
    v43 = -1;
  _drm_dev_dbg(0, 0, 0, "plane%d R0: %d - %d\n", v43, *(_DWORD *)(v37 + 1780), *(_DWORD *)(v37 + 1776));
  result = 0;
  if ( (_drm_debug & 4) != 0 )
  {
    if ( v54 )
      v45 = *(_DWORD *)(v54 + 104);
    else
      v45 = -1;
    _drm_dev_dbg(0, 0, 0, "plane%d R1: %d - %d\n", v45, *(_DWORD *)(v58 + 1780), *(_DWORD *)(v58 + 1776));
LABEL_61:
    result = 0;
  }
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}
