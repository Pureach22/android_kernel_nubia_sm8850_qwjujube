__int64 __fastcall msm_vidc_encoder_non_comv_size_iris4(__int64 a1)
{
  int v1; // w11
  int v2; // w12
  int v3; // w10
  unsigned int v4; // w19
  unsigned int v5; // w9
  int v6; // w8
  unsigned int v7; // w10
  unsigned int v8; // w1
  bool v9; // cc
  int v10; // w11
  int v11; // w13
  unsigned int v12; // w10
  unsigned int v13; // w17
  unsigned int v14; // w16
  int v15; // w13
  int v16; // w9
  unsigned int v17; // w12
  int v18; // w15
  int v19; // w13
  unsigned int v20; // w1
  int v21; // w17
  int v22; // w16
  int v23; // w2
  unsigned int v24; // w12
  unsigned int v25; // w15
  unsigned int v26; // w13
  unsigned int v27; // w17
  unsigned int v28; // w9
  unsigned int v29; // w10
  unsigned int v30; // w14
  int v31; // w13
  unsigned int v32; // w11
  unsigned int v33; // w12
  int v34; // w15
  int v35; // w1
  unsigned int v36; // w2
  unsigned int v37; // w10
  int v38; // w16
  unsigned int v39; // w13
  unsigned int v40; // w9
  unsigned int v41; // w12
  unsigned int v42; // w14
  unsigned int v43; // w15
  unsigned int v44; // w10
  bool v45; // zf
  unsigned int v46; // w8
  char v47; // w9
  unsigned int v48; // w8

  v1 = *(_DWORD *)(a1 + 312);
  v2 = *(_DWORD *)(a1 + 600);
  v3 = *(_DWORD *)(a1 + 604);
  v4 = 0;
  v5 = *(_DWORD *)(*(_QWORD *)(a1 + 320) + 4272LL);
  v6 = *(_DWORD *)(a1 + 35936);
  if ( v1 <= 7 )
  {
    if ( v1 == 1 )
    {
      v29 = v3 + 15;
      v30 = (v29 >> 4) * ((unsigned int)(v2 + 15) >> 4);
      v9 = v5 > 1;
      v31 = 11 * (((v29 >> 3) + 14) & 0x3FFFFFF0);
      v32 = (v2 + 15) & 0xFFFFFFF0;
      v33 = (((unsigned int)(v2 + 143) >> 2) & 0x3FFFFFFC) * (v29 >> 4) + 28;
      v34 = 16 * v30;
      v35 = 4 * v30;
      v36 = v30 >> 3;
      v37 = v29 & 0xFFFFFFF0;
      v38 = v31 + 5535;
      v39 = v31 + 5280;
      v40 = (v38 & 0xFFFFFF00) * v5;
      v41 = (v33 & 0xFFFFFFE0) + 510;
      v42 = 3 * ((2 * v30 + 7) & 0xFFFFFFF8);
      v43 = (v34 + 511) & 0xFFFFFF00;
      if ( !v9 )
        v40 = v39;
      v44 = v37 * v32;
      v45 = v6 == 0;
      v46 = v43
          + ((v35 + 511) & 0xFFFFFF00)
          + ((v36 + 511) & 0x3FFFFF00)
          + (v41 & 0xFFFFFE00)
          + ((v42 + 255) & 0xFFFFFF00)
          + 6 * ((v40 + 511) & 0xFFFFFE00)
          + 127744;
      v47 = !v45;
      v48 = v46 << v47;
      if ( ((unsigned __int8)v47 & (v44 <= 0x4B000)) != 0 )
        v4 = v48 + 16000;
      else
        v4 = v48;
LABEL_29:
      if ( !a1 )
        return v4;
      goto LABEL_30;
    }
    if ( v1 != 2 )
      goto LABEL_29;
    goto LABEL_9;
  }
  if ( v1 == 8 )
  {
LABEL_9:
    v7 = v3 + 31;
    v8 = v7 >> 5;
    v9 = v5 > 1;
    v10 = *(_DWORD *)(a1 + 15104);
    v11 = 11 * (((v7 >> 4) + 14) & 0x1FFFFFF0);
    v12 = (v7 & 0xFFFFFFE0) * ((v2 + 31) & 0xFFFFFFE0);
    v13 = v8 * ((unsigned int)(v2 + 31) >> 5);
    v14 = (v11 + 5535) & 0xFFFFFF00;
    v15 = v11 + 5280;
    v16 = v14 * v5;
    v17 = (((unsigned int)(v2 + 287) >> 3) & 0x1FFFFFFC) * v8 + 28;
    v18 = 16 * v13;
    if ( !v9 )
      v16 = v15;
    v19 = 4 * v13;
    v20 = v13 >> 3;
    v21 = 2 * v13;
    v22 = 127744;
    if ( (v10 & 0xFFFFFFFE) == 4 )
      v23 = 10;
    else
      v23 = 6;
    v24 = v17 & 0xFFFFFFE0;
    v25 = (v18 + 511) & 0xFFFFFF00;
    v26 = (v19 + 511) & 0xFFFFFF00;
    v27 = 3 * ((v21 + 7) & 0xFFFFFFF8);
    if ( v10 == 2 )
      v22 = 135936;
    v28 = (v22
         + v25
         + v26
         + ((v20 + 511) & 0x3FFFFF00)
         + ((v24 + 510) & 0xFFFFFE00)
         + ((v27 + 255) & 0xFFFFFF00)
         + ((v16 + 511) & 0xFFFFFE00) * v23) << (v6 != 0);
    if ( v6 != 0 && v12 <= 0x4B000 )
      v28 += 16000;
    if ( v6 )
    {
      v4 = v28 + 512;
      if ( !a1 )
        return v4;
    }
    else
    {
      v4 = v28 + 256;
      if ( !a1 )
        return v4;
    }
    goto LABEL_30;
  }
  if ( v1 != 64 )
    goto LABEL_29;
  v4 = 110592;
  if ( !a1 )
    return v4;
LABEL_30:
  if ( (msm_vidc_debug & 4) != 0 )
    printk(&unk_8FA63, "low ", a1 + 340, "msm_vidc_encoder_non_comv_size_iris4", v4);
  return v4;
}
