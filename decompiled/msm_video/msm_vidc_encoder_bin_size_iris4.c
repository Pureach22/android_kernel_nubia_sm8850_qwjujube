__int64 __fastcall msm_vidc_encoder_bin_size_iris4(__int64 a1)
{
  int v1; // w15
  int v2; // w14
  int v3; // w10
  int v4; // w11
  int v5; // w13
  unsigned int v6; // w9
  unsigned int v7; // w12
  bool v8; // zf
  unsigned int v9; // w14
  unsigned int v10; // w16
  unsigned int v11; // w14
  int v12; // w15
  unsigned int v13; // w16
  unsigned int v14; // w13
  unsigned int v15; // w14
  unsigned int v16; // w16
  unsigned int v17; // w14
  int v18; // w15
  unsigned int v19; // w16
  unsigned int v20; // w13
  unsigned int v21; // w13
  unsigned int v22; // w15
  unsigned int v23; // w19
  unsigned int v24; // w13
  unsigned int v25; // w1
  unsigned int v26; // w15
  int v27; // w10
  int v28; // w11
  unsigned int v29; // w14
  int v30; // w15
  unsigned int v31; // w9
  unsigned int v32; // w14
  unsigned int v33; // w15
  unsigned int v34; // w13
  unsigned int v35; // w1
  unsigned int v36; // w15

  v1 = *(_DWORD *)(a1 + 312);
  v2 = *(_DWORD *)(a1 + 11576);
  v3 = *(_DWORD *)(a1 + 600);
  v4 = *(_DWORD *)(a1 + 604);
  v5 = *(_DWORD *)(a1 + 15104);
  v6 = *(_DWORD *)(*(_QWORD *)(a1 + 320) + 4272LL);
  v7 = *(_DWORD *)(a1 + 21488);
  if ( v1 != 8 && v1 != 2 )
  {
    if ( v1 != 1 )
    {
      v23 = 0;
      if ( !a1 )
        return v23;
      goto LABEL_56;
    }
    v8 = v2 == 2;
    v9 = (v3 + 15) & 0xFFFFFFF0;
    v10 = (v4 + 15) & 0xFFFFFFF0;
    if ( v8 )
    {
      v11 = v10 * v9;
      v12 = *(_DWORD *)(a1 + 1828);
      v13 = 3 * v11;
      if ( (v12 & 0xFFFFFFFE) == 2 )
      {
        v14 = v13 >> 1;
      }
      else
      {
        v34 = v5 & 0xFFFFFFFE;
        v35 = v13 >> 3;
        if ( v11 > 0x25800 )
          v13 >>= 2;
        if ( v11 > 0x880000 )
          v13 = v35;
        if ( v12 == 5 )
          v36 = (9 * v11) >> 2;
        else
          v36 = v13;
        if ( v34 == 2 )
          v14 = (5 * v36) >> 2;
        else
          v14 = v36;
      }
      v21 = (v14 + 255) & 0xFFFFFF00;
      if ( v7 <= 3 )
        v7 = 3;
      v33 = (17 * v21 / 0xA + 255) & 0x3FFFFF00;
      if ( v11 <= 0x7E9000 )
        goto LABEL_35;
    }
    else
    {
      v32 = v10 * v9;
      v7 = 1;
      v21 = 3 * v32;
      v33 = 3 * v32;
      if ( v32 <= 0x7E9000 )
      {
LABEL_35:
        v29 = v33 >> (v6 > 2);
LABEL_50:
        v30 = *(_DWORD *)(a1 + 1828);
        v27 = v3 + 32;
        v28 = v4 + 32;
        goto LABEL_51;
      }
    }
    v29 = v33 / v6;
    goto LABEL_50;
  }
  v8 = v2 == 2;
  v15 = (v3 + 31) & 0xFFFFFFE0;
  v16 = (v4 + 31) & 0xFFFFFFE0;
  if ( v8 )
  {
    v17 = v16 * v15;
    v18 = *(_DWORD *)(a1 + 1828);
    v19 = 3 * v17;
    if ( (v18 & 0xFFFFFFFE) == 2 )
    {
      v20 = v19 >> 1;
    }
    else
    {
      v24 = v5 & 0xFFFFFFFE;
      v25 = v19 >> 3;
      if ( v17 > 0x25800 )
        v19 >>= 2;
      if ( v17 > 0x880000 )
        v19 = v25;
      if ( v18 == 5 )
        v26 = (9 * v17) >> 2;
      else
        v26 = v19;
      if ( v24 == 2 )
        v20 = (5 * v26) >> 2;
      else
        v20 = v26;
    }
    v21 = (v20 + 255) & 0xFFFFFF00;
    if ( v7 <= 3 )
      v7 = 3;
    v22 = (17 * v21 / 0xA + 255) & 0x3FFFFF00;
  }
  else
  {
    v17 = v16 * v15;
    v21 = 3 * v17;
    if ( v6 < 2 )
    {
      v31 = 0;
      goto LABEL_52;
    }
    v7 = 1;
    v22 = 3 * v17;
  }
  v27 = v3 + 32;
  v28 = v4 + 32;
  if ( v17 <= 0x7E9000 )
    v29 = v22 >> (v6 > 2);
  else
    v29 = v22 / v6;
  v30 = *(_DWORD *)(a1 + 1828);
LABEL_51:
  v31 = v7
      * v6
      * (((((v29 << (v30 == 5)) + 255) & 0xFFFFFF00) + ((unsigned int)(v28 * v27) >> 10 << 6) + 639) & 0xFFFFFF00)
      + 512;
LABEL_52:
  if ( *(_DWORD *)(a1 + 35936) )
    v23 = 5 * v21 + 2 * v31;
  else
    v23 = v31;
  if ( a1 )
  {
LABEL_56:
    if ( (msm_vidc_debug & 4) != 0 )
      printk(&unk_8FA63, "low ", a1 + 340, "msm_vidc_encoder_bin_size_iris4", v23);
  }
  return v23;
}
