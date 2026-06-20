__int64 __fastcall msm_vidc_encoder_line_size_iris4(__int64 a1)
{
  int v1; // w11
  int v2; // w12
  int v3; // w10
  unsigned int v4; // w9
  unsigned int v5; // w11
  unsigned int v6; // w10
  int v7; // w17
  unsigned int v8; // w16
  unsigned int v9; // w3
  int v10; // w1
  int v11; // w6
  unsigned int v12; // w12
  unsigned int v13; // w11
  int v14; // w5
  unsigned int v15; // w15
  int v16; // w2
  unsigned int v17; // w4
  unsigned int v18; // w6
  unsigned int v19; // w1
  unsigned int v20; // w17
  unsigned int v21; // w13
  int v22; // w14
  unsigned int v23; // w3
  unsigned int v24; // w2
  unsigned int v25; // w14
  int v26; // w16
  unsigned int v27; // w1
  int v28; // w10
  unsigned int v29; // w11
  unsigned int v30; // w10
  unsigned int v31; // w11
  unsigned int v32; // w10
  unsigned int v33; // w11
  int v34; // w13
  unsigned int v35; // w5
  unsigned int v36; // w12
  unsigned int v37; // w16
  unsigned int v38; // w10
  bool v39; // zf
  unsigned int v40; // w12
  int v41; // w17
  int v42; // w1
  int v44; // w14
  unsigned int v45; // w11
  bool v46; // zf
  int v47; // w16
  unsigned int v48; // w6
  int v49; // w19
  int v50; // w13
  char v51; // w14
  char v52; // w16
  int v53; // w1
  unsigned int v54; // w20
  int v55; // w2
  int v56; // w15
  int v57; // w6
  int v58; // w17
  int v59; // w4
  unsigned int v60; // w5
  unsigned int v61; // w6
  int v62; // w17
  int v63; // w1
  int v64; // w11
  unsigned int v65; // w10
  unsigned int v66; // w19

  v1 = *(_DWORD *)(a1 + 312);
  v2 = *(_DWORD *)(a1 + 600);
  v3 = *(_DWORD *)(a1 + 604);
  v4 = *(_DWORD *)(*(_QWORD *)(a1 + 320) + 4272LL);
  if ( v1 == 8 || v1 == 2 )
  {
    v33 = v3 + 31;
    v34 = *(_DWORD *)(a1 + 18128);
    v35 = (v3 + 31) & 0xFFFFFFE0;
    v36 = v2 + 31;
    v37 = (2 * (v3 + 31)) & 0xFFFFFFC0;
    v38 = v36 & 0xFFFFFFE0;
    v39 = v34 == 16 || v34 == 8;
    v40 = v36 >> 5;
    v41 = v39;
    v42 = ((v37 + 767) & 0x7FFFFF00) * v4;
    if ( v34 == 256 || v34 == 128 )
      v44 = 1;
    else
      v44 = v41;
    v45 = v4 - 1 + (v33 >> 5);
    if ( v4 <= 1 )
      v42 = v37;
    v46 = v44 == 0;
    if ( v44 )
      v47 = 6;
    else
      v47 = 3;
    v48 = v4 - 1 + v47 * v35;
    if ( v44 )
      v49 = 3;
    else
      v49 = 2;
    if ( v44 )
      v50 = 768;
    else
      v50 = 512;
    if ( v44 )
      v51 = 10;
    else
      v51 = 9;
    if ( v46 )
      v52 = 10;
    else
      v52 = 11;
    v53 = v42 + 255;
    if ( v38 <= v35 )
      v54 = v35;
    else
      v54 = v38;
    v55 = v48 / v4;
    v56 = v38 / v4 + 255;
    v57 = 96 * v35;
    v58 = 32 * v54 + 8 * v35;
    v59 = v49 * v38 + 255;
    v60 = 16 * v38;
    v61 = (v57 & 0x1FFFFC00) * v4;
    v62 = 24 * v54 + 8 * v38 + (v58 + 131328) * v4;
    v63 = 2 * (v38 + (v53 & 0x7FFFFF00)) + 510;
    v64 = v45 / v4;
    v65 = ((v38 + 511) & 0xFFFFFF00) + ((16 * v40 + 255) & 0xFFFFFF00);
    if ( v61 <= v60 )
      v61 = v60;
    v32 = v65
        + ((2020 * v40 + 255) & 0xFFFFFF00)
        + ((v62 + 1287) & 0xFFFFFF00)
        + ((v60 + 2 * v61) & 0xFFFFFF00)
        + (v63 & 0xFFFFFE00)
        + (v40 << 9)
        + v50 * v40
        + (v40 << v51)
        + (v59 & 0xFFFFFF00);
    v31 = ((v55 + 255) & 0xFFFFFF00) + (v56 & 0xFFFFFF00) + (v64 << 8) + (v64 << v52) + 512;
  }
  else
  {
    if ( v1 != 1 )
    {
      v66 = 0;
      if ( !a1 )
        return v66;
      goto LABEL_50;
    }
    v5 = v3 + 15;
    v6 = (v3 + 15) & 0xFFFFFFF0;
    v7 = v2 + 15;
    v8 = v4 - 1 + (v5 >> 4);
    v9 = (unsigned int)(v2 + 15) >> 5;
    v10 = 2 * (v2 + 15);
    v11 = 32 * (v2 + 15);
    v12 = (80 * (v5 >> 4) + 31) & 0xFFFFFFE0;
    v13 = v7 & 0xFFFFFFF0;
    v14 = 16 * v9;
    v15 = ((96 * v6) & 0x1FFFFE00) * v4;
    v16 = ((v12 + 767) & 0x7FFFFF00) * v4;
    v17 = 2 * (v7 & 0xFFFFFFF0) + 255;
    v18 = v11 & 0xFFFFFE00;
    v19 = (v10 & 0xFFFFFFE0) / v4;
    v20 = (8 * v7) & 0xFFFFFF80;
    v21 = ((v4 - 1 + 3 * v6) / v4 + 255) & 0xFFFFFF00;
    if ( v4 <= 1 )
      v16 = v12;
    v22 = 2020 * v9 + 255;
    if ( v13 <= v6 )
      v23 = v6;
    else
      v23 = v13;
    v24 = v13 + ((v16 + 255) & 0x7FFFFF00);
    v25 = v22 & 0xFFFFFF00;
    v26 = v8 / v4;
    v27 = v19 + 255;
    v28 = 24 * v23 + 8 * v13 + (32 * v23 + 8 * v6 + 131328) * v4;
    v29 = v18 + ((v13 + 511) & 0xFFFFFF00);
    if ( v15 <= 2 * v20 )
      v15 = 2 * v20;
    v30 = v29
        + (v17 & 0xFFFFFF00)
        + ((v14 + 255) & 0xFFFFFF00)
        + v25
        + ((v28 + 1287) & 0xFFFFFF00)
        + ((2 * (v15 + v20) + 255) & 0xFFFFFF00);
    v31 = v21 + (v27 & 0xFFFFFF00) + 1280 * v26 + 512;
    v32 = v30 + v18 + ((2 * v24 + 510) & 0xFFFFFE00);
  }
  v66 = (v32 + v31 * v4 + 512) << (*(_DWORD *)(a1 + 35936) != 0);
  if ( !a1 )
    return v66;
LABEL_50:
  if ( (msm_vidc_debug & 4) != 0 )
    printk(&unk_8FA63, "low ", a1 + 340, "msm_vidc_encoder_line_size_iris4", v66);
  return v66;
}
