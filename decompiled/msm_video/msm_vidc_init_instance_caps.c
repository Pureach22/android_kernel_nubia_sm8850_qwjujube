__int64 __fastcall msm_vidc_init_instance_caps(__int64 a1)
{
  _QWORD *v1; // x8
  __int64 v2; // x27
  __int64 v3; // x24
  __int64 v4; // x21
  __int64 v5; // x26
  unsigned __int8 v7; // w22
  unsigned __int8 v8; // w8
  unsigned int v9; // w9
  char v10; // w10
  void *v11; // x0
  __int64 result; // x0
  __int64 v13; // x20
  unsigned __int8 v14; // w8
  unsigned __int8 v15; // w9
  unsigned int v16; // w10
  char v17; // w11
  unsigned __int8 v18; // w25
  __int64 v19; // x0
  __int64 v20; // x8
  unsigned __int64 v21; // x1
  __int64 v22; // x2
  int v23; // w3
  __int64 v24; // x9
  unsigned __int64 v25; // x1
  unsigned __int64 i; // x10
  __int64 v27; // x2
  int v28; // w3
  unsigned int *v29; // x8
  __int64 v30; // x21
  __int64 v31; // x28
  __int64 v32; // x20
  __int64 j; // x20
  __int64 v34; // x22
  __int64 v35; // x24
  _DWORD *v36; // x1
  __int64 k; // x20
  __int64 v38; // x21
  __int64 v39; // x24
  _DWORD *v40; // x1
  __int64 v41; // x9
  unsigned int *v42; // x5
  __int64 v43; // x13
  __int64 v44; // x14
  __int64 v45; // x8
  unsigned int v46; // w8
  __int64 v47; // x8
  __int64 v48; // x16
  __int64 v49; // x17
  __int64 v50; // x0
  __int64 v51; // x16
  __int64 v52; // x17
  __int64 v53; // x0
  __int64 v54; // x16
  __int64 v55; // x17
  __int64 v56; // x0
  __int64 v57; // [xsp+8h] [xbp-18h]
  __int64 v58; // [xsp+10h] [xbp-10h]

  v1 = *(_QWORD **)(a1 + 3912);
  v2 = v1[30];
  if ( !v2 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v11 = &unk_8A79E;
LABEL_109:
    printk(v11, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_instance_caps");
    return 4294967274LL;
  }
  v3 = v1[34];
  if ( !v3 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v11 = &unk_923E1;
    goto LABEL_109;
  }
  v4 = *(_QWORD *)(a1 + 3968);
  v5 = v1[32];
  if ( (_BYTE)v4 )
  {
    v7 = 0;
    v8 = v4;
    do
    {
      v9 = v8;
      v10 = v8 & 1;
      v8 >>= 1;
      v7 += v10;
    }
    while ( v9 > 1 );
  }
  else
  {
    v7 = 0;
  }
  v13 = *(_QWORD *)(a1 + 3984);
  *(_DWORD *)(a1 + 3932) = v7;
  v14 = 0;
  if ( (_BYTE)v13 )
  {
    v15 = v13;
    do
    {
      v16 = v15;
      v17 = v15 & 1;
      v15 >>= 1;
      v14 += v17;
    }
    while ( v16 > 1 );
  }
  v18 = v14 + v7;
  *(_DWORD *)(a1 + 3936) = v14;
  v19 = devm_kmalloc(*(_QWORD *)a1 + 16LL, 33272LL * (unsigned __int8)(v14 + v7), 3520);
  *(_QWORD *)(a1 + 4784) = v19;
  if ( !v19 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_84EB0, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_instance_caps");
    return 4294967284LL;
  }
  if ( v7 )
  {
    v20 = 0;
    v21 = 0;
    do
    {
      if ( v21 <= 7 )
      {
        v22 = (1LL << v21) & v4;
        if ( !v22 )
        {
          v23 = v21 + 1;
          if ( v21 == 7 )
            goto LABEL_26;
          v22 = (2LL << v21) & v4;
          if ( !v22 )
          {
            v23 = v21 + 2;
            if ( v21 == 6 )
              goto LABEL_26;
            v22 = (4LL << v21) & v4;
            if ( !v22 )
            {
              v23 = v21 + 3;
              if ( v21 == 5 )
                goto LABEL_26;
              v22 = (8LL << v21) & v4;
              if ( !v22 )
              {
                v23 = v21 + 4;
                if ( v21 == 4
                  || (v22 = (16LL << v21) & v4) == 0
                  && ((v23 = v21 + 5, v21 == 3)
                   || (v22 = (32LL << v21) & v4) == 0
                   && ((v23 = v21 + 6, v21 == 2)
                    || (v22 = (64LL << v21) & v4) == 0
                    && ((v23 = v21 + 7, v21 == 1) || (v22 = (128LL << v21) & v4) == 0))) )
                {
LABEL_26:
                  v21 = 8;
                  goto LABEL_22;
                }
              }
            }
          }
          LODWORD(v21) = v23;
        }
        v21 = (unsigned int)v21 + 1LL;
        *(_DWORD *)(*(_QWORD *)(a1 + 4784) + v20) = 1;
        *(_DWORD *)(*(_QWORD *)(a1 + 4784) + v20 + 4) = v22;
      }
LABEL_22:
      v20 += 33272;
    }
    while ( 33272LL * v7 != v20 );
  }
  if ( v7 < (unsigned int)v18 )
  {
    v24 = 33272LL * v7;
    v25 = 0;
    for ( i = v18 - (unsigned __int64)v7; i; --i )
    {
      if ( v25 <= 7 )
      {
        v27 = (1LL << v25) & v13;
        if ( !v27 )
        {
          v28 = v25 + 1;
          if ( v25 == 7 )
            goto LABEL_49;
          v27 = (2LL << v25) & v13;
          if ( !v27 )
          {
            v28 = v25 + 2;
            if ( v25 == 6 )
              goto LABEL_49;
            v27 = (4LL << v25) & v13;
            if ( !v27 )
            {
              v28 = v25 + 3;
              if ( v25 == 5 )
                goto LABEL_49;
              v27 = (8LL << v25) & v13;
              if ( !v27 )
              {
                v28 = v25 + 4;
                if ( v25 == 4
                  || (v27 = (16LL << v25) & v13) == 0
                  && ((v28 = v25 + 5, v25 == 3)
                   || (v27 = (32LL << v25) & v13) == 0
                   && ((v28 = v25 + 6, v25 == 2)
                    || (v27 = (64LL << v25) & v13) == 0
                    && ((v28 = v25 + 7, v25 == 1) || (v27 = (128LL << v25) & v13) == 0))) )
                {
LABEL_49:
                  v25 = 8;
                  goto LABEL_45;
                }
              }
            }
          }
          LODWORD(v25) = v28;
        }
        v25 = (unsigned int)v25 + 1LL;
        *(_DWORD *)(*(_QWORD *)(a1 + 4784) + v24) = 2;
        *(_DWORD *)(*(_QWORD *)(a1 + 4784) + v24 + 4) = v27;
      }
LABEL_45:
      v24 += 33272;
    }
  }
  v29 = *(unsigned int **)(a1 + 3912);
  v57 = v3;
  v30 = v29[62];
  v31 = v29[66];
  v32 = v29[70];
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_8CBE5, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_init_instance_caps");
  v58 = v32;
  if ( (int)v30 >= 1 )
  {
    for ( j = 0; j != v30; ++j )
    {
      if ( v18 )
      {
        v34 = v2 + (j << 6);
        v35 = 0;
        do
        {
          v36 = (_DWORD *)(*(_QWORD *)(a1 + 4784) + v35);
          if ( (*v36 & *(_DWORD *)(v34 + 4)) != 0 && (v36[1] & *(_DWORD *)(v34 + 8)) != 0 )
          {
            result = update_inst_capability(v2 + (j << 6));
            if ( (_DWORD)result )
              return result;
          }
          v35 += 33272;
        }
        while ( 33272LL * v18 != v35 );
      }
    }
  }
  if ( v5 && (int)v31 >= 1 )
  {
    for ( k = 0; k != v31; ++k )
    {
      if ( v18 )
      {
        v38 = v5 + (k << 6);
        v39 = 0;
        do
        {
          v40 = (_DWORD *)(*(_QWORD *)(a1 + 4784) + v39);
          if ( (*v40 & *(_DWORD *)(v38 + 4)) != 0 && (v40[1] & *(_DWORD *)(v38 + 8)) != 0 )
          {
            result = update_inst_capability(v5 + (k << 6));
            if ( (_DWORD)result )
              return result;
          }
          v39 += 33272;
        }
        while ( 33272LL * v18 != v39 );
      }
    }
  }
  if ( (int)v58 < 1 )
    return 0;
  v41 = 0;
  while ( !v18 )
  {
LABEL_91:
    ++v41;
    result = 0;
    if ( v41 == v58 )
      return result;
  }
  v42 = (unsigned int *)(v57 + (v41 << 7));
  v43 = 0;
  while ( 1 )
  {
    v44 = *(_QWORD *)(a1 + 4784);
    v45 = v44 + v43;
    if ( (*(_DWORD *)(v44 + v43) & v42[1]) == 0 || (*(_DWORD *)(v45 + 4) & v42[2]) == 0 )
      goto LABEL_95;
    if ( !v42 || !v45 )
      break;
    v46 = *v42;
    if ( *v42 >= 0xC5 || *(_DWORD *)(v44 + 168LL * v46 + v43 + 8) != v46 )
      goto LABEL_105;
    v47 = v44 + 168LL * v46 + v43;
    *(_QWORD *)(v47 + 60) = *(_QWORD *)(v42 + 3);
    v48 = *(_QWORD *)(v42 + 9);
    v49 = *(_QWORD *)(v42 + 5);
    v50 = *(_QWORD *)(v42 + 7);
    *(_QWORD *)(v47 + 92) = *(_QWORD *)(v42 + 11);
    *(_QWORD *)(v47 + 84) = v48;
    *(_QWORD *)(v47 + 76) = v50;
    *(_QWORD *)(v47 + 68) = v49;
    v51 = *(_QWORD *)(v42 + 17);
    v52 = *(_QWORD *)(v42 + 13);
    v53 = *(_QWORD *)(v42 + 15);
    *(_QWORD *)(v47 + 124) = *(_QWORD *)(v42 + 19);
    *(_QWORD *)(v47 + 116) = v51;
    *(_QWORD *)(v47 + 108) = v53;
    *(_QWORD *)(v47 + 100) = v52;
    v54 = *(_QWORD *)(v42 + 25);
    v55 = *(_QWORD *)(v42 + 21);
    v56 = *(_QWORD *)(v42 + 23);
    *(_DWORD *)(v47 + 156) = v42[27];
    *(_QWORD *)(v47 + 148) = v54;
    *(_QWORD *)(v47 + 140) = v56;
    *(_QWORD *)(v47 + 132) = v55;
    if ( *v42 > 0xC5 || (*(_QWORD *)(v44 + 168LL * *v42 + v43 + 160) = *((_QWORD *)v42 + 14), *v42 > 0xC5) )
    {
      __break(0x5512u);
LABEL_105:
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8A99C, "err ", 0xFFFFFFFFLL, "codec", "update_inst_cap_dependency");
      return 4294967274LL;
    }
    *(_QWORD *)(v44 + 168LL * *v42 + v43 + 168) = *((_QWORD *)v42 + 15);
LABEL_95:
    v43 += 33272;
    if ( 33272LL * v18 == v43 )
      goto LABEL_91;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_834D4, "err ", 0xFFFFFFFFLL, "codec", "update_inst_cap_dependency");
  return 4294967274LL;
}
